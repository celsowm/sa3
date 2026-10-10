.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r6, _08081708 @ =gCamera
_080816C8:
	lsls r3, r4, #2
	adds r3, r3, r4
	lsls r0, r3, #3
	adds r0, #0x7c
	adds r0, r5, r0
	lsls r3, r3, #2
	adds r1, r5, #0
	adds r1, #0x2c
	adds r1, r1, r3
	ldr r1, [r1]
	asrs r1, r1, #8
	ldr r2, [r6]
	subs r1, r1, r2
	strh r1, [r0, #0x10]
	adds r1, r5, #0
	adds r1, #0x30
	adds r1, r1, r3
	ldr r1, [r1]
	asrs r1, r1, #8
	ldr r2, [r6, #4]
	subs r1, r1, r2
	strh r1, [r0, #0x12]
	bl DisplaySprite
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _080816C8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081708: .4byte gCamera

.syntax divided
