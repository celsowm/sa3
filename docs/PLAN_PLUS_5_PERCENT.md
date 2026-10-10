# Plano: +5 pontos percentuais de código matched

## Checkpoint adicional — 2026-10-10, SIO decompilation

**Target is matching code bytes, not merely C reconstruction.** The last
commit-reported matching figure preceding this batch was approximately
**81.1094%** (historical progress, not recalculated here). On the old
816,408-byte code denominator, another five percentage points would mean
**about 40,821 verified matching bytes** and a target near **86.11%**.
Recalculate from a fresh `sa3.map` before treating these as official numbers.

Recent direct-to-`main` work reconstructed **34 SIO functions in C** over
commits `e4d58bf`, `b26bcdb`, `993506f`, `1615b6f`, and `81a83e3`,
including the queue writer (`sub_8026AB8`), state/error handler
(`sub_8025E24`), multiplayer readiness check (`sub_802610C`) and packet
builders. These bodies remain inside `NONMATCH` with original ASM as the
default matching fallback, so **verified matching progress for this batch:
zero bytes**. One intervening commit `b3c4906` corrected the reset-helper
return declaration, and `21ad5a7` added host C smoke tests. Those tests
exercise behavior; they do not compare compiler output or the full ROM.

To obtain actual percentage gain: prioritize `EngineInit` and
`Task_RingsMgrStage` (both nearly matching in the existing triage), make
targeted C/agbcc comparisons, promote only verified matches, and require
`make compare` plus `sha1sum -c sa3.sha1` with the privately held European
reference. Do not promote this SIO batch on code inspection alone.

---

Base: `main` @ `30c9858`. **78,1590%** matched (638.096 / 816.408 bytes).
Meta: **≥ 83,16%**, ou seja, **+40.820 bytes** de código matched.

## De onde sai o ganho

`scripts/progress.py -m` só conta como matched as funções que deixam de
ser `NONMATCH`. Converter os `asm/*.s` grandes em `ASM_FUNC` não muda
esse número. Os 175 `NONMATCH` restantes somam **85.328 bytes**; a meta
exige quase metade deles.

| Edições até o alvo (triage) | Funções | Bytes |
|---|---:|---:|
| 0–5 | 15 | 5.612 |
| 6–10 | 16 | 5.632 |
| 11–20 | 15 | 5.480 |
| 21–50 | 49 | 20.068 |
| 51–100 | 30 | 13.688 |
| > 100 | 50 | 34.848 |

A seleção ordena por **edições por byte** (esforço ÷ ganho), não só por
edições: funções grandes e quase prontas, como `Task_RingsMgrStage`
(2.276 B, 39 edições) e `EngineInit` (1.776 B, 30), rendem mais que
dezenas de funções pequenas. São **84 funções em 5 ondas de ~1 ponto
cada**, mais uma reserva de 24 funções para substituir as que travarem.

## Método por função

1. `python3 scripts/nonmatch_triage.py --show FUNC` para ver o diff.
2. Ajustar o C: ordem de branches/early return, tipos e casts, variáveis
   temporárias, ordem de statements.
3. Se só sobrar alocação de registradores:
   `scripts/permuter_setup.py FUNC` + decomp-permuter, com limite de
   tempo; se não sair, a função vai para o fim da fila.
4. `--promote FUNC` e `make -j$(nproc)`; precisa terminar em
   `sa3.gba: OK`.
5. Se quebrar *outra* função do mesmo arquivo, promover junto os vizinhos
   próximos (como no `boss_2.c`) ou desfazer.
6. Um commit por função (ou por grupo do mesmo arquivo) direto na `main`,
   com o delta do `progress.py -m` na mensagem.

**Regras:** só `make compare` vale. Sem `NON_MATCHING=1` e sem
"equivalente". `make check_format` não roda (falta `clang-format-13`),
então mantenho só o estilo das linhas alteradas.

## Andamento

| Data | Matched | Observação |
|---|---:|---|
| 2026-10-10 15:53 | 78,1590% | Início (main `30c9858`) |
| 2026-10-10 17:05 | 78,6714% | +4.184 B, 16 funções |
| 2026-10-10 (noite) | 80,8831% | `opening.c` e `mp_char_select.c` decompilados a partir do asm puro |

