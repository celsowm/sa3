.syntax unified
.text
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080240AC
	ldr r0, _080240A0 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	ldr r1, _080240A4 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	bne _080240A8
	movs r0, #0
	adds r1, r4, #0
	bl sub_8024354
	movs r0, #0
	b _080240AC
	.align 2, 0
_080240A0: .4byte gMultiSioStatusFlags
_080240A4: .4byte 0x00000C0C
_080240A8:
	movs r0, #4
	rsbs r0, r0, #0
_080240AC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
