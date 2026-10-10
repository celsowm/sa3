#include "global.h"
#include "core.h"
#include "flags.h"
#include "malloc_ewram.h"
#include "lib/m4a/m4a.h"
#include "code_0_1.h"
#include "game/save.h"
#include "game/special_stage.h" // sub_808ADF0
#include "game/stage.h" // gStageData
#include "constants/songs.h"
#include "constants/tilemaps.h"

typedef struct {
    /* 0x000 */ Sprite s;
    /* 0x028 */ Sprite s2;
    /* 0x050 */ SpriteTransform transforms[2];
    /* 0x068 */ Background bg68;
    /* 0x0A8 */ Background bgA8;
    /* 0x0E8 */ Background bgE8;
    /* 0x128 */ s16 state;
    /* 0x12C */ s16 *hblankBuf;
    /* 0x130 */ u32 *recipTable;
    /* 0x134 */ s16 unk134;
    /* 0x136 */ s16 unk136;
    /* 0x138 */ u16 unk138;
    /* 0x13A */ u16 unk13A;
    /* 0x13C */ s16 unk13C;
    /* 0x13E */ s16 unk13E;
    /* 0x140 */ s16 unk140;
    /* 0x142 */ s16 unk142;
    /* 0x144 */ s16 unk144;
    /* 0x146 */ s16 unk146;
    /* 0x148 */ s16 unk148;
    /* 0x14A */ s16 unk14A;
    /* 0x14C */ s16 unk14C;
    /* 0x14E */ s16 unk14E[16];
} GameIntro; /* 0x170 */

void Task_170_GameIntroInit(void);
void Task_170_80A2A9C(void);
void sub_80A2700(void);
void sub_80A217C(GameIntro *intro);
void sub_80A22E0(GameIntro *intro);
void sub_80A23A4(void);
void sub_80A2774(void);
void sub_80A27EC(void);
void sub_80A2978(s16 arg0);
void sub_80A2A40(s16 arg0);
void sub_80A2D80(void);
void Task_80A2D34(void);
void Task_170_80A2B54(void);
void Task_170_80A2C60(void);
void sub_80A2E38(u8 arg0);
void sub_80A3F18(void);
void CreateIntroEggmanCutscene(u8 arg0);
s16 sub_80A2DD8(void);

extern ColorRaw sub_80C4C0C(ColorRaw color);
extern const u16 Palette_unknown_424[];
void TaskDestructor_GameIntro(struct Task *t);

void CreateGameIntroState(s16 state)
{
    struct Task *t = TaskCreate(Task_170_GameIntroInit, sizeof(GameIntro), 0x1000, 0, TaskDestructor_GameIntro);
    GameIntro *intro = TASK_DATA(t);

    if (state == 1 || state == 2) {
        gStageData.unk7 = 0;
    } else {
        gStageData.unk7 = 1;
    }

    intro->unk134 = -240;
    intro->unk136 = 140;
    intro->unk138 = 0;
    intro->unk13A = 0;
    intro->unk13C = 0;
    intro->unk13E = 0;
    intro->unk140 = 0;
    intro->unk142 = -48;
    intro->unk144 = 16;
    intro->unk146 = 16;
    intro->unk148 = 0;
    intro->unk14A = 0;
    intro->state = state;

    gBldRegs.bldCnt = 0xFF;
    gBldRegs.bldAlpha = 0;
    gBldRegs.bldY = 16;
}

