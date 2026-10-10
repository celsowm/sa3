.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A386C @ =gCurTask
	ldr r0, [r5]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	adds r0, r4, #0
	bl sub_80A3EDC
	ldrh r0, [r4, #2]
	cmp r0, #0x13
	bls _080A3870
	ldrb r0, [r4]
	bl sub_80A38C0
	ldr r0, [r5]
	bl TaskDestroy
	b _080A38AC
	.align 2, 0
_080A386C: .4byte gCurTask
_080A3870:
	adds r0, #1
	strh r0, [r4, #2]
	ldr r2, _080A38B4 @ =gWinRegs
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r1, _080A38B8 @ =gBgScrollRegs
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	strh r0, [r1, #8]
	ldr r0, [r4, #0x18]
	asrs r0, r0, #8
	strh r0, [r1, #0xa]
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A38AC
	ldr r0, _080A38BC @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A38AC
	movs r0, #2
	bl sub_808ADF0
_080A38AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A38B4: .4byte gWinRegs
_080A38B8: .4byte gBgScrollRegs
_080A38BC: .4byte gPressedKeys

.syntax divided
