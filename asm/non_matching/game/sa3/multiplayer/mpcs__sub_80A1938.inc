.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x68]
	ldr r2, _080A195C @ =0x0000B3FF
	cmp r0, r2
	bgt _080A1950
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r0, r3
	str r0, [r1, #0x68]
	cmp r0, r2
	ble _080A1960
_080A1950:
	movs r0, #0xb4
	lsls r0, r0, #8
	str r0, [r1, #0x68]
	movs r0, #1
	b _080A1962
	.align 2, 0
_080A195C: .4byte 0x0000B3FF
_080A1960:
	movs r0, #0
_080A1962:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
