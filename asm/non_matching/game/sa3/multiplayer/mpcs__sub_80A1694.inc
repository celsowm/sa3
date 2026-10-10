.syntax unified
.text
	push {r4, lr}
	adds r1, r0, #0
	movs r2, #0
	ldr r0, [r1, #0x4c]
	ldr r3, _080A16E0 @ =0x00012BFF
	cmp r0, r3
	bgt _080A16AE
	movs r4, #0x8c
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [r1, #0x4c]
	cmp r0, r3
	ble _080A16B6
_080A16AE:
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r1, #0x4c]
	movs r2, #1
_080A16B6:
	ldr r0, [r1, #0x6c]
	ldr r3, _080A16E0 @ =0x00012BFF
	cmp r0, r3
	bgt _080A16CA
	movs r4, #0x84
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [r1, #0x6c]
	cmp r0, r3
	ble _080A16D6
_080A16CA:
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r1, #0x6c]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080A16D6:
	cmp r2, #2
	beq _080A16E4
	movs r0, #0
	b _080A16E6
	.align 2, 0
_080A16E0: .4byte 0x00012BFF
_080A16E4:
	movs r0, #1
_080A16E6:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
