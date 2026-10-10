.syntax unified
.text
	ldr r1, _08025D18 @ =gMultiSioSend
	ldr r0, _08025D1C @ =0x0000660C
	strh r0, [r1]
	bx lr
	.align 2, 0
_08025D18: .4byte gMultiSioSend
_08025D1C: .4byte 0x0000660C

.syntax divided
