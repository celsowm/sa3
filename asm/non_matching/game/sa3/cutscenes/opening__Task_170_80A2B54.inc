.syntax unified
.text
	push {r4, lr}
	ldr r0, _080A2B8C @ =gCurTask
	ldr r0, [r0]
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r4, r0, r1
	ldr r1, _080A2B90 @ =0x0300013C
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r2, r1, #1
	strh r2, [r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x8d
	ble _080A2B98
	movs r0, #0x96
	subs r0, r0, r2
	ldr r2, _080A2B94 @ =gBldRegs
	movs r1, #0x10
	lsls r0, r0, #0x11
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	strh r1, [r2, #2]
	b _080A2BBA
	.align 2, 0
_080A2B8C: .4byte gCurTask
_080A2B90: .4byte 0x0300013C
_080A2B94: .4byte gBldRegs
_080A2B98:
	cmp r0, #8
	bgt _080A2BB4
	ldr r0, _080A2BB0 @ =gBldRegs
	movs r1, #0x10
	lsls r2, r2, #0x11
	asrs r2, r2, #0x10
	subs r1, r1, r2
	lsls r1, r1, #8
	orrs r1, r2
	strh r1, [r0, #2]
	b _080A2BBA
	.align 2, 0
_080A2BB0: .4byte gBldRegs
_080A2BB4:
	ldr r1, _080A2BF0 @ =gBldRegs
	movs r0, #0x10
	strh r0, [r1, #2]
_080A2BBA:
	bl sub_80A2DD8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A2C4A
	bl sub_80A2D80
	bl sub_80A23A4
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _080A2C4A
	subs r2, #0x14
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #5
	bhi _080A2C30
	lsls r0, r0, #2
	ldr r1, _080A2BF4 @ =_080A2BF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A2BF0: .4byte gBldRegs
_080A2BF4: .4byte _080A2BF8
_080A2BF8: @ jump table
	.4byte _080A2C3A @ case 0
	.4byte _080A2C10 @ case 1
	.4byte _080A2C1A @ case 2
	.4byte _080A2C30 @ case 3
	.4byte _080A2C30 @ case 4
	.4byte _080A2C30 @ case 5
_080A2C10:
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0xa
	b _080A2C38
_080A2C1A:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r1, _080A2C2C @ =gStageData
	movs r0, #1
	strb r0, [r1, #7]
	b _080A2C3A
	.align 2, 0
_080A2C2C: .4byte gStageData
_080A2C30:
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #1
_080A2C38:
	strh r0, [r1]
_080A2C3A:
	ldr r1, _080A2C50 @ =gDispCnt
	ldr r2, _080A2C54 @ =0x00001441
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080A2C58 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A2C5C @ =Task_170_80A2C60
	str r0, [r1, #8]
_080A2C4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2C50: .4byte gDispCnt
_080A2C54: .4byte 0x00001441
_080A2C58: .4byte gCurTask
_080A2C5C: .4byte Task_170_80A2C60

.syntax divided
