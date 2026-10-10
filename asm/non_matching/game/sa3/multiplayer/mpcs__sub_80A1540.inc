.syntax unified
.text
	push {r4, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, [r1, #0x4c]
	ldr r2, _080A1584 @ =0xFFFFC400
	cmp r0, r2
	ble _080A1558
	ldr r4, _080A1588 @ =0xFFFFF200
	adds r0, r0, r4
	str r0, [r1, #0x4c]
	cmp r0, r2
	bgt _080A155C
_080A1558:
	str r2, [r1, #0x4c]
	movs r3, #1
_080A155C:
	ldr r0, [r1, #0x6c]
	ldr r2, _080A158C @ =0xFFFFA600
	cmp r0, r2
	ble _080A156E
	ldr r4, _080A1588 @ =0xFFFFF200
	adds r0, r0, r4
	str r0, [r1, #0x6c]
	cmp r0, r2
	bgt _080A157A
_080A156E:
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r1, #0x6c]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080A157A:
	cmp r3, #2
	beq _080A1590
	movs r0, #0
	b _080A1592
	.align 2, 0
_080A1584: .4byte 0xFFFFC400
_080A1588: .4byte 0xFFFFF200
_080A158C: .4byte 0xFFFFA600
_080A1590:
	movs r0, #1
_080A1592:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
