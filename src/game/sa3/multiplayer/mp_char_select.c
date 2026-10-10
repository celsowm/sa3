#include "global.h"
#include "core.h"
#include "flags.h"
#include "lib/m4a/m4a.h"
#include "game/save.h"
#include "game/screen_fade.h"
#include "game/stage.h" // gStageData
#include "game/shared/stage/player.h"
#include "constants/songs.h"

// Same layout as SDC_EC in sio_debug_code_maybe.c
typedef struct {
    /* 0x00 */ ScreenFade fade;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s8 unkE[4];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ s8 unk13;
    /* 0x14 */ s8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1C */ Background bg1C;
    /* 0x5C */ Background bg5C;
    /* 0x9C */ Sprite spr9C;
    /* 0xC4 */ Sprite sprC4;
} SDC_EC; /* 0xEC */

typedef struct {
    /* 0x000 */ u8 language;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u8 unk2;
    /* 0x003 */ u8 unk3;
    /* 0x004 */ u16 unk4;
    /* 0x006 */ u16 unk6;
    /* 0x008 */ u16 unk8;
    /* 0x00A */ u16 unkA;
    /* 0x00C */ u16 unkC;
    /* 0x010 */ u32 unk10;
    /* 0x014 */ u8 *unk14;
    /* 0x018 */ u8 *unk18;
    /* 0x01C */ s8 *unk1C[4];
    /* 0x02C */ s8 *unk2C;
    /* 0x030 */ s8 *unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03C */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05C */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06C */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07C */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ u8 *tiles;
    /* 0x088 */ void *unk88;
    /* 0x08C */ Sprite s8C;
    /* 0x0B4 */ Sprite sB4;
    /* 0x0DC */ Sprite sDC;
    /* 0x104 */ Sprite s104;
    /* 0x12C */ Sprite s12C;
    /* 0x154 */ Sprite s154;
    /* 0x17C */ Sprite s17C;
    /* 0x1A4 */ Sprite s1A4;
    /* 0x1CC */ Sprite s1CC;
    /* 0x1F4 */ Background bg1F4;
    /* 0x234 */ Background bg234;
    /* 0x274 */ Background bg274;
} MpCharSelect; /* 0x2B4 */

void Task_809FCFC(void);
void TaskDestructor_80A13B0(struct Task *t);
void sub_809F964(MpCharSelect *mcs);
void sub_809FBD0(MpCharSelect *mcs);
void Task_809FEB0(void);
void Task_80A13F4(void);
void Task_80A14AC(void);
void sub_80A1030(MpCharSelect *mcs);
void sub_80A10B0(MpCharSelect *mcs);
void sub_80A1110(MpCharSelect *mcs);
void sub_80A11B8(MpCharSelect *mcs);
void sub_80A19C0(MpCharSelect *mcs);
void sub_80A0080(void);
void sub_80A010C(void);
void sub_80A0198(void);
void sub_80A021C(void);
void sub_80A0DC8(MpCharSelect *mcs);
void Task_80A1430(void);
bool32 sub_80A14E4(MpCharSelect *mcs);
bool32 sub_80A1540(MpCharSelect *mcs);
bool32 sub_80A1598(MpCharSelect *mcs);
bool32 sub_80A15E8(MpCharSelect *mcs);
bool32 sub_80A1694(MpCharSelect *mcs);
bool32 sub_80A1740(MpCharSelect *mcs, u8 arg1);
bool32 sub_80A1888(MpCharSelect *mcs);
bool32 sub_80A18B8(MpCharSelect *mcs);
bool32 sub_80A18E0(MpCharSelect *mcs);
void sub_80A1A04(MpCharSelect *mcs);
void sub_80A1A28(MpCharSelect *mcs);
void sub_80A0D20(void);
void sub_80A0344(void);
void sub_80A03F8(void);
void sub_80A04D8(void);
void sub_80A0644(void);
void sub_80A06E8(void);
void sub_80A07E0(void);
void sub_80A087C(void);
void sub_80A094C(void);
void sub_80A0A08(MpCharSelect *mcs);
void sub_80A0ADC(void);
void sub_80A0B9C(void);
void sub_80A0C5C(void);
void Task_80A13B4(void);
void sub_80A124C(MpCharSelect *mcs);
extern void sub_809BFE8(u8 arg0);
extern u8 gUnknown_030010AC[4];
extern const u8 gCharacterSelectOrderLUT[];
extern const u16 gAnnouncerSelect1st[];
extern const u16 gAnnouncerSelect2nd[];
bool32 sub_80A1768(MpCharSelect *mcs);
bool32 sub_80A182C(MpCharSelect *mcs);
bool32 sub_80A185C(MpCharSelect *mcs);
void sub_80A137C(MpCharSelect *mcs);
extern void sub_802613C(void);
extern const TileInfo2 gUnknown_080D8F00;
bool32 sub_80A16EC(MpCharSelect *mcs);
bool32 sub_80A1694(MpCharSelect *mcs);
bool32 sub_80A1938(MpCharSelect *mcs);
void sub_80A0EA8(MpCharSelect *mcs);
bool32 sub_80A163C(MpCharSelect *mcs);
bool32 sub_80A1668(MpCharSelect *mcs);
bool32 sub_80A1798(MpCharSelect *mcs);
bool32 sub_80A17FC(MpCharSelect *mcs);
bool32 sub_80A1908(MpCharSelect *mcs);
void Task_CallDestroy_80A1498(void);
extern void *CreateSomeTask_809BF3C(void *param0, void *param1, void *param2, void *param3, void *tiles);
extern const u16 gUnknown_080D8CDC[];

