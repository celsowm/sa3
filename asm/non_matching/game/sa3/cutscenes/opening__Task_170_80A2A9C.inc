.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A2B30 @ =gCurTask
	ldr r0, [r0]
	ldrh r5, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r6, r5, r0
	ldr r7, _080A2B34 @ =gDispCnt
	ldr r1, _080A2B38 @ =0x00001441
	adds r0, r1, #0
	strh r0, [r7]
	ldr r1, _080A2B3C @ =gBldRegs
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	ldr r2, _080A2B40 @ =0x0300013C
	adds r4, r5, r2
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	bl sub_80A2DD8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A2B28
	bl sub_80A2D80
	bl sub_80A23A4
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _080A2B28
	movs r0, #0x96
	strh r0, [r4]
	ldr r2, _080A2B44 @ =0x03000128
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080A2AFA
	cmp r0, #3
	bgt _080A2AFA
	ldr r2, _080A2B48 @ =0x00001541
	adds r0, r2, #0
	strh r0, [r7]
_080A2AFA:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _080A2B10
	ldr r1, _080A2B34 @ =gDispCnt
	ldr r2, _080A2B48 @ =0x00001541
	adds r0, r2, #0
	strh r0, [r1]
_080A2B10:
	ldr r1, _080A2B3C @ =gBldRegs
	movs r2, #0
	ldr r0, _080A2B4C @ =0x00003F41
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	ldr r0, _080A2B30 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A2B50 @ =Task_170_80A2B54
	str r0, [r1, #8]
_080A2B28:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2B30: .4byte gCurTask
_080A2B34: .4byte gDispCnt
_080A2B38: .4byte 0x00001441
_080A2B3C: .4byte gBldRegs
_080A2B40: .4byte 0x0300013C
_080A2B44: .4byte 0x03000128
_080A2B48: .4byte 0x00001541
_080A2B4C: .4byte 0x00003F41
_080A2B50: .4byte Task_170_80A2B54

.syntax divided
