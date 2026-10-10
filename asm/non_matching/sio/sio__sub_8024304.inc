.syntax unified
.text
	ldr r0, _08024310 @ =gMultiSioSend
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r0, #2]
	bx lr
	.align 2, 0
_08024310: .4byte gMultiSioSend

.syntax divided
