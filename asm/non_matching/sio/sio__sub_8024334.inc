.syntax unified
.text
	ldr r1, _0802434C @ =gMultiSioSend
	movs r2, #0
	ldr r0, _08024350 @ =0x00006C03
	strh r0, [r1]
	strb r2, [r1, #4]
	strb r2, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #5]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #6]
	bx lr
	.align 2, 0
_0802434C: .4byte gMultiSioSend
_08024350: .4byte 0x00006C03

.syntax divided
