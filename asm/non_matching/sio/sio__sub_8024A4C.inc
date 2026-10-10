.syntax unified
.text
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024AAA
	ldr r2, _08024AB0 @ =gMultiSioSend
	ldr r0, _08024AB4 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	lsls r6, r4, #0x18
	cmp r0, #0
	beq _08024AA2
	ldr r1, _08024AB8 @ =gMultiSioRecv
	ldr r3, _08024ABC @ =0xFFFF99FD
	adds r0, r3, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08024AA2
	movs r3, #0
	adds r5, r2, #0
	adds r5, #0xf
	adds r4, r1, #0
	adds r4, #0xf
_08024A8A:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r5, r0
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024A8A
_08024AA2:
	lsrs r0, r6, #0x18
	bl sub_8025BEC
	movs r0, #0
_08024AAA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08024AB0: .4byte gMultiSioSend
_08024AB4: .4byte gMultiSioStatusFlags
_08024AB8: .4byte gMultiSioRecv
_08024ABC: .4byte 0xFFFF99FD

.syntax divided
