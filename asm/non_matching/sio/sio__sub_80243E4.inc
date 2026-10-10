.syntax unified
.text
	ldr r2, _080243F0 @ =gMultiSioSend
	ldr r1, _080243F4 @ =0x00006C0B
	strh r1, [r2]
	strb r0, [r2, #7]
	bx lr
	.align 2, 0
_080243F0: .4byte gMultiSioSend
_080243F4: .4byte 0x00006C0B

.syntax divided
