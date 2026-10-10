.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A0968 @ =gCurTask
	ldr r1, [r6]
	ldrh r5, [r1, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r5, r0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0970
	ldr r0, _080A096C @ =Task_80A14AC
	b _080A09D2
	.align 2, 0
_080A0968: .4byte gCurTask
_080A096C: .4byte Task_80A14AC
_080A0970:
	ldr r1, _080A09DC @ =gDispCnt
	ldr r2, _080A09E0 @ =0x00001541
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _080A09E4 @ =gBgCntRegs
	movs r3, #0
	movs r2, #0
	ldr r0, _080A09E8 @ =0x00001B89
	strh r0, [r1, #4]
	ldr r0, _080A09EC @ =gBgScrollRegs
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x6c]
	movs r0, #0xaa
	lsls r0, r0, #7
	str r0, [r4, #0x70]
	ldr r1, _080A09F0 @ =0x03000274
	adds r0, r5, r1
	ldr r1, _080A09F4 @ =0x06008000
	str r1, [r0, #4]
	strh r2, [r0, #0xa]
	ldr r1, _080A09F8 @ =0x0600D800
	str r1, [r0, #0xc]
	strh r2, [r0, #0x18]
	strh r2, [r0, #0x1a]
	ldr r1, _080A09FC @ =gUnknown_080D8CDC
	ldrh r1, [r1, #0x1e]
	strh r1, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r2, [r0, #0x20]
	strh r2, [r0, #0x22]
	strh r2, [r0, #0x24]
	movs r1, #0x10
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	ldr r2, _080A0A00 @ =0x0300029E
	adds r1, r5, r2
	strb r3, [r1]
	movs r1, #6
	strh r1, [r0, #0x2e]
	bl DrawBackground
	adds r0, r4, #0
	bl sub_80A0A08
	ldr r1, [r6]
	ldr r0, _080A0A04 @ =sub_80A0ADC
_080A09D2:
	str r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A09DC: .4byte gDispCnt
_080A09E0: .4byte 0x00001541
_080A09E4: .4byte gBgCntRegs
_080A09E8: .4byte 0x00001B89
_080A09EC: .4byte gBgScrollRegs
_080A09F0: .4byte 0x03000274
_080A09F4: .4byte 0x06008000
_080A09F8: .4byte 0x0600D800
_080A09FC: .4byte gUnknown_080D8CDC
_080A0A00: .4byte 0x0300029E
_080A0A04: .4byte sub_80A0ADC

.syntax divided
