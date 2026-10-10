"""Host verification of real C multiplayer player-event dispatch (sub_802790C)."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

SOURCE = Path(__file__).resolve().parents[2] / "src/sio_stuff_x.c"
NAME = "sub_802790C"
DECL = "void sub_802790C(u16 event, u16 player)"

HEADER = r"""
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
struct PlayerMock { u8 contents[0x150]; } gPlayers[4];
struct StageMock { u8 bytes[0x100]; } gStageData;
static unsigned calls;
static u8 forwarded;
void sub_80296F8(u8 value) { ++calls; forwarded = value; }
#define CHECK(x) do { if (!(x)) { \
    fprintf(stderr, "line %d: %s\n", __LINE__, #x); return 1; \
} } while (0)
"""
DRIVER = r"""
int main(void) {
    unsigned idx, raw, k, type;
    static const u16 highs[] = { 0, 0x0100, 0x8000, 0xFF00 };
    for (idx = 0; idx < 4; ++idx) {
        for (raw = 0; raw < 256; ++raw) {
            for (k = 0; k < sizeof(highs)/sizeof(highs[0]); ++k) {
                u16 event = highs[k] | (u16)raw;
                u8 snapshot[sizeof gPlayers];
                memset(gPlayers, 0xA9, sizeof gPlayers);
                memset(&gStageData, 0xAA, sizeof gStageData);
                memcpy(snapshot, gPlayers, sizeof snapshot);
                calls = 0;
                forwarded = 0;
                sub_802790C(event, (u16)idx);
                CHECK(gStageData.bytes[0x8F] == 1);
                CHECK(gPlayers[idx].contents[0x69] == (u8)raw);
                type = raw & 0xF0;
                CHECK(calls == (type == 0x20));
                if (type == 0x20) CHECK(forwarded == (u8)raw);
                if (type == 0x10) {
                    CHECK(gPlayers[idx].contents[0x66] == 0x84);
                    CHECK(gPlayers[idx].contents[0x67] == 0x03);
                }
                for (unsigned player = 0; player < 4; ++player) {
                    for (unsigned j = 0; j < sizeof gPlayers[player].contents; ++j) {
                        int isTarget = player == idx &&
                            (j == 0x69 || (type == 0x10 && (j == 0x66 || j == 0x67)));
                        if (!isTarget) {
                            CHECK(gPlayers[player].contents[j] == 0xA9);
                        }
                    }
                }
                for (unsigned j = 0; j < sizeof gStageData.bytes; ++j)
                    if (j != 0x8F) CHECK(gStageData.bytes[j] == 0xAA);
            }
        }
    }
    return 0;
}
"""


def extract(source: str) -> str:
    signature = f'NONMATCH("asm/non_matching/sio/sio__{NAME}.inc", {DECL})'
    found = re.search(re.escape(signature) + r"\s*(\{.*?\n\})\s*END_NONMATCH",
                      source, re.S)
    if not found:
        raise AssertionError("Expected real C player-event implementation")
    return DECL + "\n" + found.group(1)


class SioPlayerEventTests(unittest.TestCase):
    def test_player_event_truth_table(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("Native C compiler unavailable")
        full = HEADER + "\n" + extract(SOURCE.read_text()) + "\n" + DRIVER
        with tempfile.TemporaryDirectory(prefix="sa3-player-events-") as tmp:
            filename = Path(tmp) / "events.c"
            binary = Path(tmp) / "events"
            filename.write_text(full, encoding="utf-8")
            cc = subprocess.run([
                compiler, "-std=c99", "-O2", "-fwrapv", "-Wall", "-Wextra",
                "-Werror", "-fsanitize=undefined",
                str(filename), "-o", str(binary)
            ], capture_output=True, text=True)
            self.assertEqual(cc.returncode, 0, cc.stderr)
            outcome = subprocess.run([str(binary)], capture_output=True, text=True)
            self.assertEqual(outcome.returncode, 0, outcome.stderr)


if __name__ == "__main__":
    unittest.main()
