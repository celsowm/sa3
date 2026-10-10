"""Compile seven REAL SIO receive/handshake C bodies with host GCC.

Extracts production source: no parallel implementation is substituted.
Exercises type checks, participant masks, negative status propagation,
buffer mutation, callbacks, and SIOCNT bits 4–5 (not bits 6–7).
This is functional source validation, not verified agbcc binary matching.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
DECLS = {
    "sub_8023FE0": "s16 sub_8023FE0(void)",
    "sub_8025360": "s16 sub_8025360(void)",
    "sub_80254CC": "s16 sub_80254CC(void)",
    "sub_80255B0": "s16 sub_80255B0(void)",
    "sub_8025614": "s16 sub_8025614(void)",
    "sub_8025674": "s16 sub_8025674(void)",
    "sub_8025714": "void sub_8025714(u8 value)",
}
HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef volatile uint32_t vu32;
static vu32 ioRegister;
#define REG_ADDR_SIOCNT (&ioRegister)
struct MockStage { u8 reserved[6]; u8 playerIndex; } gStageData;
struct MockPacket { u8 raw[24]; } gMultiSioSend, gMultiSioRecv[4];
u8 gUnknown_03001060[0x60];
u32 gMultiSioStatusFlags;
static s16 mockStatus;
static int statusCalls, send10, send20, send34, send48, reportCalls;
static int lastReport, lastValue20, lastValue34;
s16 sub_802610C(void) { ++statusCalls; return mockStatus; }
void sub_8025D10(void) { ++send10; }
void sub_8025D20(u8 v) { ++send20; lastValue20=v; }
void sub_8025D34(u8 v) { ++send34; lastValue34=v; }
void sub_8025D48(void) { ++send48; }
void sub_80243F8(u8 v) { ++reportCalls; lastReport=v; }
#define CHECK(x) do { if (!(x)) { \
    fprintf(stderr, "line %d: %s\n", __LINE__, #x); return 1; \
} } while (0)
static void reset(void) {
    statusCalls=send10=send20=send34=send48=reportCalls=0;
    lastValue20=lastValue34=lastReport=-1;
    memset(gMultiSioRecv, 0xA5, sizeof gMultiSioRecv);
    memset(&gMultiSioSend, 0xC3, sizeof gMultiSioSend);
    memset(gUnknown_03001060, 0x7B, sizeof gUnknown_03001060);
}
static void setType(unsigned i, u16 type) {
    gMultiSioRecv[i].raw[0]=(u8)type;
    gMultiSioRecv[i].raw[1]=(u8)(type>>8);
}
"""

