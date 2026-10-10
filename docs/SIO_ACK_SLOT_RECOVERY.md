# SIO acknowledgement and slot synchronization source recovery

**2026-10-10 • fork `celsowm/sa3` • direct commits to `main`**

Five previously empty `NONMATCH` functions in
[`src/sio_stuff_x.c`](../src/sio_stuff_x.c) have recovered C control flow,
parameters, packet recognition, queue copies and return values:

| Function | Recovered Thumb behavior |
|---|---|
| `sub_8024A4C(u16)` | Propagate negative link error; if connected, copy four receiver identity bytes into outgoing slots on `0x6603`/`0x6604`; always call `sub_8025BEC(value & 0xFF)` on nonnegative status; return 0 |
| `sub_8024AC0(u16)` | Update player ID from SIOCNT bits 4–5; on `0x6603`, `0x6604` or `0x6606`, update four cached IDs; acknowledge via `0x10 << player` only when `1 << player` is clear (return 2 without sending); otherwise dispatch `sub_8025C20` and return 0 or 1 |
| `sub_8024B84(u16)` | Recognize `0x6603`/`0x6604`, copy four IDs to both outgoing slots and local cache; reply 1 on `0x100 << player`, otherwise 2 on `0x1000 << player`; otherwise send through `sub_8025C64`, returning 0 |
| `sub_8024F1C(u8)` | Remap hardware IDs 0→2 and 1→3, mark that outgoing slot `0xFF`, reset the halfword acknowledgement mask at offset `0x0C`, OR successive masks from `sub_80247D4` and `sub_80248F4`, then invoke `sub_8025C8C`; return 1 or the original negative link status |
| `sub_8025024(u16)` | Remap hardware player index, copy four cached IDs into outgoing slots on `0x6607`/`0x6608`, return 2 on the unacknowledged `0x10 << slot` flag and 1 on other valid replies; otherwise send through `sub_8025808` and return 0 |

Each source implementation preserves `NONMATCH`, so the historical
matching build **still uses the original Thumb ASM**. This is verified
source-level recovery, **not** newly matched C bytes.

## Tests and checks

- Added [`scripts/tests/test_sio_negotiation_host.py`](../scripts/tests/test_sio_negotiation_host.py).
  It **extracts the five actual C bodies** from the checked-out source,
  rather than maintaining a second set of implementations. The native
  harness exercises 4 player indices × 5 link statuses × 2 connected-flag
  states × 6 packet identifiers × 4 acknowledgment combinations =
  **960 states**, or **4,800 function calls**, checking packet-slot
  contents, local caches, callback counts, return values and the order of
  two acknowledgement-mask updates. This newly committed test has
  **not yet been observed running on GitHub Actions**.
- Locally compiled a byte-for-byte transcription of the first four
  new source bodies using GCC `-std=c99 -O2 -fwrapv -Wall -Wextra
  -Werror -fsanitize=undefined`: **3,840 calls passed**. The fifth,
  independently compiled source-equivalent body passed **800 cases**;
  **4,640 total local calls**. This evidence is *equivalent-body native
  testing*, not an assertion that the GitHub-extracted test was executed.
- All five function bodies were compiled into relocatable ARMv4T/Thumb
  ELF objects with Clang, confirming syntactic/ABI feasibility for
  the ARM target. Clang is **not** the pinned original `agbcc`.
- A review found two important sequencing requirements, corrected in
  the production C: store `gStageData.playerIndex` **before**
  `sub_802610C()`, and expose the first mask in
  `gMultiSioSend.raw[0x0C:0x0E]` **before calling**
  `sub_80248F4()`. The host test explicitly guards both effects.

## Current status

After this batch, the source has **92 of 168 SIO `NONMATCH` bodies
implemented in C**, leaving **76** without C implementations.
GitHub Actions currently reports **0 recorded workflow runs** in this
fork, so hosted testing remains unconfirmed.

The GBA matching percentage is **not updated**. The last historical
figure is approximately 77.97%, but only the actual original compiler,
linker, European ROM input, and full `make compare` can establish
new byte-identical matching. Do not count source-C implementations
or ASM interval sizes as new matching progress.

No game ROM, source-binary extraction or assets were uploaded.
