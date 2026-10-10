.syntax unified
.text
	push {r4, r5, lr}
	ldr r0, _080A2DC8 @ =gCurTask
	ldr r0, [r0]
	ldrh r5, [r0, #6]
	movs r4, #0xc0
	lsls r4, r4, #0x12
	adds r4, r5, r4
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	ldr r0, _080A2DCC @ =0x03000050
	adds r1, r5, r0
	adds r0, r4, #0
	bl TransformSprite
	adds r0, r4, #0
	bl DisplaySprite
	ldr r0, _080A2DD0 @ =0x03000028
	adds r4, r5, r0
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	ldr r0, _080A2DD4 @ =0x0300005C
	adds r5, r5, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl TransformSprite
	adds r0, r4, #0
	bl DisplaySprite
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2DC8: .4byte gCurTask
_080A2DCC: .4byte 0x03000050
_080A2DD0: .4byte 0x03000028
_080A2DD4: .4byte 0x0300005C

.syntax divided
