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

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ Background bg20;
    /* 0x60 */ Background bg60;
} IntroA0; /* 0xA0 */

typedef struct {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u16 unk2;
    /* 0x004 */ u16 unk4;
    /* 0x006 */ u16 unk6;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ Background bg2C;
    /* 0x06C */ Background bg6C;
    /* 0x0AC */ Sprite sAC;
    /* 0x0D4 */ Sprite sD4[2];
    /* 0x124 */ Sprite s124[2];
} Intro174; /* 0x174 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ Background bg14;
    /* 0x54 */ Background bg54;
} Intro94A; /* 0x94 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ Background bg14;
} Intro54; /* 0x54 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ s8 unk3;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ void *tiles28;
    /* 0x2C */ Sprite s;
    /* 0x54 */ Background bg54;
} Intro94B; /* 0x94 */

void Task_170_GameIntroInit(void);
void Task_94_B_80A40A0(void);
void Task_94_B_80A41AC(void);
void Task_94_B_80A4228(void);
void Task_94_B_80A429C(void);
void Task_94_B_80A4384(void);
void TaskDestructor_94_B_80A43DC(struct Task *t);
void sub_80A3FDC(Intro94B *strc);
bool32 sub_80A43E0(Intro94B *strc);
bool32 sub_80A4440(Intro94B *strc);
bool32 sub_80A4494(Intro94B *strc);
bool32 sub_80A44E8(Intro94B *strc);
bool32 sub_80A453C(Intro94B *strc);
void sub_80A4598(Intro94B *strc);
extern void *CreateSomeTask_809BF3C(void *param0, void *param1, void *param2, void *param3, void *tiles);
void Task_54_80A3D3C(void);
void Task_54_80A3DAC(void);
void TaskDestructor_54_80A3F14(struct Task *t);
void sub_80A3CC8(Intro54 *strc);
void Task_94_A_80A39FC(void);
void TaskDestructor_94_A_80A3F10(struct Task *t);
void sub_80A398C(Intro94A *strc);
void sub_80A3A7C(void);
void sub_80A3B64(void);
void sub_80A3BFC(u8 arg0);
void Task_174_80A3444(void);
void TaskDestructor_174_80A3E38(struct Task *t);
void sub_80A3228(Intro174 *strc);
void sub_80A3354(Intro174 *strc);
void Task_174_80A3564(void);
void Task_174_80A3664(void);
void Task_174_80A3710(void);
void Task_174_80A37B8(void);
void Task_174_80A3844(void);
bool32 sub_80A3E3C(Intro174 *strc);
bool32 sub_80A3E60(Intro174 *strc);
void sub_80A3E90(Intro174 *strc);
void sub_80A3EAC(Intro174 *strc);
void sub_80A3EDC(Intro174 *strc);
void sub_80A38C0(u8 arg0);

#define INTRO174_UPDATE_WINDOW_AND_SKIP(strc)                                                                                              \
    {                                                                                                                                      \
        gWinRegs[WINREG_WIN0V] = (I((strc)->unk10) << 8) + I((strc)->unk10) + I((strc)->unk8);                                             \
        gBgScrollRegs[2][0] = I((strc)->unk14);                                                                                            \
        gBgScrollRegs[2][1] = I((strc)->unk18);                                                                                            \
                                                                                                                                           \
        if ((strc)->unk0 == 0 && (gPressedKeys & START_BUTTON)) {                                                                          \
            sub_808ADF0(2);                                                                                                                \
        }                                                                                                                                  \
    }
void Task_A0_80A2FF4(void);
void Task_A0_80A3074(void);
void TaskDestructor_A0_80A3E34(struct Task *t);
void sub_80A2F0C(IntroA0 *strc);
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
extern const TileInfo2 gUnknown_080D9980[5];
extern const TileInfo2 gUnknown_080D99A8[];
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

void sub_80A2E38(u8 arg0)
{
    IntroA0 *strc;

    gDispCnt = 0x1040;
    strc = TASK_DATA(TaskCreate(Task_A0_80A2FF4, sizeof(IntroA0), 0x100, 0, TaskDestructor_A0_80A3E34));
    strc->unk14 = Q(48);
    strc->unkC = Q(64);
    strc->unk18 = 0;
    strc->unk1C = 0;
    strc->unk1 = 2;
    strc->unk4 = 0;
    strc->unk0 = arg0;

    DmaFill32(3, 0, BG_CHAR_ADDR_FROM_BGCNT(0), 0x40);

    gBgSprites_Unknown1[1] = 0;
    gBgSprites_Unknown2[1][0] = 0;
    gBgSprites_Unknown2[1][1] = 0;
    gBgSprites_Unknown2[1][2] = 0xFF;
    gBgSprites_Unknown2[1][3] = 0x40;
    gBgSprites_Unknown1[2] = 0;
    gBgSprites_Unknown2[2][0] = 0;
    gBgSprites_Unknown2[2][1] = 0;
    gBgSprites_Unknown2[2][2] = -1;
    gBgSprites_Unknown2[2][3] = 0x40;

    sub_80A2F0C(strc);

    gBgPalette[0] = sub_80C4C0C(RGB_BLACK);
    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
}

