.syntax unified
.text
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024290
	ldr r0, _08024278 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _0802427C @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08024280
	movs r0, #4
	rsbs r0, r0, #0
	b _08024290
	.align 2, 0
_08024278: .4byte gMultiSioStatusFlags
_0802427C: .4byte 0x00000C0C
_08024280:
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _0802428E
	adds r0, r4, #0
	bl sub_80243E4
_0802428E:
	movs r0, #0
_08024290:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
