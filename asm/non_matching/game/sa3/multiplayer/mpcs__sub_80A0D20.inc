.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A0D3C @ =gCurTask
	ldr r2, [r0]
	ldrh r0, [r2, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	ldr r0, [r0, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0D44
	ldr r0, _080A0D40 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A0DA0
	.align 2, 0
_080A0D3C: .4byte gCurTask
_080A0D40: .4byte Task_80A14AC
_080A0D44:
	movs r4, #0
	ldr r0, _080A0DA8 @ =gPlayers
	mov ip, r0
	ldr r6, _080A0DAC @ =gUnknown_030010AC
	movs r7, #0x10
	rsbs r7, r7, #0
	movs r5, #0xf
_080A0D52:
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	add r1, ip
	adds r0, r4, r6
	ldrb r0, [r0]
	adds r1, #0x2a
	adds r2, r5, #0
	ands r2, r0
	ldrb r3, [r1]
	adds r0, r7, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _080A0D52
	ldr r1, _080A0DB0 @ =0x0000FFFF
	movs r0, #0
	bl TasksDestroyInPriorityRange
	ldr r1, _080A0DB4 @ =gBackgroundsCopyQueueCursor
	ldr r0, _080A0DB8 @ =gBackgroundsCopyQueueIndex
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _080A0DBC @ =gBgSpritesCount
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080A0DC0 @ =gVramGraphicsCopyCursor
	ldr r0, _080A0DC4 @ =gVramGraphicsCopyQueueIndex
	ldrb r0, [r0]
	strb r0, [r1]
	movs r0, #0
	bl sub_809BFE8
_080A0DA0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0DA8: .4byte gPlayers
_080A0DAC: .4byte gUnknown_030010AC
_080A0DB0: .4byte 0x0000FFFF
_080A0DB4: .4byte gBackgroundsCopyQueueCursor
_080A0DB8: .4byte gBackgroundsCopyQueueIndex
_080A0DBC: .4byte gBgSpritesCount
_080A0DC0: .4byte gVramGraphicsCopyCursor
_080A0DC4: .4byte gVramGraphicsCopyQueueIndex

.syntax divided
