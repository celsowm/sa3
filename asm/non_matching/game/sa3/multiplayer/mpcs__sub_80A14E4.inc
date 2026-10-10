.syntax unified
.text
	push {r4, lr}
	adds r1, r0, #0
	movs r2, #0
	ldr r0, [r1, #0x4c]
	ldr r3, _080A152C @ =0x00012BFF
	cmp r0, r3
	bgt _080A14FE
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [r1, #0x4c]
	cmp r0, r3
	ble _080A1506
_080A14FE:
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r1, #0x4c]
	movs r2, #1
_080A1506:
	ldr r0, [r1, #0x6c]
	ldr r3, _080A1530 @ =0x000149FF
	cmp r0, r3
	bgt _080A151A
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [r1, #0x6c]
	cmp r0, r3
	ble _080A1524
_080A151A:
	ldr r0, _080A1534 @ =0xFFFFC400
	str r0, [r1, #0x6c]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080A1524:
	cmp r2, #2
	beq _080A1538
	movs r0, #0
	b _080A153A
	.align 2, 0
_080A152C: .4byte 0x00012BFF
_080A1530: .4byte 0x000149FF
_080A1534: .4byte 0xFFFFC400
_080A1538:
	movs r0, #1
_080A153A:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
