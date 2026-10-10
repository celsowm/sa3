.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r1, _080279E8 @ =gDispCnt
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _080279EC @ =gBgScrollRegs
	movs r0, #0
	mov r8, r0
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	str r0, [sp, #4]
	ldr r2, _080279F0 @ =0x040000D4
	add r1, sp, #4
	str r1, [r2]
	ldr r0, _080279F4 @ =gBgCntRegs
	ldrh r1, [r0, #4]
	movs r0, #0xc
	ands r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _080279F8 @ =0x85000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r3, _080279FC @ =gBgSprites_Unknown1
	mov r2, r8
	strb r2, [r3, #2]
	ldr r0, _08027A00 @ =gBgSprites_Unknown2
	strb r2, [r0, #8]
	strb r2, [r0, #9]
	movs r1, #0xff
	strb r1, [r0, #0xa]
	movs r2, #0x40
	strb r2, [r0, #0xb]
	mov r1, r8
	strb r1, [r3, #1]
	strb r1, [r0, #4]
	strb r1, [r0, #5]
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0, #6]
	strb r2, [r0, #7]
	mov r1, r8
	strb r1, [r3]
	strb r1, [r0]
	strb r1, [r0, #1]
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0, #2]
	strb r2, [r0, #3]
	bl sub_8025D58
	lsls r0, r0, #0x10
	asrs r7, r0, #0x10
	cmp r7, #0
	beq _08027A04
	bl sub_802613C
	b _08027AA4
	.align 2, 0
_080279E8: .4byte gDispCnt
_080279EC: .4byte gBgScrollRegs
_080279F0: .4byte 0x040000D4
_080279F4: .4byte gBgCntRegs
_080279F8: .4byte 0x85000010
_080279FC: .4byte gBgSprites_Unknown1
_08027A00: .4byte gBgSprites_Unknown2
_08027A04:
	ldr r0, _08027AB0 @ =gLoadedSaveGame
	ldr r2, _08027AB4 @ =0x00000366
	adds r0, r0, r2
	ldrb r5, [r0]
	ldr r0, _08027AB8 @ =Task_F4_80283CC
	movs r2, #0x80
	lsls r2, r2, #5
	str r7, [sp]
	movs r1, #0xf4
	movs r3, #0
	bl TaskCreate
	ldrh r2, [r0, #6]
	movs r4, #0xc0
	lsls r4, r4, #0x12
	adds r4, r2, r4
	ldr r1, _08027ABC @ =0x030000F0
	adds r0, r2, r1
	strh r7, [r0]
	subs r1, #0x14
	adds r0, r2, r1
	mov r1, r8
	strb r1, [r0]
	ldr r1, _08027AC0 @ =0x030000DD
	adds r0, r2, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, _08027AC4 @ =0x030000E0
	adds r6, r2, r0
	ldr r1, _08027AC8 @ =gUnknown_080CEED8
	lsls r5, r5, #3
	adds r0, r5, r1
	ldr r3, [r0]
	str r3, [r6]
	ldr r0, _08027ACC @ =0x030000E4
	adds r6, r2, r0
	adds r1, #4
	adds r5, r5, r1
	ldr r0, [r5]
	subs r0, r0, r3
	str r0, [r6]
	ldr r1, _08027AD0 @ =0x030000E8
	adds r0, r2, r1
	str r7, [r0]
	ldr r0, _08027AD4 @ =0x030000EC
	adds r2, r2, r0
	str r7, [r2]
	movs r0, #0x44      @ MUS_VS_MUSIC_1
	bl m4aSongNumStart
	adds r0, r4, #0
	bl sub_80280AC
	adds r0, r4, #0
	bl sub_8027FD4
	strh r7, [r4]
	movs r0, #2
	strh r0, [r4, #2]
	strh r7, [r4, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r4, #6]
	movs r0, #0xff
	strh r0, [r4, #8]
	strh r7, [r4, #0xa]
	adds r0, r4, #0
	bl ScreenFadeUpdateValues
	movs r0, #0xa0
	lsls r0, r0, #0x13
	strh r7, [r0]
	ldr r0, _08027AD8 @ =gUnknown_03001060
	mov r1, r8
	strb r1, [r0, #3]
	strb r1, [r0, #2]
	strb r1, [r0, #1]
	strb r1, [r0]
	bl sub_80C6168
_08027AA4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027AB0: .4byte gLoadedSaveGame
_08027AB4: .4byte 0x00000366
_08027AB8: .4byte Task_F4_80283CC
_08027ABC: .4byte 0x030000F0
_08027AC0: .4byte 0x030000DD
_08027AC4: .4byte 0x030000E0
_08027AC8: .4byte gUnknown_080CEED8
_08027ACC: .4byte 0x030000E4
_08027AD0: .4byte 0x030000E8
_08027AD4: .4byte 0x030000EC
_08027AD8: .4byte gUnknown_03001060

.syntax divided
