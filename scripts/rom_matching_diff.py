#!/usr/bin/env python3
"""Private ROM-vs-ROM exact matching report for Sonic Advance 3.

Reads a local European reference and locally compiled ROM, prints *only*
metadata (digests, mismatch counts/offsets), never ROM bytes. Can inspect
known function intervals or additional user-supplied symbol intervals. A
matching ROM interval is not proof that its C source was decompiled.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

EU_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
GBA_BASE = 0x08000000
KNOWN = (
    ("Task_802F368", 0x0802F368, 0x0802F698),
    ("Task_802F698", 0x0802F698, 0x0802F9C4),
)


def mismatch_metrics(a: bytes, b: bytes, address_base: int = GBA_BASE) -> dict:
    """Count byte differences, including any excess bytes in either file."""
    common = min(len(a), len(b))
    mismatched = sum(x != y for x, y in zip(a, b))
    mismatched += abs(len(a) - len(b))
    first = next((idx for idx in range(common) if a[idx] != b[idx]), None)
    if first is None and len(a) != len(b):
        first = common
    return {
        "reference_bytes": len(a), "candidate_bytes": len(b),
        "mismatched_bytes": mismatched,
        "first_mismatch_address": f"0x{address_base + first:08X}" if first is not None else None,
        "exact_match": mismatched == 0,
    }


def parse_window(spec: str) -> tuple[str, int, int]:
    """Parse NAME:START:END (hex ROM addresses, exclusive end)."""
    try:
        name, start_text, end_text = spec.split(":")
        start, end = int(start_text, 0), int(end_text, 0)
    except ValueError as err:
        raise ValueError("Expected NAME:0xSTART:0xEND") from err
    if not name or not (GBA_BASE <= start < end):
        raise ValueError("Invalid window name or ROM address range")
    return name, start, end


def compare(reference: bytes, candidate: bytes,
            windows: tuple[tuple[str, int, int], ...] = KNOWN,
            verify_europe: bool = True) -> dict:
    reference_sha = hashlib.sha1(reference).hexdigest()
    if verify_europe and reference_sha != EU_SHA1:
        raise ValueError("Reference ROM SHA-1 does not match SA3 Europe rev-0")
    result = {
        "reference_sha1": reference_sha,
        "candidate_sha1": hashlib.sha1(candidate).hexdigest(),
        "full_rom": mismatch_metrics(reference, candidate),
        "windows": [],
        "warning": "ROM byte equality does not by itself establish decompiled-code coverage.",
    }
    names = set()
    for name, start, end in windows:
        if name in names:
            raise ValueError(f"Duplicate name: {name}")
        names.add(name)
        if not (GBA_BASE <= start < end <= GBA_BASE + len(reference)):
            raise ValueError(f"Window out of reference ROM bounds: {name}")
        off, stop = start - GBA_BASE, end - GBA_BASE
        span = mismatch_metrics(reference[off:stop], candidate[off:stop], start)
        span.update({"name": name, "start": f"0x{start:08X}",
                     "end_exclusive": f"0x{end:08X}"})
        result["windows"].append(span)
    return result


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("reference", type=Path, help="private original Europe rev-0 ROM")
    p.add_argument("candidate", type=Path, help="locally compiled sa3.gba")
    p.add_argument("--window", action="append", default=[],
                   help="add window NAME:0xSTART:0xEND, end exclusive")
    p.add_argument("--only-windows", action="store_true", help="omit built-in platform windows")
    p.add_argument("--output", type=Path, help="write JSON metadata report")
    args = p.parse_args()
    try:
        extra = tuple(parse_window(s) for s in args.window)
        windows = (() if args.only_windows else KNOWN) + extra
        report = compare(args.reference.read_bytes(), args.candidate.read_bytes(), windows)
    except (ValueError, OSError) as ex:
        p.error(str(ex))
    json_text = json.dumps(report, indent=2) + "\n"
    if args.output:
        args.output.write_text(json_text, encoding="utf-8")
    else:
        print(json_text, end="")
    return 0 if report["full_rom"]["exact_match"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