extern const TileInfo2 gUnknown_080D8D00;
extern const TileInfo2 gUnknown_080D8D08[][8];
extern const TileInfo2 gUnknown_080D8E80[];
extern const TileInfo2 gUnknown_080D8EF8;
extern const TileInfo2 gUnknown_080D8F08;
extern const TileInfo2 gUnknown_080D8F10;
extern const u8 gUnknown_080D8F18[];

void CreateCharacterSelectMultiplayer(SDC_EC *ec)
{
    MpCharSelect *mcs;
    u8 i;

    gDispCnt = 0x1541;
    mcs = TASK_DATA(TaskCreate(Task_809FCFC, sizeof(MpCharSelect), 0x100, 0, TaskDestructor_80A13B0));
    mcs->language = LOADED_SAVE->language;

    for (i = 0; i < 4; i++) {
        mcs->unk1C[i] = &ec->unkE[i];
    }

    mcs->unk30 = (s8 *)&ec->unk12;
    mcs->unk2C = &ec->unk14;
    mcs->unk18 = &ec->unk17;
    mcs->unk3 = ec->unk17;
    mcs->unk14 = &ec->unk16;
    *mcs->unk14 = 1;
    mcs->unk1 = ec->unk12;
    mcs->unk6 = 1;
    mcs->unk8 = 0;
    mcs->unk4 = 0;
    mcs->unkA = 0;
    mcs->unkC = 0x1000;
    mcs->unk4C = Q(120);
    mcs->unk50 = Q(80);
    mcs->unk54 = Q(120);
    mcs->unk58 = Q(80);
    mcs->unk34 = Q(120);
    mcs->unk38 = Q(17);
    mcs->unk3C = Q(120);
    mcs->unk40 = Q(17);
    mcs->unk44 = 0;
    mcs->unk48 = 0;
    mcs->unk7C = 0;
    mcs->unk80 = 0;
    mcs->unk6C = Q(120);
    mcs->unk70 = Q(85);
    mcs->unk74 = Q(201);
    mcs->unk78 = Q(22);
    mcs->unk5C = Q(120);
    mcs->unk60 = Q(145);
    mcs->unk64 = Q(300);
    mcs->unk68 = Q(145);
    mcs->tiles = OBJ_VRAM0;
    sub_809F964(mcs);
    sub_809FBD0(mcs);
    m4aMPlayAllStop();
    m4aSongNumStart(MUS_CHARACTER_SELECT);
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_809F964.inc", void sub_809F964(MpCharSelect *mcs))
{
    u8 *tiles = OBJ_VRAM0;

    {
        Sprite *s = &mcs->sDC;
        s->tiles = tiles;
        tiles += 45 * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D8D00.anim;
        s->variant = gUnknown_080D8D00.variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk3C);
        s->y = I(mcs->unk40);
        s->oamFlags = SPRITE_OAM_ORDER(1);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    {
        Sprite *s = &mcs->sB4;
        s->tiles = tiles;
        tiles += 50 * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D8D08[mcs->language][0].anim;
        s->variant = gUnknown_080D8D08[mcs->language][0].variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk34);
        s->y = I(mcs->unk38);
        s->oamFlags = SPRITE_OAM_ORDER(0);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    {
        Sprite *s = &mcs->s1A4;
        s->tiles = tiles;
        tiles += 4 * TILE_SIZE_4BPP;
        s->anim = 1396;
        s->variant = 5;
        s->prevVariant = -1;
        s->x = 120;
        s->y = I(mcs->unk60);
        s->oamFlags = SPRITE_OAM_ORDER(0);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    {
        Sprite *s = &mcs->s8C;
        s->tiles = tiles;
        tiles += 16 * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D8F08.anim;
        s->variant = gUnknown_080D8F08.variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk44);
        s->y = I(mcs->unk48);
        s->oamFlags = -SPRITE_OAM_ORDER(1);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    {
        Sprite *s = &mcs->s104;
        u32 idx = gUnknown_080D8F18[mcs->unk1] + (mcs->language != 0) * 8;
        s->tiles = tiles;
        tiles += 14 * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D8E80[idx].anim;
        s->variant = gUnknown_080D8E80[idx].variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk5C);
        s->y = I(mcs->unk60);
        s->oamFlags = SPRITE_OAM_ORDER(0);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    {
        Sprite *s = &mcs->s154;
        u32 idx = gUnknown_080D8F18[mcs->unk1] + (mcs->language != 0) * 8;
        s->tiles = tiles;
        tiles += 14 * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D8E80[idx].anim;
        s->variant = gUnknown_080D8E80[idx].variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk64);
        s->y = I(mcs->unk68);
        s->oamFlags = SPRITE_OAM_ORDER(0);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    {
        Sprite *s = &mcs->s12C;
        s->tiles = tiles;
        tiles += 24 * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D8EF8.anim;
        s->variant = gUnknown_080D8EF8.variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk5C);
        s->y = I(mcs->unk60);
        s->oamFlags = SPRITE_OAM_ORDER(1);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    {
        Sprite *s = &mcs->s1CC;
        s->tiles = tiles;
        tiles += 16 * TILE_SIZE_4BPP;
        s->anim = gUnknown_080D8F10.anim;
        s->variant = gUnknown_080D8F10.variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk4C);
        s->y = I(mcs->unk50);
        s->oamFlags = SPRITE_OAM_ORDER(0);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    mcs->tiles = tiles;
}
END_NONMATCH

void sub_809FBD0(MpCharSelect *mcs)
{
    gBgCntRegs[0] = 0x4E07;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;

    {
        Background *bg = &mcs->bg1F4;
        bg->graphics.dest = BG_CHAR_ADDR(1);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(14);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = gUnknown_080D8CDC[0];
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 45;
        bg->targetTilesY = 20;
        mcs->bg1F4.paletteOffset = 0;
        bg->flags = 0;
        DrawBackground(bg);
    }

    gBgCntRegs[1] = 0x30E;
    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;

    {
        Background *bg = &mcs->bg234;
        bg->graphics.dest = BG_CHAR_ADDR(3);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(3);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = gUnknown_080D8CDC[11];
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 16;
        bg->targetTilesY = 16;
        mcs->bg234.paletteOffset = 0;
        bg->flags = 1;
        DrawBackground(bg);
    }

    gBgCntRegs[2] = 0x1B89;
    gBgScrollRegs[2][0] = 0;
    gBgScrollRegs[2][1] = 0;

    {
        Background *bg = &mcs->bg274;
        bg->graphics.dest = BG_CHAR_ADDR(2);
        bg->graphics.anim = 0;
        bg->layoutVram = BG_SCREEN_ADDR(27);
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->tilemapId = gUnknown_080D8CDC[mcs->unk1 + 5];
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->targetTilesX = 16;
        bg->targetTilesY = 16;
        mcs->bg274.paletteOffset = 0;
        bg->flags = 6;
        DrawBackground(bg);
    }
}

void Task_809FCFC(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 i;

    sub_80A19C0(mcs);
    sub_80A1030(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);
    mcs->unk88 = CreateSomeTask_809BF3C(&mcs->unk1, &mcs->unk3, &mcs->unk4C, &mcs->unk50, mcs->tiles);

    gPlayers[PLAYER_1].charFlags.character = 0;
    gPlayers[PLAYER_1].charFlags.partnerIndex = PLAYER_3;
    gPlayers[PLAYER_2].charFlags.character = 0;
    gPlayers[PLAYER_2].charFlags.partnerIndex = PLAYER_4;
    gPlayers[PLAYER_3].charFlags.character = 2;
    gPlayers[PLAYER_3].charFlags.partnerIndex = PLAYER_1;
    gPlayers[PLAYER_4].charFlags.character = 2;
    gPlayers[PLAYER_4].charFlags.partnerIndex = PLAYER_2;

    for (i = 0; i < 4; i++) {
        if (gStageData.playerIndex == i) {
            gPlayers[i].charFlags.someIndex = 1;
        } else {
            gPlayers[i].charFlags.someIndex = 3;
            gPlayers[i].charFlags.padding1 = i;
        }
    }

    if (*mcs->unk18 == 35) {
        *mcs->unk18 = 29;
        mcs->unk3 = *mcs->unk18;
        mcs->unk4C = Q(310);
        mcs->unk54 = Q(310);
        gCurTask->main = Task_80A13F4;
    } else if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
    } else {
        gCurTask->main = Task_809FEB0;
    }
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__Task_809FEB0.inc", void Task_809FEB0(void))
{
}
END_NONMATCH

void sub_80A0080(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    bool32 res;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);

    if ((sub_80A15E8(mcs) == TRUE) && ((res = sub_80A1888(mcs)) == TRUE)) {
        *mcs->unk14 = res;
        gCurTask->main = Task_809FEB0;
    } else if (*mcs->unk18 == 35) {
        *mcs->unk18 = 29;
        mcs->unk3 = *mcs->unk18;
        mcs->unk4C = Q(310);
        mcs->unk54 = Q(310);
        gCurTask->main = Task_80A13F4;
    }
}

void sub_80A010C(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    bool32 res;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);

    if ((sub_80A1598(mcs) == TRUE) && ((res = sub_80A1888(mcs)) == TRUE)) {
        *mcs->unk14 = res;
        gCurTask->main = Task_809FEB0;
    } else if (*mcs->unk18 == 35) {
        *mcs->unk18 = 29;
        mcs->unk3 = *mcs->unk18;
        mcs->unk4C = Q(310);
        mcs->unk54 = Q(310);
        gCurTask->main = Task_80A13F4;
    }
}

