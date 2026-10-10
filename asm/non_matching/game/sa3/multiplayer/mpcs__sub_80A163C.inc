.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x4c]
	movs r2, #0xb4
	lsls r2, r2, #8
	cmp r0, r2
	ble _080A1654
	ldr r3, _080A165C @ =0xFFFFF740
	adds r0, r0, r3
	str r0, [r1, #0x4c]
	cmp r0, #0xb3
	bgt _080A1660
_080A1654:
	str r2, [r1, #0x4c]
	movs r0, #1
	b _080A1662
	.align 2, 0
_080A165C: .4byte 0xFFFFF740
_080A1660:
	movs r0, #0
_080A1662:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
