#!/usr/bin/env python3
"""ROM-free consistency audit for the SA3 matching backlog.

This reports source-level fallback ownership and cross-checks the saved
instruction triage CSV; it cannot prove a ROM match or update percentages.
Run after merges and before selecting agbcc matching candidates.
"""
from __future__ import annotations

import argparse
import csv
import json
import re
from collections import Counter, defaultdict
from pathlib import Path

REFERENCE = re.compile(r'\b(NONMATCH|ASM_FUNC)\s*\(\s*"([^"\n]+\.inc)"\s*,', re.M)
FIELDS = ("function", "file", "inc", "target_insns", "c_insns", "edits", "ratio", "status")


def audit(root: Path, ranking: Path | None = None, limit: int = 20) -> dict:
    root = root.resolve()
    if not (root / "src").is_dir() or not (root / "asm/non_matching").is_dir():
        raise ValueError("root must contain src/ and asm/non_matching/")
    if limit < 0:
        raise ValueError("limit must be non-negative")

    uses: dict[str, list[dict]] = defaultdict(list)
    for src in sorted((root / "src").rglob("*.c")):
        body = src.read_text(encoding="utf-8", errors="replace")
        for match in REFERENCE.finditer(body):
            uses[match.group(2)].append({
                "kind": match.group(1),
                "source": src.relative_to(root).as_posix(),
            })

    existing = {p.relative_to(root).as_posix()
                for p in (root / "asm/non_matching").rglob("*.inc")}
    missing = sorted(set(uses) - existing)
    unreferenced = sorted(existing - set(uses))
    active = {inc: refs for inc, refs in uses.items() if inc in existing}
    kind_counts = Counter(ref["kind"] for refs in active.values() for ref in refs)

    ranking = ranking or root / "docs/nonmatch_triage.csv"
    ranked: list[dict] = []
    if ranking.exists():
        with ranking.open(newline="", encoding="utf-8") as fp:
            reader = csv.DictReader(fp)
            if not set(FIELDS).issubset(reader.fieldnames or ()):
                raise ValueError("triage CSV missing required columns")
            ranked = list(reader)

    ranked_paths = Counter(row["inc"] for row in ranked)
    ranked_missing = sorted(inc for inc in ranked_paths if inc not in existing)
    duplicate_ranking = sorted(inc for inc, count in ranked_paths.items() if count > 1)
    active_nonmatch = {inc for inc, refs in active.items() if any(x["kind"] == "NONMATCH" for x in refs)}
    unranked_nonmatch = sorted(active_nonmatch - set(ranked_paths))
    stale_ranking = sorted(set(ranked_paths) - active_nonmatch)

    queue = []
    for row in ranked:
        if row["inc"] not in active_nonmatch:
            continue
        try:
            edits, target_insns = int(row["edits"]), int(row["target_insns"])
        except (TypeError, ValueError):
            continue
        queue.append({
            "function": row["function"], "source": row["file"],
            "inc": row["inc"], "edits": edits, "target_insns": target_insns,
            "ratio": row["ratio"],
        })
    queue.sort(key=lambda row: (row["edits"], -row["target_insns"], row["function"]))

    near = [row for row in queue if row["edits"] <= 5]
    grouped: dict[str, list[dict]] = defaultdict(list)
    for row in near:
        grouped[row["source"]].append(row)
    coupled = [{"source": src, "candidates": values}
               for src, values in sorted(grouped.items()) if len(values) >= 2]
    coupled.sort(key=lambda group: (-sum(x["target_insns"] for x in group["candidates"]), group["source"]))

    return {
        "counts": {
            "inc_files": len(existing), "active_inc_files": len(active),
            "nonmatch_references": kind_counts["NONMATCH"],
            "asm_func_references": kind_counts["ASM_FUNC"],
            "ranked_rows": len(ranked), "candidate_rows": len(queue),
        },
        "missing_referenced_inc": missing,
        "unreferenced_inc": unreferenced,
        "ranked_missing_inc": ranked_missing,
        "duplicate_ranking": duplicate_ranking,
        "unranked_active_nonmatch": unranked_nonmatch,
        "stale_ranking": stale_ranking,
        "near_match_queue": queue[:limit],
        "coupled_near_matches": coupled[:limit],
        "limitations": [
            "CSV edit distances are from the last recorded agbcc triage, not a fresh build.",
            "Instruction counts and edit distances are not ROM-byte matching metrics.",
            "Only make compare and sha1sum -c sa3.sha1 establish full matching.",
        ],
    }


def markdown(report: dict) -> str:
    c = report["counts"]
    lines = ["# SA3 matching fallback audit", "",
             "> ROM-free inventory. A successful report is not a ROM match.", "",
             f"- `.inc` files: **{c['inc_files']}**; actively referenced: **{c['active_inc_files']}**",
             f"- `NONMATCH` refs: **{c['nonmatch_references']}**; `ASM_FUNC` refs: **{c['asm_func_references']}**",
             f"- Ranked rows: **{c['ranked_rows']}**; valid ranked candidates: **{c['candidate_rows']}**", ""]
    for field, title in [
        ("missing_referenced_inc", "Missing references (must repair)"),
        ("unreferenced_inc", "Unreferenced fallbacks (review before deleting)"),
        ("unranked_active_nonmatch", "Active NONMATCH missing from saved triage"),
        ("stale_ranking", "Stale ranking entries"),
        ("ranked_missing_inc", "Ranked paths absent on disk"),
        ("duplicate_ranking", "Duplicate ranking paths"),
    ]:
        lines += [f"## {title}", ""]
        lines += [f"- `{name}`" for name in report[field]] or ["None."]
        lines += [""]
    lines += ["## Near matches (old ranking; recompile before promotion)", "",
              "| Function | C source | Instruction edits | Original instructions |", "|---|---|---:|---:|"]
    for row in report["near_match_queue"]:
        lines.append(f"| `{row['function']}` | `{row['source']}` | {row['edits']} | {row['target_insns']} |")
    lines += ["", "## Related functions worth compiling together", ""]
    for group in report["coupled_near_matches"]:
        names = ", ".join(x["function"] for x in group["candidates"])
        lines.append(f"- `{group['source']}`: {names}")
    lines += ["", "## Evidence restrictions", ""]
    lines += [f"- {value}" for value in report["limitations"]]
    return "\n".join(lines) + "\n"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1])
    ap.add_argument("--triage", type=Path, help="override saved triage CSV")
    ap.add_argument("--limit", type=int, default=20)
    ap.add_argument("--json", action="store_true", help="machine-readable output")
    ap.add_argument("--strict", action="store_true", help="fail for missing references or stale triage")
    ap.add_argument("--output", type=Path, help="save Markdown/JSON report")
    args = ap.parse_args()
    try:
        result = audit(args.root, args.triage, args.limit)
    except (ValueError, OSError) as ex:
        ap.error(str(ex))
    output = json.dumps(result, indent=2) + "\n" if args.json else markdown(result)
    if args.output:
        args.output.write_text(output, encoding="utf-8")
    else:
        print(output, end="")
    issues = ("missing_referenced_inc", "unranked_active_nonmatch", "stale_ranking",
              "ranked_missing_inc", "duplicate_ranking")
    return int(args.strict and any(result[k] for k in issues))


if __name__ == "__main__":
    raise SystemExit(main())
