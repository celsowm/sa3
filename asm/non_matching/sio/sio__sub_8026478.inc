.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r2, _080264C4 @ =gStageData
	ldrb r0, [r2, #4]
	adds r6, r2, #0
	cmp r0, #2
	bne _080264E2
	ldrb r0, [r2, #6]
	cmp r0, #0
	bne _080264D4
	movs r1, #1
	ldr r0, _080264C8 @ =gUnknown_03001060
	ldrb r3, [r0, #7]
	ldr r5, _080264CC @ =0x00006802
	movs r4, #1
_08026494:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r3, #0
	asrs r0, r2
	ands r0, r4
	cmp r0, #0
	beq _080264B2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _080264D0 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	bne _080264E2
_080264B2:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08026494
	movs r0, #3
	strb r0, [r6, #4]
	b _080264E2
	.align 2, 0
_080264C4: .4byte gStageData
_080264C8: .4byte gUnknown_03001060
_080264CC: .4byte 0x00006802
_080264D0: .4byte gMultiSioRecv
_080264D4:
	ldr r0, _080264E8 @ =gMultiSioRecv
	ldrh r1, [r0]
	ldr r0, _080264EC @ =0x00006810
	cmp r1, r0
	bne _080264E2
	movs r0, #3
	strb r0, [r2, #4]
_080264E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080264E8: .4byte gMultiSioRecv
_080264EC: .4byte 0x00006810

.syntax divided
