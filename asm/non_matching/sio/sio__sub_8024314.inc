.syntax unified
.text
	ldr r1, _0802431C @ =gMultiSioSend
	ldr r0, _08024320 @ =0x00006C01
	strh r0, [r1]
	bx lr
	.align 2, 0
_0802431C: .4byte gMultiSioSend
_08024320: .4byte 0x00006C01

.syntax divided
