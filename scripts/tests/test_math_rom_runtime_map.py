"""Offline guardrail tests for SA2 legacy vs SA3 runtime math locations."""
import importlib.util
import unittest
from pathlib import Path

P = Path(__file__).resolve().parents[1] / "math_rom_runtime_map.py"
SPEC = importlib.util.spec_from_file_location("math_rom_runtime_map", P)
M = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(M)


class RuntimeMathMapTests(unittest.TestCase):
    def test_all_math_nonmatch_intervals_have_expected_shape(self):
        self.assertEqual(len(M.RANGES), 18)
        observed = set()
        for old, next_old, digest in M.RANGES:
            self.assertNotIn(old, observed)
            observed.add(old)
            start = int(old, 16) + M.LEGACY_TO_SA3_DELTA
            end = int(next_old, 16) + M.LEGACY_TO_SA3_DELTA
            self.assertTrue(M.ROM_BASE <= start < end < 0x09000000)
            self.assertEqual(len(digest), 64)
            self.assertTrue(all(c in "0123456789abcdef" for c in digest))
        self.assertEqual(set(M.UNIQUE_PREFIXES), {
            "80832FC", "808343C", "8084A24", "8084C70",
        })
        self.assertTrue(set(M.UNIQUE_PREFIXES).issubset(observed))

    def test_verified_signature_addresses_are_not_legacy_addresses(self):
        real = {"80832FC": 0x080AEDD4, "808343C": 0x080AEF14,
                "8084A24": 0x080B04FC, "8084C70": 0x080B0748}
        for old, expected in real.items():
            self.assertEqual(int(old, 16) + M.LEGACY_TO_SA3_DELTA, expected)
            self.assertGreaterEqual(len(bytes.fromhex(M.UNIQUE_PREFIXES[old])), 18)

    def test_rejects_fake_or_other_region_rom(self):
        with self.assertRaisesRegex(ValueError, "SHA-1"):
            M.verify(b"not a Sonic Advance 3 Europe ROM")

    def test_math_c_bodies_no_longer_empty(self):
        contents = (Path(__file__).resolve().parents[2]
                    / "src/game/math.c").read_text(encoding="utf-8")
        for old, _, _ in M.RANGES:
            symbol = "sa2__sub_" + old
            self.assertIn(symbol + "(", contents)
            # All 18 now have real typed C code inside NONMATCH macros.
            self.assertNotIn("void " + symbol + "()) { }", contents)


if __name__ == "__main__":
    unittest.main()