Funções que passaram a bater: `sub_8034A20`, `sub_807AC48`, `Task_FerrisWheel`,
`Task_809947C`, `sub_80B3C28`, `sub_803D4C8`, `sub_80B7E1C`, `sub_8003BD8`,
`sub_8003CA4`, `sub_8002618`, `sa2__sub_8084EAC`, `sa2__sub_8083858`,
`sa2__sub_8083B10`, `sa2__sub_8083A48`, `sa2__sub_8084A24` (as duas últimas
copiadas do SAT-R/sa2, que já as tem em C que bate).

Também foram corrigidos erros de lógica em corpos que ainda não batem
(`Task_RingsMgrStage`, `CreateEntity_MazeCorner`, `sub_8012550`,
`sub_8097E5C`, `Task_270_809B8C8`, `Options_ButtonConfig`) e vários
outros foram aproximados.

### Mudança de estratégia: asm puro → C

Os ~89 KB restantes em `asm/*.s` (sem nenhum C ainda) rendem mais por hora
do que os `NONMATCH` antigos. `scripts/asm2nonmatch.py` converte um `.s`
inteiro num `.c` onde cada função vira um `NONMATCH` com o próprio `.inc`
(ROM idêntica). Depois cada função é escrita em C (m2c ajuda a montar as
structs) e promovida com o fluxo normal. Assim foram feitos
`asm/game__opening.s` → `src/game/sa3/cutscenes/opening.c` e
`asm/game__mp_char_select.s` → `src/game/sa3/multiplayer/mp_char_select.c`.

Cuidados aprendidos:

- `nonmatch_triage.py --show` normaliza literais: constantes erradas
  (`0xEFFF` × `0xFEFF`, `RGB_WHITE` × `0xFFFF`) só aparecem no build
  completo. Rodar sempre `make compare` antes do commit.
- O agbcc arredonda structs para múltiplo de 4 bytes: embrulhar um
  `SpriteTransform` (0xA) numa struct muda o tamanho.
- Em agbcc, `x >= N` vira `x > N-1`; quando o alvo compara com `N`
  direto, o limite vinha de uma variável (`s32 lim = 120; Q(lim)`).

### O que funcionou

- **Reescrever pelo assembly** funções pequenas/médias cujo C estava
  confuso ou errado. Muitos corpos antigos tinham remendos (`asm("")`,
  `do {} while (0)`, `volatile`) ou lógica diferente do alvo.
- **Comparar símbolos referenciados** (alvo × C) para achar erros de
  lógica: símbolo errado, `Div()` em vez de `/`, campo errado.
- **Detalhes que mudam o código gerado:** arrays 2D (`t[i][1]` gera
  base+1), acessar campos pela struct da task em vez de um ponteiro local,
  reaproveitar a mesma variável para flags e resultado, `u32` em vez de
  `u8`, rótulo comum para saídas que o compilador fundiria.
- **SAT-R/sa2** como fonte de C pronto para funções `sa2__*`.
- **m2c** (`--target gba`) para esqueletos e dicas de variáveis.

### O que rende pouco

- Diferenças só de alocação de registradores ou de slots de pilha: nem
  ajuste à mão nem decomp-permuter (10–15 min por função) resolvem com
  frequência. O permuter não enxerga slots de pilha e não lê statement
  expressions `({ ... })`.
- O ritmo observado é de ~3–4 KB por hora, bem abaixo do necessário para
  +5 pontos (40 KB) numa sessão; a meta vai precisar de várias sessões.

## Ondas

Cada onda fecha com: `make compare` OK, `progress.py -m` registrado em
`docs/DECOMP_COMPLETION_PLAN.md`, triage regenerado e push.

| Onda | Matched ao final | Perfil |
|---|---:|---|
| 1 | ~79,2% | 1–16 edições; quase todas são branch/registrador |
| 2 | ~80,1% | Inclui `EngineInit` e `Task_RingsMgrStage` (grandes, ~30–40 edições) |
| 3 | ~81,1% | 6–68 edições; entidades e bosses |
| 4 | ~82,1% | 12–87 edições; game over, UI, rampas |
| 5 | ~83,1% | 16–126 edições; name entry, special stage |

