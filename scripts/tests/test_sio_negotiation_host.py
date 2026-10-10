"""Native regression for four recovered SIO slot-negotiation functions.

Extracts the production C bodies from src/sio_stuff_x.c (not hand-maintained
copies), compiling them with mock link buffers. Not an agbcc/ROM matching test.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
FUNCTIONS = {
    "sub_8024A4C": "s16 sub_8024A4C(u16 value)",
    "sub_8024AC0": "s16 sub_8024AC0(u16 value)",
    "sub_8024F1C": "s16 sub_8024F1C(u8 value)",
    "sub_8025024": "s16 sub_8025024(u16 value)",
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
static vu32 mockControl;
#define REG_ADDR_SIOCNT (&mockControl)
struct { u8 playerIndex; } gStageData;
struct MockPacket { u8 raw[24]; } gMultiSioSend, gMultiSioRecv[4];
u8 gUnknown_030010AC[4];
u32 gMultiSioStatusFlags;
static s16 mockStatus;
static int statusCalls, lastStatusPlayer, callsBEC, callsC20;
static int calls808, callsC8C, calls7D4, calls8F4, orderError;
static u8 lastValue;
s16 sub_802610C(void) {
    statusCalls++;
    lastStatusPlayer = gStageData.playerIndex;
    return mockStatus;
}
void sub_8025BEC(u8 v) { callsBEC++; lastValue = v; }
void sub_8025C20(u8 v) { callsC20++; lastValue = v; }
void sub_8025808(u8 v) { calls808++; lastValue = v; }
void sub_8025C8C(u8 v) { callsC8C++; lastValue = v; }
u16 sub_80247D4(void) { calls7D4++; return 0x1234; }
u16 sub_80248F4(void) {
    calls8F4++;
    if ((gMultiSioSend.raw[12] |
        ((u16)gMultiSioSend.raw[13] << 8)) != 0x1234)
        orderError++;
    return 0xC000;
}
#define CHECK(expr) do { if (!(expr)) { \
    fprintf(stderr, "line %d: %s\n", __LINE__, #expr); return 1; \
} } while (0)
"""
DRIVER = r"""
static void init(unsigned id, s16 status, unsigned connected,
                 u16 type, u16 ack, unsigned input) {
    int i;
    mockControl = id << 6;
    gStageData.playerIndex = 0xDD;
    mockStatus = status;
    gMultiSioStatusFlags = connected;
    memset(&gMultiSioSend, 0xA5, sizeof gMultiSioSend);
    memset(&gMultiSioRecv, 0xB6, sizeof gMultiSioRecv);
    memset(gUnknown_030010AC, 0xC7, sizeof gUnknown_030010AC);
    gMultiSioRecv[0].raw[0] = type;
    gMultiSioRecv[0].raw[1] = type >> 8;
    gMultiSioRecv[0].raw[12] = ack;
    gMultiSioRecv[0].raw[13] = ack >> 8;
    for (i = 0; i < 4; i++)
        gMultiSioRecv[0].raw[15+i] = (u8)(input+i);
    statusCalls = callsBEC = callsC20 = calls808 = 0;
    callsC8C = calls7D4 = calls8F4 = orderError = 0;
    lastStatusPlayer = -1;
    lastValue = 0;
}
int main(void) {
    static const s16 statuses[] = {-32768,-1,0,1,32767};
    static const u16 types[] = {
        0x6603, 0x6604, 0x6606, 0x6607, 0x6608, 0x6609
    };
    unsigned id, st, connected, ty, bit;
    for (id = 0; id < 4; id++)
    for (st = 0; st < 5; st++)
    for (connected = 0; connected < 2; connected++)
    for (ty = 0; ty < 6; ty++)
    for (bit = 0; bit < 4; bit++) {
        u16 ack = (bit & 1 ? (1u << id) : 0) |
                  (bit & 2 ? (0x10u << id) : 0);
        unsigned input = 0xA558 + id;
        int success = statuses[st] >= 0;
        int acceptA = connected &&
                     (types[ty] == 0x6603 || types[ty] == 0x6604);
        int acceptB = acceptA || (connected && types[ty] == 0x6606);
        int acceptD = connected &&
                     (types[ty] == 0x6607 || types[ty] == 0x6608);
        int special = !(ack & (1u << id)) &&
                      (ack & (0x10u << id));
        u8 slot = id <= 1 ? id + 2 : id;
        int specialD = !(ack & (1u << slot)) &&
                       (ack & (0x10u << slot));
        int i;

        init(id, statuses[st], connected, types[ty], ack, input);
        CHECK(sub_8024A4C(input) == (success ? 0 : statuses[st]));
        CHECK(statusCalls == 1 && callsBEC == success && callsC20 == 0);
        if (success) CHECK(lastValue == (u8)input);
        for (i = 0; i < 4; i++)
            CHECK(gMultiSioSend.raw[15+i] ==
                  (success && acceptA ? (u8)(input+i) : 0xA5));

        init(id, statuses[st], connected, types[ty], ack, input);
        CHECK(sub_8024AC0(input) ==
              (!success ? statuses[st] : (acceptB ? (special ? 2 : 1) : 0)));
        CHECK(statusCalls == 1 && lastStatusPlayer == (int)id &&
              gStageData.playerIndex == id);
        CHECK(callsC20 == (success && !(acceptB && special)));
        if (callsC20) CHECK(lastValue == (u8)input);
        for (i = 0; i < 4; i++)
            CHECK(gUnknown_030010AC[i] ==
                  (success && acceptB ? (u8)(input+i) : 0xC7));
        CHECK(gMultiSioSend.raw[15+id] ==
              (success && acceptB && special ? 0xFF : 0xA5));

        init(id, statuses[st], connected, types[ty], ack, input);
        CHECK(sub_8024F1C((u8)input) == (success ? 1 : statuses[st]));
        CHECK(statusCalls == 1 && lastStatusPlayer == (int)id &&
              gStageData.playerIndex == id);
        CHECK(callsC8C == success && calls7D4 == success &&
              calls8F4 == success && orderError == 0);
        if (success) {
            CHECK(lastValue == (u8)input);
            CHECK(gMultiSioSend.raw[15+slot] == 0xFF);
            CHECK(gMultiSioSend.raw[12] == 0x34 &&
                  gMultiSioSend.raw[13] == 0xD2);
        }

        init(id, statuses[st], connected, types[ty], ack, input);
        CHECK(sub_8025024(input) ==
              (!success ? statuses[st] : (acceptD ? (specialD ? 2 : 1) : 0)));
        CHECK(statusCalls == 1 && lastStatusPlayer == (int)id &&
              gStageData.playerIndex == id);
        CHECK(calls808 == (success && !(acceptD && specialD)));
        if (calls808) CHECK(lastValue == (u8)input);
        for (i = 0; i < 4; i++)
            CHECK(gMultiSioSend.raw[15+i] ==
                  (!success || !acceptD ? 0xA5 :
                   (i == slot && specialD ? 0xFF : 0xC7)));
    }
    return 0;
}
"""


