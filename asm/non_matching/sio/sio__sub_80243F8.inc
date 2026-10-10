.syntax unified
.text
	ldr r2, _08024404 @ =gMultiSioSend
	ldr r1, _08024408 @ =0x00006C0C
	strh r1, [r2]
	strb r0, [r2, #7]
	bx lr
	.align 2, 0
_08024404: .4byte gMultiSioSend
_08024408: .4byte 0x00006C0C

.syntax divided
