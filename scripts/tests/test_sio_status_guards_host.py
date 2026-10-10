"""Host-compile four REAL SIO status-guard NONMATCH C bodies and exercise branches.

Covers negative link-status propagation, 0x0C0C error flags, packet producer
call parameters, and 0x6C0A response handling. No ROM or GBA build is used.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
DECLS = {
    "sub_8024074": "s16 sub_8024074(u8 value)",
    "sub_80240B4": "s16 sub_80240B4(u8 value)",
    "sub_80240F4": "s16 sub_80240F4(void)",
    "sub_8024130": "s16 sub_8024130(void)",
}

HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;

u32 gMultiSioStatusFlags;
struct MockPacket { u8 raw[24]; } gMultiSioRecv[4];
static s16 linkStatus;
static int statusCalls, send354Calls, send374Calls, send3B4Calls;
static u8 lastPlayer, lastValue;
s16 sub_802610C(void) { ++statusCalls; return linkStatus; }
void sub_8024354(u8 p, u8 v) {
    ++send354Calls; lastPlayer = p; lastValue = v;
}
void sub_8024374(u8 p, u8 v) {
    ++send374Calls; lastPlayer = p; lastValue = v;
}
void sub_80243B4(void) { ++send3B4Calls; }
#define CHECK(expr) do { if (!(expr)) { \
    fprintf(stderr, "failure at line %d: %s\n", __LINE__, #expr); return 1; \
} } while (0)
static void resetCalls(void) {
    statusCalls = send354Calls = send374Calls = send3B4Calls = 0;
    lastPlayer = lastValue = 0xDD;
}
"""

MAIN = r"""
int main(void) {
    static const s16 statuses[] = { -32768, -15, -4, -1, 0, 1, 32767 };
    static const u32 flags[] = {
        0, 1, 2, 3, 0x100, 0x200, 0x400, 0x800, 0x0C0C, 0x0C0F,
        0xFFFFFFFF, 0x12340003,
    };
    unsigned s, f, v, tag;
    for (s = 0; s < sizeof(statuses)/sizeof(statuses[0]); ++s) {
        for (f = 0; f < sizeof(flags)/sizeof(flags[0]); ++f) {
            linkStatus = statuses[s];
            gMultiSioStatusFlags = flags[f];
            for (v = 0; v < 256; ++v) {
                s16 want = linkStatus < 0 ? linkStatus :
                           (gMultiSioStatusFlags & 0x0C0C) ? -4 : 0;
                int safe = linkStatus >= 0 &&
                           !(gMultiSioStatusFlags & 0x0C0C);

                resetCalls();
                CHECK(sub_8024074((u8)v) == want);
                CHECK(statusCalls == 1);
                CHECK(send354Calls == safe && send374Calls == 0 &&
                      send3B4Calls == 0);
                if (safe) CHECK(lastPlayer == 0 && lastValue == (u8)v);

                resetCalls();
                CHECK(sub_80240B4((u8)v) == want);
                CHECK(statusCalls == 1);
                CHECK(send354Calls == 0 && send374Calls == safe &&
                      send3B4Calls == 0);
                if (safe) CHECK(lastPlayer == 0 && lastValue == (u8)v);

                resetCalls();
                CHECK(sub_80240F4() == want);
                CHECK(statusCalls == 1);
                CHECK(send354Calls == 0 && send3B4Calls == 0);
                CHECK(send374Calls == (safe && ((gMultiSioStatusFlags & 1) != 0)));
                if (safe && (gMultiSioStatusFlags & 1)) {
                    CHECK(lastPlayer == 1 && lastValue == 0xFF);
                }

                for (tag = 0; tag < 2; ++tag) {
                    u16 packet = tag ? 0x6C0A : 0x6C04;
                    gMultiSioRecv[1].raw[0] = (u8)packet;
                    gMultiSioRecv[1].raw[1] = (u8)(packet >> 8);
                    resetCalls();
                    CHECK(sub_8024130() ==
                          (!safe ? want :
                           ((gMultiSioStatusFlags & 2) && tag ? 0x10 : 0)));
                    CHECK(statusCalls == 1);
                    CHECK(send3B4Calls ==
                          (safe && ((gMultiSioStatusFlags & 2) != 0)));
                    CHECK(send354Calls == 0 && send374Calls == 0);
                }
            }
        }
    }
    return 0;
}
"""


def extract_real_c(source: str, name: str, declaration: str) -> str:
    needle = f'NONMATCH("asm/non_matching/sio/sio__{name}.inc", {declaration})'
    match = re.search(re.escape(needle) + r"\s*(\{.*?\n\})\s*END_NONMATCH",
                      source, re.S)
    if not match:
        raise AssertionError("Missing typed NONMATCH C source: " + name)
    return declaration + "\n" + match.group(1)


class SioStatusGuardsHostTests(unittest.TestCase):
    def test_full_link_status_truth_table(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("No C compiler on this host")
        source = SOURCE.read_text(encoding="utf-8")
        full = HEADER + "\n" + "\n\n".join(
            extract_real_c(source, name, decl)
            for name, decl in DECLS.items()) + "\n" + MAIN
        with tempfile.TemporaryDirectory(prefix="sa3-status-") as tmp:
            path = Path(tmp) / "status.c"
            binary = Path(tmp) / "status"
            path.write_text(full, encoding="utf-8")
            built = subprocess.run(
                [compiler, "-std=c99", "-O2", "-fwrapv",
                 "-Wall", "-Wextra", "-Werror", "-fsanitize=undefined",
                 str(path), "-o", str(binary)],
                text=True, capture_output=True)
            self.assertEqual(built.returncode, 0, built.stderr)
            run = subprocess.run([str(binary)], text=True, capture_output=True)
            self.assertEqual(run.returncode, 0, run.stderr)

    def test_sources_are_not_placeholders(self):
        source = SOURCE.read_text(encoding="utf-8")
        for name, decl in DECLS.items():
            body = extract_real_c(source, name, decl)
            self.assertIn("sub_802610C()", body)
            self.assertIn("return ", body)
            self.assertNotIn("{\n}", body)


if __name__ == "__main__":
    unittest.main()
