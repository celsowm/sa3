.syntax unified
.text
	push {lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08025AA4
	bl sub_8025D00
	movs r0, #0
_08025AA4:
	pop {r1}
	bx r1

.syntax divided
