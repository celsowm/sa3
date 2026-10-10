.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r5, #0
	ldr r1, _08024B50 @ =gStageData
	ldr r0, _08024B54 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r4, r0, #0
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024B7C
	ldr r0, _08024B58 @ =gMultiSioSend
	mov ip, r0
	ldr r0, _08024B5C @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08024B72
	ldr r3, _08024B60 @ =gMultiSioRecv
	ldrh r1, [r3]
	ldr r2, _08024B64 @ =0xFFFF99FD
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08024B08
	ldr r0, _08024B68 @ =0x00006606
	cmp r1, r0
	bne _08024B72
_08024B08:
	movs r1, #0
	ldr r6, _08024B6C @ =gUnknown_030010AC
	adds r5, r3, #0
	adds r5, #0xf
_08024B10:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r6
	adds r1, r5, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024B10
	ldrh r2, [r3, #0xc]
	adds r0, r2, #0
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08024B70
	movs r0, #0x10
	lsls r0, r4
	ands r2, r0
	cmp r2, #0
	beq _08024B70
	mov r0, ip
	adds r0, #0xf
	adds r0, r0, r4
	movs r1, #0xff
	strb r1, [r0]
	movs r0, #2
	b _08024B7C
	.align 2, 0
_08024B50: .4byte gStageData
_08024B54: .4byte 0x04000128
_08024B58: .4byte gMultiSioSend
_08024B5C: .4byte gMultiSioStatusFlags
_08024B60: .4byte gMultiSioRecv
_08024B64: .4byte 0xFFFF99FD
_08024B68: .4byte 0x00006606
_08024B6C: .4byte gUnknown_030010AC
_08024B70:
	movs r5, #1
_08024B72:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	bl sub_8025C20
	adds r0, r5, #0
_08024B7C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
