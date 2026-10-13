#!/usr/bin/env python3
"""Private Europe-ROM fingerprints for the two SA3 platform NONMATCH routines.

The reference intervals include instruction and literal/padding bytes; they
are not validated source-level function sizes. No ROM data is emitted.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

BASE = 0x08000000
EUROPE_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
INTERVALS = (
    ("Task_802F368", 0x0802F368, 0x0802F698,
     "bc14b09a54e89b28a67b6cab0e55f5fb4d16a8e768caa9ae50f1303da7a3648a"),
    ("Task_802F698", 0x0802F698, 0x0802F9C4,
     "548a349bb6842f5939b294cf1a9757e4095095f770d56e8665c5e8d11a884689"),
)


def interval_sha256(data: bytes, start: int, end: int) -> str:
    if end <= start or start < BASE or end > BASE + len(data):
        raise ValueError("Invalid Europe ROM interval")
    return hashlib.sha256(data[start - BASE:end - BASE]).hexdigest()


def validate_local_europe_rom(path: Path) -> dict:
    """Require the exact source ROM; return only metadata and hashes."""
    data = path.read_bytes()
    sha1 = hashlib.sha1(data).hexdigest()
    if sha1 != EUROPE_SHA1:
        raise ValueError("Expected Europe rev-0 Sonic Advance 3 ROM")
    output = []
    for name, start, end, expected in INTERVALS:
        observed = interval_sha256(data, start, end)
        if observed != expected:
            raise ValueError(f"Original ROM interval mismatch: {name}")
        output.append({
            "symbol": name,
            "start": f"0x{start:08X}",
            "end_exclusive": f"0x{end:08X}",
            "upper_bound_span_bytes": end - start,
            "span_sha256": observed,
            "matching_c_verified": False,
        })
    return {"rom_sha1": sha1, "intervals": output,
            "note": "ROM originals verified; not proof of compiled C matching"}


if __name__ == "__main__":
    import argparse
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("rom", type=Path, help="private baserom_sa3.gba (never upload)")
    args = p.parse_args()
    print(json.dumps(validate_local_europe_rom(args.rom), indent=2))
