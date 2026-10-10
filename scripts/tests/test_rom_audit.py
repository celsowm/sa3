#!/usr/bin/env python3
"""Self-contained tests: python3 -m unittest discover -s scripts/tests -v."""
import importlib.util
import unittest
from pathlib import Path

SCRIPT = Path(__file__).resolve().parents[1] / "rom_audit.py"
SPEC = importlib.util.spec_from_file_location("rom_audit", SCRIPT)
rom_audit = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(rom_audit)


def make_rom(code=b"B3SE"):
    blob = bytearray(b"\xFF" * 0x200)
    blob[0:4] = (0xEA00002E).to_bytes(4, "little")
    blob[0xA0:0xAC] = b"SONICADVANC3"
    blob[0xAC:0xB0] = code
    blob[0xB0:0xB2] = b"78"
    blob[0xB2] = 0x96
    blob[0xBC] = 0
    blob[0xBD] = rom_audit.gba_header_complement(blob)
    return blob


class ROMAuditTests(unittest.TestCase):
    def test_header_and_region(self):
        report = rom_audit.audit_rom(bytes(make_rom()))
        self.assertEqual(report["region"], "USA")
        self.assertTrue(report["gba_header_complement_valid"])
        self.assertTrue(report["gba_fixed_byte_valid"])
        self.assertEqual(report["entrypoint"], "0x080000C0")
        self.assertFalse(report["matches_upstream_europe_sha1"])

    def test_europe_header(self):
        self.assertEqual(rom_audit.audit_rom(bytes(make_rom(b"B3SP")))["region"], "EUROPE")

    def test_bad_header_detected(self):
        rom = make_rom()
        rom[0xA0] ^= 1
        self.assertFalse(rom_audit.audit_rom(bytes(rom))["gba_header_complement_valid"])

    def test_short_file(self):
        with self.assertRaises(ValueError):
            rom_audit.audit_rom(b"abc")

    def test_negative_branch(self):
        branch = (0xEAFFFFFF).to_bytes(4, "little")
        self.assertEqual(rom_audit.arm_entrypoint(branch), "0x08000004")
        self.assertIsNone(rom_audit.arm_entrypoint(b"\0\0\0\0"))

    def test_literal_only_lz10(self):
        # LZ10 of 64 literals: header + 8 groups of flag=0, each with 8 bytes.
        stream = b"\x10\x40\x00\x00" + (b"\x00ABCDEFGH" * 8)
        self.assertEqual(rom_audit.lz10_consumed_size(stream, 0, 64), len(stream))

    def test_valid_repeating_lz10(self):
        # Literal 'A' x 3 then 18-byte backreference at distance 1, plus 3 literals.
        # Flags: 00010000 (fourth token is compressed), output length = 24.
        stream = b"\x10\x18\x00\x00\x10AAA\xF0\x00BBB"
        self.assertEqual(rom_audit.lz10_consumed_size(stream, 0, 24), len(stream))

    def test_invalid_lookback_rejected(self):
        stream = b"\x10\x08\x00\x00\x80\x00\x01ABCDEFGH"
        self.assertIsNone(rom_audit.lz10_consumed_size(stream, 0, 8))

    def test_scan_candidates(self):
        # One literal, 3 x 18-byte lookbacks, then 9 more literals = 64.
        # First flag covers literal, 3 lookbacks and 4 following literals.
        stream = (b"\x10\x40\x00\x00\x70A" + b"\xF0\x00" * 3
                  + b"AAAA" + b"\x00AAAAA")
        self.assertEqual(rom_audit.lz10_consumed_size(stream, 0, 64), len(stream))
        original = bytes(make_rom())
        headers, matches = rom_audit.scan_lz10(original + stream)
        self.assertGreaterEqual(headers, 1)
        self.assertEqual(matches[-1]["file_offset"], "0x0000200")
        self.assertEqual(matches[-1]["decoded_bytes"], 64)
        self.assertEqual(matches[-1]["stored_bytes"], len(stream))


if __name__ == "__main__":
    unittest.main()
