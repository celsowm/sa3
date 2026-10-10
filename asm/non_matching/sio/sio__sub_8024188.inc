.syntax unified
.text
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080241A4
	movs r0, #1
	adds r1, r4, #0
	bl sub_8024394
	movs r0, #0
_080241A4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
