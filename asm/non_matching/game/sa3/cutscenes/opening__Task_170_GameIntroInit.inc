.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r0, _080A2654 @ =gCurTask
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r6, r4, r0
	mov r5, sp
	mov r0, sp
	movs r1, #0
	movs r2, #0x10
	bl memset
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5]
	strh r0, [r5, #6]
	ldr r1, _080A2658 @ =gDispCnt
	movs r0, #0x42
	strh r0, [r1]
	adds r0, r6, #0
	bl sub_80A217C
	adds r0, r6, #0
	bl sub_80A22E0
	movs r0, #0xa0
	lsls r0, r0, #4
	bl EwramMalloc
	ldr r1, _080A265C @ =0x0300012C
	adds r4, r4, r1
	str r0, [r4]
	adds r4, r0, #0
	movs r5, #0
_080A257C:
	mov r0, sp
	adds r1, r4, #0
	movs r2, #8
	bl CpuSet
	lsls r0, r5, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	adds r4, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _080A257C
	movs r0, #0x80
	lsls r0, r0, #3
	bl EwramMalloc
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	movs r5, #0
_080A25AA:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	lsls r5, r4, #2
	adds r5, r5, r0
	lsls r1, r4, #4
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #0x80
	lsls r0, r0, #0xd
	bl __divsi3
	str r0, [r5]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0xff
	ble _080A25AA
	movs r5, #0
	ldr r4, _080A2660 @ =gBgPalette
_080A25DC:
	movs r0, #0
	bl sub_80C4C0C
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	adds r1, r2, #0
	adds r1, #0x50
	lsls r1, r1, #1
	adds r1, r1, r4
	strh r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xf
	ble _080A25DC
	ldr r2, _080A2664 @ =gFlags
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A2668 @ =gBldRegs
	movs r2, #0
	ldr r0, _080A266C @ =0x00001D42
	strh r0, [r1]
	ldr r0, _080A2670 @ =0x00001010
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	movs r5, #0
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r3, #0
_080A2626:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r2, r0
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xf
	ble _080A2626
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bhi _080A26EE
	lsls r0, r0, #2
	ldr r1, _080A2674 @ =_080A2678
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A2654: .4byte gCurTask
_080A2658: .4byte gDispCnt
_080A265C: .4byte 0x0300012C
_080A2660: .4byte gBgPalette
_080A2664: .4byte gFlags
_080A2668: .4byte gBldRegs
_080A266C: .4byte 0x00001D42
_080A2670: .4byte 0x00001010
_080A2674: .4byte _080A2678
_080A2678: @ jump table
	.4byte _080A2690 @ case 0
	.4byte _080A26A0 @ case 1
	.4byte _080A26AA @ case 2
	.4byte _080A26C4 @ case 3
	.4byte _080A26CC @ case 4
	.4byte _080A26DC @ case 5
_080A2690:
	ldr r0, _080A2698 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A269C @ =Task_170_80A2A9C
	b _080A26EC
	.align 2, 0
_080A2698: .4byte gCurTask
_080A269C: .4byte Task_170_80A2A9C
_080A26A0:
	bl m4aMPlayAllStop
	movs r0, #0         @ MUS_INTRO
	bl m4aSongNumStart
_080A26AA:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080A26BC @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A26C0 @ =Task_170_80A2A9C
	b _080A26EC
	.align 2, 0
_080A26BC: .4byte gCurTask
_080A26C0: .4byte Task_170_80A2A9C
_080A26C4:
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r1, r6, r2
	b _080A26E2
_080A26CC:
	ldr r0, _080A26D4 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A26D8 @ =Task_170_80A2A9C
	b _080A26EC
	.align 2, 0
_080A26D4: .4byte gCurTask
_080A26D8: .4byte Task_170_80A2A9C
_080A26DC:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r1, r6, r0
_080A26E2:
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080A26F8 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A26FC @ =sub_80A2700
_080A26EC:
	str r0, [r1, #8]
_080A26EE:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A26F8: .4byte gCurTask
_080A26FC: .4byte sub_80A2700

.syntax divided
