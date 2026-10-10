"""Exercise the real C source for multiplayer X/Y entity-relative packet encoders.

The original Thumb passes a signed 32-bit coordinate, subtracts the entity
manager's two reference coordinates with 32-bit wrapping, then copies a
five-byte packet. This is source-level testing, not original agbcc matching.
"""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
NAMES = {
    "sub_8027538": ("void sub_8027538(s32 position)", 0x18),
    "sub_8027578": ("void sub_8027578(s32 position)", 0x20),
}
HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t s32;
struct MockEntityTask { u32 words[4]; } entity;
struct MockStage { struct MockEntityTask *taskEntitiesManager; } gStageData;
#define TASK_DATA(t) ((void *)(t)->words)
u8 lastPacket[5];
unsigned calls;
void sub_8026AB8(const u8 *packet) { memcpy(lastPacket, packet, 5); ++calls; }
#define CHECK(x) do { if (!(x)) { \
    fprintf(stderr, "line %d failure: %s\n", __LINE__, #x); return 1; \
} } while (0)
"""
MAIN = r"""
static int check_packet(u8 type, u32 expected) {
    CHECK(lastPacket[0] == type);
    CHECK(lastPacket[1] == (u8)expected);
    CHECK(lastPacket[2] == (u8)(expected >> 8));
    CHECK(lastPacket[3] == (u8)(expected >> 16));
    CHECK(lastPacket[4] == (u8)(expected >> 24));
    return 0;
}
int main(void) {
    static const u32 boundaries[] = {
        0, 1, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, 0x100, 0xA5FF0033,
    };
    unsigned x, i, r;
    gStageData.taskEntitiesManager = &entity;
    for (r = 0; r < sizeof(boundaries)/sizeof(boundaries[0]); ++r) {
        entity.words[1] = boundaries[r];
        entity.words[2] = boundaries[r] ^ 0xFEEDC0DE;
        for (x = 0; x < 65536; ++x) {
            u32 arg = ((u32)x << 16) | ((x * 29u) & 0xFFFFu);
            calls = 0;
            sub_8027538((s32)arg);
            CHECK(calls == 1);
            if (check_packet(0x18, arg - entity.words[1])) return 1;
            sub_8027578((s32)arg);
            CHECK(calls == 2);
            if (check_packet(0x20, arg - entity.words[2])) return 2;
        }
        for (i = 0; i < 4; ++i) {
            if (i != 1 && i != 2)
                CHECK(entity.words[i] == 0);
        }
    }
    return 0;
}
"""


def extract(source: str, name: str, decl: str) -> str:
    needle = f'NONMATCH("asm/non_matching/sio/sio__{name}.inc", {decl})'
    m = re.search(re.escape(needle) + r"\s*(\{.*?\n\})\s*END_NONMATCH",
                  source, re.S)
    if not m:
        raise AssertionError(f"Missing source: {name}")
    return decl + "\n" + m.group(1)


class EntityOffsetPacketTests(unittest.TestCase):
    def test_full_32bit_serialization(self):
        cc = shutil.which("cc") or shutil.which("gcc")
        if cc is None:
            self.skipTest("No native C compiler")
        source = SOURCE.read_text(encoding="utf-8")
        c_source = HEADER + "\n" + "\n\n".join(
            extract(source, n, signature) for n, (signature, _) in NAMES.items()
        ) + "\n" + MAIN
        with tempfile.TemporaryDirectory(prefix="sa3-entity-deltas-") as folder:
            path = Path(folder) / "deltas.c"
            binary = Path(folder) / "deltas"
            path.write_text(c_source, encoding="utf-8")
            build = subprocess.run([
                cc, "-std=c99", "-O2", "-fwrapv", "-Wall", "-Wextra", "-Werror",
                "-fsanitize=undefined", str(path), "-o", str(binary),
            ], text=True, capture_output=True)
            self.assertEqual(build.returncode, 0, build.stderr)
            result = subprocess.run([str(binary)], text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == "__main__":
    unittest.main()