DRIVER = r"""
int main(void) {
    static const s16 statuses[] = {-32768,-4,-1,0,1,32767};
    static const u16 types[] = {0x660C,0x660D,0x660E,0x660F,0x680F,0x6810,0xFFFF,0};
    unsigned st, mask, kind, bad, id, n, flags;

    // Participant mask logic; every selected packet must carry the expected
    // type. 0x5360 and 0x5674 additionally require mask 3, 7, or 15.
    for (st=0; st<6; st++) for (mask=0; mask<16; mask++)
    for (kind=0; kind<3; kind++) for (bad=0; bad<4; bad++) {
        int valid = mask==3 || mask==7 || mask==15;
        int anyBad = (mask & (1u<<bad)) != 0;
        u16 expected = kind==0 ? 0x660C : kind==1 ? 0x660D : 0x660F;
        s16 ret;
        reset();
        mockStatus=statuses[st];
        gUnknown_03001060[7]=(u8)mask;
        gUnknown_03001060[0x50]=0xD4;
        gUnknown_03001060[0x51]=0xE5;
        for (id=0; id<4; id++) setType(id, expected);
        setType(bad, 0x1234);
        if (kind==0) {
            ret=sub_8025360();
            CHECK(ret == (mockStatus<0 ? mockStatus : valid && !anyBad));
            CHECK(send10 == (mockStatus>=0));
        } else if (kind==1) {
            ret=sub_80254CC();
            CHECK(ret == (mockStatus<0 ? mockStatus : !anyBad));
            CHECK(send20 == (mockStatus>=0));
            if (mockStatus>=0) CHECK(lastValue20==0);
            CHECK(gUnknown_03001060[0x50] ==
                  (mockStatus<0 ? 0xD4 : 0));
            CHECK(gUnknown_03001060[0x51] ==
                  (mockStatus<0 ? 0xE5 : 0));
        } else {
            ret=sub_8025674();
            CHECK(ret == (mockStatus<0 ? mockStatus : valid && !anyBad));
            CHECK(send48 == (mockStatus>=0));
        }
        CHECK(statusCalls==1);
    }

    // Conditional response data updates: type==0x660E is an affirmative
    // response in both handlers; 0x5614 also accepts any type >0x680F,
    // updating the state while still returning zero.
    for (st=0; st<6; st++) for (flags=0; flags<2; flags++)
    for (kind=0; kind<8; kind++) for (n=0; n<256; n++) {
        int linked=flags!=0, success=statuses[st]>=0, accept, affirmative;
        u8 old=0xAB;
        reset();
        mockStatus=statuses[st];
        gMultiSioStatusFlags=flags;
        gUnknown_03001060[0x50]=old;
        gUnknown_03001060[0x51]=0xC7;
        setType(0, types[kind]);
        gMultiSioRecv[0].raw[5]=(u8)n;
        accept=(types[kind]==0x660D || types[kind]==0x660E);
        affirmative=(types[kind]==0x660E);
        CHECK(sub_80255B0() ==
              (mockStatus<0 ? mockStatus : (linked && affirmative)));
        CHECK(statusCalls==1 && send20==success);
        if (success) CHECK(lastValue20==old);
        CHECK(gUnknown_03001060[0x50] ==
              (linked && success && accept ? (u8)n : old));
        CHECK(gUnknown_03001060[0x51] ==
              (linked && success && accept ? 0 : 0xC7));

        reset();
        mockStatus=statuses[st];
        gMultiSioStatusFlags=flags;
        gUnknown_03001060[0x50]=old;
        gUnknown_03001060[0x51]=0xC7;
        setType(0, types[kind]);
        gMultiSioRecv[0].raw[5]=(u8)n;
        accept=(types[kind]==0x660E || types[kind]>0x680F);
        CHECK(sub_8025614() ==
              (mockStatus<0 ? mockStatus : (linked && affirmative)));
        CHECK(statusCalls==1 && send34==success);
        if (success) CHECK(lastValue34==old);
        CHECK(gUnknown_03001060[0x50] ==
              (linked && success && accept ? (u8)n : old));
        CHECK(gUnknown_03001060[0x51] ==
              (linked && success && accept ? 0 : 0xC7));
    }

    // 0x6C0C query: link errors, 0x0C0C errors, and always-forwarding
    // of byte 7 on a connected link, whether the type matches or not.
    for (st=0; st<6; st++) for (flags=0; flags<6; flags++)
    for (kind=0; kind<2; kind++) for (n=0; n<256; n++) {
        static const u32 masks[]={0,1,2,3,0x0C0C,0x0C0D};
        s16 wanted;
        reset();
        mockStatus=statuses[st];
        gMultiSioStatusFlags=masks[flags];
        setType(0,kind ? 0x6C0C : 0x6611);
        gMultiSioRecv[0].raw[7]=(u8)n;
        wanted=mockStatus<0 ? mockStatus :
               (masks[flags]&0x0C0C) ? -4 :
               (masks[flags]&1) && kind ? (s16)(0x1000|n) : 0;
        CHECK(sub_8023FE0() == wanted);
        CHECK(statusCalls==1);
        CHECK(reportCalls==
              (mockStatus>=0 && !(masks[flags]&0x0C0C) &&
               (masks[flags]&1) ? 1 : 0));
        if (reportCalls) CHECK(lastReport==(int)n);
    }

    // SIOCNT player identity comes from *bits 4-5*. Verify against
    // misleading bits 6-7 which can be set independently.
    for (id=0; id<4; id++) for (n=0; n<256; n++) {
        u8 before[24], cached;
        reset();
        ioRegister=(id<<4) | ((n&3)<<6) | 0x80000000u;
        gStageData.playerIndex=0xFE;
        cached=(u8)(n^0xA6);
        gUnknown_03001060[0x4C+id]=cached;
        memcpy(before,gMultiSioSend.raw,sizeof before);
        sub_8025714((u8)n);
        CHECK(gStageData.playerIndex==id);
        CHECK(gMultiSioSend.raw[0]==4 && gMultiSioSend.raw[1]==0x66);
        CHECK(gMultiSioSend.raw[3]==id);
        CHECK(gMultiSioSend.raw[4]==(u8)n);
        CHECK(gMultiSioSend.raw[15+id]==(id<=1 ? cached : 0xFF));
        for (unsigned j=0; j<24; j++) {
            int changed=j==0 || j==1 || j==3 || j==4 || j==15+id;
            if (!changed) CHECK(gMultiSioSend.raw[j]==before[j]);
        }
    }
    return 0;
}
"""


def extract_body(source: str, name: str, decl: str) -> str:
    needle = f'NONMATCH("asm/non_matching/sio/sio__{name}.inc", {decl})'
    match = re.search(re.escape(needle) + r"\s*(\{.*?\n\})\s*END_NONMATCH",
                      source, re.S)
    if not match:
        raise AssertionError(f"Missing real source body for {name}")
    return decl + "\n" + match.group(1)


class ReceiveHandshakeSourceTests(unittest.TestCase):
    def test_real_source_with_native_compiler(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("Native C compiler missing")
        code = SOURCE.read_text(encoding="utf-8")
        recovered = "\n\n".join(
            extract_body(code, name, decl) for name, decl in DECLS.items()
        )
        with tempfile.TemporaryDirectory(prefix="sa3-sio-recv-") as tmp:
            source_path = Path(tmp) / "recv.c"
            executable = Path(tmp) / "recv"
            source_path.write_text(HEADER + "\n" + recovered + "\n" + DRIVER,
                                   encoding="utf-8")
            built = subprocess.run(
                [compiler, "-std=c99", "-O2", "-fwrapv", "-Wall", "-Wextra",
                 "-Werror", "-fsanitize=undefined",
                 str(source_path), "-o", str(executable)],
                text=True, capture_output=True)
            self.assertEqual(built.returncode, 0, built.stderr)
            checked = subprocess.run([str(executable)],
                                     text=True, capture_output=True)
            self.assertEqual(checked.returncode, 0, checked.stderr)

    def test_sio_decode_has_correct_shift(self):
        code = SOURCE.read_text(encoding="utf-8")
        for name, decl in DECLS.items():
            body = extract_body(code, name, decl)
            self.assertIn("{", body)
        self.assertIn("(*(vu32 *)REG_ADDR_SIOCNT >> 4) & 3", code)
        self.assertNotIn("(*(vu32 *)REG_ADDR_SIOCNT >> 6) & 3", code)


if __name__ == "__main__":
    unittest.main()
