.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x74
	bl VramMalloc
	str r0, [r5, #0x18]
	str r0, [sp]
	movs r6, #0
	movs r0, #0
	mov sl, r0
	movs r1, #0
	mov r8, r1
	ldr r2, _0807CCA4 @ =gCamera
	mov sb, r2
_0807CBEE:
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	adds r0, r5, r0
	ldr r7, [sp]
	str r7, [r0]
	movs r1, #0x9e
	lsls r1, r1, #3         @ r1 = ANIM_BOSS_FINAL_PROJ
	strh r1, [r0, #0xc]
	mov r1, sl
	strb r1, [r0, #0x1a]
	movs r1, #0xa0
	lsls r1, r1, #3
	strh r1, [r0, #0x14]
	mov r2, r8
	strh r2, [r0, #0xe]
	strh r2, [r0, #0x16]
	movs r1, #0xff
	strb r1, [r0, #0x1b]
	movs r1, #0x10
	strb r1, [r0, #0x1c]
	mov r3, sl
	strb r3, [r0, #0x1f]
	subs r1, #0x11
	str r1, [r0, #0x20]
	movs r1, #0x80
	lsls r1, r1, #5
	str r1, [r0, #8]
	lsls r4, r6, #3
	subs r4, r4, r6
	lsls r4, r4, #2
	movs r7, #0xca
	lsls r7, r7, #1
	adds r2, r5, r7
	adds r2, r2, r4
	movs r1, #0xcf
	lsls r1, r1, #0xb
	str r1, [r2]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r3, r5, r1
	adds r3, r3, r4
	movs r1, #0xb0
	lsls r1, r1, #9
	str r1, [r3]
	ldr r1, [r2]
	asrs r1, r1, #8
	mov r7, sb
	ldr r2, [r7]
	subs r1, r1, r2
	strh r1, [r0, #0x10]
	ldr r1, [r3]
	asrs r1, r1, #8
	ldr r2, [r7, #4]
	subs r1, r1, r2
	strh r1, [r0, #0x12]
	bl UpdateSpriteAnimation
	adds r1, r5, r4
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r1, r2
	mov r3, r8
	strh r3, [r0]
	movs r7, #0xd7
	lsls r7, r7, #1
	adds r1, r1, r7
	movs r0, #1
	strh r0, [r1]
	ldr r0, [sp]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #2
	bls _0807CBEE
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807CCA4: .4byte gCamera

.syntax divided
