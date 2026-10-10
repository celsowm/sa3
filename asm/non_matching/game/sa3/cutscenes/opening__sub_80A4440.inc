.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	movs r0, #3
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080A4470
	ldr r1, [r2, #0x18]
	movs r3, #0xf0
	lsls r3, r3, #8
	cmp r1, r3
	bgt _080A448C
	ldrb r0, [r2]
	lsls r0, r0, #5
	adds r0, r1, r0
	str r0, [r2, #0x18]
	ldr r1, _080A446C @ =0x0000EFFF
	cmp r0, r1
	ble _080A448C
	str r3, [r2, #0x18]
	movs r0, #1
	b _080A448E
	.align 2, 0
_080A446C: .4byte 0x0000EFFF
_080A4470:
	ldr r1, [r2, #0x18]
	cmp r1, #0xff
	ble _080A448C
	ldrb r0, [r2]
	lsls r0, r0, #5
	subs r0, r1, r0
	str r0, [r2, #0x18]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _080A448C
	str r1, [r2, #0x18]
	movs r0, #1
	b _080A448E
_080A448C:
	movs r0, #0
_080A448E:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
