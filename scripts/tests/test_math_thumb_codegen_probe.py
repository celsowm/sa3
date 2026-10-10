"""ROM-free checks for the Thumb codegen probe contract."""
import importlib.util
from pathlib import Path
import unittest

ROOT = Path(__file__).resolve().parents[2]
SCRIPT = ROOT / "scripts/math_thumb_codegen_probe.py"
MATH = ROOT / "src/game/math.c"
spec = importlib.util.spec_from_file_location("math_thumb_codegen_probe", SCRIPT)
probe = importlib.util.module_from_spec(spec)
spec.loader.exec_module(probe)


class CodegenProbeTests(unittest.TestCase):
    def test_runtime_symbol_is_relocated_not_legacy_suffix(self):
        self.assertEqual(probe.START, 0x08084EAC + 0x2BAD8)
        self.assertEqual(probe.END, 0x08084EE0 + 0x2BAD8)
        self.assertEqual(probe.END - probe.START, 52)

    def test_extracts_real_typed_matrix_function(self):
        source = MATH.read_text(encoding="utf-8")
        extracted = probe.extract_c_body(source)
        self.assertIn("void sa2__sub_8084EAC(struct UNK_8085F1C_1 *matrix)",
                      extracted)
        self.assertIn("matrix->unk2[3] = first;", extracted)
        self.assertIn("matrix->unk2[1] = second;", extracted)
        self.assertLess(extracted.index("matrix->unk2[3] = first;"),
                        extracted.index("matrix->unk2[1] = second;"))
        self.assertNotIn(".include ", extracted)

    def test_missing_fallback_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "Missing"):
            probe.extract_c_body("#define NONMATCH(a,b) b")

    def test_truncated_fallback_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "Unterminated"):
            probe.extract_c_body(probe.SOURCE_KEY + ", void f()) {")


if __name__ == "__main__":
    unittest.main()