### Riscos

- **A contagem de edições é otimista.** O triage compila com *todos* os
  corpos em C. Com metade ainda em asm, uma função pode precisar dos
  vizinhos para bater (efeito `sub_806C970`). Por isso as ondas agrupam
  por arquivo sempre que der.
- **Algumas de 2 edições não saem fácil.** `Task_14_805C03C` e
  `sub_803C094` resistiram a ajuste manual e a 20 mil iterações do
  permuter. A reserva existe para isso.
- **Ondas 4–5 envolvem reescrever lógica**, não só ajustar: são 30–126
  edições por função, e o ritmo cai.
- **Cada sessão nova precisa do ROM** (upload) e de ~5 min de setup
  (agbcc + binutils).

### Onda 1: 17 funções, 8,508 B, 80 edições

| Função | Arquivo | Bytes | Edições |
|---|---|---:|---:|
| `UpdateBgAnimationTiles` | `background.c` | 192 | 2 |
| `sub_807AC48` | `game/sa3/bosses/gemerl_attacks.c` | 320 | 2 |
| `Task_809947C` | `game/sa3/character_select.c` | 516 | 5 |
| `sub_809BA58` | `game/sa3/code_2.c` | 1252 | 16 |
| `Task_14_805C03C` | `game/sa3/enemies/enemy_unknown_code.c` | 252 | 2 |
| `sub_805C890` | `game/sa3/enemies/enemy_unknown_code.c` | 736 | 4 |
| `sub_803C094` | `game/sa3/interactables/bonus_game_capsule.c` | 152 | 2 |
| `sub_804A1E0` | `game/sa3/interactables/boulder.c` | 504 | 6 |
| `CreateBreakableWallDebris` | `game/sa3/interactables/breakable_wall.c` | 356 | 4 |
| `sub_8034A20` | `game/sa3/interactables/breakable_wall.c` | 576 | 1 |
| `Task_FerrisWheel` | `game/sa3/interactables/ferris_wheel.c` | 772 | 2 |
| `CreateEntity_MazeCorner` | `game/sa3/interactables/maze.c` | 288 | 2 |
| `CreateEntity_Omochao` | `game/sa3/interactables/omochao.c` | 272 | 2 |
| `OmochaoPickUp` | `game/sa3/interactables/omochao.c` | 452 | 6 |
| `Task_802F698` | `game/sa3/interactables/platform.c` | 1116 | 15 |
| `sub_8094924` | `game/sa3/options/time_record_screen.c` | 372 | 4 |
| `Task_SuperSonic_TagActionAnimUpdate` | `game/sa3/stage/player.c` | 380 | 5 |

### Onda 2: 11 funções, 7,824 B, 137 edições

| Função | Arquivo | Bytes | Edições |
|---|---|---:|---:|
| `EngineInit` | `core.c` | 1776 | 30 |
| `sub_806C1C8` | `game/sa3/bosses/boss_2.c` | 304 | 6 |
| `Task_Platform_OuterPlat` | `game/sa3/bosses/boss_6.c` | 544 | 10 |
| `sub_8023440` | `game/sa3/chao_map.c` | 396 | 6 |
| `Task_802F368` | `game/sa3/interactables/platform.c` | 816 | 14 |
| `Task_SunsetBridge` | `game/sa3/interactables/sunset_bridge.c` | 416 | 7 |
| `Options_ButtonConfig` | `game/sa3/options/button_config.c` | 480 | 9 |
| `sub_80B8218` | `game/sa3/partner_ai.c` | 192 | 4 |
| `sub_80B29B4` | `game/sa3/special_stage.c` | 388 | 8 |
| `sub_8015C90` | `game/sa3/stage/player.c` | 236 | 4 |
| `Task_RingsMgrStage` | `game/shared/rings_manager.c` | 2276 | 39 |

### Onda 3: 17 funções, 8,340 B, 329 edições

