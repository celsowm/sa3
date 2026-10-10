.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	ldr r1, _08080574 @ =gPlayers
	ldrh r0, [r0, #0xc]
	cmp r0, #0x1e
	bne _08080560
	b _0808066C
_08080560:
	cmp r0, #0x1e
	bgt _08080578
	cmp r0, #0xa
	beq _08080592
	cmp r0, #0xa
	bgt _0808056E
	b _0808087A
_0808056E:
	cmp r0, #0x14
	beq _08080600
	b _0808087A
	.align 2, 0
_08080574: .4byte gPlayers
_08080578:
	cmp r0, #0x64
	bne _0808057E
	b _080806F4
_0808057E:
	cmp r0, #0x64
	bgt _0808058A
	cmp r0, #0x28
	bne _08080588
	b _080806B0
_08080588:
	b _0808087A
_0808058A:
	cmp r0, #0x6e
	bne _08080590
	b _080807AC
_08080590:
	b _0808087A
_08080592:
	movs r5, #0
	movs r0, #0x1c
	add r0, ip
	mov sb, r0
	movs r2, #0x20
	add r2, ip
	mov r8, r2
	ldr r7, [r1, #0x14]
	mov r6, ip
	adds r6, #0x24
	movs r3, #0x28
	add r3, ip
	mov sl, r3
	ldr r4, _080805F4 @ =gUnknown_080D5CD4
_080805AE:
	lsls r2, r5, #2
	adds r2, r2, r5
	lsls r2, r2, #2
	mov r0, sb
	adds r1, r0, r2
	ldr r3, _080805F8 @ =gCamera
	ldr r0, [r3]
	adds r0, #0x78
	lsls r0, r0, #8
	str r0, [r1]
	mov r1, r8
	adds r0, r1, r2
	str r7, [r0]
	adds r3, r6, r2
	lsls r1, r5, #3
	adds r0, r1, r4
	ldr r0, [r0]
	str r0, [r3]
	add r2, sl
	ldr r3, _080805FC @ =gUnknown_080D5CD8
	adds r1, r1, r3
	ldr r0, [r1]
	str r0, [r2]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #6
	bls _080805AE
	movs r0, #1
	mov r1, ip
	strb r0, [r1, #1]
	movs r0, #0x14
	strh r0, [r1, #0xc]
	b _0808087A
	.align 2, 0
_080805F4: .4byte gUnknown_080D5CD4
_080805F8: .4byte gCamera
_080805FC: .4byte gUnknown_080D5CD8
_08080600:
	movs r5, #0
	movs r6, #0
	movs r2, #0x20
	add r2, ip
	mov r8, r2
_0808060A:
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r3, r0, #2
	mov r0, r8
	adds r4, r0, r3
	ldr r0, [r4]
	asrs r0, r0, #8
	cmp r0, #0xbb
	ble _0808062A
	movs r0, #0xbc
	lsls r0, r0, #8
	str r0, [r4]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _08080650
_0808062A:
	mov r2, ip
	adds r2, #0x1c
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0x24
	adds r0, r0, r3
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r2]
	mov r0, ip
	adds r0, #0x28
	adds r0, r0, r3
	ldr r1, [r0]
	adds r1, #0x2a
	str r1, [r0]
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
_08080650:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #6
	bls _0808060A
	cmp r6, #7
	beq _08080660
	b _0808087A
_08080660:
	movs r0, #0xb4
	mov r1, ip
	strh r0, [r1, #0xe]
	movs r0, #0x1e
	strh r0, [r1, #0xc]
	b _0808087A
_0808066C:
	mov r2, ip
	ldrh r0, [r2, #0xe]
	subs r0, #1
	strh r0, [r2, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808067C
	b _0808087A
_0808067C:
	movs r5, #0
	adds r2, #0x28
	ldr r3, _080806AC @ =gUnknown_080D5CD8
_08080682:
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r5, #3
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bge _08080696
	adds r0, #7
_08080696:
	asrs r0, r0, #3
	str r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #6
	bls _08080682
	movs r0, #0x28
	mov r3, ip
	strh r0, [r3, #0xc]
	b _0808087A
	.align 2, 0
_080806AC: .4byte gUnknown_080D5CD8
_080806B0:
	movs r5, #0
	ldr r6, _080806F0 @ =gBldRegs
	mov r4, ip
	adds r4, #0x20
	mov r3, ip
	adds r3, #0x28
_080806BC:
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r0, r3, r0
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r2]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #6
	bls _080806BC
	ldrh r0, [r6, #4]
	cmp r0, #0x10
	beq _080806E0
	b _0808087A
_080806E0:
	movs r0, #0
	mov r1, ip
	strb r0, [r1, #1]
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r1, #0xc]
	b _0808087A
	.align 2, 0
_080806F0: .4byte gBldRegs
_080806F4:
	movs r0, #0
	mov r2, ip
	strh r0, [r2, #2]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r2, #8]
	lsls r0, r0, #2
	str r0, [r2, #4]
	ldr r1, _0808079C @ =gCamera
	ldr r0, [r1]
	adds r0, #0x78
	lsls r0, r0, #8
	str r0, [r2, #0x24]
	ldr r0, [r1, #4]
	adds r0, #0x68
	lsls r0, r0, #8
	str r0, [r2, #0x28]
	movs r5, #0
	movs r7, #0
	movs r3, #0x1c
	add r3, ip
	mov sb, r3
	movs r0, #0x20
	add r0, ip
	mov r8, r0
	ldr r1, _080807A0 @ =gSineTable
	mov sl, r1
	ldr r4, _080807A4 @ =0x00003FFF
_0808072C:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r7, r2
	lsls r0, r0, #1
	add r0, sl
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r2, ip
	ldr r0, [r2, #4]
	muls r0, r1, r0
	cmp r0, #0
	bge _08080746
	adds r0, r0, r4
_08080746:
	asrs r6, r0, #0xe
	lsls r0, r7, #1
	add r0, sl
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r2, ip
	ldr r0, [r2, #8]
	muls r0, r1, r0
	cmp r0, #0
	bge _0808075C
	adds r0, r0, r4
_0808075C:
	asrs r3, r0, #0xe
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #2
	mov r0, sb
	adds r0, r0, r1
	str r0, [sp]
	mov r2, ip
	ldr r0, [r2, #0x24]
	adds r0, r6, r0
	ldr r2, [sp]
	str r0, [r2]
	add r1, r8
	mov r2, ip
	ldr r0, [r2, #0x28]
	adds r0, r3, r0
	str r0, [r1]
	adds r7, #0x92
	ldr r3, _080807A8 @ =0x000003FF
	adds r0, r3, #0
	ands r7, r0
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #6
	bls _0808072C
	movs r0, #1
	strb r0, [r2, #1]
	movs r0, #0x6e
	strh r0, [r2, #0xc]
	b _0808087A
	.align 2, 0
_0808079C: .4byte gCamera
_080807A0: .4byte gSineTable
_080807A4: .4byte 0x00003FFF
_080807A8: .4byte 0x000003FF
_080807AC:
	mov r1, ip
	ldrh r0, [r1, #2]
	subs r0, #8
	ldr r2, _08080850 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	mov r3, ip
	strh r0, [r3, #2]
	ldr r0, [r3, #8]
	subs r0, #0x40
	str r0, [r3, #8]
	asrs r0, r0, #8
	cmp r0, #8
	bgt _080807CE
	movs r0, #0x80
	lsls r0, r0, #4
	str r0, [r3, #8]
_080807CE:
	mov r1, ip
	ldr r0, [r1, #8]
	lsls r0, r0, #2
	str r0, [r1, #4]
	mov r4, ip
	adds r4, #0xa8
	movs r5, #0
	ldrh r7, [r1, #2]
	movs r2, #0x1c
	add r2, ip
	mov sb, r2
	movs r3, #0x20
	add r3, ip
	mov r8, r3
	ldr r0, _08080854 @ =0x00003FFF
	mov sl, r0
_080807EE:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	lsls r0, r0, #1
	ldr r2, _08080858 @ =gSineTable
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r2, ip
	ldr r0, [r2, #4]
	muls r0, r1, r0
	cmp r0, #0
	bge _0808080A
	add r0, sl
_0808080A:
	asrs r6, r0, #0xe
	lsls r0, r7, #1
	ldr r3, _08080858 @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r3, ip
	ldr r0, [r3, #8]
	muls r0, r1, r0
	cmp r0, #0
	bge _08080822
	add r0, sl
_08080822:
	asrs r3, r0, #0xe
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #2
	mov r0, sb
	adds r0, r0, r1
	str r0, [sp]
	mov r2, ip
	ldr r0, [r2, #0x24]
	adds r0, r6, r0
	ldr r2, [sp]
	str r0, [r2]
	add r1, r8
	mov r2, ip
	ldr r0, [r2, #0x28]
	adds r0, r3, r0
	str r0, [r1]
	ldr r3, _0808085C @ =0x000001FF
	cmp r7, r3
	bhi _08080860
	movs r0, #0x80
	lsls r0, r0, #2
	b _08080864
	.align 2, 0
_08080850: .4byte 0x000003FF
_08080854: .4byte 0x00003FFF
_08080858: .4byte gSineTable
_0808085C: .4byte 0x000001FF
_08080860:
	movs r0, #0x98
	lsls r0, r0, #3
_08080864:
	strh r0, [r4, #0x14]
	adds r7, #0x92
	ldr r1, _080808E0 @ =0x000003FF
	adds r0, r1, #0
	ands r7, r0
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r4, #0x28
	cmp r5, #6
	bls _080807EE
_0808087A:
	mov r2, ip
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _080808CE
	mov r4, ip
	adds r4, #0xa8
	movs r5, #0
	movs r3, #0x1c
	add r3, ip
	mov sb, r3
	movs r0, #0x20
	add r0, ip
	mov r8, r0
	ldr r6, _080808E4 @ =gCamera
_08080896:
	lsls r2, r5, #2
	adds r2, r2, r5
	lsls r2, r2, #2
	mov r1, sb
	adds r0, r1, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r6]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	add r2, r8
	ldr r0, [r2]
	asrs r0, r0, #8
	ldr r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r4, #0x28
	cmp r5, #6
	bls _08080896
_080808CE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080808E0: .4byte 0x000003FF
_080808E4: .4byte gCamera

.syntax divided
