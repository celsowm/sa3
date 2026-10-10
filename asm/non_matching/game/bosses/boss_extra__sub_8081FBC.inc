.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldrb r0, [r7, #1]
	cmp r0, #6
	beq _08082014
	adds r4, r7, #0
	adds r4, #0x9c
	ldr r0, _08082010 @ =gCamera
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0xc8
	lsls r0, r0, #8
	str r0, [r4]
	adds r3, r7, #0
	adds r3, #0xa0
	movs r2, #0xf0
	lsls r2, r2, #7
	str r2, [r3]
	adds r0, r7, #0
	adds r0, #0xf4
	adds r1, #0x78
	lsls r1, r1, #8
	str r1, [r0]
	adds r0, #4
	str r2, [r0]
	subs r0, #0x48
	str r2, [r0]
	adds r1, r7, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	b _0808204C
	.align 2, 0
_08082010: .4byte gCamera
_08082014:
	adds r4, r7, #0
	adds r4, #0x9c
	ldr r0, _08082110 @ =gCamera
	ldr r2, [r0]
	adds r2, #0x78
	lsls r2, r2, #8
	str r2, [r4]
	adds r3, r7, #0
	adds r3, #0xa0
	ldr r0, [r0, #4]
	adds r0, #0x50
	lsls r0, r0, #8
	str r0, [r3]
	adds r1, r7, #0
	adds r1, #0xf4
	str r2, [r1]
	adds r1, #4
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb0
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #2
_0808204C:
	strb r0, [r1]
	mov r8, r4
	mov sl, r3
	adds r0, r7, #0
	adds r0, #0xfc
	movs r4, #0
	str r4, [r0]
	movs r1, #0xb8
	adds r1, r1, r7
	mov sb, r1
	movs r5, #0
	strh r4, [r1]
	adds r1, r7, #0
	adds r1, #0xa4
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xee
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl sub_8086FF8
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r6, r7, r0
	ldr r1, _08082114 @ =0x0000083C
	adds r3, r7, r1
	movs r0, #0x80
	str r3, [sp]
	bl VramMalloc
	str r0, [r6]
	ldr r0, _08082118 @ =0x000004FD
	strh r0, [r6, #0xc]
	strb r5, [r6, #0x1a]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r6, #0x14]
	strh r4, [r6, #0xe]
	strh r4, [r6, #0x16]
	movs r0, #0xff
	strb r0, [r6, #0x1b]
	movs r0, #0x10
	strb r0, [r6, #0x1c]
	strb r5, [r6, #0x1f]
	subs r0, #0x11
	str r0, [r6, #0x20]
	movs r1, #0x80
	lsls r1, r1, #5
	str r1, [r6, #8]
	ldrb r0, [r7, #1]
	ldr r3, [sp]
	cmp r0, #6
	beq _080820CA
	movs r0, #0x2a
	orrs r0, r1
	str r0, [r6, #8]
_080820CA:
	mov r1, r8
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r2, _08082110 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r6, #0x10]
	mov r1, sl
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r6, #0x12]
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r3]
	ldrh r0, [r6, #0x10]
	strh r0, [r3, #6]
	ldrh r0, [r6, #0x12]
	strh r0, [r3, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3, #2]
	strh r0, [r3, #4]
	adds r0, r6, #0
	bl UpdateSpriteAnimation
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082110: .4byte gCamera
_08082114: .4byte 0x0000083C
_08082118: .4byte 0x000004FD

.syntax divided
