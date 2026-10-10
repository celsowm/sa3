#!/usr/bin/env python3
"""Identify SA3 ARM/Thumb return-only ASM candidates, without altering game code.

The standalone ASM inventory contains *upper bounds* between adjacent source
symbols, not proven sizes. This tool checks those bounds against an exact local
European reference ROM, and only reports the specific sequence 70 47 00 00.
The final 00 00 is alignment/padding and must not be called executable code.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path

BASE = 0x08000000
EUROPE_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
THUMB_BX_LR_WITH_PADDING = bytes.fromhex("70470000")


def find_candidates(rows: list[dict[str, str]], rom: bytes) -> list[dict[str, str]]:
    """Pure analysis over trusted inventory metadata and local ROM bytes."""
    found = []
    for row in rows:
        if row.get("kind") != "standalone_asm":
            continue
        try:
            addr = int(row["address"], 16)
            end = int(row["next_address"], 16)
            bound = int(row["span_upper_bound_bytes"])
        except (KeyError, ValueError, TypeError):
            continue
        if bound != 4 or end - addr != 4:
            continue
        offset = addr - BASE
        if offset < 0 or offset + 4 > len(rom):
            continue
        if rom[offset:offset + 4] != THUMB_BX_LR_WITH_PADDING:
            continue
        found.append({
            "symbol": row["symbol"],
            "asm_path": row["asm_path"],
            "address": f"0x{addr:08X}",
            "interval_bytes": 4,
            "thumb_instruction": "bx lr",
            "candidate_c_body": "empty/no-op (signature requires audit)",
            "status": "rom_verified_asm_not_c_matching",
        })
    return sorted(found, key=lambda item: int(item["address"], 16))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path, help="Local private European SA3 baserom")
    parser.add_argument(
        "--inventory", type=Path,
        default=Path("docs/asm_standalone_function_inventory.csv"),
        help="Source-derived inventory committed in the fork",
    )
    parser.add_argument("--output", type=Path, help="Optional metadata-only JSON")
    args = parser.parse_args()
    try:
        rom = args.rom.read_bytes()
        sha = hashlib.sha1(rom).hexdigest()
        if sha != EUROPE_SHA1:
            parser.error("Expected the exact European ROM listed in sa3.sha1")
        with args.inventory.open(newline="", encoding="utf-8") as stream:
            rows = list(csv.DictReader(stream))
        candidates = find_candidates(rows, rom)
        report = {
            "reference_sha1": sha,
            "source_rows": len(rows),
            "verified_return_only_candidates": len(candidates),
            "candidates": candidates,
            "warning": (
                "Do not replace a function without auditing its ABI and return "
                "value and passing the agbcc full-ROM make compare gate."
            ),
        }
        result = json.dumps(report, indent=2) + "\n"
        if args.output:
            args.output.write_text(result, encoding="utf-8")
        else:
            print(result, end="")
        return 0
    except OSError as exc:
        parser.error(str(exc))
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
