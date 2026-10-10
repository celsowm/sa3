#include "global.h"
#include "core.h"
#include "malloc_vram.h"
#include "lib/m4a/m4a.h"
#include "game/stage.h" // gStageData
#include "game/shared/stage/camera.h"
#include "game/shared/stage/player.h"
#include "game/shared/stage/player_callbacks.h"
#include "game/sa3/bosses/eggman_escape.h" // SetFixedRandomIfTimeAttackMode

/* STRUCT:ExtraBoss BEGIN */
typedef struct {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u8 filler2[0x2];
    /* 0x004 */ s16 unk4;
    /* 0x006 */ u16 unk6;
    /* 0x008 */ s16 unk8;
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 fillerB[0x1];
    /* 0x00C */ u8 unkC;
    /* 0x00D */ u8 unkD;
    /* 0x00E */ u8 fillerE[0x2];
    /* 0x010 */ s16 unk10;
    /* 0x012 */ u16 unk12;
    /* 0x014 */ u8 filler14[0x3];
    /* 0x017 */ u8 unk17;
    /* 0x018 */ s32 unk18;
    /* 0x01C */ void *tiles1C;
    /* 0x020 */ void *tiles20;
    /* 0x024 */ void *tiles24;
    /* 0x028 */ Player *p28;
    /* 0x02C */ Player *p2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ u8 filler34[0x24];
    /* 0x058 */ PlayerUnk148_A unk58;
    /* 0x068 */ u8 unk68[4];
    /* 0x06C */ void *tiles6C;
    /* 0x070 */ u32 unk70;
    /* 0x074 */ void *tiles74;
    /* 0x078 */ u8 filler78[0x2C];
    /* 0x0A4 */ s32 unkA4;
    /* 0x0A8 */ s32 unkA8;
    /* 0x0AC */ u8 fillerAC[0x4];
    /* 0x0B0 */ s32 unkB0;
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ u8 fillerB8[0x35];
    /* 0x0ED */ u8 unkED;
    /* 0x0EE */ u8 fillerEE[0x1];
    /* 0x0EF */ s8 unkEF;
    /* 0x0F0 */ u8 fillerF0[0x29C];
    /* 0x38C */ Sprite s38C;
    /* 0x3B4 */ Sprite s3B4[4];
    /* 0x454 */ Sprite s454;
    /* 0x47C */ u8 filler47C[0x398];
    /* 0x814 */ Sprite s814;
    /* 0x83C */ u8 filler83C[0x3C];
} ExtraBoss; /* 0x878 */
/* STRUCT:ExtraBoss END */

void Task_878_2_8081E74(void);
void TaskDestructor_878_8081D64(struct Task *t);
void Task_878_2_8086FA4(void);
void TaskDestructor_878_2_8086ED8(struct Task *t);
void sub_8081FBC(ExtraBoss *boss);
void sub_80824F4(ExtraBoss *boss);
void sub_8082A4C(ExtraBoss *boss);
void sub_80853D8(ExtraBoss *boss);
void sub_8086F08(void);
void sub_8086F48(void);
void sub_808211C(ExtraBoss *boss);
void sub_8082388(ExtraBoss *boss);
void sub_8082428(ExtraBoss *boss);
void sub_8082794(ExtraBoss *boss);
void sub_8082D08(ExtraBoss *boss);
void sub_80862D8(ExtraBoss *boss);
void sub_8084EB4(ExtraBoss *boss);
void sub_8081EFC(ExtraBoss *boss);
void sub_8087174(ExtraBoss *boss);

