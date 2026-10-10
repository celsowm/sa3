.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r0, _08027EFC @ =gCurTask
	ldr r4, [r0]
	ldrh r3, [r4, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r3, r0
	ldr r2, _08027F00 @ =gMultiSioStatusFlags
	ldr r0, [r2]
	movs r1, #0x20
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _08027E9A
	ldr r1, _08027F04 @ =0x030000DE
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #8
	bhi _08027E9A
	ldr r0, _08027F08 @ =sub_8027D3C
	str r0, [r4, #8]
_08027E9A:
	adds r4, r6, #0
	ldr r0, [r4]
	movs r1, #0x10
	ands r0, r1
	adds r2, r5, #0
	adds r2, #0xdd
	cmp r0, #0
	beq _08027EAE
	movs r0, #1
	strb r0, [r2]
_08027EAE:
	ldr r0, _08027F0C @ =gMultiSioSend
	ldr r1, _08027F10 @ =gLoadedSaveGame
	ldr r3, _08027F14 @ =0x00000366
	adds r1, r1, r3
	ldrb r1, [r1]
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	strb r1, [r0]
	ldr r1, _08027F18 @ =gMultiSioRecv
	ldrb r2, [r2]
	bl MultiSioMain
	str r0, [r4]
	adds r4, r5, #0
	adds r4, #0xdf
	ldrb r0, [r4]
	cmp r0, #0
	bne _08027EDA
	bl MultiSioStart
	movs r0, #1
	strb r0, [r4]
_08027EDA:
	ldr r0, [r6]
	movs r1, #0xf0
	lsls r1, r1, #4
	ands r0, r1
	lsrs r6, r0, #8
	movs r4, #1
	ldr r7, _08027F1C @ =0x00006001
_08027EE8:
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	adds r0, r5, #0
	bl sa2__sub_8081E38
	cmp r0, #0
	bne _08027F20
	bl sub_802613C
	b _08027FC8
	.align 2, 0
_08027EFC: .4byte gCurTask
_08027F00: .4byte gMultiSioStatusFlags
_08027F04: .4byte 0x030000DE
_08027F08: .4byte sub_8027D3C
_08027F0C: .4byte gMultiSioSend
_08027F10: .4byte gLoadedSaveGame
_08027F14: .4byte 0x00000366
_08027F18: .4byte gMultiSioRecv
_08027F1C: .4byte 0x00006001
_08027F20:
	asrs r1, r4, #0x10
	adds r0, r6, #0
	lsls r0, r1
	cmp r0, #0
	beq _08027FA0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _08027F80 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	bne _08027FA0
	movs r2, #0
	ldr r4, _08027F84 @ =gUnknown_03000970
	movs r3, #0
_08027F40:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r4
	strb r3, [r0]
	strb r3, [r0, #1]
	strb r2, [r0, #2]
	strb r3, [r0, #3]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08027F40
	movs r0, #0
	ldr r1, _08027F88 @ =0x0000FFFF
	bl TasksDestroyInPriorityRange
	ldr r1, _08027F8C @ =gBackgroundsCopyQueueCursor
	ldr r0, _08027F90 @ =gBackgroundsCopyQueueIndex
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _08027F94 @ =gBgSpritesCount
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08027F98 @ =gVramGraphicsCopyCursor
	ldr r0, _08027F9C @ =gVramGraphicsCopyQueueIndex
	ldrb r0, [r0]
	strb r0, [r1]
	bl sub_8028708
	b _08027FC8
	.align 2, 0
_08027F80: .4byte gMultiSioRecv
_08027F84: .4byte gUnknown_03000970
_08027F88: .4byte 0x0000FFFF
_08027F8C: .4byte gBackgroundsCopyQueueCursor
_08027F90: .4byte gBackgroundsCopyQueueIndex
_08027F94: .4byte gBgSpritesCount
_08027F98: .4byte gVramGraphicsCopyCursor
_08027F9C: .4byte gVramGraphicsCopyQueueIndex
_08027FA0:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08027EE8
	adds r0, r5, #0
	bl sa2__sub_8081E90
	adds r2, r5, #0
	adds r2, #0xde
	ldr r0, _08027FD0 @ =gMultiSioRecv
	ldrb r1, [r0, #2]
	ldrb r0, [r2]
	cmp r0, r1
	beq _08027FC4
	strb r1, [r2]
_08027FC4:
	bl sub_8028338
_08027FC8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027FD0: .4byte gMultiSioRecv

.syntax divided
