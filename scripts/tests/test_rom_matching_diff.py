"""Synthetic tests: binary diff reports reveal metadata, not ROM bytes."""
import importlib.util
import unittest
from pathlib import Path

SCRIPT = Path(__file__).resolve().parents[1] / "rom_matching_diff.py"
SPEC = importlib.util.spec_from_file_location("rom_matching_diff", SCRIPT)
MOD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MOD)


class RomMatchingDiffTests(unittest.TestCase):
    def test_identical_windows_and_full_report(self):
        src = b"ABCDxy"
        result = MOD.compare(src, src, (("one", MOD.GBA_BASE + 1, MOD.GBA_BASE + 5),),
                             verify_europe=False)
        self.assertTrue(result["full_rom"]["exact_match"])
        self.assertEqual(result["windows"][0]["mismatched_bytes"], 0)
        self.assertEqual(result["windows"][0]["reference_bytes"], 4)

    def test_one_changed_byte_has_rom_address(self):
        src = b"ABCDxy"
        candidate = b"ABCXxy"
        result = MOD.compare(src, candidate,
                             (("one", MOD.GBA_BASE + 2, MOD.GBA_BASE + 5),),
                             verify_europe=False)
        self.assertEqual(result["full_rom"]["mismatched_bytes"], 1)
        self.assertEqual(result["windows"][0]["first_mismatch_address"], "0x08000003")
        self.assertFalse(result["windows"][0]["exact_match"])
        self.assertNotIn("ABCD", str(result))

    def test_short_or_long_candidate_is_mismatched(self):
        shortened = MOD.mismatch_metrics(b"abcd", b"ab")
        self.assertEqual(shortened["mismatched_bytes"], 2)
        self.assertEqual(shortened["first_mismatch_address"], "0x08000002")
        extended = MOD.mismatch_metrics(b"ab", b"abcd")
        self.assertEqual(extended["mismatched_bytes"], 2)
        self.assertEqual(extended["first_mismatch_address"], "0x08000002")

    def test_bad_reference_rejected(self):
        with self.assertRaisesRegex(ValueError, "Europe rev-0"):
            MOD.compare(b"fake rom", b"fake rom")

    def test_parse_windows_and_detect_invalid_ranges(self):
        self.assertEqual(MOD.parse_window("symbol:0x08000000:0x08000004"),
                         ("symbol", MOD.GBA_BASE, MOD.GBA_BASE + 4))
        for x in ("bad", "bad:abc:def", ":0x08000000:0x08000004",
                  "name:0x08000002:0x08000002"):
            with self.assertRaises(ValueError):
                MOD.parse_window(x)
        with self.assertRaisesRegex(ValueError, "Duplicate name"):
            MOD.compare(b"abcdef", b"abcdef", (("x", MOD.GBA_BASE, MOD.GBA_BASE + 2),
                                               ("x", MOD.GBA_BASE + 2, MOD.GBA_BASE + 4)),
                        verify_europe=False)
        with self.assertRaisesRegex(ValueError, "out of reference ROM"):
            MOD.compare(b"ab", b"ab", (("x", MOD.GBA_BASE, MOD.GBA_BASE + 3),),
                        verify_europe=False)


if __name__ == "__main__":
    unittest.main()
