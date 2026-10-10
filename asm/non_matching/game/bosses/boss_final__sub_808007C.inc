.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, _080800B4 @ =gPlayers
	ldr r1, _080800B8 @ =gStageData
	movs r2, #0
	movs r0, #9
	strb r0, [r1, #4]
	ldrh r1, [r4, #0x12]
	cmp r1, #0xbe
	bne _08080092
	b _08080374
_08080092:
	cmp r1, #0xbe
	bgt _080800EE
	cmp r1, #0x82
	bne _0808009C
	b _08080200
_0808009C:
	cmp r1, #0x82
	bgt _080800C8
	cmp r1, #0x64
	beq _0808017E
	cmp r1, #0x64
	bgt _080800BC
	cmp r1, #0
	beq _0808015A
	cmp r1, #0xa
	beq _08080168
	b _080804AC
	.align 2, 0
_080800B4: .4byte gPlayers
_080800B8: .4byte gStageData
_080800BC:
	cmp r1, #0x6e
	beq _080801A8
	cmp r1, #0x78
	bne _080800C6
	b _080801D4
_080800C6:
	b _080804AC
_080800C8:
	cmp r1, #0xab
	bne _080800CE
	b _08080318
_080800CE:
	cmp r1, #0xab
	bgt _080800E0
	cmp r1, #0x8c
	bne _080800D8
	b _08080230
_080800D8:
	cmp r1, #0xaa
	bne _080800DE
	b _080802F8
_080800DE:
	b _080804AC
_080800E0:
	cmp r1, #0xac
	bne _080800E6
	b _08080334
_080800E6:
	cmp r1, #0xb4
	bne _080800EC
	b _08080358
_080800EC:
	b _080804AC
_080800EE:
	cmp r1, #0xfa
	bne _080800F4
	b _0808048C
_080800F4:
	cmp r1, #0xfa
	bgt _0808011E
	cmp r1, #0xdc
	bne _080800FE
	b _080803FC
_080800FE:
	cmp r1, #0xdc
	bgt _08080110
	cmp r1, #0xc8
	bne _08080108
	b _080803A0
_08080108:
	cmp r1, #0xd2
	bne _0808010E
	b _080803D8
_0808010E:
	b _080804AC
_08080110:
	cmp r1, #0xe6
	bne _08080116
	b _0808043C
_08080116:
	cmp r1, #0xf0
	bne _0808011C
	b _08080460
_0808011C:
	b _080804AC
_0808011E:
	movs r2, #0x82
	lsls r2, r2, #2
	cmp r1, r2
	bne _08080128
	b _0808028E
_08080128:
	cmp r1, r2
	bgt _08080140
	movs r0, #0xfa
	lsls r0, r0, #1
	cmp r1, r0
	bne _08080136
	b _08080250
_08080136:
	adds r0, #0xa
	cmp r1, r0
	bne _0808013E
	b _08080274
_0808013E:
	b _080804AC
_08080140:
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r1, r0
	bne _0808014A
	b _08080420
_0808014A:
	cmp r1, r0
	ble _08080150
	b _080804AC
_08080150:
	subs r0, #0x46
	cmp r1, r0
	bne _08080158
	b _080802D0
_08080158:
	b _080804AC
_0808015A:
	ldr r0, _08080164 @ =0x00000181
	strh r0, [r4, #0x10]
	movs r0, #0xa
	b _080804AA
	.align 2, 0
_08080164: .4byte 0x00000181
_08080168:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08080176
	b _080804AC
_08080176:
	movs r0, #0x87
	strh r0, [r4, #0x10]
	movs r0, #0x64
	b _080804AA
_0808017E:
	ldrh r0, [r4, #0x14]
	movs r3, #0x10
	movs r2, #0
	orrs r0, r3
	strh r0, [r4, #0x14]
	ldrh r1, [r4, #0x10]
	movs r5, #0x10
	ldrsh r0, [r4, r5]
	cmp r0, #0x45
	bgt _08080198
	ldrh r0, [r4, #0x16]
	orrs r0, r3
	strh r0, [r4, #0x16]
_08080198:
	subs r0, r1, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080801A4
	b _080804AC
_080801A4:
	movs r0, #0x6e
	b _080804AA
_080801A8:
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	ldr r1, _080801D0 @ =0x0000085C
	cmp r0, r1
	bgt _080801B4
	b _080804AC
_080801B4:
	strh r2, [r5, #0x1c]
	strh r2, [r5, #0x18]
	strh r2, [r5, #0x1a]
	adds r0, r5, #0
	bl Player_8005380
	movs r0, #0xd6
	strh r0, [r4, #0x10]
	movs r0, #0x78
	strh r0, [r4, #0x12]
	movs r0, #0xc8
	bl sub_807FB7C
	b _080804AC
	.align 2, 0
_080801D0: .4byte 0x0000085C
_080801D4:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080801E2
	b _080804AC
_080801E2:
	ldr r1, _080801F8 @ =Player_8008CD0
	adds r0, r5, #0
	bl SetPlayerCallback
	ldr r0, _080801FC @ =0x0000029A
	bl m4aSongNumStart
	movs r0, #0xa
	strh r0, [r4, #0xc]
	movs r0, #0x82
	b _080804AA
	.align 2, 0
_080801F8: .4byte Player_8008CD0
_080801FC: .4byte 0x0000029A
_08080200:
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	ldr r1, _0808022C @ =0x00000803
	cmp r0, r1
	ble _0808020C
	b _080804AC
_0808020C:
	ldr r0, [r5, #4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #4]
	strh r2, [r5, #0x1c]
	strh r2, [r5, #0x18]
	strh r2, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x4a
	strh r2, [r0]
	adds r0, r5, #0
	bl Player_8005380
	movs r0, #0x8c
	b _080804AA
	.align 2, 0
_0808022C: .4byte 0x00000803
_08080230:
	ldr r0, _0808024C @ =gBldRegs
	ldrh r0, [r0, #4]
	cmp r0, #0x10
	beq _0808023A
	b _080804AC
_0808023A:
	ldrh r1, [r4, #0x14]
	movs r0, #0x80
	orrs r0, r1
	strh r0, [r4, #0x14]
	movs r0, #0xd2
	lsls r0, r0, #1
	strh r0, [r4, #0x10]
	adds r0, #0x50
	b _080804AA
	.align 2, 0
_0808024C: .4byte gBldRegs
_08080250:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808025E
	b _080804AC
_0808025E:
	ldr r1, _08080270 @ =Player_8008CD0
	adds r0, r5, #0
	bl SetPlayerCallback
	movs r0, #0xb4
	strh r0, [r4, #0x10]
	movs r0, #0xff
	lsls r0, r0, #1
	b _080804AA
	.align 2, 0
_08080270: .4byte Player_8008CD0
_08080274:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08080284
	b _080804AC
_08080284:
	strh r2, [r4, #0x12]
	adds r0, r5, #0
	adds r0, #0x4a
	strh r1, [r0]
	b _080804AC
_0808028E:
	ldrh r1, [r4, #0x14]
	movs r0, #0x10
	movs r7, #0
	orrs r0, r1
	strh r0, [r4, #0x14]
	ldr r1, [r5, #0x10]
	asrs r1, r1, #8
	ldr r6, _080802C8 @ =gCamera
	ldr r0, [r6]
	adds r0, #0x78
	cmp r1, r0
	bge _080802A8
	b _080804AC
_080802A8:
	movs r0, #0x64
	bl sub_807FB7C
	ldr r0, [r6]
	adds r0, #0x78
	lsls r0, r0, #8
	str r0, [r5, #0x10]
	movs r0, #0x3c
	strh r0, [r4, #0x10]
	ldr r0, _080802CC @ =0x00000212
	strh r0, [r4, #0x12]
	movs r0, #0x73      @ SE_STOPPING
	bl m4aSongNumStart
	b _080804AC
	.align 2, 0
_080802C8: .4byte gCamera
_080802CC: .4byte 0x00000212
_080802D0:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080802DE
	b _080804AC
_080802DE:
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r5, #0x30]
	adds r0, #0xba
	strh r0, [r4, #0x10]
	movs r0, #0xaa
	strh r0, [r4, #0x12]
	movs r0, #0x64
	strh r0, [r4, #0xc]
	movs r0, #0x3d      @ MUS_EX_DEMO_2
	bl m4aSongNumStart
	b _080804AC
_080802F8:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08080306
	b _080804AC
_08080306:
	ldr r0, _08080314 @ =0x00000127
	strh r0, [r5, #0x30]
	movs r0, #0x1e
	strh r0, [r4, #0x10]
	movs r0, #0xab
	b _080804AA
	.align 2, 0
_08080314: .4byte 0x00000127
_08080318:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08080326
	b _080804AC
_08080326:
	ldr r0, _08080330 @ =0x0000FF80
	strh r0, [r5, #0x1a]
	movs r0, #0xac
	b _080804AA
	.align 2, 0
_08080330: .4byte 0x0000FF80
_08080334:
	movs r1, #0x1a
	ldrsh r0, [r5, r1]
	ldr r1, [r5, #0x14]
	adds r1, r1, r0
	str r1, [r5, #0x14]
	asrs r1, r1, #8
	ldr r0, _08080354 @ =gCamera
	ldr r0, [r0, #4]
	adds r0, #0x64
	cmp r1, r0
	ble _0808034C
	b _080804AC
_0808034C:
	movs r0, #1
	strh r0, [r4, #0x10]
	movs r0, #0xb4
	b _080804AA
	.align 2, 0
_08080354: .4byte gCamera
_08080358:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08080366
	b _080804AC
_08080366:
	movs r0, #0x94
	lsls r0, r0, #1
	strh r0, [r5, #0x30]
	movs r0, #0x78
	strh r0, [r4, #0x10]
	movs r0, #0xbe
	b _080804AA
_08080374:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	beq _08080384
	b _080804AC
_08080384:
	ldr r1, _08080398 @ =gBldRegs
	ldr r0, _0808039C @ =0x00003FBF
	strh r0, [r1]
	movs r0, #8
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r0, #1
	strh r0, [r4, #0x10]
	movs r0, #0xc8
	b _080804AA
	.align 2, 0
_08080398: .4byte gBldRegs
_0808039C: .4byte 0x00003FBF
_080803A0:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080803AE
	b _080804AC
_080803AE:
	movs r0, #4
	strh r0, [r4, #0x10]
	ldr r1, _080803D4 @ =gBldRegs
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _080804AC
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	movs r0, #0x3c
	strh r0, [r4, #0x10]
	movs r0, #0xd2
	b _080804AA
	.align 2, 0
_080803D4: .4byte gBldRegs
_080803D8:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080804AC
	ldr r0, _080803F4 @ =0x00000129
	strh r0, [r5, #0x30]
	movs r0, #0xdc
	strh r0, [r4, #0x12]
	ldr r0, _080803F8 @ =0x0000023F
	bl m4aSongNumStart
	b _080804AC
	.align 2, 0
_080803F4: .4byte 0x00000129
_080803F8: .4byte 0x0000023F
_080803FC:
	ldr r1, _0808041C @ =gBldRegs
	ldrh r0, [r1, #4]
	subs r0, #1
	strh r0, [r1, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080804AC
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r0, #0x78
	strh r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #2
	b _080804AA
	.align 2, 0
_0808041C: .4byte gBldRegs
_08080420:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080804AC
	ldr r0, [r5, #4]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0x78
	strh r0, [r4, #0x10]
	movs r0, #0xe6
	b _080804AA
_0808043C:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080804AC
	ldr r0, [r5, #4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #4]
	movs r0, #0x95
	lsls r0, r0, #1
	strh r0, [r5, #0x30]
	movs r0, #0x1e
	strh r0, [r4, #0x10]
	movs r0, #0xf0
	b _080804AA
_08080460:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _080804AC
	ldr r0, _08080488 @ =0x0000012B
	strh r0, [r5, #0x30]
	strh r1, [r5, #0x18]
	movs r0, #0xfe
	lsls r0, r0, #8
	strh r0, [r5, #0x1a]
	movs r0, #0xfa
	strh r0, [r4, #0x12]
	movs r0, #0x70
	bl m4aSongNumStart
	b _080804AC
	.align 2, 0
_08080488: .4byte 0x0000012B
_0808048C:
	ldrh r0, [r5, #0x1a]
	subs r0, #0x2a
	strh r0, [r5, #0x1a]
	movs r0, #0x1a
	ldrsh r1, [r5, r0]
	ldr r0, [r5, #0x14]
	adds r0, r0, r1
	str r0, [r5, #0x14]
	asrs r0, r0, #8
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080804AC
	movs r0, #0x96
	lsls r0, r0, #1
_080804AA:
	strh r0, [r4, #0x12]
_080804AC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
