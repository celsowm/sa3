.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x44]
	ldr r0, _080A18F4 @ =0x000004FF
	cmp r2, r0
	bgt _080A18F8
	adds r0, r2, #0
	adds r0, #0x40
	b _080A18FA
	.align 2, 0
_080A18F4: .4byte 0x000004FF
_080A18F8:
	movs r0, #0
_080A18FA:
	str r0, [r1, #0x44]
	movs r0, #0xb4
	lsls r0, r0, #7
	str r0, [r1, #0x48]
	movs r0, #1
	pop {r1}
	bx r1

.syntax divided
