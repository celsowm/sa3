.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x20]
	ldr r0, _080A3E84 @ =0x00006FFF
	cmp r1, r0
	ble _080A3E88
	subs r1, #0x80
	ldrb r0, [r2, #1]
	lsls r0, r0, #7
	subs r1, r1, r0
	str r1, [r2, #0x20]
	movs r0, #0xe0
	lsls r0, r0, #7
	cmp r1, r0
	bgt _080A3E88
	str r0, [r2, #0x20]
	movs r0, #1
	b _080A3E8A
	.align 2, 0
_080A3E84: .4byte 0x00006FFF
_080A3E88:
	movs r0, #0
_080A3E8A:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
