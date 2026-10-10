.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r5, r7, r0
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r0, r0, r2
	adds r3, r7, r0
	movs r4, #0
	ldrh r2, [r5, #0x16]
	cmp r2, #0xc8
	bne _0807E57C
	b _0807E78C
_0807E57C:
	cmp r2, #0xc8
	bgt _0807E59C
	cmp r2, #0x14
	bne _0807E586
	b _0807E6B2
_0807E586:
	cmp r2, #0x14
	bgt _0807E594
	cmp r2, #0
	beq _0807E5C8
	cmp r2, #0xa
	beq _0807E66C
	b _0807E98C
_0807E594:
	cmp r2, #0x64
	bne _0807E59A
	b _0807E6C8
_0807E59A:
	b _0807E98C
_0807E59C:
	cmp r2, #0xe6
	bne _0807E5A2
	b _0807E854
_0807E5A2:
	cmp r2, #0xe6
	bgt _0807E5B4
	cmp r2, #0xd2
	bne _0807E5AC
	b _0807E7AC
_0807E5AC:
	cmp r2, #0xdc
	bne _0807E5B2
	b _0807E83C
_0807E5B2:
	b _0807E98C
_0807E5B4:
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r2, r0
	bne _0807E5BE
	b _0807E8B4
_0807E5BE:
	adds r0, #0xa
	cmp r2, r0
	bne _0807E5C6
	b _0807E940
_0807E5C6:
	b _0807E98C
_0807E5C8:
	cmp r6, #0
	beq _0807E5D2
	cmp r6, #1
	beq _0807E5E0
	b _0807E5F0
_0807E5D2:
	movs r3, #0x9e
	lsls r3, r3, #2
	adds r2, r7, r3
	ldr r0, _0807E5DC @ =sBossFinalAnimsHands
	b _0807E5E8
	.align 2, 0
_0807E5DC: .4byte sBossFinalAnimsHands
_0807E5E0:
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, _0807E600 @ =sBossFinalAnimsHands+0x18
_0807E5E8:
	ldrh r1, [r0, #4]
	strh r1, [r2, #0xc]
	ldrh r0, [r0, #6]
	strb r0, [r2, #0x1a]
_0807E5F0:
	cmp r6, #0
	bne _0807E604
	ldr r0, [r5]
	asrs r0, r0, #8
	movs r2, #0xc6
	lsls r2, r2, #3
	adds r1, r2, #0
	b _0807E60E
	.align 2, 0
_0807E600: .4byte sBossFinalAnimsHands+0x18
_0807E604:
	ldr r0, [r5]
	asrs r0, r0, #8
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r1, r3, #0
_0807E60E:
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807E664 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r0, [r5, #4]
	asrs r0, r0, #8
	movs r1, #0x60
	subs r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0807E668 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, _0807E664 @ =0xFFFF0000
	mov r4, sp
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #8
	bl sa2__sub_8085A9C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r5, #8]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	str r0, [r5, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #2
	strh r0, [r5, #0x10]
	movs r0, #0xa
	strh r0, [r5, #0x16]
	b _0807E98C
	.align 2, 0
_0807E664: .4byte 0xFFFF0000
_0807E668: .4byte 0x0000FFFF
_0807E66C:
	ldr r0, [r5]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [r5]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bgt _0807E68C
	strb r4, [r5, #0x13]
	strh r2, [r5, #0x14]
	movs r0, #0x14
	strh r0, [r5, #0x16]
_0807E68C:
	cmp r6, #0
	bne _0807E6A0
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _0807E69C
	b _0807E98C
_0807E69C:
	adds r0, r1, #0
	b _0807E982
_0807E6A0:
	ldrh r1, [r3]
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	bne _0807E6AC
	b _0807E98C
_0807E6AC:
	adds r0, r1, #0
	subs r0, #0x10
	b _0807E984
_0807E6B2:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807E6C0
	b _0807E98C
_0807E6C0:
	strh r4, [r5, #0x14]
	movs r0, #0x64
	strh r0, [r5, #0x16]
	b _0807E98C
_0807E6C8:
	cmp r6, #0
	bne _0807E71C
	ldr r4, _0807E718 @ =gSineTable
	ldrh r3, [r5, #0x10]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r3, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0807E6EA
	adds r0, #0x3f
_0807E6EA:
	asrs r2, r0, #6
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0807E700
	adds r0, #0x3f
_0807E700:
	asrs r1, r0, #6
	movs r3, #0xc6
	lsls r3, r3, #0xb
	adds r0, r2, r3
	str r0, [r5]
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r0, r1, r2
	str r0, [r5, #4]
	ldrh r0, [r5, #0x10]
	subs r0, #0x10
	b _0807E766
	.align 2, 0
_0807E718: .4byte gSineTable
_0807E71C:
	ldr r4, _0807E780 @ =gSineTable
	ldrh r3, [r5, #0x10]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r3, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0807E73A
	adds r0, #0x3f
_0807E73A:
	asrs r2, r0, #6
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0807E750
	adds r0, #0x3f
_0807E750:
	asrs r1, r0, #6
	movs r3, #0xd8
	lsls r3, r3, #0xb
	adds r0, r2, r3
	str r0, [r5]
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r0, r1, r2
	str r0, [r5, #4]
	ldrh r0, [r5, #0x10]
	adds r0, #0x10
_0807E766:
	ldr r3, _0807E784 @ =0x000003FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, #0x10
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	ldr r1, _0807E788 @ =0x07FF0000
	cmp r0, r1
	bgt _0807E77E
	b _0807E98C
_0807E77E:
	b _0807E8AE
	.align 2, 0
_0807E780: .4byte gSineTable
_0807E784: .4byte 0x000003FF
_0807E788: .4byte 0x07FF0000
_0807E78C:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807E79A
	b _0807E98C
_0807E79A:
	ldr r0, _0807E7A8 @ =0x0000023D
	bl m4aSongNumStart
	movs r0, #0xd2
	strh r0, [r5, #0x16]
	b _0807E98C
	.align 2, 0
_0807E7A8: .4byte 0x0000023D
_0807E7AC:
	ldr r1, [r5, #0x20]
	ldr r0, [r5, #0x24]
	cmp r1, r0
	bge _0807E7E0
	ldr r2, [r5, #0x1c]
	adds r0, r1, r2
	str r0, [r5, #0x20]
	ldr r0, [r5, #8]
	muls r0, r2, r0
	cmp r0, #0
	bge _0807E7C4
	adds r0, #0xff
_0807E7C4:
	asrs r0, r0, #8
	ldr r1, [r5]
	adds r1, r1, r0
	str r1, [r5]
	ldr r0, [r5, #0xc]
	muls r0, r2, r0
	cmp r0, #0
	bge _0807E7D6
	adds r0, #0xff
_0807E7D6:
	asrs r1, r0, #8
	ldr r0, [r5, #4]
	adds r0, r0, r1
	str r0, [r5, #4]
	b _0807E7E2
_0807E7E0:
	movs r4, #1
_0807E7E2:
	ldrh r2, [r3, #2]
	movs r0, #2
	ldrsh r1, [r3, r0]
	ldr r0, _0807E7FC @ =0x000001FF
	cmp r1, r0
	bgt _0807E800
	adds r0, r2, #0
	adds r0, #0x10
	strh r0, [r3, #2]
	ldrh r0, [r3, #4]
	adds r0, #0x10
	strh r0, [r3, #4]
	b _0807E804
	.align 2, 0
_0807E7FC: .4byte 0x000001FF
_0807E800:
	movs r0, #2
	orrs r4, r0
_0807E804:
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	cmp r1, r0
	ble _0807E82C
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r0, r7, r0
	adds r1, r3, #0
	movs r2, #2
	adds r3, r6, #0
	bl sub_807F334
	movs r0, #1
	strb r0, [r5, #0x13]
_0807E82C:
	cmp r4, #3
	beq _0807E832
	b _0807E98C
_0807E832:
	movs r0, #0xa
	strh r0, [r5, #0x14]
	movs r0, #0xdc
	strh r0, [r5, #0x16]
	b _0807E98C
_0807E83C:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807E84A
	b _0807E98C
_0807E84A:
	movs r0, #0xe6
	strh r0, [r5, #0x16]
	movs r0, #0
	strb r0, [r5, #0x13]
	b _0807E98C
_0807E854:
	ldr r1, [r5, #0x20]
	cmp r1, #0
	ble _0807E888
	ldr r0, [r5, #0x1c]
	subs r1, r1, r0
	str r1, [r5, #0x20]
	rsbs r2, r0, #0
	ldr r0, [r5, #8]
	muls r0, r2, r0
	cmp r0, #0
	bge _0807E86C
	adds r0, #0xff
_0807E86C:
	asrs r0, r0, #8
	ldr r1, [r5]
	adds r1, r1, r0
	str r1, [r5]
	ldr r0, [r5, #0xc]
	muls r0, r2, r0
	cmp r0, #0
	bge _0807E87E
	adds r0, #0xff
_0807E87E:
	asrs r1, r0, #8
	ldr r0, [r5, #4]
	adds r0, r0, r1
	str r0, [r5, #4]
	b _0807E88A
_0807E888:
	movs r4, #1
_0807E88A:
	ldrh r2, [r3, #2]
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0807E8A6
	adds r0, r2, #0
	subs r0, #0x10
	strh r0, [r3, #2]
	ldrh r0, [r3, #4]
	subs r0, #0x10
	strh r0, [r3, #4]
	b _0807E8AA
_0807E8A6:
	movs r0, #2
	orrs r4, r0
_0807E8AA:
	cmp r4, #3
	bne _0807E98C
_0807E8AE:
	movs r0, #0x6e
	strh r0, [r5, #0x16]
	b _0807E98C
_0807E8B4:
	cmp r6, #0
	bne _0807E8C8
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r2, _0807E8C4 @ =0x00000614
	adds r1, r2, #0
	b _0807E8D0
	.align 2, 0
_0807E8C4: .4byte 0x00000614
_0807E8C8:
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r3, _0807E90C @ =0x000006DC
	adds r1, r3, #0
_0807E8D0:
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldr r0, [r5, #4]
	asrs r0, r0, #8
	movs r1, #0x98
	subs r1, r1, r0
	mov r4, sp
	movs r0, #0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #8
	bl sa2__sub_8085A9C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r5, #8]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	str r0, [r5, #0xc]
	cmp r6, #0
	beq _0807E910
	cmp r6, #1
	beq _0807E920
	b _0807E930
	.align 2, 0
_0807E90C: .4byte 0x000006DC
_0807E910:
	movs r3, #0x9e
	lsls r3, r3, #2
	adds r2, r7, r3
	ldr r0, _0807E91C @ =sBossFinalAnimsHands
	b _0807E928
	.align 2, 0
_0807E91C: .4byte sBossFinalAnimsHands
_0807E920:
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, _0807E93C @ =sBossFinalAnimsHands+0x18
_0807E928:
	ldrh r1, [r0, #0xc]
	strh r1, [r2, #0xc]
	ldrh r0, [r0, #0xe]
	strb r0, [r2, #0x1a]
_0807E930:
	movs r0, #1
	strb r0, [r5, #0x13]
	movs r0, #0x9b
	lsls r0, r0, #1
	strh r0, [r5, #0x16]
	b _0807E98C
	.align 2, 0
_0807E93C: .4byte sBossFinalAnimsHands+0x18
_0807E940:
	ldr r1, [r5]
	ldr r0, [r5, #8]
	adds r2, r1, r0
	str r2, [r5]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	cmp r6, #0
	bne _0807E970
	ldr r0, _0807E96C @ =0x00061400
	cmp r2, r0
	bgt _0807E960
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r5, #0x16]
_0807E960:
	ldrh r0, [r3]
	cmp r0, #0
	beq _0807E98C
	subs r0, #0x10
	b _0807E984
	.align 2, 0
_0807E96C: .4byte 0x00061400
_0807E970:
	ldr r0, _0807E994 @ =0x0006DBFF
	cmp r2, r0
	ble _0807E97C
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r5, #0x16]
_0807E97C:
	ldrh r0, [r3]
	cmp r0, #0
	beq _0807E98C
_0807E982:
	adds r0, #0x10
_0807E984:
	ldr r2, _0807E998 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3]
_0807E98C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E994: .4byte 0x0006DBFF
_0807E998: .4byte 0x000003FF

.syntax divided
