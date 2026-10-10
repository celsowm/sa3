#include "global.h"
#include "core.h"
#include "malloc_vram.h"
#include "lib/m4a/m4a.h"
#include "game/stage.h" // gStageData
#include "game/shared/stage/camera.h"
#include "game/shared/stage/player.h"
#include "game/shared/stage/player_callbacks.h"
#include "constants/move_states.h"
#include "game/sa3/bosses/eggman_escape.h" // SetFixedRandomIfTimeAttackMode

typedef struct {
    /* 0x00 */ s32 qX;
    /* 0x04 */ s32 qY;
    /* 0x08 */ u8 unk8[0x10];
} ExtraBossPart; /* 0x18 */

/* STRUCT:ExtraBoss BEGIN */
typedef struct {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u8 filler2[0x2];
    /* 0x004 */ s16 unk4;
    /* 0x006 */ s16 unk6;
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
    /* 0x034 */ u32 unk34;
    /* 0x038 */ u8 filler38[0x4];
    /* 0x03C */ s8 unk3C;
    /* 0x03D */ s8 unk3D;
    /* 0x03E */ s8 unk3E;
    /* 0x03F */ s8 unk3F;
    /* 0x040 */ u8 filler40[0x8];
    /* 0x048 */ s32 unk48;
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ u8 filler50[0x8];
    /* 0x058 */ u8 unk58[7];
    /* 0x05F */ u8 unk5F;
    /* 0x060 */ u8 filler60[0x8];
    /* 0x068 */ u8 unk68[4];
    /* 0x06C */ void *tiles6C;
    /* 0x070 */ u32 unk70;
    /* 0x074 */ void *tiles74;
    /* 0x078 */ u8 filler78[0x24];
    /* 0x09C */ s32 qX;
    /* 0x0A0 */ s32 qY;
    /* 0x0A4 */ s32 unkA4;
    /* 0x0A8 */ s32 unkA8;
    /* 0x0AC */ u8 fillerAC[0x4];
    /* 0x0B0 */ s32 unkB0;
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ u16 unkB8;
    /* 0x0BA */ u8 fillerBA[0x33];
    /* 0x0ED */ u8 unkED;
    /* 0x0EE */ u8 unkEE;
    /* 0x0EF */ u8 unkEF;
    /* 0x0F0 */ s16 unkF0;
    /* 0x0F2 */ u8 fillerF2[0x2];
    /* 0x0F4 */ s32 unkF4;
    /* 0x0F8 */ s32 unkF8;
    /* 0x0FC */ s32 unkFC;
    /* 0x100 */ u8 filler100[0x8];
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 filler109[0x3];
    /* 0x10C */ ExtraBossPart parts[4];
    /* 0x16C */ u8 filler16C[0x220];
    /* 0x38C */ Sprite s38C;
    /* 0x3B4 */ Sprite s3B4[4];
    /* 0x454 */ Sprite s454;
    /* 0x47C */ u8 filler47C[0x398];
    /* 0x814 */ Sprite s814;
    /* 0x83C */ SpriteTransform tf83C;
    /* 0x848 */ u8 filler848[0x30];
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
void sub_8086FF8(ExtraBoss *boss, u8 arg1);

extern void (*const gUnknown_08E2ED50[])(ExtraBoss *);
extern const u16 gUnknown_080D5D0C[][2];
extern const u8 gUnknown_080D5D18[];
extern bool32 sub_8010184(Sprite *s, s32 offsetX, s32 offsetY, s16 hbIndex, Player *p);

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
    gPlayers[PLAYER_1].unk148.ptr = (PlayerUnk148 *)boss->unk58;
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
    Player *p;

    if (gStageData.rings == 0) {
        if (gStageData.unk4 != 7) {
            p = boss->p28;
            if (!(p->moveState & MOVESTATE_DEAD)) {
                SetPlayerCallback(p, sub_80105F0);
            }

            p = boss->p2C;
            if (!(p->moveState & MOVESTATE_DEAD)) {
                SetPlayerCallback(p, sub_80105F0);
            }
        }

        if (boss->unk5F == 1) {
            boss->unk5F++;
            boss->unk4 = 1;
            boss->unk8 = 0;
            boss->unk1 = 7;
            boss->unkD = boss->unkC;
        }
    } else if (boss->unk0 != 0) {
        if (gStageData.unk4 == 7) {
            boss->unk1 = gStageData.unk4;
            return;
        }

        p = boss->p28;
        if (!(p->moveState & MOVESTATE_DEAD)) {
            if (--boss->unk6 == 0) {
                boss->unk6 = 60;
                if (--gStageData.rings == 0) {
                    SetPlayerCallback(p, sub_80105F0);
                    SetPlayerCallback(boss->p2C, sub_80105F0);
                }
            }
        }
    }
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8081FBC.inc", void sub_8081FBC(ExtraBoss *boss))
{
    Sprite *s;
    SpriteTransform *tf;

    if (boss->unk1 != 6) {
        boss->qX = Q(gCamera.x + 200);
        boss->qY = Q(120);
        boss->unkF4 = Q(gCamera.x + 120);
        boss->unkF8 = Q(120);
        boss->unkB0 = Q(120);
        boss->unkB4 = 0;
        boss->unk108 = 1;
    } else {
        s32 x = Q(gCamera.x + 120);
        s32 y;
        boss->qX = x;
        y = Q(gCamera.y + 80);
        boss->qY = y;
        boss->unkF4 = x;
        boss->unkF8 = y;
        boss->unkB0 = 0;
        boss->unkB4 = 0;
        boss->unk108 = 2;
    }

    boss->unkFC = 0;
    boss->unkB8 = 0;
    boss->unkA4 = Q(4);
    boss->unkEE = 0;
    boss->unkEF = 0;
    boss->unkF0 = 0;
    sub_8086FF8(boss, 0);

    s = &boss->s38C;
    tf = &boss->tf83C;
    s->tiles = VramMalloc(128);
    s->anim = 1277;
    s->variant = 0;
    s->oamFlags = SPRITE_OAM_ORDER(10);
    s->animCursor = 0;
    s->qAnimDelay = 0;
    s->prevVariant = -1;
    s->animSpeed = SPRITE_ANIM_SPEED(1.0);
    s->palId = 0;
    s->hitboxes[0].index = -1;
    s->frameFlags = 0x1000;

    if (boss->unk1 != 6) {
        s->frameFlags |= 0x2A;
    }

    s->x = I(boss->qX) - gCamera.x;
    s->y = I(boss->qY) - gCamera.y;
    tf->rotation = boss->unkB8;
    tf->x = s->x;
    tf->y = s->y;
    tf->qScaleX = Q(1);
    tf->qScaleY = Q(1);
    UpdateSpriteAnimation(s);
}
END_NONMATCH

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_808211C.inc", void sub_808211C(ExtraBoss *boss))
{
}
END_NONMATCH

void sub_8082388(ExtraBoss *boss)
{
    Sprite *s = &boss->s38C;
    SpriteTransform *tf = &boss->tf83C;

    switch (boss->unk108) {
        case 1:
            s->x = I(boss->qX) - gCamera.x;
            s->y = I(boss->qY) - gCamera.y;
            tf->rotation = boss->unkB8;
            tf->x = s->x;
            tf->y = s->y;
            TransformSprite(s, tf);
            UpdateSpriteAnimation(s);
            DisplaySprite(s);
            break;

        case 2:
            s->x = I(boss->qX) - gCamera.x;
            s->y = I(boss->qY) - gCamera.y;
            UpdateSpriteAnimation(s);
            DisplaySprite(s);
            break;
    }
}

NONMATCH("asm/non_matching/game/bosses/boss_extra__sub_8082428.inc", void sub_8082428(ExtraBoss *boss))
{
    Sprite *s = &boss->s38C;

    switch (boss->unkEF) {
        case 50:
            boss->unkF0 = 6;
            s->anim = 1277;
            s->variant = 1;
            boss->unkEF++;
            break;

        case 51:
            if (--boss->unkF0 == 0) {
                s->anim = 1277;
                s->variant = 2;
                boss->unkEF++;
            }
            break;

        case 52:
            break;

        case 100:
            boss->unkF0 = 6;
            s->anim = 1277;
            s->variant = 1;
            boss->unkEF++;
            break;

        case 101:
            if (--boss->unkF0 == 0) {
                s->anim = 1277;
                s->variant = 0;
                boss->unkEF++;
            }
            break;

        case 102:
            boss->unkEF = 0;
            break;

        case 150:
            boss->unk108 = 2;
            s->anim = 1287;
            s->variant = 0;
            s->oamFlags = SPRITE_OAM_ORDER(19);
            s->frameFlags = 0x1000;
            boss->unkEF++;
            break;
    }
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

void sub_80870E4(u16 value)
{
    if (gBgOffsetsHBlankPrimary == gBgOffsetsBuffer) {
        DmaFill16(3, value, gBgOffsetsBuffer[0], sizeof(gBgOffsetsBuffer[0]));
    } else {
        DmaFill16(3, value, gBgOffsetsBuffer[1], sizeof(gBgOffsetsBuffer[1]));
    }
}

void sub_8087140(u16 value, u8 start, u8 end)
{
    u16 *offsets = gBgOffsetsHBlankPrimary;

    for (offsets += start; start < end; start++) {
        *offsets++ = value;
    }
}

void sub_8087174(ExtraBoss *boss)
{
    boss->unk34 = 0;
}

void sub_808717C(ExtraBoss *boss)
{
    boss->unk34 |= 1;
}

void sub_8087188(ExtraBoss *boss, s16 width, s16 arg2, u16 height)
{
    s32 halfWidth;

    boss->unk34 |= 2;
    halfWidth = width / 2;
    boss->unk48 = halfWidth;
    boss->unk4C = arg2;
    boss->unk3C = -halfWidth;
    boss->unk3D = -height;
    boss->unk3E = halfWidth;
    boss->unk3F = height;
}

u8 sub_80871CC(ExtraBoss *boss, Player *p)
{
    u8 result = 0;
    u8 i;

    for (i = 0; i < ARRAY_COUNT(boss->s3B4); i++) {
        if (sub_8010184(&boss->s3B4[i], I(boss->parts[i].qX), I(boss->parts[i].qY), 0, p) == TRUE) {
            result = 1;
            break;
        }
    }

    return result;
}

void TaskDestructor_38_8087234(struct Task *t)
{
}

void sub_8087238(void)
{
}
