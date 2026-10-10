.syntax unified
.text
	ldr r1, _08025D08 @ =gMultiSioSend
	ldr r0, _08025D0C @ =0x0000660B
	strh r0, [r1]
	bx lr
	.align 2, 0
_08025D08: .4byte gMultiSioSend
_08025D0C: .4byte 0x0000660B

.syntax divided
