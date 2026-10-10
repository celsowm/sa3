# SIO link-state and entity synchronization C recovery

**Date:** 2026-10-10. **Repository:** `celsowm/sa3` (`main`).
**Production file:** [`src/sio_stuff_x.c`](../src/sio_stuff_x.c).

Seven previously empty SIO `NONMATCH` bodies now have typed, nonempty C
implementations derived from their original Thumb routines:

| Function | Recovered behavior |
|---|---|
| `sub_8024DC8` | Get SIO player ID from `REG_ADDR_SIOCNT[7:6]`; propagate negative status; on success call `sub_8025770`, and recognize `0x6606` reply when connected |
| `sub_8025AA8` | Read same player ID; propagate negative status; on success send state via `sub_8025D10`; recognize `0x660D` reply when connected |
| `sub_80261B0` | Advance four-state local queue generation, clear queue-control byte, mark eight five-byte slots free, update flags on all four players, and mark send/receive byte `0x12` invalid |
| `sub_8027538` | Send five-byte X delta packet `0x18`, subtracting the entity-manager task-data 32-bit reference at offset `+4`, little-endian modulo `2^32` |
| `sub_8027578` | Send five-byte Y delta packet `0x20`, subtracting the task-data reference at `+8` |
| `sub_802790C` | Player event: store low byte at `Player+0x69`, set `StageData+0x8F`, set halfword `0x0384` at `Player+0x66` for high nibble `0x10`, or call `sub_80296F8` for `0x20` |
| `sub_802613C` | Clear global flag `0x400` and create a `Task_8026178` task with data size 0, priority `0x2000`, flags 0 and no destructor |

**Reverse engineering correction:** the actual Thumb instructions in
`sub_80261B0` compute `-0x39 == 0xFFFFFFC7`, **not**
`~0x39 == 0xFFFFFFC6`. The source-level C and its dedicated
regression test explicitly use `(u8)-0x39`. This preserves bit 0 of
the original player byte and clears exactly the intended state flags.

The offsets were cross-checked against the current `Player` (size
`0x150`) and `StageData` (`taskEntitiesManager` at `0x94`)
definitions. The SIO packet encoder writes five initialized bytes
because `sub_8026AB8` copies five bytes of each packet.

## Regression tests committed

- [`scripts/tests/test_sio_handshake_queue_reset_host.py`](../scripts/tests/test_sio_handshake_queue_reset_host.py):
  extracts the **actual three C bodies**; checks negative status
  propagation, ID-bit extraction, side-effect calls, 256 queue-reset
  scenarios, untouched player bytes and untouched payload bytes
- [`scripts/tests/test_sio_entity_offset_packets_host.py`](../scripts/tests/test_sio_entity_offset_packets_host.py):
  compiles the **actual two source bodies**, sweeps 65,536 input values
  across seven reference origins, checks all packet bytes and modulo
  32-bit subtraction, including signed boundary values
- [`scripts/tests/test_sio_player_event_dispatch_host.py`](../scripts/tests/test_sio_player_event_dispatch_host.py):
  checks all 256 event low bytes, four players and four high-byte values,
  including untouched regions and exactly-once event dispatch
- [`scripts/tests/test_sio_multiboot_task_start_host.py`](../scripts/tests/test_sio_multiboot_task_start_host.py):
  extracts the actual task constructor and tests 16,384 combinations
  of initial flags and the five creation arguments

**Local execution evidence (separate compact C mirrors):** GCC with
`-O2 -Wall -Wextra -Werror -fwrapv -fsanitize=undefined` passed
**132,736 mixed handshake/queue/entity-event calls** and **16,384
task-start flag combinations**. Their mirror implementations also
compiled to ARMv4T/Thumb ELF objects with Clang. These checks are
**not** substitutes for running the committed extraction tests
or for matching compiler verification; the latter two are pending.

## Current count and binary matching

After these seven functions, `src/sio_stuff_x.c` contains **87/168**
nonempty `NONMATCH` source C implementations. **81** still have empty
C bodies.

The default GBA build continues to use the original `asm/*.inc`
fallbacks for these functions. No ARM agbcc build or `make compare`
is known to have succeeded in this iteration. Therefore no new binary
matching percentage or game-ROM SHA-1 is claimed; the last historical
~77.97% matched estimate remains provisional.

The private game ROM was not uploaded to GitHub.
