.syntax unified
.text
	ldr r1, _080243BC @ =gMultiSioSend
	ldr r0, _080243C0 @ =0x00006C0A
	strh r0, [r1]
	bx lr
	.align 2, 0
_080243BC: .4byte gMultiSioSend
_080243C0: .4byte 0x00006C0A

.syntax divided
