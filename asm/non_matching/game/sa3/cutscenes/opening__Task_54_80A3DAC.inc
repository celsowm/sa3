.syntax unified
.text
	push {lr}
	ldr r0, _080A3DF4 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r3, r1, r0
	ldr r2, _080A3DF8 @ =gWinRegs
	ldr r0, [r3, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r3, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r1, _080A3DFC @ =gBldRegs
	ldrh r0, [r1, #4]
	cmp r0, #0xe
	bhi _080A3E04
	ldrh r0, [r3, #4]
	adds r0, #0x30
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r1, #4]
	ldrb r0, [r3]
	cmp r0, #0
	bne _080A3E2E
	ldr r0, _080A3E00 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A3E2E
	b _080A3E28
	.align 2, 0
_080A3DF4: .4byte gCurTask
_080A3DF8: .4byte gWinRegs
_080A3DFC: .4byte gBldRegs
_080A3E00: .4byte gPressedKeys
_080A3E04:
	ldrb r0, [r3]
	cmp r0, #0
	beq _080A3E12
	movs r0, #5
	bl CreateGameIntroState
	b _080A3E18
_080A3E12:
	movs r0, #3
	bl CreateGameIntroState
_080A3E18:
	ldr r0, _080A3E24 @ =gCurTask
	ldr r0, [r0]
	bl TaskDestroy
	b _080A3E2E
	.align 2, 0
_080A3E24: .4byte gCurTask
_080A3E28:
	movs r0, #2
	bl sub_808ADF0
_080A3E2E:
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
