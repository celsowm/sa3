.syntax unified
.text
	push {r4, lr}
	ldr r4, _08025C50 @ =gMultiSioSend
	ldr r3, _08025C54 @ =gStageData
	ldr r1, _08025C58 @ =0x04000128
	ldr r2, [r1]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1e
	strb r2, [r3, #6]
	ldr r1, _08025C5C @ =0x00006603
	strh r1, [r4]
	strb r2, [r4, #3]
	adds r3, r4, #0
	adds r3, #0xf
	adds r3, r2, r3
	ldr r1, _08025C60 @ =gUnknown_03001060
	adds r1, #0x4c
	adds r2, r2, r1
	ldrb r1, [r2]
	strb r1, [r3]
	strb r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08025C50: .4byte gMultiSioSend
_08025C54: .4byte gStageData
_08025C58: .4byte 0x04000128
_08025C5C: .4byte 0x00006603
_08025C60: .4byte gUnknown_03001060

.syntax divided
