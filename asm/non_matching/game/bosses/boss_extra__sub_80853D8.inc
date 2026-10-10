.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x2c]
	mov r8, r0
	movs r0, #0x40
	bl VramMalloc
	str r0, [r7, #0x6c]
	adds r1, r7, #0
	adds r1, #0x72
	movs r6, #0
	movs r5, #0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	adds r4, r7, #0
	adds r4, #0x74
	movs r0, #0x10
	bl VramMalloc
	str r0, [r7, #0x74]
	movs r0, #0x9f
	lsls r0, r0, #3
	strh r0, [r4, #0xc]
	strb r6, [r4, #0x1a]
	subs r0, #0xb8
	strh r0, [r4, #0x14]
	strh r5, [r4, #0xe]
	strh r5, [r4, #0x16]
	movs r0, #0xff
	strb r0, [r4, #0x1b]
	movs r0, #0x10
	strb r0, [r4, #0x1c]
	strb r6, [r4, #0x1f]
	subs r0, #0x11
	str r0, [r4, #0x20]
	movs r0, #0xa0
	lsls r0, r0, #5
	str r0, [r4, #8]
	mov r1, r8
	ldr r0, [r1, #0x10]
	asrs r0, r0, #8
	ldr r2, _08085454 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	mov r1, r8
	ldr r0, [r1, #0x14]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085454: .4byte gCamera

.syntax divided
