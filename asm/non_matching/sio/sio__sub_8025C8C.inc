.syntax unified
.text
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, _08025CC4 @ =gMultiSioSend
	ldr r1, _08025CC8 @ =gStageData
	ldr r0, _08025CCC @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r2, r0, #0
	cmp r2, #1
	bhi _08025CB6
	ldr r0, _08025CD0 @ =gUnknown_03001060
	ldrb r1, [r0, #7]
	movs r0, #4
	lsls r0, r2
	ands r1, r0
	cmp r1, #0
	bne _08025CB6
	adds r2, #2
_08025CB6:
	ldr r0, _08025CD4 @ =0x00006605
	strh r0, [r3]
	strb r2, [r3, #3]
	strb r4, [r3, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08025CC4: .4byte gMultiSioSend
_08025CC8: .4byte gStageData
_08025CCC: .4byte 0x04000128
_08025CD0: .4byte gUnknown_03001060
_08025CD4: .4byte 0x00006605

.syntax divided
