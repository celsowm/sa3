.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802417A
	ldr r0, _08024150 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08024154 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08024158
	movs r0, #4
	rsbs r0, r0, #0
	b _0802417A
	.align 2, 0
_08024150: .4byte gMultiSioStatusFlags
_08024154: .4byte 0x00000C0C
_08024158:
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _08024164
	movs r0, #0
	b _0802417A
_08024164:
	ldr r0, _08024180 @ =gMultiSioRecv+1*0x18
	movs r4, #0
	ldrh r1, [r0]
	ldr r0, _08024184 @ =0x00006C0A
	cmp r1, r0
	bne _08024172
	movs r4, #0x10
_08024172:
	bl sub_80243B4
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_0802417A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08024180: .4byte gMultiSioRecv+1*0x18
_08024184: .4byte 0x00006C0A

.syntax divided
