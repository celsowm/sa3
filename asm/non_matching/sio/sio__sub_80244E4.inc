.syntax unified
.text
	push {r4, r5, lr}
	ldr r1, _08024524 @ =gStageData
	ldr r0, _08024528 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024576
	ldr r2, _0802452C @ =gMultiSioSend
	ldr r3, _08024530 @ =gUnknown_03001060
	ldr r0, _08024534 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	strb r0, [r2, #2]
	strb r0, [r3, #7]
	adds r4, r0, #0
	bl sub_8025BB0
	adds r0, r4, #0
	cmp r0, #3
	beq _0802453C
	cmp r0, #7
	beq _0802453C
	cmp r0, #0xf
	beq _0802453C
	b _08024576
	.align 2, 0
_08024524: .4byte gStageData
_08024528: .4byte 0x04000128
_0802452C: .4byte gMultiSioSend
_08024530: .4byte gUnknown_03001060
_08024534: .4byte gMultiSioStatusFlags
_08024538:
	adds r0, r3, #0
	b _08024576
_0802453C:
	movs r1, #0
	lsls r4, r4, #0x10
	asrs r3, r4, #0x10
	ldr r5, _0802457C @ =0x00006602
_08024544:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r3, #0
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08024564
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08024580 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	bne _08024538
_08024564:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024544
	movs r1, #0x10
	asrs r0, r4, #0x10
	orrs r0, r1
_08024576:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802457C: .4byte 0x00006602
_08024580: .4byte gMultiSioRecv

.syntax divided
