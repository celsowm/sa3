.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _08028924 @ =gCurTask
	ldr r0, [r0]
	ldrh r7, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r0, r7
	mov sb, r0
	bl sub_802610C
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _0802891E
	bl sub_8029368
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	beq _08028928
_0802891E:
	bl sub_802613C
	b _08028A4A
	.align 2, 0
_08028924: .4byte gCurTask
_08028928:
	ldr r0, _08028A58 @ =gBldRegs
	strh r5, [r0]
	strh r5, [r0, #4]
	ldr r1, _08028A5C @ =gDispCnt
	movs r2, #0xc2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _08028A60 @ =gUnknown_03001060
	ldr r0, _08028A64 @ =gMultiSioStatusFlags
	ldr r2, [r0]
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r2, r0
	lsrs r2, r2, #8
	ldr r0, _08028A68 @ =0x04000128
	ldr r1, [r0]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1e
	movs r0, #1
	lsls r0, r1
	orrs r2, r0
	strb r2, [r3, #7]
	ldr r4, _08028A6C @ =gMultiSioSend
	ldr r0, _08028A70 @ =0x00006001
	strh r0, [r4]
	ldrb r0, [r3, #7]
	strb r0, [r4, #2]
	ldr r6, _08028A74 @ =gStageData
	ldrb r0, [r6]
	strb r0, [r4, #3]
	ldr r1, _08028A78 @ =0x0300048C
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldr r2, _08028A7C @ =0x0300048B
	adds r1, r7, r2
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r4, #5]
	movs r0, #0x8e
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	strb r0, [r4, #7]
	ldrb r1, [r3, #7]
	subs r2, #3
	adds r0, r7, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	bl sub_8029150
	movs r0, #0xa0
	lsls r0, r0, #0x13
	strh r5, [r0]
	ldr r4, _08028A80 @ =gMultiSioRecv
	ldrb r0, [r6, #6]
	cmp r0, #0
	beq _080289C0
	ldrb r0, [r4, #7]
	mov r1, r8
	strb r0, [r1]
	ldrb r2, [r4, #3]
	ldrb r0, [r6]
	adds r1, r2, #0
	cmp r0, r1
	beq _080289C0
	strb r2, [r6]
	ldr r2, _08028A84 @ =0x03000460
	adds r0, r7, r2
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	strb r1, [r0, #0x1a]
	bl UpdateSpriteAnimation
_080289C0:
	ldrh r1, [r4]
	ldr r0, _08028A70 @ =0x00006001
	cmp r1, r0
	beq _080289D0
	ldr r0, _08028A74 @ =gStageData
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _08028A4A
_080289D0:
	movs r0, #0x91
	lsls r0, r0, #3
	add r0, sb
	ldrh r1, [r0]
	adds r1, #5
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0xc3
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _08028A4A
	ldr r0, _08028A74 @ =gStageData
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _08028A26
	ldr r2, _08028A88 @ =gPseudoRandom
	ldr r0, [r2]
	ldr r6, _08028A8C @ =0x00196225
	muls r0, r6, r0
	ldr r5, _08028A90 @ =0x3C6EF35F
	adds r4, r0, r5
	str r4, [r2]
	str r4, [sp]
	ldr r0, [sp]
	movs r1, #0xf
	ands r0, r1
	lsls r3, r0, #0x10
	cmp r3, #0
	beq _08028A22
	adds r7, r2, #0
	adds r1, r4, #0
_08028A0E:
	adds r0, r1, #0
	muls r0, r6, r0
	adds r1, r0, r5
	str r1, [sp]
	ldr r0, _08028A94 @ =0xFFFF0000
	adds r3, r3, r0
	asrs r0, r3, #0x10
	cmp r0, #0
	bne _08028A0E
	str r1, [r7]
_08028A22:
	ldr r0, [sp]
	str r0, [r2]
_08028A26:
	bl sub_80293BC
	ldr r1, _08028A98 @ =0x00000492
	add r1, sb
	strb r0, [r1]
	mov r0, sb
	bl sub_80292C8
	movs r1, #0x91
	lsls r1, r1, #3
	add r1, sb
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, _08028A9C @ =gCurTask
	ldr r1, [r0]
	ldr r0, _08028AA0 @ =Task_8028AA4
	str r0, [r1, #8]
_08028A4A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028A58: .4byte gBldRegs
_08028A5C: .4byte gDispCnt
_08028A60: .4byte gUnknown_03001060
_08028A64: .4byte gMultiSioStatusFlags
_08028A68: .4byte 0x04000128
_08028A6C: .4byte gMultiSioSend
_08028A70: .4byte 0x00006001
_08028A74: .4byte gStageData
_08028A78: .4byte 0x0300048C
_08028A7C: .4byte 0x0300048B
_08028A80: .4byte gMultiSioRecv
_08028A84: .4byte 0x03000460
_08028A88: .4byte gPseudoRandom
_08028A8C: .4byte 0x00196225
_08028A90: .4byte 0x3C6EF35F
_08028A94: .4byte 0xFFFF0000
_08028A98: .4byte 0x00000492
_08028A9C: .4byte gCurTask
_08028AA0: .4byte Task_8028AA4

.syntax divided
