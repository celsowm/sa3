.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A3748 @ =gCurTask
	ldr r0, [r5]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A372A
	adds r0, r4, #0
	bl sub_80A3E90
_080A372A:
	ldr r1, _080A374C @ =gBldRegs
	ldrh r0, [r1, #4]
	cmp r0, #0xf
	bls _080A375C
	movs r2, #0
	movs r0, #0x10
	strh r0, [r1, #4]
	ldr r1, _080A3750 @ =gWinRegs
	ldr r0, _080A3754 @ =0x00002017
	strh r0, [r1, #8]
	strh r2, [r4, #2]
	ldr r1, [r5]
	ldr r0, _080A3758 @ =Task_174_80A37B8
	str r0, [r1, #8]
	b _080A37A6
	.align 2, 0
_080A3748: .4byte gCurTask
_080A374C: .4byte gBldRegs
_080A3750: .4byte gWinRegs
_080A3754: .4byte 0x00002017
_080A3758: .4byte Task_174_80A37B8
_080A375C:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r1, #4]
	ldr r2, _080A37AC @ =gWinRegs
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r1, _080A37B0 @ =gBgScrollRegs
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	strh r0, [r1, #8]
	ldr r0, [r4, #0x18]
	asrs r0, r0, #8
	strh r0, [r1, #0xa]
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A37A6
	ldr r0, _080A37B4 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A37A6
	movs r0, #2
	bl sub_808ADF0
_080A37A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A37AC: .4byte gWinRegs
_080A37B0: .4byte gBgScrollRegs
_080A37B4: .4byte gPressedKeys

.syntax divided
