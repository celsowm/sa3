#include "global.h"
#include "core.h"
#include "game/stage.h"
#include "game/game_over.h"
#include "constants/songs.h"

void Task_8029648(void);
void TaskDestructor_8029774(Task *t);

// Raw IWRAM buffers referenced by the original SIO Thumb routines.
extern u8 gUnknown_03001060[];
extern u8 gUnknown_030010AC[];
extern u8 gUnknown_03001CC0[];

void sub_8024334(void);
void sub_8025BC0(void);
void sub_80287CC(void);
s16 sub_8025E24(u8 id);
s16 sub_802610C(void);
s16 sub_8025D58(void);
void sub_8024304(void);
void sub_8024394(u8 player, u8 value);
void sub_80243C4(u8 player, u8 value);
void sub_80243B4(void);
void sub_80243E4(u8 value);
void MultiSio_SendPlayerName(void);
void sub_8025770(void);
void sub_8025D00(void);
void sub_8025D48(void);
void sub_80260F0(void);

NONMATCH("asm/non_matching/sio/sio__sub_8023A88.inc", void sub_8023A88(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023BB0.inc", void sub_8023BB0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023C5C.inc", void sub_8023C5C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023D60.inc", void sub_8023D60(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023E04.inc", void sub_8023E04(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023E80.inc", void sub_8023E80(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023EFC.inc", void sub_8023EFC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023F60.inc", void sub_8023F60(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8023FE0.inc", void sub_8023FE0(void))
{
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_8024040.inc", s16 sub_8024040(void))
{
    s16 result = (u16)sub_8025D58();
    sub_8024304();
    gUnknown_03001060[7] = 0;
    return result;
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024068.inc", void sub_8024068(void))
{
    sub_8024334();
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024074.inc", void sub_8024074(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80240B4.inc", void sub_80240B4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80240F4.inc", void sub_80240F4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024130.inc", void sub_8024130(void))
{
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_8024188.inc", s16 sub_8024188(u8 value))
{
    s16 result = sub_802610C();
    if (result >= 0) {
        sub_8024394(1, value);
        return 0;
    }
    return result;
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_80241AC.inc", s16 sub_80241AC(u8 value))
{
    s16 result = sub_802610C();
    s16 response = 0;
    u16 type;

    if (result < 0) {
        return result;
    }
    if (gMultiSioStatusFlags & 0x0C0C) {
        return -4;
    }

    type = *(u16 *)&gMultiSioRecv[0].raw[0];
    if (type == 0x6C08 || type == 0x6C0B) {
        response = 0x10;
    }
    sub_80243C4(1, value);
    return response;
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_8024208.inc", s16 sub_8024208(void))
{
    s16 result = sub_802610C();
    s16 response = 0;

    if (result < 0) {
        return result;
    }
    if (gMultiSioStatusFlags & 0x0C0C) {
        return -4;
    }
    if (*(u16 *)&gMultiSioRecv[0].raw[0] == 0x6C0A) {
        response = 0x10;
    }
    sub_80243B4();
    return response;
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_8024254.inc", s16 sub_8024254(u8 value))
{
    s16 result = sub_802610C();
    if (result < 0) {
        return result;
    }
    if (gMultiSioStatusFlags & 0x0C0C) {
        return -4;
    }
    if (gMultiSioStatusFlags & 2) {
        sub_80243E4(value);
    }
    return 0;
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024298.inc", void sub_8024298(void))
{
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024304.inc", void sub_8024304(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0;
    gMultiSioSend.raw[2] = 0;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024314.inc", void sub_8024314(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C01;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024324.inc", void sub_8024324(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C02;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024334.inc", void sub_8024334(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C03;
    gMultiSioSend.raw[4] = 0;
    gMultiSioSend.raw[3] = 0;
    gMultiSioSend.raw[5] = 0xFF;
    gMultiSioSend.raw[6] = 0xFF;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024354.inc", void sub_8024354(u8 player, u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C03;
    gMultiSioSend.raw[4] = value;
    gMultiSioSend.raw[5 + player] = value;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024374.inc", void sub_8024374(u8 player, u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C04;
    gMultiSioSend.raw[4] = value;
    gMultiSioSend.raw[5 + player] = value;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8024394.inc", void sub_8024394(u8 player, u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C07;
    gMultiSioSend.raw[4] = value;
    gMultiSioSend.raw[5 + player] = value;
}
END_NONMATCH

// C reconstruction from the original Thumb instructions; ASM remains the matching fallback.
NONMATCH("asm/non_matching/sio/sio__sub_80243B4.inc", void sub_80243B4(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C0A;
}
END_NONMATCH

// C reconstruction from the original Thumb instructions; ASM remains the matching fallback.
NONMATCH("asm/non_matching/sio/sio__sub_80243C4.inc", void sub_80243C4(u8 player, u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C08;
    gMultiSioSend.raw[4] = value;
    gMultiSioSend.raw[5 + player] = value;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_80243E4.inc", void sub_80243E4(u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C0B;
    gMultiSioSend.raw[7] = value;
}
END_NONMATCH

// Reconstructed from Thumb; retain the original assembly for matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_80243F8.inc", void sub_80243F8(u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6C0C;
    gMultiSioSend.raw[7] = value;
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_802440C.inc", void sub_802440C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80244E4.inc", void sub_80244E4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024584.inc", void sub_8024584(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80246B4.inc", void sub_80246B4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80247D4.inc", void sub_80247D4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80248F4.inc", void sub_80248F4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024984.inc", void sub_8024984(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024A4C.inc", void sub_8024A4C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024AC0.inc", void sub_8024AC0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024B84.inc", void sub_8024B84(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024C68.inc", void sub_8024C68(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024DC8.inc", void sub_8024DC8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024E1C.inc", void sub_8024E1C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024F1C.inc", void sub_8024F1C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8024F84.inc", void sub_8024F84(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025024.inc", void sub_8025024(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80250EC.inc", void sub_80250EC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80251F8.inc", void sub_80251F8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80252E8.inc", void sub_80252E8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025360.inc", void sub_8025360(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80253CC.inc", void sub_80253CC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025460.inc", void sub_8025460(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80254CC.inc", void sub_80254CC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025534.inc", void sub_8025534(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80255B0.inc", void sub_80255B0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025614.inc", void sub_8025614(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025674.inc", void sub_8025674(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__MultiSio_SendPlayerName.inc", void MultiSio_SendPlayerName(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025714.inc", void sub_8025714(void))
{
}
END_NONMATCH

// C reconstruction of packet assembly; binary matching not yet established.
NONMATCH("asm/non_matching/sio/sio__sub_8025770.inc", void sub_8025770(void))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gStageData.playerIndex = id;
    gMultiSioSend.raw[3] = id;
    *(u16 *)&gMultiSioSend.raw[0] = 0x6606;
    gMultiSioSend.raw[15] = gUnknown_03001060[0x4C];
    gMultiSioSend.raw[16] = gUnknown_03001060[0x4D];
}
END_NONMATCH

// C reconstruction of packet assembly; binary matching not yet established.
NONMATCH("asm/non_matching/sio/sio__sub_80257AC.inc", void sub_80257AC(u8 value))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gStageData.playerIndex = id;
    gMultiSioSend.raw[15] = gUnknown_03001060[0x4C];
    gMultiSioSend.raw[16] = gUnknown_03001060[0x4D];
    if (id <= 1) {
        id += 2;
    }
    gMultiSioSend.raw[15 + id] = 0xFF;
    *(u16 *)&gMultiSioSend.raw[0] = 0x6607;
    gMultiSioSend.raw[3] = id;
    gMultiSioSend.raw[4] = value;
}
END_NONMATCH

// C reconstruction of packet assembly; binary matching not yet established.
NONMATCH("asm/non_matching/sio/sio__sub_8025808.inc", void sub_8025808(u8 value))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    u8 i;
    gStageData.playerIndex = id;
    if (id <= 1 && !(gUnknown_03001060[7] & (4 << id))) {
        id += 2;
    }
    *(u16 *)&gMultiSioSend.raw[0] = 0x6607;
    gMultiSioSend.raw[3] = id;
    for (i = 0; i < 4; i++) {
        gMultiSioSend.raw[15 + i] = gUnknown_030010AC[i];
    }
    gMultiSioSend.raw[4] = value;
}
END_NONMATCH

// C reconstruction of packet assembly; binary matching not yet established.
NONMATCH("asm/non_matching/sio/sio__sub_8025874.inc", void sub_8025874(u8 value))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gStageData.playerIndex = id;
    if (id <= 1 && !(gUnknown_03001060[7] & (4 << id))) {
        id += 2;
    }
    *(u16 *)&gMultiSioSend.raw[0] = 0x6608;
    gMultiSioSend.raw[3] = id;
    if (id > 1) {
        gMultiSioSend.raw[15 + id] = gUnknown_03001060[0x4C + id];
    }
    gMultiSioSend.raw[4] = value;
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_80258D4.inc", s16 sub_80258D4(void))
{
    s16 result = (u16)sub_8025D58();
    MultiSio_SendPlayerName();
    gUnknown_03001060[7] = 0;
    return result;
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_80258FC.inc", void sub_80258FC(void))
{
    sub_8025BC0();
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025908.inc", void sub_8025908(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025948.inc", void sub_8025948(void))
{
}
END_NONMATCH

// Verified against the Thumb control flow; retain ASM until agbcc/ROM matching.
NONMATCH("asm/non_matching/sio/sio__sub_8025998.inc", s16 sub_8025998(void))
{
    u8 status = gUnknown_03001060[7];
    s16 result = sub_802610C();
    u16 packetType;

    if (result < 0) {
        return result;
    }
    sub_8025770();
    if (status != 3 && status != 7 && status != 15) {
        return 0;
    }

    gUnknown_03001060[0x4D] = gMultiSioRecv[1].raw[4];
    packetType = *(u16 *)&gMultiSioRecv[1].raw[0];
    if (packetType == 0x6606 || packetType == 0x6607) {
        return 1;
    }
    return 0;
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_80259EC.inc", void sub_80259EC(void))
{
    sub_8025BC0();
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80259F8.inc", void sub_80259F8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025A38.inc", void sub_8025A38(void))
{
}
END_NONMATCH

// Verified against the Thumb control flow; retain ASM until agbcc/ROM matching.
NONMATCH("asm/non_matching/sio/sio__sub_8025A90.inc", s16 sub_8025A90(void))
{
    s16 result = sub_802610C();
    if (result < 0) {
        return result;
    }
    sub_8025D00();
    return 0;
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025AA8.inc", void sub_8025AA8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025AFC.inc", void sub_8025AFC(void))
{
}
END_NONMATCH

// Verified against the Thumb control flow; retain ASM until agbcc/ROM matching.
NONMATCH("asm/non_matching/sio/sio__sub_8025B48.inc", s16 sub_8025B48(void))
{
    s16 result = sub_802610C();
    if (result < 0) {
        return result;
    }
    sub_8025D48();
    return *(u16 *)&gMultiSioRecv[0].raw[0] > 0x660F;
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025B78.inc", void sub_8025B78(void))
{
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025BA0.inc", void sub_8025BA0(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6601;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025BB0.inc", void sub_8025BB0(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6602;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025BC0.inc", void sub_8025BC0(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x6603;
    gMultiSioSend.raw[3] = 0;
    gMultiSioSend.raw[4] = 0;
    *(u16 *)&gMultiSioSend.raw[6] = 0;
    *(u32 *)&gMultiSioSend.raw[8] = 0;
    *(u16 *)&gMultiSioSend.raw[12] = 0;
    gMultiSioSend.raw[15] = 0xFF;
    gMultiSioSend.raw[16] = 0xFF;
    gMultiSioSend.raw[17] = 0xFF;
    gMultiSioSend.raw[18] = 0xFF;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025BEC.inc", void sub_8025BEC(u8 value))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gStageData.playerIndex = id;
    *(u16 *)&gMultiSioSend.raw[0] = 0x6603;
    gMultiSioSend.raw[3] = id;
    gMultiSioSend.raw[15 + id] = 0xFF;
    gMultiSioSend.raw[4] = value;
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8025C20.inc", void sub_8025C20(u8 value))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gStageData.playerIndex = id;
    *(u16 *)&gMultiSioSend.raw[0] = 0x6603;
    gMultiSioSend.raw[3] = id;
    gMultiSioSend.raw[15 + id] = gUnknown_03001060[0x4C + id];
    gMultiSioSend.raw[4] = value;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025C64.inc", void sub_8025C64(u8 value))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gStageData.playerIndex = id;
    *(u16 *)&gMultiSioSend.raw[0] = 0x6605;
    gMultiSioSend.raw[3] = id;
    gMultiSioSend.raw[4] = value;
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025C8C.inc", void sub_8025C8C(void))
{
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025CD8.inc", void sub_8025CD8(void))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gStageData.playerIndex = id;
    gMultiSioSend.raw[3] = id;
    *(u16 *)&gMultiSioSend.raw[0] = 0x660A;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025D00.inc", void sub_8025D00(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x660B;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025D10.inc", void sub_8025D10(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x660C;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025D20.inc", void sub_8025D20(u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x660D;
    gMultiSioSend.raw[5] = value;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025D34.inc", void sub_8025D34(u8 value))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x660E;
    gMultiSioSend.raw[5] = value;
}
END_NONMATCH

// C reconstruction from the European ROM Thumb routine; matching builds retain ASM.
NONMATCH("asm/non_matching/sio/sio__sub_8025D48.inc", void sub_8025D48(void))
{
    *(u16 *)&gMultiSioSend.raw[0] = 0x660F;
}
END_NONMATCH

// Reset the multiplayer transport, clear the packet buffers, and negotiate
// the local player index. Reconstructed from the European Thumb reference;
// keep the exact assembly in matching builds until agbcc/ROM comparison passes.
NONMATCH("asm/non_matching/sio/sio__sub_8025D58.inc", s16 sub_8025D58(void))
{
    s16 i;

    sub_80260F0();

    DmaFill32(3, 0, &gMultiSioSend, sizeof(gMultiSioSend));
    DmaWait(3);
    DmaFill32(3, 0, gMultiSioRecv, sizeof(gMultiSioRecv));
    DmaWait(3);
    DmaFill32(3, 0, gUnknown_03001060, 4);
    DmaWait(3);

    for (i = 0; i < 4; i++) {
        gUnknown_03001060[0x4C + i] = 0xFF;
        gUnknown_03001060[i] = 0;
    }

    MultiSioInit(0);
    gMultiSioStatusFlags = MultiSioMain(&gMultiSioSend, gMultiSioRecv, 0);
    gStageData.playerIndex = (*(volatile u32 *)0x04000128 >> 4) & 3;
    gMultiSioEnabled = TRUE;

    if (gMultiSioStatusFlags & 0x80) {
        MultiSioStart();
    }

    return gStageData.playerIndex;
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_8025E24.inc", s16 sub_8025E24(u8 id))
{
    u8 *state = gUnknown_03001060;
    u32 flags = gMultiSioStatusFlags;
    bool8 active = FALSE;
    u8 mismatch;

    if (flags & 0x81) {
        if (!(flags & (1 << id))) {
            state[id]++;
            if (state[id] > 180) {
                return -2;
            }
        } else {
            state[id] = 0;
        }
    }

    flags = gMultiSioStatusFlags;
    if (flags & 0x100) {
        active = TRUE;
    }

    mismatch = state[7];
    if ((flags & 0x1000)
        || (active && !(flags & 1) && *(u16 *)&gMultiSioRecv[0].raw[0] != 0)
        || (mismatch != 0 && mismatch != (flags & 0xF))) {
        state[6]++;
        if (state[6] >= (s8)state[4] + 8) {
            return -1;
        }
    } else {
        state[6] = 0;
    }

    if ((s8)state[4] > 0) {
        state[4]--;
    } else if ((s8)state[4] < 0) {
        state[4]++;
    }
    return 0;
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8025EEC.inc", void sub_8025EEC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8026080.inc", void sub_8026080(void))
{
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_80260F0.inc", void sub_80260F0(void))
{
    gMultiSioEnabled = FALSE;
    MultiSioStop();
    MultiSioInit(0);
}
END_NONMATCH

// Thumb-to-C reconstruction; the reference ASM remains the default matching path.
NONMATCH("asm/non_matching/sio/sio__sub_802610C.inc", s16 sub_802610C(void))
{
    u8 id = (*(volatile u32 *)0x04000128 >> 4) & 3;
    if (gStageData.playerIndex != id) {
        return -1;
    }
    return sub_8025E24(id);
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_802613C.inc", void sub_802613C(void))
{
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_802616C.inc", void sub_802616C(u8 value))
{
    gUnknown_03001060[4] = value;
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_8026178.inc", void Task_8026178(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_802618C.inc", void sub_802618C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80261B0.inc", void sub_80261B0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8026254.inc", void sub_8026254(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8026478.inc", void sub_8026478(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80264F0.inc", void sub_80264F0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8026720.inc", void sub_8026720(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80267E8.inc", void sub_80267E8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8026850.inc", void sub_8026850(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80268B8.inc", void sub_80268B8(void))
{
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_8026AB8.inc", void sub_8026AB8(const u8 *packet))
{
    s16 i;
    for (i = 0; i < 8; i++) {
        u8 *slot = &gUnknown_03001CC0[2 + 5 * i];
        if (slot[0] == 0xFF) {
            slot[0] = packet[0];
            slot[1] = packet[1];
            slot[2] = packet[2];
            slot[3] = packet[3];
            slot[4] = packet[4];
            break;
        }
    }
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8026B10.inc", void sub_8026B10(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80274AC.inc", void sub_80274AC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80274F4.inc", void sub_80274F4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027538.inc", void sub_8027538(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027578.inc", void sub_8027578(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80275B8.inc", void sub_80275B8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80275F0.inc", void sub_80275F0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027620.inc", void sub_8027620(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027658.inc", void sub_8027658(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027674.inc", void sub_8027674(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80276A8.inc", void sub_80276A8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80276F4.inc", void sub_80276F4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_802773C.inc", void sub_802773C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027768.inc", void sub_8027768(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80277AC.inc", void sub_80277AC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80277F0.inc", void sub_80277F0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027834.inc", void sub_8027834(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_802785C.inc", void sub_802785C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027878.inc", void sub_8027878(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_802789C.inc", void sub_802789C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80278C4.inc", void sub_80278C4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80278DC.inc", void sub_80278DC(void))
{
}
END_NONMATCH

// C reconstruction from the original Thumb instructions; ASM remains the matching fallback.
NONMATCH("asm/non_matching/sio/sio__sub_80278F8.inc", void sub_80278F8(const u8 *src))
{
    *(u16 *)((u8 *)&gStageData + 0x12) = *(const u16 *)(src + 2);
}
END_NONMATCH

// The original Thumb implementation is a single bx lr (followed by alignment).
void sub_8027904(void)
{
}

// The original Thumb implementation is a single bx lr (followed by alignment).
void sub_8027908(void)
{
}

NONMATCH("asm/non_matching/sio/sio__sub_802790C.inc", void sub_802790C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027960.inc", void sub_8027960(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_F4_8027ADC.inc", void Task_F4_8027ADC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sa2__sub_8081604.inc", void sa2__sub_8081604(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027D3C.inc", void sub_8027D3C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sa2__sub_8081A5C.inc", void sa2__sub_8081A5C(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_F4_8027E70.inc", void Task_F4_8027E70(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8027FD4.inc", void sub_8027FD4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80280AC.inc", void sub_80280AC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028160.inc", void sub_8028160(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028338.inc", void sub_8028338(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_F4_80283CC.inc", void Task_F4_80283CC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_F4_8028418.inc", void Task_F4_8028418(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028448.inc", void sub_8028448(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028478.inc", void sub_8028478(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_F4_80284A4.inc", void Task_F4_80284A4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80284E8.inc", void sub_80284E8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028530.inc", void sub_8028530(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sa2__sub_8081D70.inc", void sa2__sub_8081D70(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80285A0.inc", void sub_80285A0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sa2__sub_8081E38.inc", void sa2__sub_8081E38(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sa2__sub_8081E90.inc", void sa2__sub_8081E90(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028688.inc", void sub_8028688(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028708.inc", void sub_8028708(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028770.inc", void sub_8028770(void))
{
}
END_NONMATCH

// Reconstructed from Thumb; leave original instructions in matching builds.
NONMATCH("asm/non_matching/sio/sio__sub_80287B8.inc", void sub_80287B8(void))
{
    gUnknown_03001060[7] = 0;
    sub_80287CC();
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80287CC.inc", void sub_80287CC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028850.inc", void sub_8028850(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_80288F0.inc", void Task_80288F0(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__Task_8028AA4.inc", void Task_8028AA4(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028C94.inc", void sub_8028C94(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8028DEC.inc", void sub_8028DEC(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8029150.inc", void sub_8029150(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_80292C8.inc", void sub_80292C8(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8029324.inc", void sub_8029324(void))
{
}
END_NONMATCH

NONMATCH("asm/non_matching/sio/sio__sub_8029368.inc", void sub_8029368(void))
{
}
END_NONMATCH
// TODO: Fake-match
u8 sub_80293BC(void)
{
#ifndef NON_MATCHING
    register StageData *stageData asm("r0") = &gStageData;
    register u8 *ptrOpponentIndex asm("r1") = &stageData->mpOpponentPlayerIndex;
#else
    StageData *stageData = &gStageData;
    u8 *ptrOpponentIndex = &stageData->mpOpponentPlayerIndex;
#endif
    u8 opponentIndex = *ptrOpponentIndex;
    u8 result = 0xAA;
    if (opponentIndex != 0xFF) {
        result = 0x55;
        result -= (1 << (*ptrOpponentIndex * 2));
    }

    return result;
}
