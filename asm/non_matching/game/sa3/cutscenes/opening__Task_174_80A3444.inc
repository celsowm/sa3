.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r0, _080A34F0 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r1, r0
	movs r6, #0
	ldrh r0, [r5, #6]
	cmp r0, #0
	bne _080A349A
	ldr r2, _080A34F4 @ =gBldRegs
	movs r0, #0xc2
	strh r0, [r2]
	ldr r4, _080A34F8 @ =gDispCnt
	ldrh r0, [r4]
	movs r3, #0xc0
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _080A34FC @ =gWinRegs
	movs r0, #0xff
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #6]
	ldr r0, _080A3500 @ =0x00001137
	strh r0, [r1, #8]
	strh r6, [r1, #0xa]
	movs r0, #0x10
	strh r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r5, #4]
	movs r0, #1
	strh r0, [r5, #6]
	adds r0, r5, #0
	bl sub_80A3228
	ldrh r1, [r4]
	ldr r0, _080A3504 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r4]
_080A349A:
	ldr r1, [r5, #0x10]
	ldr r0, _080A3508 @ =0x00002FFF
	cmp r1, r0
	ble _080A34B4
	ldr r2, _080A350C @ =0xFFFFFF00
	adds r0, r1, r2
	str r0, [r5, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A34B4
	str r1, [r5, #0x10]
	movs r6, #1
_080A34B4:
	ldr r1, [r5, #8]
	movs r2, #0x80
	lsls r2, r2, #7
	cmp r1, r2
	bgt _080A34D4
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r1, r3
	str r1, [r5, #8]
	ldr r0, _080A3510 @ =0x00003FFF
	cmp r1, r0
	ble _080A34D4
	str r2, [r5, #8]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080A34D4:
	ldr r0, _080A34F4 @ =gBldRegs
	ldrh r1, [r0, #4]
	adds r3, r0, #0
	cmp r1, #0
	beq _080A3514
	ldrh r0, [r5, #4]
	lsrs r0, r0, #8
	strh r0, [r3, #4]
	ldr r1, _080A350C @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	b _080A351A
	.align 2, 0
_080A34F0: .4byte gCurTask
_080A34F4: .4byte gBldRegs
_080A34F8: .4byte gDispCnt
_080A34FC: .4byte gWinRegs
_080A3500: .4byte 0x00001137
_080A3504: .4byte 0x0000FEFF
_080A3508: .4byte 0x00002FFF
_080A350C: .4byte 0xFFFFFF00
_080A3510: .4byte 0x00003FFF
_080A3514:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080A351A:
	ldr r4, _080A3554 @ =gWinRegs
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r5, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	movs r2, #0
	strh r1, [r4, #4]
	cmp r6, #3
	bne _080A354C
	movs r0, #0xf0
	strh r0, [r3]
	ldr r0, _080A3558 @ =0x00003017
	strh r0, [r4, #8]
	movs r0, #0x1f
	strh r0, [r3, #2]
	strh r2, [r3, #4]
	strh r2, [r5, #6]
	strh r2, [r5, #4]
	ldr r0, _080A355C @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A3560 @ =Task_174_80A3564
	str r0, [r1, #8]
_080A354C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3554: .4byte gWinRegs
_080A3558: .4byte 0x00003017
_080A355C: .4byte gCurTask
_080A3560: .4byte Task_174_80A3564

.syntax divided
