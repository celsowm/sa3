# SA3 post-merge build validation — October 13, 2026

The real SAT-R/agbcc compiler (SHA `57a5b3e21157ffa5490deebfa4d6dcf0b3052d28`) was built successfully by GitHub Actions run [38441209322](https://github.com/celsowm/sa3/actions/runs/38441209322), and the compiler bundle was downloaded to an offline Linux environment.

A second trusted runner packaged a git-archived copy of the public fork's source from commit `e744e7b035516eb04ceba28bc56dfa2a207ff6a1`, plus Ubuntu ARM binutils as an offline kit. **No copyrighted ROM was uploaded**. The user-supplied European rev-0 reference ROM was placed privately at `baserom_sa3.gba`, with original SHA-1 verified.

## Real clean-ish build evidence

Using Linux arm-none-eabi binutils 2.38 and pinned original agbcc, command:

```sh
make -j4 PLATFORM=gba CPU_ARCH=arm compare
sha1sum -c sa3.sha1
```

The **initial** link failed with seven unresolved relocations from the old multiplayer C inline Assembly include files, as the upstream character selection data symbols were renamed. Resolved the **four exact symbol names** inside six fallback `.inc` files:

| Original symbol | Renamed symbol |
|---|---|
| `gUnknown_080D8CDC` | `gCharSelect3_Tilemaps` |
| `gUnknown_080D8D00` | `gTileInfo_CharSelect3_HeaderBackdrop` |
| `gUnknown_080D8D08` | `gTileInfo_CharSelect3_TeamDescriptions` |
| `gUnknown_080D8E80` | `gTileInfo_CharSelect3_NameTagNames` |

Only linker-relocated **symbol names** were changed in the Assembly fallbacks; instruction bytes and control flow were left untouched. The two affected C translation units were forced to recompile in the existing build directory (`touch src/game/sa3/multiplayer/mp_char_select.c src/game/sa3/character_select.c`). A fresh checkout compiles these normally.

Subsequent local output:

```text
arm-none-eabi-ld -T ldscript.txt -Map sa3.map <objects> <lib> -o sa3.elf
arm-none-eabi-objcopy -O binary --pad-to 0x8400000 sa3.elf sa3.gba
tools/gbafix/gbafix sa3.gba ...
/usr/bin/sha1sum -c sa3.sha1
sa3.gba: OK
```

This proves **the generated full 16 MiB ROM is SHA-1-identical** to the European reference: `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.

## Source progress from rebuilt sa3.map

```text
src:     811872 /   816408 total bytes decompiled   99.4444%
src:     664656 /   816408 total bytes matched      81.4122%
data:   4930806 / 14011012 total bytes analysed   35.1924%
```

Remaining (under the current `scripts/progress.py` classification):
- 4,536 code bytes not yet decompiled.
- 151,752 code bytes not yet marked as matching.
- 9,080,206 bytes of data not marked analyzed.

For these **text-mode** measurements in the offline sandbox, the unused `git` import was stubbed at runtime because GitPython could not be installed without network access; the repository's original linker-map parser ran unmodified. In a normal build environment, install GitPython and run `python3 scripts/progress.py text -m` directly.

## Next matching step

```bash
python3 scripts/nonmatch_triage.py --show Task_802F368 -v
python3 scripts/nonmatch_triage.py --show Task_802F698 -v
```

At this exact rebuilt baseline, each has **only one** normalized instruction difference: reference `ldr r0, [sp, #4]` versus C-emitted `adds r0, r7, #0`, in the platform flag access tail. No gameplay implementation was promoted as matching from this step alone. Any attempted promotion must be followed by another full `make compare`.
