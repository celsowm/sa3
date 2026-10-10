.syntax unified
.text
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080242F4
	ldr r0, _080242BC @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _080242C0 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _080242C4
	movs r0, #4
	rsbs r0, r0, #0
	b _080242F4
	.align 2, 0
_080242BC: .4byte gMultiSioStatusFlags
_080242C0: .4byte 0x00000C0C
_080242C4:
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _080242D0
	movs r0, #0
	b _080242F4
_080242D0:
	adds r0, r4, #0
	bl sub_80243F8
	ldr r0, _080242FC @ =gMultiSioRecv+1*0x18
	ldrh r1, [r0]
	ldr r0, _08024300 @ =0x00006C0C
	cmp r1, r0
	bne _080242F0
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r0, #0
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_080242F0:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
_080242F4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080242FC: .4byte gMultiSioRecv+1*0x18
_08024300: .4byte 0x00006C0C

.syntax divided