void sub_80A217C(GameIntro *intro)
{
    Background *bg = &intro->bg68;

    gDispCnt = 0x42;
    gBgCntRegs[0] = 0x1F0C;
    gBgCntRegs[1] = 0x1708;
    gBgCntRegs[2] = 0x6B81;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;
    gBgScrollRegs[1][0] = 16;
    gBgScrollRegs[1][1] = 116;
    gBgScrollRegs[2][0] = 0;
    gBgScrollRegs[2][1] = 0;
    gBgScrollRegs[3][0] = 0;
    gBgScrollRegs[3][1] = 0;

    bg->graphics.dest = (void *)BG_CHAR_ADDR(0);
    bg->graphics.anim = 0;
    bg->layoutVram = (void *)BG_SCREEN_ADDR(11);
    bg->unk18 = 0;
    bg->unk1A = 0;
    bg->tilemapId = TM_UNKNOWN_424;
    bg->unk1E = 0;
    bg->unk20 = 0;
    bg->unk22 = 0;
    bg->unk24 = 0;
    bg->targetTilesX = 32;
    bg->targetTilesY = 32;
    intro->bg68.paletteOffset = 0;
    intro->bg68.animFrameCounter = 0;
    intro->bg68.animDelayCounter = 0;
    bg->flags = 6;
    bg->scrollX = 0;
    bg->scrollY = 0;
    DrawBackground(bg);

    if (intro->state == 3 || intro->state == 5) {
        Background *bg = &intro->bgE8;
        bg->graphics.dest = (void *)BG_CHAR_ADDR(2);
        bg->graphics.anim = 0;
        bg->layoutVram = (void *)BG_SCREEN_ADDR(23);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_423;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        intro->bgE8.paletteOffset = 0;
        intro->bgE8.animFrameCounter = 0;
        intro->bgE8.animDelayCounter = 0;
        bg->flags = 0x11;
        bg->scrollX = 0;
        bg->scrollY = 0;
        DrawBackground(bg);
    }

    if (intro->state == 1 || intro->state == 2) {
        Background *bg2 = &intro->bgA8;
        bg2->graphics.dest = (void *)BG_CHAR_ADDR(3);
        bg2->graphics.anim = 0;
        bg2->layoutVram = (void *)BG_SCREEN_ADDR(31);
        bg2->unk18 = 0;
        bg2->unk1A = 0;
        if (intro->state == 1) {
            bg2->tilemapId = TM_UNKNOWN_425;
        } else {
            bg2->tilemapId = TM_UNKNOWN_426;
        }
        bg2->unk1E = 0;
        bg2->unk20 = 0;
        bg2->unk22 = 0;
        bg2->unk24 = 0;
        bg2->targetTilesX = 32;
        bg2->targetTilesY = 32;
        bg2->paletteOffset = 0;
        bg2->animFrameCounter = 0;
        bg2->animDelayCounter = 0;
        bg2->flags = 0;
        bg2->scrollX = 0;
        bg2->scrollY = 0;
        DrawBackground(bg2);
    }
}

void sub_80A22E0(GameIntro *intro)
{
    SpriteTransform *tf = &intro->transforms[0];
    Sprite *s = &intro->s;

    s->tiles = OBJ_VRAM0;
    s->frameFlags = 0x1020;
    s->anim = 161;
    s->x = 130;
    s->y = 140;
    s->oamFlags = SPRITE_OAM_ORDER(17);
    s->qAnimDelay = 0;
    s->prevAnim = -1;
    s->variant = 3;
    s->prevVariant = -1;
    s->animSpeed = SPRITE_ANIM_SPEED(1.0);
    s->palId = 0;
    s->hitboxes[0].index = -1;
    tf->rotation = 0;
    tf->qScaleX = -224;
    tf->qScaleY = 224;
    tf->x = s->x;
    tf->y = s->y;

    s = &intro->s2;
    tf++;
    s->tiles = OBJ_VRAM0 + 0x800;
    s->frameFlags = 0x1021;
    s->anim = 487;
    s->x = 100;
    s->y = 140;
    s->oamFlags = SPRITE_OAM_ORDER(16);
    s->qAnimDelay = 0;
    s->prevAnim = -1;
    s->variant = 4;
    s->prevVariant = -1;
    s->animSpeed = SPRITE_ANIM_SPEED(1.0);
    s->palId = 1;
    s->hitboxes[0].index = -1;
    tf->rotation = 0;
    tf->qScaleX = -256;
    tf->qScaleY = 256;
    tf->x = s->x;
    tf->y = s->y;
}

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A23A4.inc", void sub_80A23A4(void))
{
    GameIntro *intro = TASK_DATA(gCurTask);
    s16 *buf;
    s16 i;

    gHBlankCopySize = 16;
    gHBlankCopyTarget = (void *)&REG_BG2PA;
    gBgOffsetsHBlankPrimary = buf = intro->hblankBuf;
    gFlags |= FLAGS_EXECUTE_HBLANK_COPY;

    intro->unk138 = (intro->unk138 + intro->unk140) & 0xFFF;
    intro->unk13A = (intro->unk13A + intro->unk142) & 0x7FF;
    intro->unk148 = intro->unk148 + intro->unk144;
    intro->unk14A = intro->unk14A + intro->unk146;

    for (i = 0; i < DISPLAY_HEIGHT; i++) {
        u16 dist;
        u16 v;

        if (i - intro->unk136 >= 0) {
            dist = i - intro->unk136;
        } else {
            dist = intro->unk136 - i;
        }

        v = intro->recipTable[(s16)dist] * (s16)dist * 2 + intro->unk13A * 16;

        if (i < intro->unk136) {
            if ((s16)v < 0) {
                v -= 0x8000;
            }
        } else if ((s16)v >= 0) {
            v += 0x8000;
        }

        buf[0] = intro->recipTable[(s16)dist] >> 2;
        buf[4] = ((intro->recipTable[(s16)dist] * intro->unk134) >> 2) + intro->unk138 * 16;
        buf[6] = v;
        buf += 8;
    }
}
END_NONMATCH

