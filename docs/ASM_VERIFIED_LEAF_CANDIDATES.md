# ROM-verified standalone Assembly leaf triage

Baseline: `937a94e` from SAT-R source; the reference is the privately
supplied **European** SA3 ROM with SHA-1
`685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.

## Source inventory and validated leaves

The repository file [asm_standalone_function_inventory.csv](asm_standalone_function_inventory.csv)
records **448 named standalone Assembly entry labels** in six large
`asm/*.s` files. Of these, **442** have a next source label from which a
conservative upper-bound interval can be calculated (six final labels have
unknown upper bounds); **57** intervals are at most 32 bytes and **244**
are at most 128 bytes.

Cross-checking all **17 four-byte intervals** against the exact European
reference ROM found the same sequence in each:

- `70 47` — Thumb `bx lr`: return immediately.
- `00 00` — next two bytes, generally padding/alignment, **not** another
  function instruction.

A separate, local Clang 17 ARMv4T Thumb compile of two empty C functions
also emitted the `bx lr` instruction. **This does not prove agbcc matching.**

| Source file | Function name | Verified EU ROM address |
|---|---|---|
| `asm/sio_stuff_x.s` | `sub_8027904` | `0x08027904` |
| `asm/sio_stuff_x.s` | `sub_8027908` | `0x08027908` |
| `asm/boss_final.s` | `sub_808183C` | `0x0808183C` |
| `asm/boss_final.s` | `PlayerCB_8081894` | `0x08081894` |
| `asm/boss_final.s` | `PlayerCB_80819BC` | `0x08081A3C` |
| `asm/boss_final.s` | `sub_8081B18` | `0x08081B18` |
| `asm/boss_final.s` | `sub_8081B1C` | `0x08081B1C` |
| `asm/boss_final.s` | `sub_8081B20` | `0x08081B20` |
| `asm/boss_extra.s` | `sub_8087040` | `0x08087040` |
| `asm/boss_extra.s` | `TaskDestructor_50_80870AC` | `0x080870AC` |
| `asm/boss_extra.s` | `TaskDestructor_38_8087234` | `0x08087234` |
| `asm/game__mp_char_select.s` | `TaskDestructor_80A13B0` | `0x080A13B0` |
| `asm/game__opening.s` | `TaskDestructor_A0_80A3E34` | `0x080A3E34` |
| `asm/game__opening.s` | `TaskDestructor_174_80A3E38` | `0x080A3E38` |
| `asm/game__opening.s` | `TaskDestructor_94_A_80A3F10` | `0x080A3F10` |
| `asm/game__opening.s` | `TaskDestructor_54_80A3F14` | `0x080A3F14` |
| `asm/game__opening.s` | `TaskDestructor_94_B_80A43DC` | `0x080A43DC` |

**Important:** Source label `PlayerCB_80819BC` is at **0x08081A3C**
in the original Assembly and EU ROM. Prefer the source address to
guessing from the name; investigate the outdated/misleading suffix separately.

## First matching implementation batch

Start with the **eight TaskDestructor callbacks** above. The ROM bytes
indicate no CPU-visible action aside from return. Before translating:

1. Find each symbol's declarations and references; confirm its **actual
   function signature** (likely `void (*)(struct Task *)`, but do not guess).
2. Identify original translation unit and linker placement/order.
3. Replace the corresponding four-byte Assembly with a correctly typed
   C function while ensuring symbol order, section alignment and the
   overall ROM layout remain unchanged.
4. Build with the pinned **SAT-R/agbcc** compiler and compare the generated
   object instructions and **full ROM SHA-1** to the European reference.
5. Keep a converted function only after `make compare` passes, then log
   the byte-accurate matching delta. Avoid batch-merging all eight at once.

The other nine functions need ABI/return-value analysis before assuming
that an empty C body is equivalent: `bx lr` **preserves r0**, which can
matter if a function returns a value.

## Reproduction commands

```bash
# In a checked-out SA3 fork; use your own legally obtained ROM.
python3 scripts/asm_leaf_candidates.py /private/path/baserom_sa3.gba \
  --inventory docs/asm_standalone_function_inventory.csv \
  --output /private/path/leaf_candidates.json

python3 -m unittest discover -s scripts/tests -v
```

No original ROM bytes or extracted resources are distributed by these tools.
The local run of the candidate verifier confirmed 17/17 on the EU ROM using a
17-row subset of the source-derived inventory. The full CSV contains the same
17 interval entries, along with longer intervals and unknown-sized labels.
The C source has **not** been converted, and the original matching percentage
has **not** increased yet because the agbcc toolchain was unavailable in
this sandbox.
