.syntax unified
.text
	ldr r1, _0802432C @ =gMultiSioSend
	ldr r0, _08024330 @ =0x00006C02
	strh r0, [r1]
	bx lr
	.align 2, 0
_0802432C: .4byte gMultiSioSend
_08024330: .4byte 0x00006C02

.syntax divided