void sub_80A2F0C(IntroA0 *strc)
{
    gDispCnt |= DISPCNT_BG1_ON;
    gBgCntRegs[1] = 0xC81;
    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;

    {
        Background *bg = &strc->bg60;
        bg->graphics.dest = BG_CHAR_ADDR(0);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(12);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_302;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        strc->bg60.paletteOffset = 0;
        bg->flags = 5;
        DrawBackground(bg);
    }

    gDispCnt |= DISPCNT_BG2_ON;
    gBgCntRegs[2] = 0x5888;
    gBgScrollRegs[2][0] = 0;
    gBgScrollRegs[2][1] = 0;

    {
        Background *bg = &strc->bg20;
        bg->graphics.dest = BG_CHAR_ADDR(2);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(24);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_301;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        strc->bg20.paletteOffset = 0;
        bg->flags = 6;
        DrawBackground(bg);
    }
}

void Task_A0_80A2FF4(void)
{
    IntroA0 *strc = TASK_DATA(gCurTask);

    gBldRegs.bldCnt = 0x3FFF;
    gDispCnt |= (DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
    gWinRegs[WINREG_WIN0H] = 0xFF;
    gWinRegs[WINREG_WIN1H] = 0xFF;
    gWinRegs[WINREG_WIN1V] = 0xFF;
    gWinRegs[WINREG_WININ] = 0x3117;
    gWinRegs[WINREG_WINOUT] = 0;
    gBldRegs.bldY = 16;
    strc->unk6 = 0x1000;
    strc->unk8 = 1;
    gWinRegs[WINREG_WIN0V] = (I(strc->unk14) << 8) + I(strc->unk14) + I(strc->unkC);
    gBldRegs.bldAlpha = 0x1F;
    gBldRegs.bldY = 16;
    gCurTask->main = Task_A0_80A3074;
}

void Task_A0_80A3074(void)
{
    IntroA0 *strc = TASK_DATA(gCurTask);
    bool32 done = FALSE;

    if (strc->unk4 > 4 || ++strc->unk4 > 4) {
        if (strc->unk18 < Q(80)) {
            strc->unk18 += Q(strc->unk1);
            if (strc->unk18 >= Q(80)) {
                strc->unk18 = Q(80);
                done = TRUE;
            }
        }
    }

    gWinRegs[WINREG_WIN0V] = (I(strc->unk14) << 8) + I(strc->unk14) + I(strc->unkC);
    gBgScrollRegs[2][0] = I(strc->unk18);
    gBgScrollRegs[2][1] = I(strc->unk1C);

    if (done) {
        if (strc->unk0 == 0) {
            CreateGameIntroState(2);
        } else {
            CreateGameIntroState(4);
        }
        TaskDestroy(gCurTask);
    }
}

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__CreateIntroEggmanCutscene.inc", void CreateIntroEggmanCutscene(u8 arg0))
{
    Intro174 *strc;

    gDispCnt = 0x7140;
    strc = TASK_DATA(TaskCreate(Task_174_80A3444, sizeof(Intro174), 0x100, 0, TaskDestructor_174_80A3E38));
    strc->unk0 = arg0;
    strc->unk10 = Q(64);
    strc->unk8 = Q(32);
    strc->unk14 = 0;
    strc->unk18 = -Q(100);
    strc->unk24 = Q(230);
    strc->unk28 = Q(130);
    strc->unk1C = Q(180);
    strc->unk20 = Q(160);
    strc->unk1 = 1;
    strc->unk6 = 0;
    strc->unk4 = 0;
    strc->unk2 = 0;

    DmaFill32(3, 0, BG_CHAR_ADDR_FROM_BGCNT(0), 0x40);

    gBgSprites_Unknown1[1] = 0;
    gBgSprites_Unknown2[1][0] = 0;
    gBgSprites_Unknown2[1][1] = 0;
    gBgSprites_Unknown2[1][2] = 0xFF;
    gBgSprites_Unknown2[1][3] = 0x40;
    gBgSprites_Unknown1[2] = 0;
    gBgSprites_Unknown2[2][0] = 0;
    gBgSprites_Unknown2[2][1] = 0;
    gBgSprites_Unknown2[2][2] = -1;
    gBgSprites_Unknown2[2][3] = 0x40;

    sub_80A3354(strc);

    gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);

    if (strc->unk0 != 0) {
        gBgPalette[0] = sub_80C4C0C(RGB_BLACK);
    } else {
        gBgPalette[0] = sub_80C4C0C(0xFFFF);
    }
    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
}
END_NONMATCH

