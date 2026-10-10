#!/usr/bin/env python3
"""Create a decomp-permuter directory for one NONMATCH function.

    scripts/permuter_setup.py FUNC [--permuter ../decomp-permuter]
    ../decomp-permuter/permuter.py build/permuter/FUNC -j8

The directory holds the NON_MATCHING-preprocessed C (other function bodies
stripped), the target object assembled from the function's .inc, and a
compile.sh that runs the same agbcc command line as the Makefile.
"""

import argparse
import os
import shlex
import stat
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import nonmatch_triage as triage  # noqa: E402

ROOT = triage.ROOT


def strip_attributes(text):
    out, i = [], 0
    while True:
        j = text.find("__attribute__", i)
        if j < 0:
            return "".join(out) + text[i:]
        out.append(text[i:j])
        k = text.index("(", j)
        depth = 0
        while True:
            depth += {"(": 1, ")": -1}.get(text[k], 0)
            k += 1
            if depth == 0:
                break
        i = k


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("func")
    ap.add_argument("--permuter", default=os.path.join(os.path.dirname(ROOT), "decomp-permuter"))
    args = ap.parse_args()

    for src, funcs in triage.find_nonmatch_files().items():
        inc = dict(funcs).get(args.func)
        if inc:
            break
    else:
        sys.exit(f"{args.func}: not a NONMATCH function")

    out = os.path.join(ROOT, "build", "permuter", args.func)
    os.makedirs(out, exist_ok=True)
    obj, cmds = triage.build_commands(src)
    base = obj[:-2]
    cpp = next(c for c in cmds if c.startswith("arm-none-eabi-cpp"))
    cc = next(c for c in cmds if "agbcc" in c and "preproc" in c)
    as_cmd = next(c for c in cmds if c.startswith("arm-none-eabi-as"))

    # Preprocessed C with every NONMATCH body as plain C (the promoted state).
    tmp_src = os.path.join(os.path.dirname(src), ".triage_" + os.path.basename(src))
    with open(os.path.join(ROOT, src), encoding="utf-8") as f:
        text = triage.as_plain_c(f.read())
    with open(os.path.join(ROOT, tmp_src), "w", encoding="utf-8") as f:
        f.write(text)
    cpp = cpp.replace(base + ".i", f"{out}/full.i").replace(" " + src + " ", " " + tmp_src + " ")
    try:
        subprocess.run(cpp, shell=True, cwd=ROOT, check=True)
    finally:
        os.remove(os.path.join(ROOT, tmp_src))
    preproc, agbcc = (p.strip() for p in cc.split("|", 1))
    preproc = preproc.replace(base + ".i", f"{out}/full.i")
    with open(f"{out}/full.c", "w") as f:
        subprocess.run(preproc, shell=True, cwd=ROOT, check=True, stdout=f)
    with open(f"{out}/full.c") as f:
        text = "".join(l for l in f if not l.startswith("#"))
    # pycparser can't parse every attribute placement. Candidates are only
    # hints; every result is re-checked by make compare.
    with open(f"{out}/base.c", "w") as f:
        f.write(strip_attributes(text))
    subprocess.run([sys.executable, os.path.join(args.permuter, "strip_other_fns.py"), f"{out}/base.c", args.func],
                   check=True)

    # compile.sh: input.c -o output.o
    agbcc_bin = os.path.join(ROOT, agbcc.split()[0])
    agbcc_flags = " ".join(agbcc.split()[1:]).split(" -o ")[0]
    as_flags = " ".join(as_cmd.split()[1:-3])
    script = f"""#!/bin/bash
set -e
INPUT="$1"; OUTPUT="$3"
TMP="$OUTPUT.s"
{shlex.quote(agbcc_bin)} {agbcc_flags} -o "$TMP" "$INPUT"
printf ".text\\n\\t.align\\t2, 0\\n" >> "$TMP"
arm-none-eabi-as {as_flags} "$TMP" -o "$OUTPUT"
"""
    with open(f"{out}/compile.sh", "w") as f:
        f.write(script)
    os.chmod(f"{out}/compile.sh", os.stat(f"{out}/compile.sh").st_mode | stat.S_IEXEC)

    # Target object from the original .inc.
    with open(f"{out}/target.s", "w") as f:
        f.write(f'.code 16\n.text\n.align 2, 0\n.global {args.func}\n.thumb_func\n{args.func}:\n'
                f'.include "{inc}"\n.text\n.align 2, 0\n')
    subprocess.run(f"arm-none-eabi-as {as_flags} -I {ROOT} {out}/target.s -o {out}/target.o",
                   shell=True, cwd=ROOT, check=True)
    with open(f"{out}/settings.toml", "w") as f:
        f.write(f'func_name = "{args.func}"\ncompiler_type = "gcc"\n')
    print(out)


if __name__ == "__main__":
    main()
