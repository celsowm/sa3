.syntax unified
.text
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, [r2, #0x4c]
	ldr r1, _080A1630 @ =0x000077FF
	cmp r0, r1
	bgt _080A1602
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [r2, #0x4c]
	cmp r0, r1
	ble _080A160A
_080A1602:
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r2, #0x4c]
	movs r3, #1
_080A160A:
	movs r0, #0x78
	lsls r1, r0, #8
	ldr r0, [r2, #0x6c]
	cmp r0, r1
	bge _080A1620
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [r2, #0x6c]
	cmp r0, r1
	blt _080A1628
_080A1620:
	str r1, [r2, #0x6c]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080A1628:
	cmp r3, #2
	beq _080A1634
	movs r0, #0
	b _080A1636
	.align 2, 0
_080A1630: .4byte 0x000077FF
_080A1634:
	movs r0, #1
_080A1636:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
