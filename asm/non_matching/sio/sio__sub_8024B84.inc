.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0
	mov sl, r0
	ldr r1, _08024C20 @ =gStageData
	ldr r0, _08024C24 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	mov sb, r0
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024C58
	ldr r3, _08024C28 @ =gMultiSioSend
	ldr r0, _08024C2C @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	lsls r4, r4, #0x18
	str r4, [sp]
	cmp r0, #0
	beq _08024C4E
	ldr r5, _08024C30 @ =gMultiSioRecv
	ldr r1, _08024C34 @ =0xFFFF99FD
	adds r0, r1, #0
	ldrh r2, [r5]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08024C4E
	movs r0, #0
	ldr r1, _08024C38 @ =gUnknown_030010AC
	mov r8, r1
	adds r3, #0xf
	mov ip, r3
	adds r6, r5, #0
	adds r6, #0xf
	movs r7, #0xff
_08024BE6:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	mov r2, r8
	adds r4, r1, r2
	mov r0, ip
	adds r3, r0, r1
	adds r2, r6, r1
	ldrb r0, [r2]
	strb r0, [r3]
	ldrb r2, [r2]
	adds r0, r7, #0
	ands r0, r2
	strb r0, [r4]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08024BE6
	ldrh r1, [r5, #0xc]
	movs r0, #0x80
	lsls r0, r0, #1
	mov r2, sb
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	beq _08024C3C
	movs r0, #1
	b _08024C4C
	.align 2, 0
_08024C20: .4byte gStageData
_08024C24: .4byte 0x04000128
_08024C28: .4byte gMultiSioSend
_08024C2C: .4byte gMultiSioStatusFlags
_08024C30: .4byte gMultiSioRecv
_08024C34: .4byte 0xFFFF99FD
_08024C38: .4byte gUnknown_030010AC
_08024C3C:
	movs r0, #0x80
	lsls r0, r0, #5
	mov r2, sb
	lsls r0, r2
	ands r1, r0
	cmp r1, #0
	beq _08024C4E
	movs r0, #2
_08024C4C:
	mov sl, r0
_08024C4E:
	ldr r1, [sp]
	lsrs r0, r1, #0x18
	bl sub_8025C64
	mov r0, sl
_08024C58:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

.syntax divided
