.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _08023AA8 @ =gStageData
	ldr r0, _08023AAC @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	cmp r0, #0
	beq _08023AB0
	movs r0, #0
	b _08023B80
	.align 2, 0
_08023AA8: .4byte gStageData
_08023AAC: .4byte 0x04000128
_08023AB0:
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023B80
	ldr r2, _08023AD0 @ =gMultiSioStatusFlags
	ldr r1, [r2]
	ldr r0, _08023AD4 @ =0x00000C0C
	ands r1, r0
	cmp r1, #0
	beq _08023AD8
	movs r0, #4
	rsbs r0, r0, #0
	b _08023B80
	.align 2, 0
_08023AD0: .4byte gMultiSioStatusFlags
_08023AD4: .4byte 0x00000C0C
_08023AD8:
	ldr r4, _08023B90 @ =gMultiSioSend
	strb r1, [r4, #2]
	movs r1, #0
	movs r7, #1
	ldr r0, _08023B94 @ =gLoadedSaveGame
	mov ip, r0
	adds r5, r4, #6
	mov sl, r5
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, ip
	mov sb, r0
	ldr r5, _08023B98 @ =0x00000365
	add r5, ip
	mov r8, r5
_08023AF6:
	lsls r1, r1, #0x10
	asrs r2, r1, #0x10
	adds r3, r7, #0
	lsls r3, r2
	ldr r5, _08023B9C @ =gMultiSioStatusFlags
	ldr r0, [r5]
	ands r0, r3
	adds r6, r1, #0
	cmp r0, #0
	beq _08023B6C
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08023BA0 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _08023BA4 @ =0x00006C01
	cmp r0, r1
	bne _08023B6C
	ldrb r0, [r4, #2]
	orrs r3, r0
	strb r3, [r4, #2]
	mov r5, ip
	ldrb r0, [r5, #0x10]
	strb r0, [r4, #3]
	ldrb r0, [r5, #0x11]
	strb r0, [r4, #4]
	ldr r1, _08023BA8 @ =gLoadedSaveGame + 0x36
	ldrb r0, [r1]
	strb r0, [r4, #5]
	movs r1, #0
	mov r3, sl
	ldr r5, _08023BAC @ =gLoadedSaveGame + 0x29
_08023B38:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r2, r3, r0
	adds r1, r0, r5
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble _08023B38
	strb r7, [r4, #0xd]
	mov r5, sb
	ldrb r0, [r5]
	strb r0, [r4, #0xe]
	mov r1, r8
	ldrb r0, [r1]
	strb r0, [r4, #0xf]
	mov r0, ip
	adds r0, #0x32
	ldrb r0, [r0]
	strb r0, [r4, #0x10]
	mov r5, ip
	ldrh r0, [r5, #0x34]
	strb r0, [r4, #0x11]
_08023B6C:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r6, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08023AF6
	bl sub_8024314
	ldrb r0, [r4, #2]
_08023B80:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023B90: .4byte gMultiSioSend
_08023B94: .4byte gLoadedSaveGame
_08023B98: .4byte 0x00000365
_08023B9C: .4byte gMultiSioStatusFlags
_08023BA0: .4byte gMultiSioRecv
_08023BA4: .4byte 0x00006C01
_08023BA8: .4byte gLoadedSaveGame + 0x36
_08023BAC: .4byte gLoadedSaveGame + 0x29

.syntax divided
