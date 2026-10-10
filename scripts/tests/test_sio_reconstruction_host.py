"""Host-only smoke checks for reconstructed SIO control logic.

These compile the actual NONMATCH C bodies with mocked globals. Passing here
does NOT imply agbcc instruction matching or an identical European ROM.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src" / "sio_stuff_x.c"

C_PREFIX = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;
typedef uint8_t bool8;
#define FALSE 0

union MultiSioData { u8 raw[0x18]; };
u8 gUnknown_03001060[0x60];
u8 gUnknown_03001CC0[2 + 8 * 5];
u32 gMultiSioStatusFlags;
union MultiSioData gMultiSioRecv[4];
"""

C_CHECKS = r"""
#define CHECK(expr, n) do { if (!(expr)) { fprintf(stderr, "case %d failed\n", n); return n; } } while (0)
int main(void) {
    u8 packetA[5] = {0x38, 5, 7, 9, 11};
    u8 packetB[5] = {0x38, 0x21, 1, 2, 3};
    u8 packetC[5] = {0x38, 3, 4, 5, 6};
    int i;

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gUnknown_03001060[4] = 2;
    gUnknown_03001060[6] = 3;
    CHECK(sub_8025E24(2) == 0, 1);
    CHECK(gUnknown_03001060[4] == 1, 2);
    CHECK(gUnknown_03001060[6] == 0, 3);

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gUnknown_03001060[4] = 0xFE;
    CHECK(sub_8025E24(0) == 0, 4);
    CHECK(gUnknown_03001060[4] == 0xFF, 5);

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gMultiSioStatusFlags = 0x81;
    gUnknown_03001060[2] = 180;
    CHECK(sub_8025E24(2) == -2, 6);
    CHECK(gUnknown_03001060[2] == 181, 7);

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gMultiSioStatusFlags = 0x85;
    gUnknown_03001060[2] = 7;
    CHECK(sub_8025E24(2) == 0, 8);
    CHECK(gUnknown_03001060[2] == 0, 9);

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gMultiSioStatusFlags = 0x1000;
    gUnknown_03001060[6] = 7;
    CHECK(sub_8025E24(0) == -1, 10);
    CHECK(gUnknown_03001060[6] == 8, 11);

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gMultiSioStatusFlags = 0;
    gUnknown_03001060[7] = 2;
    CHECK(sub_8025E24(0) == 0, 12);
    CHECK(gUnknown_03001060[6] == 1, 13);

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gMultiSioStatusFlags = 0x100;
    gMultiSioRecv[0].raw[0] = 1;
    CHECK(sub_8025E24(0) == 0, 14);
    CHECK(gUnknown_03001060[6] == 1, 15);

    memset(gUnknown_03001060, 0, sizeof(gUnknown_03001060));
    gMultiSioStatusFlags = 0x101;
    CHECK(sub_8025E24(0) == 0, 16);
    CHECK(gUnknown_03001060[6] == 0, 17);

    memset(gUnknown_03001CC0, 0xFF, sizeof(gUnknown_03001CC0));
    sub_8026AB8(packetA);
    CHECK(memcmp(&gUnknown_03001CC0[2], packetA, 5) == 0, 18);
    sub_8026AB8(packetB);
    CHECK(memcmp(&gUnknown_03001CC0[7], packetB, 5) == 0, 19);
    CHECK(memcmp(&gUnknown_03001CC0[2], packetA, 5) == 0, 20);
    for (i = 2; i < 8; ++i) {
        gUnknown_03001CC0[2 + 5 * i] = 0x38;
    }
    sub_8026AB8(packetC);
    CHECK(memcmp(&gUnknown_03001CC0[2], packetA, 5) == 0, 21);
    CHECK(memcmp(&gUnknown_03001CC0[7], packetB, 5) == 0, 22);
    return 0;
}
"""


def extract_body(source: str, address: str, declaration: str) -> str:
    prefix = (
        'NONMATCH("asm/non_matching/sio/sio__sub_'
        + address + '.inc", ' + declaration + ')'
    )
    pattern = re.compile(re.escape(prefix) + r"\s*(\{.*?\n\})\s*END_NONMATCH", re.S)
    match = pattern.search(source)
    if match is None:
        raise AssertionError("missing reconstructed C body for sub_" + address)
    return declaration + "\n" + match.group(1) + "\n"


class SioReconstructionHostTests(unittest.TestCase):
    def test_state_machine_and_packet_queue(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("C compiler unavailable (host-only test)")

        source = SOURCE.read_text(encoding="utf-8")
        functions = [
            extract_body(source, "8025E24", "s16 sub_8025E24(u8 id)"),
            extract_body(source, "8026AB8", "void sub_8026AB8(const u8 *packet)"),
        ]
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            unit = root / "sio_host.c"
            exe = root / "sio_host"
            unit.write_text(
                C_PREFIX + "\n" + "\n".join(functions) + "\n" + C_CHECKS,
                encoding="utf-8",
            )
            compile_run = subprocess.run(
                [compiler, "-std=c99", "-O0", "-Wall", "-Wextra", "-Werror",
                 str(unit), "-o", str(exe)],
                capture_output=True, text=True, check=False,
            )
            self.assertEqual(compile_run.returncode, 0, compile_run.stderr)
            result = subprocess.run(
                [str(exe)], capture_output=True, text=True, check=False
            )
            self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == "__main__":
    unittest.main()
