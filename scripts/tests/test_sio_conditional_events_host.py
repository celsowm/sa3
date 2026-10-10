"""Host-side truth-table tests for SIO packet encoders 8027768/80277AC/80277F0.

Verifies all four branch combinations against the Thumb instruction flow.
Does not establish agbcc or full-ROM matching.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src" / "sio_stuff_x.c"
DEFS = [
    ("8027768", 8, False),
    ("80277AC", 9, True),
    ("80277F0", 10, False),
]

HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
u8 queued[5];
void sub_8026AB8(const u8 *packet) { memcpy(queued, packet, 5); }
#define CHECK(ok, id) do { if (!(ok)) { fprintf(stderr, "case %d failed\n", id); return id; } } while (0)
"""

MAIN = r"""
int main(void) {
    unsigned a, b;
    int step = 0;
    for (a = 0; a < 4; a++) {
        for (b = 0; b < 3; b++) {
            u8 expected = (((a & 1) != 0) == (b != 0)) ? 10 : 5;
            sub_8027768(a, b);
            CHECK(queued[0] == 0x38 && queued[1] == 8 && queued[2] == expected, ++step);
            sub_80277AC(a, b);
            CHECK(queued[0] == 0x38 && queued[1] == 9 && queued[2] == (expected == 10 ? 5 : 10), ++step);
            sub_80277F0(a, b);
            CHECK(queued[0] == 0x38 && queued[1] == 10 && queued[2] == expected, ++step);
        }
    }
    return 0;
}
"""


def extract(text, address):
    signature = "void sub_" + address + "(u16 first, u16 second)"
    literal = 'NONMATCH("asm/non_matching/sio/sio__sub_' + address + '.inc", ' + signature + ')'
    m = re.search(re.escape(literal) + r"\s*(\{.*?\n\})\s*END_NONMATCH", text, re.S)
    if m is None:
        raise AssertionError("Missing C body " + address)
    return signature + "\n" + m.group(1)


class SioConditionalEventTests(unittest.TestCase):
    def test_truth_tables(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("C compiler not installed")
        source = SOURCE.read_text(encoding="utf-8")
        functions = "\n".join(extract(source, n) for n, _, _ in DEFS)
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / "events.c"
            exe = Path(folder) / "events"
            path.write_text(HEADER + "\n" + functions + "\n" + MAIN, encoding="utf-8")
            compiled = subprocess.run(
                [compiler, "-std=c99", "-Wall", "-Wextra", "-Werror",
                 str(path), "-o", str(exe)], capture_output=True, text=True,
            )
            self.assertEqual(compiled.returncode, 0, compiled.stderr)
            result = subprocess.run([str(exe)], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == "__main__":
    unittest.main()
