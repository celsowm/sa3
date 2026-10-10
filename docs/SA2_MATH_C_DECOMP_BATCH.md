# SA3: Six mathematical Assembly fallbacks reimplemented in C

**Date:** 2026-10-10. **Target:** `celsowm/sa3`, European matching ROM.
**Changed production file:** [`src/game/math.c`](../src/game/math.c).

## Delivered C implementations

Six previously empty `NONMATCH` bodies were replaced by concrete
fixed-point C implementations derived from their corresponding Thumb ASM:

| Symbol | Algorithm | ASM reference |
|---|---|---|
| `sa2__sub_8083858` | Normalize Q6.10 four-component rotation | `asm/non_matching/game/math/sa2__unused_sub_8083858.inc` |
| `sa2__sub_8083B10` | Normalize with conjugation of first 3 components | `asm/non_matching/game/math/sa2__unused_sub_8083B10.inc` |
| `sa2__sub_8083A48` | Quaternion product, storing into second argument | `asm/non_matching/game/math/sa2__unused_sub_8083A48.inc` |
| `sa2__sub_8084EAC` | Swap off-diagonal pairs of the 3x3 basis | `asm/non_matching/game/math/sa2__unused_sub_8084EAC.inc` |
| `sa2__sub_8085314` | Quaternion-to-3x3 transform with translation fields reset | `asm/non_matching/game/math/sa2__unused_sub_8085314.inc` |
| `sa2__sub_8083B88` | 3x3 affine transform composition and signed 64-bit translations | `asm/non_matching/game/math/sa2__sub_8083B88.inc` |

The original `NONMATCH` macros and ASM `.inc` files remain in place.
The default GBA matching build therefore **still uses the original Assembly**;
these C implementations can instead compile in a `NON_MATCHING` build and
are intended as real source equivalents awaiting matching compiler optimization.

## Local validation

- The European ROM SHA-1 was independently rechecked:
  `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.
- An equivalent six-function C harness was compiled locally with host GCC
  (`-O2 -fwrapv -Wall -Wextra -Werror`). **2,600 sampled
  fixed-point comparisons passed** against independent formulas from ASM:
  300 norm, 300 conjugate norm, 400 quaternion products, 300 transpositions,
  300 quaternion-to-matrix conversions, **1,000 matrix compositions**.
- All six equivalent function bodies compiled to an ARMv4T/Thumb relocatable
  object with LLVM/Clang 17 and no warnings. This confirms ARM syntax only;
  **Clang is not the original matching compiler**.
- Repository test [`scripts/tests/test_math_c_fallbacks.py`](../scripts/tests/test_math_c_fallbacks.py)
  extracts the **actual new `NONMATCH` C bodies** from `math.c`, compiles
  them with a native C compiler, and runs those 2,600 seeded examples. This
  new repository test has been committed but **has not yet been observed
  running through GitHub Actions**; the local harness was an independently
  maintained equivalent.
- No end-to-end ROM build, emulator regression, `make compare`, or
  incremental `scripts/progress.py text -m` has succeeded in this execution
  environment, because `SAT-R/agbcc` and ARM binutils remain unavailable.

## Reverse-engineering invariants and risks

- Input/output structures are the original `UNK_8085D14` and
  `UNK_8085F1C_1`, with 16-bit Q6.10 rotation and matrix terms.
- Normalization uses the original integer square-root and integer scale
  `0x100000 / (u16)Sqrt(sum_of_squares)`. The original ASM divides
  by zero on an all-zero quaternion; do not invent recovery behavior while
  targeting matching code.
- Multiplication updates the second quaternion. The matrix transform
  composition expects distinct input/output buffers; aliasing requires
  additional analysis of ASM load/store ordering.
- The quadratic expressions have been validated in typical Q6.10 ranges.
  Signed 32-bit overflow, original ASM word wrapping, intermediate
  left shifts and compiler-specific behavior at extreme inputs require
  separate emulation or exact matching compiler verification.
- The affine-translation paths use **signed 64-bit multiplication**
  followed by a right shift of ten bits; they are not simple 32-bit dot
  products. This distinction was recovered from the original
  `__muldi3` calls and multiword additions.
- These C bodies are a **real source decompilation advance** but **not yet
  ROM-matching functions**. Do not add their instruction counts to the
  historical 636,516 matched bytes; default ROM compilation still selects ASM.

## Next steps

1. Obtain/pin compatible `SAT-R/agbcc`, `old_agbcc`, ARM assembler/linker,
   and the project-specific asset generation tools; reproduce `make compare`
   for the European hash.
2. Enable `NON_MATCHING` for development and run native/emulator smoke
   tests exercising matrix transforms, vector normalization and gameplay.
3. Optimize each C function in isolation to match the original Thumb
   instructions and position, removing its fallback only when the **whole**
   European ROM SHA-1 remains unchanged.
4. Re-run `scripts/progress.py text -m` after each accepted matching
   conversion; prioritize `sa2__sub_8083B88` as the largest mathematical
   routine in this batch.

The source work is kept in the user's independent fork; SAT-R upstream's
strict no-LLM submission policy remains respected.
