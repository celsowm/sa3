.syntax unified
.text
	ldr r1, _08025BA8 @ =gMultiSioSend
	ldr r0, _08025BAC @ =0x00006601
	strh r0, [r1]
	bx lr
	.align 2, 0
_08025BA8: .4byte gMultiSioSend
_08025BAC: .4byte 0x00006601

.syntax divided
