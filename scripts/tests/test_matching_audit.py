"""ROM-free tests for stale/non-matching fallback audits."""
import csv
import importlib.util
import tempfile
import unittest
from pathlib import Path

SCRIPT = Path(__file__).resolve().parents[1] / "matching_audit.py"
SPEC = importlib.util.spec_from_file_location("matching_audit", SCRIPT)
MOD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MOD)


class MatchingAuditTests(unittest.TestCase):
    def fixture(self, root):
        (root / "src/game").mkdir(parents=True)
        (root / "asm/non_matching/game").mkdir(parents=True)
        (root / "docs").mkdir()
        (root / "src/game/actor.c").write_text(
            'NONMATCH("asm/non_matching/game/a.inc", void actor()) {}\n'
            'ASM_FUNC("asm/non_matching/game/b.inc", void helper())\n'
            'NONMATCH("asm/non_matching/game/missing.inc", void lost()) {}\n'
        )
        for n in ("a", "b", "orphan"):
            (root / f"asm/non_matching/game/{n}.inc").write_text("bx lr\n")
        with (root / "docs/nonmatch_triage.csv").open("w", newline="") as fp:
            writer = csv.DictWriter(fp, fieldnames=MOD.FIELDS)
            writer.writeheader()
            writer.writerow(dict(function="actor", file="src/game/actor.c",
                                 inc="asm/non_matching/game/a.inc", target_insns=55,
                                 c_insns=55, edits=1, ratio=".982", status="diff"))
            writer.writerow(dict(function="stale", file="src/game/actor.c",
                                 inc="asm/non_matching/game/orphan.inc", target_insns=4,
                                 c_insns=4, edits=0, ratio="1.000", status="match-candidate"))

    def test_merge_regression_detection(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            self.fixture(root)
            result = MOD.audit(root)
            self.assertEqual(result["counts"]["inc_files"], 3)
            self.assertEqual(result["counts"]["nonmatch_references"], 1)
            self.assertEqual(result["counts"]["asm_func_references"], 1)
            self.assertEqual(result["missing_referenced_inc"], ["asm/non_matching/game/missing.inc"])
            self.assertEqual(result["unreferenced_inc"], ["asm/non_matching/game/orphan.inc"])
            self.assertEqual(result["stale_ranking"], ["asm/non_matching/game/orphan.inc"])
            self.assertEqual(result["near_match_queue"][0]["function"], "actor")
            self.assertIn("ROM-free", MOD.markdown(result))

    def test_unranked_and_grouped(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            self.fixture(root)
            (root / "asm/non_matching/game/new.inc").write_text("bx lr")
            with (root / "src/game/actor.c").open("a") as fp:
                fp.write('NONMATCH("asm/non_matching/game/new.inc", void new_actor()) {}\n')
            result = MOD.audit(root)
            self.assertEqual(result["unranked_active_nonmatch"], ["asm/non_matching/game/new.inc"])

    def test_missing_bad_root(self):
        with tempfile.TemporaryDirectory() as tmp:
            with self.assertRaisesRegex(ValueError, "root must contain"):
                MOD.audit(Path(tmp))
            with self.assertRaisesRegex(ValueError, "limit"):
                root = Path(tmp)
                (root / "src").mkdir()
                (root / "asm/non_matching").mkdir(parents=True)
                MOD.audit(root, limit=-1)


if __name__ == "__main__":
    unittest.main()
