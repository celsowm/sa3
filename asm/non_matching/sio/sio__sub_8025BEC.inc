.syntax unified
.text
	ldr r3, _08025C10 @ =gMultiSioSend
	ldr r2, _08025C14 @ =gStageData
	ldr r1, _08025C18 @ =0x04000128
	ldr r1, [r1]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1e
	strb r1, [r2, #6]
	ldr r2, _08025C1C @ =0x00006603
	strh r2, [r3]
	strb r1, [r3, #3]
	adds r2, r3, #0
	adds r2, #0xf
	adds r1, r1, r2
	movs r2, #0xff
	strb r2, [r1]
	strb r0, [r3, #4]
	bx lr
	.align 2, 0
_08025C10: .4byte gMultiSioSend
_08025C14: .4byte gStageData
_08025C18: .4byte 0x04000128
_08025C1C: .4byte 0x00006603

.syntax divided