void Task_170_GameIntroInit(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);
    BgAffineReg affine;
    BgAffineReg *pAffine = &affine;
    s16 *buf;
    s16 i;

    memset(pAffine, 0, sizeof(affine));
    pAffine->pa = Q(1);
    pAffine->pd = Q(1);
    gDispCnt = 0x42;
    sub_80A217C(intro);
    sub_80A22E0(intro);

    buf = intro->hblankBuf = EwramMalloc(DISPLAY_HEIGHT * sizeof(affine));
    for (i = 0; i < DISPLAY_HEIGHT; i++, buf += sizeof(affine) / sizeof(u16)) {
        CpuSet(&affine, buf, sizeof(affine) / sizeof(u16));
    }

    intro->recipTable = EwramMalloc(256 * sizeof(u32));
    for (i = 0; i < 256; i++) {
        intro->recipTable[i] = 0x100000 / (i * 16 + 0x400);
    }

    for (i = 0; i < 16; i++) {
        gBgPalette[i + 0x50] = sub_80C4C0C(RGB_BLACK);
    }

    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
    gBldRegs.bldCnt = 0x1D42;
    gBldRegs.bldAlpha = 0x1010;
    gBldRegs.bldY = 0;
    intro->unk14C = 0;

    for (i = 0; i < 16; i++) {
        intro->unk14E[i] = 0;
    }

    switch (intro->state) {
        case 0:
            gCurTask->main = Task_170_80A2A9C;
            break;
        case 1:
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_INTRO);
        case 2:
            intro->unk13C = 10;
            gCurTask->main = Task_170_80A2A9C;
            break;
        case 3:
            intro->unk13C = 0;
            gCurTask->main = sub_80A2700;
            break;
        case 4:
            gCurTask->main = Task_170_80A2A9C;
            break;
        case 5:
            intro->unk13C = 0;
            gCurTask->main = sub_80A2700;
            break;
    }
}

void sub_80A2700(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);
    s32 res;

    gDispCnt = 0x1641;

    res = sub_80A2DD8();
    if (res == 0) {
        sub_80A2978(intro->unk13E);
        sub_80A2A40(0);
        sub_80A2D80();
        sub_80A23A4();

        if (intro->unk13C > 0) {
            intro->unk13C--;
        } else {
            intro->unk13C = res;
            gCurTask->main = sub_80A2774;
        }
    }
}

void sub_80A2774(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);

    if (sub_80A2DD8() == 0) {
        sub_80A2978(intro->unk13E >> 1);
        sub_80A2A40(intro->unk13C >> 3);
        sub_80A2D80();
        sub_80A23A4();

        if (++intro->unk13C < 64) {
            if (intro->unk13C > 32) {
                intro->unk13E++;
            }
        } else {
            intro->unk13E++;
            sub_80A2A40(7);
            gCurTask->main = sub_80A27EC;
        }
    }
}

