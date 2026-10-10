.syntax unified
.text
	push {r4, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, [r1, #0x5c]
	ldr r2, _080A19B0 @ =0x000077FF
	cmp r0, r2
	bgt _080A1982
	movs r4, #0xc0
	lsls r4, r4, #2
	adds r0, r0, r4
	str r0, [r1, #0x5c]
	cmp r0, r2
	ble _080A198A
_080A1982:
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r1, #0x5c]
	movs r3, #1
_080A198A:
	ldr r0, [r1, #0x64]
	movs r2, #0xf0
	lsls r2, r2, #7
	cmp r0, r2
	ble _080A199E
	ldr r4, _080A19B4 @ =0xFFFFFD00
	adds r0, r0, r4
	str r0, [r1, #0x64]
	cmp r0, r2
	bgt _080A19A6
_080A199E:
	str r2, [r1, #0x64]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080A19A6:
	cmp r3, #2
	beq _080A19B8
	movs r0, #0
	b _080A19BA
	.align 2, 0
_080A19B0: .4byte 0x000077FF
_080A19B4: .4byte 0xFFFFFD00
_080A19B8:
	movs r0, #1
_080A19BA:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
