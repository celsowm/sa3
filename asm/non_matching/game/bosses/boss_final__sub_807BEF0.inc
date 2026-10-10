.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, sl
	mov r8, r0
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	mov r1, r8
	str r0, [r1]
	movs r0, #0x9a
	lsls r0, r0, #1
	add r0, sl
	mov sb, r0
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	ldr r1, _0807BFDC @ =0xFFFFB800
	adds r0, r0, r1
	mov r1, sb
	str r0, [r1]
	movs r7, #0x94
	lsls r7, r7, #2
	add r7, sl
	movs r0, #0x10
	bl VramMalloc
	str r0, [r7]
	movs r6, #0
	movs r5, #0
	ldr r0, _0807BFE0 @ =0x000004F2 @ ANIM_BOSS_FINAL_GLASS
	strh r0, [r7, #0xc]
	strb r6, [r7, #0x1a]
	adds r0, #0x8e
	strh r0, [r7, #0x14]
	strh r5, [r7, #0xe]
	strh r5, [r7, #0x16]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r1, #0x10
	strb r1, [r7, #0x1c]
	strb r6, [r7, #0x1f]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r7, #0x20]
	movs r1, #0x80
	lsls r1, r1, #6
	str r1, [r7, #8]
	mov r1, r8
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r4, _0807BFE4 @ =gCamera
	ldr r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #0x10]
	mov r1, sb
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	movs r7, #0x8a
	lsls r7, r7, #2
	add r7, sl
	movs r0, #8
	bl VramMalloc
	str r0, [r7]
	ldr r0, _0807BFE8 @ =0x000004F3 @ ANIM_BOSS_FINAL_EGGMAN
	strh r0, [r7, #0xc]
	strb r6, [r7, #0x1a]
	adds r0, #0x8d
	strh r0, [r7, #0x14]
	strh r5, [r7, #0xe]
	strh r5, [r7, #0x16]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r7, #0x1b]
	movs r1, #0x10
	strb r1, [r7, #0x1c]
	strb r6, [r7, #0x1f]
	str r0, [r7, #0x20]
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r7, #8]
	mov r1, r8
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #0x10]
	mov r1, sb
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807BFDC: .4byte 0xFFFFB800
_0807BFE0: .4byte 0x000004F2
_0807BFE4: .4byte gCamera
_0807BFE8: .4byte 0x000004F3

.syntax divided