extern void (*const gUnknown_08E2ED50[])(ExtraBoss *);
extern const u16 gUnknown_080D5D0C[][2];
extern const u8 gUnknown_080D5D18[];

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8081C80.inc", void sub_8081C80(void))
{
    struct Task *t = TaskCreate(Task_878_2_8081E74, sizeof(ExtraBoss), 0x3100, 0, TaskDestructor_878_8081D64);
    ExtraBoss *boss = TASK_DATA(t);

    gStageData.taskBoss = t;

    if (gStageData.difficulty == 0) {
        boss->unk0 = 12;
    } else {
        boss->unk0 = 10;
    }

    boss->unk10 = 1;
    boss->unk12 = 0;
    boss->unk4 = 1;
    boss->unk8 = 0;
    boss->unk1 = 0;
    boss->unkA = 0;
    boss->unkC = 0;
    boss->unkD = 0;
    boss->tiles6C = 0;
    boss->unk17 = 0;
    boss->unk18 = 0;
    gBgScrollRegs[0][0] = 104;
    gBgScrollRegs[0][1] = 48;
    gCamera.SA2_LABEL(unk50) |= 1;
    boss->s38C.tiles = NULL;
    boss->s3B4[0].tiles = NULL;
    boss->s454.tiles = NULL;
    boss->s814.tiles = NULL;
    boss->tiles1C = NULL;
    boss->tiles20 = NULL;
    boss->tiles24 = NULL;
    boss->tiles6C = NULL;
    boss->tiles74 = NULL;
    SetFixedRandomIfTimeAttackMode();
    boss->p28 = &gPlayers[PLAYER_1];
    boss->p2C = &gPlayers[PLAYER_2];
    gPlayers[PLAYER_1].unk148.ptr = (PlayerUnk148 *)&boss->unk58;
    boss->p2C->unk148.ptr = (PlayerUnk148 *)&boss->unk68;
    boss->unk70 = 0;
    sub_80853D8(boss);
}
END_NONMATCH

void TaskDestructor_878_8081D64(struct Task *t)
{
    ExtraBoss *boss = TASK_DATA(t);

    if (boss->s38C.tiles != NULL) {
        VramFree(boss->s38C.tiles);
    }
    if (boss->s3B4[0].tiles != NULL) {
        VramFree(boss->s3B4[0].tiles);
    }
    if (boss->s454.tiles != NULL) {
        VramFree(boss->s454.tiles);
    }
    if (boss->s814.tiles != NULL) {
        VramFree(boss->s814.tiles);
    }

    if (boss->unk1 != 6) {
        if (boss->tiles1C != NULL) {
            VramFree(boss->tiles1C);
        }
        if (boss->tiles20 != NULL) {
            VramFree(boss->tiles20);
        }
        if (boss->tiles24 != NULL) {
            VramFree(boss->tiles24);
        }
        if (boss->tiles6C != NULL) {
            VramFree(boss->tiles6C);
        }
        if (boss->tiles74 != NULL) {
            VramFree(boss->tiles74);
        }
    }
}

void sub_8081DF4(s32 arg0)
{
    ExtraBoss *boss = TASK_DATA(TaskCreate(Task_878_2_8086FA4, sizeof(ExtraBoss), 0x2100, 0, TaskDestructor_878_2_8086ED8));

    boss->unk30 = arg0;
    boss->unk4 = 1;
    boss->unk8 = 0;
    boss->unk1 = 6;
    boss->unkA = 0;
    boss->unkC = 0;
    boss->unkD = 0;
    boss->unk17 = 0;
    boss->unk18 = 0;
    boss->tiles6C = NULL;
    boss->p28 = &gPlayers[PLAYER_1];
    boss->p2C = &gPlayers[PLAYER_2];
    boss->s38C.tiles = NULL;
    boss->s454.tiles = NULL;
    sub_8081FBC(boss);
    sub_8082A4C(boss);
}