void sub_80A0198(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 count = 0;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A1A04(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);

    if (sub_80A1694(mcs) == TRUE) {
        count = 1;
    }

    if (sub_80A1740(mcs, 120) == TRUE) {
        count++;
    }

    if (count == 2) {
        mcs->unk3 = 29;
        mcs->unk54 = Q(310);
        gCurTask->main = Task_80A1430;
    }
}

void sub_80A021C(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
    } else if (*mcs->unk18 == 13) {
        Sprite *s = &mcs->sB4;
        s->anim = gUnknown_080D8D08[0][mcs->language * 8 + 1].anim;
        s->variant = gUnknown_080D8D08[0][mcs->language * 8 + 1].variant;
        UpdateSpriteAnimation(s);
        mcs->unk6C = Q(300);
        mcs->unk4C = Q(300);
        mcs->unk2 = mcs->unk1;
        mcs->unk1 = *mcs->unk30;
        mcs->unk74 = Q(201);
        sub_80A0EA8(mcs);
        mcs->unk54 = Q(120);
        mcs->unk58 = Q(80);
        CreateSomeTask_809BF3C(&mcs->unk2, &mcs->unk3, &mcs->unk54, &mcs->unk58, mcs->unk88);
        mcs->unk3 = *mcs->unk18;
        sub_80A19C0(mcs);
        sub_80A1A04(mcs);
        sub_80A10B0(mcs);
        gCurTask->main = sub_80A0344;
    } else if (*mcs->unk18 == 2) {
        sub_80A19C0(mcs);
        sub_80A1A04(mcs);
        sub_80A10B0(mcs);
        sub_80A1110(mcs);
        *mcs->unk14 = 1;
        *mcs->unk18 = 1;
        mcs->unk3 = *mcs->unk18;
        gCurTask->main = Task_809FEB0;
    } else {
        sub_80A19C0(mcs);
        sub_80A1A04(mcs);
        sub_80A10B0(mcs);
        sub_80A1110(mcs);
    }
}

