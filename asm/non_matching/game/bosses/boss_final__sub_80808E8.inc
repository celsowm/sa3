.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _0808099C @ =Task_11C_8080AD4
	movs r1, #0x8e
	lsls r1, r1, #1     @ 0x11C
	movs r2, #0x84
	lsls r2, r2, #6
	ldr r3, _080809A0 @ =TaskDestructor_8081C4C
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	str r0, [sp, #4]
	ldrh r2, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r7, r2, r0
	movs r1, #0
	strb r4, [r7]
	movs r0, #1
	strh r0, [r7, #4]
	strh r1, [r7, #6]
	strh r1, [r7, #2]
	str r1, [r7, #0xc]
	str r1, [r7, #0x10]
	movs r4, #0
	ldr r0, _080809A4 @ =0x03000068
	adds r1, r2, r0
	movs r3, #0
	adds r5, r1, #0
_08080932:
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, r1, r0
	str r3, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #2
	bls _08080932
	movs r4, #0
	adds r1, r7, #0
	adds r1, #0x1c
	str r1, [sp, #8]
	adds r2, r7, #0
	adds r2, #0x20
	str r2, [sp, #0xc]
	movs r0, #0x24
	adds r0, r0, r7
	mov sl, r0
	adds r6, r7, #0
	adds r6, #0xa0
	movs r1, #0xd8
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _080809A8 @ =gCamera
	mov sb, r2
	mov ip, r4
_0808096A:
	cmp r4, #2
	beq _080809AC
	lsls r3, r4, #3
	subs r2, r3, r4
	lsls r2, r2, #2
	adds r1, r7, #0
	adds r1, #0x14
	adds r1, r1, r2
	str r1, [sp, #0x14]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x78
	lsls r0, r0, #8
	ldr r1, [sp, #0x14]
	str r0, [r1]
	adds r1, r7, #0
	adds r1, #0x18
	adds r1, r1, r2
	mov r2, sb
	ldr r0, [r2, #4]
	adds r0, #0xb4
	lsls r0, r0, #8
	str r0, [r1]
	b _080809C0
	.align 2, 0
_0808099C: .4byte Task_11C_8080AD4
_080809A0: .4byte TaskDestructor_8081C4C
_080809A4: .4byte 0x03000068
_080809A8: .4byte gCamera
_080809AC:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x8c
	lsls r0, r0, #8
	str r0, [r7, #0x4c]
	ldr r0, [r1, #4]
	adds r0, #0xd4
	lsls r0, r0, #8
	str r0, [r7, #0x50]
	movs r3, #0x10
_080809C0:
	subs r1, r3, r4
	lsls r1, r1, #2
	ldr r2, [sp, #8]
	adds r0, r2, r1
	mov r2, ip
	str r2, [r0]
	ldr r2, [sp, #0xc]
	adds r0, r2, r1
	mov r2, ip
	str r2, [r0]
	mov r2, sl
	adds r0, r2, r1
	mov r2, ip
	str r2, [r0]
	adds r1, r7, r1
	movs r0, #1
	strh r0, [r1, #0x28]
	strh r2, [r1, #0x2a]
	ldrb r0, [r7]
	cmp r0, #0
	beq _080809EE
	movs r0, #0xfa
	lsls r0, r0, #2
_080809EE:
	strh r0, [r1, #0x2c]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #2
	bls _0808096A
	ldrb r0, [r7]
	cmp r0, #0
	bne _08080A08
	movs r0, #0x74
	bl VramMalloc
	b _08080A0A
_08080A08:
	movs r0, #0
_08080A0A:
	str r0, [r7, #8]
	movs r0, #0x80
	bl VramMalloc
	adds r1, r0, #0
	str r1, [r7, #0xc]
	str r1, [r7, #0x68]
	movs r2, #0
	movs r4, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	strh r0, [r5, #0x14]
	subs r0, #0x48		@ r0 = ANIM_EGGMAN_SIDE
	strh r0, [r5, #0xc]
	movs r0, #4
	strb r0, [r5, #0x1a]
	strh r4, [r5, #0x16]
	movs r0, #0xff
	strb r0, [r5, #0x1b]
	movs r0, #0x10
	mov sl, r0
	mov r0, sl
	strb r0, [r5, #0x1c]
	strb r2, [r5, #0x1f]
	strh r4, [r5, #0x10]
	strh r4, [r5, #0x12]
	movs r0, #0x80
	lsls r0, r0, #5
	mov sb, r0
	str r0, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r1, r0
	str r1, [r6]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r6, #0x14]
	subs r0, #0x89
	strh r0, [r6, #0xc]
	strb r2, [r6, #0x1a]
	strh r4, [r6, #0x16]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r6, #0x1b]
	mov r1, sl
	strb r1, [r6, #0x1c]
	movs r0, #9
	strb r0, [r6, #0x1f]
	strh r4, [r6, #0x10]
	strh r4, [r6, #0x12]
	mov r0, sb
	str r0, [r6, #8]
	movs r0, #0x88
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r7, #2]
	strh r0, [r1]
	ldrh r0, [r6, #0x10]
	strh r0, [r1, #6]
	ldrh r0, [r6, #0x12]
	strh r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r0, #0x24
	str r2, [sp, #0x10]
	bl VramMalloc
	adds r1, r0, #0
	str r1, [r7, #0x10]
	mov r0, r8
	str r1, [r0]
	movs r0, #0xa0
	lsls r0, r0, #3
	mov r1, r8
	strh r0, [r1, #0x14]
	adds r0, #0xa		@ r0 = ANIM_GEMERL_HOVER_AWAY
	strh r0, [r1, #0xc]
	ldr r2, [sp, #0x10]
	strb r2, [r1, #0x1a]
	strh r4, [r1, #0x16]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #0x1b]
	mov r0, sl
	strb r0, [r1, #0x1c]
	strb r2, [r1, #0x1f]
	strh r4, [r1, #0x10]
	strh r4, [r1, #0x12]
	mov r2, sb
	str r2, [r1, #8]
	ldr r0, [sp, #4]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

.syntax divided
