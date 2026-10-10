.syntax unified
.text
	push {lr}
	ldr r0, _080A14A8 @ =gCurTask
	ldr r0, [r0]
	bl TaskDestroy
	pop {r0}
	bx r0
	.align 2, 0
_080A14A8: .4byte gCurTask

.syntax divided
