"""Tests of the original boss_2 vertical boundary, no reference ROM needed."""
import importlib.util
import tempfile
import unittest
from pathlib import Path

SPEC = importlib.util.spec_from_file_location(
    "boss2_reference_oracle",
    Path(__file__).resolve().parents[1] / "boss2_reference_oracle.py",
)
MOD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MOD)


class Boss2ReferenceOracleTests(unittest.TestCase):
    def test_below_and_equal_boundary(self):
        for world_y in (-300, -121, -120):
            next_q, flag = MOD.reference_logic(world_y << 8, 0)
            self.assertEqual((next_q, flag), (-120 << 8, 1))

    def test_near_boundary_subtract_four_pixels(self):
        for world_y in (-119, -118, -117):
            self.assertEqual(MOD.reference_logic(world_y << 8, 0),
                             (-120 << 8, 1))
        self.assertEqual(MOD.reference_logic(-116 << 8, 0),
                         (-120 << 8, 0))
        self.assertEqual(MOD.reference_logic(-100 << 8, 0),
                         (-104 << 8, 0))

    def test_camera_offset(self):
        self.assertEqual(MOD.reference_logic(84 << 8, 200),
                         (80 << 8, 0))
        self.assertEqual(MOD.reference_logic(79 << 8, 200),
                         (80 << 8, 1))

    def test_rejects_non_reference_file(self):
        with tempfile.TemporaryDirectory() as tmp:
            p = Path(tmp) / "fake.gba"
            p.write_bytes(b"non-matching")
            with self.assertRaises(ValueError):
                MOD.validate_local_europe_rom(p)


if __name__ == "__main__":
    unittest.main()
