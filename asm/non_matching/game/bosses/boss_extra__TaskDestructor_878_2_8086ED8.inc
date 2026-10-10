.syntax unified
.text
	push {r4, lr}
	ldrh r4, [r0, #6]
	ldr r1, _08086F00 @ =0x0300038C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08086EEA
	bl VramFree
_08086EEA:
	ldr r1, _08086F04 @ =0x03000454
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08086EF8
	bl VramFree
_08086EF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086F00: .4byte 0x0300038C
_08086F04: .4byte 0x03000454

.syntax divided