void sub_80A0344(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 count = 0;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A1A04(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);

    if (sub_80A1798(mcs) == TRUE) {
        count = 1;
    }
    if (sub_80A17FC(mcs) == TRUE) {
        count++;
    }
    if (sub_80A1668(mcs) == TRUE) {
        count++;
    }
    if (sub_80A163C(mcs) == TRUE) {
        count++;
    }

    mcs->unk5C = mcs->unk54;
    mcs->unk64 = mcs->unk4C;

    if (count == 4 && sub_80A1908(mcs) == TRUE) {
        *mcs->unk18 = 14;
        mcs->unk3 = *mcs->unk18;
        gCurTask->main = sub_80A03F8;
    }
}

void sub_80A03F8(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 count = 0;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A1A04(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);

    if (mcs->unk3 == *mcs->unk18) {
        if (sub_80A1798(mcs) == TRUE) {
            count = 1;
        }
        if (sub_80A17FC(mcs) == TRUE) {
            count++;
        }
        if (sub_80A1668(mcs) == TRUE) {
            count++;
        }
        if (sub_80A163C(mcs) == TRUE) {
            count++;
        }
        if (sub_80A1908(mcs) == TRUE) {
            count++;
        }

        if (count == 5) {
            mcs->unk3 = *mcs->unk18;
            *mcs->unk14 = 1;
            mcs->unk74 = Q(261);
            mcs->unk7C = Q(120);
            mcs->unk6C = Q(180);
            mcs->unk54 = Q(60);
            mcs->unk4C = Q(180);
            mcs->unk68 = Q(145);
            gCurTask->main = sub_80A0644;
        }
    }
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A04D8.inc", void sub_80A04D8(void))
{
}
END_NONMATCH

void sub_80A0644(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 count = 0;
    bool32 res;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A1A04(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);

    if (sub_80A16EC(mcs) == TRUE) {
        count = 1;
    }

    if ((mcs->unk68 <= Q(145)) || ((mcs->unk68 -= Q(6)) < Q(145))) {
        mcs->unk68 = Q(145);
        res = TRUE;
    } else {
        res = FALSE;
    }

    if (res == TRUE) {
        count++;
    }

    if (count == 2) {
        *mcs->unk14 = 1;
        gCurTask->main = sub_80A04D8;
    }
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A06E8.inc", void sub_80A06E8(void))
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
    } else {
        gBgSprites_Unknown1[2] = 0;
        gBgSprites_Unknown2[2][0] = 0;
        gBgSprites_Unknown2[2][1] = 0;
        gBgSprites_Unknown2[2][2] = 0xFF;
        gBgSprites_Unknown2[2][3] = 0x40;
        mcs->unk6C = Q(142);
        mcs->unk70 = Q(22);
        gBgScrollRegs[2][0] = 142;
        gBgScrollRegs[2][1] = -22;
        gDispCnt = 0x1740;
        gBgCntRegs[2] = 0x1B09;

        {
            Background *bg = &mcs->bg274;
            bg->graphics.dest = BG_CHAR_ADDR(2);
            bg->graphics.anim = 0;
            bg->layoutVram = BG_SCREEN_ADDR(27);
            bg->unk18 = 0;
            bg->unk1A = 0;
            bg->tilemapId = gUnknown_080D8CDC[gUnknown_080D8F18[mcs->unk1] + 10];
            bg->unk1E = 0;
            bg->unk20 = 0;
            bg->unk22 = 0;
            bg->unk24 = 0;
            bg->targetTilesX = 16;
            bg->targetTilesY = 16;
            mcs->bg274.paletteOffset = 0;
            bg->flags = 2;
            DrawBackground(bg);
        }

        sub_80A10B0(mcs);
        sub_80A1110(mcs);
        sub_80A11B8(mcs);
        gCurTask->main = sub_80A07E0;
    }
}
END_NONMATCH

