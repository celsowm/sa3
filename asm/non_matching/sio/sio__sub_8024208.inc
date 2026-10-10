.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024246
	ldr r0, _08024228 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	ldr r1, _0802422C @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08024230
	movs r0, #4
	rsbs r0, r0, #0
	b _08024246
	.align 2, 0
_08024228: .4byte gMultiSioStatusFlags
_0802422C: .4byte 0x00000C0C
_08024230:
	movs r4, #0
	ldr r0, _0802424C @ =gMultiSioRecv
	ldrh r1, [r0]
	ldr r0, _08024250 @ =0x00006C0A
	cmp r1, r0
	bne _0802423E
	movs r4, #0x10
_0802423E:
	bl sub_80243B4
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_08024246:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802424C: .4byte gMultiSioRecv
_08024250: .4byte 0x00006C0A

.syntax divided
