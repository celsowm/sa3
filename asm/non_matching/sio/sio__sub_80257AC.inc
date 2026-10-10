.syntax unified
.text
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r3, _080257F4 @ =gMultiSioSend
	ldr r1, _080257F8 @ =gStageData
	ldr r0, _080257FC @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	movs r4, #0xff
	adds r2, r0, #0
	ldr r0, _08025800 @ =gUnknown_03001060
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r1, [r1]
	strb r1, [r3, #0xf]
	adds r0, #0x4d
	ldrb r0, [r0]
	strb r0, [r3, #0x10]
	cmp r2, #1
	bhi _080257DA
	adds r2, #2
_080257DA:
	adds r0, r3, #0
	adds r0, #0xf
	adds r0, r2, r0
	ldrb r1, [r0]
	orrs r1, r4
	strb r1, [r0]
	ldr r0, _08025804 @ =0x00006607
	strh r0, [r3]
	strb r2, [r3, #3]
	strb r5, [r3, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080257F4: .4byte gMultiSioSend
_080257F8: .4byte gStageData
_080257FC: .4byte 0x04000128
_08025800: .4byte gUnknown_03001060
_08025804: .4byte 0x00006607

.syntax divided
