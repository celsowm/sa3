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
	ldr r1, _080252A0 @ =gStageData
	ldr r0, _080252A4 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r5, r0, #0
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080252D6
	cmp r5, #1
	bhi _08025230
	adds r0, r5, #2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08025230:
	ldr r3, _080252A8 @ =gMultiSioSend
	ldr r0, _080252AC @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	lsls r4, r4, #0x18
	str r4, [sp]
	cmp r0, #0
	beq _080252CC
	ldr r6, _080252B0 @ =gMultiSioRecv
	ldr r1, _080252B4 @ =0xFFFF99F9
	adds r0, r1, #0
	ldrh r1, [r6]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080252CC
	movs r0, #0
	ldr r1, _080252B8 @ =gUnknown_030010AC
	mov sb, r1
	adds r3, #0xf
	mov r8, r3
	adds r7, r6, #0
	adds r7, #0xf
	movs r1, #0xff
	mov ip, r1
_08025266:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	mov r0, sb
	adds r4, r1, r0
	mov r0, r8
	adds r3, r0, r1
	adds r2, r7, r1
	ldrb r0, [r2]
	strb r0, [r3]
	ldrb r2, [r2]
	mov r0, ip
	ands r0, r2
	strb r0, [r4]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08025266
	ldrh r1, [r6, #0xc]
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r0, r5
	ands r0, r1
	cmp r0, #0
	beq _080252BC
	movs r1, #1
	mov sl, r1
	b _080252CC
	.align 2, 0
_080252A0: .4byte gStageData
_080252A4: .4byte 0x04000128
_080252A8: .4byte gMultiSioSend
_080252AC: .4byte gMultiSioStatusFlags
_080252B0: .4byte gMultiSioRecv
_080252B4: .4byte 0xFFFF99F9
_080252B8: .4byte gUnknown_030010AC
_080252BC:
	movs r0, #0x80
	lsls r0, r0, #5
	lsls r0, r5
	ands r1, r0
	cmp r1, #0
	beq _080252CC
	movs r0, #2
	mov sl, r0
_080252CC:
	ldr r1, [sp]
	lsrs r0, r1, #0x18
	bl sub_8025C8C
	mov r0, sl
_080252D6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
