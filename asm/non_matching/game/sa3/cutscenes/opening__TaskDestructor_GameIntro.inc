.syntax unified
.text
	push {r4, lr}
	ldrh r4, [r0, #6]
	ldr r1, _080A2D28 @ =0x0300012C
	adds r0, r4, r1
	ldr r0, [r0]
	bl EwramFree
	ldr r0, _080A2D2C @ =0x03000130
	adds r4, r4, r0
	ldr r0, [r4]
	bl EwramFree
	ldr r2, _080A2D30 @ =gFlags
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D28: .4byte 0x0300012C
_080A2D2C: .4byte 0x03000130
_080A2D30: .4byte gFlags

.syntax divided
