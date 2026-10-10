.syntax unified
.text
	push {r4, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, [r1, #0x4c]
	movs r2, #0xb4
	lsls r2, r2, #8
	cmp r0, r2
	ble _080A1706
	ldr r4, _080A1730 @ =0xFFFFF740
	adds r0, r0, r4
	str r0, [r1, #0x4c]
	cmp r0, r2
	bgt _080A170A
_080A1706:
	str r2, [r1, #0x4c]
	movs r3, #1
_080A170A:
	ldr r0, [r1, #0x6c]
	movs r2, #0xb4
	lsls r2, r2, #8
	cmp r0, r2
	ble _080A171E
	ldr r4, _080A1734 @ =0xFFFFF7C0
	adds r0, r0, r4
	str r0, [r1, #0x6c]
	cmp r0, r2
	bgt _080A1726
_080A171E:
	str r2, [r1, #0x6c]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080A1726:
	cmp r3, #2
	beq _080A1738
	movs r0, #0
	b _080A173A
	.align 2, 0
_080A1730: .4byte 0xFFFFF740
_080A1734: .4byte 0xFFFFF7C0
_080A1738:
	movs r0, #1
_080A173A:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
