.syntax unified
.text
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x94
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _08081A58
	bl VramFree
	movs r0, #0
	str r0, [r4]
_08081A58:
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _08081A6C
	bl VramFree
	movs r0, #0
	str r0, [r4]
_08081A6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
