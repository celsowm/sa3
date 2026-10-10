# Sonic Advance 3 — U.S. ROM reverse-engineering baseline

Audit date: 2026-10-10. Source: a user-provided, locally inspected GBA ROM.
**Only hashes, offsets and metadata are committed. No ROM or asset bytes.**

## Identity and compatibility

| Field | Result |
|---|---|
| Title | \`SONICADVANC3\` |
| GBA game code | \`B3SE\` (USA) |
| Maker code | \`78\` |
| ROM revision | 0 |
| File size | 16,777,216 bytes (16 MiB) |
| SHA-1 | \`30db467effa5014806d42db57e2299398a51355b\` |
| SHA-256 | \`f937fa93b97b14b9fb9fce98844c534f936222d21d1fdb5f1af42292bad32c85\` |
| GBA fixed byte and header complement | Valid |
| Initial ARM branch target | \`0x080000C0\` |
| Contiguous trailing \`0xFF\` padding | 1,577,372 bytes |

**Hard boundary:** the project's matching target is currently the **European** ROM, GBA
game code \`B3SP\`, SHA-1 \`685af3a2dc0f1b3f8922e73ec42c1dc92e210e39\`.
This U.S. dump **cannot** pass that target hash; a valid U.S. header is not proof
that code layouts, addresses or data are equivalent to the European target.
The existing \`GAME_REGION=USA\` configuration branch does **not**, on its own,
prove that a U.S. ROM can already be rebuilt bit-identically.

## New tooling in this fork

\`scripts/rom_audit.py\` accepts user-supplied ROM files *locally* and reports:

- SHA-1/SHA-256, header fields, region, revision and GBA header checks.
- The initial ARM unconditional branch target when available.
- Optional 1-MiB-range occupancy, without embedding ROM data.
- Four-byte aligned, structurally validated candidate GBA LZ10 streams
  (syntactic verification only; compressed bytes are not extracted).
- Optional explicit \`--require-region\` and \`--require-sha1\` validation,
  exiting with status 2 when a requested check fails.

Example, using your own local ROM path:

\`\`\`bash
python3 scripts/rom_audit.py "/path/to/your/sa3_usa.gba" --require-region USA
python3 scripts/rom_audit.py "/path/to/your/sa3_usa.gba" --scan-lz10 --segments --json > rom-audit-local.json
python3 -m unittest discover -s scripts/tests -v

# This intentionally fails on the supplied USA ROM (exit status 2).
python3 scripts/rom_audit.py "/path/to/your/sa3_usa.gba" --require-region EUROPE
\`\`\`

Do not commit the baserom or extracted graphics/audio, and do not upload it to
the fork's GitHub Actions environment.

## Asset reconnaissance results (USA address space only)

For 4-byte aligned headers with declared decoded length 64..1,048,576 bytes,
the scan inspected **11,776 plausible headers** and found **28 streams**
whose LZ10 tokens and backreferences were structurally valid and whose
stored lengths were smaller than the declared decoded lengths.

A second, local read-only pass counted exact, 4-byte-aligned, little-endian
pointers to those stream addresses in the U.S. ROM. **12 of the 28** have an
observed direct reference. They are the best initial candidates to investigate:

| Candidate ROM address | Stored bytes | Decoded bytes | Direct pointer site |
|---|---:|---:|---|
| \`0x08E5BEB4\` | 13,418 | 39,680 | \`0x08027DE8\` |
| \`0x08E5F320\` | 13,403 | 39,936 | \`0x08027DD0\` |
| \`0x08E6277C\` | 17,064 | 32,768 | \`0x080CEB8C\` |
| \`0x08E66A24\` | 28,208 | 76,452 | \`0x080CEB88\` |
| \`0x08E6D854\` | 29,239 | 77,228 | \`0x080CEB80\` |
| \`0x08E74A8C\` | 28,272 | 77,088 | \`0x080CEB84\` |
| \`0x08E7B8FC\` | 513 | 4,096 | \`0x08E2E73C\` |
| \`0x08E7BB00\` | 924 | 4,096 | \`0x08E2E740\` |
| \`0x08E7BE9C\` | 1,218 | 4,096 | \`0x08E2E744\` |
| \`0x08E7C360\` | 1,361 | 4,096 | \`0x08E2E748\` |
| \`0x08E7C8B4\` | 563 | 4,096 | \`0x08E2E74C\` |
| \`0x08E7CAE8\` | 1,024 | 4,096 | \`0x08E2E750\` |

The remaining **16 candidates** have no exact 4-byte-aligned pointer under
this simple search; indirect/indexed access, relocation, false-positive
streams or unreferenced data remain possible. The table **does not identify
an asset type** or establish offsets in the European ROM.

The final MiB of the U.S. ROM (file offsets \`0xF00000..0xFFFFFF\`) is
entirely \`0xFF\`. This is padding, not proof of unknown game data.

## Required next steps

1. **Keep the European matching work honest.** M0's European bit-identical
   rebuild remains blocked until a legitimate European \`baserom_sa3.gba\` is
   available in the local build environment with compatible \`SAT-R/agbcc\`.
2. **Use the supplied USA ROM for static reverse engineering now.** Start
   with the 12 directly referenced LZ10 candidates: identify the pointer
   table owners, decompression callers, data formats and U.S.-only symbol
   names. Do not transplant offset constants into the European project.
3. **Establish separate USA build proof** if USA bit-identical support is
   desired: isolate code/data regional divergences, reproduce the U.S. ROM's
   SHA-1 and maintain *separate* USA and Europe progress baselines.
4. Add an address-level cross-version correspondence table only after
   confirming function boundaries and signatures independently. Avoid
   treating one ROM's symbol offsets as correct in the other.
5. Close M0 only after actual compilation and reference-hash verification;
   neither ROM audit nor LZ10 scanning substitutes for matching C functions.

## Evidence

- Local audit executed against the supplied 16-MiB USA file.
- \`scripts/rom_audit.py\` self-tests: 9 passing as of this report.
- \`--require-region USA\`: success.
- \`--require-region EUROPE\`: exit code 2, as designed.
- Matching compilation, emulator execution and cross-region binary diffs:
  **not run** (no European baserom/toolchain installed in this environment).

The original SAT-R repository disallows AI-created issues/PRs. Keep this
AI-assisted work in the independent fork and do not submit it upstream.
