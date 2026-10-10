.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r1, _080A31D4 @ =gDispCnt
	ldr r0, _080A31D8 @ =0x00007140
	strh r0, [r1]
	ldr r0, _080A31DC @ =Task_174_80A3444
	movs r1, #0xba
	lsls r1, r1, #1
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, _080A31E0 @ =TaskDestructor_174_80A3E38
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r4, r0
	movs r1, #0
	strb r5, [r4]
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r4, #0x10]
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r4, #8]
	str r1, [r4, #0x14]
	ldr r0, _080A31E4 @ =0xFFFF9C00
	str r0, [r4, #0x18]
	movs r0, #0xe6
	lsls r0, r0, #8
	str r0, [r4, #0x24]
	movs r0, #0x82
	lsls r0, r0, #8
	str r0, [r4, #0x28]
	movs r0, #0xb4
	lsls r0, r0, #8
	str r0, [r4, #0x1c]
	movs r0, #0xa0
	lsls r0, r0, #8
	str r0, [r4, #0x20]
	movs r6, #1
	strb r6, [r4, #1]
	movs r3, #0
	strh r1, [r4, #6]
	strh r1, [r4, #4]
	strh r1, [r4, #2]
	str r1, [sp, #4]
	ldr r2, _080A31E8 @ =0x040000D4
	add r0, sp, #4
	str r0, [r2]
	ldr r0, _080A31EC @ =gBgCntRegs
	ldrh r1, [r0]
	movs r0, #0xc
	ands r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _080A31F0 @ =0x85000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r5, _080A31F4 @ =gBgSprites_Unknown1
	strb r3, [r5, #1]
	ldr r0, _080A31F8 @ =gBgSprites_Unknown2
	strb r3, [r0, #4]
	strb r3, [r0, #5]
	movs r1, #0xff
	strb r1, [r0, #6]
	movs r2, #0x40
	strb r2, [r0, #7]
	strb r3, [r5, #2]
	strb r3, [r0, #8]
	strb r3, [r0, #9]
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0, #0xa]
	strb r2, [r0, #0xb]
	adds r0, r4, #0
	bl sub_80A3354
	ldr r2, _080A31FC @ =gWinRegs
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A3200
	movs r0, #0
	b _080A3202
	.align 2, 0
_080A31D4: .4byte gDispCnt
_080A31D8: .4byte 0x00007140
_080A31DC: .4byte Task_174_80A3444
_080A31E0: .4byte TaskDestructor_174_80A3E38
_080A31E4: .4byte 0xFFFF9C00
_080A31E8: .4byte 0x040000D4
_080A31EC: .4byte gBgCntRegs
_080A31F0: .4byte 0x85000010
_080A31F4: .4byte gBgSprites_Unknown1
_080A31F8: .4byte gBgSprites_Unknown2
_080A31FC: .4byte gWinRegs
_080A3200:
	ldr r0, _080A321C @ =0x0000FFFF
_080A3202:
	bl sub_80C4C0C
	ldr r1, _080A3220 @ =gBgPalette
	strh r0, [r1]
	ldr r1, _080A3224 @ =gFlags
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A321C: .4byte 0x0000FFFF
_080A3220: .4byte gBgPalette
_080A3224: .4byte gFlags

.syntax divided
