.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _080A3FB4 @ =gDispCnt
	movs r2, #0x82
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080A3FB8 @ =Task_94_B_80A40A0
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r1, _080A3FBC @ =TaskDestructor_94_B_80A43DC
	str r1, [sp]
	movs r1, #0x94
	movs r3, #0
	bl TaskCreate
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r4, r0
	movs r1, #0xa0
	lsls r1, r1, #7
	str r1, [r4, #0x14]
	movs r2, #0
	str r2, [r4, #0xc]
	ldr r0, _080A3FC0 @ =0xFFFF8800
	str r0, [r4, #0x18]
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
	str r1, [r4, #0x1c]
	movs r0, #4
	strb r0, [r4]
	movs r6, #1
	strb r6, [r4, #3]
	strb r2, [r4, #2]
	movs r0, #0x19
	strb r0, [r4, #1]
	movs r5, #0
	strh r2, [r4, #8]
	strh r2, [r4, #6]
	strh r2, [r4, #4]
	adds r0, r4, #0
	bl sub_80A3FDC
	ldr r0, _080A3FC4 @ =0x0000FFFF
	bl sub_80C4C0C
	ldr r1, _080A3FC8 @ =gBgPalette
	strh r0, [r1]
	ldr r1, _080A3FCC @ =gFlags
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _080A3FD0 @ =gBgSprites_Unknown1
	strb r5, [r0]
	ldr r1, _080A3FD4 @ =gBgSprites_Unknown2
	strb r5, [r1]
	strb r5, [r1, #1]
	movs r0, #0xff
	strb r0, [r1, #2]
	movs r0, #0x40
	strb r0, [r1, #3]
	ldr r2, _080A3FD8 @ =gWinRegs
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #0xc]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3FB4: .4byte gDispCnt
_080A3FB8: .4byte Task_94_B_80A40A0
_080A3FBC: .4byte TaskDestructor_94_B_80A43DC
_080A3FC0: .4byte 0xFFFF8800
_080A3FC4: .4byte 0x0000FFFF
_080A3FC8: .4byte gBgPalette
_080A3FCC: .4byte gFlags
_080A3FD0: .4byte gBgSprites_Unknown1
_080A3FD4: .4byte gBgSprites_Unknown2
_080A3FD8: .4byte gWinRegs

.syntax divided
