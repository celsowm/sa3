.syntax unified
.text
	push {r4, r5, lr}
	ldr r0, _080A3590 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	adds r0, r4, #0
	bl sub_80A3E3C
	ldr r1, _080A3594 @ =gBldRegs
	ldrh r0, [r1, #4]
	cmp r0, #0xf
	bhi _080A3598
	ldrh r0, [r4, #4]
	adds r0, #0x80
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r1, #4]
	b _080A35AC
	.align 2, 0
_080A3590: .4byte gCurTask
_080A3594: .4byte gBldRegs
_080A3598:
	movs r0, #0
	bl sub_80C4C0C
	ldr r1, _080A35FC @ =gBgPalette
	strh r0, [r1]
	ldr r2, _080A3600 @ =gFlags
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080A35AC:
	ldrh r0, [r4, #2]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x96
	bls _080A3618
	movs r3, #0x80
	lsls r3, r3, #5
	strh r3, [r4, #4]
	strh r5, [r4, #2]
	ldr r2, _080A3604 @ =gBldRegs
	movs r0, #0xd0
	strh r0, [r2]
	ldr r1, _080A3608 @ =gWinRegs
	ldr r0, _080A360C @ =0x00003017
	strh r0, [r1, #8]
	movs r0, #0x1f
	strh r0, [r2, #2]
	movs r0, #0x10
	strh r0, [r2, #4]
	strh r5, [r4, #6]
	strh r3, [r4, #4]
	movs r0, #0
	bl sub_80C4C0C
	ldr r1, _080A35FC @ =gBgPalette
	strh r0, [r1]
	ldr r2, _080A3600 @ =gFlags
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _080A3610 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A3614 @ =Task_174_80A3664
	str r0, [r1, #8]
	b _080A3650
	.align 2, 0
_080A35FC: .4byte gBgPalette
_080A3600: .4byte gFlags
_080A3604: .4byte gBldRegs
_080A3608: .4byte gWinRegs
_080A360C: .4byte 0x00003017
_080A3610: .4byte gCurTask
_080A3614: .4byte Task_174_80A3664
_080A3618:
	ldr r2, _080A3658 @ =gWinRegs
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r1, _080A365C @ =gBgScrollRegs
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	strh r0, [r1, #8]
	ldr r0, [r4, #0x18]
	asrs r0, r0, #8
	strh r0, [r1, #0xa]
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A3650
	ldr r0, _080A3660 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A3650
	movs r0, #2
	bl sub_808ADF0
_080A3650:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3658: .4byte gWinRegs
_080A365C: .4byte gBgScrollRegs
_080A3660: .4byte gPressedKeys

.syntax divided
