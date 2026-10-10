#!/usr/bin/env python3
"""Regenerate metadata-only SA3 ASM backlog from a checked-out source tree.

Optional private European ROM is read only for SHA-256 fingerprints of ranges
BETWEEN source entry labels. Such ranges are UPPER BOUNDS and may contain
padding, literal pools, and data. This tool cannot prove matching C code.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
from collections import Counter
from pathlib import Path

BASE = 0x08000000
EU_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
LABEL = re.compile(r"^([A-Za-z_$][\w.$]*):\s*@\s*0x(08[0-9A-Fa-f]{6})\b", re.M)
INCLUDE = re.compile(r'\b(ASM_FUNC|NONMATCH)\s*\(\s*"([^"]+\.inc)"\s*,', re.M)
FIELDS = ["kind", "asm_path", "symbol", "address", "next_address",
          "span_upper_bound_bytes", "source_files", "macro_kinds",
          "rom_slice_sha256", "priority"]


def function_labels(source: str) -> list[tuple[str, int]]:
    out = [(m[1], int(m[2], 16)) for m in LABEL.finditer(source)]
    if any(b[1] <= a[1] for a, b in zip(out, out[1:])):
        raise ValueError("Nonascending ARM/Thumb source labels")
    return out


def collect(root: Path, european_rom: bytes | None = None) -> dict:
    if european_rom is not None and hashlib.sha1(european_rom).hexdigest() != EU_SHA1:
        raise ValueError("Wrong European reference ROM SHA-1")
    if not (root / "asm").is_dir():
        raise ValueError("Expected checked-out repository with asm/ directory")
    uses: dict[str, list[tuple[str, str]]] = {}
    for file in sorted((root / "src").rglob("*.c")):
        for kind, include in INCLUDE.findall(file.read_text(errors="replace")):
            uses.setdefault(include, []).append((file.relative_to(root).as_posix(), kind))

    rows = []
    for file in sorted((root / "asm").glob("*.s")):
        found = function_labels(file.read_text(errors="replace"))
        for i, (name, address) in enumerate(found):
            next_addr = found[i + 1][1] if i + 1 < len(found) else None
            upper = next_addr - address if next_addr is not None else None
            fingerprint = ""
            if european_rom is not None and upper is not None:
                off = address - BASE
                if 0 <= off and off + upper <= len(european_rom):
                    fingerprint = hashlib.sha256(
                        european_rom[off:off + upper]).hexdigest()
            rows.append({
                "kind": "standalone_asm",
                "asm_path": file.relative_to(root).as_posix(),
                "symbol": name,
                "address": f"0x{address:08X}",
                "next_address": f"0x{next_addr:08X}" if next_addr else "",
                "span_upper_bound_bytes": upper if upper is not None else "",
                "source_files": "",
                "macro_kinds": "",
                "rom_slice_sha256": fingerprint,
                "priority": ("P6-unknown-bound" if upper is None else
                             "P1-small-boundary" if upper <= 32 else
                             "P2-medium-boundary" if upper <= 128 else
                             "P3-complex-boundary"),
            })

    seen = set()
    orphan = 0
    for file in sorted((root / "asm/non_matching").rglob("*.inc")):
        name = file.relative_to(root).as_posix()
        seen.add(name)
        refs = uses.get(name, [])
        if not refs:
            orphan += 1
        rows.append({
            "kind": "asm_inc_fallback",
            "asm_path": name,
            "symbol": file.stem.rsplit("__", 1)[-1],
            "address": "",
            "next_address": "",
            "span_upper_bound_bytes": "",
            "source_files": ";".join(sorted({path for path, _ in refs})),
            "macro_kinds": ";".join(sorted({kind for _, kind in refs})),
            "rom_slice_sha256": "",
            "priority": "P4-inspect-inc" if refs else "P5-unreferenced-inc",
        })

    bounds = [int(row["span_upper_bound_bytes"]) for row in rows
              if row["kind"] == "standalone_asm" and row["span_upper_bound_bytes"] != ""]
    stats = {
        "standalone_entry_labels": sum(row["kind"] == "standalone_asm" for row in rows),
        "bounded_intervals": len(bounds),
        "intervals_le_32": sum(n <= 32 for n in bounds),
        "intervals_le_128": sum(n <= 128 for n in bounds),
        "nonmatching_inc_files": len(seen),
        "orphan_inc_files": orphan,
        "missing_referenced_includes": sorted(set(uses) - seen),
        "fingerprints_use_verified_europe_rom": european_rom is not None,
        "priorities": dict(sorted(Counter(row["priority"] for row in rows).items())),
        "limitation": "Next-entry-label spans are UPPER BOUNDS, not function sizes.",
    }
    return {"stats": stats, "rows": rows}


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--root", type=Path, default=Path("."))
    p.add_argument("--europe-rom", type=Path)
    p.add_argument("--out-csv", type=Path)
    p.add_argument("--out-json", type=Path)
    args = p.parse_args()
    try:
        rom = args.europe_rom.read_bytes() if args.europe_rom else None
        report = collect(args.root, rom)
        if args.out_csv:
            with args.out_csv.open("w", newline="", encoding="utf-8") as f:
                writer = csv.DictWriter(f, fieldnames=FIELDS)
                writer.writeheader()
                writer.writerows(report["rows"])
        if args.out_json:
            args.out_json.write_text(json.dumps(report, indent=2) + "\n")
    except (ValueError, OSError) as exc:
        p.error(str(exc))
    print(json.dumps(report["stats"], indent=2))
    return 1 if report["stats"]["missing_referenced_includes"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
