.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x6c]
	movs r3, #0xb4
	lsls r3, r3, #8
	cmp r1, r3
	ble _080A1816
	ldr r0, _080A181C @ =0xFFFFF7C0
	adds r1, r1, r0
	str r1, [r2, #0x6c]
	ldr r0, _080A1820 @ =0x0000B3FF
	cmp r1, r0
	bgt _080A1824
_080A1816:
	str r3, [r2, #0x6c]
	movs r0, #1
	b _080A1826
	.align 2, 0
_080A181C: .4byte 0xFFFFF7C0
_080A1820: .4byte 0x0000B3FF
_080A1824:
	movs r0, #0
_080A1826:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
