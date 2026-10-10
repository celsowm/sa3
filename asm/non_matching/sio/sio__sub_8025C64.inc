.syntax unified
.text
	ldr r3, _08025C7C @ =gMultiSioSend
	ldr r2, _08025C80 @ =gStageData
	ldr r1, _08025C84 @ =0x04000128
	ldr r1, [r1]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1e
	strb r1, [r2, #6]
	ldr r2, _08025C88 @ =0x00006605
	strh r2, [r3]
	strb r1, [r3, #3]
	strb r0, [r3, #4]
	bx lr
	.align 2, 0
_08025C7C: .4byte gMultiSioSend
_08025C80: .4byte gStageData
_08025C84: .4byte 0x04000128
_08025C88: .4byte 0x00006605

.syntax divided
