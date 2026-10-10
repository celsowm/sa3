.syntax unified
.text
	push {lr}
	ldr r1, _08026108 @ =gMultiSioEnabled
	movs r0, #0
	strb r0, [r1]
	bl MultiSioStop
	movs r0, #0
	bl MultiSioInit
	pop {r0}
	bx r0
	.align 2, 0
_08026108: .4byte gMultiSioEnabled

.syntax divided
