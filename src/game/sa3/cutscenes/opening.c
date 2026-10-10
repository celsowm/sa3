#include "global.h"
#include "core.h"
#include "flags.h"
#include "malloc_ewram.h"
#include "lib/m4a/m4a.h"
#include "game/stage.h" // gStageData
#include "constants/tilemaps.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
} GameIntroSub; /* 0xC */

typedef struct {
    /* 0x000 */ Sprite s;
    /* 0x028 */ Sprite s2;
    /* 0x050 */ GameIntroSub sub[2];
    /* 0x068 */ Background bg68;
    /* 0x0A8 */ Background bgA8;
    /* 0x0E8 */ Background bgE8;
    /* 0x128 */ s16 state;
    /* 0x12C */ void *hblankBuf;
    /* 0x130 */ s32 *recipTable;
    /* 0x134 */ s16 unk134;
    /* 0x136 */ s16 unk136;
    /* 0x138 */ s16 unk138;
    /* 0x13A */ s16 unk13A;
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

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A22E0.inc", void sub_80A22E0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A23A4.inc", void sub_80A23A4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_170_GameIntroInit.inc", void Task_170_GameIntroInit(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2700.inc", void sub_80A2700(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2774.inc", void sub_80A2774(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A27EC.inc", void sub_80A27EC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2978.inc", void sub_80A2978(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2A40.inc", void sub_80A2A40(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_170_80A2A9C.inc", void Task_170_80A2A9C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_170_80A2B54.inc", void Task_170_80A2B54(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_170_80A2C60.inc", void Task_170_80A2C60(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__TaskDestructor_GameIntro.inc", void TaskDestructor_GameIntro(struct Task *t))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__Task_80A2D34.inc", void Task_80A2D34(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2D80.inc", void sub_80A2D80(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2DD8.inc", void sub_80A2DD8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__sub_80A2E38.inc", void sub_80A2E38(void))
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

NONMATCH("asm/non_matching/game/sa3/cutscenes/opening__CreateIntroEggmanCutscene.inc", void CreateIntroEggmanCutscene(void))
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
