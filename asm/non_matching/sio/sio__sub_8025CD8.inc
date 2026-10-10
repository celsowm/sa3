.syntax unified
.text
	ldr r2, _08025CF0 @ =gMultiSioSend
	ldr r1, _08025CF4 @ =gStageData
	ldr r0, _08025CF8 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	strb r0, [r2, #3]
	ldr r0, _08025CFC @ =0x0000660A
	strh r0, [r2]
	bx lr
	.align 2, 0
_08025CF0: .4byte gMultiSioSend
_08025CF4: .4byte gStageData
_08025CF8: .4byte 0x04000128
_08025CFC: .4byte 0x0000660A

.syntax divided
