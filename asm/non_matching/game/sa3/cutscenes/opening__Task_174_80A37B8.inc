.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A37F0 @ =gCurTask
	ldr r0, [r5]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	adds r0, r4, #0
	bl sub_80A3EAC
	adds r0, r4, #0
	bl sub_80A3E60
	cmp r0, #1
	bne _080A37F8
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _080A37F8
	movs r0, #0
	strh r0, [r4, #2]
	ldr r1, [r5]
	ldr r0, _080A37F4 @ =Task_174_80A3844
	str r0, [r1, #8]
	b _080A3830
	.align 2, 0
_080A37F0: .4byte gCurTask
_080A37F4: .4byte Task_174_80A3844
_080A37F8:
	ldr r2, _080A3838 @ =gWinRegs
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r1, _080A383C @ =gBgScrollRegs
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	strh r0, [r1, #8]
	ldr r0, [r4, #0x18]
	asrs r0, r0, #8
	strh r0, [r1, #0xa]
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A3830
	ldr r0, _080A3840 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A3830
	movs r0, #2
	bl sub_808ADF0
_080A3830:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3838: .4byte gWinRegs
_080A383C: .4byte gBgScrollRegs
_080A3840: .4byte gPressedKeys

.syntax divided
