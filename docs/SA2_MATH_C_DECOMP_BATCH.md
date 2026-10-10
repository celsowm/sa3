# SA3: Mathematical Assembly fallbacks reimplemented in C

> **2026-10-10 correction:** Function suffixes preserve SA2 addresses. The ROM
> intervals and SHA-256 values below use the actual SA3 Europe locations,
> mapped with a confirmed +0x2BAD8 offset. See
> [SA2_MATH_ROM_RELOCATION.md](SA2_MATH_ROM_RELOCATION.md) for the full
> 18-entry audit and signature evidence. Earlier unrelocated hashes were invalid.


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


## Second source-level batch — six more recovered affine routines (2026-10-10)

Implemented in `src/game/math.c` after the original six-function batch:

| Symbol | C recovery | EU ROM range [start, end) | Range SHA-256 |
|---|---|---|---|
| `sa2__sub_8083E44` | 3x3 affine multiply in-place over lhs | `080AF91C–080AFB68` (588 B) | `b5a303e5d0d8a24798ff73d547c44cf605fbaa71a71b6e5271c938e0bfeee391` |
| `sa2__sub_8084090` | 3x3 affine multiply in-place over rhs | `080AFB68–080AFDBC` (596 B) | `b17cdb328ca52e6df75d7b4ba79a951e6016d49b0df28380d32f6e224d7de1c8` |
| `sa2__sub_80842E4` | Affine transform of a 3D vector into separate output | `080AFDBC–080AFF04` (328 B) | `eaf74c952f27224ef818d687ae560c63c8283a1562ec760387cc806f8ffbcd38` |
| `sa2__sub_808442C` | In-place 3D affine transform with sequential updated coordinates | `080AFF04–080B0064` (352 B) | `f7b95e266ccdee2d635fc0bb702c435345a21fe55b889d644defea3579d14d19` |
| `sa2__sub_808477C` | Perspective-normalized projected 3D vector | `080B0254–080B03DC` (392 B) | `e7e18154bef25d2debe4f600e42b642fa4c4ace72a7c230743109a24c2a9246f` |
| `sa2__sub_80851E0` | Orthogonal affine inverse: transpose and transformed negated translation | `080B0CB8–080B0DEC` (308 B) | `481160edc80a8160c389157ab8d94a48078a75c51c379b828153d43fa7542e2d` |

Reference EU ROM SHA-1: `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.
All six range hashes were computed privately on the verified original European ROM. The **2,564 total bytes** are original **symbol-to-next-symbol intervals**, potentially including literal pools and alignment. **Do not count them as verified C matching bytes.**

### Validation performed

- The six-function native mirror compiled with GCC (`-O2 -fwrapv -Wall -Wextra -Werror`) and Clang 17 for ARMv4T Thumb (`-target armv4t-none-eabi -mthumb`).
- **8,700 local native C randomized examples passed**, with deterministic seeds: 1,500 each of the two in-place affine compositions, 1,500 separate-output vector transforms, 1,500 affine inversions, 1,200 sequential in-place vector transforms, 1,500 perspective projections.
- The committed `scripts/tests/test_math_c_fallbacks.py` now extracts all **twelve actual source C bodies**, compiles them with host GCC/Clang where available, and contains randomized regression tests for these six new routines in addition to the earlier six. The **repository test suite has not been observed passing on hosted CI** in this iteration; local native mirrors were used for immediate validation.
- The original `NONMATCH` ASM `.inc` fallbacks are kept intentionally. Exact `SAT-R/agbcc` codegen, linker placement, `make compare`, ROM SHA-1 and emulator behavior **are still not verified**. The historical ~77.97% matching rate is unchanged.
- For `sa2__sub_808442C`, the Thumb routine's order matters: it uses **new X when computing Y** and **new X/Y when computing Z**; do not replace with a generic matrix multiply that reads an immutable original vector.
- For `sa2__sub_808477C`, the depth divisor is a **wrapped 32-bit dot product** followed by signed arithmetic right shift and division; the projected coordinates use **signed 64-bit intermediate products**. Division by zero is an original precondition; do not silently invent different behavior.

The recommended next match attempts, once `agbcc` is available, are the smaller isolated `sa2__sub_80842E4`, `sa2__sub_808442C` and `sa2__sub_80851E0`, then the heavier in-place and perspective routines. Promote each C implementation individually only after full ROM compare passes.


## Third source-level batch — two original-ASM edge cases (2026-10-10)

`src/game/math.c` now has **14 non-empty C implementations among 18
`NONMATCH` math functions**, verified by inspecting the fork's actual
`NONMATCH` macro bodies. The exact European ROM remains the oracle;
its SHA-1 is `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.