void sub_80A27EC(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);
    s16 i;

    intro->unk14C = (intro->unk14C + 1) & 0xFF;

    if (sub_80A2DD8() != 0) {
        return;
    }

    sub_80A2978(intro->unk13E >> 1);
    intro->unk13C++;
    intro->unk13E++;

    if (intro->unk14C == 0) {
        for (i = 0; i < 16; i++) {
            intro->unk14E[i] = 0;
        }
    }

    for (i = 0; i < 16; i++) {
        if (intro->unk14C > i * 4) {
            s16 v = intro->unk14C - i * 4;
            intro->unk14E[i] = (v > 31) ? 31 : v;
        }
    }

    for (i = 0; i < 16; i++) {
        u16 c = intro->unk14E[i] & 0x1F;
        gBgPalette[i + 0x50] = sub_80C4C0C(c | (c << 5) | (c << 10));
    }

    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
    sub_80A2D80();
    sub_80A23A4();

    if (intro->unk14C == 149) {
        m4aMPlayFadeOut(&gMPlayInfo_BGM, 5);
        m4aMPlayFadeOut(&gMPlayInfo_SE1, 5);
        m4aMPlayFadeOut(&gMPlayInfo_SE2, 5);
        m4aMPlayFadeOut(&gMPlayInfo_SE3, 5);
    }

    if (intro->unk14C > 159) {
        gBldRegs.bldCnt = 0xBF;
        gBldRegs.bldAlpha = 0;
        gBldRegs.bldY = 16;
        gFlags &= ~FLAGS_EXECUTE_HBLANK_COPY;
        gCurTask->main = Task_80A2D34;
    }
}

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2978.inc", void sub_80A2978(s16 arg0))
{
    GameIntro *intro = TASK_DATA(gCurTask);
    s32 half;
    s32 sum;
    s16 t;

    if (arg0 < 256) {
        s32 off = ((arg0 + 32) >> 4) - 4;
        intro->transforms[0].y = intro->s.y = intro->unk136 - off;
        off = (arg0 >> 4) - 4;
        intro->transforms[1].y = intro->s2.y = intro->unk136 - off;
        half = arg0 >> 1;
        intro->transforms[0].x = intro->s.x = arg0 + (half + 130);

        sum = half + arg0;
        t = 224 - sum;
        if (t > 0) {
            intro->transforms[0].qScaleX = -t;
            intro->transforms[0].qScaleY = t;
        }

        off = (arg0 >> 2) - 100;
        intro->transforms[1].x = intro->s2.x = arg0 * 2 - off;

        t = 256 - sum;
        if (t > 0) {
            intro->transforms[1].qScaleX = -t;
            intro->transforms[1].qScaleY = t;
        }
    }
}
END_NONMATCH

void sub_80A2A40(s16 arg0)
{
    const u16 *pal;
    s16 i;

    if (arg0 < 0) {
        arg0 = 0;
    } else if (arg0 > 7) {
        arg0 = 7;
    }

    pal = &Palette_unknown_424[arg0 * 32];
    for (i = 0; i < 32; i++) {
        gBgPalette[i] = sub_80C4C0C(pal[i]);
    }

    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
}

void Task_170_80A2A9C(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);

    gDispCnt = 0x1441;
    gBldRegs.bldCnt = 0;
    gBldRegs.bldAlpha = 0;
    gBldRegs.bldY = 0;
    intro->unk13C--;

    if (sub_80A2DD8() == 0) {
        sub_80A2D80();
        sub_80A23A4();

        if (intro->unk13C <= 0) {
            intro->unk13C = 150;

            if (intro->state != 0 && intro->state <= 3) {
                gDispCnt = 0x1541;
            }

            if (intro->state == 5) {
                gDispCnt = 0x1541;
            }

            gBldRegs.bldCnt = 0x3F41;
            gBldRegs.bldAlpha = 0x1000;
            gBldRegs.bldY = 0;
            gCurTask->main = Task_170_80A2B54;
        }
    }
}

void Task_170_80A2B54(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);
    s32 t = (u16)intro->unk13C - 1;
    intro->unk13C = t;

    if ((s16)t > 141) {
        s16 a = (150 - t) * 2;
        gBldRegs.bldAlpha = ((16 - a) << 8) | a;
    } else if ((s16)t <= 8) {
        s16 a = t * 2;
        gBldRegs.bldAlpha = ((16 - a) << 8) | a;
    } else {
        gBldRegs.bldAlpha = 16;
    }

    if (sub_80A2DD8() == 0) {
        sub_80A2D80();
        sub_80A23A4();

        if (intro->unk13C <= 0) {
            switch (intro->state) {
                case 0:
                    break;
                case 1:
                    intro->unk13C = 10;
                    break;
                case 2:
                    intro->unk13C = 120;
                    gStageData.unk7 = 1;
                    break;
                case 3:
                case 4:
                case 5:
                default:
                    intro->unk13C = 1;
                    break;
            }

            gDispCnt = 0x1441;
            gCurTask->main = Task_170_80A2C60;
        }
    }
}

void Task_170_80A2C60(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);
    s32 res;

    intro->unk13C--;

    res = sub_80A2DD8();
    if (res == 0) {
        if (intro->unk13C > 0) {
            sub_80A2D80();
            sub_80A23A4();
        } else {
            gBldRegs.bldCnt = 0xFF;
            gBldRegs.bldAlpha = res;
            gBldRegs.bldY = 16;

            switch (intro->state) {
                case 0:
                    sub_80A2E38(1);
                    break;
                case 1:
                    sub_80A2E38(0);
                    break;
                case 2:
                    sub_80A3F18();
                    break;
                case 4:
                    CreateIntroEggmanCutscene(1);
                    break;
            }

            TaskDestroy(gCurTask);
        }
    }
}

