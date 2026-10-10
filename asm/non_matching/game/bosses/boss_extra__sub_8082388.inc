.syntax unified
.text
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r4, r3, r0
	ldr r1, _080823A8 @ =0x0000083C
	adds r5, r3, r1
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080823AC
	cmp r0, #2
	beq _080823F4
	b _0808241E
	.align 2, 0
_080823A8: .4byte 0x0000083C
_080823AC:
	adds r0, r3, #0
	adds r0, #0x9c
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r2, _080823F0 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	adds r0, r3, #0
	adds r0, #0xa0
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	adds r0, r3, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	strh r0, [r5]
	ldrh r0, [r4, #0x10]
	strh r0, [r5, #6]
	ldrh r0, [r4, #0x12]
	strh r0, [r5, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	bl TransformSprite
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	b _0808241E
	.align 2, 0
_080823F0: .4byte gCamera
_080823F4:
	adds r0, r3, #0
	adds r0, #0x9c
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r2, _08082424 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	adds r0, r3, #0
	adds r0, #0xa0
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
_0808241E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082424: .4byte gCamera

.syntax divided
