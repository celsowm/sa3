.syntax unified
.text
	push {lr}
	ldr r0, _08026188 @ =sub_8025EEC
	movs r1, #0
	bl sub_8001D58
	pop {r0}
	bx r0
	.align 2, 0
_08026188: .4byte sub_8025EEC

.syntax divided
