.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #4]
	cmp r0, #0xe
	bls _080A4438
	movs r0, #3
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080A4414
	ldr r1, [r2, #0x18]
	movs r3, #0x96
	lsls r3, r3, #8
	cmp r1, r3
	bgt _080A4438
	ldrb r0, [r2]
	lsls r0, r0, #9
	adds r0, r1, r0
	str r0, [r2, #0x18]
	ldr r1, _080A4410 @ =0x000095FF
	cmp r0, r1
	ble _080A4438
	str r3, [r2, #0x18]
	movs r0, #1
	b _080A443A
	.align 2, 0
_080A4410: .4byte 0x000095FF
_080A4414:
	ldr r1, [r2, #0x18]
	ldr r0, _080A4434 @ =0x000059FF
	cmp r1, r0
	ble _080A4438
	ldrb r0, [r2]
	lsls r0, r0, #9
	subs r0, r1, r0
	str r0, [r2, #0x18]
	movs r1, #0xb4
	lsls r1, r1, #7
	cmp r0, r1
	bgt _080A4438
	str r1, [r2, #0x18]
	movs r0, #1
	b _080A443A
	.align 2, 0
_080A4434: .4byte 0x000059FF
_080A4438:
	movs r0, #0
_080A443A:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
