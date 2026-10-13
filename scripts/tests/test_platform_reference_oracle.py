"""Synthetic tests for platform reference fingerprints; no ROM asset required."""
import hashlib
import importlib.util
import tempfile
import unittest
from pathlib import Path

SCRIPT = Path(__file__).resolve().parents[1] / "platform_reference_oracle.py"
SPEC = importlib.util.spec_from_file_location("platform_reference_oracle", SCRIPT)
MOD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MOD)


class PlatformReferenceTests(unittest.TestCase):
    def test_two_original_intervals_are_adjacent(self):
        a, b = MOD.INTERVALS
        self.assertEqual(a[2], b[1])
        self.assertEqual(a[2] - a[1], 816)
        self.assertEqual(b[2] - b[1], 812)

    def test_hash_only_requested_interval(self):
        payload = b"ABCDEFGH"
        self.assertEqual(MOD.interval_sha256(payload, MOD.BASE + 2, MOD.BASE + 6),
                         hashlib.sha256(b"CDEF").hexdigest())
        for start, end in [(MOD.BASE, MOD.BASE), (MOD.BASE-1, MOD.BASE+1),
                           (MOD.BASE, MOD.BASE+len(payload)+1)]:
            with self.assertRaises(ValueError):
                MOD.interval_sha256(payload, start, end)

    def test_rejects_wrong_rom(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "wrong.gba"
            path.write_bytes(b"not a ROM")
            with self.assertRaisesRegex(ValueError, "Europe rev-0"):
                MOD.validate_local_europe_rom(path)


if __name__ == "__main__":
    unittest.main()
