"""ROM-free host test for SIO handshake/dispatch C reconstruction.

Builds the real C bodies from sio_stuff_x.c with a mocked multiplayer
transport. Tests orchestration and error paths, NOT agbcc binary matching.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src" / "sio_stuff_x.c"

PREFIX = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef int16_t s16;
union MultiSioData { u8 raw[0x18]; };
union MultiSioData gMultiSioSend;
struct { u8 playerIndex; } gStageData;

static char trace[32];
static int traceLen;
static s16 readyStatus;
static u16 syncMask, disconnectMask;
static u8 forwarded, outgoingSlotBeforeSync;

static void record(char event) { trace[traceLen++] = event; }
s16 sub_802610C(void) { record('C'); return readyStatus; }
u16 sub_80247D4(void) {
    record('A');
    outgoingSlotBeforeSync = gMultiSioSend.raw[15 + gStageData.playerIndex];
    return syncMask;
}
u16 sub_80248F4(void) { record('B'); return disconnectMask; }
void sub_8025BEC(u8 x) { record('P'); forwarded = x; }
void sub_8025C64(u8 x) { record('Q'); forwarded = x; }
void sub_80257AC(u8 x) { record('R'); forwarded = x; }
static void reset(void) {
    memset(&gMultiSioSend, 0xA5, sizeof(gMultiSioSend));
    memset(trace, 0, sizeof(trace));
    traceLen = 0;
    forwarded = 0;
    gStageData.playerIndex = 2;
    readyStatus = 0;
    syncMask = 0x0010;
    disconnectMask = 0x0200;
    outgoingSlotBeforeSync = 0;
}
#define CHECK(expr, num) do { \
    if (!(expr)) { fprintf(stderr, "failure %d: %s\n", num, #expr); return num; } \
} while (0)
"""

CASES = r"""
int main(void) {
    reset();
    readyStatus = -2;
    CHECK(sub_8025908(9) == -2, 1);
    CHECK(strcmp(trace, "C") == 0, 2);
    CHECK(forwarded == 0, 3);

    reset();
    CHECK(sub_8025908(9) == 0, 4);
    CHECK(*(u16 *)&gMultiSioSend.raw[12] == 0x0210, 5);
    CHECK(strcmp(trace, "CABP") == 0, 6);
    CHECK(forwarded == 9, 7);

    reset();
    gMultiSioSend.raw[17] = 3;
    CHECK(sub_8025948(6) == 1, 8);
    CHECK(outgoingSlotBeforeSync == 0xFF, 9);
    CHECK(strcmp(trace, "CABQ") == 0, 10);
    CHECK(*(u16 *)&gMultiSioSend.raw[12] == 0x0210, 11);
    CHECK(forwarded == 6, 12);

    reset();
    readyStatus = -4;
    gMultiSioSend.raw[17] = 3;
    CHECK(sub_8025948(6) == -4, 13);
    CHECK(strcmp(trace, "C") == 0, 14);
    CHECK(gMultiSioSend.raw[17] == 3, 15);

    reset();
    CHECK(sub_80259F8(7) == 0, 16);
    CHECK(strcmp(trace, "CABR") == 0, 17);
    CHECK(*(u16 *)&gMultiSioSend.raw[12] == 0x0210, 18);
    CHECK(forwarded == 7, 19);

    reset();
    sub_8025B78();
    CHECK(strcmp(trace, "AB") == 0, 20);
    CHECK(*(u16 *)&gMultiSioSend.raw[12] == 0x0210, 21);
    return 0;
}
"""


def body(source, address, signature):
    expression = (r'NONMATCH\("asm/non_matching/sio/sio__sub_' + address
                  + r'\.inc", ' + re.escape(signature)
                  + r'\)\s*(\{[\s\S]*?\n\})\s*END_NONMATCH')
    match = re.search(expression, source)
    if match is None:
        raise AssertionError("missing reconstructed body: sub_" + address)
    return signature + "\n" + match.group(1) + "\n"


class SioDispatchHostTests(unittest.TestCase):
    def test_packet_merge_and_handler_dispatch(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("No host C compiler")

        source = SOURCE.read_text(encoding="utf-8")
        declarations = [
            ("8025908", "s16 sub_8025908(u8 value)"),
            ("8025948", "s16 sub_8025948(u8 value)"),
            ("80259F8", "s16 sub_80259F8(u8 value)"),
            ("8025B78", "void sub_8025B78(void)"),
        ]
        functions = "\n".join(body(source, address, signature)
                              for address, signature in declarations)
        with tempfile.TemporaryDirectory() as directory:
            c = Path(directory) / "dispatch.c"
            exe = Path(directory) / "dispatch"
            c.write_text(PREFIX + "\n" + functions + "\n" + CASES,
                         encoding="utf-8")
            compile_result = subprocess.run(
                [compiler, "-std=c99", "-O0", "-Wall", "-Wextra",
                 "-Werror", str(c), "-o", str(exe)],
                capture_output=True, text=True)
            self.assertEqual(compile_result.returncode, 0,
                             compile_result.stderr)
            run = subprocess.run([str(exe)], capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stderr)


if __name__ == "__main__":
    unittest.main()
