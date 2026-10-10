# Sonic Advance 3 — Matching Decompilation Completion Plan

> Scope: `celsowm/sa3` (independent fork of `SAT-R/sa3`).
> Baseline: `937a94e6492ddc9e561f1510314ce717ec7f6aca` (2026-10-10).
> Objective: finish the **matching** GBA decompilation, then finish identifying/structuring remaining data, without changing game behavior or the target ROM.

## 1. Definition of done

The completion claim is justified only after **all** of the following:

1. A clean, reproducible build of the European ROM (`sa3.gba`) passes `make compare` and the `sa3.sha1` reference check: SHA-1 `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.
2. `python3 scripts/progress.py text -m` reports **100.0000% matched code**, with a manually audited classification of the remaining assembly (startup, library, intentionally handwritten assembly vs. game functions).
3. No remaining reachable game function is included through `ASM_FUNC`, `NONMATCH`, or `asm/non_matching/*.inc` as a substitute for matching C. Retained assembly has a specific rationale documented by path.
4. Remaining large `asm/*.s` code units are converted to matched C where applicable, or documented as legitimate low-level assembly.
5. `python3 scripts/progress.py text` reports **100% decompiled code**, using the same audited scope.
6. Data identification/analysis is completed as a separate tracked milestone: named structures and well-understood asset/data boundaries, with no claim that merely extracting a blob makes it understood.
7. Project toolchain, build and ROM comparison can be repeated from clean checkout with a **user-provided, lawfully obtained** baserom; CI and repository history never distribute the ROM.
8. Emulator smoke/regression scenarios pass for startup, normal stages, characters and partners, bosses, special stages, saves, audio and multiplayer/link behavior. Emulation tests supplement, **not replace**, binary matching.

**Non-goals:** rewriting mechanics, optimizing code, porting to other consoles, changing gameplay, modifying assets, or claiming matching based on a visually similar ROM. The LibSaturn port, if pursued, should be a separate downstream project after the GBA reference is stable.

## 2. Baseline and measurement

The fork's `main` was identical to upstream at the baseline SHA. The upstream published `gh-pages/reports/progress-sa3-*.csv` records contain that **exact** SHA and the following map-derived counts:

| Measurement | Baseline | Gap | Target |
|---|---:|---:|---:|
| Decompiled code bytes | 722,852 / 816,408 (88.54%) | 93,556 | 100% |
| Matching code bytes | 636,516 / 816,408 (77.97%) | 179,892 | 100% |
| Analyzed data bytes | 4,930,229 / 14,011,012 (35.19%) | 9,080,783 | 100%, separately audited |

Important: the difference between decompiled and matching code is **86,336 bytes** of existing C classified as non-matching. The other **93,556 bytes** remain not yet decompiled by the progress script. File sizes and numbers of functions cannot be added to those ROM-byte measurements.

The source tree contains 225 `.c` files; `asm/non_matching` contains **187 `.inc` files** (excluding two `.gitkeep` files), totaling 783,679 bytes **of assembly text on disk**, not 783,679 ROM bytes. A source file may contain more than one unit to match.

### Remaining `asm/non_matching` source-inventory hotspots

| Area | `.inc` files | Next action |
|---|---:|---|
| `game/interactables` | 37 | Convert small gameplay objects; consolidate common struct understanding |
| `game/bosses` | 33 | Group by boss, preserve task lifecycles and collision timing |
| `game/stage` | 25 | Player, camera, stage intro/UI: regression-critical |
| `game/sa3` | 23 | Options, character select, special stage, SA3-specific systems |
| `game/math` | 18 | Match functions, inline behavior and type/shift semantics |
| `engine` | 15 | Shared rendering/engine initialization and background helpers |
| `game` top-level | 14 | Miscellaneous gameplay/character selection |
| `game/enemies` | 12 | Prefer small self-contained enemy functions |
| `game/shared` | 8 | Shared stage/rings/music helpers |
| Root | 1 | Unclassified utility; identify owner |

Large standalone Assembly sources requiring **function-level inventory**, not whole-file rewrite:

- `asm/boss_final.s` (~227 KB Assembly source)
- `asm/sio_stuff_x.s` (~208 KB)
- `asm/boss_extra.s` (~190 KB)
- `asm/game__opening.s` (~87 KB)
- `asm/game__mp_char_select.s` (~80 KB)
- `asm/code_z_1.s` (~35 KB)

The above sizes are repository file sizes, not runtime code sizes or reliable effort estimates.

## 3. Work plan (ordered, with exit gates)

### Phase 0 — Establish reproducible baseline, safety and an actionable backlog

- [ ] Provision the exact compatible `SAT-R/agbcc` toolchain (including the libc/newlib revision noted in README), `arm-none-eabi` binutils, `clang-format-13`, native build utilities and Python `gitpython`.
- [ ] Verify the local `baserom_sa3.gba` is the specified **European** revision and never commit, attach or publish copyrighted ROM bytes.
- [ ] Run a clean `make -j"$(nproc)"` (which defaults to `compare` on GBA); save the commit, compiler version, hash result, map and output of both modes of `scripts/progress.py`.
- [ ] Enumerate linker-map **functions and ROM-byte ranges** behind every `ASM_FUNC`, `NONMATCH`, `asm/non_matching` include and standalone `asm/*.s`. Classify into `asm-only`, `C-nonmatching`, `matching`, `data`, `handwritten/third-party`, or `unknown`.
- [ ] Build a machine-readable `docs/decomp-backlog.csv` (function, address, size in ROM bytes, C file, ASM path, status, category, owner, validation evidence, latest commit), **generated from real map/symbols** rather than guessed file-size percentages.
- [ ] Add a small read-only reporting tool that detects remaining ASM inclusions, naming placeholders and regressions, and produces per-area counts + matching deltas. Use the existing `scripts/progress.py` as the source of truth for percent complete.
- [ ] Harden fork CI before allowing untrusted contributions: audit upstream's `pull_request_target` plus `allow-unsafe-pr-checkout` combination; do not give secrets to untrusted code. Keep public jobs for formatting/static checks; gate ROM-backed comparison on trusted contexts with secure assets or run locally.
- [ ] Add documented Linux/macOS build instructions; pin toolchain revisions. No dependency on an unavailable hosted ROM.

**Gate:** exact baseline ROM comparison is green locally and there is a prioritized list of real functions with measured ROM sizes. If baserom/toolchain is unavailable, mark the gate **BLOCKED**, not passed.

### Phase 1 — Resolve isolated `asm/non_matching` C replacements

- [ ] Sort candidates by dependencies, ROM bytes, function size and ability to verify immediately.
- [ ] First wave: isolated enemy routines, small `interactables`, leaf math/helpers and single-task wrappers.
- [ ] Second wave: remaining `game/interactables`, `game/enemies` and self-contained `game/sa3` routines.
- [ ] For each candidate reconstruct correct types, integer widths/sign extension, global addresses, structs and offsets, control flow and inlining; inspect compiler output against the target function.
- [ ] Replace the fallback only after its matching C builds and whole-ROM SHA-1 comparison passes; remove stale `.inc` references and update backlog/progress.
- [ ] Commit narrowly scoped units, never large cross-cutting refactors during matching work.

**Gate:** zero unreviewed easy/leaf candidates; measurable increase in matched code and no ROM/SHA regression.

### Phase 2 — High-coupling player/stage and shared engine systems

- [ ] Complete `game/stage` code: player and partner states, camera, stage intro, UI and collision helpers.
- [ ] Complete `game/shared` and `engine`: stage/music/ring managers, background updates, engine initialization and any shared code requiring matching.
- [ ] Resolve `game/math` leftovers with precise signedness, shifts, division, fixed-point and inline assumptions.
- [ ] Prefer shared, correctly named structs/constants over incorrect per-file casts; avoid changing already-matching call sites without testing every affected translation unit.
- [ ] Use related SAT-R/sa2 code **as semantic reference only**; SA3 ABI, code generation and data layouts must be verified directly.

**Gate:** no unresolved `game/stage`, `game/shared`, `game/math`, or `engine` substitutions; validated stage start/move/collision/finish sequences.

### Phase 3 — Character selection, SA3-specific state machines and bosses

- [ ] Match remaining `game/sa3` paths: selection, options, opening, partner AI, special stage and interfaces.
- [ ] Close `game/bosses` non-matching routines in order of dependency, with one boss and all state transitions per validation batch.
- [ ] Reverse engineer cross-file task ownership, callback signatures, parent/child task lifetimes, sprite pointers, effects and boss hitboxes before matching.
- [ ] Define deterministic gameplay scenarios for character pairing/tag moves, extra stages, bosses and credits; correlate behavior with original ROM in emulator.

**Gate:** all high-level game C units accounted for and the matching code percentage rises without untested behavior changes.

### Phase 4 — Retire standalone Assembly code islands

- [ ] Parse `asm/boss_extra.s` and `asm/boss_final.s` into address-level function inventory; migrate per logical boss state machine, retaining linker order and symbol addresses.
- [ ] Migrate `asm/game__opening.s` and `asm/game__mp_char_select.s` according to call graph and dependencies, not line count.
- [ ] Migrate `asm/sio_stuff_x.s` in separable pieces and validate link/multiplayer timing; this is a high-risk subsystem and must not be tackled as one giant rewrite.
- [ ] Audit `asm/code_z_1.s` and smaller miscellaneous segments.
- [ ] Explicitly mark unavoidable low-level stubs, startup or libraries as intentional ASM; separate them from unfinished game logic.
- [ ] Verify each translated function against target assembly and each integration against the full ROM's hash.

**Gate:** 100% matched and 100% decompiled **code within the audited scope**, and no unexplained game-function Assembly.

### Phase 5 — Finish data identification and asset understanding

- [ ] Reconcile the remaining 9,080,783 data bytes by linker-map section and ownership. Prioritize true unknowns; distinguish compression, padding, graphics, sound, tables, map/entity data, binary includes and legitimate third-party artifacts.
- [ ] Replace opaque unknown data with documented symbols/structures and extraction/reproduction rules where practical, without changing bytes, alignment, ordering or ROM offsets.
- [ ] Verify zone/act maps, tilemaps, collision metadata, graphics/palettes, animation tables, localized strings and audio assets.
- [ ] Identify data which must legitimately remain verbatim binary and document the provenance and exact-match rule rather than claiming it was reconstructed.
- [ ] Update the progress script's classification only after a transparent audit; never inflate completion by recategorizing unknown data.

**Gate:** 100% of project-defined data identified/analyzed, or publish an explicit remaining-data inventory and label the project 'code complete, data incomplete'.

### Phase 6 — Final QA and release handoff

- [ ] Rebuild from an empty build directory twice using pinned tools and a local, verified base ROM.
- [ ] Assert bit-identical SHA-1 after each build and retain an auditable per-function progress trail.
- [ ] Exercise smoke matrix on mGBA/compatible emulator: boot, main menu/options, each playable character, partner/tag actions, all zones, bosses, special stages, saves/loads, multiplayer/link and credits.
- [ ] Document outstanding runtime/emulator limitations and separate them from mismatches (a matching ROM is the primary correctness oracle).
- [ ] Remove only verified obsolete `asm/non_matching` fallbacks; keep useful reference disassembly available through history or documentation.
- [ ] Write `docs/DECOMP_COMPLETION_REPORT.md` with commands, environment/tool versions, source SHA, target ROM SHA, map-derived code/data metrics and exceptions.

**Gate:** completion report links to reproducible evidence; no unchecked TODO masquerades as completion.

## 4. Execution protocol for each function

1. Locate target address, size, references, original disassembly and the containing source/object.
2. Identify calling convention, Thumb/ARM mode, register/spill pattern, literals, signedness, data dependencies and struct field offsets.
3. Construct clean C (temporary m2c-style output is a hypothesis, not accepted final source).
4. Compile with **exact** target agbcc version and flags; compare generated instructions/literals/ordering, while checking symbol visibility and object boundaries.
5. Keep adapting C until the target instruction stream matches; remove ASM fallback and confirm the full linked ROM hash. Code which compiles but fails matching is **not done**.
6. Re-run progress metrics, `make check_format`, and subsystem emulator tests when applicable.
7. Record evidence and commit with scope like `match: finish <function> in <subsystem>`.

Do **not** use `NON_MATCHING=1`, `DEBUG=1`, `COMPARE=0`, or emulator similarity to declare an exact-match milestone done.

## 5. Local verification commands

```bash
# Install dependencies, set up compatible agbcc, and supply your own
# legally obtained, SHA-verified European baserom_sa3.gba first.
make -j"$(nproc)"             # Default GBA goal invokes compare
make compare                 # Must pass original ROM SHA-1
sha1sum -c sa3.sha1
python3 scripts/progress.py text
python3 scripts/progress.py text -m
make check_format
```

`scripts/progress.py` requires `sa3.map`; `make` requires the compiler and assets. Preserve command exit codes and raw output as evidence. For macOS use an appropriate job-count command instead of assuming `nproc`.

## 6. Progress milestones and decision rules

| Milestone | Required proof |
|---|---|
| M0 — Baseline verified | Reproducible build/hash; measured function inventory; safe CI |
| M1 — 80% matched | All matching work verified, progress +2.03 percentage points from baseline |
| M2 — 85% matched | Focused leaf/gameplay batches completed, subsystem smoke tests |
| M3 — 90% matched | Player, stage and engine hotspots significantly reduced |
| M4 — 95% matched | Most bosses and SA3 state machines complete, major ASM islands underway |
| M5 — 100% matched | No game-function fallback; full ROM SHA and audit clean |
| M6 — Data completion | Remaining data fully classified and independently reported |
| M7 — Final verification | Clean rebuild, regression matrix, completion report |

Prioritize **verified matched ROM bytes**, not number of commits, lines of C or removed `.inc` files. If progress doesn't move, inspect the actual linker map and function boundaries before attributing credit.

## 7. Risks and boundaries

- **Compiler sensitivity:** recompilation under the wrong agbcc/newlib revision can fail exact matching even when C semantics look right. Pin the toolchain first.
- **Misleading metrics:** `.inc` file count and Assembly file length are not ROM code bytes; separate 'matching', 'decompiled' and 'data analyzed' percentages.
- **Coupled structs/ABIs:** global struct changes can silently break other previously matching functions; use a small batch + full SHA check.
- **Multiplayer/serial timing:** `asm/sio_stuff_x.s` needs protocol and emulator-link tests in addition to matching.
- **ROM distribution:** baserom must remain private and user-supplied; no copyrighted ROM or unreleased assets in public repo/CI artifacts.
- **Fork/upstream policy:** upstream SAT-R explicitly prohibits AI/LLM-origin issues and pull requests. Keep this AI-assisted plan and future work inside `celsowm/sa3`; **do not open upstream PRs/issues containing AI-generated content**.
- **Status honesty:** repository files and upstream progress reports were inspected, but a new local ROM build/emulator run has **not** been executed as part of preparing this plan.

## 8. First implementation batch (do next)

1. Baseline verification + pin tools; solve fork CI security and trusted local ROM handling.
2. Implement **read-only** map/symbol-aware backlog report and capture M0 evidence.
3. Complete 5–10 genuinely isolated small `game/enemies`/`game/interactables` functions, each with function-level matching and full-ROM checks.
4. Build deterministic mGBA smoke scenarios for menus, character + partner movement and one stage.
5. Recompute matching/decomp/data metrics and choose the next batch by actual ROM-byte contribution.

Do not start a mass conversion of `asm/sio_stuff_x.s` or the final-boss assembly before the baseline and per-function verification loop are reliable.

## 9. ROM audit addendum — 2026-10-10

The first real ROM artifact supplied for this fork was a **USA rev-0** image,
SHA-1 `30db467effa5014806d42db57e2299398a51355b`, GBA ID `B3SE`.
It is **not** the European `B3SP` / `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`
ROM targeted by the existing matching source and progress metrics.

**Completed first ROM-backed work:**
- Added `scripts/rom_audit.py`, which validates ROM fingerprints, header and
  ARM branch entrypoint, and scans structurally valid LZ10 candidates.
- Added 9 passing offline unit tests in `scripts/tests/test_rom_audit.py`.
- Identified 28 candidate LZ10 streams in the USA ROM; 12 have directly
  observable aligned pointer-shaped references. Full details are in
  [USA_ROM_BASELINE.md](USA_ROM_BASELINE.md).
- Verified that `--require-region USA` succeeds and
  `--require-region EUROPE` fails as designed.

**M0 status: partial / not passed.** The uploaded USA ROM can support static
reverse engineering and a future *separate* USA matching target. It cannot
satisfy the existing European bit-identical compare. No compiler-backed ROM
build or emulator test has yet been run; the upstream 77.97% matching baseline
must not be advanced based only on this metadata analysis.

**Next priority:** identify owners/decompression callers for the 12
pointer-backed USA streams, build a verified USA↔Europe cross-reference map
only with independently established correspondence, and obtain a local
European source of reference bytes before declaring any Europe matching win.

## 10. European reference ROM now verified — 2026-10-10

The user supplied the **exact European rev-0 ROM** required for the original target:

- `B3SP` / 16 MiB / GBA header valid.
- SHA-1 `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39` matches `sa3.sha1`.
- SHA-256 `d9c96aad4b3795d3e667637fcf9399636ae355fcf12677d2883107ea273dea15`.
- Reference bytes are privately available for analysis; **never commit or upload ROM data**.

Cross-region mapping completed: 28 structurally valid aligned LZ10 candidates
per ROM, 12 with direct pointer-shaped sites per ROM, and 22 EU streams
with identical decoded SHA-256 in USA. The 12 directly referenced
correspondences all have EU stream address = USA stream address + `0x390`,
but this is not a safe general relocation rule. A companion reproducible
tool and three offline tests are committed:

- [EUROPE_ROM_BASELINE.md](EUROPE_ROM_BASELINE.md)
- `scripts/rom_region_compare.py`
- `scripts/tests/test_rom_region_compare.py`

**M0 remains INCOMPLETE; build/hash verification is currently BLOCKED** in this
sandbox: compatible agbcc and ARM binutils are not installed, and direct
network access from the build container is restricted. The input ROM itself
is now **verified and available**, so the ROM itself is no longer the blocker.
The remaining M0 inventory and CI gates also still need verification. No
claim of successful compilation, 100% match, increased matching percentage,
or emulator runtime validation has been made. Next work: provision exact
toolchain, reproduce `make compare`, measure the current map, then start
verified leaf-function matching. 


## 11. First ROM-backed executable tooling batch — 2026-10-10

Work was committed directly to `main` in this independent fork:

- `docs/asm_standalone_function_inventory.csv`: **448 named ASM function entry labels** across six standalone `asm/*.s` sources. Of 442 upper-bounded intervals, 57 are at most 32 bytes and 244 at most 128 bytes. **These spans are NOT exact function sizes**; they may include literal pools and padding.
- `scripts/asm_function_backlog.py`: reproducible inventory of standalone labels and `ASM_FUNC`/`NONMATCH` fallback `.inc` ownership from the checked-out source. With the private exact EU ROM, optionally records metadata-only SHA-256 hashes of bounded intervals. Adds synthetic tests.
- `scripts/asm_leaf_candidates.py`: requires SHA-1-identical European ROM and cross-references the committed CSV, finding Thumb-only `bx lr` leaf candidates without dumping ROM content; adds synthetic tests.
- `docs/asm_thumb_leaf_candidates.json` and `docs/ASM_VERIFIED_LEAF_CANDIDATES.md`: **17 of 17** source intervals of four bytes verified on the European ROM. Each contains `70 47 00 00` (`bx lr` plus padding). **Eight TaskDestructor callbacks** are the first proposed actual-C migration batch, subject to ABI/linker and agbcc proof.
- `.github/workflows/build.yml`: removed unsafe `pull_request_target` execution/checkout; tests run without private ROM on push/PR. ROM-backed job is opt-in for trusted pushes via repository variable `ENABLE_ROM_BUILD=true`, with `STORAGE_URL`, `STORAGE_USERNAME`, and `STORAGE_PASSWORD` configured privately. No secrets on PR jobs.
- The local sandbox ran **20 offline unit tests** from the synthetic triage and ROM-audit suite using the corresponding local module implementations. GitHub Actions has **zero recorded runs** at this writing, so hosted CI success is not claimed.
- A local Clang 17 `armv4t-none-eabi -mthumb -O2` compilation of two experimental empty callbacks emitted `bx lr`, corroborating the candidate codegen pattern. **This is not an agbcc matching result.**

**Current gate:** the European reference ROM exists and is SHA-verified, but `SAT-R/agbcc` and ARM binutils are not available in the current sandbox; `make compare` was not executed. The legacy matching percentage (about 77.97%) remains unchanged. No candidate was removed from ASM or declared matching without the exact build.

For the next implementation commit, inspect each destructor's signature and its place within the explicitly ordered `ldscript.txt` `.text` units before editing source. Changing C-object/ASM-object ordering will otherwise shift downstream ROM addresses and break matching even if a generated stub instruction is correct.


## 12. Tactical execution sprint — 2026-10-10

The follow-on execution plan is committed as [NEXT_MATCHING_SPRINT.md](NEXT_MATCHING_SPRINT.md).
It orders the work as (1) reproducible EU ROM build and toolchain pinning;
(2) map-derived exact function-byte/matching oracle and CI validation;
(3) one or two Thumb destructor no-op conversions to prove linker feasibility;
(4) substantive existing-C `NONMATCH` candidates `sub_806CFD4`,
`sub_805E624`, then `sub_8050D90`; (5) ten verified matching
conversions and new prioritization toward the 80% matching milestone.

**Planning-only update**: No new C code was converted, no agbcc build was
executed, and the historical ~77.97% matching rate is unchanged.
