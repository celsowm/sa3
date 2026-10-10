#!/usr/bin/env python3
"""Preflight for exact European SA3 matching builds; never uploads ROM data."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

TARGET_SHA1 = "685af3a2dc0f1b3f8922e73ec42c1dc92e210e39"


def check(root: Path, rom: Path, build: bool = False) -> dict:
    root, rom = root.resolve(), rom.resolve()
    result = {"rom": {"exists": rom.is_file()}, "toolchain": {}, "checks": {}, "build": None}
    if rom.is_file():
        with rom.open("rb") as stream:
            digest = hashlib.file_digest(stream, "sha1").hexdigest()
        result["rom"].update({
            "bytes": rom.stat().st_size, "sha1": digest,
            "matches_europe": digest == TARGET_SHA1,
        })
    else:
        result["rom"]["matches_europe"] = False
    for executable in ("make", "arm-none-eabi-as", "arm-none-eabi-ld",
                       "arm-none-eabi-objcopy", "sha1sum"):
        result["toolchain"][executable] = shutil.which(executable)
    agbcc = root / "tools/agbcc/bin/agbcc"
    result["toolchain"]["agbcc"] = str(agbcc) if agbcc.is_file() else None
    for file in ("Makefile", "config.mk", "ldscript.txt", "sa3.sha1"):
        result["checks"][file] = (root / file).is_file()
    ready = (result["rom"]["matches_europe"] and all(result["toolchain"].values())
             and all(result["checks"].values()))
    result["prerequisites_ok"] = bool(ready)
    if build and ready:
        target = root / "baserom_sa3.gba"
        if target.resolve() != rom:
            result["build"] = {
                "status": "blocked",
                "reason": "Place the verified ROM at <repo>/baserom_sa3.gba; no automatic ROM copies.",
            }
        else:
            run = subprocess.run(["make", "compare"], cwd=root, capture_output=True,
                                 text=True, timeout=1200)
            result["build"] = {
                "exit_code": run.returncode,
                "status": "passed" if run.returncode == 0 else "failed",
                "log_tail": "\n".join((run.stdout + "\n" + run.stderr).splitlines()[-30:]),
            }
    result["passed"] = bool(ready and
                            (not build or (result["build"] or {}).get("status") == "passed"))
    return result


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--root", type=Path, default=Path("."))
    ap.add_argument("--rom", type=Path, required=True)
    ap.add_argument("--build", action="store_true",
                    help="Run make compare only when dependencies are ready")
    ap.add_argument("--output", type=Path, help="Optional local JSON report")
    args = ap.parse_args()
    report = check(args.root, args.rom, args.build)
    output = json.dumps(report, indent=2) + "\n"
    if args.output:
        args.output.write_text(output, encoding="utf-8")
    print(output, end="")
    return 0 if report["passed"] else 2


if __name__ == "__main__":
    sys.exit(main())
