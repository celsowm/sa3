.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A42F4 @ =gCurTask
	ldr r0, [r5]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r3, r1, r0
	movs r2, #0x9b
	lsls r2, r2, #9
	str r2, [r3, #0x18]
	movs r4, #0
	movs r1, #0x1d
	strb r1, [r3, #1]
	ldrb r0, [r3, #2]
	adds r0, #1
	strb r0, [r3, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080A430C
	strh r4, [r3, #4]
	ldr r2, _080A42F8 @ =gBldRegs
	movs r0, #0xa0
	strh r0, [r2]
	ldr r1, _080A42FC @ =gWinRegs
	movs r0, #0xc0
	lsls r0, r0, #6
	strh r0, [r1, #8]
	strh r4, [r1, #0xa]
	movs r0, #0x10
	strh r0, [r2, #4]
	movs r0, #0
	bl sub_80C4C0C
	ldr r1, _080A4300 @ =gBgPalette
	strh r0, [r1]
	ldr r2, _080A4304 @ =gFlags
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, [r5]
	ldr r0, _080A4308 @ =Task_94_B_80A4384
	b _080A436A
	.align 2, 0
_080A42F4: .4byte gCurTask
_080A42F8: .4byte gBldRegs
_080A42FC: .4byte gWinRegs
_080A4300: .4byte gBgPalette
_080A4304: .4byte gFlags
_080A4308: .4byte Task_94_B_80A4384
_080A430C:
	movs r0, #0x19
	strb r0, [r3, #1]
	movs r0, #3
	ldrsb r0, [r3, r0]
	movs r1, #1
	cmp r0, #0
	ble _080A4320
	movs r0, #1
	rsbs r0, r0, #0
	adds r1, r0, #0
_080A4320:
	strb r1, [r3, #3]
	lsls r0, r1, #0x18
	cmp r0, #0
	ble _080A4338
	ldr r0, _080A4334 @ =0xFFFF8800
	str r0, [r3, #0x18]
	movs r0, #0x96
	lsls r0, r0, #9
	b _080A4340
	.align 2, 0
_080A4334: .4byte 0xFFFF8800
_080A4338:
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r3, #0x18]
	ldr r0, _080A4374 @ =0xFFFFC400
_080A4340:
	str r0, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x2c
	ldr r2, _080A4378 @ =gUnknown_080D99A8
	ldrb r1, [r3, #2]
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r1, [r1]
	strh r1, [r0, #0xc]
	ldrb r1, [r3, #2]
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	strb r1, [r0, #0x1a]
	movs r1, #0xff
	strb r1, [r0, #0x1b]
	bl UpdateSpriteAnimation
	ldr r0, _080A437C @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A4380 @ =Task_94_B_80A41AC
_080A436A:
	str r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4374: .4byte 0xFFFFC400
_080A4378: .4byte gUnknown_080D99A8
_080A437C: .4byte gCurTask
_080A4380: .4byte Task_94_B_80A41AC

.syntax divided
