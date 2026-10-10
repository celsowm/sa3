.syntax unified
.text
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r3, _08025748 @ =gMultiSioSend
	ldr r1, _0802574C @ =gStageData
	ldr r0, _08025750 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	movs r4, #0xff
	adds r2, r0, #0
	ldr r0, _08025754 @ =0x00006604
	strh r0, [r3]
	strb r2, [r3, #3]
	cmp r2, #1
	bhi _0802575C
	adds r0, r3, #0
	adds r0, #0xf
	adds r0, r2, r0
	ldr r1, _08025758 @ =gUnknown_03001060
	adds r1, #0x4c
	adds r1, r2, r1
	ldrb r1, [r1]
	strb r1, [r0]
	b _08025768
	.align 2, 0
_08025748: .4byte gMultiSioSend
_0802574C: .4byte gStageData
_08025750: .4byte 0x04000128
_08025754: .4byte 0x00006604
_08025758: .4byte gUnknown_03001060
_0802575C:
	adds r1, r3, #0
	adds r1, #0xf
	adds r1, r2, r1
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
_08025768:
	strb r5, [r3, #4]
	pop {r4, r5}
	pop {r0}
	bx r0

.syntax divided