void sub_80A07E0(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 count = 0;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A137C(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);

    if (sub_80A1740(mcs, 90) == TRUE) {
        count = 1;
    }
    if (sub_80A1768(mcs) == TRUE) {
        count++;
    }
    if (sub_80A185C(mcs) == TRUE) {
        count++;
    }
    if (sub_80A182C(mcs) == TRUE) {
        count++;
    }

    mcs->unk5C = mcs->unk54;
    mcs->unk64 = mcs->unk4C + 5;

    if (count == 4) {
        gCurTask->main = sub_80A087C;
    }
}

void sub_80A087C(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A1A04(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);

    if (mcs->unk6 != 0) {
        gDispCnt |= DISPCNT_WIN0_ON;
        gWinRegs[WINREG_WIN0H] = DISPLAY_WIDTH;
        gWinRegs[WINREG_WIN0V] = DISPLAY_HEIGHT;
        gWinRegs[WINREG_WININ] |= 0x3F;
        gWinRegs[WINREG_WINOUT] |= 0x1F;
        gBldRegs.bldCnt = 0x3FBF;
        gBldRegs.bldY = 0;
        mcs->unk6 = 0;
        mcs->unk8 = 0;
    }

    if (gBldRegs.bldY < 16) {
        gBldRegs.bldY = mcs->unk8 >> 8;
        mcs->unk8 += Q(1);
    } else {
        gBldRegs.bldY = 16;
        *mcs->unk18 = 22;
        mcs->unk3 = *mcs->unk18;
        mcs->unk6 = 1;
        gCurTask->main = sub_80A094C;
    }
}

void sub_80A094C(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
    } else {
        gDispCnt = 0x1541;
        gBgCntRegs[2] = 0x1B89;
        gBgScrollRegs[2][0] = 0;
        gBgScrollRegs[2][1] = 0;
        mcs->unk6C = Q(120);
        mcs->unk70 = Q(85);

        {
            Background *bg = &mcs->bg274;
            bg->graphics.dest = BG_CHAR_ADDR(2);
            bg->graphics.anim = 0;
            bg->layoutVram = BG_SCREEN_ADDR(27);
            bg->unk18 = 0;
            bg->unk1A = 0;
            bg->tilemapId = gUnknown_080D8CDC[15];
            bg->unk1E = 0;
            bg->unk20 = 0;
            bg->unk22 = 0;
            bg->unk24 = 0;
            bg->targetTilesX = 16;
            bg->targetTilesY = 16;
            mcs->bg274.paletteOffset = 0;
            bg->flags = 6;
            DrawBackground(bg);
        }

        sub_80A0A08(mcs);
        gCurTask->main = sub_80A0ADC;
    }
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A0A08.inc", void sub_80A0A08(MpCharSelect *mcs))
{
    Sprite *s;
    u32 a, b;

    {
        Sprite *s = &mcs->s12C;
        s->anim = gUnknown_080D8F00.anim;
        s->variant = gUnknown_080D8F00.variant;
        s->prevVariant = -1;
        s->x = I(mcs->unk5C);
        s->y = I(mcs->unk60);
        s->oamFlags = SPRITE_OAM_ORDER(1);
        s->animCursor = 0;
        s->qAnimDelay = 0;
        s->animSpeed = SPRITE_ANIM_SPEED(1.0);
        s->palId = 0;
        s->frameFlags = 0;
        UpdateSpriteAnimation(s);
    }

    s = &mcs->sB4;
    a = gUnknown_080D8F18[mcs->unk2];
    b = gUnknown_080D8F18[mcs->unk1];

    if (a > 4 || b > 4) {
        sub_802613C();
    }

    if (a == 0 || b == 0) {
        if (a == 2 || b == 2) {
            a = 4;
        } else if (a == 3 || b == 3) {
            a = 6;
        } else if (a == 4 || b == 4) {
            a = 3;
        } else {
            a = 2;
        }
    } else if ((a == 4 && b == 1) || (a == 1 && b == 4)) {
        a = 5;
    } else {
        a = 2;
    }

    s->anim = gUnknown_080D8D08[0][a + mcs->language * 8].anim;
    s->variant = gUnknown_080D8D08[0][a + mcs->language * 8].variant;
    UpdateSpriteAnimation(s);
}
END_NONMATCH

void sub_80A0ADC(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A10B0(mcs);
    sub_80A124C(mcs);

    if (mcs->unk6 != 0) {
        gDispCnt |= DISPCNT_WIN0_ON;
        gWinRegs[WINREG_WIN0H] = DISPLAY_WIDTH;
        gWinRegs[WINREG_WIN0V] = DISPLAY_HEIGHT;
        gWinRegs[WINREG_WININ] |= 0x3F;
        gWinRegs[WINREG_WINOUT] |= 0x1F;
        gBldRegs.bldCnt = 0x3FBF;
        gBldRegs.bldY = 16;
        mcs->unk8 = 0x1000;
        mcs->unk6 = 0;
    }

    if (gBldRegs.bldY != 0) {
        gBldRegs.bldY = mcs->unk8 >> 8;
        mcs->unk8 -= Q(1);
    } else {
        mcs->unk6 = 1;
        gBldRegs.bldY = 0;
        gCurTask->main = sub_80A0B9C;
    }
}

