.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	adds r2, #0x2c
	ldr r1, [r0, #0x20]
	asrs r1, r1, #8
	strh r1, [r2, #0x10]
	ldr r0, [r0, #0x24]
	asrs r0, r0, #8
	strh r0, [r2, #0x12]
	adds r0, r2, #0
	bl DisplaySprite
	pop {r0}
	bx r0

.syntax divided
