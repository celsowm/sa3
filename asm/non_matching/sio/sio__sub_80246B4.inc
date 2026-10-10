.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _08024758 @ =gStageData
	ldr r0, _0802475C @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080247B4
	movs r1, #0
	ldr r0, _08024760 @ =gMultiSioStatusFlags
	mov r8, r0
	mov ip, r8
	ldr r7, _08024764 @ =gUnknown_0300106C
_080246DC:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	movs r1, #1
	lsls r1, r3
	mov r4, ip
	ldr r2, [r4]
	ands r2, r1
	adds r6, r0, #0
	cmp r2, #0
	beq _08024738
	lsls r0, r3, #1
	adds r4, r0, r3
	lsls r1, r4, #3
	ldr r0, _08024768 @ =gMultiSioRecv
	adds r2, r1, r0
	ldr r1, _0802476C @ =0xFFFF99FF
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08024738
	lsls r0, r3, #2
	adds r0, r0, r7
	ldr r1, [r2, #4]
	str r1, [r0]
	movs r1, #0
	lsls r4, r4, #2
	ldr r5, _08024770 @ =gUnknown_0300107C
	adds r3, r2, #0
	adds r3, #8
_0802471C:
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
	ble _0802471C
_08024738:
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r6, r4
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080246DC
	mov r0, r8
	ldr r3, [r0]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	bne _08024774
	movs r0, #0
	b _080247B4
	.align 2, 0
_08024758: .4byte gStageData
_0802475C: .4byte 0x04000128
_08024760: .4byte gMultiSioStatusFlags
_08024764: .4byte gUnknown_0300106C
_08024768: .4byte gMultiSioRecv
_0802476C: .4byte 0xFFFF99FF
_08024770: .4byte gUnknown_0300107C
_08024774:
	ldr r5, _080247C0 @ =gMultiSioSend
	ldr r2, _080247C4 @ =gMultiSioRecv
	movs r4, #0
	ldr r1, _080247C8 @ =0xFFFF99FE
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08024798
	ldr r1, _080247CC @ =gUnknown_03001060
	movs r0, #0xf
	ands r0, r3
	strb r0, [r2, #2]
	strb r0, [r5, #2]
	strb r0, [r1, #7]
	adds r4, r0, #0
_08024798:
	ldrh r1, [r2]
	ldr r0, _080247D0 @ =0x00006603
	cmp r1, r0
	bne _080247AC
	movs r1, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080247AC:
	bl sub_8025BB0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_080247B4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080247C0: .4byte gMultiSioSend
_080247C4: .4byte gMultiSioRecv
_080247C8: .4byte 0xFFFF99FE
_080247CC: .4byte gUnknown_03001060
_080247D0: .4byte 0x00006603

.syntax divided
