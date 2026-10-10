.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r1, [r5, #0x12]
	ldr r6, _08084EDC @ =0x000003F2
	cmp r1, r6
	bne _08084EC4
	b _08085058
_08084EC4:
	cmp r1, r6
	bgt _08084EF2
	cmp r1, #0x64
	beq _08084F82
	cmp r1, #0x64
	bgt _08084EE0
	cmp r1, #0
	beq _08084F34
	cmp r1, #0xa
	beq _08084F4E
	b _080851EE
	.align 2, 0
_08084EDC: .4byte 0x000003F2
_08084EE0:
	cmp r1, #0x6e
	bne _08084EE6
	b _080851EE
_08084EE6:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _08084EF0
	b _08085014
_08084EF0:
	b _080851EE
_08084EF2:
	ldr r0, _08084F14 @ =0x00000BB8
	cmp r1, r0
	bne _08084EFA
	b _08085164
_08084EFA:
	cmp r1, r0
	bgt _08084F18
	movs r0, #0xff
	lsls r0, r0, #2
	cmp r1, r0
	bne _08084F08
	b _0808509E
_08084F08:
	movs r0, #0xfa
	lsls r0, r0, #3
	cmp r1, r0
	bne _08084F12
	b _080850BC
_08084F12:
	b _080851EE
	.align 2, 0
_08084F14: .4byte 0x00000BB8
_08084F18:
	ldr r0, _08084F2C @ =0x00000BC2
	cmp r1, r0
	bne _08084F20
	b _080851B0
_08084F20:
	ldr r0, _08084F30 @ =0x00001388
	cmp r1, r0
	bne _08084F28
	b _080851E6
_08084F28:
	b _080851EE
	.align 2, 0
_08084F2C: .4byte 0x00000BC2
_08084F30: .4byte 0x00001388
_08084F34:
	adds r0, r5, #0
	movs r1, #0
	bl sub_80867FC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08084F44
	b _080851EE
_08084F44:
	adds r0, r5, #0
	movs r1, #0
	bl sub_80854B8
	b _080851EE
_08084F4E:
	ldrh r0, [r5, #0x10]
	subs r0, #1
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	beq _08084F76
	adds r0, r5, #0
	movs r1, #1
	bl sub_80867FC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08084F6C
	b _080851EE
_08084F6C:
	adds r0, r5, #0
	movs r1, #1
	bl sub_80854B8
	b _080851EE
_08084F76:
	movs r0, #0x64
	adds r1, r5, #0
	adds r1, #0xef
	strb r0, [r1]
	strh r2, [r5, #0x12]
	b _080851EE
_08084F82:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08084F92
	b _080851EE
_08084F92:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08084FB0
	ldrh r0, [r5, #0x10]
	subs r0, #0x78
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08084FAA
	strh r1, [r5, #0x10]
	strh r1, [r5, #0x12]
	b _08085002
_08084FAA:
	movs r0, #0xa
	strh r0, [r5, #0x12]
	b _08085002
_08084FB0:
	ldr r1, _08084FC4 @ =gStageData
	ldrb r0, [r1, #3]
	cmp r0, #5
	bne _08084FD0
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _08084FC8
	movs r0, #0x6e
	b _08084FDE
	.align 2, 0
_08084FC4: .4byte gStageData
_08084FC8:
	movs r0, #1
	movs r1, #0
	bl sub_8027674
_08084FD0:
	adds r0, r5, #0
	bl sub_8085458
	movs r0, #0x78
	strh r0, [r5, #0x10]
	movs r0, #0xfa
	lsls r0, r0, #2
_08084FDE:
	strh r0, [r5, #0x12]
	ldr r0, [r5, #0x28]
	adds r0, #0x48
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r5, #0x2c]
	adds r0, #0x48
	strh r1, [r0]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #4]
	movs r2, #0x80
	lsls r2, r2, #0x14
	orrs r0, r2
	str r0, [r1, #4]
	ldr r1, [r5, #0x2c]
	ldr r0, [r1, #4]
	orrs r0, r2
	str r0, [r1, #4]
_08085002:
	ldrh r0, [r5, #0x12]
	cmp r0, #0xa
	bne _0808500A
	b _080851EE
_0808500A:
	movs r1, #0x64
	adds r0, r5, #0
	adds r0, #0xef
	strb r1, [r0]
	b _080851EE
_08085014:
	ldrh r0, [r5, #0x10]
	subs r0, #1
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	beq _08085024
	b _080851EE
_08085024:
	ldr r0, [r5, #0x1c]
	bl VramFree
	ldr r0, [r5, #0x20]
	bl VramFree
	str r4, [r5, #0x1c]
	str r4, [r5, #0x20]
	movs r0, #0x74
	bl VramMalloc
	str r0, [r5, #0x24]
	adds r0, r5, #0
	movs r1, #1
	bl sub_80851FC
	ldr r0, _08085054 @ =0x00000221
	bl m4aSongNumStart
	movs r0, #0xf
	strh r0, [r5, #0x10]
	strh r6, [r5, #0x12]
	b _080851EE
	.align 2, 0
_08085054: .4byte 0x00000221
_08085058:
	ldrh r0, [r5, #0x10]
	subs r0, #1
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08085066
	b _080851EE
_08085066:
	ldrb r1, [r5, #0xe]
	adds r1, #0xa
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl sub_80851FC
	ldr r0, _08085090 @ =0x00000221
	bl m4aSongNumStart
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi _08085094
	movs r0, #0xf
	strh r0, [r5, #0x10]
	b _080851EE
	.align 2, 0
_08085090: .4byte 0x00000221
_08085094:
	movs r0, #0x78
	strh r0, [r5, #0x10]
	movs r0, #0xff
	lsls r0, r0, #2
	b _080851EC
_0808509E:
	ldrh r0, [r5, #0x10]
	subs r0, #1
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080850AC
	b _080851EE
_080850AC:
	ldr r0, _080850B8 @ =0x00000221
	bl m4aSongNumStart
	movs r0, #0xfa
	lsls r0, r0, #3
	b _080851EC
	.align 2, 0
_080850B8: .4byte 0x00000221
_080850BC:
	ldr r0, _08085148 @ =gStageData
	ldr r0, [r0, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08085132
	ldr r3, _0808514C @ =gPseudoRandom
	ldr r0, [r3]
	ldr r2, _08085150 @ =0x00196225
	muls r0, r2, r0
	ldr r1, _08085154 @ =0x3C6EF35F
	adds r0, r0, r1
	ldr r4, _08085158 @ =0x000003FF
	ands r4, r0
	muls r0, r2, r0
	adds r0, r0, r1
	str r0, [r3]
	movs r1, #0x30
	bl __umodsi3
	ldr r3, _0808515C @ =gSineTable
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r2, r1, #0
	muls r2, r0, r2
	lsrs r2, r2, #6
	lsls r1, r4, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r3, r1, #0
	muls r3, r0, r3
	lsrs r3, r3, #6
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r0, [r0]
	adds r0, r0, r2
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r1, [r1]
	adds r1, r1, r3
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	movs r2, #0xc0
	lsls r2, r2, #2
	movs r3, #0x1e
	str r3, [sp]
	ldr r3, [r5, #0x24]
	str r3, [sp, #4]
	adds r3, r4, #0
	bl sub_8086D64
_08085132:
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _080851EE
	ldr r0, _08085160 @ =0x00000221
	bl m4aSongNumStart
	b _080851EE
	.align 2, 0
_08085148: .4byte gStageData
_0808514C: .4byte gPseudoRandom
_08085150: .4byte 0x00196225
_08085154: .4byte 0x3C6EF35F
_08085158: .4byte 0x000003FF
_0808515C: .4byte gSineTable
_08085160: .4byte 0x00000221
_08085164:
	ldr r1, _0808519C @ =gBldRegs
	movs r2, #0
	ldr r0, _080851A0 @ =0x00003FBF
	strh r0, [r1]
	movs r0, #8
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	strh r0, [r5, #0x10]
	ldr r0, _080851A4 @ =0x00000BC2
	strh r0, [r5, #0x12]
	ldr r1, _080851A8 @ =gPlayers
	ldr r0, [r1, #4]
	movs r2, #0x80
	lsls r2, r2, #0x14
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080851AC @ =gMusicManagerState
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1, #6]
	b _080851EE
	.align 2, 0
_0808519C: .4byte gBldRegs
_080851A0: .4byte 0x00003FBF
_080851A4: .4byte 0x00000BC2
_080851A8: .4byte gPlayers
_080851AC: .4byte gMusicManagerState
_080851B0:
	ldrh r0, [r5, #0x10]
	subs r0, #1
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080851EE
	ldr r1, _080851D8 @ =gBldRegs
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _080851E0
	ldr r0, _080851DC @ =0x00001388
	strh r0, [r5, #0x12]
	movs r0, #0x78
	strh r0, [r5, #0x10]
	b _080851EE
	.align 2, 0
_080851D8: .4byte gBldRegs
_080851DC: .4byte 0x00001388
_080851E0:
	movs r0, #8
	strh r0, [r5, #0x10]
	b _080851EE
_080851E6:
	bl sub_805602C
	ldr r0, _080851F8 @ =0x00001392
_080851EC:
	strh r0, [r5, #0x12]
_080851EE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080851F8: .4byte 0x00001392

.syntax divided