void sub_80A3228(Intro174 *strc)
{
    u8 i = 0;
    u8 *tiles = OBJ_VRAM0;
    Sprite *s = &strc->sAC;

    s->tiles = tiles;
    tiles += gUnknown_080D9980[0].numTiles * TILE_SIZE_4BPP;
    s->anim = gUnknown_080D9980[0].anim;
    s->variant = gUnknown_080D9980[0].variant;
    s->prevVariant = -1;
    s->x = I(strc->unk24);
    s->y = I(strc->unk28);
    s->oamFlags = SPRITE_OAM_ORDER(0);
    s->animCursor = 0;
    s->qAnimDelay = 0;
    s->animSpeed = SPRITE_ANIM_SPEED(1.0);
    s->palId = 0;
    s->frameFlags = 0;
    UpdateSpriteAnimation(s);

    for (; i < ARRAY_COUNT(strc->sD4); i++) {
        Sprite *s = &strc->sD4[i];
        s->tiles = tiles;
        tiles += gUnknown_080D9980[i + 1].numTiles * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D9980[i + 1].anim;
        s->variant = gUnknown_080D9980[i + 1].variant;
        s->prevVariant = -1;
        s->x = I(strc->unk1C);
        s->y = I(strc->unk20);
        s->oamFlags = SPRITE_OAM_ORDER(1);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    for (i = 0; i < ARRAY_COUNT(strc->s124); i++) {
        Sprite *s = &strc->s124[i];
        s->tiles = tiles;
        tiles += gUnknown_080D9980[i + 3].numTiles * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D9980[i + 3].anim;
        s->variant = gUnknown_080D9980[i + 3].variant;
        s->prevVariant = -1;
        s->x = I(strc->unk1C);
        s->y = I(strc->unk20);
        s->oamFlags = SPRITE_OAM_ORDER(1);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }
}

void sub_80A3354(Intro174 *strc)
{
    gDispCnt |= DISPCNT_BG2_ON;
    gBgCntRegs[2] = 0x5888;
    gBgScrollRegs[2][0] = I(strc->unk14);
    gBgScrollRegs[2][1] = I(strc->unk18);

    {
        Background *bg = &strc->bg2C;
        bg->graphics.dest = BG_CHAR_ADDR(2);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(24);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_300;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        strc->bg2C.paletteOffset = 0;
        bg->flags = 6;
        DrawBackground(bg);
    }

    gDispCnt |= DISPCNT_BG1_ON;
    gBgCntRegs[1] = 0x681;
    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;

    {
        Background *bg = &strc->bg6C;
        bg->graphics.dest = BG_CHAR_ADDR(0);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(6);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_299;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        strc->bg6C.paletteOffset = 0;
        bg->flags = 5;
        DrawBackground(bg);
    }
}

void Task_174_80A3444(void)
{
    Intro174 *strc = TASK_DATA(gCurTask);
    u8 count = 0;

    if (strc->unk6 == 0) {
        gBldRegs.bldCnt = 0xC2;
        gDispCnt |= (DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        gWinRegs[WINREG_WIN0H] = 0xFF;
        gWinRegs[WINREG_WIN1H] = 0xFF;
        gWinRegs[WINREG_WIN1V] = 0xFF;
        gWinRegs[WINREG_WININ] = 0x1137;
        gWinRegs[WINREG_WINOUT] = 0;
        gBldRegs.bldY = 16;
        strc->unk4 = 0x1000;
        strc->unk6 = 1;
        sub_80A3228(strc);
        gDispCnt &= ~DISPCNT_BG0_ON;
    }

    if (strc->unk10 >= Q(48)) {
        strc->unk10 -= Q(1);
        if (strc->unk10 <= Q(48)) {
            strc->unk10 = Q(48);
            count = 1;
        }
    }

    if (strc->unk8 <= Q(64)) {
        strc->unk8 += Q(2);
        if (strc->unk8 >= Q(64)) {
            strc->unk8 = Q(64);
            count++;
        }
    }

    if (gBldRegs.bldY != 0) {
        gBldRegs.bldY = strc->unk4 >> 8;
        strc->unk4 -= Q(1);
    } else {
        count++;
    }

    gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);

    if (count == 3) {
        gBldRegs.bldCnt = 0xF0;
        gWinRegs[WINREG_WININ] = 0x3017;
        gBldRegs.bldAlpha = 0x1F;
        gBldRegs.bldY = 0;
        strc->unk6 = 0;
        strc->unk4 = 0;
        gCurTask->main = Task_174_80A3564;
    }
}

void Task_174_80A3564(void)
{
    Intro174 *strc = TASK_DATA(gCurTask);

    sub_80A3E3C(strc);

    if (gBldRegs.bldY < 16) {
        strc->unk4 += 0x80;
        gBldRegs.bldY = strc->unk4 >> 8;
    } else {
        gBgPalette[0] = sub_80C4C0C(RGB_BLACK);
        gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
    }

    if (++strc->unk2 > 150) {
        strc->unk4 = 0x1000;
        strc->unk2 = 0;
        gBldRegs.bldCnt = 0xD0;
        gWinRegs[WINREG_WININ] = 0x3017;
        gBldRegs.bldAlpha = 0x1F;
        gBldRegs.bldY = 16;
        strc->unk6 = 0;
        strc->unk4 = 0x1000;
        gBgPalette[0] = sub_80C4C0C(RGB_BLACK);
        gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
        gCurTask->main = Task_174_80A3664;
    } else {
        gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);
        gBgScrollRegs[2][0] = I(strc->unk14);
        gBgScrollRegs[2][1] = I(strc->unk18);

        if (strc->unk0 == 0 && (gPressedKeys & START_BUTTON)) {
            sub_808ADF0(2);
        }
    }
}

