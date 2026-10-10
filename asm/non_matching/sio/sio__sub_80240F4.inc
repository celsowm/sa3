.syntax unified
.text
	push {lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802412C
	ldr r0, _08024114 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08024118 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _0802411C
	movs r0, #4
	rsbs r0, r0, #0
	b _0802412C
	.align 2, 0
_08024114: .4byte gMultiSioStatusFlags
_08024118: .4byte 0x00000C0C
_0802411C:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0802412A
	movs r1, #0xff
	bl sub_8024374
_0802412A:
	movs r0, #0
_0802412C:
	pop {r1}
	bx r1

.syntax divided
