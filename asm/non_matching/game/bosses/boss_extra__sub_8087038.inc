.syntax unified
.text
	adds r0, #0xef
	strb r1, [r0]
	bx lr
	.align 2, 0

.syntax divided
