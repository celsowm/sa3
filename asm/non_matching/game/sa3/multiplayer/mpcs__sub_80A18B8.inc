.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldr r0, _080A18CC @ =0x0000B3FF
	cmp r2, r0
	ble _080A18D0
	adds r0, #1
	str r0, [r1, #0x60]
	movs r0, #1
	b _080A18DA
	.align 2, 0
_080A18CC: .4byte 0x0000B3FF
_080A18D0:
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r2, r3
	str r0, [r1, #0x60]
	movs r0, #0
_080A18DA:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
