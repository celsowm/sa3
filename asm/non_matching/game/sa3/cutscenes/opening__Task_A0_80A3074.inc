.syntax unified
.text
	push {r4, lr}
	ldr r0, _080A30E4 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r3, r1, r0
	movs r4, #0
	ldrh r0, [r3, #4]
	cmp r0, #4
	bhi _080A3096
	adds r0, #1
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080A30B2
_080A3096:
	ldr r1, [r3, #0x18]
	ldr r2, _080A30E8 @ =0x00004FFF
	cmp r1, r2
	bgt _080A30B2
	ldrb r0, [r3, #1]
	lsls r0, r0, #8
	adds r0, r1, r0
	str r0, [r3, #0x18]
	cmp r0, r2
	ble _080A30B2
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r3, #0x18]
	movs r4, #1
_080A30B2:
	ldr r2, _080A30EC @ =gWinRegs
	ldr r0, [r3, #0x14]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r3, #0xc]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r1, _080A30F0 @ =gBgScrollRegs
	ldr r0, [r3, #0x18]
	asrs r0, r0, #8
	strh r0, [r1, #8]
	ldr r0, [r3, #0x1c]
	asrs r0, r0, #8
	strh r0, [r1, #0xa]
	cmp r4, #0
	beq _080A3102
	ldrb r0, [r3]
	cmp r0, #0
	bne _080A30F4
	movs r0, #2
	bl CreateGameIntroState
	b _080A30FA
	.align 2, 0
_080A30E4: .4byte gCurTask
_080A30E8: .4byte 0x00004FFF
_080A30EC: .4byte gWinRegs
_080A30F0: .4byte gBgScrollRegs
_080A30F4:
	movs r0, #4
	bl CreateGameIntroState
_080A30FA:
	ldr r0, _080A3108 @ =gCurTask
	ldr r0, [r0]
	bl TaskDestroy
_080A3102:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3108: .4byte gCurTask

.syntax divided
