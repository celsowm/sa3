.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrh r3, [r7, #8]
	movs r4, #0x96
	lsls r4, r4, #1
	cmp r3, r4
	bne _080843B2
	b _0808457C
_080843B2:
	cmp r3, r4
	bgt _080843D6
	cmp r3, #0x64
	beq _080844B0
	cmp r3, #0x64
	bgt _080843C8
	cmp r3, #0
	beq _0808440A
	cmp r3, #0xa
	beq _08084490
	b _08084908
_080843C8:
	cmp r3, #0x6e
	bne _080843CE
	b _08084504
_080843CE:
	cmp r3, #0xc8
	bne _080843D4
	b _08084550
_080843D4:
	b _08084908
_080843D6:
	movs r0, #0xaf
	lsls r0, r0, #1
	cmp r3, r0
	bne _080843E0
	b _080846F0
_080843E0:
	cmp r3, r0
	bgt _080843F6
	subs r0, #0x14
	cmp r3, r0
	bne _080843EC
	b _080845D4
_080843EC:
	adds r0, #0xa
	cmp r3, r0
	bne _080843F4
	b _080846D8
_080843F4:
	b _08084908
_080843F6:
	movs r0, #0xb4
	lsls r0, r0, #1
	cmp r3, r0
	bne _08084400
	b _08084788
_08084400:
	adds r0, #0x8c
	cmp r3, r0
	bne _08084408
	b _0808489C
_08084408:
	b _08084908
_0808440A:
	ldr r2, _0808447C @ =gPseudoRandom
	ldr r1, [r2]
	ldr r0, _08084480 @ =0x00196225
	muls r0, r1, r0
	ldr r1, _08084484 @ =0x3C6EF35F
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #1
	ands r0, r1
	adds r1, r7, #0
	adds r1, #0xe2
	strb r0, [r1]
	subs r1, #0x12
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xd4
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xe4
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	strh r3, [r7, #4]
	movs r0, #0x64
	strh r0, [r7, #8]
	ldr r0, _08084488 @ =0x00000239
	bl m4aSongNumStart
	movs r1, #0
	movs r3, #0
	ldr r2, _0808448C @ =0x000004FE
_0808445C:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r4, #0xed
	lsls r4, r4, #2
	adds r0, r0, r4
	adds r0, r7, r0
	strh r2, [r0, #0xc]
	strb r3, [r0, #0x1a]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _0808445C
	b _08084908
	.align 2, 0
_0808447C: .4byte gPseudoRandom
_08084480: .4byte 0x00196225
_08084484: .4byte 0x3C6EF35F
_08084488: .4byte 0x00000239
_0808448C: .4byte 0x000004FE
_08084490:
	ldrh r0, [r7, #4]
	subs r0, #1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808449E
	b _08084908
_0808449E:
	adds r2, r7, #0
	adds r2, #0xe2
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x64
	strh r0, [r7, #8]
	b _08084908
_080844B0:
	adds r0, r7, #0
	adds r0, #0xe2
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #0
	beq _080844BE
	movs r1, #2
_080844BE:
	adds r4, r1, #0
	adds r0, r7, #0
	adds r0, #0xd0
	lsls r1, r4, #2
	adds r2, r0, r1
	ldr r0, [r0]
	ldr r1, [r2]
	cmp r0, r1
	ble _080844DE
	movs r6, #0xa2
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	adds r0, r1, r0
	str r0, [r2]
	b _080844E8
_080844DE:
	ldr r0, _08084500 @ =0x00000239
	bl m4aSongNumStart
	movs r0, #0x6e
	strh r0, [r7, #8]
_080844E8:
	subs r0, r4, #1
	lsls r0, r0, #2
	adds r1, r7, #0
	adds r1, #0xe4
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	b _0808456C
	.align 2, 0
_08084500: .4byte 0x00000239
_08084504:
	adds r0, r7, #0
	adds r0, #0xe2
	ldrb r0, [r0]
	movs r1, #2
	cmp r0, #0
	beq _08084512
	movs r1, #1
_08084512:
	adds r4, r1, #0
	adds r0, r7, #0
	adds r0, #0xd0
	lsls r1, r4, #2
	adds r2, r0, r1
	ldr r0, [r0]
	ldr r1, [r2]
	cmp r0, r1
	ble _08084532
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r1, r0
	str r0, [r2]
	b _0808453A
_08084532:
	movs r0, #0x3c
	strh r0, [r7, #4]
	movs r0, #0xc8
	strh r0, [r7, #8]
_0808453A:
	subs r0, r4, #1
	lsls r0, r0, #2
	adds r1, r7, #0
	adds r1, #0xe4
	adds r1, r1, r0
	ldr r0, [r1]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r0, r4
	str r0, [r1]
	b _0808456C
_08084550:
	ldrh r0, [r7, #4]
	subs r0, #1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808456C
	ldr r0, _08084578 @ =0x00000505
	movs r2, #0x87
	lsls r2, r2, #2
	movs r1, #0
	movs r3, #1
	bl sub_8078DB0
	strh r4, [r7, #8]
_0808456C:
	adds r0, r7, #0
	movs r1, #4
	bl sub_8082E2C
	b _08084908
	.align 2, 0
_08084578: .4byte 0x00000505
_0808457C:
	ldr r2, _080845F8 @ =gDispCnt
	ldrh r0, [r2]
	movs r6, #0x84
	lsls r6, r6, #6
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080845FC @ =gWinRegs
	movs r3, #0
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #0xa0
	strh r0, [r1, #4]
	movs r0, #0x3f
	strh r0, [r1, #8]
	movs r0, #0x18
	strh r0, [r1, #0xa]
	ldr r1, _08084600 @ =gBldRegs
	ldr r0, _08084604 @ =0x00003841
	strh r0, [r1]
	ldr r0, _08084608 @ =0x00000C0C
	strh r0, [r1, #2]
	movs r0, #0xc
	strh r0, [r1, #4]
	movs r0, #1
	strb r0, [r7, #0xf]
	ldr r0, _0808460C @ =0x00000814
	adds r1, r7, r0
	ldr r2, _08084610 @ =gUnknown_080D5D0C
	ldrh r0, [r2]
	strh r0, [r1, #0xc]
	ldrh r0, [r2, #2]
	strb r0, [r1, #0x1a]
	movs r0, #0xff
	strb r0, [r1, #0x1b]
	adds r0, r7, #0
	adds r0, #0xcc
	strh r3, [r0]
	ldr r0, _08084614 @ =0x0000023E
	bl m4aSongNumStart
	movs r0, #0xa5
	lsls r0, r0, #1
	strh r0, [r7, #8]
_080845D4:
	adds r1, r7, #0
	adds r1, #0xcc
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r1, #0
	cmp r0, #0xff
	bls _0808463A
	adds r0, r7, #0
	adds r0, #0xe2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08084618
	movs r0, #5
	adds r1, #0x21
	b _0808461E
	.align 2, 0
_080845F8: .4byte gDispCnt
_080845FC: .4byte gWinRegs
_08084600: .4byte gBldRegs
_08084604: .4byte 0x00003841
_08084608: .4byte 0x00000C0C
_0808460C: .4byte 0x00000814
_08084610: .4byte gUnknown_080D5D0C
_08084614: .4byte 0x0000023E
_08084618:
	movs r0, #6
	adds r1, r7, #0
	adds r1, #0xed
_0808461E:
	strb r0, [r1]
	movs r0, #0xb4
	strh r0, [r7, #4]
	ldr r2, _080846BC @ =0x00000814
	adds r1, r7, r2
	ldr r2, _080846C0 @ =gUnknown_080D5D0C
	ldrh r0, [r2, #4]
	strh r0, [r1, #0xc]
	ldrh r0, [r2, #6]
	strb r0, [r1, #0x1a]
	movs r0, #0xff
	strb r0, [r1, #0x1b]
	adds r0, #0x55
	strh r0, [r7, #8]
_0808463A:
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r2, _080846C4 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0xa0
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r1, _080846C8 @ =gSineTable
	ldrh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0808467A
	ldr r4, _080846CC @ =0x00003FFF
	adds r0, r0, r4
_0808467A:
	mov r6, r8
	lsls r4, r6, #0x10
	asrs r1, r4, #0x10
	mov r8, r1
	ldr r2, _080846D0 @ =0xFFA80000
	adds r4, r4, r2
	asrs r4, r4, #0x10
	mov r3, sb
	lsls r5, r3, #0x10
	asrs r5, r5, #0x10
	asrs r6, r0, #0xe
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl sub_8085618
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl sub_8087188
	adds r0, r7, #0
	movs r1, #4
	bl sub_8082E2C
	ldr r1, _080846D4 @ =gBgScrollRegs
	movs r4, #0xac
	lsls r4, r4, #1
	adds r0, r4, #0
	mov r6, r8
	b _08084766
	.align 2, 0
_080846BC: .4byte 0x00000814
_080846C0: .4byte gUnknown_080D5D0C
_080846C4: .4byte gCamera
_080846C8: .4byte gSineTable
_080846CC: .4byte 0x00003FFF
_080846D0: .4byte 0xFFA80000
_080846D4: .4byte gBgScrollRegs
_080846D8:
	adds r0, r7, #0
	adds r0, #0xee
	ldrb r0, [r0]
	cmp r0, #0
	beq _08084718
	movs r0, #4
	adds r1, r7, #0
	adds r1, #0xed
	strb r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #1
	b _08084716
_080846F0:
	adds r0, r7, #0
	adds r0, #0xee
	ldrb r0, [r0]
	cmp r0, #0
	beq _08084718
	adds r1, r7, #0
	adds r1, #0xed
	movs r0, #0
	strb r0, [r1]
	ldr r3, _08084774 @ =0x00000814
	adds r1, r7, r3
	ldr r2, _08084778 @ =gUnknown_080D5D0C
	ldrh r0, [r2]
	strh r0, [r1, #0xc]
	ldrh r0, [r2, #2]
	strb r0, [r1, #0x1a]
	movs r0, #0xff
	strb r0, [r1, #0x1b]
	adds r0, #0x69
_08084716:
	strh r0, [r7, #8]
_08084718:
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r4, [r0]
	asrs r4, r4, #8
	ldr r1, _0808477C @ =gCamera
	ldr r0, [r1]
	subs r4, r4, r0
	adds r0, r7, #0
	adds r0, #0xa0
	ldr r5, [r0]
	asrs r5, r5, #8
	ldr r0, [r1, #4]
	subs r5, r5, r0
	lsls r4, r4, #0x10
	asrs r6, r4, #0x10
	ldr r0, _08084780 @ =0xFFA80000
	adds r4, r4, r0
	asrs r4, r4, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x18
	bl sub_8085618
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x18
	bl sub_8087188
	adds r0, r7, #0
	movs r1, #4
	bl sub_8082E2C
	ldr r1, _08084784 @ =gBgScrollRegs
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r2, #0
_08084766:
	subs r0, r0, r6
	strh r0, [r1]
	movs r0, #0x18
	subs r0, r0, r5
	strh r0, [r1, #2]
	b _08084908
	.align 2, 0
_08084774: .4byte 0x00000814
_08084778: .4byte gUnknown_080D5D0C
_0808477C: .4byte gCamera
_08084780: .4byte 0xFFA80000
_08084784: .4byte gBgScrollRegs
_08084788:
	adds r4, r7, #0
	adds r4, #0xcc
	ldrh r0, [r4]
	subs r0, #4
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _080847D4
	ldr r2, _0808486C @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _08084870 @ =0x0000DEFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08084874 @ =gWinRegs
	strh r3, [r0, #8]
	strh r3, [r0, #0xa]
	ldr r0, _08084878 @ =gBldRegs
	strh r3, [r0]
	strh r3, [r0, #2]
	strh r3, [r0, #4]
	ldr r2, _0808487C @ =gFlags
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r3, _08084880 @ =0x00000814
	adds r1, r7, r3
	ldr r2, _08084884 @ =gUnknown_080D5D0C
	ldrh r0, [r2, #8]
	strh r0, [r1, #0xc]
	ldrh r0, [r2, #0xa]
	strb r0, [r1, #0x1a]
	movs r0, #0xff
	strb r0, [r1, #0x1b]
	adds r0, #0xf5
	strh r0, [r7, #8]
_080847D4:
	ldrh r0, [r4]
	cmp r0, #0
	beq _08084842
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r2, _08084888 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0xa0
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r1, _0808488C @ =gSineTable
	ldrh r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0808481A
	ldr r6, _08084890 @ =0x00003FFF
	adds r0, r0, r6
_0808481A:
	mov r1, r8
	lsls r4, r1, #0x10
	ldr r2, _08084894 @ =0xFFA80000
	adds r4, r4, r2
	asrs r4, r4, #0x10
	mov r3, sb
	lsls r5, r3, #0x10
	asrs r5, r5, #0x10
	asrs r6, r0, #0xe
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl sub_8085618
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl sub_8087188
_08084842:
	adds r0, r7, #0
	movs r1, #4
	bl sub_8082E2C
	ldr r2, _08084898 @ =gBgScrollRegs
	movs r4, #0xac
	lsls r4, r4, #1
	adds r1, r4, #0
	mov r6, r8
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r2]
	movs r1, #0x18
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r2, #2]
	b _08084908
	.align 2, 0
_0808486C: .4byte gDispCnt
_08084870: .4byte 0x0000DEFF
_08084874: .4byte gWinRegs
_08084878: .4byte gBldRegs
_0808487C: .4byte gFlags
_08084880: .4byte 0x00000814
_08084884: .4byte gUnknown_080D5D0C
_08084888: .4byte gCamera
_0808488C: .4byte gSineTable
_08084890: .4byte 0x00003FFF
_08084894: .4byte 0xFFA80000
_08084898: .4byte gBgScrollRegs
_0808489C:
	adds r3, r7, #0
	adds r3, #0xd4
	ldr r2, [r3]
	cmp r2, #0
	beq _080848C4
	movs r4, #0xa2
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	subs r0, r2, r0
	str r0, [r3]
	adds r2, r7, #0
	adds r2, #0xd8
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	adds r2, #0xc
	adds r3, #0x14
	b _080848F2
_080848C4:
	strb r2, [r7, #0xf]
	strb r2, [r7, #1]
	movs r1, #0
	adds r2, r7, #0
	adds r2, #0xe4
	adds r3, r7, #0
	adds r3, #0xe8
	ldr r5, _08084914 @ =0x000004FE
	movs r4, #1
_080848D6:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r6, #0xed
	lsls r6, r6, #2
	adds r0, r0, r6
	adds r0, r7, r0
	strh r5, [r0, #0xc]
	strb r4, [r0, #0x1a]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _080848D6
_080848F2:
	ldr r0, [r2]
	ldr r1, _08084918 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r3]
	adds r0, r7, #0
	movs r1, #4
	bl sub_8082E2C
_08084908:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084914: .4byte 0x000004FE
_08084918: .4byte 0xFFFFFE80

.syntax divided
