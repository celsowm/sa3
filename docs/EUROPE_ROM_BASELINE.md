# Sonic Advance 3 — European reference ROM baseline

**Audit date:** 2026-10-10. The European ROM was provided privately and analyzed locally. No ROM, game code, graphics, audio, extracted assets or executable blobs have been committed.

## Status: target ROM available and SHA-1 verified; clean build still pending

| Property | European reference |
|---|---|
| GBA title | `SONIC ADVANC` |
| Game code | `B3SP` |
| Revision | 0 |
| Maker | `8P` |
| Size | 16,777,216 bytes (16 MiB) |
| SHA-1 | `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39` |
| SHA-256 | `d9c96aad4b3795d3e667637fcf9399636ae355fcf12677d2883107ea273dea15` |
| GBA header fixed byte and complement | Both valid |
| Initial ARM unconditional branch target | `0x080000C0` |
| Trailing `0xFF` bytes | 1,576,460 |

The SHA-1 matches `sa3.sha1` and the EU target stated by the SAT-R source README. **This establishes ROM identity, not that current source has compiled to that image.** The original `scripts/progress.py` counts remain unchanged until verified compilation and per-function matching.

The locally available environment did not contain `arm-none-eabi` GNU binutils or the compatible `SAT-R/agbcc` compiler. Outbound direct access to github.com was unavailable from the build sandbox, so a clean build was **not performed**. GitHub source/documentation updates were made through the authenticated GitHub connector without transferring the ROM.

## Cross-region observations

Comparison against the previously supplied verified USA rev-0 ROM
(`B3SE`, SHA-1 `30db467effa5014806d42db57e2299398a51355b`):

- Both images contain **16,777,216 bytes**.
- At the **same file offset**, 6,725,643 bytes are equal (40.08796%) and 10,051,573 bytes differ (59.91204%).
- There are 500 fully identical 4,096-byte aligned blocks out of 4,096.
- Offset-by-offset differences do **not** estimate gameplay similarity or percentage of source-code changes: relocation/insertions shift bytes.
- EU had 11,821 plausible aligned LZ10 headers and USA had 11,776.
- Each had **28** structurally valid compressed candidates under the scanner bounds (64..1,048,576 decoded bytes).
- In each image, **12 candidates** have at least one exact aligned ROM pointer-shaped reference.
- **22 EU candidates** have at least one **identical SHA-256 of decoded LZ10 content** in the USA ROM.
- There are 52 possible EU↔USA candidate pairs because multiple small streams share identical decoded contents; **do not interpret 52 as 52 unique resources**.

### Highest-confidence LZ10 correspondence leads

Each row has the **same decoded bytes across both ROMs** (verified via SHA-256), a structurally valid GBA LZ10 stream and a pointer-shaped value in both ROMs.

| EU stream address | USA stream address | Decoded bytes | EU pointer site | USA pointer site |
|---|---|---:|---|---|
| `0x08E5C244` | `0x08E5BEB4` | 39,680 | `0x08027DB8` | `0x08027DE8` |
| `0x08E5F6B0` | `0x08E5F320` | 39,936 | `0x08027DA0` | `0x08027DD0` |
| `0x08E62B0C` | `0x08E6277C` | 32,768 | `0x080CEF14` | `0x080CEB8C` |
| `0x08E66DB4` | `0x08E66A24` | 76,452 | `0x080CEF10` | `0x080CEB88` |
| `0x08E6DBE4` | `0x08E6D854` | 77,228 | `0x080CEF08` | `0x080CEB80` |
| `0x08E74E1C` | `0x08E74A8C` | 77,088 | `0x080CEF0C` | `0x080CEB84` |
| `0x08E7BC8C` | `0x08E7B8FC` | 4,096 | `0x08E2EAB8` | `0x08E2E73C` |
| `0x08E7BE90` | `0x08E7BB00` | 4,096 | `0x08E2EABC` | `0x08E2E740` |
| `0x08E7C22C` | `0x08E7BE9C` | 4,096 | `0x08E2EAC0` | `0x08E2E744` |
| `0x08E7C6F0` | `0x08E7C360` | 4,096 | `0x08E2EAC4` | `0x08E2E748` |
| `0x08E7CC44` | `0x08E7C8B4` | 4,096 | `0x08E2EAC8` | `0x08E2E74C` |
| `0x08E7CE78` | `0x08E7CAE8` | 4,096 | `0x08E2EACC` | `0x08E2E750` |

**Observed asset offset delta:** Each of these 12 European stream addresses is
`USA + 0x390` (912 bytes). This is **not a universal address conversion**:
pointer-site deltas differ across code and data sections. Proven identical
decompressed contents do not establish resource names, callers or matching
functions; those require follow-up symbol and call-graph investigation.

## Reproduce without redistributing ROMs

The repository contains `scripts/rom_audit.py` and new
`scripts/rom_region_compare.py`, plus corresponding offline unit tests.

```bash
# Run from the repository root. ROMs are local user-supplied files.
python3 scripts/rom_audit.py "/local/path/europe.gba" \
  --require-region EUROPE \
  --require-sha1 685af3a2dc0f1b3f8922e73ec42c1dc92e210e39

python3 scripts/rom_region_compare.py \
  "/local/path/europe.gba" "/local/path/usa.gba" \
  --output /private/path/sa3-rom-comparison.json

python3 -m unittest discover -s scripts/tests -v
```

The new region comparison's **three synthetic unit tests** passed in the local sandbox, using a compatible local ROM-audit interface. The comparison was separately executed against both user-provided ROMs; those metrics are recorded above. A full clean build with the project's exact GBA compiler has not been attempted, and test execution in GitHub Actions has not been confirmed.

## Next decompilation actions

1. Run the reproducible baseline build with `SAT-R/agbcc` and ARM binutils, user-supplied EU ROM at `baserom_sa3.gba`, and `make compare` (which checks `sa3.sha1`).
2. Generate the map-derived function backlog and confirm each ASM inclusion/function range using the **EU** address space. Use `scripts/progress.py text -m` as the percent-matched authority.
3. Identify the owners and usage of pointer tables around EU `0x08027DA0`, `0x080CEF08`, and `0x08E2EAB8`, without assuming the corresponding USA addresses are valid for EU.
4. Once `make compare` works, translate the smallest isolated `asm/non_matching` routines to matching C in narrowly scoped commits, recording ROM SHA and precise progress delta per function.

**Status:** EU source image validated, cross-region mapping underway, matching compilation *blocked by missing toolchain* in the current execution environment. Do not mark M0 passed or advance the 77.97% historical matching metric.
