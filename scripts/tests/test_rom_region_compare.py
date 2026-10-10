#!/usr/bin/env python3
"""Run with: python3 -m unittest discover -s scripts/tests -v"""
import importlib.util
import sys
import unittest
from pathlib import Path

SCRIPTS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SCRIPTS))
SPEC = importlib.util.spec_from_file_location(
    "rom_region_compare", SCRIPTS / "rom_region_compare.py")
region = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(region)


class RegionCompareTests(unittest.TestCase):
    def test_lz10_valid_and_invalid(self):
        stream = b"\x10\x18\x00\x00\x10AAA\xF0\x00BBB"
        self.assertEqual(region.decode_lz10(stream, 0, 24), b"A" * 21 + b"BBB")
        with self.assertRaises(ValueError):
            region.decode_lz10(stream, 0, 23)
        with self.assertRaises(ValueError):
            region.decode_lz10(b"\x10\x04\x00\x00\x80\x00\x01", 0, 4)

    def test_aligned_byte_diff(self):
        a = b"\x00\x01\x02\x03\x04\x05\x06\x07"
        b = b"\x00\x07\x03\x03\x04\x00\x06\x07"
        result = region.byte_comparison(a, b)
        self.assertEqual(result["different_bytes"], 3)
        self.assertEqual(result["different_contiguous_runs"], 2)
        self.assertEqual(result["identical_bytes"], 5)
        with self.assertRaises(ValueError):
            region.byte_comparison(a, b[:-1])

    def test_region_required(self):
        with self.assertRaises(ValueError):
            region.compare_roms(b"x" * 192, b"x" * 192)


if __name__ == "__main__":
    unittest.main()
