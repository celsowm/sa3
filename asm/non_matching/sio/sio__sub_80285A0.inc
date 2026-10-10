.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _080285DC @ =gCurTask
	ldr r0, [r0]
	ldrh r5, [r0, #6]
	ldr r0, _080285E0 @ =0x0300008C
	adds r6, r5, r0
	adds r0, r6, #0
	bl UpdateSpriteAnimation
	adds r0, r6, #0
	bl DisplaySprite
	ldr r0, _080285E4 @ =0x030000B4
	adds r6, r5, r0
	ldr r0, _080285E8 @ =0x00000596		@ ANIM_MP_TXT_CHARS_AND_ACTS
	strh r0, [r6, #0xc]
	adds r4, #0xd
	strb r4, [r6, #0x1a]
	adds r0, r6, #0
	bl UpdateSpriteAnimation
	adds r0, r6, #0
	bl DisplaySprite
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080285DC: .4byte gCurTask
_080285E0: .4byte 0x0300008C
_080285E4: .4byte 0x030000B4
_080285E8: .4byte 0x00000596

.syntax divided
