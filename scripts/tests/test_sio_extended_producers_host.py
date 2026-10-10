"""Host C checks for reconstructed multiplayer queue event producers.

These tests exercise C packet layouts. Matching builds still use the original
Thumb ASM under NONMATCH; this suite does not claim binary matching.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src" / "sio_stuff_x.c"
CASES = [
    ("80275B8", "void sub_80275B8(u8 player, u8 value, u8 parameter)"),
    ("80275F0", "void sub_80275F0(u8 player, u8 value, u8 parameter)"),
    ("8027674", "void sub_8027674(u8 player, u16 value)"),
]
HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
u8 observed[5];
void sub_8026AB8(const u8 *packet) { memcpy(observed, packet, 5); }
#define CHECK(expr, code) do { if (!(expr)) { fprintf(stderr, "case %d\n", code); return code; } } while(0)
"""
MAIN = r"""
int main(void) {
    sub_80275B8(1, 0xAA, 0x35);
    CHECK(observed[0] == 0x38 && observed[1] == 1, 1);
    CHECK(observed[2] == 0x35 && observed[3] == 1 && observed[4] == 0xAA, 2);
    sub_80275B8(0, 0xAA, 0x35);
    CHECK(observed[4] == 0, 3);
    sub_80275F0(3, 0x84, 0x28);
    CHECK(observed[0] == 0x38 && observed[1] == 0x20, 4);
    CHECK(observed[2] == 0x28 && observed[3] == 3 && observed[4] == 0x84, 5);
    sub_8027674(2, 0xABCD);
    CHECK(observed[0] == 0x38 && observed[1] == 0x0C && observed[2] == 2, 6);
    CHECK(observed[3] == 0xCD && observed[4] == 0xAB, 7);
    return 0;
}
"""

def extract(src, ident, declaration):
    prefix = 'NONMATCH("asm/non_matching/sio/sio__sub_' + ident + '.inc", ' + declaration + ')'
    pattern = re.compile(re.escape(prefix) + r"\s*(\{.*?\n\})\s*END_NONMATCH", re.S)
    m = pattern.search(src)
    if not m:
        raise AssertionError("Missing reconstructed C function sub_" + ident)
    return declaration + "\n" + m.group(1)


class SioExtendedProducersHostTests(unittest.TestCase):
    def test_packet_layouts(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("Host C compiler unavailable")
        source = SOURCE.read_text(encoding="utf-8")
        bodies = "\n".join(extract(source, a, d) for a, d in CASES)
        with tempfile.TemporaryDirectory() as folder:
            c = Path(folder) / "producer.c"
            exe = Path(folder) / "producer"
            c.write_text(HEADER + "\n" + bodies + "\n" + MAIN, encoding="utf-8")
            built = subprocess.run(
                [compiler, "-std=c99", "-O0", "-Wall", "-Wextra", "-Werror",
                 str(c), "-o", str(exe)], capture_output=True, text=True,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            result = subprocess.run([str(exe)], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == "__main__":
    unittest.main()
