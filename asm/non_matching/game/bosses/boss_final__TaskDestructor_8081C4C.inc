.syntax unified
.text
	push {r4, lr}
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _08081C64
	bl VramFree
	movs r0, #0
	str r0, [r4, #8]
_08081C64:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _08081C6E
	bl VramFree
_08081C6E:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _08081C78
	bl VramFree
_08081C78:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
