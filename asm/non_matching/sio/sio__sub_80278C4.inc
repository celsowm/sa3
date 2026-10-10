.syntax unified
.text
	ldr r2, _080278D4 @ =gMultiSioSend
	ldr r0, _080278D8 @ =gStageData
	ldrb r1, [r0, #5]
	strb r1, [r2, #0x12]
	adds r0, #0xae
	ldrh r0, [r0]
	strh r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080278D4: .4byte gMultiSioSend
_080278D8: .4byte gStageData

.syntax divided
