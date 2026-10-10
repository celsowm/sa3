#!/usr/bin/env python3
"""Isolated Thumb codegen probe for the SA2-named matrix transpose.

This is a Clang compatibility/size probe, NOT agbcc matching verification.
It extracts the REAL sa2__sub_8084EAC NONMATCH C body from src/game/math.c,
compiles it for ARMv4T/Thumb, and compares its emitted .text to the correct
SA3-Europe ROM runtime interval (never the original SA2 symbol suffix).
No raw ROM bytes or ROM artifact is written or printed.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile

TARGET_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"
START, END = 0x080B0984, 0x080B09B8
SOURCE_KEY = 'NONMATCH("asm/non_matching/game/math/sa2__unused_sub_8084EAC.inc"'
C_HEADER = """#include <stdint.h>
typedef int16_t s16;
struct UNK_8085F1C_1 {
    s16 unk0, unk2[9];
    int32_t unk14, unk18, unk1C;
};
#define NONMATCH(path, decl) decl
#define END_NONMATCH
"""


def extract_c_body(source: str) -> str:
    start = source.find(SOURCE_KEY)
    if start < 0:
        raise ValueError("Missing sa2__sub_8084EAC C fallback")
    end = source.find("END_NONMATCH", start)
    if end < 0:
        raise ValueError("Unterminated sa2__sub_8084EAC C fallback")
    body = source[start:end + len("END_NONMATCH")]
    if body.count("NONMATCH(") != 1 or body.count("{") != body.count("}"):
        raise ValueError("Malformed matrix transpose fallback")
    return C_HEADER + body + "\n"


def compare(clang: str, objcopy: str, original_source: Path, europe_rom: Path) -> dict:
    original = europe_rom.read_bytes()
    if hashlib.sha1(original).hexdigest() != TARGET_SHA1:
        raise ValueError("Only the exact European SA3 matching ROM is valid")
    reference = original[START - 0x08000000:END - 0x08000000]
    with tempfile.TemporaryDirectory(prefix="sa3-math-thumb-") as tmp:
        source_path = Path(tmp) / "matrix_transpose.c"
        object_path = Path(tmp) / "matrix_transpose.o"
        section_path = Path(tmp) / "matrix_transpose.text"
        source_path.write_text(extract_c_body(original_source.read_text()), encoding="utf-8")
        subprocess.run([clang, "-target", "armv4t-none-eabi", "-mthumb",
                        "-O2", "-fno-builtin", "-c", str(source_path),
                        "-o", str(object_path)], check=True)
        subprocess.run([objcopy, "--dump-section", ".text=" + str(section_path),
                        str(object_path)], check=True)
        emitted = section_path.read_bytes()
    first_different = next((i for i, (a, b) in
                            enumerate(zip(emitted, reference)) if a != b),
                           min(len(emitted), len(reference)))
    return {
        "symbol": "sa2__sub_8084EAC",
        "rom_address": f"0x{START:08X}",
        "end_exclusive": f"0x{END:08X}",
        "original_reference_sha256": hashlib.sha256(reference).hexdigest(),
        "original_span_bytes": len(reference),
        "isolated_clang_thumb_bytes": len(emitted),
        "isolated_clang_thumb_sha256": hashlib.sha256(emitted).hexdigest(),
        "first_mismatch_offset": first_different if emitted != reference else None,
        "isolated_clang_byte_identical": emitted == reference,
        "matching_status": "UNVERIFIED_AGBCC_AND_FULL_ROM",
        "warning": "Even identical isolated Clang bytes do not establish full agbcc ROM matching.",
    }


def main() -> int:
    cli = argparse.ArgumentParser(description=__doc__)
    cli.add_argument("europe_rom", type=Path)
    cli.add_argument("--source", type=Path, default=Path("src/game/math.c"))
    cli.add_argument("--clang", default="clang")
    cli.add_argument("--objcopy", default="llvm-objcopy")
    args = cli.parse_args()
    result = compare(args.clang, args.objcopy, args.source, args.europe_rom)
    print(json.dumps(result, indent=2))
    return 0 if result["isolated_clang_byte_identical"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