| Função | Arquivo | Bytes | Edições |
|---|---|---:|---:|
| `sub_80BE190` | `background.c` | 732 | 21 |
| `sub_8000414` | `game/game.c` | 292 | 17 |
| `sub_8076DD4` | `game/sa3/bosses/boss_7.c` | 928 | 30 |
| `sub_807AD88` | `game/sa3/bosses/gemerl_attacks.c` | 180 | 9 |
| `Task_40_805C198` | `game/sa3/enemies/enemy_unknown_code.c` | 232 | 6 |
| `sub_8061F50` | `game/sa3/enemies/hariisen_proj.c` | 412 | 16 |
| `sub_803B6E8` | `game/sa3/interactables/bonus_game_capsule.c` | 284 | 16 |
| `sub_80358A0` | `game/sa3/interactables/dash_ring.c` | 236 | 6 |
| `Task_DeathCrusher` | `game/sa3/interactables/death_crusher.c` | 1352 | 68 |
| `Task_8039230` | `game/sa3/interactables/grind_rail.c` | 776 | 21 |
| `sub_8048044` | `game/sa3/interactables/minecart.c` | 468 | 10 |
| `Task_PlatformMaybeFalling` | `game/sa3/interactables/platform_3_falling.c` | 652 | 36 |
| `CreateEntity_TriggerBossOrGoal` | `game/sa3/interactables/trigger_boss_and_goal_ring.c` | 288 | 6 |
| `sub_808738C` | `game/sa3/main_menu.c` | 268 | 9 |
| `sub_80932E0` | `game/sa3/options/name_entry_screen.c` | 208 | 7 |
| `Task_80B6D78` | `game/sa3/special_stage.c` | 764 | 41 |
| `sub_8011BFC` | `game/sa3/stage/player.c` | 268 | 10 |

### Onda 4: 19 funções, 8,200 B, 637 edições

| Função | Arquivo | Bytes | Edições |
|---|---|---:|---:|
| `sub_8000538` | `game/game.c` | 560 | 35 |
| `sub_806C6FC` | `game/sa3/bosses/boss_2.c` | 180 | 13 |
| `sub_806CAA4` | `game/sa3/bosses/boss_2.c` | 524 | 41 |
| `sub_807ABB8` | `game/sa3/bosses/gemerl_attacks.c` | 144 | 12 |
| `Task_270_809B8C8` | `game/sa3/code_2.c` | 168 | 12 |
| `sub_805C63C` | `game/sa3/enemies/enemy_unknown_code.c` | 596 | 49 |
| `Task_8003084` | `game/sa3/game_over.c` | 324 | 30 |
| `Task_8003288` | `game/sa3/game_over.c` | 304 | 29 |
| `sub_8002618` | `game/sa3/game_over.c` | 164 | 12 |
| `Task_BigAirBubble` | `game/sa3/interactables/air_bubbles.c` | 448 | 39 |
| `sub_803D4C8` | `game/sa3/interactables/bonus_game_enemies.c` | 332 | 30 |
| `sub_8031C10` | `game/sa3/interactables/ramp.c` | 1100 | 77 |
| `CreateEntity_SunsetBridge` | `game/sa3/interactables/sunset_bridge.c` | 396 | 32 |
| `Task_TriggerBossAndGoalRingInit` | `game/sa3/interactables/trigger_boss_and_goal_ring.c` | 444 | 32 |
| `sub_80947EC` | `game/sa3/options/time_record_screen.c` | 312 | 19 |
| `sub_8011E70` | `game/sa3/stage/player.c` | 328 | 29 |
| `sub_8011FB8` | `game/sa3/stage/player.c` | 352 | 24 |
| `Task_8065FAC` | `game/stage/some_stage_manager.c` | 368 | 35 |
| `sub_8021A64` | `game/stage/stage_ui.c` | 1156 | 87 |

### Onda 5: 20 funções, 8,012 B, 1042 edições

