.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x6c]
	ldr r3, _080A1850 @ =0x0000C8FF
	cmp r2, r3
	bgt _080A1844
	movs r0, #3
	lsls r0, r0, #8
	adds r0, r2, r0
	str r0, [r1, #0x6c]
	cmp r0, r3
	ble _080A1854
_080A1844:
	movs r0, #0xc9
	lsls r0, r0, #8
	str r0, [r1, #0x6c]
	movs r0, #1
	b _080A1856
	.align 2, 0
_080A1850: .4byte 0x0000C8FF
_080A1854:
	movs r0, #0
_080A1856:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
