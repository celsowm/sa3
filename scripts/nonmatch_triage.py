#!/usr/bin/env python3
"""Rank NONMATCH functions by how close their C body is to the target ASM.

For every C file using NONMATCH, compile it twice with the real build
commands (taken from `make -n`): once normally (the .inc ASM is used) and
once with NON_MATCHING defined (the C body is used). Each NONMATCH function
is then disassembled from both objects and the normalized instruction
streams are diffed.

Requires a configured toolchain (agbcc, arm-none-eabi binutils). Output is
a CSV sorted by closeness, so near-misses can be worked first.
"""

import argparse
import csv
import difflib
import os
import re
import shlex
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NONMATCH_RE = re.compile(r'NONMATCH\(\s*"([^"]+)"\s*,[^)]*?\b(\w+)\s*\(', re.S)
FUNC_HDR_RE = re.compile(r"^[0-9a-f]+ <([^>]+)>:$")
INSN_RE = re.compile(r"^\s*[0-9a-f]+:\s+(.*)$")


def find_nonmatch_files():
    result = {}
    for dirpath, _, files in os.walk(os.path.join(ROOT, "src")):
        for name in files:
            if not name.endswith(".c"):
                continue
            path = os.path.join(dirpath, name)
            with open(path, encoding="utf-8", errors="replace") as f:
                text = f.read()
            funcs = [(m.group(2), m.group(1)) for m in NONMATCH_RE.finditer(text)]
            if funcs:
                result[os.path.relpath(path, ROOT)] = funcs
    return result


def build_commands(src):
    obj = "build/gba/sa3/" + src[:-2] + ".o"
    out = subprocess.run(
        ["make", "-n", "-W", src, obj], cwd=ROOT, capture_output=True, text=True, check=True
    ).stdout
    cmds = [l for l in out.splitlines() if l and not l.startswith("echo") and not l.startswith("#")]
    return obj, cmds


def compile_variant(src, workdir, non_matching):
    obj, cmds = build_commands(src)
    base = obj[:-2]
    tag = "nm" if non_matching else "asm"
    new_base = os.path.join(workdir, tag, src[:-2])
    os.makedirs(os.path.dirname(new_base), exist_ok=True)
    for cmd in cmds:
        cmd = cmd.replace(base + ".", new_base + ".")
        if non_matching and cmd.startswith("arm-none-eabi-cpp"):
            cmd = cmd.replace(" -D DEBUG=0", " -D NON_MATCHING=1 -D DEBUG=0", 1)
        r = subprocess.run(cmd, shell=True, cwd=ROOT, capture_output=True, text=True)
        if r.returncode != 0:
            return None, r.stderr.strip().splitlines()[-1:] or ["compile failed"]
    return new_base + ".o", None


def global_funcs(obj):
    out = subprocess.run(["arm-none-eabi-nm", obj], capture_output=True, text=True).stdout
    return {l.split()[-1] for l in out.splitlines() if " T " in l}


def disasm(obj):
    """Return {global function: [normalized insn]} for an object."""
    out = subprocess.run(
        ["arm-none-eabi-objdump", "-d", "--no-show-raw-insn", obj], capture_output=True, text=True
    ).stdout
    globs = global_funcs(obj)
    funcs, cur = {}, None
    for line in out.splitlines():
        m = FUNC_HDR_RE.match(line)
        if m:
            if m.group(1) in globs:
                cur = m.group(1)
                funcs[cur] = []
            continue
        m = INSN_RE.match(line)
        if m and cur:
            insn = normalize(m.group(1))
            if insn != ".short 0x0000":  # alignment padding varies with earlier functions
                funcs[cur].append(insn)
    return funcs


def normalize(insn):
    insn = insn.split(";")[0].split("@")[0].strip()
    insn = re.sub(r"<[^>]*>", "", insn)  # symbolic targets
    parts = insn.split(None, 1)
    op = parts[0]
    args = parts[1] if len(parts) > 1 else ""
    if op.startswith("b") and op not in ("bic", "bics"):
        args = ""  # branch targets differ by layout only
    if op == ".word":
        args = ""  # literal pools (relocations unresolved in .o)
    args = re.sub(r"\[pc, #\d+\]", "[pc]", args)
    args = re.sub(r"^([^,]+), \S+$", r"\1, LIT", args) if op == "ldr" and "pc" in insn else args
    return (op + " " + args).strip()


def score(target, candidate):
    sm = difflib.SequenceMatcher(None, target, candidate, autojunk=False)
    edits = sum(max(i2 - i1, j2 - j1) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != "equal")
    return edits, sm.ratio()


def triage_file(src, funcs, workdir):
    rows = []
    asm_obj, err1 = compile_variant(src, workdir, False)
    nm_obj, err2 = compile_variant(src, workdir, True)
    asm_d = disasm(asm_obj) if asm_obj else {}
    nm_d = disasm(nm_obj) if nm_obj else {}
    for name, inc in funcs:
        target = asm_d.get(name)
        cand = nm_d.get(name)
        row = {"function": name, "file": src, "inc": inc, "target_insns": len(target) if target else "",
               "c_insns": "", "edits": "", "ratio": "", "status": ""}
        if target is None:
            row["status"] = "no-target" + (f": {err1[0]}" if err1 else "")
        elif cand is None:
            row["status"] = "c-compile-error: " + err2[0] if err2 else "no-c-body"
        else:
            edits, ratio = score(target, cand)
            row.update(c_insns=len(cand), edits=edits, ratio=f"{ratio:.3f}",
                       status="match-candidate" if edits == 0 else "diff")
        rows.append(row)
    return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("-o", "--output", default="docs/nonmatch_triage.csv")
    ap.add_argument("-j", "--jobs", type=int, default=os.cpu_count())
    ap.add_argument("--workdir", default="build/triage")
    ap.add_argument("files", nargs="*", help="limit to these C files")
    args = ap.parse_args()

    files = find_nonmatch_files()
    if args.files:
        files = {k: v for k, v in files.items() if k in args.files}
    workdir = os.path.join(ROOT, args.workdir)
    rows = []
    with ThreadPoolExecutor(args.jobs) as ex:
        for r in ex.map(lambda kv: triage_file(kv[0], kv[1], workdir), files.items()):
            rows.extend(r)

    def key(r):
        if r["edits"] == "":
            return (1, 0, r["function"])
        return (0, r["edits"], r["function"])

    rows.sort(key=key)
    with open(os.path.join(ROOT, args.output), "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        w.writeheader()
        w.writerows(rows)
    print(f"{len(rows)} NONMATCH functions in {len(files)} files -> {args.output}", file=sys.stderr)


if __name__ == "__main__":
    main()
