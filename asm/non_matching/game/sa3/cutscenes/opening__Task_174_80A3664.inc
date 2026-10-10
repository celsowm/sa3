.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A36A4 @ =gCurTask
	ldr r0, [r5]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A367E
	adds r0, r4, #0
	bl sub_80A3E90
_080A367E:
	ldr r2, _080A36A8 @ =gBldRegs
	ldrh r1, [r2, #4]
	cmp r1, #0
	bne _080A36B0
	strh r1, [r2, #4]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _080A36C0
	strh r1, [r4, #2]
	strh r1, [r4, #4]
	ldr r1, [r5]
	ldr r0, _080A36AC @ =Task_174_80A3710
	str r0, [r1, #8]
	b _080A36F8
	.align 2, 0
_080A36A4: .4byte gCurTask
_080A36A8: .4byte gBldRegs
_080A36AC: .4byte Task_174_80A3710
_080A36B0:
	ldr r1, _080A3700 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r2, #4]
_080A36C0:
	ldr r2, _080A3704 @ =gWinRegs
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r1, _080A3708 @ =gBgScrollRegs
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	strh r0, [r1, #8]
	ldr r0, [r4, #0x18]
	asrs r0, r0, #8
	strh r0, [r1, #0xa]
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A36F8
	ldr r0, _080A370C @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A36F8
	movs r0, #2
	bl sub_808ADF0
_080A36F8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3700: .4byte 0xFFFFFF00
_080A3704: .4byte gWinRegs
_080A3708: .4byte gBgScrollRegs
_080A370C: .4byte gPressedKeys

.syntax divided
