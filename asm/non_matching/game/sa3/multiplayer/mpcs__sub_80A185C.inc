.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x74]
	movs r2, #0xc9
	lsls r2, r2, #8
	cmp r0, r2
	ble _080A1874
	ldr r3, _080A187C @ =0xFFFFFD00
	adds r0, r0, r3
	str r0, [r1, #0x74]
	cmp r0, r2
	bgt _080A1880
_080A1874:
	str r2, [r1, #0x74]
	movs r0, #1
	b _080A1882
	.align 2, 0
_080A187C: .4byte 0xFFFFFD00
_080A1880:
	movs r0, #0
_080A1882:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
