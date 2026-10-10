.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024032
	ldr r0, _08024000 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08024004 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08024008
	movs r0, #4
	rsbs r0, r0, #0
	b _08024032
	.align 2, 0
_08024000: .4byte gMultiSioStatusFlags
_08024004: .4byte 0x00000C0C
_08024008:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08024014
	movs r0, #0
	b _08024032
_08024014:
	ldr r2, _08024038 @ =gMultiSioRecv
	movs r4, #0
	ldrh r1, [r2]
	ldr r0, _0802403C @ =0x00006C0C
	cmp r1, r0
	bne _0802402A
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	ldrb r4, [r2, #7]
	orrs r4, r0
_0802402A:
	ldrb r0, [r2, #7]
	bl sub_80243F8
	adds r0, r4, #0
_08024032:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08024038: .4byte gMultiSioRecv
_0802403C: .4byte 0x00006C0C

.syntax divided
