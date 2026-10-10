.syntax unified
.text
	push {r4, r5, lr}
	ldr r2, _08086E80 @ =gCurTask
	ldr r0, [r2]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	adds r0, #0x10
	adds r5, r1, r0
	ldrb r0, [r4, #0xe]
	subs r0, #1
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08086E84
	ldr r0, [r2]
	bl TaskDestroy
	b _08086ECC
	.align 2, 0
_08086E80: .4byte gCurTask
_08086E84:
	ldr r3, _08086ED4 @ =gCamera
	adds r0, r3, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	ldr r1, [r4]
	adds r1, r1, r0
	movs r2, #8
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	str r1, [r4]
	ldrh r0, [r4, #0xc]
	ldrh r2, [r4, #0xa]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	ldr r0, [r4, #4]
	adds r0, r0, r2
	str r0, [r4, #4]
	asrs r1, r1, #8
	ldr r0, [r3]
	subs r1, r1, r0
	strh r1, [r5, #0x10]
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	ldr r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
_08086ECC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086ED4: .4byte gCamera

.syntax divided
