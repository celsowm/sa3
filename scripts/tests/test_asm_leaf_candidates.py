"""Tests for the ROM-gated return-only Assembly triage."""
import importlib.util
import unittest
from pathlib import Path

SCRIPT = Path(__file__).resolve().parents[1] / "asm_leaf_candidates.py"
SPEC = importlib.util.spec_from_file_location("asm_leaf_candidates", SCRIPT)
MOD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MOD)


def row(address="0x080000C0", end="0x080000C4", size="4",
        kind="standalone_asm"):
    return {
        "kind": kind,
        "asm_path": "asm/game__opening.s",
        "symbol": "TaskDestructor_Test",
        "address": address,
        "next_address": end,
        "span_upper_bound_bytes": size,
    }


class ASMLeafCandidateTests(unittest.TestCase):
    def test_accepts_rom_verified_thumb_return_with_padding(self):
        rom = bytearray(0x200)
        rom[0xC0:0xC4] = bytes.fromhex("70470000")
        matches = MOD.find_candidates([row()], bytes(rom))
        self.assertEqual(len(matches), 1)
        self.assertEqual(matches[0]["address"], "0x080000C0")
        self.assertEqual(matches[0]["status"], "rom_verified_asm_not_c_matching")

    def test_rejects_wrong_opcode_and_different_boundaries(self):
        rom = bytearray(0x200)
        rom[0xC0:0xC4] = bytes.fromhex("70470000")
        self.assertEqual(MOD.find_candidates([row(size="8")], rom), [])
        self.assertEqual(MOD.find_candidates([row(end="0x080000C8")], rom), [])
        self.assertEqual(MOD.find_candidates([row(kind="asm_inc_fallback")], rom), [])
        rom[0xC0] = 0
        self.assertEqual(MOD.find_candidates([row()], rom), [])

    def test_rejects_invalid_address_and_missing_fields(self):
        rom = bytes(0x200)
        self.assertEqual(MOD.find_candidates([row(address="0x09000000",
                                                   end="0x09000004")], rom), [])
        self.assertEqual(MOD.find_candidates([{}], rom), [])


if __name__ == "__main__":
    unittest.main()