def extract_real_c(source, name, signature):
    needle = f'NONMATCH("asm/non_matching/sio/sio__{name}.inc", {signature})'
    match = re.search(re.escape(needle) + r"\s*(\{.*?\n\})\s*END_NONMATCH",
                      source, re.S)
    if match is None:
        raise AssertionError(f"Missing typed C implementation: {name}")
    return signature + "\n" + match.group(1)


class SioNegotiationHostTests(unittest.TestCase):
    def test_all_four_negotiation_paths(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("Native C compiler unavailable")
        production = SOURCE.read_text(encoding="utf-8")
        functions = "\n\n".join(
            extract_real_c(production, name, declaration)
            for name, declaration in FUNCTIONS.items()
        )
        with tempfile.TemporaryDirectory(prefix="sa3-sio-negotiation-") as tmp:
            source_file = Path(tmp) / "negotiation.c"
            executable = Path(tmp) / "negotiation"
            source_file.write_text(HEADER + "\n" + functions + "\n" + DRIVER,
                                   encoding="utf-8")
            built = subprocess.run([
                compiler, "-std=c99", "-O2", "-fwrapv",
                "-Wall", "-Wextra", "-Werror", "-fsanitize=undefined",
                str(source_file), "-o", str(executable),
            ], capture_output=True, text=True)
            self.assertEqual(built.returncode, 0, built.stderr)
            tested = subprocess.run([str(executable)],
                                    capture_output=True, text=True)
            self.assertEqual(tested.returncode, 0, tested.stderr)

    def test_no_placeholder_bodies(self):
        source = SOURCE.read_text(encoding="utf-8")
        for name, signature in FUNCTIONS.items():
            body = extract_real_c(source, name, signature)
            self.assertIn("sub_802610C()", body)
            self.assertNotIn("{\n}", body)


if __name__ == "__main__":
    unittest.main()
