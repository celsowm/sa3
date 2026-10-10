.syntax unified
.text
	push {lr}
	ldr r1, _080287C8 @ =gUnknown_03001060
	movs r0, #0
	strb r0, [r1, #7]
	bl sub_80287CC
	pop {r0}
	bx r0
	.align 2, 0
_080287C8: .4byte gUnknown_03001060

.syntax divided
