.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r7, _080A0704 @ =gCurTask
	ldr r1, [r7]
	ldrh r6, [r1, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r6, r0
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A070C
	ldr r0, _080A0708 @ =Task_80A14AC
	b _080A07A0
	.align 2, 0
_080A0704: .4byte gCurTask
_080A0708: .4byte Task_80A14AC
_080A070C:
	ldr r0, _080A07A8 @ =gBgSprites_Unknown1
	movs r3, #0
	strb r3, [r0, #2]
	ldr r1, _080A07AC @ =gBgSprites_Unknown2
	strb r3, [r1, #8]
	strb r3, [r1, #9]
	movs r0, #0xff
	strb r0, [r1, #0xa]
	movs r0, #0x40
	strb r0, [r1, #0xb]
	movs r0, #0x8e
	lsls r0, r0, #8
	str r0, [r5, #0x6c]
	movs r0, #0xb0
	lsls r0, r0, #5
	str r0, [r5, #0x70]
	ldr r1, _080A07B0 @ =gBgScrollRegs
	movs r4, #0
	movs r0, #0x8e
	strh r0, [r1, #8]
	ldr r0, _080A07B4 @ =0x0000FFEA
	strh r0, [r1, #0xa]
	ldr r1, _080A07B8 @ =gDispCnt
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _080A07BC @ =gBgCntRegs
	ldr r0, _080A07C0 @ =0x00001B09
	strh r0, [r1, #4]
	ldr r1, _080A07C4 @ =0x03000274
	adds r0, r6, r1
	ldr r2, _080A07C8 @ =gUnknown_080D8F18
	ldrb r1, [r5, #1]
	adds r1, r1, r2
	ldrb r1, [r1]
	ldr r2, _080A07CC @ =0x06008000
	str r2, [r0, #4]
	strh r3, [r0, #0xa]
	ldr r2, _080A07D0 @ =0x0600D800
	str r2, [r0, #0xc]
	strh r3, [r0, #0x18]
	strh r3, [r0, #0x1a]
	ldr r2, _080A07D4 @ =gUnknown_080D8CDC
	adds r1, #0xa
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	strh r1, [r0, #0x1c]
	strh r3, [r0, #0x1e]
	strh r3, [r0, #0x20]
	strh r3, [r0, #0x22]
	strh r3, [r0, #0x24]
	movs r1, #0x10
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	ldr r2, _080A07D8 @ =0x0300029E
	adds r1, r6, r2
	strb r4, [r1]
	movs r1, #2
	strh r1, [r0, #0x2e]
	bl DrawBackground
	adds r0, r5, #0
	bl sub_80A10B0
	adds r0, r5, #0
	bl sub_80A1110
	adds r0, r5, #0
	bl sub_80A11B8
	ldr r1, [r7]
	ldr r0, _080A07DC @ =sub_80A07E0
_080A07A0:
	str r0, [r1, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A07A8: .4byte gBgSprites_Unknown1
_080A07AC: .4byte gBgSprites_Unknown2
_080A07B0: .4byte gBgScrollRegs
_080A07B4: .4byte 0x0000FFEA
_080A07B8: .4byte gDispCnt
_080A07BC: .4byte gBgCntRegs
_080A07C0: .4byte 0x00001B09
_080A07C4: .4byte 0x03000274
_080A07C8: .4byte gUnknown_080D8F18
_080A07CC: .4byte 0x06008000
_080A07D0: .4byte 0x0600D800
_080A07D4: .4byte gUnknown_080D8CDC
_080A07D8: .4byte 0x0300029E
_080A07DC: .4byte sub_80A07E0

.syntax divided
