.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldrh r1, [r5, #0x16]
	cmp r1, #0x6e
	bne _0807ED9E
	b _0807F200
_0807ED9E:
	cmp r1, #0x6e
	bgt _0807EDB6
	cmp r1, #1
	beq _0807EDFE
	cmp r1, #1
	bgt _0807EDB0
	cmp r1, #0
	beq _0807EDDA
	b _0807F200
_0807EDB0:
	cmp r1, #0x64
	beq _0807EE64
	b _0807F200
_0807EDB6:
	cmp r1, #0xd2
	bne _0807EDBC
	b _0807F010
_0807EDBC:
	cmp r1, #0xd2
	bgt _0807EDC8
	cmp r1, #0xc8
	bne _0807EDC6
	b _0807EF44
_0807EDC6:
	b _0807F200
_0807EDC8:
	cmp r1, #0xdc
	bne _0807EDCE
	b _0807F064
_0807EDCE:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _0807EDD8
	b _0807F1A0
_0807EDD8:
	b _0807F200
_0807EDDA:
	ldrb r0, [r5, #1]
	cmp r0, #4
	ble _0807EDE2
	b _0807F200
_0807EDE2:
	cmp r0, #1
	bge _0807EDE8
	b _0807F200
_0807EDE8:
	adds r0, r5, #0
	bl sub_807F228
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807EDF6
	b _0807F200
_0807EDF6:
	adds r0, r5, #0
	bl sub_807F434
	b _0807F200
_0807EDFE:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	beq _0807EE0E
	b _0807F200
_0807EE0E:
	adds r0, r5, #0
	movs r1, #1
	bl sub_807BE58
	ldrb r0, [r5]
	cmp r0, #0
	beq _0807EE34
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r1, _0807EE30 @ =gUnknown_080D5C38
	ldrh r0, [r1]
	strh r0, [r2, #0xc]
	ldrh r0, [r1, #2]
	strb r0, [r2, #0x1a]
	strh r4, [r5, #0x16]
	b _0807F200
	.align 2, 0
_0807EE30: .4byte gUnknown_080D5C38
_0807EE34:
	ldr r1, _0807EE48 @ =gStageData
	ldrb r0, [r1, #3]
	cmp r0, #5
	bne _0807EE58
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _0807EE4C
	movs r0, #0x6e
	strh r0, [r5, #0x16]
	b _0807F200
	.align 2, 0
_0807EE48: .4byte gStageData
_0807EE4C:
	adds r0, r1, #0
	adds r0, #0xae
	ldrh r1, [r0]
	movs r0, #1
	bl sub_8027674
_0807EE58:
	adds r0, r5, #0
	bl sub_8081C08
	movs r0, #0x64
	strh r0, [r5, #0x16]
	b _0807F200
_0807EE64:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807EE72
	b _0807F200
_0807EE72:
	movs r3, #0
	ldr r4, _0807EEA8 @ =gPlayers
_0807EE76:
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r2, r0, r4
	ldr r0, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807EEAC
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #0x1c
	ands r1, r0
	cmp r1, #4
	beq _0807EEA0
	cmp r1, #0xc
	bne _0807EEAC
_0807EEA0:
	movs r0, #4
	strh r0, [r5, #0x14]
	b _0807F200
	.align 2, 0
_0807EEA8: .4byte gPlayers
_0807EEAC:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _0807EE76
	ldr r1, _0807EEE8 @ =gStageData
	movs r0, #4
	strb r0, [r1, #4]
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_807BE58
	movs r0, #0x80
	lsls r0, r0, #4
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0xd3
	str r1, [sp]
	movs r1, #4
	movs r2, #0
	bl CreateScreenShake
	ldrb r0, [r5]
	cmp r0, #0
	beq _0807EEEC
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _0807EEEE
	.align 2, 0
_0807EEE8: .4byte gStageData
_0807EEEC:
	movs r1, #0
_0807EEEE:
	ldr r0, _0807EF38 @ =gUnknown_080D5C48
	adds r0, r1, r0
	ldrb r0, [r0]
	movs r1, #0
	strh r0, [r5, #8]
	strh r1, [r5, #0xc]
	movs r0, #5
	strb r0, [r5, #1]
	adds r0, r5, #0
	movs r2, #0xb
	bl sub_807DB00
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0xb
	bl sub_807DB00
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r1, _0807EF3C @ =gUnknown_080D5C38
	ldrh r0, [r1, #0xc]
	strh r0, [r2, #0xc]
	ldrh r0, [r1, #0xe]
	strb r0, [r2, #0x1a]
	ldr r0, _0807EF40 @ =0x00000221
	bl m4aSongNumStart
	movs r0, #0x96
	bl sub_807FB7C
	movs r0, #0
	bl sub_807FB7C
	movs r0, #0xc8
	strh r0, [r5, #0x16]
	b _0807F200
	.align 2, 0
_0807EF38: .4byte gUnknown_080D5C48
_0807EF3C: .4byte gUnknown_080D5C38
_0807EF40: .4byte 0x00000221
_0807EF44:
	ldrh r1, [r5, #0x14]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807EFC4
	ldr r3, _0807EFF8 @ =gPseudoRandom
	ldr r0, [r3]
	ldr r2, _0807EFFC @ =0x00196225
	muls r0, r2, r0
	ldr r1, _0807F000 @ =0x3C6EF35F
	adds r0, r0, r1
	ldr r7, _0807F004 @ =0x000003FF
	ands r7, r0
	muls r0, r2, r0
	adds r0, r0, r1
	str r0, [r3]
	movs r1, #0x30
	bl __umodsi3
	adds r2, r0, #0
	ldr r1, _0807F008 @ =gSineTable
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r7, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	lsrs r4, r0, #6
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r2, r0
	lsrs r6, r0, #6
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r1, r1, r4
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	adds r2, r2, r6
	asrs r2, r2, #8
	subs r2, #0x30
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #0xc0
	lsls r3, r3, #2
	str r7, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, [r5, #0x18]
	str r0, [sp, #0xc]
	movs r0, #7
	bl sub_8079758
_0807EFC4:
	ldrh r0, [r5, #0x14]
	adds r0, #1
	strh r0, [r5, #0x14]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _0807EFD8
	ldr r0, _0807F00C @ =0x00000221
	bl m4aSongNumStart
_0807EFD8:
	movs r3, #0x97
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807EFE6
	b _0807F200
_0807EFE6:
	movs r0, #0xd2
	strh r0, [r5, #0x16]
	movs r0, #0x3c
	strh r0, [r5, #0x14]
	movs r0, #0xa
	bl sub_807FB7C
	b _0807F200
	.align 2, 0
_0807EFF8: .4byte gPseudoRandom
_0807EFFC: .4byte 0x00196225
_0807F000: .4byte 0x3C6EF35F
_0807F004: .4byte 0x000003FF
_0807F008: .4byte gSineTable
_0807F00C: .4byte 0x00000221
_0807F010:
	movs r1, #0
	ldr r3, _0807F058 @ =gPlayers
	movs r2, #0xb4
	lsls r2, r2, #1
_0807F018:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r3
	adds r0, #0x52
	strh r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _0807F018
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807F040
	b _0807F200
_0807F040:
	movs r0, #0xb4
	strh r0, [r5, #0x14]
	movs r0, #0xdc
	strh r0, [r5, #0x16]
	ldr r0, _0807F05C @ =0x00000221
	bl m4aSongNumStart
	ldr r1, _0807F060 @ =gMusicManagerState
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1, #6]
	b _0807F200
	.align 2, 0
_0807F058: .4byte gPlayers
_0807F05C: .4byte 0x00000221
_0807F060: .4byte gMusicManagerState
_0807F064:
	movs r1, #0
	ldr r3, _0807F14C @ =gPlayers
	movs r2, #0xb4
	lsls r2, r2, #1
_0807F06C:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r3
	adds r0, #0x52
	strh r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _0807F06C
	ldrh r1, [r5, #0x14]
	movs r4, #1
	mov r8, r4
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _0807F120
	ldr r4, _0807F150 @ =gPseudoRandom
	ldr r0, [r4]
	ldr r3, _0807F154 @ =0x00196225
	adds r1, r0, #0
	muls r1, r3, r1
	ldr r2, _0807F158 @ =0x3C6EF35F
	adds r1, r1, r2
	movs r0, #0xff
	ands r0, r1
	movs r6, #0xa0
	lsls r6, r6, #2
	adds r7, r0, r6
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	str r0, [r4]
	movs r1, #0x30
	bl __umodsi3
	adds r2, r0, #0
	movs r0, #3
	adds r3, r2, #0
	ands r3, r0
	lsls r3, r3, #8
	ldr r1, _0807F15C @ =gSineTable
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r7, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r2, r0
	lsrs r4, r0, #6
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	lsrs r6, r0, #6
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r1, r1, r4
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	movs r4, #0x90
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r2, [r0]
	adds r2, r2, r6
	asrs r2, r2, #8
	subs r2, #0x60
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r6, #0x80
	lsls r6, r6, #3
	adds r0, r6, #0
	orrs r3, r0
	str r7, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, [r5, #0x18]
	str r0, [sp, #0xc]
	movs r0, #7
	bl sub_8079758
_0807F120:
	ldrh r1, [r5, #0x14]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _0807F130
	ldr r0, _0807F160 @ =0x00000221
	bl m4aSongNumStart
_0807F130:
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	ldrh r3, [r5, #0x14]
	cmp r0, #0x3c
	bne _0807F16C
	ldr r1, _0807F164 @ =gBldRegs
	movs r2, #0
	ldr r0, _0807F168 @ =0x00003FBF
	strh r0, [r1]
	movs r0, #8
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	b _0807F184
	.align 2, 0
_0807F14C: .4byte gPlayers
_0807F150: .4byte gPseudoRandom
_0807F154: .4byte 0x00196225
_0807F158: .4byte 0x3C6EF35F
_0807F15C: .4byte gSineTable
_0807F160: .4byte 0x00000221
_0807F164: .4byte gBldRegs
_0807F168: .4byte 0x00003FBF
_0807F16C:
	cmp r0, #0x3b
	bgt _0807F184
	mov r0, r8
	ands r0, r3
	cmp r0, #0
	beq _0807F184
	ldr r1, _0807F19C @ =gBldRegs
	ldrh r0, [r1, #4]
	cmp r0, #0x10
	beq _0807F184
	adds r0, #1
	strh r0, [r1, #4]
_0807F184:
	subs r0, r3, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807F200
	movs r0, #0x3c
	strh r0, [r5, #0x14]
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r5, #0x16]
	b _0807F200
	.align 2, 0
_0807F19C: .4byte gBldRegs
_0807F1A0:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _0807F200
	movs r0, #1
	strh r0, [r5, #8]
	strh r1, [r5, #0xc]
	ldr r0, _0807F20C @ =gStageData
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0807F1F8
	ldr r4, _0807F210 @ =gPlayers
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r2, r4, r3
	ldr r0, [r2]
	ldr r1, _0807F214 @ =0xFFFFFEFF
	ands r0, r1
	str r0, [r2]
	movs r6, #0xa8
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r1, _0807F218 @ =Player_8005380
	bl SetPlayerCallback
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r4, #0x10]
	str r0, [r1]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r0, [r4, #0x14]
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r0, [r0]
	ldr r3, _0807F21C @ =0x00000177
	adds r1, r4, r3
	strb r0, [r1]
_0807F1F8:
	ldr r0, _0807F220 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _0807F224 @ =sub_807F568
	str r0, [r1, #8]
_0807F200:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F20C: .4byte gStageData
_0807F210: .4byte gPlayers
_0807F214: .4byte 0xFFFFFEFF
_0807F218: .4byte Player_8005380
_0807F21C: .4byte 0x00000177
_0807F220: .4byte gCurTask
_0807F224: .4byte sub_807F568

.syntax divided
