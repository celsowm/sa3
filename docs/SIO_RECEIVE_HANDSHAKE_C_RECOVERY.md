# SIO receive handshake and SIOCNT bitfield correction

**Date:** 2026-10-10. **Fork:** `celsowm/sa3`. All commits to `main`.
**Production:** [`src/sio_stuff_x.c`](../src/sio_stuff_x.c).

## Seven new C implementations

Seven original `NONMATCH` bodies were empty and now have typed,
source-level Thumb reconstructions:

| Function | Behavior reconstructed |
|---|---|
| `sub_8023FE0` | Propagate negative link-status error; reject `0x0C0C` error bits with `-4`; when connected, forward received byte 7 and return `0x1000 \| byte7` only for incoming type `0x6C0C` |
| `sub_8025360` | Send `sub_8025D10` on nonnegative status; require active participant mask 3/7/15 and received type `0x660C` at every active SIO slot |
| `sub_80254CC` | Clear local halfword at `gUnknown_03001060 + 0x50`, transmit zero with `sub_8025D20`, and require type `0x660D` in every participant selected by the mask; empty mask succeeds as in Thumb |
| `sub_80255B0` | Send current cached value; accept types `0x660D` and `0x660E`, store response byte 5 into the cached halfword and return 1 only for `0x660E` |
| `sub_8025614` | Similar response handling with `sub_8025D34`; accept exactly `0x660E` **or unsigned type greater than** `0x680F`; return 1 only for `0x660E` |
| `sub_8025674` | Send `sub_8025D48`; require participant mask 3/7/15 and received type `0x660F` at every selected slot |
| `sub_8025714` | Encode outgoing `0x6604` packet using hardware player bits 4–5, cached slot value for IDs 0–1 or `0xFF` for IDs 2–3, preserving remaining packet bytes |

The original `NONMATCH` ASM fallbacks remain active for the standard
matching ROM build. None of these C bodies is yet proven byte-identical.

## Confirmed Thumb decoding bug fixed in seven source bodies

The reference Thumb ID extraction is:

```asm
lsls r0, r0, #0x1a
lsrs r0, r0, #0x1e
```

This is `(SIOCNT >> 4) & 3`, **not `(SIOCNT >> 6) & 3`**.
The earlier source reconstructions were incorrect for IDs other than
cases in which SIOCNT happened to contain repeated bits.

Corrected all seven `(*(vu32 *)REG_ADDR_SIOCNT >> 6) & 3` occurrences
to `>> 4` in the production SIO file, covering:

`sub_8024AC0`, `sub_8024B84`, `sub_8024DC8`,
`sub_8024F1C`, `sub_8025024`, `sub_8025AA8`, and
the new `sub_8025714`.

Also corrected hardware-register mocks in two previously committed
regression tests and the documentation mentioning bits 6–7. The
corrected tests write `id << 4`, and the new receive test deliberately
sets misleading independent values in bits 6–7 to detect regressions.

## Test evidence and limitations

- New extraction-based test:
  [`scripts/tests/test_sio_receive_handshake_host.py`](../scripts/tests/test_sio_receive_handshake_host.py).
  It compiles the **real seven new C bodies**, extracted from
  `src/sio_stuff_x.c`, with GCC in CI, mocks the SIO register and
  buffers, and checks return values, callback counts, byte updates and
  participant masks. The test checks that no `>> 6` hardware decode
  remains. This committed extraction-based test has **not yet been
  observed running in GitHub Actions**.
- Locally, an independently transcribed native C implementation of
  all seven functions compiled with GCC `-O2 -fwrapv -Wall -Wextra
  -Werror -fsanitize=undefined`; **69,760 functional test calls passed**
  (handshake status/mask permutations, returned data, all byte-7
  variants, and SIOCNT player selection). Local executable:
  `/mnt/data/sa3_sio_handshake_validation`.
- The equivalent seven-body C source also compiled into a relocatable
  **ARMv4T/Thumb object** with Clang (`-target armv4t-none-eabi -mthumb`).
  This proves syntax/code generation for Clang only; it **does not**
  establish original `agbcc` matching or emulator correctness.
- Confirmed the input Europe ROM privately by SHA-1
  `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.
  No ROM binary bytes or proprietary assets were uploaded.

## Current status

The production SIO source now has **99 non-empty C `NONMATCH` bodies
out of 168**; **69** remain empty. These source C recoveries are not
compiled into the matching GBA build. The historical approximately
**77.97% matched** code measurement is **unchanged**, pending a
pinned `agbcc` toolchain, the European baseline and a successful
full `make compare`.
