"""Compile and execute the REAL five recovered SIO C bodies from src/sio_stuff_x.c.

The independent test driver checks the original Thumb packet field contract
and bounds (including the full five bytes copied by sub_8026AB8).
This is source-level testing, NOT agbcc or whole-ROM matching.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src/sio_stuff_x.c"
FUNCTIONS = {
    "sub_8027620": "void sub_8027620(u16 first, u16 second)",
    "sub_8027834": "void sub_8027834(void)",
    "sub_8027878": "void sub_8027878(u8 value)",
    "sub_802789C": "void sub_802789C(void)",
    "sub_80278C4": "void sub_80278C4(void)",
}

HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
struct { u8 raw[0xC0]; } gStageData;
struct { u8 raw[0x20]; } gMultiSioSend;
u8 queued[5];
unsigned queueCalls;
void sub_8026AB8(const u8 *packet) {
    memcpy(queued, packet, 5);
    ++queueCalls;
}
#define CHECK(expr) do { if (!(expr)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #expr); return 1; \
} } while (0)
"""

DRIVER = r"""
int main(void) {
    unsigned n, before;
    u8 snapshot[sizeof gMultiSioSend.raw];

    // Exercise every possible u16 first argument and an independent second.
    for (n = 0; n < 65536; ++n) {
        u16 first = (u16)n;
        u16 second = (u16)(n ^ 0xA53C);
        before = queueCalls;
        sub_8027620(first, second);
        CHECK(queueCalls == before + 1);
        CHECK(queued[0] == 0x30);
        CHECK(queued[1] == (u8)first);
        CHECK(queued[2] == (u8)(first >> 8));
        CHECK(queued[3] == (u8)second);
        CHECK(queued[4] == (u8)(second >> 8));
    }

    // 0x23 / 0x24 / 0x25 are three distinct message types.
    for (n = 0; n < 256; ++n) {
        gStageData.raw[0xB4] = (u8)n;
        before = queueCalls;
        sub_8027834();
        CHECK(queueCalls == before + 1);
        CHECK(queued[0] == 0x38 && queued[1] == 0x23);
        CHECK(queued[2] == 0 && queued[3] == (u8)n && queued[4] == 0);

        before = queueCalls;
        sub_8027878((u8)n);
        CHECK(queueCalls == before + 1);
        CHECK(queued[0] == 0x38 && queued[1] == 0x24);
        CHECK(queued[2] == (u8)n && queued[3] == 0 && queued[4] == 0);

        gStageData.raw[0xAE] = (u8)n;
        gStageData.raw[0xAF] = (u8)(n ^ 0xB4);
        before = queueCalls;
        sub_802789C();
        CHECK(queueCalls == before + 1);
        CHECK(queued[0] == 0x38 && queued[1] == 0x25);
        CHECK(queued[2] == (u8)n);
        CHECK(queued[3] == (u8)(n ^ 0xB4) && queued[4] == 0);

        // 0x78C4 writes into the existing send packet, never enqueues.
        memset(gMultiSioSend.raw, 0xAA, sizeof gMultiSioSend.raw);
        gStageData.raw[5] = (u8)(n ^ 0x3C);
        memcpy(snapshot, gMultiSioSend.raw, sizeof snapshot);
        before = queueCalls;
        sub_80278C4();
        CHECK(queueCalls == before);
        CHECK(gMultiSioSend.raw[0x12] == (u8)(n ^ 0x3C));
        CHECK(gMultiSioSend.raw[0x14] == (u8)n);
        CHECK(gMultiSioSend.raw[0x15] == (u8)(n ^ 0xB4));
        snapshot[0x12] = gMultiSioSend.raw[0x12];
        snapshot[0x14] = gMultiSioSend.raw[0x14];
        snapshot[0x15] = gMultiSioSend.raw[0x15];
        CHECK(memcmp(snapshot, gMultiSioSend.raw, sizeof snapshot) == 0);
    }
    CHECK(queueCalls == 65536 + 3 * 256);
    return 0;
}
"""


def extract_c_body(source: str, name: str, declaration: str) -> str:
    signature = ('NONMATCH("asm/non_matching/sio/sio__'
                 + name + '.inc", ' + declaration + ')')
    rx = re.compile(re.escape(signature)
                    + r"\s*(\{.*?\n\})\s*END_NONMATCH", re.S)
    found = rx.search(source)
    if not found:
        raise AssertionError("Missing typed C body for " + name)
    return declaration + "\n" + found.group(1)


class RecoveredSioPacketTests(unittest.TestCase):
    def test_packet_formats_and_queue_bounds(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("No native C compiler available")
        source = SOURCE.read_text(encoding="utf-8")
        generated = HEADER + "\n" + "\n\n".join(
            extract_c_body(source, name, decl)
            for name, decl in FUNCTIONS.items()) + "\n" + DRIVER
        with tempfile.TemporaryDirectory(prefix="sa3-sio-msgs-") as temp:
            path = Path(temp) / "packet_handlers.c"
            exe = Path(temp) / "packet_handlers"
            path.write_text(generated, encoding="utf-8")
            compiled = subprocess.run(
                [compiler, "-std=c99", "-O2", "-Wall", "-Wextra", "-Werror",
                 str(path), "-o", str(exe)], text=True, capture_output=True)
            self.assertEqual(compiled.returncode, 0, compiled.stderr)
            tested = subprocess.run([str(exe)], text=True, capture_output=True)
            self.assertEqual(tested.returncode, 0, tested.stderr)

    def test_each_handler_extracts_real_source(self):
        code = SOURCE.read_text(encoding="utf-8")
        for name, declaration in FUNCTIONS.items():
            body = extract_c_body(code, name, declaration)
            self.assertTrue(body.count("sub_8026AB8") == (
                0 if name == "sub_80278C4" else 1))
            self.assertIn("{", body)
            self.assertIn("}", body)


if __name__ == "__main__":
    unittest.main()
