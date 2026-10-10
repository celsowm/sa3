.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _08027B24 @ =gCurTask
	ldr r0, [r6]
	ldrh r5, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r5, r0
	ldr r0, _08027B28 @ =gUnknown_03001060
	movs r4, #0
	strb r4, [r0, #3]
	strb r4, [r0, #2]
	strb r4, [r0, #1]
	strb r4, [r0]
	ldr r0, _08027B2C @ =gMultiSioEnabled
	strb r4, [r0]
	bl sub_80260F0
	strh r4, [r5]
	movs r0, #1
	strh r0, [r5, #2]
	strh r4, [r5, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r5, #6]
	movs r0, #0xff
	strh r0, [r5, #8]
	strh r4, [r5, #0xa]
	adds r0, r5, #0
	bl ScreenFadeUpdateValues
	ldr r1, [r6]
	ldr r0, _08027B30 @ =Task_F4_8028418
	str r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08027B24: .4byte gCurTask
_08027B28: .4byte gUnknown_03001060
_08027B2C: .4byte gMultiSioEnabled
_08027B30: .4byte Task_F4_8028418

.syntax divided
