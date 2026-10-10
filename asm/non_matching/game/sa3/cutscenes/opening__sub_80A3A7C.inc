.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r6, _080A3B14 @ =gCurTask
	ldr r0, [r6]
	ldrh r3, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r3, r0
	ldr r2, _080A3B18 @ =gWinRegs
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	movs r5, #0
	strh r1, [r2, #4]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne _080A3ABA
	ldr r0, _080A3B1C @ =gDispCnt
	ldrh r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #3
	adds r2, r7, #0
	orrs r1, r2
	strh r1, [r0]
_080A3ABA:
	ldrh r0, [r4, #2]
	cmp r0, #5
	bne _080A3B02
	ldr r1, _080A3B20 @ =gBgCntRegs
	ldr r0, _080A3B24 @ =0x00005D88
	strh r0, [r1, #4]
	ldr r0, _080A3B28 @ =gBgScrollRegs
	strh r5, [r0, #8]
	strh r5, [r0, #0xa]
	ldr r1, _080A3B2C @ =0x03000014
	adds r0, r3, r1
	ldr r1, _080A3B30 @ =0x06008000
	str r1, [r0, #4]
	strh r5, [r0, #0xa]
	ldr r1, _080A3B34 @ =0x0600E800
	str r1, [r0, #0xc]
	strh r5, [r0, #0x18]
	strh r5, [r0, #0x1a]
	movs r1, #0x98
	lsls r1, r1, #1
	strh r1, [r0, #0x1c]
	strh r5, [r0, #0x1e]
	strh r5, [r0, #0x20]
	strh r5, [r0, #0x22]
	strh r5, [r0, #0x24]
	movs r1, #0x20
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	ldr r7, _080A3B38 @ =0x0300003E
	adds r2, r3, r7
	movs r1, #0
	strb r1, [r2]
	movs r1, #6
	strh r1, [r0, #0x2e]
	bl DrawBackground
_080A3B02:
	ldrh r0, [r4, #2]
	cmp r0, #0xa
	bls _080A3B40
	strh r5, [r4, #6]
	ldr r1, [r6]
	ldr r0, _080A3B3C @ =sub_80A3B64
	str r0, [r1, #8]
	b _080A3B58
	.align 2, 0
_080A3B14: .4byte gCurTask
_080A3B18: .4byte gWinRegs
_080A3B1C: .4byte gDispCnt
_080A3B20: .4byte gBgCntRegs
_080A3B24: .4byte 0x00005D88
_080A3B28: .4byte gBgScrollRegs
_080A3B2C: .4byte 0x03000014
_080A3B30: .4byte 0x06008000
_080A3B34: .4byte 0x0600E800
_080A3B38: .4byte 0x0300003E
_080A3B3C: .4byte sub_80A3B64
_080A3B40:
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A3B58
	ldr r0, _080A3B60 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A3B58
	movs r0, #2
	bl sub_808ADF0
_080A3B58:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3B60: .4byte gPressedKeys

.syntax divided
