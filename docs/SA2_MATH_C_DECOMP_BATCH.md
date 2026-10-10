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


## Second source-level batch — six more recovered affine routines (2026-10-10)

Implemented in `src/game/math.c` after the original six-function batch:

| Symbol | C recovery | EU ROM range [start, end) | Range SHA-256 |
|---|---|---|---|
| `sa2__sub_8083E44` | 3x3 affine multiply in-place over lhs | `08083E44–08084090` (588 B) | `ef5850f8d7050336e3cb36d7206559e0fa1efd7c770e309f9c316fee35ed839a` |
| `sa2__sub_8084090` | 3x3 affine multiply in-place over rhs | `08084090–080842E4` (596 B) | `15622b53d55424f24c706bc858d203783b1b2f047286aea646f504615b324757` |
| `sa2__sub_80842E4` | Affine transform of a 3D vector into separate output | `080842E4–0808442C` (328 B) | `60490bc58cc3631b647f939ace286572746e387f6f482182de3c9bd96538ef57` |
| `sa2__sub_808442C` | In-place 3D affine transform with sequential updated coordinates | `0808442C–0808458C` (352 B) | `8ccb209c6aa5c5e1a5d215c0e935fe9ad50f52096b06b91a234e071da162f0c6` |
| `sa2__sub_808477C` | Perspective-normalized projected 3D vector | `0808477C–08084904` (392 B) | `1ace076ea09c5c0075abfd36ee3be30a60aa253231a26a5b4c148da5990ee71a` |
| `sa2__sub_80851E0` | Orthogonal affine inverse: transpose and transformed negated translation | `080851E0–08085314` (308 B) | `86c8595c13fa82b1a3effd51abbc29a34452c03a573395576704900181acb5e9` |

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
| `sa2__sub_8084EE0` | Q6.10 inverse/adjugate; **three 16-bit writes at offsets 0x14, 0x16, 0x18**, despite the current type declaring 32-bit translation members | `0x08084EE0..0x080851E0` (768 bytes) | `1f08506cb704f549f8f8ecc63cf59c3dbb3228c59baecacc5abde1fba8cf318f` |
| `sa2__sub_808458C` | Signed 64-bit quotient/projection; the **last product `z*unk1C` is the numerator**, while the accumulated dot product plus `0x100000`, shifted by 10, forms the divisor; input is re-read per output component to respect aliasing | `0x0808458C..0x0808477C` (496 bytes) | `d00a2a00a260548c87137ad273509188d52a184179f6dadf579582c91f879535` |

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