| Source symbol | Algorithm / important original behavior | EU original ROM interval | SHA-256 of original interval |
|---|---|---|---|
| `sa2__sub_8084EE0` | Q6.10 inverse/adjugate; **three 16-bit writes at offsets 0x14, 0x16, 0x18**, despite the current type declaring 32-bit translation members | `0x080B09B8..0x080B0CB8` (768 bytes) | `9ebc67cf2f6d381c8793f27ad8339ca88de21bcab1c84a6bc04d7e2da7d17ee1` |
| `sa2__sub_808458C` | Signed 64-bit quotient/projection; the **last product `z*unk1C` is the numerator**, while the accumulated dot product plus `0x100000`, shifted by 10, forms the divisor; input is re-read per output component to respect aliasing | `0x080B0064..0x080B0254` (496 bytes) | `829ded12a661c24e1dbe0132a04217998edf9629fe52c297ca4e323b9a74308d` |

The original ROM intervals total **1,264 bytes**, including possible
literal-pool data and alignment. They are **NOT newly matching C bytes**.

### What was tested

- Both source-level bodies were implemented in their real
  `NONMATCH` blocks in `src/game/math.c`. No original `.inc` ASM
  fallback or symbol was removed, so the default EU matching build is
  protected from an unverified C-codegen change.
- The inverse's equivalent C code compiled on x86-64 GCC with
  `-O2 -fwrapv -Werror` and as an ARMv4T/Thumb ELF object with Clang 17.
  A local mirror passed **8,000 independent signed-integer formula cases**,
  comparing the **complete 32-byte matrix memory image** after all stores.
- The projection's equivalent C code likewise compiled on x86-64 GCC and
  ARMv4T/Thumb Clang 17. A local mirror passed **20,000 independent cases**,
  including `output == input` aliasing and 32-bit result truncation.
- The committed `scripts/tests/test_math_c_fallbacks.py` extracts the
  **real source C bodies** and adds two deterministic native tests
  (3,000 inverse + 6,000 projection attempts). These latest committed tests
  **have not been run in GitHub Actions** here. Local mirror testing is
  additional evidence, not a claimed compiled `agbcc` match.
- The fixed-point projection revealed an important test-only pitfall:
  Python's unbounded integer arithmetic must explicitly sign-truncate
  both the row result and shifted intermediate to ARM **32-bit values**.
  Without that, otherwise correct aliased outputs can appear wrong.

### Remaining empty mathematical C fallbacks

1. `sa2__sub_80832FC` — fixed-point 64-bit polynomial interpolation; current
   signature in C is a placeholder, needs exact parameters and return type.
2. `sa2__sub_808343C` — related 64-bit interpolation; ABI still unknown.
3. `sa2__sub_8084A24` — axis/angle matrix initializer with an unusual
   zeroing loop and additional writes **beyond the first 32 bytes** of its
   pointer; map the true destination capacity before reconstructing.
4. `sa2__sub_8084C70` — basis construction from two positions and direction,
   with conditional normalization; recover complete ABI and threshold cases.

This brings the source work to **14/18 mathematical `NONMATCH` bodies
implemented in C**. The original **~77.97% ROM matching percentage has not
changed**, since `agbcc` and a verified end-to-end `make compare` are
still missing here. The next priority is either independently recovering
these final four routines or running the pinned toolchain to promote
individual existing fallbacks to verified C matches.


## Fourth source-level batch: 18 of 18 mathematical NONMATCH C bodies (2026-10-10)

**Completed the remaining four previously empty C implementations:**

| Source symbol | Decompiled algorithm | Notable ABI/behavior |
|---|---|---|
| `sa2__sub_80832FC` | Cubic Bezier interpolation in fixed-point with signed 64-bit products | Six arguments, `s32` return; last shift is an `u8` stacked parameter |
| `sa2__sub_808343C` | Cubic Hermite interpolation and its four polynomial coefficients | `r0..r3` carry p0/m0/m1/p1, plus stacked t/shift |
| `sa2__sub_8084A24` | Rodrigues 3D rotation matrix from angle and Q6.10 axis | Writes **52 bytes maximum**: zeros 32 bytes and writes `s16` slots 17/21/25, as well as the basis |
| `sa2__sub_8084C70` | Look-at/orthogonal 3D basis from two positions and direction | Preserve threshold `abs(x+y+z) > 32`, fallback axes and sequential normalization |

