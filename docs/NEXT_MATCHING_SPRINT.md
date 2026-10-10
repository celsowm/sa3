# SA3 matching decomp — next execution sprint

Status: **PLANNED — NO GAMEPLAY SOURCE CHANGES YET**  
Prepared: 2026-10-10 for fork `celsowm/sa3`, current `main` `e8e5cddb8342d27900f86dc32e8d79e22a3c621c`.

This is the tactical follow-up to [DECOMP_COMPLETION_PLAN.md](DECOMP_COMPLETION_PLAN.md), not a second competing completion definition.

## Goal and non-negotiable baseline

**Objective:** unblock the first verified C conversions, establish a reusable function-matching workflow and produce measurable growth of byte-accurate matching code toward 80%.

- Target: Europe rev-0, GBA ID `B3SP`, SHA-1 `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.
- A private, hash-verified European reference ROM has been inspected; never commit, push, attach to CI artifacts or redistribute ROM bytes.
- Previously published baseline at original source commit `937a94e`: **636,516 / 816,408 matching code bytes** (~77.9654%); **722,852 / 816,408 decompiled code bytes** (~88.54%). These are historical map-derived values; refresh after a clean local build.
- If the code-byte denominator stayed at 816,408, reaching 80% would require at least **16,611 additional verified matching code bytes**. This is an indicative milestone threshold, not a promise that tiny stubs will achieve it.
- Inventory: 448 standalone ASM labels across six major sources, including 17 verified 4-byte Thumb return/padding intervals. The latest repository tree contains **186 `.inc` files under `asm/non_matching`**; recheck macro ownership and stray/orphan includes with the actual tree before relying on counts.
- Previously **no** successful fork ROM build, hosted Actions test run, or newly matching C conversion was verified. Static ROM analysis is **not** matching code progress.

## Workstream A — M0, establish the exact matching oracle (highest priority)

### A1. Deterministic local build

1. Fetch `SAT-R/agbcc` and record the **exact installed git SHA**. Respect the updated libc/newlib requirement from the project README; do not silently use an old agbcc or modern GCC as the matching compiler.
2. Install/pin `arm-none-eabi` binutils, build dependencies, clang-format-13 and Python GitPython. Confirm versions in the evidence log.
3. Place a user-owned European baserom **only in the private workspace** as `baserom_sa3.gba`; verify its SHA-1 **before** building. The repository already ignores `*.gba`; also check `git status` for accidental binary/asset additions.
4. Run `make clean`, `make -j<N>` (the GBA default invokes `compare`), `make compare`, and `sha1sum -c sa3.sha1`. Collect commands, exit statuses, compiler SHA, full-ROM SHA, `sa3.map`, and tool versions.
5. Run `python3 scripts/progress.py text` and `python3 scripts/progress.py text -m`; record map-derived baselines and confirm the old published numbers or explain the delta.
6. Run ROM-free tests `python3 -m unittest discover -s scripts/tests -v` and `make check_format`. Fix failures without touching gameplay semantics.

**Gate A:** a **clean, reproducible `make compare` exits 0**, proving the exact EU ROM SHA. If the toolchain is unavailable or baseline cannot reproduce, keep all gameplay-conversion tickets **BLOCKED**. Tooling, inventory and ABI research may continue.

### A2. Verify CI and prevent any ROM leakage

- Confirm the ROM-free test job actually runs on pushes/PRs in the fork. The previous audit saw **zero** workflow runs, not evidence of success.
- Keep `pull_request_target` and unsafe checkout out of PR workflows; `permissions: contents: read` for untrusted jobs.
- The existing ROM-backed job is opt-in via `vars.ENABLE_ROM_BUILD == 'true'` on trusted pushes. Never enable it merely because the ROM is available in this conversation; it requires a privately controlled source, credentials, and independent leak review.
- Do not upload generated `.gba`, game resources or private reference files as GitHub artifacts. Publish only aggregate metrics/symbol maps where appropriate.
- If the `gh-pages` branch or reporting workflow does not exist/work on the fork, disable publishing until independently verified rather than treating publication failures as ROM-compare failures.

**Gate B:** ROM-free checks pass on fork Actions; ROM-backed build either passes in a secure trusted context or remains explicitly disabled with local `make compare` evidence.

## Workstream B — make function-level verification mechanical

Implement or extend a small `scripts/matching/` toolbox driven by the verified EU ROM, `sa3.map`, ELF symbols, the original assembler and compiled objects:

- Generate `docs/decomp-backlog.csv` from **real function boundaries and object/map ownership**, with `ROM address`, symbol, owner `.c`/ASM, bytes of executable code, fallback macro, status, dependency estimate, and last verified SHA. The existing `asm_function_backlog.py` label intervals are **upper bounds**, not guaranteed function sizes.
- Create a report that distinguishes (a) instructions, (b) literal pools/padding/alignment, (c) relocation/symbol pointer values, and (d) changed linker placement. Never call an interval matched because just `bx lr` matches.
- Capture compile flags for each unit; diff generated disassembly / exact ROM ranges in **Thumb or ARM mode as appropriate**. Preserve linker-ordered object placement in `ldscript.txt` and verify function-pointer Thumb-bit behavior when migrating ASM symbols.
- Establish a gate usable for every candidate: compile, compare object behavior/relocations, full `make compare`, refresh `scripts/progress.py -m`, and one relevant emulator smoke scenario.
- If a change fails the exact-ROM comparison, save a **metadata-only** mismatch report and revert/adjust the candidate; never mark a non-matching version done.

**Gate C:** demonstrate the report on one existing matching function and one original ASM fallback; no false-positive claim on padding-only matches.

## Workstream C — first 3 conversion batches

### Batch C1 — one or two 4-byte `TaskDestructor` proof-of-process conversions

Start with **one** from these user-ROM-verified candidates, then a second only after success:

- `TaskDestructor_80A13B0` at `0x080A13B0`, originally `asm/game__mp_char_select.s`
- `TaskDestructor_A0_80A3E34` at `0x080A3E34`, originally `asm/game__opening.s`

Evidence from the European ROM shows `70 47 00 00` (Thumb `bx lr` + padding) in both 4-byte source-label intervals. **Verify declarations and call sites**; `TaskDestructor` strongly suggests `void (struct Task *)`, but names are not proof of the ABI. Removing an ASM definition and adding a C object may break linker placement and function-pointer relocations; first design a minimal, reversible section/linker strategy. Do not rewrite all 17 at once.

If a fully C replacement cannot be kept at the exact symbol address without unacceptable linker hacks, **defer** these stubs. Their gain is only about 2 instruction bytes apiece; they are a matching-mechanism test, not the route to 80%.

**Gate C1:** one and then two `TaskDestructor` functions build with original agbcc, match exact target addresses and full ROM SHA, and report small positive map-derived matching-code deltas.

### Batch C2 — first meaningful existing-C NONMATCH conversions

Work on these **in order of measured executable ROM size and dependency complexity**, once A and B are green:

1. `src/game/sa3/bosses/boss_2.c::sub_806CFD4`, fallback `asm/non_matching/game/bosses/boss_2__sub_806CFD4.inc` — existing C body; inspect signed fixed-point arithmetic, conditions and exact return values.
2. `src/game/sa3/enemies/juggling.c::sub_805E624`, fallback `asm/non_matching/game/enemies/juggling__sub_805E624.inc` — existing C body; inspect loop lowering, address/data layout and register allocation.
3. `src/game/stage/camera.c::sub_8050D90`, fallback `asm/non_matching/game/stage/cam__sub_8050D90.inc` — existing C body, but more coupling and camera regressions; defer until first two match.
4. `src/game/sa3/bosses/boss_2.c::sub_806C6FC` — follow-up after `sub_806CFD4`, with boss state behavior tests.
5. `src/game/math.c::sa2__sub_8084EAC` — a small existing ASM fallback with a skeletal/unused C declaration; prioritize only after verifying signature, reachability and whether its effect is counted in project progress.

These are **investigation candidates**, not known easy matches. In particular, `.inc` text length is not compiled size and a plausible C body is not proof of byte identity.

**Gate C2:** at least **three distinct nontrivial C functions** verified matching one at a time, with `NONMATCH` fallbacks retired and exact ROM checks green; preserve source readability.

### Batch C3 — scale to a 10-function verified queue

- Regenerate and rank fallback queue by actual code bytes, compiler complexity, available C implementation and test impact. Prefer existing C `NONMATCH` over wholly ASM modules for early progress.
- After achieving **ten** newly matching routines with full SHA evidence, calculate ROM bytes gained and determine whether next work should focus on interactables/enemies or larger shared game/engine functions.
- Select next candidates based on **bytes matched per verified attempt**, not just number of functions or lines of Assembly converted.

**Gate C3:** 10 verified conversions, per-function ledger and zero baseline SHA regressions.

## Workstream D — toward 80% and beyond

Priorities after the first ten:

1. `game/interactables` (37 originally inventoried ASM `.inc` fallbacks) and `game/enemies` (12): self-contained entities first.
2. Remaining player/camera/math routines (`game/stage`, `game/math`): signed fixed-point math, collisions and calling conventions demand higher scrutiny.
3. `game/bosses` and SA3 state machines; functional test matrices for states, phase transitions and hazards.
4. Standalone `asm/game__opening.s`, `asm/game__mp_char_select.s`, `asm/boss_final.s`, `asm/boss_extra.s`, `asm/code_z_1.s`: migrate per dependency/call graph and preserve sections/linker addresses.
5. `asm/sio_stuff_x.s` only with verified link/multiplayer protocol and timing tests, then reconcile remaining shared engine, data and intentionally hand-written ASM.

Do not promise 80% merely by exhausting trivial no-ops. Track separate `decompiled`, `matched`, and `analyzed data` metrics and treat the final 100% matching audit as a distinct milestone.

## Acceptance checklist for EVERY matching commit

- [ ] Parent/baseline reference commit and function address recorded
- [ ] Correct function signature, ABI, fixed-point types and Thumb/ARM calling mode established
- [ ] Updated `C` code compiles with **pinned agbcc**, no `NON_MATCHING=1` bypass
- [ ] Original and emitted instruction/relocation/layout differences explained
- [ ] Original European ROM hash reproduced by `make compare`
- [ ] `sha1sum -c sa3.sha1`, `make check_format`, and ROM-free unit tests pass
- [ ] `scripts/progress.py text -m` shows validated new matched bytes (or classify and explain an unchanged result)
- [ ] Relevant emulator smoke test documented; no accidental ROM/resources committed
- [ ] Small commit directly to fork `main` with `match: <subsystem>/<symbol>` message

## Compact next-commit queue

| Order | Proposed deliverable | Required evidence | Outcome |
|---|---|---|---|
| 1 | Pinned agbcc + arm-none-eabi baseline and trusted ROM hash | `make compare` success, map and tool versions | M0 unblocked |
| 2 | ROM-free CI verified and backlog generated from actual map | workflow result, zero missing fallbacks | Tooling reliable |
| 3 | Per-function diff/oracle harness | matching/nonmatching fixture results | Accurate matching decisions |
| 4 | First `TaskDestructor` stub (optional linker feasibility spike) | exact address + full SHA | Process proved or consciously deferred |
| 5 | `sub_806CFD4` C matching | compile/ROM hash + updated ledger | First substantive conversion |
| 6 | `sub_805E624` C matching | compile/ROM hash + gameplay smoke test | Repeatable conversion |
| 7 | `sub_8050D90` or alternate easier leaf | compile/ROM hash + camera smoke | Third substantive conversion |
| 8 | Seven more function conversions prioritized from measured map | total 10 accepted commits | Next wave selected |

## Exit status and scope

**Current status is a plan, not verified implementation.** The correctly identified EU ROM is available for offline analysis, but this working environment currently lacks `arm-none-eabi` binutils and the exact `SAT-R/agbcc` compiler. No `make compare` or compiled new matching C has been claimed. All completion evidence must be generated by actual runs.

The original SAT-R/sa3 README prohibits AI-origin issues and pull requests; keep this AI-assisted plan and derivative development **inside the independent fork**, not submitted upstream.


## Execution evidence — 2026-10-10, next iteration

- Confirmed private EU ROM SHA-1 against `sa3.sha1`.
- A direct sandbox fetch/clone of GitHub failed at DNS resolution for `github.com`, and the sandbox has no `arm-none-eabi-as`. Therefore the matching build has **not** run; `make compare` and Clang alone are not substitutes.
- Fixed `scripts/matching_preflight.py` to require both `agbcc` and `old_agbcc`, plus the ARM preprocessor; added the associated test.
- Fixed the trusted `.github/workflows/build.yml` compare command to `make -j"$(nproc)" compare`.
- Created `scripts/boss2_reference_oracle.py` and `scripts/tests/test_boss2_reference_oracle.py` for candidate `sub_806CFD4`: original Europe ROM interval **0x0806CFD4..0x0806D01C** (72 bytes), SHA-256 `90b2fc662a30ffd5bf7693e8ebce4da3a744cabc389a2f4653daf509f0639ba1`. Four boundary behavior tests were authored; hosted or complete local suite execution for this new addition is **not yet verified**.
- This oracle documents vertical screen-space behavior, but is **not** an emitted matching C implementation. Its mathematical model assumes typical non-overflow game coordinates, not universal ARM flag accuracy.
- **No change to the historical matching percentage.** The immediate next gate remains provisioning agbcc/binutils in a network-enabled build environment and reproducing the European image checksum.


## Implemented source milestone — 2026-10-10: six mathematical C fallbacks

This iteration advanced actual game source, not only tooling:

- `src/game/math.c`: six formerly empty `NONMATCH` C bodies now contain
  fixed-point implementations for quaternion normalization/conjugation,
  quaternion multiplication, matrix transposition, quaternion-to-matrix
  conversion and 3x3 affine transform composition.
- `scripts/tests/test_math_c_fallbacks.py` extracts these functions from the
  **actual source file**, compiles them with native C and checks 2,600 seeded
  mathematical examples against separate reference formulas.
- A parallel equivalent local host-GCC implementation was compiled and
  evaluated on 2,600 samples (all passed); an equivalent ARMv4T Thumb object
  also compiled with Clang 17. Refer to
  [SA2_MATH_C_DECOMP_BATCH.md](SA2_MATH_C_DECOMP_BATCH.md) for evidence and
  restrictions.
- **These six are source-level C reimplementations, NOT verified matching C.**
  The `NONMATCH` fallbacks remain intact for original GBA builds because
  exact `agbcc` and `make compare` validation is still pending. Do not
  increase the historical 77.97% matching number.

**Updated priority:** once the exact European build runs, measure and tackle
`sa2__sub_8083B88` first among the new math functions because it covers
3x3 basis multiplication plus 64-bit translation, then the normalization and
matrix helpers. Return to Boss 2 `sub_806CFD4` and entity fallbacks after
confirming the best matching-code bytes gained per function.
