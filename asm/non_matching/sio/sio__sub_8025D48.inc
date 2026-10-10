.syntax unified
.text
	ldr r1, _08025D50 @ =gMultiSioSend
	ldr r0, _08025D54 @ =0x0000660F
	strh r0, [r1]
	bx lr
	.align 2, 0
_08025D50: .4byte gMultiSioSend
_08025D54: .4byte 0x0000660F

.syntax divided
