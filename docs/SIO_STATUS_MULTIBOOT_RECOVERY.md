# SIO status and MultiBoot reconstruction — 2026-10-10

This iteration reconstructed **five additional SIO routines** as actual typed C
bodies in [`src/sio_stuff_x.c`](../src/sio_stuff_x.c). Original
`NONMATCH` Assembly remains the default GBA build path: this is
source-level decompilation, not verified binary matching.

| Thumb symbol | Recovered ABI and behavior |
|---|---|
| `sub_8024074(u8)` | `s16` status guard; propagate negative link error, return `-4` on `0x0C0C` flags, otherwise call `sub_8024354(0,value)` and return zero |
| `sub_80240B4(u8)` | Identical guard with `sub_8024374(0,value)` instead of the previous producer |
| `sub_80240F4(void)` | Same status guard; dispatch `sub_8024374(1,0xFF)` only if flag bit zero is set, otherwise no send |
| `sub_8024130(void)` | Same status guard; flag `2` enables a reply check against `gMultiSioRecv[1]` packet type `0x6C0A`; returns `0x10` for a match (zero otherwise) and invokes `sub_80243B4()` regardless of tag match |
| `sub_8028530(void)` | Call `MultiBootMain(&gMultiBootParam)` exactly once; only return codes `0x50`, `0x60`, `0x70`, `0x71` call `sub_802613C()` and return true |

`sub_8024130` decodes the little-endian response tag with individual
byte loads, avoiding potentially misaligned or strict-aliasing-sensitive
`u16 *` reads in portable C. This preserves the original GBA little-endian
value and leaves the default matching ASM unchanged.

## Tests

Two new tests extract **the actual committed C bodies** from the fork:

- [`scripts/tests/test_sio_status_guards_host.py`](../scripts/tests/test_sio_status_guards_host.py)
  covers 7 link statuses, 12 flag patterns, 256 argument values and
  both response-tag branches; checks each callback's exact count and
  argument pair, error propagation and the no-send cases.
- [`scripts/tests/test_sio_multiboot_completion_host.py`](../scripts/tests/test_sio_multiboot_completion_host.py)
  covers 1,024 consecutive return values plus an `INT32_MAX` edge case.
  The only success codes must trigger exactly one transition.

**Executed in this turn:** equivalent isolated native-C versions of the
five functions were compiled with GCC `-std=c99 -O2 -fwrapv -Wall -Wextra
-Werror -fsanitize=undefined` and passed **107,520 SIO status function
calls and 1,024 MultiBoot response cases**. The equivalent source
compiled to ARMv4T/Thumb relocatable objects using Clang. The extraction-
based tests themselves have been committed for CI but **have not been
run in hosted GitHub Actions**, and they are not substitutes for the
original matching compiler.

## Progress and next gate

`src/sio_stuff_x.c` has **80/168** `NONMATCH` C bodies with
implementations, leaving **88** empty. The default EU GBA ROM still
uses the original ASM for these routines, so the historical reported
`~77.97%` matching percentage remains unchanged.

The correct next gate for *binary* progress is to install the exact
`SAT-R/agbcc` compiler and ARM binutils in a build environment,
reproduce the Europe ROM SHA-1
`685af3a2dc0f1b3f8922e73ec42c1dc92e210e39` with `make compare`,
and then promote functions one by one only when the **whole ROM is
byte-identical**.

No game ROM, extracted binary or proprietary asset was committed.