void TaskDestructor_GameIntro(struct Task *t)
{
    GameIntro *intro = TASK_DATA(t);
    EwramFree(intro->hblankBuf);
    EwramFree(intro->recipTable);
    gFlags &= ~FLAGS_EXECUTE_HBLANK_COPY;
}

void Task_80A2D34(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);

    switch (intro->state) {
        case 3:
            sub_808ADF0(2);
            break;
        case 5:
            LOADED_SAVE->unk34 |= 1;
            sub_8001E58();
            WarpToMap(2, 0);
            break;
    }
}

void sub_80A2D80(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);
    Sprite *s = &intro->s;

    UpdateSpriteAnimation(s);
    TransformSprite(s, &intro->transforms[0]);
    DisplaySprite(s);

    s = &intro->s2;
    UpdateSpriteAnimation(s);
    TransformSprite(s, &intro->transforms[1]);
    DisplaySprite(s);
}

s16 sub_80A2DD8(void)
{
    GameIntro *intro = TASK_DATA(gCurTask);

    if (gStageData.unk7 != 0 && intro->state != 0 && intro->state <= 3 && (gPressedKeys & START_BUTTON)) {
        gFlags &= ~FLAGS_EXECUTE_HBLANK_COPY;
        sub_808ADF0(2);
        return TRUE;
    }

    return FALSE;
}

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2E38.inc", void sub_80A2E38(u8 arg0))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2F0C.inc", void sub_80A2F0C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_A0_80A2FF4.inc", void Task_A0_80A2FF4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_A0_80A3074.inc", void Task_A0_80A3074(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__CreateIntroEggmanCutscene.inc", void CreateIntroEggmanCutscene(u8 arg0))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3228.inc", void sub_80A3228(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3354.inc", void sub_80A3354(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_174_80A3444.inc", void Task_174_80A3444(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_174_80A3564.inc", void Task_174_80A3564(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_174_80A3664.inc", void Task_174_80A3664(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_174_80A3710.inc", void Task_174_80A3710(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_174_80A37B8.inc", void Task_174_80A37B8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_174_80A3844.inc", void Task_174_80A3844(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A38C0.inc", void sub_80A38C0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A398C.inc", void sub_80A398C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_94_A_80A39FC.inc", void Task_94_A_80A39FC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3A7C.inc", void sub_80A3A7C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3B64.inc", void sub_80A3B64(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3BFC.inc", void sub_80A3BFC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3CC8.inc", void sub_80A3CC8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_54_80A3D3C.inc", void Task_54_80A3D3C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_54_80A3DAC.inc", void Task_54_80A3DAC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__TaskDestructor_A0_80A3E34.inc", void TaskDestructor_A0_80A3E34(struct Task *t))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__TaskDestructor_174_80A3E38.inc", void TaskDestructor_174_80A3E38(struct Task *t))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3E3C.inc", void sub_80A3E3C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3E60.inc", void sub_80A3E60(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3E90.inc", void sub_80A3E90(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3EAC.inc", void sub_80A3EAC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3EDC.inc", void sub_80A3EDC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__TaskDestructor_94_A_80A3F10.inc", void TaskDestructor_94_A_80A3F10(struct Task *t))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__TaskDestructor_54_80A3F14.inc", void TaskDestructor_54_80A3F14(struct Task *t))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3F18.inc", void sub_80A3F18(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A3FDC.inc", void sub_80A3FDC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_94_B_80A40A0.inc", void Task_94_B_80A40A0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_94_B_80A41AC.inc", void Task_94_B_80A41AC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_94_B_80A4228.inc", void Task_94_B_80A4228(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_94_B_80A429C.inc", void Task_94_B_80A429C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_94_B_80A4384.inc", void Task_94_B_80A4384(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__TaskDestructor_94_B_80A43DC.inc", void TaskDestructor_94_B_80A43DC(struct Task *t))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A43E0.inc", void sub_80A43E0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A4440.inc", void sub_80A4440(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A4494.inc", void sub_80A4494(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A44E8.inc", void sub_80A44E8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A453C.inc", void sub_80A453C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A4598.inc", void sub_80A4598(void))
{
}
END_NONMATCH
