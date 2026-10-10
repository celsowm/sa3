.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r1, _080A2EE4 @ =gDispCnt
	movs r2, #0x82
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080A2EE8 @ =Task_A0_80A2FF4
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r1, _080A2EEC @ =TaskDestructor_A0_80A3E34
	str r1, [sp]
	movs r1, #0xa0
	movs r3, #0
	bl TaskCreate
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #6
	str r1, [r0, #0x14]
	movs r1, #0x80
	lsls r1, r1, #7
	str r1, [r0, #0xc]
	movs r2, #0
	str r2, [r0, #0x18]
	str r2, [r0, #0x1c]
	movs r1, #2
	strb r1, [r0, #1]
	movs r4, #0
	strh r2, [r0, #4]
	strb r5, [r0]
	str r2, [sp, #4]
	ldr r3, _080A2EF0 @ =0x040000D4
	add r1, sp, #4
	str r1, [r3]
	ldr r1, _080A2EF4 @ =gBgCntRegs
	ldrh r2, [r1]
	movs r1, #0xc
	ands r1, r2
	lsls r1, r1, #0xc
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	str r1, [r3, #4]
	ldr r1, _080A2EF8 @ =0x85000010
	str r1, [r3, #8]
	ldr r1, [r3, #8]
	ldr r5, _080A2EFC @ =gBgSprites_Unknown1
	strb r4, [r5, #1]
	ldr r1, _080A2F00 @ =gBgSprites_Unknown2
	strb r4, [r1, #4]
	strb r4, [r1, #5]
	movs r2, #0xff
	strb r2, [r1, #6]
	movs r3, #0x40
	strb r3, [r1, #7]
	strb r4, [r5, #2]
	strb r4, [r1, #8]
	strb r4, [r1, #9]
	movs r2, #1
	rsbs r2, r2, #0
	strb r2, [r1, #0xa]
	strb r3, [r1, #0xb]
	bl sub_80A2F0C
	movs r0, #0
	bl sub_80C4C0C
	ldr r1, _080A2F04 @ =gBgPalette
	strh r0, [r1]
	ldr r2, _080A2F08 @ =gFlags
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2EE4: .4byte gDispCnt
_080A2EE8: .4byte Task_A0_80A2FF4
_080A2EEC: .4byte TaskDestructor_A0_80A3E34
_080A2EF0: .4byte 0x040000D4
_080A2EF4: .4byte gBgCntRegs
_080A2EF8: .4byte 0x85000010
_080A2EFC: .4byte gBgSprites_Unknown1
_080A2F00: .4byte gBgSprites_Unknown2
_080A2F04: .4byte gBgPalette
_080A2F08: .4byte gFlags

.syntax divided
