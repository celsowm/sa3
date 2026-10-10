#!/usr/bin/env python3
"""Locate SA2-named math code in the European SA3 ROM using true runtime addresses.

Legacy SA2 function suffixes are NOT runtime addresses in SA3. Four original
Thumb entry sequences were independently assembled and found exactly once in
the private, SHA-verified Europe ROM, establishing the +0x2BAD8 section delta.
The other entries use this delta and are verified via SHA-256, not independently
unique-sequence located. Original code-byte intervals include potential data.
No ROM bytes are printed, saved, or uploaded.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

EUROPE_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
ROM_BASE = 0x08000000
LEGACY_TO_SA3_DELTA = 0x2BAD8

# old symbol suffix, exclusive next-symbol suffix, SHA-256 at SA3 runtime offset
RANGES = (
    ("80832FC", "808343C", "7bcc4955aa7a86f6f1ab93ad157bdb3c8eed77356ef0b0ebf25e40d14636b7c6"),
    ("808343C", "8083504", "7566bd24cb3d7d27f6b3d0b3fc2b8d2b9e737e6a0108916dd62c5c7203dc65d3"),
    ("8083858", "80838CC", "7731d2b2b2380d31c83f97421c2224796bdf272647b17912f6f8d39660655d91"),
    ("8083A48", "8083B10", "ff60d999c4632e335886e8179d399c492ae9f3f285dbf5c15d09174609e61516"),
    ("8083B10", "8083B88", "56b0c882b38148d79d9f2848e929deb95dd74c25558abd412b411a9a375b73dd"),
    ("8083B88", "8083E44", "d6a8cff8d5bcd925a77dc582309b34162413935b095de54acd35e3595936f6c6"),
    ("8083E44", "8084090", "b5a303e5d0d8a24798ff73d547c44cf605fbaa71a71b6e5271c938e0bfeee391"),
    ("8084090", "80842E4", "b17cdb328ca52e6df75d7b4ba79a951e6016d49b0df28380d32f6e224d7de1c8"),
    ("80842E4", "808442C", "eaf74c952f27224ef818d687ae560c63c8283a1562ec760387cc806f8ffbcd38"),
    ("808442C", "808458C", "f7b95e266ccdee2d635fc0bb702c435345a21fe55b889d644defea3579d14d19"),
    ("808458C", "808477C", "829ded12a661c24e1dbe0132a04217998edf9629fe52c297ca4e323b9a74308d"),
    ("808477C", "8084904", "e7e18154bef25d2debe4f600e42b642fa4c4ace72a7c230743109a24c2a9246f"),
    ("8084A24", "8084B54", "170bc7d283ad020e74bc1af640145e1d81ba938e62cbd7801825188f3497feea"),
    ("8084C70", "8084EAC", "86dee33129053842f31e800f05cb3a30ff2e3656f39be9da1658e451bcea6de7"),
    ("8084EAC", "8084EE0", "ea1419346318229f9310e1f0ba87ada94f100b056c3200d38027db4eb1675dca"),
    ("8084EE0", "80851E0", "9ebc67cf2f6d381c8793f27ad8339ca88de21bcab1c84a6bc04d7e2da7d17ee1"),
    ("80851E0", "8085314", "481160edc80a8160c389157ab8d94a48078a75c51c379b828153d43fa7542e2d"),
    ("8085314", "80853F8", "c695327b5f88a75acf786b0ad5f73b8c3eeba415bfb83b2f584c237804da0313"),
)

# Distinctive 18-20-byte original ASM prefixes, independently assembled
# with Clang ARMv4T Thumb and searched for UNIQUE matches in the EU ROM.
UNIQUE_PREFIXES = {
    "80832FC": "f0b557464e464546e0b48db080468a4600920193",
    "808343C": "f0b557464e464546e0b482b081468a4600920193",
    "8084A24": "f0b5474680b48446171c0904090c62460020",
    "8084C70": "f0b5051c1f1c0b686b614c68ac618968e961",
}


def verify(rom: bytes) -> dict:
    if hashlib.sha1(rom).hexdigest() != EUROPE_SHA1:
        raise ValueError("ROM SHA-1 differs from the European SA3 matching baseline")
    rows = []
    for old, next_old, expected in RANGES:
        start = int(old, 16) + LEGACY_TO_SA3_DELTA
        end = int(next_old, 16) + LEGACY_TO_SA3_DELTA
        actual = hashlib.sha256(rom[start - ROM_BASE:end - ROM_BASE]).hexdigest()
        if end <= start or actual != expected:
            raise ValueError("SA3 reference interval failed: sa2__sub_" + old)
        if old in UNIQUE_PREFIXES:
            signature = bytes.fromhex(UNIQUE_PREFIXES[old])
            offset = start - ROM_BASE
            if rom[offset:offset + len(signature)] != signature:
                raise ValueError("Independent Thumb signature differs: " + old)
            if rom.count(signature) != 1:
                raise ValueError("Thumb signature is not unique: " + old)
        rows.append({
            "symbol": "sa2__sub_" + old,
            "old_sa2_suffix": "0x" + old.upper(),
            "sa3_runtime_address": f"0x{start:08X}",
            "end_exclusive": f"0x{end:08X}",
            "interval_bytes_upper_bound": end - start,
            "original_interval_sha256": actual,
            "unique_thumb_entry_confirmed": old in UNIQUE_PREFIXES,
            "matching_c_status": "NOT_VERIFIED",
        })
    return {
        "rom_sha1": EUROPE_SHA1,
        "sa2_name_to_sa3_runtime_delta": f"0x{LEGACY_TO_SA3_DELTA:X}",
        "entries": len(rows),
        "distinctive_entries_verified": len(UNIQUE_PREFIXES),
        "interval_bytes_total": sum(r["interval_bytes_upper_bound"] for r in rows),
        "caution": "These are SA3 ROM intervals, NOT compiled matching-C coverage.",
        "functions": rows,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("europe_rom", type=Path, help="PRIVATE matching ROM")
    parser.add_argument("--output", type=Path,
                        help="Metadata-only JSON file (never raw ROM bytes)")
    args = parser.parse_args()
    try:
        report = verify(args.europe_rom.read_bytes())
    except (OSError, ValueError) as exc:
        parser.error(str(exc))
    text = json.dumps(report, indent=2) + "\n"
    if args.output:
        args.output.write_text(text, encoding="utf-8")
    else:
        print(text, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
