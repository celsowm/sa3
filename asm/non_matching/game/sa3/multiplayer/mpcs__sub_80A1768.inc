.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x4c]
	movs r3, #0x96
	lsls r3, r3, #8
	cmp r1, r3
	ble _080A1782
	ldr r0, _080A1788 @ =0xFFFFFD00
	adds r1, r1, r0
	str r1, [r2, #0x4c]
	ldr r0, _080A178C @ =0x000095FF
	cmp r1, r0
	bgt _080A1790
_080A1782:
	str r3, [r2, #0x4c]
	movs r0, #1
	b _080A1792
	.align 2, 0
_080A1788: .4byte 0xFFFFFD00
_080A178C: .4byte 0x000095FF
_080A1790:
	movs r0, #0
_080A1792:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
