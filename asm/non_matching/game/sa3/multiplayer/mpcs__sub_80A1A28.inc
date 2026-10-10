.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r2, r1, r0
	ldr r0, [r1, #0x18]
	ldrb r0, [r0]
	ldr r0, [r1, #0x4c]
	asrs r0, r0, #8
	strh r0, [r2, #0x10]
	ldr r0, [r1, #0x50]
	asrs r0, r0, #8
	strh r0, [r2, #0x12]
	adds r0, r2, #0
	bl DisplaySprite
	pop {r0}
	bx r0

.syntax divided
