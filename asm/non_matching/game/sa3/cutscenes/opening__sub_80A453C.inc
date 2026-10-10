.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	movs r0, #3
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080A456C
	ldr r1, [r2, #0x20]
	ldr r0, _080A4568 @ =0x000009FF
	cmp r1, r0
	ble _080A4590
	ldrb r0, [r2]
	lsls r0, r0, #0xb
	subs r0, r1, r0
	str r0, [r2, #0x20]
	movs r1, #0xa0
	lsls r1, r1, #4
	cmp r0, r1
	bgt _080A4590
	str r1, [r2, #0x20]
	movs r0, #1
	b _080A4592
	.align 2, 0
_080A4568: .4byte 0x000009FF
_080A456C:
	ldr r1, [r2, #0x20]
	movs r3, #0xe6
	lsls r3, r3, #8
	cmp r1, r3
	bgt _080A4590
	ldrb r0, [r2]
	lsls r0, r0, #0xb
	adds r0, r1, r0
	str r0, [r2, #0x20]
	ldr r1, _080A458C @ =0x0000E5FF
	cmp r0, r1
	ble _080A4590
	str r3, [r2, #0x20]
	movs r0, #1
	b _080A4592
	.align 2, 0
_080A458C: .4byte 0x0000E5FF
_080A4590:
	movs r0, #0
_080A4592:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
