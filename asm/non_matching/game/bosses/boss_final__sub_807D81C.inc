.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r3, r6, r1
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	asrs r2, r2, #8
	ldr r4, _0807D8B0 @ =gCamera
	ldr r0, [r4]
	subs r2, r2, r0
	strh r2, [r5, #0x10]
	adds r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	strh r2, [r3, #6]
	ldrh r0, [r5, #0x12]
	strh r0, [r3, #8]
	adds r0, r5, #0
	adds r1, r3, #0
	bl TransformSprite
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r3, r6, r1
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	asrs r2, r2, #8
	ldr r0, [r4]
	subs r2, r2, r0
	strh r2, [r5, #0x10]
	adds r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	strh r2, [r3, #6]
	ldrh r0, [r5, #0x12]
	strh r0, [r3, #8]
	adds r0, r5, #0
	adds r1, r3, #0
	bl TransformSprite
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D8B0: .4byte gCamera

.syntax divided
