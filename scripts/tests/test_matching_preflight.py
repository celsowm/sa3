"""Synthetic tests for the no-upload SA3 compiler/baserom preflight."""
import importlib.util
from pathlib import Path
import tempfile
import unittest

P = Path(__file__).resolve().parents[1] / "matching_preflight.py"
S = importlib.util.spec_from_file_location("matching_preflight", P)
M = importlib.util.module_from_spec(S)
S.loader.exec_module(M)


class MatchingPreflightTests(unittest.TestCase):
    def test_missing_rom_is_blocked(self):
        with tempfile.TemporaryDirectory() as folder:
            result = M.check(Path(folder), Path(folder) / "absent.gba")
            self.assertFalse(result["passed"])
            self.assertFalse(result["rom"]["matches_europe"])
            self.assertFalse(result["prerequisites_ok"])

    def test_wrong_rom_is_blocked_without_executing_build(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "baserom_sa3.gba").write_bytes(b"not the europe rom")
            result = M.check(root, root / "baserom_sa3.gba", build=True)
            self.assertFalse(result["passed"])
            self.assertIsNone(result["build"])


if __name__ == "__main__":
    unittest.main()