| Função | Arquivo | Bytes | Edições |
|---|---|---:|---:|
| `sub_802AE64` | `game/gTask_03001CFC.c` | 408 | 57 |
| `sub_806C4F8` | `game/sa3/bosses/boss_2.c` | 220 | 31 |
| `CreateEggPinballOuterPlatform` | `game/sa3/bosses/boss_6.c` | 220 | 30 |
| `sub_807467C` | `game/sa3/bosses/boss_6.c` | 376 | 48 |
| `sub_807AE3C` | `game/sa3/bosses/gemerl_attacks.c` | 384 | 54 |
| `sub_805C510` | `game/sa3/enemies/enemy_unknown_code.c` | 300 | 38 |
| `CreateMuukaden` | `game/sa3/enemies/muukaden.c` | 436 | 45 |
| `sub_803B354` | `game/sa3/interactables/bonus_game_capsule.c` | 324 | 37 |
| `Task_8034E44` | `game/sa3/interactables/breakable_wall.c` | 324 | 44 |
| `Task_ClosingWall` | `game/sa3/interactables/closing_wall.c` | 592 | 86 |
| `Task_RocketMain` | `game/sa3/interactables/rocket.c` | 356 | 52 |
| `Task_8092AC8` | `game/sa3/options/name_entry_screen.c` | 512 | 58 |
| `sub_8091E84` | `game/sa3/options/name_entry_screen.c` | 1008 | 126 |
| `sub_8092F60` | `game/sa3/options/name_entry_screen.c` | 344 | 45 |
| `sub_80B3C28` | `game/sa3/special_stage.c` | 292 | 34 |
| `sub_80B7074` | `game/sa3/special_stage.c` | 672 | 97 |
| `Player_801D1D0` | `game/sa3/stage/player.c` | 300 | 42 |
| `sub_8012118` | `game/sa3/stage/player.c` | 340 | 39 |
| `Task_StageMusicManager` | `game/shared/stage/music_manager.c` | 468 | 63 |
| `sub_8050D90` | `game/stage/camera.c` | 136 | 16 |

### Reserva: 24 funções, 8,400 B, 1506 edições

| Função | Arquivo | Bytes | Edições |
|---|---|---:|---:|
| `sub_806B788` | `game/sa3/bosses/boss_2.c` | 188 | 33 |
| `Task_Boss_8073BE0` | `game/sa3/bosses/boss_6.c` | 260 | 48 |
| `Task_Boss_8073D98` | `game/sa3/bosses/boss_6.c` | 436 | 68 |
| `Task_Boss_8073F4C` | `game/sa3/bosses/boss_6.c` | 260 | 45 |
| `sub_807813C` | `game/sa3/bosses/boss_7.c` | 132 | 24 |
| `sub_807B10C` | `game/sa3/bosses/gemerl_attacks.c` | 216 | 41 |
| `sub_805E624` | `game/sa3/enemies/juggling.c` | 188 | 30 |
| `sub_803AAE8` | `game/sa3/interactables/bonus_game_capsule.c` | 592 | 118 |
| `sub_803B804` | `game/sa3/interactables/bonus_game_capsule.c` | 268 | 46 |
| `Task_8045F48` | `game/sa3/interactables/rocket.c` | 848 | 163 |
| `Task_8092A0C` | `game/sa3/options/name_entry_screen.c` | 188 | 37 |
| `sub_80B7E1C` | `game/sa3/partner_ai.c` | 228 | 43 |
| `sub_80B8FB8` | `game/sa3/partner_ai.c` | 80 | 13 |
| `sub_80B6198` | `game/sa3/special_stage.c` | 356 | 68 |
| `Player_80087CC` | `game/sa3/stage/player.c` | 336 | 57 |
| `sub_801226C` | `game/sa3/stage/player.c` | 252 | 48 |
| `sub_8012368` | `game/sa3/stage/player.c` | 260 | 48 |
| `sub_8012550` | `game/sa3/stage/player.c` | 228 | 34 |
| `sub_8015064` | `game/sa3/stage/player.c` | 224 | 43 |
| `sub_8015A44` | `game/sa3/stage/player.c` | 588 | 88 |
| `Task_EC_808DA44` | `game/sio_debug_code_maybe.c` | 500 | 86 |
| `Task_EC_808DEB8` | `game/sio_debug_code_maybe.c` | 432 | 73 |
| `sub_8050EE4` | `game/stage/camera.c` | 268 | 45 |
| `sub_8022234` | `game/stage/stage_ui.c` | 1072 | 207 |

