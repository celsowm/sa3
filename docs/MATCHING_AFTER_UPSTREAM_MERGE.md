# Post-upstream-merge matching sprint (2026-10-13)

Baseline: fork `main` after PR #3, merge `ce7b1502d`.

## Measured vs unverified

- **Latest previously verified match milestone:** 663,508 / 816,408 code bytes, 81.2716%, at `f135a325` **before** the upstream merge. This is *not* a post-merge measurement.
- The merged upstream reorganized `src/game/sa3/character_select.c`, `src/game/sa3/cutscenes/opening.c`, and `ldscript.txt`; do not assume the previous match percentage survived unchanged.
- The current repository tree contains **428** `asm/non_matching/*.inc` paths. The previously generated `docs/nonmatch_triage.csv` has **418** rows. These are different concepts; `ASM_FUNC` fallbacks and orphaned includes must be counted separately.
- The upstream merge reintroduced `asm/non_matching/game/char_select__sub_809947C.inc` for the C `NONMATCH` wrapper. Treat potential matching regression as an investigation, not a proved code-byte loss.
- Full `make compare` and the post-merge `sa3.map` were **not executed** in the current environment (no original agbcc / ARM GNU toolchain). Input European ROM SHA-1 was verified separately, but verifying the input does not verify the newly generated output ROM.

## Immediate workflow

Run the new ROM-free audit first:

```bash
python3 scripts/matching_audit.py --output docs/matching_audit.md
python3 scripts/matching_audit.py --json --output docs/matching_audit.json
python3 -m unittest discover -s scripts/tests -v
```

The report distinguishes:
- Active `NONMATCH` and `ASM_FUNC` references.
- Unreferenced `.inc` files, which should **not** be deleted automatically.
- Missing fallback includes.
- Fresh `NONMATCH` references absent from the saved triage CSV.
- Obsolete ranked paths and duplicate entries.
- The nearest available instruction-level diffs, and groups in the same source file.

Use `--strict` to fail on missing references and out-of-date rank coverage once the triage is regenerated. Never consider a stale triage score to be a measured matching result.

Then perform a clean, private European ROM build on a machine with the pinned SAT-R agbcc and ARM binutils:

```bash
make -j"$(nproc)" compare
sha1sum -c sa3.sha1
python3 scripts/progress.py text
python3 scripts/progress.py text -m
python3 scripts/nonmatch_triage.py
python3 scripts/matching_audit.py --strict
```

## Ranked source-level targets

The following are **pre-merge** instruction differences, not fresh compiler results:

| Batch | Functions | Difference in last triage | Notes |
|---|---|---|---|
| P1 (paired) | `Task_802F368`, `Task_802F698` | one edit each | Both in `src/game/sa3/interactables/platform.c`; compiler allocation is coupled; test together |
| P2 | `sub_8078BAC` | one edit | `boss_7.c`, register/call-layout sensitive |
| P3 | `CreateEntity_Omochao` | two edits | self-contained spawn task |
| P4 | `Task_14_805C03C` | two edits | enemy logic |
| P5 | `UpdateBgAnimationTiles` | two edits | background animation |
| P6 | `Player_801D1D0` | two edits | player code; broad regression surface |

For the platform pair:

```bash
python3 scripts/nonmatch_triage.py --show Task_802F368 -v
python3 scripts/nonmatch_triage.py --show Task_802F698 -v
```

Fix only the specific compiler-generated differences and preserve the original execution semantics. When the candidate C compiles to an identical instruction stream, promote the **pair in the same test batch**, then run full `make compare`. If the final ROM SHA-1 changes, restore the original fallback and treat the attempt as non-matching.

## Completion definition

Matching success is **the generated European ROM with SHA-1 `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`** plus a sound map-derived increase in matched code bytes. Do not count source-level C recovery, instruction similarity, or `.inc` removals as binary matching without the full-ROM validation.

Keep the European ROM private. SAT-R upstream explicitly rejects AI-generated submissions; this plan is intended for `celsowm/sa3` only.