void Task_174_80A3664(void)
{
    Intro174 *strc = TASK_DATA(gCurTask);

    if (strc->unk0 == 0) {
        sub_80A3E90(strc);
    }

    if (gBldRegs.bldY == 0) {
        gBldRegs.bldY = 0;
        if (++strc->unk2 > 60) {
            strc->unk2 = 0;
            strc->unk4 = 0;
            gCurTask->main = Task_174_80A3710;
            return;
        }
    } else {
        strc->unk4 -= Q(1);
        gBldRegs.bldY = strc->unk4 >> 8;
    }

    INTRO174_UPDATE_WINDOW_AND_SKIP(strc);
}

void Task_174_80A3710(void)
{
    Intro174 *strc = TASK_DATA(gCurTask);

    if (strc->unk0 == 0) {
        sub_80A3E90(strc);
    }

    if (gBldRegs.bldY >= 16) {
        gBldRegs.bldY = 16;
        gWinRegs[WINREG_WININ] = 0x2017;
        strc->unk2 = 0;
        gCurTask->main = Task_174_80A37B8;
    } else {
        strc->unk4 += Q(1);
        gBldRegs.bldY = strc->unk4 >> 8;
        INTRO174_UPDATE_WINDOW_AND_SKIP(strc);
    }
}

void Task_174_80A37B8(void)
{
    Intro174 *strc = TASK_DATA(gCurTask);

    sub_80A3EAC(strc);

    if (sub_80A3E60(strc) == TRUE && ++strc->unk2 > 60) {
        strc->unk2 = 0;
        gCurTask->main = Task_174_80A3844;
    } else {
        INTRO174_UPDATE_WINDOW_AND_SKIP(strc);
    }
}

void Task_174_80A3844(void)
{
    Intro174 *strc = TASK_DATA(gCurTask);

    sub_80A3EDC(strc);

    if (strc->unk2 >= 20) {
        sub_80A38C0(strc->unk0);
        TaskDestroy(gCurTask);
    } else {
        strc->unk2++;
        INTRO174_UPDATE_WINDOW_AND_SKIP(strc);
    }
}

void sub_80A38C0(u8 arg0)
{
    Intro94A *strc;

    gDispCnt = 0x1040;
    strc = TASK_DATA(TaskCreate(Task_94_A_80A39FC, sizeof(Intro94A), 0x100, 0, TaskDestructor_94_A_80A3F10));
    strc->unk0 = arg0;
    strc->unk10 = Q(48);
    strc->unk8 = Q(64);
    strc->unk2 = 0;

    DmaFill32(3, 0, BG_CHAR_ADDR_FROM_BGCNT(0), 0x40);

    gBgSprites_Unknown1[1] = 0;
    gBgSprites_Unknown2[1][0] = 0;
    gBgSprites_Unknown2[1][1] = 0;
    gBgSprites_Unknown2[1][2] = 0xFF;
    gBgSprites_Unknown2[1][3] = 0x40;
    gBgSprites_Unknown1[2] = 0;
    gBgSprites_Unknown2[2][0] = 0;
    gBgSprites_Unknown2[2][1] = 0;
    gBgSprites_Unknown2[2][2] = -1;
    gBgSprites_Unknown2[2][3] = 0x40;

    sub_80A398C(strc);

    gBgPalette[0] = sub_80C4C0C(RGB_BLACK);
    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
}

