#!/usr/bin/env python3
"""Compare locally owned EU/USA GBA ROMs by bytes and decoded LZ10 hashes.

Read-only: prints metadata and never exports ROM or decoded asset bytes.
Matching assets are NOT evidence of matching C code or a reproducible ROM build.
Requires sibling scripts/rom_audit.py.
"""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
from typing import Any

from rom_audit import audit_rom, find_rom_pointer_sites, scan_lz10

EUROPE_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
USA_OBSERVED_SHA1 = "30db467effa5014806d42db57e2299398a51355b"
MIB = 1 << 20


def decode_lz10(data: bytes, start: int, expected_size: int) -> bytes:
    """Decode a validated GBA LZ10 candidate into temporary memory only."""
    if start < 0 or start + 4 > len(data) or data[start] != 0x10:
        raise ValueError("Invalid LZ10 header")
    declared = int.from_bytes(data[start + 1:start + 4], "little")
    if declared != expected_size or not 1 <= expected_size <= MIB:
        raise ValueError("Invalid LZ10 decoded size")
    pos = start + 4
    out = bytearray()
    while len(out) < expected_size:
        if pos >= len(data):
            raise ValueError("Truncated LZ10 flags")
        flags = data[pos]
        pos += 1
        for bit in range(7, -1, -1):
            if len(out) >= expected_size:
                break
            if flags & (1 << bit):
                if pos + 2 > len(data):
                    raise ValueError("Truncated LZ10 backreference")
                hi, lo = data[pos], data[pos + 1]
                pos += 2
                count = (hi >> 4) + 3
                distance = (((hi & 15) << 8) | lo) + 1
                if distance > len(out) or len(out) + count > expected_size:
                    raise ValueError("Invalid LZ10 backreference")
                for _ in range(count):
                    out.append(out[-distance])
            else:
                if pos >= len(data):
                    raise ValueError("Truncated LZ10 literal")
                out.append(data[pos])
                pos += 1
    return bytes(out)


def candidate_inventory(data: bytes) -> dict[str, Any]:
    headers, candidates = scan_lz10(data)
    result = []
    for c in candidates:
        address = int(c["rom_address"], 16)
        decoded = decode_lz10(data, int(c["file_offset"], 16), c["decoded_bytes"])
        result.append({
            "rom_address": c["rom_address"],
            "stored_bytes": c["stored_bytes"],
            "decoded_bytes": c["decoded_bytes"],
            "decoded_sha256": hashlib.sha256(decoded).hexdigest(),
            "pointer_sites": find_rom_pointer_sites(data, address),
        })
    return {"plausible_headers": headers, "candidates": result}


def byte_comparison(left: bytes, right: bytes) -> dict[str, Any]:
    """Offset-aligned byte comparison; not a code/region equivalence proof."""
    if len(left) != len(right):
        raise ValueError("Different ROM lengths")
    segments = []
    differences = 0
    runs = 0
    previous_diff = False
    for start in range(0, len(left), MIB):
        mismatches = 0
        for x, y in zip(left[start:start + MIB], right[start:start + MIB]):
            different = x != y
            mismatches += different
            if different and not previous_diff:
                runs += 1
            previous_diff = different
        differences += mismatches
        segments.append({"file_offset": f"0x{start:07X}", "different_bytes": mismatches})
    identical_4kb = sum(
        left[i:i + 4096] == right[i:i + 4096]
        for i in range(0, len(left), 4096)
    )
    return {
        "different_bytes": differences,
        "identical_bytes": len(left) - differences,
        "identical_percent": round(100 * (len(left) - differences) / len(left), 5),
        "different_contiguous_runs": runs,
        "identical_4kb_blocks": identical_4kb,
        "total_4kb_blocks": (len(left) + 4095) // 4096,
        "per_mib": segments,
    }


def compare_roms(europe: bytes, usa: bytes) -> dict[str, Any]:
    euro_meta = audit_rom(europe)
    usa_meta = audit_rom(usa)
    if euro_meta["region"] != "EUROPE" or usa_meta["region"] != "USA":
        raise ValueError("Expected EUROPE ROM first, USA ROM second")
    if not euro_meta["gba_header_complement_valid"] or not usa_meta["gba_header_complement_valid"]:
        raise ValueError("Invalid GBA header checksum")

    eu_items = candidate_inventory(europe)
    us_items = candidate_inventory(usa)
    usa_by_hash: dict[tuple[int, str], list[dict[str, Any]]] = {}
    for c in us_items["candidates"]:
        usa_by_hash.setdefault((c["decoded_bytes"], c["decoded_sha256"]), []).append(c)

    correspondences = []
    for c in eu_items["candidates"]:
        for u in usa_by_hash.get((c["decoded_bytes"], c["decoded_sha256"]), []):
            correspondences.append({
                "europe_address": c["rom_address"],
                "usa_address": u["rom_address"],
                "address_delta_bytes": int(c["rom_address"], 16) - int(u["rom_address"], 16),
                "decoded_bytes": c["decoded_bytes"],
                "decoded_sha256": c["decoded_sha256"],
                "europe_pointer_sites": c["pointer_sites"],
                "usa_pointer_sites": u["pointer_sites"],
            })
    return {
        "disclaimer": "Metadata only; does not establish matching functions or a working build.",
        "europe": {
            "sha1": euro_meta["sha1"],
            "game_code": euro_meta["game_code"],
            "matches_target": euro_meta["sha1"] == EUROPE_SHA1,
        },
        "usa": {
            "sha1": usa_meta["sha1"],
            "game_code": usa_meta["game_code"],
            "matches_observed_file": usa_meta["sha1"] == USA_OBSERVED_SHA1,
        },
        "aligned_bytes": byte_comparison(europe, usa),
        "lz10": {
            "eu_plausible_headers": eu_items["plausible_headers"],
            "usa_plausible_headers": us_items["plausible_headers"],
            "eu_structurally_valid_candidates": len(eu_items["candidates"]),
            "usa_structurally_valid_candidates": len(us_items["candidates"]),
            "eu_pointer_backed": sum(bool(c["pointer_sites"]) for c in eu_items["candidates"]),
            "usa_pointer_backed": sum(bool(c["pointer_sites"]) for c in us_items["candidates"]),
            "eu_candidates_with_usa_decoded_match": len(
                {p["europe_address"] for p in correspondences}
            ),
            "matched_pairs_including_duplicate_contents": len(correspondences),
            "cross_region_matches": correspondences,
        },
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("europe", type=Path, help="Local European SA3 ROM")
    parser.add_argument("usa", type=Path, help="Local US SA3 ROM")
    parser.add_argument("--output", type=Path, help="Write metadata JSON locally")
    args = parser.parse_args()
    try:
        result = compare_roms(args.europe.read_bytes(), args.usa.read_bytes())
    except (OSError, ValueError) as exc:
        parser.error(str(exc))
    report = json.dumps(result, indent=2) + "\n"
    if args.output:
        args.output.write_text(report, encoding="utf-8")
    else:
        print(report, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
