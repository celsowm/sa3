.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r0, #0x10
	bl VramMalloc
	str r0, [sp, #4]
	movs r0, #1
	bl VramMalloc
	str r0, [sp, #8]
	movs r0, #0
	mov r8, r0
	movs r1, #0x80
	str r1, [sp]
_0808251A:
	ldr r2, [sp]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r2, r3
	lsls r0, r0, #1
	ldr r4, _0808276C @ =gSineTable
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _08082538
	adds r0, #0x3f
_08082538:
	asrs r4, r0, #6
	ldr r1, [sp]
	lsls r0, r1, #1
	ldr r2, _0808276C @ =gSineTable
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _08082552
	adds r0, #0x3f
_08082552:
	asrs r3, r0, #6
	mov r5, r8
	lsls r1, r5, #1
	add r1, r8
	lsls r2, r1, #3
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r7, r5
	adds r0, r0, r2
	mov sb, r0
	adds r5, r7, #0
	adds r5, #0x9c
	ldr r0, [r5]
	adds r0, r0, r4
	mov r4, sb
	str r0, [r4]
	movs r4, #0x88
	lsls r4, r4, #1
	adds r0, r7, r4
	adds r0, r0, r2
	mov ip, r0
	adds r4, r7, #0
	adds r4, #0xa0
	ldr r0, [r4]
	adds r0, r0, r3
	mov r3, ip
	str r0, [r3]
	adds r2, r7, r2
	movs r0, #0x90
	lsls r0, r0, #1
	adds r2, r2, r0
	mov r3, sp
	ldrh r3, [r3]
	strh r3, [r2]
	mov r3, r8
	lsls r0, r3, #2
	add r0, r8
	lsls r0, r0, #3
	movs r3, #0xed
	lsls r3, r3, #2
	adds r0, r0, r3
	adds r6, r7, r0
	lsls r1, r1, #2
	ldr r0, _08082770 @ =0x00000848
	adds r1, r1, r0
	adds r3, r7, r1
	ldr r1, [sp, #4]
	str r1, [r6]
	ldr r0, _08082774 @ =0x000004FE
	strh r0, [r6, #0xc]
	movs r0, #1
	strb r0, [r6, #0x1a]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r6, #0x14]
	movs r0, #0
	strh r0, [r6, #0xe]
	strh r0, [r6, #0x16]
	movs r0, #0xff
	strb r0, [r6, #0x1b]
	movs r0, #0x10
	strb r0, [r6, #0x1c]
	movs r1, #0
	strb r1, [r6, #0x1f]
	subs r0, #0x11
	str r0, [r6, #0x20]
	movs r0, #0x20
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	mov r1, r8
	adds r1, #0xb
	orrs r1, r0
	str r1, [r6, #8]
	str r5, [sp, #0x14]
	str r4, [sp, #0x18]
	mov r4, r8
	cmp r4, #0
	beq _080825F8
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r6, #8]
_080825F8:
	mov r5, sb
	ldr r1, [r5]
	asrs r1, r1, #8
	ldr r4, _08082778 @ =gCamera
	ldr r0, [r4]
	subs r1, r1, r0
	strh r1, [r6, #0x10]
	mov r1, ip
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r6, #0x12]
	ldr r5, _0808277C @ =0xFFFFFD80
	adds r0, r5, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	ldr r2, _08082780 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r6, #0x10]
	strh r0, [r3, #6]
	ldrh r0, [r6, #0x12]
	strh r0, [r3, #8]
	movs r5, #0x80
	lsls r5, r5, #1
	strh r5, [r3, #2]
	adds r0, r5, #0
	strh r0, [r3, #4]
	adds r0, r6, #0
	bl UpdateSpriteAnimation
	movs r5, #0
	mov r1, r8
	lsls r0, r1, #4
	adds r1, #1
	str r1, [sp, #0x10]
	mov r2, r8
	subs r2, r0, r2
	mov sb, r2
	lsls r0, r2, #4
	ldr r3, _08082784 @ =0x00000454
	adds r0, r0, r3
	adds r0, r7, r0
	str r0, [sp, #0xc]
	mov sl, r4
_08082656:
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r2, r1, #2
	mov r4, sb
	lsls r0, r4, #3
	adds r2, r2, r0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r3, r7, r0
	adds r3, r3, r2
	ldr r4, [sp, #0x14]
	ldr r0, [r4]
	str r0, [r3]
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r4, r7, r0
	adds r4, r4, r2
	ldr r2, [sp, #0x18]
	ldr r0, [r2]
	str r0, [r4]
	lsls r1, r1, #3
	ldr r0, [sp, #0xc]
	adds r6, r0, r1
	ldr r1, [sp, #8]
	str r1, [r6]
	ldr r0, _08082788 @ =0x000004FF
	strh r0, [r6, #0xc]
	movs r2, #0
	strb r2, [r6, #0x1a]
	subs r0, #0x3f
	strh r0, [r6, #0x14]
	movs r0, #0
	strh r0, [r6, #0xe]
	strh r0, [r6, #0x16]
	movs r0, #0xff
	strb r0, [r6, #0x1b]
	movs r0, #0x10
	strb r0, [r6, #0x1c]
	movs r1, #0
	strb r1, [r6, #0x1f]
	subs r0, #0x11
	str r0, [r6, #0x20]
	movs r2, #0x80
	lsls r2, r2, #5
	str r2, [r6, #8]
	ldr r0, [r3]
	asrs r0, r0, #8
	mov r3, sl
	ldr r1, [r3]
	subs r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r0, [r4]
	asrs r0, r0, #8
	ldr r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r6, #0x12]
	mov r4, r8
	cmp r4, #0
	bne _080826D0
	cmp r5, #0
	beq _080826D6
_080826D0:
	movs r0, #0x81
	lsls r0, r0, #0xc
	str r0, [r6, #8]
_080826D6:
	adds r0, r6, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #5
	bls _08082656
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r2, [sp]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	mov r4, r8
	cmp r4, #3
	bhi _08082704
	b _0808251A
_08082704:
	ldr r5, _0808278C @ =0x00000814
	adds r6, r7, r5
	movs r0, #0x10
	bl VramMalloc
	str r0, [r6]
	movs r3, #0
	movs r1, #0
	ldr r0, _08082790 @ =0x00000504
	strh r0, [r6, #0xc]
	strb r3, [r6, #0x1a]
	movs r0, #0x90
	lsls r0, r0, #2
	strh r0, [r6, #0x14]
	strh r1, [r6, #0xe]
	strh r1, [r6, #0x16]
	movs r0, #0xff
	strb r0, [r6, #0x1b]
	movs r0, #0x10
	strb r0, [r6, #0x1c]
	strb r3, [r6, #0x1f]
	subs r0, #0x11
	str r0, [r6, #0x20]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r6, #8]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r2, _08082778 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r6, #0x10]
	movs r4, #0x88
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r6, #0x12]
	strb r3, [r7, #0xf]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808276C: .4byte gSineTable
_08082770: .4byte 0x00000848
_08082774: .4byte 0x000004FE
_08082778: .4byte gCamera
_0808277C: .4byte 0xFFFFFD80
_08082780: .4byte 0x000003FF
_08082784: .4byte 0x00000454
_08082788: .4byte 0x000004FF
_0808278C: .4byte 0x00000814
_08082790: .4byte 0x00000504

.syntax divided
