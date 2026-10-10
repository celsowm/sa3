"""Regression checks for multiplayer SIOCNT ID extraction in SIO C reconstructions.

The original Thumb instructions `lsls #26; lsrs #30` select SIOCNT bits 4..5,
not bits 30..31. These source/ASM checks require no proprietary ROM or agbcc;
they are not a substitute for an exact matching build.
"""
from pathlib import Path
import re
import unittest

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src" / "sio_stuff_x.c"
ASM = ROOT / "asm" / "non_matching" / "sio"

ID_READERS = (
    "sub_8025770",
    "sub_80257AC",
    "sub_8025808",
    "sub_8025874",
    "sub_8025BEC",
    "sub_8025C20",
    "sub_8025C64",
    "sub_8025CD8",
    "sub_802610C",
)
CORRECT_EXPR = "(*(volatile u32 *)0x04000128 >> 4) & 3"


class SioPlayerIdTests(unittest.TestCase):
    def test_arm_thumb_shift_identity_for_all_16_bit_register_values(self):
        for value in range(65536):
            thumb = ((value << 26) & 0xFFFFFFFF) >> 30
            extracted = (value >> 4) & 3
            self.assertEqual(thumb, extracted, hex(value))

    def test_all_reconstructed_id_readers_use_correct_register_bits(self):
        source = SOURCE.read_text(encoding="utf-8")
        self.assertNotIn("0x04000128 >> 30", source)
        for symbol in ID_READERS:
            asm_path = ASM / ("sio__" + symbol + ".inc")
            asm = asm_path.read_text(encoding="utf-8")
            self.assertRegex(asm, r"lsls\s+r\d+,\s*r\d+,\s*#0x1a")
            self.assertRegex(asm, r"lsrs\s+r\d+,\s*r\d+,\s*#0x1e")

            start = source.index('NONMATCH("asm/non_matching/sio/sio__'
                                 + symbol + '.inc",')
            end = source.index("\nEND_NONMATCH", start)
            implementation = source[start:end]
            self.assertIn(CORRECT_EXPR, implementation, symbol)

    def test_id_bits_are_independent_of_irrelevant_register_bits(self):
        for expected in range(4):
            for high_bits in (0, 0xFFFF0000, 0xC0000000, 0xFFFFFFFF):
                # SIOCNT is a 16-bit hardware register, but the code reads it
                # through a 32-bit pointer; high bits must never affect the ID.
                value = (high_bits & ~0x30) | (expected << 4)
                self.assertEqual((value >> 4) & 3, expected)


if __name__ == "__main__":
    unittest.main()
