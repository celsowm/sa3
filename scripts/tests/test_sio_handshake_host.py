"""Host-only behavioral checks for SIO 0x660A/0x660D handshakes.

These tests compile the actual NONMATCH C bodies with mocked functions;
they cannot prove agbcc instruction matching.
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
typedef uint32_t u32;
typedef struct { u8 playerIndex; } StageData;
union MultiSioData { u8 raw[0x18]; };
union MultiSioData gMultiSioSend, gMultiSioRecv[4];
StageData gStageData;
u8 gUnknown_03001060[0x60];
u32 gMultiSioStatusFlags;
s16 readyStatus;
int calls;
u8 lastByte;
s16 sub_802610C(void) { calls++; return readyStatus; }
void sub_8025CD8(void) { calls += 10; }
void sub_8025D20(u8 value) { calls += 100; lastByte = value; }
#define CHECK(expr, code) do { if (!(expr)) { \
    fprintf(stderr, "FAIL %d: %s\n", code, #expr); return code; \
} } while (0)
"""

CASES = r"""
int main(void) {
    readyStatus = -2;
    CHECK(sub_8025A38() == -2, 1);
    CHECK(calls == 1, 2);
    calls = 0;
    readyStatus = 0;
    gUnknown_03001060[7] = 3;
    gMultiSioRecv[1].raw[0] = 0x0A;
    gMultiSioRecv[1].raw[1] = 0x66;
    CHECK(sub_8025A38() == 1, 3);
    CHECK(calls == 11, 4);
    calls = 0;
    gUnknown_03001060[7] = 15;
    gMultiSioRecv[1].raw[0] = 0;
    gMultiSioRecv[3].raw[0] = 0x0B;
    gMultiSioRecv[3].raw[1] = 0x66;
    CHECK(sub_8025A38() == 1, 5);
    calls = 0;
    gMultiSioRecv[3].raw[0] = 0x0C;
    CHECK(sub_8025A38() == 0, 6);
    calls = 0;
    gUnknown_03001060[7] = 1;
    CHECK(sub_8025A38() == 0, 7);
    CHECK(calls == 11, 8);

    calls = 0;
    readyStatus = -4;
    CHECK(sub_8025AFC() == -4, 9);
    CHECK(calls == 1, 10);
    readyStatus = 0;
    calls = 0;
    gUnknown_03001060[0x50] = 8;
    gMultiSioStatusFlags = 1;
    gMultiSioRecv[0].raw[0] = 0x0D;
    gMultiSioRecv[0].raw[1] = 0x66;
    CHECK(sub_8025AFC() == 1, 11);
    CHECK(lastByte == 8 && calls == 101, 12);
    gMultiSioStatusFlags = 0;
    CHECK(sub_8025AFC() == 0, 13);
    return 0;
}
"""


def extract(source, address, signature):
    pattern = (
        r'NONMATCH\("asm/non_matching/sio/sio__sub_' + address
        + r'\.inc", ' + re.escape(signature)
        + r'\)\s*(\{[\s\S]*?\n\})\s*END_NONMATCH'
    )
    match = re.search(pattern, source)
    if match is None:
        raise AssertionError("Missing SIO C body " + address)
    return signature + "\n" + match.group(1)


class SioHandshakeHostTests(unittest.TestCase):
    def test_handshake_and_error_propagation(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if not compiler:
            self.skipTest("Host compiler unavailable")
        source = SOURCE.read_text(encoding="utf-8")
        bodies = [
            extract(source, "8025A38", "s16 sub_8025A38(void)"),
            extract(source, "8025AFC", "s16 sub_8025AFC(void)"),
        ]
        with tempfile.TemporaryDirectory() as directory:
            cfile = Path(directory) / "handshake.c"
            binary = Path(directory) / "handshake"
            cfile.write_text(PREFIX + "\n" + "\n".join(bodies) + "\n" + CASES)
            cc = subprocess.run(
                [compiler, "-std=c99", "-Wall", "-Wextra", "-Werror",
                 str(cfile), "-o", str(binary)],
                capture_output=True, text=True
            )
            self.assertEqual(cc.returncode, 0, cc.stderr)
            run = subprocess.run([str(binary)], capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stderr)


if __name__ == "__main__":
    unittest.main()