All 18 mathematical `NONMATCH` blocks now have real C bodies in
`src/game/math.c`. The original Assembly fallbacks are intentionally
preserved; this is a completed **source recovery milestone**, **NOT**
18 compiled matching functions.

### Fourth-batch validation

- Compiled a **local equivalent native C implementation of the four new
  function bodies** with host GCC `-O2 -fwrapv -Wall -Wextra -Werror`;
  **22,000** independent deterministic checks succeeded: 12,000 combined
  Bezier/Hermite evaluations, 5,000 Rodrigues rotations and 5,000 look-at
  basis computations (including source-buffer boundaries).
- A local equivalent source also compiled as an ARMv4T/Thumb relocatable
  object using Clang; this does **not** establish original agbcc codegen.
- Updated `scripts/tests/test_math_c_fallbacks.py` to extract the **18
  actual C bodies** from a checked-out fork and compile/test them on a host.
  It adds 8,500 deterministic cases in four test methods. Hosted Actions
  has **zero recorded workflow runs**; success of the entire committed
  suite has NOT been asserted.
- Audited an important flaw in the prior hash records: SA2-named symbol
  suffixes are old SA2 addresses, not SA3 locations. Four independently
  unique Thumb entry signatures established the common SA3 relocation
  **`+0x2BAD8`**; 18 SHA-256 reference ranges were corrected and published
  in [SA2_MATH_ROM_RELOCATION.md](SA2_MATH_ROM_RELOCATION.md), with a
  reproducible `scripts/math_rom_runtime_map.py` validator and offline tests.
- The 18 original SA3 ROM label-to-next-label ranges total **6,640 bytes**.
  This includes literal pools and alignment; **it is not newly matched C**.

**Next gate:** run the pinned SAT-R/agbcc + binutils matching build, verify
the EU SHA-1 with `make compare`, then remove `NONMATCH` for each C routine
individually when the complete ROM remains byte-identical. Historical
~77.97% ROM matching progress is still the last verified value. For
non-matching compilation, prioritize runtime functionality smoke tests of
the newly restored transforms as well.


## First direct isolated codegen comparison — 2026-10-10

The next stage started auditing **compiled instructions**, not just sampled
mathematical outputs. The first probe is `sa2__sub_8084EAC` (Q6.10
matrix transpose, `asm/non_matching/game/math/sa2__unused_sub_8084EAC.inc`).

- Correct relocated Europe ROM address: **`0x080B0984`** (legacy suffix
  `0x08084EAC + 0x2BAD8`); original interval ends `0x080B09B8`.
- Original 52-byte ROM interval SHA-256:
  `ea1419346318229f9310e1f0ba87ada94f100b056c3200d38027db4eb1675dca`.
- The original Thumb disassembly uses a three-pair XOR-swap sequence,
  which writes the **upper index before the lower index**.
- Changed `src/game/math.c` C body to preserve that original store
  order and keep typed C semantics. The ASM fallback remains intact.
- An equivalent extracted-body-style standalone C probe compiled with
  **Clang ARMv4T Thumb -O2**: **26 bytes**, SHA-256
  `30e3467bdef917aa8fef42a1b4125439823ecb13071f3856e74df4c1e41f6f40`.
  The emitted bytes already differ at offset 0 from the 52-byte original
  ROM interval. Clang folds away the XOR-swap pattern.
- Added reproducible `scripts/math_thumb_codegen_probe.py`, which
  extracts the **actual repo C body**, compiles it with Clang, reads the
  object `.text` and compares it against the verified original ROM;
  added `scripts/tests/test_math_thumb_codegen_probe.py` for offline
  source selection and runtime address guards.
- **Important qualification:** The offline Clang sample above used an
  **equivalent isolated source**. The newly committed extraction-based
  runner and its new repo tests have **not yet been run in GitHub Actions
  or against a complete local checkout**. Output can differ by Clang
  version. Clang is not agbcc; neither a matching nor a nonmatching
  isolated Clang result conclusively establishes what pinned agbcc
  would emit in the full game.

This is the first concrete instruction-level mismatch baseline in the
math recovery effort, and it explains why functionally equivalent C is
insufficient to update the matching percentage. The only acceptance
gate remains original `agbcc`, linker placement, and full
`make compare` against the exact Europe ROM.

## Superseded (2026-10-10)

The host-compiler tests and the Thumb codegen probe described above were
removed once the real agbcc toolchain and `make compare` became available:
they validated behaviour, not matching, and broke as soon as a math
function was promoted to plain C. Progress on these functions is now
tracked only by `scripts/nonmatch_triage.py` and `make compare`.
