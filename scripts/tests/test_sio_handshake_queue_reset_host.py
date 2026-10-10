"""Compile the actual reconstructed serial handshake/reset C bodies with host GCC.

Proves byte layouts, early-return side effects, and queue/player reset loops.
Does not claim GBA agbcc binary matching or emulated link connectivity.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
FUNCTIONS = {
    "sub_8024DC8": "s16 sub_8024DC8(void)",
    "sub_8025AA8": "s16 sub_8025AA8(void)",
    "sub_80261B0": "void sub_80261B0(void)",
}
HEADER = r"""
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef int16_t s16;
typedef int32_t s32;
typedef uint32_t u32;
typedef volatile uint32_t vu32;

static vu32 mockSioControl;
#define REG_ADDR_SIOCNT (&mockSioControl)
struct Stage { u8 pad[6]; u8 playerIndex; } gStageData;
struct SioPacket { u8 raw[0x18]; };
struct SioPacket gMultiSioRecv[4], gMultiSioSend;
struct MockPlayer { u8 bytes[0x150]; } gPlayers[4];
u8 gUnknown_03001CC0[64];
u32 gMultiSioStatusFlags;

static s16 statusResult;
static unsigned statusCalls, transmitCalls, resetCalls;
s16 sub_802610C(void) { ++statusCalls; return statusResult; }
void sub_8025D10(void) { ++transmitCalls; }
void sub_8025770(void) { ++resetCalls; }

#define CHECK(expr) do { if (!(expr)) { \
  fprintf(stderr, "line %d: %s\n", __LINE__, #expr); return 1; \
} } while (0)
"""
DRIVER = r"""
static void prepare(unsigned id, s16 status, u32 flags, u16 type) {
    mockSioControl = (id << 6) | 0x2C000000;
    gStageData.playerIndex = 0xFF;
    gMultiSioStatusFlags = flags;
    statusResult = status;
    gMultiSioRecv[0].raw[0] = (u8)type;
    gMultiSioRecv[0].raw[1] = (u8)(type >> 8);
    transmitCalls = resetCalls = statusCalls = 0;
}
static int check_handshakes(void) {
    static const s16 statuses[] = { -32768, -4, -1, 0, 1, 32767 };
    static const u32 flags[] = { 0, 1, 2, 3, 0xC0C, 0xC0D, 0x80000000 };
    static const u16 types[] = { 0x6606, 0x660D, 0x1234, 0x0000 };
    unsigned id, s, f, t;
    for (id = 0; id < 4; ++id) {
      for (s = 0; s < sizeof statuses / sizeof statuses[0]; ++s) {
        for (f = 0; f < sizeof flags / sizeof flags[0]; ++f) {
          for (t = 0; t < sizeof types / sizeof types[0]; ++t) {
            s16 status = statuses[s];
            u32 enabled = flags[f] & 1;
            prepare(id, status, flags[f], types[t]);
            CHECK(sub_8024DC8() == (status < 0 ? status :
                   enabled && types[t] == 0x6606 ? 1 : 0));
            CHECK(gStageData.playerIndex == id);
            CHECK(statusCalls == 1);
            CHECK(transmitCalls == 0);
            CHECK(resetCalls == (status >= 0));

            prepare(id, status, flags[f], types[t]);
            CHECK(sub_8025AA8() == (status < 0 ? status :
                   enabled && types[t] == 0x660D ? 1 : 0));
            CHECK(gStageData.playerIndex == id);
            CHECK(statusCalls == 1);
            CHECK(transmitCalls == (status >= 0));
            CHECK(resetCalls == 0);
          }
        }
      }
    }
    return 0;
}
static int check_queue_reset(void) {
    unsigned i, j, frame;
    for (frame = 0; frame < 256; ++frame) {
        memset(gUnknown_03001CC0, 0xA5, sizeof gUnknown_03001CC0);
        memset(gPlayers, 0xB9, sizeof gPlayers);
        memset(&gMultiSioSend, 0xB3, sizeof gMultiSioSend);
        memset(gMultiSioRecv, 0xC2, sizeof gMultiSioRecv);
        gUnknown_03001CC0[0] = (u8)frame;
        for (i = 0; i < 4; ++i) {
            gPlayers[i].bytes[0x2C] = (u8)(frame + 19 * i);
        }
        sub_80261B0();
        CHECK(gUnknown_03001CC0[0] == ((frame + 1) & 3));
        CHECK(gUnknown_03001CC0[1] == 0);
        for (i = 2; i < sizeof gUnknown_03001CC0; ++i) {
            int marker = ((i - 2) % 5 == 0 && i < 2 + 8 * 5);
            CHECK(gUnknown_03001CC0[i] == (marker ? 0xFF : 0xA5));
        }
        for (i = 0; i < 4; ++i) {
            CHECK(gPlayers[i].bytes[0x2C] ==
                  (((u8)(frame + 19 * i) & (u8)~0x39) | 0x20));
            for (j = 0; j < sizeof gPlayers[i].bytes; ++j) {
                if (j != 0x2C) CHECK(gPlayers[i].bytes[j] == 0xB9);
            }
        }
        for (j = 0; j < sizeof gMultiSioSend.raw; ++j)
            CHECK(gMultiSioSend.raw[j] == (j == 0x12 ? 0xFF : 0xB3));
        for (i = 0; i < 4; ++i)
            for (j = 0; j < sizeof gMultiSioRecv[i].raw; ++j)
                CHECK(gMultiSioRecv[i].raw[j] == (j == 0x12 ? 0xFF : 0xC2));
    }
    return 0;
}
int main(void) {
    if (check_handshakes()) return 1;
    if (check_queue_reset()) return 2;
    return 0;
}
"""


def extract_source(source: str, name: str, declaration: str) -> str:
    sig = f'NONMATCH("asm/non_matching/sio/sio__{name}.inc", {declaration})'
    match = re.search(re.escape(sig) + r"\s*(\{.*?\n\})\s*END_NONMATCH",
                      source, re.S)
    if match is None:
        raise AssertionError(f"Missing reconstructed C function: {name}")
    return declaration + "\n" + match.group(1)


class SioHandshakeAndResetTests(unittest.TestCase):
    def test_extracted_c_bodies_run(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if not compiler:
            self.skipTest("No native C compiler")
        source = SOURCE.read_text(encoding="utf-8")
        combined = HEADER + "\n" + "\n\n".join(
            extract_source(source, name, decl)
            for name, decl in FUNCTIONS.items()) + "\n" + DRIVER
        with tempfile.TemporaryDirectory(prefix="sa3-sio-handshake-") as temp:
            c = Path(temp) / "handshake.c"
            executable = Path(temp) / "handshake"
            c.write_text(combined, encoding="utf-8")
            compile_result = subprocess.run([
                compiler, "-std=c99", "-O2", "-fwrapv", "-Wall", "-Wextra",
                "-Werror", "-fsanitize=undefined", str(c), "-o", str(executable)
            ], text=True, capture_output=True)
            self.assertEqual(compile_result.returncode, 0, compile_result.stderr)
            run = subprocess.run([str(executable)], text=True, capture_output=True)
            self.assertEqual(run.returncode, 0, run.stderr)

    def test_three_real_functions_not_empty(self):
        source = SOURCE.read_text(encoding="utf-8")
        for name, decl in FUNCTIONS.items():
            self.assertNotEqual(extract_source(source, name, decl).count("\n"), 2)


if __name__ == "__main__":
    unittest.main()