void sub_80A0B9C(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 char2 = gUnknown_080D8F18[mcs->unk2];
    u8 char1 = gUnknown_080D8F18[mcs->unk1];

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A10B0(mcs);
    sub_80A124C(mcs);

    if (mcs->unk4 == 0) {
        m4aSongNumStart(gAnnouncerSelect1st[gCharacterSelectOrderLUT[char2]]);
    } else if (mcs->unk4 == 60) {
        m4aSongNumStart(511);
    } else if (mcs->unk4 == 90) {
        m4aSongNumStart(gAnnouncerSelect2nd[gCharacterSelectOrderLUT[char1]]);
    }

    if (++mcs->unk4 > 119) {
        gCurTask->main = sub_80A0C5C;
    }
}

void sub_80A0C5C(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A10B0(mcs);
    sub_80A124C(mcs);

    if (mcs->unk6 != 0) {
        gDispCnt |= DISPCNT_WIN0_ON;
        gWinRegs[WINREG_WIN0H] = DISPLAY_WIDTH;
        gWinRegs[WINREG_WIN0V] = DISPLAY_HEIGHT;
        gWinRegs[WINREG_WININ] |= 0x3F;
        gWinRegs[WINREG_WINOUT] |= 0x1F;
        gBldRegs.bldCnt = 0x3FFF;
        mcs->unk6 = 0;
        mcs->unk8 = 0;
    }

    if (gBldRegs.bldY < 16) {
        gBldRegs.bldY = mcs->unk8 >> 8;
        mcs->unk8 += Q(1);
    } else {
        gBldRegs.bldY = 16;
        mcs->unk4C = Q(310);
        mcs->unk54 = Q(310);
        mcs->unk3 = 29;
        *mcs->unk18 = 29;
        mcs->unk4 = 0;
        gCurTask->main = Task_80A13B4;
    }
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A0D20.inc", void sub_80A0D20(void))
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 i;

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    for (i = 0; i < 4; i++) {
        gPlayers[i].charFlags.character = gUnknown_030010AC[i];
    }

    TasksDestroyAll();
    gBackgroundsCopyQueueCursor = gBackgroundsCopyQueueIndex;
    gBgSpritesCount = 0;
    gVramGraphicsCopyCursor = gVramGraphicsCopyQueueIndex;
    sub_809BFE8(0);
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A0DC8.inc", void sub_80A0DC8(MpCharSelect *mcs))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A0EA8.inc", void sub_80A0EA8(MpCharSelect *mcs))
{
}
END_NONMATCH

void sub_80A1030(MpCharSelect *mcs)
{
    Sprite *s = &mcs->s8C;
    u32 n = 2;
    s32 x;
    s32 left, right;
    u8 i;

    x = (*mcs->unk18 > 13) ? 180 : 120;

    for (i = 0, left = x - 40, right = x + 40; i < n; i++) {
        if (i != 0) {
            s->x = left - I(mcs->unk44);
        } else {
            s->x = right + I(mcs->unk44);
        }
        s->y = I(mcs->unk48);

        if (i != 0) {
            s->frameFlags |= SPRITE_FLAG_MASK_X_FLIP;
        } else {
            s->frameFlags &= ~SPRITE_FLAG_MASK_X_FLIP;
        }
        DisplaySprite(s);
    }
}

void sub_80A10B0(MpCharSelect *mcs)
{
    Sprite *s;
    u8 i;

    for (i = 0, s = &mcs->sDC; i < 2; i++) {
        s->x = I(mcs->unk3C);
        s->y = I(mcs->unk40);

        if (i != 0) {
            s->frameFlags &= ~SPRITE_FLAG_MASK_X_FLIP;
        } else {
            s->frameFlags |= SPRITE_FLAG_MASK_X_FLIP;
        }
        DisplaySprite(s);
    }

    s = &mcs->sB4;
    s->x = I(mcs->unk34);
    s->y = I(mcs->unk38);
    DisplaySprite(s);
}

