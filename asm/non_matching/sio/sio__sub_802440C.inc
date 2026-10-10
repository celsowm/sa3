.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r1, _0802442C @ =gStageData
	ldr r0, _08024430 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r4, r0, #0
	cmp r4, #0
	beq _08024434
	movs r0, #0
	b _080244BE
	.align 2, 0
_0802442C: .4byte gStageData
_08024430: .4byte 0x04000128
_08024434:
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080244BE
	ldr r7, _080244CC @ =gMultiSioSend
	strb r4, [r7, #2]
	movs r1, #0
	ldr r0, _080244D0 @ =gMultiSioStatusFlags
	mov sb, r0
	ldr r2, _080244D4 @ =0x00006601
	mov r8, r2
	ldr r0, _080244D8 @ =gUnknown_0300106C
	mov ip, r0
_08024452:
	lsls r1, r1, #0x10
	asrs r3, r1, #0x10
	movs r4, #1
	lsls r4, r3
	mov r2, sb
	ldr r0, [r2]
	ands r0, r4
	adds r6, r1, #0
	cmp r0, #0
	beq _080244AA
	lsls r0, r3, #1
	adds r5, r0, r3
	lsls r1, r5, #3
	ldr r0, _080244DC @ =gMultiSioRecv
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, r8
	bne _080244AA
	ldrb r0, [r7, #2]
	orrs r4, r0
	strb r4, [r7, #2]
	lsls r0, r3, #2
	add r0, ip
	ldr r1, [r2, #4]
	str r1, [r0]
	movs r1, #0
	lsls r4, r5, #2
	ldr r5, _080244E0 @ =gUnknown_0300107C
	adds r3, r2, #0
	adds r3, #8
_0802448E:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r2, r1, r4
	adds r2, r2, r5
	adds r1, r3, r1
	ldrh r1, [r1]
	strh r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0802448E
_080244AA:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r6, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024452
	bl sub_8025BA0
	ldrb r0, [r7, #2]
_080244BE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080244CC: .4byte gMultiSioSend
_080244D0: .4byte gMultiSioStatusFlags
_080244D4: .4byte 0x00006601
_080244D8: .4byte gUnknown_0300106C
_080244DC: .4byte gMultiSioRecv
_080244E0: .4byte gUnknown_0300107C

.syntax divided
