.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	movs r5, #0xa2
	lsls r5, r5, #1
	add r5, sl
	ldr r0, _0807D804 @ =0x0005C400
	str r0, [r5]
	movs r6, #0xa4
	lsls r6, r6, #1
	add r6, sl
	movs r4, #0x98
	lsls r4, r4, #8
	str r4, [r6]
	mov r0, sl
	movs r1, #0
	movs r2, #0
	bl sub_807DB00
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, sl
	mov sb, r0
	ldr r0, _0807D808 @ =0x00072C00
	mov r1, sb
	str r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	add r0, sl
	mov r8, r0
	str r4, [r0]
	mov r0, sl
	movs r1, #1
	movs r2, #0
	bl sub_807DB00
	movs r7, #0x9e
	lsls r7, r7, #2
	add r7, sl
	movs r2, #0xd0
	lsls r2, r2, #2
	add r2, sl
	movs r0, #0x40
	str r2, [sp]
	bl VramMalloc
	str r0, [r7]
	ldr r1, _0807D80C @ =0x000004F1 @ ANIM_BOSS_FINAL_HAND
	strh r1, [r7, #0xc]
	movs r0, #0
	strb r0, [r7, #0x1a]
	adds r1, #0xf
	strh r1, [r7, #0x14]
	movs r0, #0
	strh r0, [r7, #0xe]
	strh r0, [r7, #0x16]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r1, #0x10
	strb r1, [r7, #0x1c]
	movs r0, #0
	strb r0, [r7, #0x1f]
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r7, #0x20]
	ldr r0, _0807D810 @ =0x0000106A
	str r0, [r7, #8]
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r5, _0807D814 @ =gCamera
	ldr r1, [r5]
	subs r0, r0, r1
	strh r0, [r7, #0x10]
	ldr r0, [r6]
	asrs r0, r0, #8
	ldr r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	ldr r2, [sp]
	movs r0, #0
	strh r0, [r2]
	ldrh r0, [r7, #0x10]
	strh r0, [r2, #6]
	ldrh r0, [r7, #0x12]
	strh r0, [r2, #8]
	movs r4, #0x80
	lsls r4, r4, #1
	strh r4, [r2, #2]
	strh r4, [r2, #4]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	movs r7, #0xa8
	lsls r7, r7, #2
	add r7, sl
	movs r2, #0xd3
	lsls r2, r2, #2
	add r2, sl
	movs r0, #0x40
	str r2, [sp]
	bl VramMalloc
	str r0, [r7]
	ldr r1, _0807D80C @ =0x000004F1 @ ANIM_BOSS_FINAL_HAND
	strh r1, [r7, #0xc]
	movs r0, #6
	strb r0, [r7, #0x1a]
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r7, #0x14]
	movs r1, #0
	strh r1, [r7, #0xe]
	strh r1, [r7, #0x16]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r7, #0x1b]
	movs r0, #0x10
	strb r0, [r7, #0x1c]
	strb r1, [r7, #0x1f]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r7, #0x20]
	ldr r0, _0807D818 @ =0x0000106B
	str r0, [r7, #8]
	mov r1, sb
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r1, [r5]
	subs r0, r0, r1
	strh r0, [r7, #0x10]
	mov r1, r8
	ldr r0, [r1]
	asrs r0, r0, #8
	ldr r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	ldr r2, [sp]
	movs r0, #0
	strh r0, [r2]
	ldrh r0, [r7, #0x10]
	strh r0, [r2, #6]
	ldrh r0, [r7, #0x12]
	strh r0, [r2, #8]
	strh r4, [r2, #2]
	strh r4, [r2, #4]
	adds r0, r7, #0
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
_0807D804: .4byte 0x0005C400
_0807D808: .4byte 0x00072C00
_0807D80C: .4byte 0x000004F1
_0807D810: .4byte 0x0000106A
_0807D814: .4byte gCamera
_0807D818: .4byte 0x0000106B

.syntax divided
