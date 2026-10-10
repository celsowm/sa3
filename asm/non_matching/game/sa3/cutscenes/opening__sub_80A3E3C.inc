.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x18]
	cmp r2, #0
	bge _080A3E5A
	ldrb r0, [r1, #1]
	lsls r0, r0, #8
	adds r0, r2, r0
	str r0, [r1, #0x18]
	cmp r0, #0
	blt _080A3E5A
	movs r0, #0
	str r0, [r1, #0x18]
	movs r0, #1
	b _080A3E5C
_080A3E5A:
	movs r0, #0
_080A3E5C:
	pop {r1}
	bx r1

.syntax divided
