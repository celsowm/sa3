.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov sl, r1
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r2, _08026B80 @ =gMultiSioRecv
	adds r4, r1, r2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r2, _08026B84 @ =gPlayers
	adds r6, r1, r2
	ldrb r1, [r4, #0x12]
	lsls r3, r1, #0x18
	lsrs r0, r3, #0x18
	mov r8, r2
	cmp r0, #0xff
	bne _08026B4C
	bl _08027496_return
_08026B4C:
	lsrs r3, r3, #0x1e
	str r3, [sp, #8]
	movs r3, #0x38
	ands r3, r1
	movs r7, #7
	ands r7, r1
	ldrb r5, [r4, #0x13]
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1d
	ldr r2, [sp, #8]
	cmp r2, r0
	bne _08026B6E
	bl _08027496_return
_08026B6E:
	cmp r3, #0x38
	bls _08026B76
	bl _08027470
_08026B76:
	lsls r0, r3, #2
	ldr r1, _08026B88 @ =_08026B8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026B80: .4byte gMultiSioRecv
_08026B84: .4byte gPlayers
_08026B88: .4byte _08026B8C
_08026B8C: @ jump table
	.4byte _08027496_return @ case 0
	.4byte _08027470 @ case 1
	.4byte _08027470 @ case 2
	.4byte _08027470 @ case 3
	.4byte _08027470 @ case 4
	.4byte _08027470 @ case 5
	.4byte _08027470 @ case 6
	.4byte _08027470 @ case 7
	.4byte _08026C70 @ case 8
	.4byte _08027470 @ case 9
	.4byte _08027470 @ case 10
	.4byte _08027470 @ case 11
	.4byte _08027470 @ case 12
	.4byte _08027470 @ case 13
	.4byte _08027470 @ case 14
	.4byte _08027470 @ case 15
	.4byte _08026D7C @ case 16
	.4byte _08027470 @ case 17
	.4byte _08027470 @ case 18
	.4byte _08027470 @ case 19
	.4byte _08027470 @ case 20
	.4byte _08027470 @ case 21
	.4byte _08027470 @ case 22
	.4byte _08027470 @ case 23
	.4byte _08026CD0 @ case 24
	.4byte _08027470 @ case 25
	.4byte _08027470 @ case 26
	.4byte _08027470 @ case 27
	.4byte _08027470 @ case 28
	.4byte _08027470 @ case 29
	.4byte _08027470 @ case 30
	.4byte _08027470 @ case 31
	.4byte _08026D08 @ case 32
	.4byte _08027470 @ case 33
	.4byte _08027470 @ case 34
	.4byte _08027470 @ case 35
	.4byte _08027470 @ case 36
	.4byte _08027470 @ case 37
	.4byte _08027470 @ case 38
	.4byte _08027470 @ case 39
	.4byte _08026EA8 @ case 40
	.4byte _08027470 @ case 41
	.4byte _08027470 @ case 42
	.4byte _08027470 @ case 43
	.4byte _08027470 @ case 44
	.4byte _08027470 @ case 45
	.4byte _08027470 @ case 46
	.4byte _08027470 @ case 47
	.4byte _08026DD8 @ case 48
	.4byte _08027470 @ case 49
	.4byte _08027470 @ case 50
	.4byte _08027470 @ case 51
	.4byte _08027470 @ case 52
	.4byte _08027470 @ case 53
	.4byte _08027470 @ case 54
	.4byte _08027470 @ case 55
	.4byte _08026F10 @ case 56
_08026C70:
	adds r0, r4, #0
	adds r0, #0x12
	ldrb r2, [r0, #1]
	ldrb r1, [r0, #2]
	lsls r1, r1, #8
	orrs r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_802AE64
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r2, r0, #0x1e
	ldr r1, _08026CC8 @ =gStageData
	lsrs r0, r2, #0x1e
	ldrb r1, [r1, #6]
	cmp r0, r1
	beq _08026C9C
	bl _08027470
_08026C9C:
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08026CCC @ =gPlayers
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x4a
	ldrh r0, [r1]
	adds r0, #0x3c
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x78
	bgt _08026CC0
	b _08027470
_08026CC0:
	movs r0, #0x78
	strh r0, [r1]
	b _08027470
	.align 2, 0
_08026CC8: .4byte gStageData
_08026CCC: .4byte gPlayers
_08026CD0:
	adds r2, r4, #0
	adds r2, #0x12
	ldr r0, _08026D04 @ =gStageData
	adds r0, #0x94
	ldr r0, [r0]
	ldrh r3, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r3, r3, r0
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r0, r1
	ldrb r1, [r2, #3]
	lsls r1, r1, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r0, r1
	ldr r1, [r3, #4]
	adds r1, r1, r0
	movs r3, #3
	rsbs r3, r3, #0
	adds r0, r3, #0
	strb r0, [r1]
	b _08027470
	.align 2, 0
_08026D04: .4byte gStageData
_08026D08:
	adds r4, #0x12
	ldr r2, _08026D74 @ =gStageData
	adds r0, r2, #0
	adds r0, #0x94
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r1, r0
	ldrb r0, [r2, #0xa]
	cmp r0, #9
	bne _08026D52
	ldrb r1, [r4, #1]
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r0, r1
	ldrb r2, [r4, #3]
	lsls r2, r2, #0x10
	orrs r2, r0
	ldrb r1, [r4, #4]
	lsls r1, r1, #0x18
	orrs r1, r2
	ldr r0, [r5, #8]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08026D52
	ldr r1, _08026D78 @ =gUnknown_03001D00
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x8a      @ SE_POOF
	bl m4aSongNumStart
_08026D52:
	ldrb r1, [r4, #1]
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r0, r1
	ldrb r1, [r4, #3]
	lsls r1, r1, #0x10
	orrs r1, r0
	ldrb r0, [r4, #4]
	lsls r0, r0, #0x18
	orrs r0, r1
	ldr r1, [r5, #8]
	adds r1, r1, r0
	mov r0, sl
	subs r0, #6
	strb r0, [r1]
	b _08027470
	.align 2, 0
_08026D74: .4byte gStageData
_08026D78: .4byte gUnknown_03001D00
_08026D7C:
	adds r5, r4, #0
	adds r5, #0x12
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1e
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r3, _08026DD0 @ =gPlayers
	adds r1, r1, r3
	ldr r4, _08026DD4 @ =gStageData
	ldrb r2, [r4, #6]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, r0, r3
	cmp r0, r1
	beq _08026DAE
	b _08027470
_08026DAE:
	adds r0, r4, #0
	adds r0, #0x21
	strb r7, [r0]
	adds r0, #0x8d
	ldrh r0, [r0]
	str r0, [r4, #0x24]
	ldrb r1, [r5, #1]
	ldrb r0, [r5, #2]
	lsls r0, r0, #8
	orrs r0, r1
	strh r0, [r4, #0x28]
	ldrb r1, [r5, #3]
	ldrb r0, [r5, #4]
	lsls r0, r0, #8
	orrs r0, r1
	strh r0, [r4, #0x2a]
	b _08027470
	.align 2, 0
_08026DD0: .4byte gPlayers
_08026DD4: .4byte gStageData
_08026DD8:
	adds r2, r4, #0
	adds r2, #0x12
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08026E94 @ =gPlayers
	adds r4, r0, r1
	ldr r1, _08026E98 @ =gCamera
	ldrb r3, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r0, r3
	str r0, [r1]
	str r0, [r1, #0x28]
	ldrb r3, [r2, #3]
	ldrb r0, [r2, #4]
	lsls r0, r0, #8
	orrs r0, r3
	str r0, [r1, #4]
	str r0, [r1, #0x2c]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r0, r1
	adds r0, #0x78
	lsls r0, r0, #8
	str r0, [r4, #0x10]
	ldrb r1, [r2, #3]
	ldrb r0, [r2, #4]
	lsls r0, r0, #8
	orrs r0, r1
	adds r1, r4, #0
	adds r1, #0x25
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	adds r0, #0x50
	lsls r0, r0, #8
	str r0, [r4, #0x14]
	ldr r0, [r4, #4]
	ldr r1, _08026E9C @ =0xFFFEFFFF
	ands r0, r1
	str r0, [r4, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	ands r3, r0
	cmp r3, #0
	bne _08026E88
	adds r0, r6, #0
	adds r0, #0x27
	ldrb r0, [r0]
	adds r2, r4, #0
	adds r2, #0x27
	strb r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1c]
	ldr r0, [r4, #4]
	ldr r1, _08026EA0 @ =0xEFFFFFDF
	ands r0, r1
	str r0, [r4, #4]
	str r3, [r4, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026E76
	adds r0, r4, #0
	bl sub_8016F28
_08026E76:
	ldr r0, [r4, #4]
	movs r1, #0x80
	lsls r1, r1, #0x11
	ands r0, r1
	cmp r0, #0
	bne _08026E88
	adds r0, r4, #0
	bl Player_8005380
_08026E88:
	ldr r0, _08026EA4 @ =gStageData
	adds r0, #0xb7
	movs r1, #2
	strb r1, [r0]
	b _08027470
	.align 2, 0
_08026E94: .4byte gPlayers
_08026E98: .4byte gCamera
_08026E9C: .4byte 0xFFFEFFFF
_08026EA0: .4byte 0xEFFFFFDF
_08026EA4: .4byte gStageData
_08026EA8:
	adds r4, #0x12
	mov r0, sl
	cmp r0, #0
	beq _08026EBA
	ldr r0, _08026F08 @ =gStageData
	ldrb r0, [r0, #6]
	cmp r0, #0
	beq _08026EBA
	b _08027470
_08026EBA:
	ldrb r1, [r4, #1]
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r0, r1
	ldrb r2, [r4, #3]
	ldrb r1, [r4, #4]
	lsls r1, r1, #8
	orrs r1, r2
	bl sub_802790C
	ldr r1, _08026F08 @ =gStageData
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _08026ED8
	b _08027470
_08026ED8:
	ldrb r0, [r4, #1]
	ldrb r2, [r4, #2]
	lsls r2, r2, #8
	orrs r2, r0
	ldrb r3, [r4, #3]
	ldrb r4, [r4, #4]
	adds r1, #0x8f
	movs r0, #1
	strb r0, [r1]
	mov r1, sp
	movs r0, #0x28
	strb r0, [r1]
	lsls r2, r2, #8
	ldr r0, [sp]
	ldr r1, _08026F0C @ =0xFF0000FF
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	strb r3, [r0, #3]
	strb r4, [r0, #4]
	bl sub_8026AB8
	b _08027470
	.align 2, 0
_08026F08: .4byte gStageData
_08026F0C: .4byte 0xFF0000FF
_08026F10:
	subs r0, r5, #1
	cmp r0, #0x24
	bls _08026F18
	b _08027470
_08026F18:
	lsls r0, r0, #2
	ldr r1, _08026F24 @ =_08026F28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026F24: .4byte _08026F28
_08026F28: @ jump table
	.4byte _08026FBC @ case 0
	.4byte _08027470 @ case 1
	.4byte _08027074 @ case 2
	.4byte _08027470 @ case 3
	.4byte _08027064 @ case 4
	.4byte _080273A4 @ case 5
	.4byte _080270A8 @ case 6
	.4byte _08027108 @ case 7
	.4byte _0802715C @ case 8
	.4byte _080271A4 @ case 9
	.4byte _08027218 @ case 10
	.4byte _0802736C @ case 11
	.4byte _08027470 @ case 12
	.4byte _08027470 @ case 13
	.4byte _08027470 @ case 14
	.4byte _08027470 @ case 15
	.4byte _08027470 @ case 16
	.4byte _08027470 @ case 17
	.4byte _08027470 @ case 18
	.4byte _08027470 @ case 19
	.4byte _08027470 @ case 20
	.4byte _08027470 @ case 21
	.4byte _08027470 @ case 22
	.4byte _08027470 @ case 23
	.4byte _08027470 @ case 24
	.4byte _08027470 @ case 25
	.4byte _08027470 @ case 26
	.4byte _08027470 @ case 27
	.4byte _08027470 @ case 28
	.4byte _08027470 @ case 29
	.4byte _08027470 @ case 30
	.4byte _08027020 @ case 31
	.4byte _08027300 @ case 32
	.4byte _08027210 @ case 33
	.4byte _080271F8 @ case 34
	.4byte _0802737C @ case 35
	.4byte _0802738C @ case 36
_08026FBC:
	adds r2, r4, #0
	adds r2, #0x12
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08026FF8 @ =gPlayers
	adds r3, r0, r1
	ldr r4, _08026FFC @ =gStageData
	ldrb r0, [r2, #2]
	strb r0, [r4, #0xc]
	ldrb r0, [r2, #3]
	strh r0, [r4, #0x12]
	ldr r0, [r3, #4]
	ldr r1, _08027000 @ =0xEFFFFFFF
	ands r0, r1
	str r0, [r3, #4]
	ldrb r0, [r2, #3]
	cmp r0, #1
	bne _08027008
	ldrb r0, [r2, #4]
	strb r0, [r4, #9]
	ldr r4, _08027004 @ =Player_800AE14
	b _0802700A
	.align 2, 0
_08026FF8: .4byte gPlayers
_08026FFC: .4byte gStageData
_08027000: .4byte 0xEFFFFFFF
_08027004: .4byte Player_800AE14
_08027008:
	ldr r4, _0802701C @ =Player_800AD24
_0802700A:
	adds r0, r3, #0
	adds r1, r4, #0
	bl SetPlayerCallback
	adds r0, r6, #0
	adds r1, r4, #0
	bl SetPlayerCallback
	b _08027470
	.align 2, 0
_0802701C: .4byte Player_800AD24
_08027020:
	adds r2, r4, #0
	adds r2, #0x12
	ldr r0, _08027060 @ =gStageData
	ldrb r1, [r0, #0xb]
	adds r4, r0, #0
	ldrb r3, [r2, #2]
	cmp r1, r3
	bne _08027042
	ldrh r0, [r4, #0xe]
	ldrb r1, [r2, #3]
	cmp r0, r1
	bne _08027042
	ldrb r0, [r4, #9]
	ldrb r3, [r2, #4]
	cmp r0, r3
	bne _08027042
	b _08027470
_08027042:
	ldrb r0, [r2, #2]
	strb r0, [r4, #0xb]
	ldrb r0, [r2, #3]
	strh r0, [r4, #0xe]
	ldrb r0, [r2, #4]
	strb r0, [r4, #9]
	bl sub_8003D2C
	movs r1, #0xe
	ldrsh r0, [r4, r1]
	ldrb r1, [r4, #0xb]
	bl WarpToMap
	b _08027470
	.align 2, 0
_08027060: .4byte gStageData
_08027064:
	ldr r0, _08027070 @ =gStageData
	adds r0, #0xb6
	movs r1, #1
	strb r1, [r0]
	b _08027470
	.align 2, 0
_08027070: .4byte gStageData
_08027074:
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _080270A4 @ =gPlayers
	adds r2, r0, r1
	ldr r0, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0802709A
	b _08027470
_0802709A:
	adds r0, r2, #0
	bl Player_8009518
	b _08027470
	.align 2, 0
_080270A4: .4byte gPlayers
_080270A8:
	adds r5, r4, #0
	adds r5, #0x12
	ldrb r0, [r5, #2]
	ldr r2, _08027100 @ =gStageData
	ldrb r3, [r2, #6]
	asrs r0, r3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080270C8
	adds r1, r2, #0
	adds r1, #0xac
	ldrh r0, [r1]
	ldrb r2, [r5, #3]
	adds r0, r0, r2
	strh r0, [r1]
_080270C8:
	movs r3, #0
	movs r6, #1
_080270CC:
	ldrb r1, [r5, #2]
	lsls r0, r3, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	ands r0, r6
	asrs r1, r0
	ands r1, r6
	cmp r1, #0
	beq _080270F0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r4
	lsls r0, r0, #4
	ldr r1, _08027104 @ =gPlayers
	adds r0, r0, r1
	bl sub_8017A58
_080270F0:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080270CC
	b _08027470
	.align 2, 0
_08027100: .4byte gStageData
_08027104: .4byte gPlayers
_08027108:
	adds r6, r4, #0
	adds r6, #0x12
	movs r3, #0
	movs r5, #0
_08027110:
	ldrb r0, [r6, #2]
	lsls r1, r3, #0x10
	asrs r4, r1, #0x10
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08027148
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r4
	lsls r0, r0, #4
	ldr r1, _08027158 @ =gPlayers
	adds r2, r0, r1
	adds r1, r2, #0
	adds r1, #0x60
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x5e
	strh r5, [r0]
	adds r0, #4
	strh r5, [r0]
	adds r0, r2, #0
	bl sub_80179BC
_08027148:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08027110
	b _08027470
	.align 2, 0
_08027158: .4byte gPlayers
_0802715C:
	adds r2, r4, #0
	adds r2, #0x12
	movs r3, #0
	movs r5, #0
_08027164:
	ldrb r0, [r2, #2]
	lsls r1, r3, #0x10
	asrs r4, r1, #0x10
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08027196
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r4
	lsls r0, r0, #4
	mov r3, r8
	adds r1, r0, r3
	adds r3, r1, #0
	adds r3, #0x5e
	movs r0, #0x96
	lsls r0, r0, #3
	strh r0, [r3]
	adds r0, r1, #0
	adds r0, #0x60
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
_08027196:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08027164
	b _08027470
_080271A4:
	adds r6, r4, #0
	adds r6, #0x12
	movs r3, #0
	movs r5, #0
_080271AC:
	ldrb r0, [r6, #2]
	lsls r1, r3, #0x10
	asrs r4, r1, #0x10
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080271E4
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r4
	lsls r0, r0, #4
	ldr r1, _080271F4 @ =gPlayers
	adds r1, r0, r1
	adds r2, r1, #0
	adds r2, #0x62
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r2]
	adds r0, r1, #0
	adds r0, #0x5e
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, r1, #0
	bl sub_80179BC
_080271E4:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080271AC
	b _08027470
	.align 2, 0
_080271F4: .4byte gPlayers
_080271F8:
	ldr r1, _0802720C @ =gStageData
	ldrb r0, [r4, #0x15]
	subs r0, #1
	adds r1, #0xb4
	strb r0, [r1]
	movs r0, #1
	bl AddLives
	b _08027470
	.align 2, 0
_0802720C: .4byte gStageData
_08027210:
	ldr r1, _080272EC @ =gUnknown_03001060
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #9]
_08027218:
	adds r2, r4, #0
	adds r2, #0x12
	ldr r0, _080272F0 @ =gStageData
	mov r8, r0
	ldrb r3, [r0, #6]
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r0, r0, #4
	ldr r1, _080272F4 @ =gPlayers
	mov sb, r1
	adds r6, r0, r1
	movs r0, #1
	mov ip, r0
	ldr r5, _080272EC @ =gUnknown_03001060
	ldrb r1, [r5, #8]
	adds r0, r1, #0
	asrs r0, r3
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _0802724A
	movs r0, #0
	mov ip, r0
_0802724A:
	adds r0, r7, #0
	lsls r0, r3
	orrs r1, r0
	mov r3, sl
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r4, r7, #0
	lsls r4, r0
	orrs r1, r4
	strb r1, [r5, #8]
	adds r0, #4
	adds r3, r7, #0
	lsls r3, r0
	adds r1, r3, #0
	orrs r1, r4
	ldrb r0, [r5, #9]
	bics r0, r1
	strb r0, [r5, #9]
	ldrb r1, [r5, #9]
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _08027278
	orrs r1, r3
_08027278:
	strb r1, [r5, #9]
	ldrb r1, [r5, #9]
	ldrb r0, [r2, #3]
	cmp r0, #0
	beq _08027284
	orrs r1, r4
_08027284:
	strb r1, [r5, #9]
	ldr r1, [r6]
	ldr r0, _080272F8 @ =Player_8008A8C
	cmp r1, r0
	bne _08027290
	b _08027470
_08027290:
	ldr r0, _080272FC @ =Player_800ED80
	cmp r1, r0
	bne _08027298
	b _08027470
_08027298:
	mov r0, ip
	cmp r0, #0
	bne _080272A0
	b _08027470
_080272A0:
	bl sub_8026850
	ldrb r1, [r5, #9]
	mov r2, r8
	ldrb r0, [r2, #6]
	adds r0, #4
	asrs r1, r0
	ands r1, r7
	cmp r1, #0
	bne _080272B6
	b _08027470
_080272B6:
	adds r0, r6, #0
	bl sub_800ED50
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	mov r3, sb
	adds r2, r0, r3
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #0x1c
	ands r0, r1
	cmp r0, #8
	beq _080272E4
	b _08027470
_080272E4:
	adds r0, r2, #0
	bl sub_800ED50
	b _08027470
	.align 2, 0
_080272EC: .4byte gUnknown_03001060
_080272F0: .4byte gStageData
_080272F4: .4byte gPlayers
_080272F8: .4byte Player_8008A8C
_080272FC: .4byte Player_800ED80
_08027300:
	ldr r0, _08027360 @ =gStageData
	ldrb r1, [r0, #6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r5, _08027364 @ =gPlayers
	adds r4, r0, r5
	ldr r1, [r4]
	ldr r0, _08027368 @ =Player_800ED80
	cmp r1, r0
	beq _0802731C
	b _08027470
_0802731C:
	adds r0, r4, #0
	bl Player_8008C1C
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r2, r0, r5
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #0x1c
	ands r0, r1
	cmp r0, #8
	bne _0802734C
	adds r0, r2, #0
	bl Player_8008C1C
_0802734C:
	mov r1, sp
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #0x21
	strb r0, [r1, #1]
	mov r0, sp
	bl sub_8026AB8
	b _08027470
	.align 2, 0
_08027360: .4byte gStageData
_08027364: .4byte gPlayers
_08027368: .4byte Player_800ED80
_0802736C:
	adds r0, r4, #0
	adds r0, #0x12
	mov r2, sl
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	bl sub_807A0E8
	b _08027470
_0802737C:
	ldr r0, _08027388 @ =gStageData
	ldrb r1, [r4, #0x14]
	adds r0, #0xb4
	strb r1, [r0]
	b _08027470
	.align 2, 0
_08027388: .4byte gStageData
_0802738C:
	adds r0, r4, #0
	adds r0, #0x12
	ldr r1, _080273A0 @ =gStageData
	ldrb r2, [r0, #2]
	ldrb r0, [r0, #3]
	lsls r0, r0, #8
	orrs r0, r2
	adds r1, #0xae
	strh r0, [r1]
	b _08027470
	.align 2, 0
_080273A0: .4byte gStageData
_080273A4:
	adds r4, #0x12
	ldr r5, _080273EC @ =gStageData
	ldrb r0, [r5, #3]
	cmp r0, #6
	bne _080273F4
	adds r0, r5, #0
	adds r0, #0x98
	ldr r0, [r0]
	cmp r0, #0
	beq _08027470
	ldrb r1, [r4, #2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _080273F0 @ =gPlayers
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #1
	beq _080273E0
	adds r1, r2, #0
	adds r1, #0x54
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
_080273E0:
	movs r0, #0
	adds r1, r2, #0
	bl sub_801EBC0
	b _08027470
	.align 2, 0
_080273EC: .4byte gStageData
_080273F0: .4byte gPlayers
_080273F4:
	cmp r0, #7
	bne _08027470
	ldrb r0, [r5, #6]
	mov r3, sl
	cmp r3, #0
	beq _08027404
	cmp r0, #0
	bne _08027470
_08027404:
	cmp r0, #0
	bne _08027412
	adds r0, r5, #0
	adds r0, #0xae
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802742E
_08027412:
	ldrb r1, [r4, #2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08027458 @ =gPlayers
	adds r0, r0, r1
	bl sub_80293E8
	ldrb r1, [r4, #2]
	adds r0, r5, #0
	adds r0, #0x8e
	strb r1, [r0]
_0802742E:
	ldr r3, _0802745C @ =gStageData
	ldrb r0, [r3, #6]
	cmp r0, #0
	bne _08027470
	ldrb r2, [r4, #2]
	mov r1, sp
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #6
	strb r0, [r1, #1]
	adds r0, r3, #0
	adds r0, #0xae
	ldrh r0, [r0]
	cmp r0, #0
	bne _08027460
	mov r0, sp
	adds r1, r3, #0
	adds r1, #0x8e
	ldrb r1, [r1]
	strb r1, [r0, #2]
	b _0802746A
	.align 2, 0
_08027458: .4byte gPlayers
_0802745C: .4byte gStageData
_08027460:
	mov r0, sp
	strb r2, [r0, #2]
	adds r0, r3, #0
	adds r0, #0x8e
	strb r2, [r0]
_0802746A:
	mov r0, sp
	bl sub_8026AB8
_08027470:
	ldr r2, _080274A8 @ =gPlayers
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #4
	adds r1, r1, r2
	adds r1, #0x2c
	ldr r2, [sp, #8]
	lsls r3, r2, #3
	ldrb r2, [r1]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
_08027496_return:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080274A8: .4byte gPlayers

.syntax divided
