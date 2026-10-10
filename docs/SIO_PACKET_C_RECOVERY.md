# SIO packet reconstruction — 2026-10-10

This pass recovered **nine additional C bodies** in
[`src/sio_stuff_x.c`](../src/sio_stuff_x.c), keeping the original Thumb
`NONMATCH` fallbacks for the verified ROM build.

| Function | Packet / side effect recovered from original Thumb |
|---|---|
| `sub_8027620(u16,u16)` | Queue five bytes: `30,lo(a),hi(a),lo(b),hi(b)` |
| `sub_8027834(void)` | `38,23,0,stage[0xB4],0` |
| `sub_8027878(u8)` | `38,24,value,0,0` |
| `sub_802789C(void)` | `38,25,stage[0xAE],stage[0xAF],0` |
| `sub_80278C4(void)` | Copy `stage[5]` to `gMultiSioSend.raw[0x12]`; copy stage bytes `0xAE/AF` to send bytes `0x14/15` |
| `sub_80274AC(u16,u16)` | Set `stage[0xBB]=7`; queue `08,lo(a),hi(a),lo(b),hi(b)` |
| `sub_80274F4(u8,u16,u16)` | Queue `((flags&7)|0x10),lo(a),hi(a),lo(b),hi(b)` |
| `sub_80276A8(u8)` | Queue `38,06,selected,0,0`: use `stage[0x8E]` only when `stage[6]==0` and the halfword at `0xAE` is zero; otherwise queue/store supplied value |
| `sub_80276F4(u16,u16)` | Set `stage[0x8F]=1`; queue `28,lo(a),hi(a),lo(b),hi(b)` |

**Five-byte queue invariant:** `sub_8026AB8` reads *five* bytes from
its input even where a caller's original Thumb local stack buffer
only initialized 2–4 of them. In the new C, any such undefined
trailing fields are explicitly initialized to zero to avoid reading
uninitialized host memory. This is a source safety decision, **not a
claim that those unknown stack bytes had zero values in the original
game**. The original ASM is still selected for exact builds.

## Tests and reproducibility

The test [`scripts/tests/test_sio_more_packet_handlers.py`](../scripts/tests/test_sio_more_packet_handlers.py)
extracts the **actual nine C implementations**, compiles the extracted
bodies with a host C compiler, and runs exhaustive/repeated checks for:

- All 65,536 first-u16 inputs, with a different second-u16 input,
  independently for packet types `0x30`, `0x08`, `0x10–0x17`
  and `0x28`
- All 256 values for each three `0x38` event packet handlers
- All 256 send-buffer synchronization variants, including non-target
  bytes staying unchanged
- All 256 inputs across four conditional `0x38/0x06` branches, testing
  state-byte updates, queue bytes and preserved cached values

**Locally executed:** equivalent copies of the nine C bodies compiled
with GCC `-std=c99 -O2 -Wall -Wextra -Werror` and UBSan
(`-fsanitize=undefined`) and **263,936 queue calls passed**. All nine
equivalent implementations also compiled to an ARMv4T/Thumb object with
Clang and strict warning flags.

**Not yet established:** the newly committed extraction-based Python
test has not been executed in hosted GitHub Actions or against a full
locally cloned fork, because the host sandbox cannot reach GitHub.
The main CI file already contains a `unittest discover -s scripts/tests`
job that will include the new test when Actions runs. GitHub's API
currently shows no workflow runs in this fork.

## Matching caveat

Nine additional source-level C reconstructions do **not** increase the
verified matching percentage. The matching build retains the original
Assembly through `NONMATCH`; no pinned `SAT-R/agbcc` build, full ROM
SHA-1 comparison, or emulator regression has been completed in this
iteration. The historical **~77.97% binary matching** estimate remains
the last reported value.

No game ROM, proprietary assets or extracted game binary bytes were
committed.