void sub_80A398C(Intro94A *strc)
{
    gDispCnt |= DISPCNT_BG1_ON;
    gBgCntRegs[1] = 0xD81;
    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;

    {
        Background *bg = &strc->bg54;
        bg->graphics.dest = BG_CHAR_ADDR(0);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(13);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_302;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        strc->bg54.paletteOffset = 0;
        bg->flags = 5;
        DrawBackground(bg);
    }
}

void Task_94_A_80A39FC(void)
{
    struct Task *t = gCurTask;
    Intro94A *strc = TASK_DATA(t);

    gBldRegs.bldCnt = 0x3FFF;
    gDispCnt |= (DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
    gWinRegs[WINREG_WIN0H] = 0xFF;
    gWinRegs[WINREG_WIN1H] = 0xFF;
    gWinRegs[WINREG_WIN1V] = 0xFF;
    gWinRegs[WINREG_WININ] = 0x3117;
    gWinRegs[WINREG_WINOUT] = 0;
    gBldRegs.bldY = 16;
    strc->unk4 = 0x1000;
    strc->unk6 = 1;
    gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);
    gBldRegs.bldAlpha = 0x1F;
    gBldRegs.bldY = 16;
    t->main = sub_80A3A7C;
}

void sub_80A3A7C(void)
{
    Intro94A *strc = TASK_DATA(gCurTask);

    gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);

    if (++strc->unk2 == 4) {
        gDispCnt |= DISPCNT_BG2_ON;
    }

    if (strc->unk2 == 5) {
        gBgCntRegs[2] = 0x5D88;
        gBgScrollRegs[2][0] = 0;
        gBgScrollRegs[2][1] = 0;

        {
            Background *bg = &strc->bg14;
            bg->graphics.dest = BG_CHAR_ADDR(2);
            bg->graphics.anim = 0;
            bg->layoutVram = BG_SCREEN_ADDR(29);
            bg->unk18 = 0;
            bg->unk1A = 0;
            bg->tilemapId = TM_UNKNOWN_304;
            bg->unk1E = 0;
            bg->unk20 = 0;
            bg->unk22 = 0;
            bg->unk24 = 0;
            bg->targetTilesX = 32;
            bg->targetTilesY = 32;
            strc->bg14.paletteOffset = 0;
            bg->flags = 6;
            DrawBackground(bg);
        }
    }

    if (strc->unk2 > 10) {
        strc->unk6 = 0;
        gCurTask->main = sub_80A3B64;
    } else if (strc->unk0 == 0 && (gPressedKeys & START_BUTTON)) {
        sub_808ADF0(2);
    }
}

void sub_80A3B64(void)
{
    Intro94A *strc = TASK_DATA(gCurTask);

    gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);

    if (strc->unk6 == 0) {
        gBldRegs.bldCnt = 0x3FBF;
        gDispCnt |= (DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        gWinRegs[WINREG_WIN0H] = 0xFF;
        gWinRegs[WINREG_WIN1H] = 0xFF;
        gWinRegs[WINREG_WIN1V] = 0xFF;
        gWinRegs[WINREG_WININ] = 0x24;
        gWinRegs[WINREG_WINOUT] = 0;
        strc->unk4 = 0;
        strc->unk6 = 1;
        gBldRegs.bldY = 0;
    }

    if (gBldRegs.bldY < 15) {
        strc->unk4 += 0x30;
        gBldRegs.bldY = strc->unk4 >> 8;
    } else {
        sub_80A3BFC(strc->unk0);
        TaskDestroy(gCurTask);
    }
}

void sub_80A3BFC(u8 arg0)
{
    Intro54 *strc;

    gDispCnt = 0x7040;
    strc = TASK_DATA(TaskCreate(Task_54_80A3D3C, sizeof(Intro54), 0x100, 0, TaskDestructor_54_80A3F14));
    strc->unk0 = arg0;
    strc->unk10 = Q(48);
    strc->unk8 = Q(64);
    strc->unk2 = 0;

    DmaFill32(3, 0, BG_CHAR_ADDR_FROM_BGCNT(0), 0x40);

    gBgSprites_Unknown1[1] = 0;
    gBgSprites_Unknown2[1][0] = 0;
    gBgSprites_Unknown2[1][1] = 0;
    gBgSprites_Unknown2[1][2] = 0xFF;
    gBgSprites_Unknown2[1][3] = 0x40;
    gBgSprites_Unknown1[2] = 0;
    gBgSprites_Unknown2[2][0] = 0;
    gBgSprites_Unknown2[2][1] = 0;
    gBgSprites_Unknown2[2][2] = -1;
    gBgSprites_Unknown2[2][3] = 0x40;

    sub_80A3CC8(strc);

    gBgPalette[0] = sub_80C4C0C(RGB_BLACK);
    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
}

