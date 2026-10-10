.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x54]
	movs r2, #0xf0
	lsls r2, r2, #6
	cmp r0, r2
	ble _080A1680
	ldr r3, _080A1688 @ =0xFFFFF740
	adds r0, r0, r3
	str r0, [r1, #0x54]
	cmp r0, #0x3b
	bgt _080A168C
_080A1680:
	str r2, [r1, #0x54]
	movs r0, #1
	b _080A168E
	.align 2, 0
_080A1688: .4byte 0xFFFFF740
_080A168C:
	movs r0, #0
_080A168E:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
