.syntax unified
.text
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080241F8
	ldr r0, _080241D0 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	ldr r1, _080241D4 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _080241D8
	movs r0, #4
	rsbs r0, r0, #0
	b _080241F8
	.align 2, 0
_080241D0: .4byte gMultiSioStatusFlags
_080241D4: .4byte 0x00000C0C
_080241D8:
	movs r4, #0
	ldr r0, _08024200 @ =gMultiSioRecv
	ldrh r1, [r0]
	ldr r0, _08024204 @ =0x00006C08
	cmp r1, r0
	beq _080241EA
	adds r0, #3
	cmp r1, r0
	bne _080241EC
_080241EA:
	movs r4, #0x10
_080241EC:
	movs r0, #1
	adds r1, r5, #0
	bl sub_80243C4
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_080241F8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08024200: .4byte gMultiSioRecv
_08024204: .4byte 0x00006C08

.syntax divided
