.syntax unified
.text
	push {r4, lr}
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080817F8
	bl VramFree
	movs r0, #0
	str r0, [r4, #0x18]
_080817F8:
	adds r0, r4, #0
	bl sub_8081AA0
	adds r0, r4, #0
	bl sub_8081A40
	adds r0, r4, #0
	bl sub_808170C
	pop {r4}
	pop {r0}
	bx r0

.syntax divided