void Task_878_2_8081E74(void)
{
    ExtraBoss *boss = TASK_DATA(gCurTask);

    if (gStageData.unk4 == 3) {
        gDispCnt &= ~(DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        gDispCnt &= ~DISPCNT_BG0_ON;
        gCamera.SA2_LABEL(unk50) &= ~1;
        boss->unk4 = 1;
        boss->unk8 = 0;
        boss->unk6 = 60;
        sub_8081FBC(boss);
        sub_80824F4(boss);
        boss->tiles1C = VramMalloc(16);
        boss->tiles20 = VramMalloc(16);
        boss->tiles24 = NULL;
        gCurTask->main = sub_8086F08;
    }
}

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8081EFC.inc", void sub_8081EFC(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8081FBC.inc", void sub_8081FBC(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_808211C.inc", void sub_808211C(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8082388.inc", void sub_8082388(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8082428.inc", void sub_8082428(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80824F4.inc", void sub_80824F4(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8082794.inc", void sub_8082794(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8082A4C.inc", void sub_8082A4C(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8082D08.inc", void sub_8082D08(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8082E2C.inc", void sub_8082E2C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8083A44.inc", void sub_8083A44(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8083BE4.inc", void sub_8083BE4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8083F8C.inc", void sub_8083F8C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_808439C.inc", void sub_808439C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_808491C.inc", void sub_808491C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8084B2C.inc", void sub_8084B2C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8084BEC.inc", void sub_8084BEC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8084C50.inc", void sub_8084C50(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8084EB4.inc", void sub_8084EB4(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80851FC.inc", void sub_80851FC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80853D8.inc", void sub_80853D8(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8085458.inc", void sub_8085458(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80854B8.inc", void sub_80854B8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8085588.inc", void sub_8085588(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8085618.inc", void sub_8085618(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80856DC.inc", void sub_80856DC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8085784.inc", void sub_8085784(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_808587C.inc", void sub_808587C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80862D8.inc", void sub_80862D8(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80863FC.inc", void sub_80863FC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80865B0.inc", void sub_80865B0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8086774.inc", void sub_8086774(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80867FC.inc", void sub_80867FC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8086A40.inc", void sub_8086A40(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__Task_50_8086B94.inc", void Task_50_8086B94(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8086D64.inc", void sub_8086D64(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__Task_38_8086E58.inc", void Task_38_8086E58(void))
{
}
END_NONMATCH

void TaskDestructor_878_2_8086ED8(struct Task *t)
{
    ExtraBoss *boss = TASK_DATA(t);

    if (boss->s38C.tiles != NULL) {
        VramFree(boss->s38C.tiles);
    }
    if (boss->s454.tiles != NULL) {
        VramFree(boss->s454.tiles);
    }
}

void sub_8086F08(void)
{
    ExtraBoss *boss = TASK_DATA(gCurTask);

    m4aSongNumStart(575);
    sub_808211C(boss);
    sub_8082388(boss);
    sub_8082794(boss);
    gCurTask->main = sub_8086F48;
}

void sub_8086F48(void)
{
    ExtraBoss *boss = TASK_DATA(gCurTask);

    sub_8087174(boss);
    sub_808211C(boss);
    gUnknown_08E2ED50[boss->unk1](boss);
    sub_80862D8(boss);
    sub_8084EB4(boss);
    sub_8082428(boss);
    sub_8082388(boss);
    sub_8082794(boss);
    sub_8081EFC(boss);
}

void Task_878_2_8086FA4(void)
{
    ExtraBoss *boss = TASK_DATA(gCurTask);

    sub_808211C(boss);
    gUnknown_08E2ED50[boss->unk1](boss);
    sub_8082388(boss);
    sub_8082D08(boss);
}

void sub_8086FE4(void)
{
    TaskDestroy(gCurTask);
}

void sub_8086FF8(ExtraBoss *boss, u8 arg1)
{
    boss->unkED = arg1;

    switch (boss->unkED) {
        case 7:
            boss->unkB0 = Q(120);
            boss->unkB4 = 0;
            break;
        case 8:
            boss->unkA4 = -Q(2);
            boss->unkA8 = -Q(1);
            break;
    }
}

void sub_8087038(ExtraBoss *boss, s8 arg1)
{
    boss->unkEF = arg1;
}

void sub_8087040(void)
{
}

void sub_8087044(ExtraBoss *boss, u8 arg1)
{
    Sprite *s = &boss->s814;
    s->anim = gUnknown_080D5D0C[arg1][0];
    s->variant = gUnknown_080D5D0C[arg1][1];
    s->prevVariant = -1;
}

void sub_808706C(ExtraBoss *boss, u8 arg1)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(boss->s3B4); i++) {
        Sprite *s = &boss->s3B4[i];
        if (arg1 == 0) {
            s->anim = 1278;
            s->variant = 1;
        } else {
            s->anim = 1278;
            s->variant = 0;
        }
    }
}

void TaskDestructor_50_80870AC(struct Task *t)
{
}

void sub_80870B0(ExtraBoss *boss)
{
    boss->unk1 = gUnknown_080D5D18[boss->unkA];
    if (++boss->unkA > 4) {
        boss->unkA = 0;
    }
    boss->unk4 = 1;
    boss->unk8 = 0;
}

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80870E0.inc", void sub_80870E0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80870E4.inc", void sub_80870E4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8087140.inc", void sub_8087140(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8087174.inc", void sub_8087174(ExtraBoss *boss))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_808717C.inc", void sub_808717C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8087188.inc", void sub_8087188(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_80871CC.inc", void sub_80871CC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__TaskDestructor_38_8087234.inc", void TaskDestructor_38_8087234(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8087238.inc", void sub_8087238(void))
{
}
END_NONMATCH
