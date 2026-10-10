.syntax unified
.text
	ldr r2, _08025D40 @ =gMultiSioSend
	ldr r1, _08025D44 @ =0x0000660E
	strh r1, [r2]
	strb r0, [r2, #5]
	bx lr
	.align 2, 0
_08025D40: .4byte gMultiSioSend
_08025D44: .4byte 0x0000660E

.syntax divided
