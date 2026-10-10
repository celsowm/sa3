.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0807F61C @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r7, r1, r0
	ldr r0, _0807F620 @ =gStageData
	adds r0, #0xac
	movs r1, #0
	strh r1, [r0]
	adds r0, r7, #0
	bl sub_807C14C
	movs r4, #0
	ldr r5, _0807F624 @ =gCamera
_0807F58C:
	lsls r3, r4, #2
	adds r3, r3, r4
	lsls r0, r3, #3
	adds r0, #0x7c
	adds r0, r7, r0
	lsls r3, r3, #2
	adds r1, r7, #0
	adds r1, #0x2c
	adds r1, r1, r3
	ldr r1, [r1]
	asrs r1, r1, #8
	ldr r2, [r5]
	subs r1, r1, r2
	strh r1, [r0, #0x10]
	adds r1, r7, #0
	adds r1, #0x30
	adds r1, r1, r3
	ldr r1, [r1]
	asrs r1, r1, #8
	ldr r2, [r5, #4]
	subs r1, r1, r2
	strh r1, [r0, #0x12]
	bl DisplaySprite
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0807F58C
	ldrh r1, [r7, #0xc]
	ldr r0, _0807F628 @ =0x00000406
	cmp r1, r0
	beq _0807F5F0
	movs r1, #0
	ldr r3, _0807F62C @ =gPlayers
	movs r2, #0xb4
	lsls r2, r2, #1
_0807F5D6:
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
	bls _0807F5D6
_0807F5F0:
	ldrh r1, [r7, #0xc]
	ldr r2, _0807F630 @ =0x000007DA
	cmp r1, r2
	bne _0807F5FA
	b _0807F904
_0807F5FA:
	cmp r1, r2
	bgt _0807F684
	ldr r4, _0807F634 @ =0x000003E9
	cmp r1, r4
	bne _0807F606
	b _0807F80C
_0807F606:
	cmp r1, r4
	bgt _0807F64A
	cmp r1, #0xa
	bne _0807F610
	b _0807F7BC
_0807F610:
	cmp r1, #0xa
	bgt _0807F638
	cmp r1, #0
	beq _0807F700
	b _0807FB6C
	.align 2, 0
_0807F61C: .4byte gCurTask
_0807F620: .4byte gStageData
_0807F624: .4byte gCamera
_0807F628: .4byte 0x00000406
_0807F62C: .4byte gPlayers
_0807F630: .4byte 0x000007DA
_0807F634: .4byte 0x000003E9
_0807F638:
	cmp r1, #0x64
	bne _0807F63E
	b _0807F7C2
_0807F63E:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _0807F648
	b _0807F7DA
_0807F648:
	b _0807FB6C
_0807F64A:
	ldr r0, _0807F66C @ =0x00000406
	mov r8, r0
	cmp r1, r8
	bne _0807F654
	b _0807FB6C
_0807F654:
	cmp r1, r8
	bgt _0807F670
	subs r0, #0x14
	cmp r1, r0
	bne _0807F660
	b _0807F834
_0807F660:
	adds r0, #0xa
	cmp r1, r0
	bne _0807F668
	b _0807F84A
_0807F668:
	b _0807FB6C
	.align 2, 0
_0807F66C: .4byte 0x00000406
_0807F670:
	movs r0, #0xfa
	lsls r0, r0, #3
	cmp r1, r0
	bne _0807F67A
	b _0807F898
_0807F67A:
	adds r0, #1
	cmp r1, r0
	bne _0807F682
	b _0807F8DC
_0807F682:
	b _0807FB6C
_0807F684:
	ldr r4, _0807F6A8 @ =0x00000802
	cmp r1, r4
	bne _0807F68C
	b _0807FAA0
_0807F68C:
	cmp r1, r4
	bgt _0807F6CC
	ldr r5, _0807F6AC @ =0x000007EE
	cmp r1, r5
	bne _0807F698
	b _0807F994
_0807F698:
	cmp r1, r5
	bgt _0807F6B4
	ldr r0, _0807F6B0 @ =0x000007E4
	cmp r1, r0
	bne _0807F6A4
	b _0807F934
_0807F6A4:
	b _0807FB6C
	.align 2, 0
_0807F6A8: .4byte 0x00000802
_0807F6AC: .4byte 0x000007EE
_0807F6B0: .4byte 0x000007E4
_0807F6B4:
	ldr r0, _0807F6C8 @ =0x000007F3
	cmp r1, r0
	bne _0807F6BC
	b _0807F9EC
_0807F6BC:
	adds r0, #5
	cmp r1, r0
	bne _0807F6C4
	b _0807FA2A
_0807F6C4:
	b _0807FB6C
	.align 2, 0
_0807F6C8: .4byte 0x000007F3
_0807F6CC:
	movs r5, #0x82
	lsls r5, r5, #4
	cmp r1, r5
	bne _0807F6D6
	b _0807FB40
_0807F6D6:
	cmp r1, r5
	bgt _0807F6F0
	ldr r0, _0807F6EC @ =0x0000080C
	cmp r1, r0
	bne _0807F6E2
	b _0807FAD6
_0807F6E2:
	adds r0, #0xa
	cmp r1, r0
	bne _0807F6EA
	b _0807FAFC
_0807F6EA:
	b _0807FB6C
	.align 2, 0
_0807F6EC: .4byte 0x0000080C
_0807F6F0:
	ldr r0, _0807F6FC @ =0x000008FC
	cmp r1, r0
	bne _0807F6F8
	b _0807FB58
_0807F6F8:
	b _0807FB6C
	.align 2, 0
_0807F6FC: .4byte 0x000008FC
_0807F700:
	ldr r6, _0807F7A8 @ =gStageData
	ldrb r1, [r6, #6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r2, _0807F7AC @ =gPlayers
	adds r0, r0, r2
	adds r1, r0, #0
	adds r1, #0x4a
	movs r5, #0
	strh r5, [r1]
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r2
	adds r0, #0x4a
	strh r5, [r0]
	ldr r0, [r7, #0x18]
	cmp r0, #0
	beq _0807F73E
	bl VramFree
	str r5, [r7, #0x18]
_0807F73E:
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	cmp r0, #0
	beq _0807F750
	bl VramFree
	str r5, [r4]
_0807F750:
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r4, r7, r2
	ldr r0, [r4]
	cmp r0, #0
	beq _0807F762
	bl VramFree
	str r5, [r4]
_0807F762:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0807F774
	bl VramFree
	str r5, [r4]
_0807F774:
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	cmp r0, #0
	beq _0807F786
	bl VramFree
	str r5, [r4]
_0807F786:
	ldr r2, _0807F7B0 @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _0807F7B4 @ =0x00009EFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0807F7B8 @ =gBgScrollRegs
	strh r5, [r0]
	strh r5, [r0, #2]
	bl sub_80299FC
	movs r0, #9
	strb r0, [r6, #4]
	movs r0, #7
	strb r0, [r6, #9]
	movs r0, #0xa
	strh r0, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807F7A8: .4byte gStageData
_0807F7AC: .4byte gPlayers
_0807F7B0: .4byte gDispCnt
_0807F7B4: .4byte 0x00009EFF
_0807F7B8: .4byte gBgScrollRegs
_0807F7BC:
	movs r0, #0x64
	strh r0, [r7, #0xc]
	b _0807FB6C
_0807F7C2:
	bl MetExtraBossEnableConditions
	cmp r0, #0
	beq _0807F7D2
	movs r0, #0xfa
	lsls r0, r0, #3
	strh r0, [r7, #0xc]
	b _0807FB6C
_0807F7D2:
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r7, #0xc]
	b _0807FB6C
_0807F7DA:
	movs r0, #1
	bl sub_807FB7C
	movs r0, #0
	bl sub_808178C
	movs r0, #0
	bl sub_80808E8
	movs r0, #2
	bl sub_807FB7C
	ldr r0, _0807F808 @ =gCamera
	ldr r1, [r0, #0x1c]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r1, r2
	str r1, [r0, #0x1c]
	movs r0, #0x96
	lsls r0, r0, #3
	strh r0, [r7, #8]
	strh r4, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807F808: .4byte gCamera
_0807F80C:
	ldr r1, _0807F830 @ =gBldRegs
	ldrh r0, [r1, #4]
	subs r0, #1
	strh r0, [r1, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _0807F81E
	b _0807FB6C
_0807F81E:
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r0, #0x96
	lsls r0, r0, #3
	strh r0, [r7, #8]
	subs r0, #0xbe
	strh r0, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807F830: .4byte gBldRegs
_0807F834:
	ldrh r0, [r7, #8]
	subs r0, #1
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807F842
	b _0807FB6C
_0807F842:
	movs r0, #0xff
	lsls r0, r0, #2
	strh r0, [r7, #0xc]
	b _0807FB6C
_0807F84A:
	ldr r0, _0807F88C @ =gStageData
	ldrb r1, [r0, #6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r4, _0807F890 @ =gPlayers
	adds r6, r0, r4
	ldr r5, _0807F894 @ =Player_8005E80
	adds r0, r6, #0
	adds r1, r5, #0
	bl SetPlayerCallback
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
	adds r6, r0, r4
	adds r0, r6, #0
	adds r1, r5, #0
	bl SetPlayerCallback
	mov r4, r8
	strh r4, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807F88C: .4byte gStageData
_0807F890: .4byte gPlayers
_0807F894: .4byte Player_8005E80
_0807F898:
	movs r0, #1
	bl sub_807FB7C
	movs r0, #1
	bl sub_80808E8
	str r0, [r7, #0x28]
	movs r0, #1
	bl sub_808178C
	movs r0, #2
	bl sub_807FB7C
	ldr r1, _0807F8D4 @ =gCamera
	ldr r0, [r1, #0x1c]
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1, #0x1c]
	ldr r0, [r1, #4]
	str r0, [r1, #0x10]
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r7, #8]
	bl m4aMPlayAllStop
	ldr r0, _0807F8D8 @ =0x000007D1
	strh r0, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807F8D4: .4byte gCamera
_0807F8D8: .4byte 0x000007D1
_0807F8DC:
	ldr r1, _0807F900 @ =gBldRegs
	ldrh r0, [r1, #4]
	subs r0, #1
	strh r0, [r1, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _0807F8EE
	b _0807FB6C
_0807F8EE:
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r7, #8]
	strh r2, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807F900: .4byte gBldRegs
_0807F904:
	ldrh r0, [r7, #8]
	subs r0, #1
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807F912
	b _0807FB6C
_0807F912:
	ldr r1, _0807F92C @ =gCamera
	ldr r0, [r1, #0x1c]
	subs r0, #0xf0
	str r0, [r1, #0x18]
	movs r0, #0xc8
	strh r0, [r7, #8]
	movs r0, #0x3c      @ MUS_EX_DEMO_1
	bl m4aSongNumStart
	ldr r0, _0807F930 @ =0x000007E4
	strh r0, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807F92C: .4byte gCamera
_0807F930: .4byte 0x000007E4
_0807F934:
	ldrh r0, [r7, #8]
	subs r0, #1
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	beq _0807F944
	b _0807FB6C
_0807F944:
	ldr r2, _0807F97C @ =gDispCnt
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #6
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0807F980 @ =gWinRegs
	ldr r0, _0807F984 @ =0x00007778
	strh r0, [r1]
	movs r0, #0xa0
	strh r0, [r1, #4]
	movs r0, #0x3c
	strh r0, [r1, #8]
	movs r0, #0x1c
	strh r0, [r1, #0xa]
	ldr r1, _0807F988 @ =gBldRegs
	ldr r0, _0807F98C @ =0x00003FBF
	strh r0, [r1]
	movs r0, #8
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r3, [r7, #0xa]
	strh r5, [r7, #0xc]
	ldr r0, _0807F990 @ =0x0000029B
	bl m4aSongNumStart
	b _0807FB6C
	.align 2, 0
_0807F97C: .4byte gDispCnt
_0807F980: .4byte gWinRegs
_0807F984: .4byte 0x00007778
_0807F988: .4byte gBldRegs
_0807F98C: .4byte 0x00003FBF
_0807F990: .4byte 0x0000029B
_0807F994:
	ldrh r0, [r7, #0xa]
	adds r0, #0x20
	strh r0, [r7, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _0807F9B2
	movs r0, #0x78
	strh r0, [r7, #8]
	movs r0, #2
	strh r0, [r7, #0xa]
	movs r0, #0
	strb r0, [r7, #0xe]
	ldr r0, _0807F9E0 @ =0x000007F3
	strh r0, [r7, #0xc]
_0807F9B2:
	ldr r1, _0807F9E4 @ =gSineTable
	movs r2, #0xa
	ldrsh r0, [r7, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bge _0807F9C8
	ldr r1, _0807F9E8 @ =0x000001FF
	adds r0, r0, r1
_0807F9C8:
	asrs r1, r0, #9
	movs r0, #0x78
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0
	bge _0807F9D8
	movs r4, #0
_0807F9D8:
	adds r0, r1, #0
	adds r0, #0x78
	b _0807FA72
	.align 2, 0
_0807F9E0: .4byte 0x000007F3
_0807F9E4: .4byte gSineTable
_0807F9E8: .4byte 0x000001FF
_0807F9EC:
	movs r4, #0x58
	movs r3, #0x98
	ldrh r0, [r7, #8]
	subs r0, #1
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0807FA08
	strh r0, [r7, #0xa]
	movs r0, #0xff
	lsls r0, r0, #3
	strh r0, [r7, #0xc]
	b _0807FA7E
_0807FA08:
	ldrh r0, [r7, #0xa]
	subs r0, #1
	strh r0, [r7, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807FA7E
	movs r0, #2
	strh r0, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	movs r1, #1
	eors r0, r1
	strb r0, [r7, #0xe]
	cmp r0, #0
	bne _0807FA7E
	movs r4, #0x60
	movs r3, #0x90
	b _0807FA7E
_0807FA2A:
	ldrh r0, [r7, #0xa]
	adds r0, #8
	strh r0, [r7, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _0807FA44
	movs r0, #4
	strh r0, [r7, #8]
	ldr r0, _0807FA90 @ =0x0000029B
	bl m4aSongNumStop
	strh r4, [r7, #0xc]
_0807FA44:
	ldr r1, _0807FA94 @ =gSineTable
	movs r2, #0xa
	ldrsh r0, [r7, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x58
	muls r0, r1, r0
	cmp r0, #0
	bge _0807FA5E
	ldr r1, _0807FA98 @ =0x00003FFF
	adds r0, r0, r1
_0807FA5E:
	asrs r1, r0, #0xe
	movs r0, #0x58
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0
	bge _0807FA6E
	movs r4, #0
_0807FA6E:
	adds r0, r1, #0
	adds r0, #0x98
_0807FA72:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _0807FA7E
	movs r3, #0xf0
_0807FA7E:
	ldr r2, _0807FA9C @ =gWinRegs
	lsls r1, r4, #0x10
	asrs r1, r1, #8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r2]
	b _0807FB6C
	.align 2, 0
_0807FA90: .4byte 0x0000029B
_0807FA94: .4byte gSineTable
_0807FA98: .4byte 0x00003FFF
_0807FA9C: .4byte gWinRegs
_0807FAA0:
	ldrh r0, [r7, #8]
	subs r0, #1
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807FB6C
	ldr r1, _0807FAC8 @ =gBldRegs
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _0807FAD0
	movs r0, #0x78
	strh r0, [r7, #8]
	ldr r0, _0807FACC @ =0x0000080C
	strh r0, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807FAC8: .4byte gBldRegs
_0807FACC: .4byte 0x0000080C
_0807FAD0:
	movs r0, #4
	strh r0, [r7, #8]
	b _0807FB6C
_0807FAD6:
	ldrh r0, [r7, #8]
	subs r0, #1
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807FB6C
	ldr r0, [r7, #0x28]
	bl sub_8081DF4
	ldr r0, _0807FAF4 @ =0x0000023F
	bl m4aSongNumStart
	ldr r0, _0807FAF8 @ =0x00000816
	strh r0, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807FAF4: .4byte 0x0000023F
_0807FAF8: .4byte 0x00000816
_0807FAFC:
	ldr r4, _0807FB2C @ =gBldRegs
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0807FB6C
	ldr r2, _0807FB30 @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _0807FB34 @ =0x0000DFFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0807FB38 @ =gWinRegs
	strh r3, [r0, #8]
	strh r3, [r0, #0xa]
	strh r3, [r4]
	strh r3, [r4, #2]
	strh r3, [r4, #4]
	ldr r0, _0807FB3C @ =0x0000078A
	strh r0, [r7, #8]
	strh r5, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807FB2C: .4byte gBldRegs
_0807FB30: .4byte gDispCnt
_0807FB34: .4byte 0x0000DFFF
_0807FB38: .4byte gWinRegs
_0807FB3C: .4byte 0x0000078A
_0807FB40:
	ldrh r0, [r7, #8]
	subs r0, #1
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807FB6C
	ldr r0, _0807FB54 @ =0x000008FC
	strh r0, [r7, #0xc]
	b _0807FB6C
	.align 2, 0
_0807FB54: .4byte 0x000008FC
_0807FB58:
	movs r0, #0x58      @ MUS_FINAL_CLEAR
	bl m4aSongNumStart
	bl sub_8002508
	ldr r0, _0807FB78 @ =0x0000091A
	strh r0, [r7, #0xc]
	movs r0, #0x1e
	bl sub_807FB7C
_0807FB6C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FB78: .4byte 0x0000091A

.syntax divided
