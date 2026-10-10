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
RELOC_RE = re.compile(r"^\s*[0-9a-f]+:\s+R_ARM_\w+\s+(\S+)$")


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


def as_plain_c(text):
    """Turn every NONMATCH(path, decl) ... END_NONMATCH into plain C.

    This is the state after promoting all of them, and unlike defining
    NON_MATCHING it keeps `#ifndef NON_MATCHING` matching hacks active."""
    out, i = [], 0
    while True:
        j = text.find("NONMATCH(", i)
        if j < 0 or (j > 0 and (text[j - 1].isalnum() or text[j - 1] == "_")):
            if j < 0:
                break
            out.append(text[i : j + 1])
            i = j + 1
            continue
        k, depth = j + len("NONMATCH"), 0
        while True:
            depth += {"(": 1, ")": -1}.get(text[k], 0)
            k += 1
            if depth == 0:
                break
        inner = text[j + len("NONMATCH(") : k - 1]
        decl = inner[inner.index('"', inner.index('"') + 1) + 1 :].lstrip().lstrip(",")
        out.append(text[i:j] + decl.strip())
        i = k
    out.append(text[i:])
    return "".join(out).replace("END_NONMATCH", "")


def compile_variant(src, workdir, non_matching):
    obj, cmds = build_commands(src)
    base = obj[:-2]
    tag = "nm" if non_matching else "asm"
    new_base = os.path.join(workdir, tag, src[:-2])
    os.makedirs(os.path.dirname(new_base), exist_ok=True)
    tmp_src = None
    if non_matching:
        # Next to the original so relative includes still resolve.
        tmp_src = os.path.join(os.path.dirname(src), ".triage_" + os.path.basename(src))
        with open(os.path.join(ROOT, src), encoding="utf-8") as f:
            text = as_plain_c(f.read())
        with open(os.path.join(ROOT, tmp_src), "w", encoding="utf-8") as f:
            f.write(text)
    try:
        for cmd in cmds:
            cmd = cmd.replace(base + ".", new_base + ".")
            if tmp_src and cmd.startswith("arm-none-eabi-cpp"):
                cmd = cmd.replace(" " + src + " ", " " + tmp_src + " ")
            r = subprocess.run(cmd, shell=True, cwd=ROOT, capture_output=True, text=True)
            if r.returncode != 0:
                errs = [l for l in r.stderr.splitlines() if "rror" in l] or r.stderr.strip().splitlines()[-1:]
                return None, errs or ["compile failed"]
    finally:
        if tmp_src:
            os.remove(os.path.join(ROOT, tmp_src))
    return new_base + ".o", None


def global_funcs(obj):
    out = subprocess.run(["arm-none-eabi-nm", obj], capture_output=True, text=True).stdout
    return {l.split()[-1] for l in out.splitlines() if " T " in l}


def disasm(obj, targets=False):
    """Return {global function: [normalized insn]} for an object.

    With targets=True, branches keep their destination as an instruction
    index within the function (for --show)."""
    out = subprocess.run(
        ["arm-none-eabi-objdump", "-dzr", "--no-show-raw-insn", obj], capture_output=True, text=True
    ).stdout
    globs = global_funcs(obj)
    funcs, addrs, cur = {}, {}, None
    for line in out.splitlines():
        m = FUNC_HDR_RE.match(line)
        if m:
            if m.group(1) in globs:
                cur = m.group(1)
                funcs[cur], addrs[cur] = [], []
            continue
        m = RELOC_RE.match(line)
        if m and cur and funcs[cur] and funcs[cur][-1] == ".word":
            funcs[cur][-1] = ".word " + m.group(1)
            continue
        m = INSN_RE.match(line)
        if m and cur:
            insn = normalize(m.group(1))
            if insn != ".short 0x0000":  # alignment padding varies with earlier functions
                funcs[cur].append(insn)
                addrs[cur].append((int(line.split(":")[0], 16), m.group(1)))
    if targets:
        for name, insns in funcs.items():
            index = {a: i for i, (a, _) in enumerate(addrs[name])}
            for i, (_, raw) in enumerate(addrs[name]):
                b = re.match(r"(b\w*(?:\.n|\.w)?)\s+([0-9a-f]+)\b", raw)
                if b and int(b.group(2), 16) in index:
                    insns[i] = f"{insns[i]} ->{index[int(b.group(2), 16)]}"
            insns[:] = [f"{i:3} {x}" for i, x in enumerate(insns)]
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


def show(func, workdir, verbose=False):
    for src, funcs in find_nonmatch_files().items():
        if func in (f for f, _ in funcs):
            break
    else:
        sys.exit(f"{func}: not a NONMATCH function")
    objs = []
    for nm in (False, True):
        obj, err = compile_variant(src, workdir, nm)
        if obj is None:
            sys.exit(f"compile failed: {err[0]}")
        objs.append(obj)
    target, cand = (disasm(o)[func] for o in objs)
    if verbose:
        t2, c2 = (disasm(o, targets=True)[func] for o in objs)
        strip = lambda x: x.split(None, 1)[1]
        sm = difflib.SequenceMatcher(None, [strip(x) for x in t2], [strip(x) for x in c2], autojunk=False)
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag == "equal":
                continue
            lo, hi = max(i1 - 4, 0), i2 + 4
            print(f"@@ target {i1}-{i2} / c {j1}-{j2} ({tag})")
            for k in range(lo, hi):
                if k >= len(t2):
                    break
                mark = "-" if i1 <= k < i2 else " "
                print(f"{mark} {t2[k]}")
            for k in range(j1, j2):
                print(f"+ {c2[k]}")
    else:
        for line in difflib.unified_diff(target, cand, "target", "c", n=4, lineterm=""):
            print(line)
    print(f"edits={score(target, cand)[0]}", file=sys.stderr)


def promote(func):
    for src, funcs in find_nonmatch_files().items():
        inc = dict(funcs).get(func)
        if inc:
            break
    else:
        sys.exit(f"{func}: not a NONMATCH function")
    path = os.path.join(ROOT, src)
    with open(path, encoding="utf-8") as f:
        text = f.read()
    m = re.search(r'NONMATCH\(\s*"' + re.escape(inc) + r'"\s*,\s*(.*?)\)\s*\n\{', text, re.S)
    decl = re.sub(r"\s+", " ", m.group(1))
    end = text.index("END_NONMATCH\n", m.end())
    text = text[: m.start()] + decl + "\n{" + text[m.end() : end] + text[end + len("END_NONMATCH\n") :]
    with open(path, "w", encoding="utf-8") as f:
        f.write(text)
    os.remove(os.path.join(ROOT, inc))
    print(f"promoted {func} in {src}; removed {inc}")


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("-o", "--output", default="docs/nonmatch_triage.csv")
    ap.add_argument("-j", "--jobs", type=int, default=os.cpu_count())
    ap.add_argument("--workdir", default="build/triage")
    ap.add_argument("--show", metavar="FUNC", help="print a diff for one function instead of a CSV")
    ap.add_argument("-v", "--verbose", action="store_true", help="with --show: indexed diff with branch targets")
    ap.add_argument("--promote", metavar="FUNC",
                    help="turn a NONMATCH into plain C and delete its .inc (verify with make compare!)")
    ap.add_argument("files", nargs="*", help="limit to these C files")
    args = ap.parse_args()

    if args.promote:
        return promote(args.promote)

    if args.show:
        return show(args.show, os.path.join(ROOT, args.workdir), args.verbose)

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
