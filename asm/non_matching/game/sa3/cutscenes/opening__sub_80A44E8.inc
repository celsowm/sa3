.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	movs r0, #3
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080A4510
	ldr r1, [r2, #0x20]
	ldr r3, _080A450C @ =0xFFFF3800
	cmp r1, r3
	blt _080A4534
	ldrb r0, [r2]
	lsls r0, r0, #0xb
	subs r0, r1, r0
	str r0, [r2, #0x20]
	cmp r0, r3
	bgt _080A4534
	b _080A4528
	.align 2, 0
_080A450C: .4byte 0xFFFF3800
_080A4510:
	ldr r1, [r2, #0x20]
	movs r3, #0xdc
	lsls r3, r3, #9
	cmp r1, r3
	bgt _080A4534
	ldrb r0, [r2]
	lsls r0, r0, #0xb
	adds r0, r1, r0
	str r0, [r2, #0x20]
	ldr r1, _080A4530 @ =0x0001B7FF
	cmp r0, r1
	ble _080A4534
_080A4528:
	str r3, [r2, #0x20]
	movs r0, #1
	b _080A4536
	.align 2, 0
_080A4530: .4byte 0x0001B7FF
_080A4534:
	movs r0, #0
_080A4536:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