void sub_80A3CC8(Intro54 *strc)
{
    gDispCnt |= DISPCNT_BG0_ON;
    gBgCntRegs[0] = 0x5888;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;

    {
        Background *bg = &strc->bg14;
        bg->graphics.dest = BG_CHAR_ADDR(2);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(24);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_303;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        strc->bg14.paletteOffset = 0;
        bg->flags = 4;
        DrawBackground(bg);
    }
}

void Task_54_80A3D3C(void)
{
    struct Task *t = gCurTask;
    Intro54 *strc = TASK_DATA(t);

    gBldRegs.bldCnt = 0x3FBF;
    gDispCnt |= (DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
    gWinRegs[WINREG_WIN0H] = 0xFF;
    gWinRegs[WINREG_WIN1H] = 0xFF;
    gWinRegs[WINREG_WIN1V] = 0xFF;
    gWinRegs[WINREG_WININ] = 0x21;
    gWinRegs[WINREG_WINOUT] = 0;
    gBldRegs.bldY = 0;
    strc->unk4 = 0;
    strc->unk6 = 1;
    gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);
    t->main = Task_54_80A3DAC;
}

void Task_54_80A3DAC(void)
{
    Intro54 *strc = TASK_DATA(gCurTask);

    gWinRegs[WINREG_WIN0V] = (I(strc->unk10) << 8) + I(strc->unk10) + I(strc->unk8);

    if (gBldRegs.bldY < 15) {
        strc->unk4 += 0x30;
        gBldRegs.bldY = strc->unk4 >> 8;

    } else {
        if (strc->unk0 != 0) {
            CreateGameIntroState(5);
        } else {
            CreateGameIntroState(3);
        }
        TaskDestroy(gCurTask);
        return;
    }

    if (strc->unk0 == 0 && (gPressedKeys & START_BUTTON)) {
        sub_808ADF0(2);
    }
}

void TaskDestructor_A0_80A3E34(struct Task *t)
{
}

void TaskDestructor_174_80A3E38(struct Task *t)
{
}

bool32 sub_80A3E3C(Intro174 *strc)
{
    if (strc->unk18 < 0) {
        strc->unk18 += Q(strc->unk1);
        if (strc->unk18 >= 0) {
            strc->unk18 = 0;
            return TRUE;
        }
    }

    return FALSE;
}

bool32 sub_80A3E60(Intro174 *strc)
{
    if (strc->unk20 >= Q(112)) {
        strc->unk20 -= Q(0.5) + (strc->unk1 << 7);
        if (strc->unk20 <= Q(112)) {
            strc->unk20 = Q(112);
            return TRUE;
        }
    }

    return FALSE;
}

void sub_80A3E90(Intro174 *strc)
{
    Sprite *s = &strc->sAC;
    s->x = I(strc->unk24);
    s->y = I(strc->unk28);
    DisplaySprite(s);
}

void sub_80A3EAC(Intro174 *strc)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(strc->sD4); i++) {
        Sprite *s = &strc->sD4[i];
        s->x = I(strc->unk1C);
        s->y = I(strc->unk20);
        DisplaySprite(s);
    }
}

void sub_80A3EDC(Intro174 *strc)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(strc->s124); i++) {
        Sprite *s = &strc->s124[i];
        s->x = I(strc->unk1C);
        s->y = I(strc->unk20);
        DisplaySprite(s);
    }
}

void TaskDestructor_94_A_80A3F10(struct Task *t)
{
}

void TaskDestructor_54_80A3F14(struct Task *t)
{
}

void sub_80A3F18(void)
{
    Intro94B *strc;

    gDispCnt = 0x1040;
    strc = TASK_DATA(TaskCreate(Task_94_B_80A40A0, sizeof(Intro94B), 0x100, 0, TaskDestructor_94_B_80A43DC));
    strc->unk14 = Q(80);
    strc->unkC = 0;
    strc->unk18 = -Q(120);
    strc->unk20 = Q(300);
    strc->unk24 = Q(80);
    strc->unk1C = Q(80);
    strc->unk0 = 4;
    strc->unk3 = 1;
    strc->unk2 = 0;
    strc->unk1 = 25;
    strc->unk8 = 0;
    strc->unk6 = 0;
    strc->unk4 = 0;
    sub_80A3FDC(strc);

    gBgPalette[0] = sub_80C4C0C(0xFFFF);
    gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;

    gBgSprites_Unknown1[0] = 0;
    gBgSprites_Unknown2[0][0] = 0;
    gBgSprites_Unknown2[0][1] = 0;
    gBgSprites_Unknown2[0][2] = 0xFF;
    gBgSprites_Unknown2[0][3] = 0x40;

    gWinRegs[WINREG_WIN0V] = (I(strc->unk14) << 8) + I(strc->unk14) + I(strc->unkC);
}

