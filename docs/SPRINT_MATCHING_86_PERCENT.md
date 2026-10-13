# SA3 — Campanha de +5 pontos percentuais de matching (86,42%)

**Data:** 2026-10-13  
**Fork:** `celsowm/sa3`, `main`  
**Baseline funcional:** commit `16d24bd77248d703c7e00ebc46bb58844f59c615`  
**ROM-alvo:** Sonic Advance 3 Europe rev-0 (`B3SP`), SHA-1 `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.  
**Compilador:** SAT-R/agbcc `57a5b3e21157ffa5490deebfa4d6dcf0b3052d28`, binutils ARM.  
**Condição principal:** nenhum avanço conta sem `make compare` e `sha1sum -c sa3.sha1` aprovados.

> Este é o **plano de execução atualizado e quantitativo**. O histórico em
> [PLAN_PLUS_5_PERCENT.md](PLAN_PLUS_5_PERCENT.md) documenta campanhas
> anteriores e não deve ser confundido com o novo baseline. Os alvos de
> crescimento abaixo são **metas, não resultados já obtidos**.

## 1. Baseline medido com agbcc real, após o merge upstream

O build Linux offline já gerou uma ROM exatamente igual à europeia,
após o conserto de referências a símbolos renomeados no multiplayer.

| Métrica oficial (`scripts/progress.py`) | Bytes | Percentual |
|---|---:|---:|
| Código total | 816.408 | 100% |
| Código decompilado | 811.872 | 99,4444% |
| **Código matched** | **664.656** | **81,4122%** |
| Código ainda não matched | 151.752 | 18,5878% |
| Dados analisados | 4.930.806 de 14.011.012 | 35,1924% |

`+5,00` pontos percentuais requer `ceil(816408 * 0,05) = 40.821`
**bytes matched adicionais**, perfazendo 705.477 bytes (86,4123%).
Para apresentar **86,42%** com duas casas sem arredondamento enganoso,
adotamos a meta operacional ligeiramente mais alta:

- **mínimo operacional de fechamento: 705.540 bytes matched**, ou **+40.884 bytes**;
- nenhuma mudança na classificação do progresso apenas para inflar o indicador;
- código decompilado, código matched e dados analisados seguem contabilidades diferentes.

### Trilha de marcos obrigatórios

| Marco | Mínimo matched acumulado | Crescimento cumulativo | Percentual aproximado |
|---|---:|---:|---:|
| Baseline | 664.656 | 0 | 81,4122% |
| M1 | 672.821 | +8.165 | 82,4124% |
| M2 | 680.985 | +16.329 | 83,4123% |
| M3 | 689.149 | +24.493 | 84,4123% |
| M4 | 697.313 | +32.657 | 85,4123% |
| **M5 (entrega)** | **705.540** | **+40.884** | **86,4200%** |

Cada marco só fica verde após compilação completa, ROM SHA idêntico e
relatório `progress.py -m` arquivado no commit.

## 2. Inventário de bytes efetivos: há margem para chegar à meta

Os valores foram extraídos do **ELF gerado pelo agbcc**, usando tamanhos
`FUNC` de `arm-none-eabi-readelf -sW sa3.elf`, e associados a
`docs/nonmatch_triage.csv`. Isto mede **tamanho de código por símbolo**,
não caracteres de Assembly ou linhas de C.

- 418 linhas no ranking `NONMATCH` disponível.
- 417 símbolos recuperados no ELF, somando 147.232 bytes de funções.
- `sub_8097E5C` não apareceu com esse nome na tabela de símbolos; deve ser
  reconciliado antes de usá-lo num orçamento. Não inventar tamanho.
- O ranking de *edits* é anterior à última mesclagem: serve para triagem,
  não é prova de que o candidato já bate.
- Tamanhos e classificação do ELF devem ser **recalculados** após cada marco,
  pois outros agrupamentos e alinhamentos podem mudar.

### Reservatórios por esforço de matching

| Grupo | Faixa de edits no ranking antigo | Funções | Bytes de função no ELF |
|---|---|---:|---:|
| Gameplay: quase pronto | 0–10 | 40 | **16.092** |
| Gameplay: pequeno/médio | 11–35 | 46 | **10.884** |
| Gameplay: médio | 36–75 | 63 | **17.296** |
| Gameplay: difícil mas abordável | 76–150 | 48 | **16.552** |
| **Subtotal gameplay, 0–150 edits** | | **197** | **60.824** |
| Gameplay difícil (>150 edits) | >150 | 71 | 58.688 |
| SIO/multiplayer | todas as faixas | 137 | 21.872 |
| Matemática | todas as faixas | 13 | 5.848 |

Para alcançar 40.884 bytes a partir dos 60.824 bytes de gameplay
em até 150 edits, seria necessário **67,22% de aproveitamento**. É uma
campanha ambiciosa, mas com margem para descartar candidatos difíceis.
SIO, matemática e funções com >150 edits são a **segunda linha de reserva**;
não precisam ser a primeira aposta.

Importante: os 147.232 bytes são um inventário de funções identificadas,
**não** a mesma coisa que os 151.752 bytes da métrica `progress.py`,
que também considera outras unidades e classificações do linker.

## 3. Ordem de ataque por retorno em bytes e risco de regressão

| Prioridade | Função / bloco | Bytes ELF | Edits anteriores | Por que atacar |
|---|---|---:|---:|---|
| A1 | `Task_802F368` + `Task_802F698` | **1.628** | 1 + 1 | Mesmo `platform.c`, diferença localizada entre reload da pilha e cópia de `r7` |
| A2 | `EngineInit` | **1.776** | 5 | Muito código já quase correspondente |
| A3 | `Task_RingsMgrStage` | **2.276** | 7 | Maior retorno imediato em bytes |
| A4 | `Task_8039230` (grind rail) | 776 | 8 | Interactable isolável |
| A5 | `sub_809BA58` (`code_2.c`) | 1.252 | 16 | Tamanho compensa esforço |
| B1 | `Task_DeathCrusher` | 728 | 16 | Entidade com valor intermediário |
| B2 | `sub_808211C` (extra boss) | 620 | 20 | Função média com C existente |
| B3 | `sub_8076DD4` (boss 7) | 928 | 39 | Bom retorno entre candidatos de dificuldade média |
| B4 | `Task_80B6D78` (special stage) | 764 | 41 | Parte maior da máquina de estados |
| C1 | `sub_8031C10` (rampa) | 1.100 | 77 | Uma função de alto rendimento |
| C2 | `sub_8021A64` (stage UI) | 1.156 | 87 | Alto rendimento, maior risco de dependência |
| C3 | `sub_8091E84` (name entry) | 1.008 | 126 | Reserva de grande tamanho |

**As quatro primeiras rotinas (plataformas + engine + rings) oferecem
5.680 bytes potenciais**, ou cerca de 0,696 ponto percentual, se todas
forem efetivamente promovidas e validadas. Isso não basta para 5 pp:
a campanha precisa prosseguir por centenas de outras rotinas menores ou
várias médias, sem ficar presa a uma função difícil.

### Detalhes técnicos da primeira intervenção

`Task_802F368` e `Task_802F698` apresentam cada uma o mesmo tipo de
diferença apontada por `--show -v`: o target faz
`ldr r0, [sp, #4]`, enquanto o C emite `adds r0, r7, #0`.
Investigar **vida útil de `shared`**, segunda referência a
`TASK_DATA(gCurTask)`, escopo, spill/reload e ordem das declarações.
Compilar variações com o agbcc original e examinar os dois diffs;
não aceitar código apenas semanticamente semelhante.

Quando a promoção de uma delas alterar a alocação de registradores
da outra, experimentar **promover o par junto** e exigir ROM idêntica.
Se não resolver, preservar os fallbacks e saltar para A2/A3. O
primeiro par não deve travar o restante da campanha.

## 4. Cinco ondas, com metas por bytes aprovados (não por commits)

1. **Onda 1 — 82,41%:** tentar inicialmente o pool gameplay 0–10 edits
   (16.092 bytes disponíveis), na ordem plataformas, `EngineInit`,
   `Task_RingsMgrStage`, grind rail, Omochao, boss 7, enemies e
   outros leafs. Continuar até alcançar 672.821 bytes matched
   ou registrar explicitamente os impedimentos.
2. **Onda 2 — 83,41%:** aproveitar sobras da onda 1 e funções com
   11–35 edits (10.884 bytes), incluindo `sub_809BA58`,
   `Task_DeathCrusher` e `sub_808211C`. Agrupar funções que
   usam as mesmas structs e dependem da ordenação em uma mesma unidade C.
3. **Onda 3 — 84,41%:** expandir para gameplay com 36–75 edits
   (17.296 bytes), priorizando boss 2, boss 7, inimigos, objetos e
   special stage; revisar signedness, fixed-point, layout de tasks,
   chamadas indiretas e regalloc.
4. **Onda 4 — 85,41%:** avançar para o pool 76–150 edits
   (16.552 bytes), selecionando as de maior retorno por alteração
   validada, especialmente rampa, stage UI, name entry e tarefas grandes.
   Reavaliar dependências antes de alterações de structs globais.
5. **Onda 5 — ≥86,42%:** preencher o saldo até **705.540 bytes**:
   candidatos restantes das quatro ondas, depois funções de baixo risco
   de SIO/matemática somente com testes restabelecidos, ou rotinas
   gameplay de >150 edits previamente identificadas por payoff.
   Não forçar promotions nem mudar o denominador para alcançar a meta.

Uma onda é uma **fila de trabalho**, não uma promessa de que todos os
candidatos irão bater. Os pools são sobrepostos apenas pelas sobras
transferidas, nunca se soma o mesmo símbolo duas vezes.

## 5. Ciclo de matching exato para cada batch

```bash
# 0. Precondições: EU baserom privado, agbcc pinado, binutils e build limpo
python3 scripts/matching_preflight.py --rom baserom_sa3.gba --build
make -j"$(nproc)" compare
sha1sum -c sa3.sha1
python3 scripts/progress.py text -m

# 1. Compare as instruções originais com as compiladas em C
python3 scripts/nonmatch_triage.py --show Task_802F368 -v
python3 scripts/nonmatch_triage.py --show Task_802F698 -v

# 2. Experimentos são feitos sem commitar fallbacks removidos prematuramente.
# Ajuste C, recompile; somente se houver matching inspecione a promoção.
python3 scripts/nonmatch_triage.py --promote FUNC

# 3. A promoção só fica se a ROM completa continuar exatamente igual.
make -j"$(nproc)" compare
sha1sum -c sa3.sha1
python3 scripts/progress.py text -m
python3 -m unittest discover -s scripts/tests -v
```

Registrar para cada batch: SHA pai, símbolos tocados, ELF address/size,
edits antes/depois, bytes matched antes/depois, resultado do SHA-1,
eventuais mudanças em `ldscript.txt`, status do CI e testes de gameplay.
Reverter a promoção que quebrar matching; fazer commits pequenos
**diretamente na `main` do fork somente depois da verificação**.

### Validações e pendências paralelas

- **Build oracle passou** no ambiente offline com a ROM correta.
- O CI público tem **oito falhas históricas em testes SIO** que não localizam
  os corpos C esperados. Investigar se os testes extraem o código-fonte
  errado ou se há C ausente; **não desabilitar testes para fingir sucesso**.
  SIO fica em reserva até o diagnóstico.
- `make check_format` também sinalizou diferenças preexistentes em muitos
  arquivos. Corrigir ou isolar o formato das linhas efetivamente alteradas
  sem reformatar o jogo inteiro e perturbar matching.
- `docs/nonmatch_triage.csv` deve ser regenerado com o agbcc
  pinado depois do merge; os edits acima são um ponto de partida histórico,
  não um ranking atualizado automaticamente.
- A referência europeia deve permanecer **local/privada**, jamais publicada
  no GitHub ou embutida nos artefatos de CI.
- Não enviar conteúdo produzido com IA como PR/issue ao upstream SAT-R,
  cujo projeto proíbe submissões dessa origem.

## 6. Definition of done — campanha de +5 pp

`M5` é concluído apenas quando:

- `scripts/progress.py text -m` obtiver **pelo menos 705.540 / 816.408
  bytes** matched, sem alteração oportunista na definição de matching;
- `make compare` + `sha1sum -c sa3.sha1` retornarem `sa3.gba: OK`;
- o relatório registrar ganho líquido **≥40.884 bytes**, deduplicando
  os símbolos e preservando a classificação de código;
- cada rotina promovida possuir o fallback correto substituído pelo
  C matched, sem código do jogo intencionalmente quebrado;
- resultados de testes e exceções (inclusive SIO/formatação) estiverem
  documentados honestamente; sem alegar teste verde se não rodou;
- a `main` contiver o ledger dos commits de cada onda e o resultado final.

**A campanha de +5 pp não equivale a 100% de descompilação.**
Ela leva de 81,4122% até ≥86,42% de **matching de código**;
o restante do código e dos dados segue em marcos posteriores.

## 7. Execution ledger — batch 1: platform pair (2026-10-13)

**Proof from actual pinned agbcc and local private Europe ROM (not CI claims):**

- Original cleanly reproduced baseline: **664,656 / 816,408 = 81.4122% matched**.
- In `src/game/sa3/interactables/platform.c`, both `Task_802F368` and
  `Task_802F698` originally differed by **one assembly instruction** each:
  the target loaded the task pointer using `ldr r0, [sp, #4]`, whereas the
  generated C did `adds r0, r7, #0`.
- After trying more than 10 variants of pointer aliasing and stack constraints,
  the pinned original `agbcc` produced exact normalized instruction streams
  for both when an explicit single-instruction stack reload was used with a
  register-constrained C pointer. This is a compiler/ABI-sensitive matching
  idiom; leave the explanatory comments in source.
- Both were changed from `NONMATCH` to C declarations, and their two obsolete
  fallback `.inc` files were removed.
- **Whole-ROM linker & hash test passed**:
  `make -j4 PLATFORM=gba CPU_ARCH=arm compare` → `sa3.gba: OK`;
  output SHA-1 `685af3a2dc0f1b3f8922e73ec42c1dc92e210e39`.
- Progress script on the freshly generated `sa3.map`: **666,588 / 816,408
  matched = 81.6489%**. Net improvement = **+1,932 matched bytes**
  (+0.23665 percentage points), which may include compiler/linker
  classification interactions beyond the two interval upper bounds.
- Decompiled code remains **811,872 / 816,408 = 99.4444%**.
  Data remains **4,930,806 / 14,011,012 = 35.1924%**.
- Offline unit suite ran 72 tests with 8 **pre-existing SIO failures**
  (tests expecting source bodies unavailable in the current SIO layout).
  This is not a green suite; the gameplay ROM oracle is green.

**M1 target:** 672,821 matched bytes. **Remaining to M1: 6,233 bytes.**
**M5 target:** 705,540 matched bytes. **Remaining to M5: 38,952 bytes.**

Next candidates: `EngineInit` (1,776 ELF bytes, 5 edits in older ranking),
`Task_RingsMgrStage` (2,276 bytes, 7 edits). Always validate with the pinned
agbcc and the complete European ROM, not normalized instruction score alone.


## 8. Execution ledger — batch 2: background animation (2026-10-13)

**ROM-matched C promotion:** \`UpdateBgAnimationTiles\`, source
\`src/background.c\`, old fallback
\`asm/non_matching/engine/UpdateBgAnimationTiles.inc\`.

- Previous mismatch: only two Thumb instructions in the animation branch.
  The reference uses \`mov r4, ip; ldr r1, [r4, #4]\`; the C fallback
  candidate used \`mov r0, ip; ldr r1, [r0, #4]\`.
- Solution: keep the original C implementation, with an SA3-only
  \`r1\`-bound pointer output from a two-instruction inline ASM fragment
  selecting the original \`r4\` base. Use the existing expression for
  SA1/SA2 instead of changing those engines' register allocation.
- Tested multiple alternatives with the pinned original agbcc. The
  reconstructed C produced **0 normalized instruction edits**.
- Removed the obsolete fallback and rebuilt the **full private European
  ROM** with \`make -j4 compare\`; \`sa3.gba: OK\`, and a separate
  \`sha1sum -c sa3.sha1\` also passed.
- Official \`scripts/progress.py text -m\` algorithm on the new
  \`sa3.map\`: **666,780 / 816,408 = 81.6724% matched**.
  Previous batch: 666,588; **net +192 bytes** (+0.02352 pp).
- Total gain since the verified baseline: **+2,124 matched bytes**.
  The decompiled fraction remains 811,872 / 816,408 = 99.4444%.
- In the offline environment without GitPython, the unused import
  \`git\` was stubbed only at runtime for the text-mode reporter;
  the map parser was run unchanged.

**Remaining:** M1 (672,821) needs **6,041 bytes**, and M5
(705,540) needs **38,760 bytes**.

**Engineering caveat:** the single machine-instruction fragment is
intentionally assembler/compiler-specific; it is *not* a generic C
portability solution. The full ROM comparison, not the triage diff,
is the acceptance gate. Keep all reference ROM bytes private.
