"""Compile the real SIO MultiBoot C body and test its return-code table."""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
SIGNATURE = "bool32 sub_8028530(void)"
ASM = "asm/non_matching/sio/sio__sub_8028530.inc"

HEADER = r"""
#include <stdint.h>
#include <stdio.h>
typedef uint32_t bool32;
typedef int32_t s32;
#define TRUE 1
#define FALSE 0
struct MultiBootParam { unsigned char data[4]; } gMultiBootParam;
static s32 response;
static int mainCalls, transitionCalls;
s32 MultiBootMain(struct MultiBootParam *param) {
    if (param != &gMultiBootParam) return -123456;
    ++mainCalls;
    return response;
}
void sub_802613C(void) { ++transitionCalls; }
#define CHECK(x) do { if (!(x)) { \
    fprintf(stderr, "line %d failed: %s\n", __LINE__, #x); return 1; \
} } while (0)
"""

MAIN = r"""
int main(void) {
    s32 tested;
    for (tested = -512; tested < 512; ++tested) {
        int good = tested == 0x50 || tested == 0x60 ||
                   tested == 0x70 || tested == 0x71;
        response = tested;
        mainCalls = transitionCalls = 0;
        CHECK(sub_8028530() == (unsigned)good);
        CHECK(mainCalls == 1);
        CHECK(transitionCalls == good);
    }
    response = 2147483647;
    mainCalls = transitionCalls = 0;
    CHECK(sub_8028530() == 0 && mainCalls == 1 && transitionCalls == 0);
    return 0;
}
"""


class SioMultiBootTests(unittest.TestCase):
    def test_completion_codes_and_failure_paths(self):
        cc = shutil.which("cc") or shutil.which("gcc")
        if not cc:
            self.skipTest("No native C compiler")
        source = SOURCE.read_text(encoding="utf-8")
        pattern = (r'NONMATCH\("' + re.escape(ASM) + r'", '
                   + re.escape(SIGNATURE)
                   + r'\)\s*(\{.*?\n\})\s*END_NONMATCH')
        found = re.search(pattern, source, re.S)
        self.assertIsNotNone(found, "Real MultiBoot C body was not found")
        full = HEADER + "\n" + SIGNATURE + "\n" + found.group(1) + "\n" + MAIN
        with tempfile.TemporaryDirectory(prefix="sa3-multiboot-") as temp:
            path = Path(temp) / "multi_boot_state.c"
            program = Path(temp) / "multi_boot_state"
            path.write_text(full, encoding="utf-8")
            result = subprocess.run(
                [cc, "-std=c99", "-O2", "-Wall", "-Wextra", "-Werror",
                 "-fsanitize=undefined", str(path), "-o", str(program)],
                capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            run = subprocess.run([str(program)], capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stderr)


if __name__ == "__main__":
    unittest.main()