void sub_80A1110(MpCharSelect *mcs)
{
    Sprite *s;
    u8 i;
    u8 character;
    u32 lang;

    for (i = 0, s = &mcs->s12C; i < 2; i++) {
        s->x = I(mcs->unk5C);
        s->y = I(mcs->unk60);
        s->palId = 0;

        if (i != 0) {
            s->frameFlags |= SPRITE_FLAG_MASK_X_FLIP;
        } else {
            s->frameFlags &= ~SPRITE_FLAG_MASK_X_FLIP;
        }
        DisplaySprite(s);
    }

    lang = (mcs->language != 0);
    if (*mcs->unk18 > 12) {
        character = gUnknown_080D8F18[mcs->unk2];
    } else {
        character = gUnknown_080D8F18[mcs->unk1];
    }

    s = &mcs->s104;
    {
        s->anim = gUnknown_080D8E80[character + lang * 8].anim;
        s->variant = gUnknown_080D8E80[character + lang * 8].variant;
    }
    s->x = I(mcs->unk5C);
    s->y = I(mcs->unk60);
    UpdateSpriteAnimation(s);
    DisplaySprite(s);
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A11B8.inc", void sub_80A11B8(MpCharSelect *mcs))
{
    Sprite *s;
    u8 i;
    u32 lang;

    for (i = 0, s = &mcs->s12C; i < 2; i++) {
        s->x = I(mcs->unk64);
        s->y = I(mcs->unk68);
        s->palId = 1;

        if (i != 0) {
            s->frameFlags |= SPRITE_FLAG_MASK_X_FLIP;
        } else {
            s->frameFlags &= ~SPRITE_FLAG_MASK_X_FLIP;
        }
        DisplaySprite(s);
    }

    lang = (mcs->language != 0);
    {
        u8 idx = gUnknown_080D8F18[mcs->unk1];
        Sprite *s2 = &mcs->s154;
        const TileInfo2 *ti = &gUnknown_080D8E80[lang * 8 + idx];
        s2->anim = ti->anim;
        s2->variant = ti->variant;
        s2->x = I(mcs->unk64);
        s2->y = I(mcs->unk68);
        UpdateSpriteAnimation(s2);
        DisplaySprite(s2);
    }
}
END_NONMATCH

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A124C.inc", void sub_80A124C(MpCharSelect *mcs))
{
}
END_NONMATCH

void sub_80A137C(MpCharSelect *mcs)
{
    gBgScrollRegs[1][0] = I(mcs->unk74);
    gBgScrollRegs[1][1] = -I(mcs->unk78);
    gBgScrollRegs[0][0] = I(mcs->unk7C);
    gBgScrollRegs[0][1] = I(mcs->unk80);
    gBgScrollRegs[2][0] = I(mcs->unk6C);
    gBgScrollRegs[2][1] = -I(mcs->unk70);
}

void TaskDestructor_80A13B0(struct Task *t)
{
}

void Task_80A13B4(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 *p = mcs->unk18;

    if (*p == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    if (mcs->unk3 == 37) {
        *p = 38;
        gCurTask->main = sub_80A0D20;
    }
}

void Task_80A13F4(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);
    u8 *p = mcs->unk18;

    if (*p == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    if (mcs->unk3 == 37) {
        *p = 38;
        TaskDestroy(gCurTask);
    }
}

void Task_80A1430(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    if (*mcs->unk18 == 34) {
        gCurTask->main = Task_80A14AC;
        return;
    }

    sub_80A19C0(mcs);
    sub_80A1A04(mcs);
    sub_80A10B0(mcs);
    sub_80A1110(mcs);
    sub_80A11B8(mcs);
    mcs->unk4C = Q(120);
    *mcs->unk14 = 1;
    *mcs->unk18 = 1;
    mcs->unk3 = *mcs->unk18;
    gCurTask->main = Task_809FEB0;
}

void Task_CallDestroy_80A1498(void)
{
    TaskDestroy(gCurTask);
}

void Task_80A14AC(void)
{
    MpCharSelect *mcs = TASK_DATA(gCurTask);

    mcs->unk4C = Q(310);
    mcs->unk54 = Q(310);
    mcs->unk3 = 29;
    *mcs->unk18 = 29;
    mcs->unk4 = 0;
    gCurTask->main = Task_CallDestroy_80A1498;
}

bool32 sub_80A14E4(MpCharSelect *mcs)
{
    u8 count = 0;

    if ((mcs->unk4C >= Q(300)) || ((mcs->unk4C += 0xE00) >= Q(300))) {
        do {
            mcs->unk4C = Q(300);
            count = 1;
        } while (0);
    }

    if ((mcs->unk6C >= Q(330)) || ((mcs->unk6C += 0xE00) >= Q(330))) {
        mcs->unk6C = -Q(60);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

bool32 sub_80A1540(MpCharSelect *mcs)
{
    u8 count = 0;

    if ((mcs->unk4C <= -Q(60)) || ((mcs->unk4C += -0xE00) <= -Q(60))) {
        mcs->unk4C = -Q(60);
        count = 1;
    }

    if ((mcs->unk6C <= -Q(90)) || ((mcs->unk6C += -0xE00) <= -Q(90))) {
        mcs->unk6C = Q(300);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A1598.inc", bool32 sub_80A1598(MpCharSelect *mcs))
{
    u8 count = 0;

    if ((mcs->unk4C <= Q(120)) || ((mcs->unk4C += -0xE00) <= Q(120))) {
        mcs->unk4C = Q(120);
        count = 1;
    }

    if ((mcs->unk6C <= Q(120)) || ((mcs->unk6C += -0xE00) <= Q(120))) {
        mcs->unk6C = Q(120);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}
END_NONMATCH

bool32 sub_80A15E8(MpCharSelect *mcs)
{
    u8 count = 0;
    s32 lim = 120;

    if ((mcs->unk4C >= Q(120)) || ((mcs->unk4C += 0xE00) >= Q(120))) {
        mcs->unk4C = Q(120);
        count = 1;
    }

    if ((mcs->unk6C >= Q(lim)) || ((mcs->unk6C += 0xE00) >= Q(lim))) {
        mcs->unk6C = Q(lim);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

bool32 sub_80A163C(MpCharSelect *mcs)
{
    if ((mcs->unk4C <= Q(180)) || ((mcs->unk4C -= 0x8C0) < 180)) {
        mcs->unk4C = Q(180);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A1668(MpCharSelect *mcs)
{
    if ((mcs->unk54 <= Q(60)) || ((mcs->unk54 -= 0x8C0) < 60)) {
        mcs->unk54 = Q(60);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A1694(MpCharSelect *mcs)
{
    u8 count = 0;

    if ((mcs->unk4C >= Q(300)) || ((mcs->unk4C += 0x8C0) >= Q(300))) {
        do {
            mcs->unk4C = Q(300);
            count = 1;
        } while (0);
    }

    if ((mcs->unk6C >= Q(300)) || ((mcs->unk6C += 0x840) >= Q(300))) {
        mcs->unk6C = Q(300);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

bool32 sub_80A16EC(MpCharSelect *mcs)
{
    u8 count = 0;

    if ((mcs->unk4C <= Q(180)) || ((mcs->unk4C += -0x8C0) <= Q(180))) {
        mcs->unk4C = Q(180);
        count = 1;
    }

    if ((mcs->unk6C <= Q(180)) || ((mcs->unk6C += -0x840) <= Q(180))) {
        mcs->unk6C = Q(180);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

bool32 sub_80A1740(MpCharSelect *mcs, u8 arg1)
{
    if ((mcs->unk54 >= Q(arg1)) || ((mcs->unk54 += 0x300) > Q(arg1))) {
        mcs->unk54 = Q(arg1);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A1768(MpCharSelect *mcs)
{
    if ((mcs->unk4C <= Q(150)) || ((mcs->unk4C -= 0x300) < Q(150))) {
        mcs->unk4C = Q(150);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A1798(MpCharSelect *mcs)
{
    u8 count = 0;

    if ((mcs->unk74 >= Q(261)) || ((mcs->unk74 += 0x600) >= Q(261))) {
        mcs->unk74 = Q(261);
        count = 1;
    }

    if (mcs->unk7C < Q(120)) {
        mcs->unk7C += 0x7E0;
        if (mcs->unk7C > Q(120)) {
            mcs->unk7C = Q(120);
            count++;
        }
    } else {
        mcs->unk7C = Q(120);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

bool32 sub_80A17FC(MpCharSelect *mcs)
{
    if ((mcs->unk6C <= Q(180)) || ((mcs->unk6C -= 0x840) < Q(180))) {
        mcs->unk6C = Q(180);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A182C(MpCharSelect *mcs)
{
    s32 speed = 3;

    if ((mcs->unk6C >= Q(201)) || ((mcs->unk6C += Q(speed)) >= Q(201))) {
        mcs->unk6C = Q(201);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A185C(MpCharSelect *mcs)
{
    if ((mcs->unk74 <= Q(201)) || ((mcs->unk74 -= 0x300) <= Q(201))) {
        mcs->unk74 = Q(201);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A1888(MpCharSelect *mcs)
{
    if (mcs->unk60 <= Q(145)) {
        mcs->unk60 = Q(145);
        return TRUE;
    }

    mcs->unk60 -= Q(6);
    if (mcs->unk60 < Q(145)) {
        mcs->unk60 = Q(145);
    }

    return FALSE;
}

bool32 sub_80A18B8(MpCharSelect *mcs)
{
    if (mcs->unk60 < Q(180)) {
        mcs->unk60 += Q(6);
        return FALSE;
    }

    mcs->unk60 = Q(180);
    return TRUE;
}

bool32 sub_80A18E0(MpCharSelect *mcs)
{
    if (mcs->unk44 < Q(5)) {
        mcs->unk44 += 0x40;
    } else {
        mcs->unk44 = 0;
    }

    mcs->unk48 = Q(90);
    return TRUE;
}

bool32 sub_80A1908(MpCharSelect *mcs)
{
    if ((mcs->unk68 <= Q(145)) || ((mcs->unk68 -= Q(6)) < Q(145))) {
        mcs->unk68 = Q(145);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A1938(MpCharSelect *mcs)
{
    if ((mcs->unk68 >= Q(180)) || ((mcs->unk68 += Q(6)) >= Q(180))) {
        mcs->unk68 = Q(180);
        return TRUE;
    }

    return FALSE;
}

bool32 sub_80A1968(MpCharSelect *mcs)
{
    u8 count = 0;

    if ((mcs->unk5C >= Q(120)) || ((mcs->unk5C += Q(3)) >= Q(120))) {
        mcs->unk5C = Q(120);
        count = 1;
    }

    if ((mcs->unk64 <= Q(120)) || ((mcs->unk64 -= Q(3)) <= Q(120))) {
        mcs->unk64 = Q(120);
        count++;
    }

    if (count == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void sub_80A19C0(MpCharSelect *mcs)
{
    mcs->unkA += 0xC0;
    SA2_LABEL(sub_8003EE4)(mcs->unkA >> 6, (s16)mcs->unkC >> 4, 0x100, 0x40, 0x40, I(mcs->unk6C), I(mcs->unk70), &gBgAffineRegs[0]);
}

void sub_80A1A04(MpCharSelect *mcs)
{
    gBgScrollRegs[1][0] = I(mcs->unk74);
    gBgScrollRegs[1][1] = -I(mcs->unk78);
    gBgScrollRegs[0][0] = I(mcs->unk7C);
    gBgScrollRegs[0][1] = I(mcs->unk80);
}

NONMATCH("asm/non_matching/game/sa3/multiplayer/mpcs__sub_80A1A28.inc", void sub_80A1A28(MpCharSelect *mcs))
{
    Sprite *s = &mcs->s1CC;
    s->x = I(mcs->unk4C);
    s->y = I(mcs->unk50);
    DisplaySprite(s);
}
END_NONMATCH