void sub_80A3FDC(Intro94B *strc)
{
    {
        u8 idx = strc->unk2;
        u8 *tiles = OBJ_VRAM0;
        Sprite *s = &strc->s;
        s->tiles = tiles;
        strc->tiles28 = tiles + 0x680;
        s->anim = gUnknown_080D99A8[idx].anim;
        s->variant = gUnknown_080D99A8[idx].variant;
        s->prevVariant = -1;
        s->x = I(strc->unk20);
        s->y = I(strc->unk24);
        s->oamFlags = SPRITE_OAM_ORDER(10);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    gDispCnt |= DISPCNT_BG0_ON;
    gBgCntRegs[0] = 0x5888;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 110;

    {
        Background *bg = &strc->bg54;
        bg->graphics.dest = BG_CHAR_ADDR(2);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(24);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = TM_UNKNOWN_303;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 32;
        bg->targetTilesY = 32;
        strc->bg54.paletteOffset = 0;
        bg->flags = 4;
        DrawBackground(bg);
    }
}

void Task_94_B_80A40A0(void)
{
    Intro94B *strc = TASK_DATA(gCurTask);
    u8 count = 0;

    if (strc->unk8 == 0) {
        gBldRegs.bldCnt = 0x3FFF;
        gDispCnt |= (DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        gWinRegs[WINREG_WIN0H] = 0xFF;
        gWinRegs[WINREG_WIN1H] = 0xFF;
        gWinRegs[WINREG_WIN1V] = 0xFF;
        gWinRegs[WINREG_WININ] = 0x1011;
        gWinRegs[WINREG_WINOUT] = 0;
        gBldRegs.bldY = 16;
        strc->unk6 = 0x1000;
        strc->unk8 = 1;
        CreateSomeTask_809BF3C(&strc->unk2, &strc->unk1, &strc->unk18, &strc->unk1C, strc->tiles28);
    }

    if (strc->unk14 >= Q(64)) {
        strc->unk14 -= Q(1);
        if (strc->unk14 <= Q(64)) {
            strc->unk14 = Q(64);
            count = 1;
        }
    }

    if (strc->unkC <= Q(32)) {
        strc->unkC += Q(2);
        if (strc->unkC >= Q(32)) {
            strc->unkC = Q(32);
            count++;
        }
    }

    gWinRegs[WINREG_WIN0V] = (I(strc->unk14) << 8) + I(strc->unk14) + I(strc->unkC);

    if (count == 2) {
        gBldRegs.bldCnt = 0x3FFF;
        gWinRegs[WINREG_WININ] = 0x1011;
        gBldRegs.bldAlpha = 0;
        gBldRegs.bldY = 16;
        strc->unk8 = 0;
        gCurTask->main = Task_94_B_80A41AC;
    }
}

void Task_94_B_80A41AC(void)
{
    Intro94B *strc = TASK_DATA(gCurTask);

    sub_80A4598(strc);
    gWinRegs[WINREG_WIN0V] = (I(strc->unk14) << 8) + I(strc->unk14) + I(strc->unkC);
    sub_80A43E0(strc);

    if (strc->unk4 > 44) {
        strc->unk4 = 0;
        gCurTask->main = Task_94_B_80A4228;
    } else if (gPressedKeys & START_BUTTON) {
        strc->unk18 = Q(310);
        strc->unk1 = 29;
        sub_808ADF0(2);
    } else {
        strc->unk4++;
    }
}

void Task_94_B_80A4228(void)
{
    Intro94B *strc = TASK_DATA(gCurTask);

    sub_80A4598(strc);

    if (sub_80A453C(strc) == TRUE) {
        strc->unk1 = 27;
    }

    sub_80A4440(strc);

    if (strc->unk4 > 119) {
        strc->unk4 = 0;
        gCurTask->main = Task_94_B_80A429C;
    } else if (gPressedKeys & START_BUTTON) {
        strc->unk18 = Q(310);
        strc->unk1 = 29;
        sub_808ADF0(2);
    } else {
        strc->unk4++;
    }
}

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_94_B_80A429C.inc", void Task_94_B_80A429C(void))
{
    Intro94B *strc = TASK_DATA(gCurTask);

    strc->unk18 = Q(310);
    strc->unk1 = 29;

    if (++strc->unk2 > 4) {
        strc->unk4 = 0;
        gBldRegs.bldCnt = 0xA0;
        gWinRegs[WINREG_WININ] = 0x3000;
        gWinRegs[WINREG_WINOUT] = 0;
        gBldRegs.bldY = 16;
        gBgPalette[0] = sub_80C4C0C(RGB_BLACK);
        gFlags |= FLAGS_UPDATE_BACKGROUND_PALETTES;
        gCurTask->main = Task_94_B_80A4384;
    } else {
        strc->unk1 = 25;
        strc->unk3 = (strc->unk3 > 0) ? -1 : 1;

        if (strc->unk3 > 0) {
            strc->unk18 = -Q(120);
            strc->unk20 = Q(300);
        } else {
            strc->unk18 = Q(360);
            strc->unk20 = -Q(60);
        }

        {
            Sprite *s = &strc->s;
            s->anim = gUnknown_080D99A8[strc->unk2].anim;
            s->variant = gUnknown_080D99A8[strc->unk2].variant;
            s->prevVariant = -1;
            UpdateSpriteAnimation(s);
        }
        gCurTask->main = Task_94_B_80A41AC;
    }
}
END_NONMATCH

void Task_94_B_80A4384(void)
{
    Intro94B *strc = TASK_DATA(gCurTask);
    u32 *pltt = (u32 *)BG_PLTT;

    gBldRegs.bldCnt = 0xA0;
    gWinRegs[WINREG_WININ] = 0x3000;
    gWinRegs[WINREG_WINOUT] = 0;
    gBldRegs.bldY = 16;
    *pltt = 0;

    if (strc->unk4 > 2) {
        CreateIntroEggmanCutscene(0);
        TaskDestroy(gCurTask);
    } else {
        strc->unk4++;
    }
}

void TaskDestructor_94_B_80A43DC(struct Task *t)
{
}

bool32 sub_80A43E0(Intro94B *strc)
{
    if (strc->unk4 > 14) {
        if (strc->unk3 > 0) {
            if (strc->unk18 <= Q(150)) {
                strc->unk18 += (strc->unk0 << 9);
                if (strc->unk18 >= Q(150)) {
                    strc->unk18 = Q(150);
                    return TRUE;
                }
            }
        } else if (strc->unk18 >= Q(90)) {
            strc->unk18 -= (strc->unk0 << 9);
            if (strc->unk18 <= Q(90)) {
                strc->unk18 = Q(90);
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool32 sub_80A4440(Intro94B *strc)
{
    if (strc->unk3 > 0) {
        if (strc->unk18 <= Q(240)) {
            strc->unk18 += (strc->unk0 << 5);
            if (strc->unk18 >= Q(240)) {
                strc->unk18 = Q(240);
                return TRUE;
            }
        }
    } else if (strc->unk18 >= Q(1)) {
        strc->unk18 -= (strc->unk0 << 5);
        if (strc->unk18 <= Q(1)) {
            strc->unk18 = Q(1);
            return TRUE;
        }
    }

    return FALSE;
}

bool32 sub_80A4494(Intro94B *strc)
{
    if (strc->unk3 > 0) {
        if (strc->unk18 <= Q(310)) {
            strc->unk18 += (strc->unk0 << 10);
            if (strc->unk18 >= Q(310)) {
                strc->unk18 = Q(310);
                return TRUE;
            }
        }
    } else if (strc->unk18 >= -Q(70)) {
        strc->unk18 -= (strc->unk0 << 10);
        if (strc->unk18 <= -Q(70)) {
            strc->unk18 = -Q(70);
            return TRUE;
        }
    }

    return FALSE;
}

bool32 sub_80A44E8(Intro94B *strc)
{
    if (strc->unk3 > 0) {
        if (strc->unk20 >= -Q(200)) {
            strc->unk20 -= (strc->unk0 << 11);
            if (strc->unk20 <= -Q(200)) {
                strc->unk20 = -Q(200);
                return TRUE;
            }
        }
    } else if (strc->unk20 <= Q(440)) {
        strc->unk20 += (strc->unk0 << 11);
        if (strc->unk20 >= Q(440)) {
            strc->unk20 = Q(440);
            return TRUE;
        }
    }

    return FALSE;
}

bool32 sub_80A453C(Intro94B *strc)
{
    if (strc->unk3 > 0) {
        if (strc->unk20 >= Q(10)) {
            strc->unk20 -= (strc->unk0 << 11);
            if (strc->unk20 <= Q(10)) {
                strc->unk20 = Q(10);
                return TRUE;
            }
        }
    } else if (strc->unk20 <= Q(230)) {
        strc->unk20 += (strc->unk0 << 11);
        if (strc->unk20 >= Q(230)) {
            strc->unk20 = Q(230);
            return TRUE;
        }
    }

    return FALSE;
}

void sub_80A4598(Intro94B *strc)
{
    Sprite *s = &strc->s;
    s->x = I(strc->unk20);
    s->y = I(strc->unk24);
    DisplaySprite(s);
}
