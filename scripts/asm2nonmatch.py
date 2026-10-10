#!/usr/bin/env python3
"""Turn a plain asm/*.s file of thumb functions into a C file of NONMATCH stubs.

Every function becomes `NONMATCH("<incdir>/<prefix>__<func>.inc", void func(void)) { } END_NONMATCH`
whose .inc holds the original instructions, so the ROM stays byte-identical while each
function can then be decompiled (and promoted) individually with the usual tooling.

usage: asm2nonmatch.py asm/foo.s src/game/foo.c asm/non_matching/game/foo PREFIX
"""
import os
import re
import sys

FUNC_RE = re.compile(r'^\s*thumb_func_start (\w+)\s*$')


def split_functions(text):
    lines = text.split('\n')
    header, funcs, cur = [], [], None
    for line in lines:
        m = FUNC_RE.match(line)
        if m:
            cur = [m.group(1), []]
            funcs.append(cur)
            continue
        if cur is None:
            header.append(line)
            continue
        # drop the "func: @ 0x..." label: the C declaration provides the symbol
        if re.match(r'^%s:' % re.escape(cur[0]), line):
            continue
        cur[1].append(line)
    return header, funcs


def main():
    asm_path, c_path, inc_dir, prefix = sys.argv[1:5]
    header, funcs = split_functions(open(asm_path).read())
    os.makedirs(inc_dir, exist_ok=True)
    out = ['#include "global.h"', '']
    for name, body in funcs:
        while body and not body[-1].strip():
            body.pop()
        inc = os.path.join(inc_dir, '%s__%s.inc' % (prefix, name))
        with open(inc, 'w') as f:
            f.write('.syntax unified\n.text\n' + '\n'.join(body) + '\n\n.syntax divided\n')
        out.append('NONMATCH("%s", void %s(void))' % (inc, name))
        out.append('{')
        out.append('}')
        out.append('END_NONMATCH')
        out.append('')
    with open(c_path, 'w') as f:
        f.write('\n'.join(out))
    print('%d functions' % len(funcs))


if __name__ == '__main__':
    main()
