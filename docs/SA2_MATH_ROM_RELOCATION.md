# SA3 Europe ROM runtime locations for all 18 SA2 math fallbacks

**Audited:** 2026-10-10. **Reference EU SHA-1:** `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.

**Correction to earlier reports:** the `sa2__sub_808xxxxx` names preserve
the *Sonic Advance 2* addresses. Those numbers must **NOT** be used directly
as SA3 ROM addresses. Previous SHA-256 tables using those unrelocated
addresses were misleading and have been corrected in the batch report.

Four function-entry Thumb prefixes from the real ASM were assembled
with Clang for ARMv4T and each found **exactly once** in the exact
European SA3 ROM:

| Legacy symbol suffix | Unique observed SA3 ROM address | Signature bytes |
|---|---|---|
| `80832FC` | `0x080AEDD4` | 20 |
| `808343C` | `0x080AEF14` | 20 |
| `8084A24` | `0x080B04FC` | 18 |
| `8084C70` | `0x080B0748` | 18 |

All four establish the same section relocation: **legacy value + `0x2BAD8`**.
For the remaining functions, the corresponding relocated addresses have
been checked for plausible original Thumb entry bytes and are protected
by private-ROM SHA-256 reference comparisons. **Only the four above have
independently confirmed unique entry signatures.** This does not establish
the exact executable instruction count or that the new C produces matching
instructions.

## Full relocation and private-ROM interval baseline

Each end is the **next known source symbol** (exclusive); ranges can include
inline constants, alignment and data. They are **upper bounds**, not a
verified number of compiled C code bytes.

| Function | Actual SA3 start | End (exclusive) | Span | SHA-256 of original EU ROM interval |
|---|---|---|---:|---|
| `sa2__sub_80832FC` | `0x080AEDD4` | `0x080AEF14` | 320 | `7bcc4955aa7a86f6f1ab93ad157bdb3c8eed77356ef0b0ebf25e40d14636b7c6` |
| `sa2__sub_808343C` | `0x080AEF14` | `0x080AEFDC` | 200 | `7566bd24cb3d7d27f6b3d0b3fc2b8d2b9e737e6a0108916dd62c5c7203dc65d3` |
| `sa2__sub_8083858` | `0x080AF330` | `0x080AF3A4` | 116 | `7731d2b2b2380d31c83f97421c2224796bdf272647b17912f6f8d39660655d91` |
| `sa2__sub_8083A48` | `0x080AF520` | `0x080AF5E8` | 200 | `ff60d999c4632e335886e8179d399c492ae9f3f285dbf5c15d09174609e61516` |
| `sa2__sub_8083B10` | `0x080AF5E8` | `0x080AF660` | 120 | `56b0c882b38148d79d9f2848e929deb95dd74c25558abd412b411a9a375b73dd` |
| `sa2__sub_8083B88` | `0x080AF660` | `0x080AF91C` | 700 | `d6a8cff8d5bcd925a77dc582309b34162413935b095de54acd35e3595936f6c6` |
| `sa2__sub_8083E44` | `0x080AF91C` | `0x080AFB68` | 588 | `b5a303e5d0d8a24798ff73d547c44cf605fbaa71a71b6e5271c938e0bfeee391` |
| `sa2__sub_8084090` | `0x080AFB68` | `0x080AFDBC` | 596 | `b17cdb328ca52e6df75d7b4ba79a951e6016d49b0df28380d32f6e224d7de1c8` |
| `sa2__sub_80842E4` | `0x080AFDBC` | `0x080AFF04` | 328 | `eaf74c952f27224ef818d687ae560c63c8283a1562ec760387cc806f8ffbcd38` |
| `sa2__sub_808442C` | `0x080AFF04` | `0x080B0064` | 352 | `f7b95e266ccdee2d635fc0bb702c435345a21fe55b889d644defea3579d14d19` |
| `sa2__sub_808458C` | `0x080B0064` | `0x080B0254` | 496 | `829ded12a661c24e1dbe0132a04217998edf9629fe52c297ca4e323b9a74308d` |
| `sa2__sub_808477C` | `0x080B0254` | `0x080B03DC` | 392 | `e7e18154bef25d2debe4f600e42b642fa4c4ace72a7c230743109a24c2a9246f` |
| `sa2__sub_8084A24` | `0x080B04FC` | `0x080B062C` | 304 | `170bc7d283ad020e74bc1af640145e1d81ba938e62cbd7801825188f3497feea` |
| `sa2__sub_8084C70` | `0x080B0748` | `0x080B0984` | 572 | `86dee33129053842f31e800f05cb3a30ff2e3656f39be9da1658e451bcea6de7` |
| `sa2__sub_8084EAC` | `0x080B0984` | `0x080B09B8` | 52 | `ea1419346318229f9310e1f0ba87ada94f100b056c3200d38027db4eb1675dca` |
| `sa2__sub_8084EE0` | `0x080B09B8` | `0x080B0CB8` | 768 | `9ebc67cf2f6d381c8793f27ad8339ca88de21bcab1c84a6bc04d7e2da7d17ee1` |
| `sa2__sub_80851E0` | `0x080B0CB8` | `0x080B0DEC` | 308 | `481160edc80a8160c389157ab8d94a48078a75c51c379b828153d43fa7542e2d` |
| `sa2__sub_8085314` | `0x080B0DEC` | `0x080B0ED0` | 228 | `c695327b5f88a75acf786b0ad5f73b8c3eeba415bfb83b2f584c237804da0313` |

Summed interval upper bounds: **6640 bytes**.
No game ROM bytes, assembly excerpts or game assets are committed by the
metadata verifier.

## Reproduce

```bash
# The ROM remains private and never needs to be committed.
python3 scripts/math_rom_runtime_map.py /private/baserom_sa3.gba \
  --output /private/sa3_math_rom_runtime_metadata.json
```

The verifier checks EU SHA-1, 18 interval SHA-256 hashes, and uniqueness
of four independently identified Thumb prefixes. If the ROM is wrong,
it fails rather than emitting misleading provenance.

**Current matching state:** All 18 `src/game/math.c` `NONMATCH` bodies
have source-level C implementations, but the normal matching build still
uses the original ASM fallback. `agbcc` and full `make compare` were
not available. **Historical matching remains ~77.97%; no byte gain is claimed.**
