.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0802462C @ =gStageData
	ldr r0, _08024630 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	cmp r0, #0
	beq _08024628
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080245A8
	b _080246A2
_080245A8:
	movs r1, #0
	ldr r0, _08024634 @ =gMultiSioStatusFlags
	mov r8, r0
	mov ip, r8
	ldr r7, _08024638 @ =gUnknown_0300106C
_080245B2:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	movs r1, #1
	lsls r1, r3
	mov r4, ip
	ldr r2, [r4]
	ands r2, r1
	adds r6, r0, #0
	cmp r2, #0
	beq _0802460E
	lsls r0, r3, #1
	adds r4, r0, r3
	lsls r1, r4, #3
	ldr r0, _0802463C @ =gMultiSioRecv
	adds r2, r1, r0
	ldr r1, _08024640 @ =0xFFFF99FF
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0802460E
	lsls r0, r3, #2
	adds r0, r0, r7
	ldr r1, [r2, #4]
	str r1, [r0]
	movs r1, #0
	lsls r4, r4, #2
	ldr r5, _08024644 @ =gUnknown_0300107C
	adds r3, r2, #0
	adds r3, #8
_080245F2:
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
	ble _080245F2
_0802460E:
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r6, r4
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080245B2
	mov r1, r8
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08024648
_08024628:
	movs r0, #0
	b _080246A2
	.align 2, 0
_0802462C: .4byte gStageData
_08024630: .4byte 0x04000128
_08024634: .4byte gMultiSioStatusFlags
_08024638: .4byte gUnknown_0300106C
_0802463C: .4byte gMultiSioRecv
_08024640: .4byte 0xFFFF99FF
_08024644: .4byte gUnknown_0300107C
_08024648:
	ldr r5, _08024668 @ =gMultiSioSend
	ldr r2, _0802466C @ =gMultiSioRecv
	movs r4, #0
	ldrh r3, [r2]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r3
	movs r1, #0xcc
	lsls r1, r1, #7
	cmp r0, r1
	beq _08024670
	cmp r3, #0
	beq _08024670
	movs r0, #5
	rsbs r0, r0, #0
	b _080246A2
	.align 2, 0
_08024668: .4byte gMultiSioSend
_0802466C: .4byte gMultiSioRecv
_08024670:
	ldr r1, _080246AC @ =0xFFFF99FF
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08024686
	ldrb r0, [r2, #2]
	strb r0, [r5, #2]
	ldrb r4, [r2, #2]
_08024686:
	ldrh r1, [r2]
	ldr r0, _080246B0 @ =0x00006602
	cmp r1, r0
	bne _0802469A
	movs r1, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0802469A:
	bl sub_8025BA0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_080246A2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080246AC: .4byte 0xFFFF99FF
_080246B0: .4byte 0x00006602

.syntax divided
