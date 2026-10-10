.syntax unified
.text
	ldr r2, _08025798 @ =gMultiSioSend
	ldr r1, _0802579C @ =gStageData
	ldr r0, _080257A0 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	strb r0, [r2, #3]
	ldr r0, _080257A4 @ =0x00006606
	strh r0, [r2]
	ldr r0, _080257A8 @ =gUnknown_03001060
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r1, [r1]
	strb r1, [r2, #0xf]
	adds r0, #0x4d
	ldrb r0, [r0]
	strb r0, [r2, #0x10]
	bx lr
	.align 2, 0
_08025798: .4byte gMultiSioSend
_0802579C: .4byte gStageData
_080257A0: .4byte 0x04000128
_080257A4: .4byte 0x00006606
_080257A8: .4byte gUnknown_03001060

.syntax divided
