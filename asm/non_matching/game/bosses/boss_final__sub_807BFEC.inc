.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r5, #0x98
	lsls r5, r5, #1
	add r5, r8
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	str r0, [r5]
	movs r6, #0x9a
	lsls r6, r6, #1
	add r6, r8
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ldr r1, _0807C06C @ =0xFFFFB800
	adds r0, r0, r1
	str r0, [r6]
	movs r7, #0x8a
	lsls r7, r7, #2
	add r7, r8
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r4, _0807C070 @ =gCamera
	ldr r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #0x10]
	ldr r0, [r6]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	adds r0, r7, #0
	bl DisplaySprite
	movs r7, #0x94
	lsls r7, r7, #2
	add r7, r8
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #0x10]
	ldr r0, [r6]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	adds r0, r7, #0
	bl DisplaySprite
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C06C: .4byte 0xFFFFB800
_0807C070: .4byte gCamera

.syntax divided
