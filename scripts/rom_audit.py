#!/usr/bin/env python3
"""Read-only, region-aware audit of a user-supplied Sonic Advance 3 GBA ROM.

Outputs ROM metadata and *candidate* LZ10 stream offsets without extracting
copyrighted asset bytes. Does not imply that the ROM can be rebuilt from source.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path
from typing import Any, Optional

ROM_BASE = 0x08000000
HEADER_SIZE = 0xC0
MIB = 1024 * 1024
REGIONS = {"B3SE": "USA", "B3SP": "EUROPE"}
EUROPE_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
# Observed from a privately supplied U.S. rev-0 file on 2026-10-10.
# Informational baseline ONLY; this is not the fork's matching target.
OBSERVED_USA_SHA1 = "30db467effa5014806d42db57e2299398a51355b"


def gba_header_complement(data: bytes) -> int:
    """Compute byte at 0xBD from header bytes 0xA0..0xBC inclusive."""
    if len(data) < HEADER_SIZE:
        raise ValueError("ROM is shorter than the GBA header")
    return (-sum(data[0xA0:0xBD]) - 0x19) & 0xFF


def arm_entrypoint(data: bytes) -> Optional[str]:
    """Return target of an initial ARM B, or None for non-B instructions."""
    if len(data) < 4:
        return None
    instruction = int.from_bytes(data[:4], "little")
    # ARM unconditional B (not BL), with PC-relative signed 24-bit displacement.
    if (instruction & 0xFF000000) != 0xEA000000:
        return None
    imm24 = instruction & 0xFFFFFF
    if imm24 & 0x800000:
        imm24 -= 1 << 24
    target = ROM_BASE + 8 + (imm24 << 2)
    return f"0x{target:08X}"


def _segment_summary(data: bytes) -> list[dict[str, Any]]:
    segments = []
    for start in range(0, len(data), MIB):
        block = data[start:start + MIB]
        non_ff = len(block) - block.count(0xFF)
        segments.append({
            "file_offset": f"0x{start:07X}",
            "length": len(block),
            "bytes_not_ff": non_ff,
        })
    return segments


def lz10_consumed_size(data: bytes, start: int, decoded_size: int) -> Optional[int]:
    """Validate an LZ10 token stream and return its stored length.

    Does not copy/decompress user assets. Rejects references to bytes before
    stream start, overshooting output, and truncated tokens. A syntactically
    valid stream is only a *candidate*: pointer/reference checking is required.
    """
    pos = start + 4
    written = 0
    end = len(data)
    while written < decoded_size:
        if pos >= end:
            return None
        flags = data[pos]
        pos += 1
        for shift in range(7, -1, -1):
            if written >= decoded_size:
                break
            if not (flags & (1 << shift)):
                if pos >= end:
                    return None
                pos += 1
                written += 1
            else:
                if pos + 1 >= end:
                    return None
                a, b = data[pos], data[pos + 1]
                pos += 2
                run = (a >> 4) + 3
                lookback = (((a & 0xF) << 8) | b) + 1
                if lookback > written or written + run > decoded_size:
                    return None
                written += run
    return pos - start


def scan_lz10(data: bytes, min_output: int = 64,
              max_output: int = MIB) -> tuple[int, list[dict[str, Any]]]:
    """Scan four-byte aligned offsets for plausible LZ10 streams."""
    if min_output < 1 or max_output < min_output:
        raise ValueError("Invalid decoded-size limits")
    candidates = []
    plausible_headers = 0
    for pos in range(0, len(data) - 4, 4):
        if data[pos] != 0x10:
            continue
        size = data[pos + 1] | (data[pos + 2] << 8) | (data[pos + 3] << 16)
        if not min_output <= size <= max_output:
            continue
        plausible_headers += 1
        consumed = lz10_consumed_size(data, pos, size)
        # Filter accidental uncompressed or larger-than-output sequences.
        if consumed is not None and consumed < size:
            candidates.append({
                "file_offset": f"0x{pos:07X}",
                "rom_address": f"0x{ROM_BASE + pos:08X}",
                "stored_bytes": consumed,
                "decoded_bytes": size,
            })
    return plausible_headers, candidates


def audit_rom(data: bytes, scan_lz: bool = False,
              segments: bool = False) -> dict[str, Any]:
    if len(data) < HEADER_SIZE:
        raise ValueError("File too small to be a Game Boy Advance ROM")
    code = data[0xAC:0xB0].decode("ascii", errors="replace")
    region = REGIONS.get(code, "UNKNOWN")
    sha1 = hashlib.sha1(data).hexdigest()
    result: dict[str, Any] = {
        "title": data[0xA0:0xAC].rstrip(b"\0").decode("ascii", errors="replace"),
        "game_code": code,
        "region": region,
        "maker_code": data[0xB0:0xB2].decode("ascii", errors="replace"),
        "revision": data[0xBC],
        "size_bytes": len(data),
        "sha1": sha1,
        "sha256": hashlib.sha256(data).hexdigest(),
        "gba_fixed_byte_valid": data[0xB2] == 0x96,
        "gba_header_complement_valid": gba_header_complement(data) == data[0xBD],
        "entrypoint": arm_entrypoint(data),
        "matches_upstream_europe_sha1": sha1 == EUROPE_SHA1,
        "matches_observed_usa_rev0_sha1": sha1 == OBSERVED_USA_SHA1,
        "trailing_ff_padding_bytes": len(data) - len(data.rstrip(b"\xFF")),
    }
    if segments:
        result["mib_segments"] = _segment_summary(data)
    if scan_lz:
        headers, found = scan_lz10(data)
        result["lz10"] = {
            "scan_alignment_bytes": 4,
            "min_decoded_bytes": 64,
            "max_decoded_bytes": MIB,
            "plausible_headers": headers,
            "structurally_valid_compressed_candidates": len(found),
            "candidates": found,
            "warning": "Candidate streams are not proven assets; validate ROM pointers and ownership.",
        }
    return result


def main(argv: Optional[list[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path, help="Path to a locally owned ROM (never uploaded)")
    parser.add_argument("--json", action="store_true", help="Emit machine-readable metadata")
    parser.add_argument("--scan-lz10", action="store_true", help="Find structural LZ10 candidates")
    parser.add_argument("--segments", action="store_true", help="Summarize bytes in 1 MiB regions")
    parser.add_argument("--require-region", choices=["USA", "EUROPE"],
                        help="Exit unsuccessfully if region differs")
    parser.add_argument("--require-sha1", help="Exit unsuccessfully unless SHA-1 equals value")
    args = parser.parse_args(argv)
    try:
        report = audit_rom(args.rom.read_bytes(), args.scan_lz10, args.segments)
    except (OSError, ValueError) as exc:
        parser.error(str(exc))

    checks = []
    if args.require_region:
        checks.append(("region", report["region"] == args.require_region))
    if args.require_sha1:
        checks.append(("SHA-1", report["sha1"] == args.require_sha1.lower()))
    checks.append(("header", report["gba_fixed_byte_valid"] and report["gba_header_complement_valid"]))
    report["required_checks_passed"] = all(ok for _, ok in checks)
    report["failed_checks"] = [name for name, ok in checks if not ok]

    if args.json:
        print(json.dumps(report, indent=2, ensure_ascii=True))
    else:
        for key in ("title", "game_code", "region", "maker_code", "revision", "size_bytes",
                    "sha1", "sha256", "entrypoint", "gba_fixed_byte_valid",
                    "gba_header_complement_valid", "matches_upstream_europe_sha1",
                    "matches_observed_usa_rev0_sha1", "trailing_ff_padding_bytes"):
            print(f"{key}: {report[key]}")
        if args.scan_lz10:
            details = report["lz10"]
            print(f"LZ10: {details['structurally_valid_compressed_candidates']} candidates "
                  f"from {details['plausible_headers']} plausible 4-byte-aligned headers")
            for item in details["candidates"]:
                print(f"  {item['rom_address']}  "
                      f"stored={item['stored_bytes']} decoded={item['decoded_bytes']}")
        if args.segments:
            for entry in report["mib_segments"]:
                print(f"{entry['file_offset']}: "
                      f"{entry['bytes_not_ff']}/{entry['length']} bytes != FF")
        if report["failed_checks"]:
            print("FAILED CHECKS: " + ", ".join(report["failed_checks"]), file=sys.stderr)
    return 0 if report["required_checks_passed"] else 2


if __name__ == "__main__":
    sys.exit(main())
