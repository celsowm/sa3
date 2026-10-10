#!/usr/bin/env python3
"""Europe-ROM reference oracle for SA3 boss_2 sub_806CFD4.

No game ROM, assets or extracted instructions are stored in this repository.
The comparison is intentionally limited to the original 72-byte ROM range;
this is an original ASM function, NOT a matching-C conversion.
"""
from __future__ import annotations

import hashlib
from pathlib import Path

BASE = 0x08000000
START = 0x0806CFD4
END = 0x0806D01C
ROM_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
ORIGINAL_SPAN_SHA256 = "90b2fc662a30ffd5bf7693e8ebce4da3a744cabc389a2f4653daf509f0639ba1"
BOUNDARY_Q8 = -120 * 256


def signed32(number: int) -> int:
    number &= 0xFFFFFFFF
    return number - 0x100000000 if number & 0x80000000 else number


def reference_logic(q_y: int, camera_y: int) -> tuple[int, int]:
    """Model observed ASM, returning (new q_y, clamped flag).

    All intermediate integer operations wrap to signed 32-bit; the ROM uses
    arithmetic shift-right before subtracting camera_y. At extreme inputs
    the signed condition is evaluated against the ARM flags, not Python big
    integers. The typical gameplay-range model below avoids such overflows.
    """
    screen_pixels = signed32(q_y) >> 8
    difference = signed32(screen_pixels - signed32(camera_y))
    screen_q8 = signed32(difference << 8)
    threshold = BOUNDARY_Q8
    # CMP + BLE after first signed range test. If not below/equal, subtract
    # 4px in Q8 and check CMP + BGE. Very large values would require direct
    # ARM flag emulation for exact overflow behavior; inputs are bounded.
    if screen_q8 <= threshold:
        return signed32(signed32(camera_y << 8) + threshold), 1
    adjusted = signed32(screen_q8 - 4 * 256)
    if adjusted < threshold:
        return signed32(signed32(camera_y << 8) + threshold), 1
    return signed32(signed32(camera_y << 8) + adjusted), 0


def validate_local_europe_rom(path: Path) -> dict:
    """Read private local ROM bytes; return only fingerprint metadata."""
    data = path.read_bytes()
    rom_sha1 = hashlib.sha1(data).hexdigest()
    if rom_sha1 != ROM_SHA1:
        raise ValueError("Not the matching Europe rev-0 reference ROM")
    span = data[START - BASE:END - BASE]
    observed = hashlib.sha256(span).hexdigest()
    if len(span) != 72 or observed != ORIGINAL_SPAN_SHA256:
        raise ValueError("Original sub_806CFD4 reference region differs")
    return {
        "rom_sha1": rom_sha1,
        "symbol": "sub_806CFD4",
        "start": f"0x{START:08X}",
        "end_exclusive": f"0x{END:08X}",
        "rom_span_bytes": len(span),
        "original_rom_span_sha256": observed,
        "status": "reference_asm_verified_c_not_matching",
    }


if __name__ == "__main__":
    import argparse
    import json
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("rom", type=Path)
    args = p.parse_args()
    print(json.dumps(validate_local_europe_rom(args.rom), indent=2))
