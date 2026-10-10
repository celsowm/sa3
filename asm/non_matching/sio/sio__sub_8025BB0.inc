.syntax unified
.text
	ldr r1, _08025BB8 @ =gMultiSioSend
	ldr r0, _08025BBC @ =0x00006602
	strh r0, [r1]
	bx lr
	.align 2, 0
_08025BB8: .4byte gMultiSioSend
_08025BBC: .4byte 0x00006602

.syntax divided
