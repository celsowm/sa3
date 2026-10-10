.syntax unified
.text
	ldr r1, _08025BE4 @ =gMultiSioSend
	movs r3, #0
	movs r2, #0
	ldr r0, _08025BE8 @ =0x00006603
	strh r0, [r1]
	strb r3, [r1, #3]
	strb r3, [r1, #4]
	strh r2, [r1, #6]
	str r2, [r1, #8]
	strh r2, [r1, #0xc]
	movs r0, #0xff
	strb r0, [r1, #0xf]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #0x10]
	strb r0, [r1, #0x11]
	strb r0, [r1, #0x12]
	bx lr
	.align 2, 0
_08025BE4: .4byte gMultiSioSend
_08025BE8: .4byte 0x00006603

.syntax divided
