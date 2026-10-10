.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _0809FDEC @ =gCurTask
	ldr r0, [r0]
	ldrh r5, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r7, r5, r0
	adds r0, r7, #0
	bl sub_80A19C0
	adds r0, r7, #0
	bl sub_80A1030
	adds r0, r7, #0
	bl sub_80A10B0
	adds r0, r7, #0
	bl sub_80A1110
	adds r0, r7, #0
	bl sub_80A11B8
	ldr r1, _0809FDF0 @ =0x03000001
	adds r0, r5, r1
	ldr r2, _0809FDF4 @ =0x03000003
	adds r1, r5, r2
	ldr r3, _0809FDF8 @ =0x0300004C
	adds r2, r5, r3
	ldr r4, _0809FDFC @ =0x03000050
	adds r3, r5, r4
	ldr r6, _0809FE00 @ =0x03000084
	adds r4, r5, r6
	ldr r4, [r4]
	str r4, [sp]
	bl CreateSomeTask_809BF3C
	ldr r1, _0809FE04 @ =0x03000088
	adds r5, r5, r1
	str r0, [r5]
	ldr r5, _0809FE08 @ =gPlayers
	adds r3, r5, #0
	adds r3, #0x2a
	ldrb r1, [r3]
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r0, r1
	strb r0, [r3]
	adds r4, r5, #0
	adds r4, #0x2b
	ldrb r1, [r4]
	movs r3, #4
	rsbs r3, r3, #0
	adds r0, r3, #0
	ands r0, r1
	movs r6, #2
	orrs r0, r6
	strb r0, [r4]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	strb r0, [r4]
	ldr r1, _0809FE0C @ =0x0000017B
	adds r4, r5, r1
	ldrb r0, [r4]
	movs r1, #3
	orrs r0, r1
	strb r0, [r4]
	ldr r0, _0809FE10 @ =0x000002CA
	adds r4, r5, r0
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	orrs r0, r6
	strb r0, [r4]
	ldr r1, _0809FE14 @ =0x000002CB
	adds r4, r5, r1
	ldrb r1, [r4]
	adds r0, r3, #0
	ands r0, r1
	strb r0, [r4]
	ldr r4, _0809FE18 @ =0x0000041A
	adds r1, r5, r4
	ldrb r0, [r1]
	ands r2, r0
	orrs r2, r6
	strb r2, [r1]
	ldr r6, _0809FE1C @ =0x0000041B
	adds r1, r5, r6
	ldrb r0, [r1]
	ands r3, r0
	movs r0, #1
	orrs r3, r0
	strb r3, [r1]
	movs r4, #0
	movs r6, #0x1d
	rsbs r6, r6, #0
_0809FDC6:
	ldr r0, _0809FE20 @ =gStageData
	ldrb r0, [r0, #6]
	cmp r0, r4
	bne _0809FE24
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r4
	lsls r0, r0, #4
	adds r0, r0, r5
	adds r0, #0x2b
	ldrb r2, [r0]
	adds r1, r6, #0
	ands r1, r2
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	b _0809FE4E
	.align 2, 0
_0809FDEC: .4byte gCurTask
_0809FDF0: .4byte 0x03000001
_0809FDF4: .4byte 0x03000003
_0809FDF8: .4byte 0x0300004C
_0809FDFC: .4byte 0x03000050
_0809FE00: .4byte 0x03000084
_0809FE04: .4byte 0x03000088
_0809FE08: .4byte gPlayers
_0809FE0C: .4byte 0x0000017B
_0809FE10: .4byte 0x000002CA
_0809FE14: .4byte 0x000002CB
_0809FE18: .4byte 0x0000041A
_0809FE1C: .4byte 0x0000041B
_0809FE20: .4byte gStageData
_0809FE24:
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r1, r1, r5
	adds r3, r1, #0
	adds r3, #0x2b
	ldrb r2, [r3]
	adds r0, r6, #0
	ands r0, r2
	movs r2, #0xc
	orrs r0, r2
	strb r0, [r3]
	adds r1, #0x2a
	lsls r3, r4, #4
	ldrb r2, [r1]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
_0809FE4E:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0809FDC6
	ldr r1, [r7, #0x18]
	ldrb r0, [r1]
	cmp r0, #0x23
	bne _0809FE84
	movs r0, #0x1d
	strb r0, [r1]
	ldr r0, [r7, #0x18]
	ldrb r0, [r0]
	strb r0, [r7, #3]
	movs r0, #0x9b
	lsls r0, r0, #9
	str r0, [r7, #0x4c]
	str r0, [r7, #0x54]
	ldr r0, _0809FE7C @ =gCurTask
	ldr r1, [r0]
	ldr r0, _0809FE80 @ =Task_80A13F4
	b _0809FE9E
	.align 2, 0
_0809FE7C: .4byte gCurTask
_0809FE80: .4byte Task_80A13F4
_0809FE84:
	cmp r0, #0x22
	bne _0809FE98
	ldr r0, _0809FE90 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _0809FE94 @ =Task_80A14AC
	b _0809FE9E
	.align 2, 0
_0809FE90: .4byte gCurTask
_0809FE94: .4byte Task_80A14AC
_0809FE98:
	ldr r0, _0809FEA8 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _0809FEAC @ =Task_809FEB0
_0809FE9E:
	str r0, [r1, #8]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FEA8: .4byte gCurTask
_0809FEAC: .4byte Task_809FEB0

.syntax divided
