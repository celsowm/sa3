.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _08027B6C @ =gCurTask
	ldr r0, [r0]
	ldrh r6, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r7, r6, r0
	bl sa2__sub_8081D70
	lsls r0, r0, #0x18
	asrs r0, r0, #8
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	ldr r1, _08027B70 @ =0x030000DC
	adds r0, r6, r1
	strb r2, [r0]
	ldr r0, _08027B74 @ =0x04000128
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _08027B78
	bl sub_802613C
	b _08027D18
	.align 2, 0
_08027B6C: .4byte gCurTask
_08027B70: .4byte 0x030000DC
_08027B74: .4byte 0x04000128
_08027B78:
	ldr r0, _08027C40 @ =gMultiBootParam
	mov r8, r0
	ldrb r0, [r0, #0x1e]
	movs r1, #0xe
	ands r1, r0
	cmp r1, #0
	beq _08027C68
	mov r1, r8
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	bne _08027C80
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08027C80
	bl sub_80285A0
	ldr r0, _08027C44 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08027C80
	ldr r2, _08027C48 @ =0x030000DD
	adds r0, r6, r2
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08027C4C @ =gFlags
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	orrs r0, r1
	str r0, [r4]
	bl m4aMPlayAllStop
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	bl m4aSoundVSyncOff
	ldr r1, _08027C50 @ =0x040000B0
	ldrh r2, [r1, #0xa]
	ldr r4, _08027C54 @ =0x0000C5FF
	adds r0, r4, #0
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r2, [r1, #0xa]
	ldr r3, _08027C58 @ =0x00007FFF
	adds r0, r3, #0
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r0, [r1, #0xa]
	adds r1, #0xc
	ldrh r2, [r1, #0xa]
	adds r0, r4, #0
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r2, [r1, #0xa]
	adds r0, r3, #0
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r0, [r1, #0xa]
	adds r1, #0xc
	ldrh r2, [r1, #0xa]
	adds r0, r4, #0
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r2, [r1, #0xa]
	adds r0, r3, #0
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r0, [r1, #0xa]
	ldr r0, _08027C5C @ =0x040000D4
	ldrh r1, [r0, #0xa]
	ands r4, r1
	strh r4, [r0, #0xa]
	ldrh r1, [r0, #0xa]
	ands r3, r1
	strh r3, [r0, #0xa]
	ldrh r0, [r0, #0xa]
	ldr r1, _08027C60 @ =0x030000E0
	adds r0, r6, r1
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r2, _08027C64 @ =0x030000E4
	adds r0, r6, r2
	ldr r2, [r0]
	subs r2, #0xc0
	str r5, [sp]
	mov r0, r8
	movs r3, #4
	bl MultiBootStartMaster
	b _08027C80
	.align 2, 0
_08027C40: .4byte gMultiBootParam
_08027C44: .4byte gPressedKeys
_08027C48: .4byte 0x030000DD
_08027C4C: .4byte gFlags
_08027C50: .4byte 0x040000B0
_08027C54: .4byte 0x0000C5FF
_08027C58: .4byte 0x00007FFF
_08027C5C: .4byte 0x040000D4
_08027C60: .4byte 0x030000E0
_08027C64: .4byte 0x030000E4
_08027C68:
	ldr r2, _08027CA4 @ =0x030000DD
	adds r0, r6, r2
	strb r1, [r0]
	ldr r2, _08027CA8 @ =gFlags
	ldr r0, [r2]
	ldr r1, _08027CAC @ =0xFFFFBFFF
	ands r0, r1
	ldr r1, _08027CB0 @ =0xFFFF7FFF
	ands r0, r1
	str r0, [r2]
	bl m4aSoundVSyncOn
_08027C80:
	adds r0, r7, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027CC0
	ldr r0, _08027CB4 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027CC0
	movs r0, #0x6b      @ SE_ABORT
	bl m4aSongNumStart
	ldr r0, _08027CB8 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _08027CBC @ =Task_F4_8027ADC
	b _08027D16
	.align 2, 0
_08027CA4: .4byte 0x030000DD
_08027CA8: .4byte gFlags
_08027CAC: .4byte 0xFFFFBFFF
_08027CB0: .4byte 0xFFFF7FFF
_08027CB4: .4byte gPressedKeys
_08027CB8: .4byte gCurTask
_08027CBC: .4byte Task_F4_8027ADC
_08027CC0:
	bl sub_8028530
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	bne _08027D18
	ldr r0, _08027D24 @ =gMultiBootParam
	bl MultiBootCheckComplete
	cmp r0, #0
	beq _08027D18
	adds r0, r7, #0
	bl sub_8028160
	adds r0, r7, #0
	adds r0, #0xde
	strb r5, [r0]
	ldr r2, _08027D28 @ =gMultiSioSend
	strb r5, [r2]
	ldr r0, _08027D2C @ =gMultiSioRecv
	mov ip, r0
	strb r5, [r0]
	strb r5, [r0, #0x18]
	mov r4, ip
	adds r4, #0x30
	strb r5, [r4]
	mov r3, ip
	adds r3, #0x48
	strb r5, [r3]
	strb r5, [r2, #2]
	movs r1, #0
	ldr r0, _08027D30 @ =0x0000F001
	strh r0, [r2]
	mov r2, ip
	strb r1, [r2, #2]
	mov r0, ip
	adds r0, #0x18
	strb r1, [r0, #2]
	strb r1, [r4, #2]
	strb r1, [r3, #2]
	ldr r0, _08027D34 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _08027D38 @ =sub_8028448
_08027D16:
	str r0, [r1, #8]
_08027D18:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027D24: .4byte gMultiBootParam
_08027D28: .4byte gMultiSioSend
_08027D2C: .4byte gMultiSioRecv
_08027D30: .4byte 0x0000F001
_08027D34: .4byte gCurTask
_08027D38: .4byte sub_8028448

.syntax divided
