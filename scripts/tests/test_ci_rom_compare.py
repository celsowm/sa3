"""Regression tests for distinct original/input and compiled/output ROM checks.

These tests use synthetic bytes, never a commercial game ROM.
"""
import hashlib
import subprocess
import tempfile
import unittest
from pathlib import Path

SCRIPT = "awk '{print $1 \"  baserom_sa3.gba\"}' sa3.sha1 | sha1sum -c -"


class RomCompareWorkflowTests(unittest.TestCase):
    def test_check_original_before_output_exists(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            payload = b"synthetic-gba-header-for-hash-test"
            (root / "baserom_sa3.gba").write_bytes(payload)
            expected = hashlib.sha1(payload).hexdigest()
            (root / "sa3.sha1").write_text(f"{expected}  sa3.gba\n")
            self.assertFalse((root / "sa3.gba").exists())
            result = subprocess.run(["bash", "-o", "pipefail", "-c", SCRIPT], cwd=root,
                                    capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertIn("baserom_sa3.gba: OK", result.stdout)

    def test_corrupt_original_rejected_even_without_output(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            expected = hashlib.sha1(b"correct-bytes").hexdigest()
            (root / "sa3.sha1").write_text(f"{expected}  sa3.gba\n")
            (root / "baserom_sa3.gba").write_bytes(b"wrong-bytes")
            result = subprocess.run(["bash", "-o", "pipefail", "-c", SCRIPT], cwd=root,
                                    capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)

    def test_workflow_runs_checks_in_correct_order(self):
        workflow = Path(__file__).resolve().parents[2] / ".github/workflows/build.yml"
        if not workflow.exists():
            self.skipTest("GitHub Actions workflow not present in sparse test workspace")
        content = workflow.read_text()
        fetch = content.index("- name: Fetch private baserom")
        compare = content.index("- name: Compare", fetch)
        self.assertIn(SCRIPT, content[fetch:compare])
        self.assertNotIn("sha1sum -c sa3.sha1", content[fetch:compare].replace(
            "# sha1sum -c sa3.sha1 checks the generated sa3.gba, which does", ""))
        self.assertIn("sha1sum -c sa3.sha1", content[compare:])


if __name__ == "__main__":
    unittest.main()
