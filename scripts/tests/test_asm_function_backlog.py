"""Synthetic tests for ASM backlog extraction (no ROM required)."""
import importlib.util
import tempfile
import unittest
from pathlib import Path

SCRIPT = Path(__file__).resolve().parents[1] / "asm_function_backlog.py"
SPEC = importlib.util.spec_from_file_location("asm_function_backlog", SCRIPT)
MOD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MOD)


class BacklogTests(unittest.TestCase):
    def test_function_intervals_are_not_exact_sizes(self):
        labels = MOD.function_labels(
            "func_a: @ 0x080000C0\nmov r0, r0\n"
            "func_b: @ 0x080000C4\nbx lr\n"
            "func_c: @ 0x08000100\nbx lr\n")
        self.assertEqual(labels[0], ("func_a", 0x080000C0))
        self.assertEqual(labels[2], ("func_c", 0x08000100))
        with self.assertRaises(ValueError):
            MOD.function_labels("a: @ 0x08000100\nb: @ 0x080000FE")

    def test_backlog_includes_matching_macro_ownership(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "asm/non_matching/game").mkdir(parents=True)
            (root / "src").mkdir()
            (root / "asm/sample.s").write_text(
                "Foo: @ 0x080000C0\nbar: @ 0x080000C4\n"
                "Baz: @ 0x08000100\n")
            (root / "asm/non_matching/game/foo.inc").write_text("bx lr")
            (root / "src/example.c").write_text(
                'NONMATCH("asm/non_matching/game/foo.inc", void foo())')
            result = MOD.collect(root)
            stats = result["stats"]
            self.assertEqual(stats["standalone_entry_labels"], 3)
            self.assertEqual(stats["bounded_intervals"], 2)
            self.assertEqual(stats["intervals_le_32"], 1)
            self.assertEqual(stats["nonmatching_inc_files"], 1)
            self.assertEqual(stats["orphan_inc_files"], 0)
            self.assertEqual(stats["missing_referenced_includes"], [])
            self.assertEqual(result["rows"][-1]["source_files"], "src/example.c")

    def test_missing_reference_and_rom_guard(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "asm").mkdir()
            (root / "src").mkdir()
            (root / "src/example.c").write_text(
                'ASM_FUNC("asm/non_matching/not_found.inc", void x())')
            report = MOD.collect(root)
            self.assertEqual(report["stats"]["missing_referenced_includes"],
                             ["asm/non_matching/not_found.inc"])
            with self.assertRaisesRegex(ValueError, "Wrong European"):
                MOD.collect(root, b"incorrect rom")


if __name__ == "__main__":
    unittest.main()
