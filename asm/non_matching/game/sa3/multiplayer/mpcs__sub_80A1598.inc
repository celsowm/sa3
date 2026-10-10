.syntax unified
.text
	push {r4, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, [r1, #0x4c]
	movs r2, #0xf0
	lsls r2, r2, #7
	cmp r0, r2
	ble _080A15B2
	ldr r4, _080A15DC @ =0xFFFFF200
	adds r0, r0, r4
	str r0, [r1, #0x4c]
	cmp r0, r2
	bgt _080A15B6
_080A15B2:
	str r2, [r1, #0x4c]
	movs r3, #1
_080A15B6:
	movs r0, #0x78
	lsls r2, r0, #8
	ldr r0, [r1, #0x6c]
	cmp r0, r2
	ble _080A15CA
	ldr r4, _080A15DC @ =0xFFFFF200
	adds r0, r0, r4
	str r0, [r1, #0x6c]
	cmp r0, r2
	bgt _080A15D2
_080A15CA:
	str r2, [r1, #0x6c]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080A15D2:
	cmp r3, #2
	beq _080A15E0
	movs r0, #0
	b _080A15E2
	.align 2, 0
_080A15DC: .4byte 0xFFFFF200
_080A15E0:
	movs r0, #1
_080A15E2:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
