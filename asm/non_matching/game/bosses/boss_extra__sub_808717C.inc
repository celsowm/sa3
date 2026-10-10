.syntax unified
.text
	ldr r1, [r0, #0x34]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x34]
	bx lr
	.align 2, 0

.syntax divided
