.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	mov r6, sb
	adds r6, #0x40
	mov r0, sp
	adds r0, #0x28
	str r0, [sp, #0x3c]
	ldr r1, _080290E8 @ =gUnknown_080CEF50
	movs r2, #8
	bl memcpy
	ldr r1, _080290EC @ =gDispCnt
	movs r2, #0x82
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	movs r7, #0
	ldr r0, _080290F0 @ =0x00001E08
	ldr r3, _080290F4 @ =gBgCntRegs
	strh r0, [r3]
	ldr r0, _080290F8 @ =0x00005C0F
	strh r0, [r3, #6]
	str r7, [sp, #0x30]
	ldr r5, _080290FC @ =0x040000D4
	add r0, sp, #0x30
	str r0, [r5]
	movs r1, #0xc
	mov r8, r1
	movs r2, #3
	lsls r1, r2, #0xe
	ldr r2, _08029100 @ =0x060004C0
	adds r1, r1, r2
	str r1, [r5, #4]
	ldr r3, _08029104 @ =0x85000008
	str r3, [r5, #8]
	ldr r1, [r5, #8]
	movs r1, #0x26
	ldr r2, _08029108 @ =gBgSprites_Unknown1
	strb r1, [r2, #3]
	ldr r4, _0802910C @ =gBgSprites_Unknown2
	movs r3, #0
	strb r3, [r4, #0xc]
	strb r3, [r4, #0xd]
	movs r1, #0xff
	strb r1, [r4, #0xe]
	movs r1, #0x40
	strb r1, [r4, #0xf]
	str r7, [sp, #0x30]
	ldr r1, _08029110 @ =0x05000010
	mov sl, r1
	mov r1, sb
	mov r2, sl
	bl CpuSet
	ldr r0, _08029114 @ =0x0600C000
	mov r2, sb
	str r0, [r2, #4]
	ldr r0, _08029118 @ =0x0600E000
	str r0, [r2, #0xc]
	movs r3, #4
	strh r3, [r2, #0x1c]
	movs r0, #0x1e
	strh r0, [r2, #0x26]
	movs r0, #0x19
	strh r0, [r2, #0x28]
	movs r0, #3
	strh r0, [r2, #0x2e]
	mov r0, sb
	bl DrawBackground
	str r7, [sp, #0x34]
	add r0, sp, #0x34
	adds r1, r6, #0
	mov r2, sl
	bl CpuSet
	ldr r0, _0802911C @ =0x06008000
	str r0, [r6, #4]
	ldr r0, _08029120 @ =0x0600F000
	str r0, [r6, #0xc]
	ldr r0, _08029124 @ =gStageData
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, #5
	strh r0, [r6, #0x1c]
	movs r0, #0x12
	strh r0, [r6, #0x26]
	movs r1, #4
	strh r1, [r6, #0x28]
	strh r7, [r6, #0x2e]
	adds r0, r6, #0
	bl DrawBackground
	ldr r1, _08029128 @ =gBgScrollRegs
	ldr r0, _0802912C @ =0x0000FFD0
	strh r0, [r1]
	subs r0, #0x10
	strh r0, [r1, #2]
	str r7, [sp, #0x38]
	add r1, sp, #0x38
	str r1, [r5]
	ldr r2, _080290F4 @ =gBgCntRegs
	ldrh r0, [r2]
	mov r3, r8
	ands r3, r0
	lsls r3, r3, #0xc
	mov r8, r3
	ldr r0, _08029130 @ =0x06000480
	add r8, r0
	mov r0, r8
	str r0, [r5, #4]
	ldr r2, _08029104 @ =0x85000008
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	movs r0, #0x24
	ldr r3, _08029108 @ =gBgSprites_Unknown1
	strb r0, [r3]
	movs r0, #0
	strb r0, [r4]
	strb r0, [r4, #1]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #2]
	movs r0, #0x20
	strb r0, [r4, #3]
	ldr r2, _08029134 @ =0x06010000
	mov sl, r2
	movs r3, #0
_08028EF6:
	lsls r4, r3, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #4
	adds r0, #0x80
	mov r2, sb
	adds r7, r2, r0
	mov r0, sl
	str r0, [r7]
	movs r2, #0x80
	lsls r2, r2, #5
	mov r8, r2
	str r2, [r7, #8]
	add r1, sp
	adds r1, #0x28
	ldrh r0, [r1]
	movs r1, #0
	strh r0, [r7, #0xc]		@ anim : ???
	strb r1, [r7, #0x1a]
	movs r0, #0x78
	strh r0, [r7, #0x10]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, #0x14
	strh r0, [r7, #0x12]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r7, #0x14]
	strh r1, [r7, #0x16]
	movs r0, #1
	rsbs r0, r0, #0
	add r1, sp, #0x40
	strh r0, [r1]
	ldr r0, _08029138 @ =0x0000FFFF
	strh r0, [r7, #0x18]
	movs r2, #1
	rsbs r2, r2, #0
	add r0, sp, #0x44
	strb r2, [r0]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r6, #0x10
	strb r6, [r7, #0x1c]
	strb r3, [r7, #0x1f]
	adds r5, r2, #0
	str r5, [r7, #0x20]
	str r5, [r7, #0x28]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	adds r4, #1
	lsls r4, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #4
	add sl, r1
	lsrs r3, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08028EF6
	movs r0, #0
	str r0, [sp, #0x38]
	ldr r2, _0802913C @ =0x0500000A
	add r0, sp, #0x38
	mov r1, sp
	bl CpuSet
	mov r2, r8
	str r2, [sp, #8]
	mov r3, sl
	str r3, [sp]
	mov r1, sp
	ldrh r0, [r1, #0x18]
	add r2, sp, #0x40
	ldrh r2, [r2]
	orrs r0, r2
	strh r0, [r1, #0x18]
	ldrb r0, [r1, #0x1b]
	add r3, sp, #0x44
	ldrb r3, [r3]
	orrs r0, r3
	strb r0, [r1, #0x1b]
	mov r0, sp
	strb r6, [r0, #0x1c]
	str r5, [sp, #0x20]
	movs r7, #0xa0
	lsls r7, r7, #1
	add r7, sb
	ldr r2, _08029140 @ =0x0400000A
	adds r1, r7, #0
	bl CpuSet
	movs r7, #0xb4
	lsls r7, r7, #1
	add r7, sb
	ldr r0, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #8]
	movs r3, #1
_08028FC2:
	mov r0, sp
	adds r1, r7, #0
	ldr r2, _08029140 @ =0x0400000A
	str r3, [sp, #0x48]
	bl CpuSet
	ldr r3, [sp, #0x48]
	lsls r0, r3, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	adds r7, #0x28
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _08028FC2
	movs r7, #0xa0
	lsls r7, r7, #1
	add r7, sb
	movs r3, #0
	movs r2, #0xb3
	lsls r2, r2, #3
	mov r8, r2			@ r8 = 1432 palette anim?
_08028FF0:
	ldr r0, _08029144 @ =gUnknown_03000970
	lsls r6, r3, #0x10
	asrs r6, r6, #0x10
	lsls r5, r6, #2
	adds r0, r5, r0
	ldrb r4, [r0, #1]
	adds r0, r4, #0
	movs r1, #0xa
	str r3, [sp, #0x48]
	bl Div
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	strh r1, [r7, #0xc]
	ldr r3, [sp, #0x48]
	strb r3, [r7, #0x1a]
	movs r1, #0x28
	strh r1, [r7, #0x10]
	adds r5, r5, r6
	lsls r5, r5, #3
	adds r5, #0x14
	strh r5, [r7, #0x12]
	adds r7, #0x28
	mov r2, r8
	strh r2, [r7, #0xc]
	adds r0, #0xb
	strb r0, [r7, #0x1a]
	movs r0, #0xaa
	strh r0, [r7, #0x10]
	strh r5, [r7, #0x12]
	adds r7, #0x28
	strh r2, [r7, #0xc]
	adds r4, #0xb
	strb r4, [r7, #0x1a]
	movs r0, #0xb4
	strh r0, [r7, #0x10]
	strh r5, [r7, #0x12]
	adds r7, #0x28
	strh r2, [r7, #0xc]
	movs r0, #0xa
	strb r0, [r7, #0x1a]
	movs r0, #0xc8
	strh r0, [r7, #0x10]
	strh r5, [r7, #0x12]
	adds r7, #0x28
	strh r2, [r7, #0xc]
	ldr r4, _08029124 @ =gStageData
	ldrb r0, [r4]
	lsls r2, r0, #1
	adds r2, r2, r0
	adds r2, #4
	ldr r0, _08029148 @ =0x00000492
	add r0, sb
	ldrb r1, [r0]
	lsls r0, r6, #1
	asrs r1, r0
	movs r0, #3
	ands r1, r0
	adds r2, r2, r1
	strb r2, [r7, #0x1a]
	movs r1, #0x50
	strh r1, [r7, #0x10]
	strh r5, [r7, #0x12]
	adds r6, #1
	lsls r6, r6, #0x10
	adds r7, #0x28
	lsrs r3, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #3
	ble _08028FF0
	movs r3, #0xb4
	lsls r3, r3, #4
	add sl, r3
	movs r7, #0x8c
	lsls r7, r7, #3
	add r7, sb
	mov r0, sl
	str r0, [r7]
	ldr r0, _0802914C @ =0x00000599		@ ANIM_PRESS_START
	strh r0, [r7, #0xc]
	ldrb r0, [r4]
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	strb r0, [r7, #0x1a]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r7, #8]
	movs r0, #0x78
	strh r0, [r7, #0x10]
	strh r1, [r7, #0x12]
	movs r7, #0xa0
	lsls r7, r7, #1
	add r7, sb
	movs r3, #0
_080290BA:
	adds r0, r7, #0
	str r3, [sp, #0x48]
	bl UpdateSpriteAnimation
	ldr r3, [sp, #0x48]
	lsls r0, r3, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	adds r7, #0x28
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _080290BA
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080290E8: .4byte gUnknown_080CEF50
_080290EC: .4byte gDispCnt
_080290F0: .4byte 0x00001E08
_080290F4: .4byte gBgCntRegs
_080290F8: .4byte 0x00005C0F
_080290FC: .4byte 0x040000D4
_08029100: .4byte 0x060004C0
_08029104: .4byte 0x85000008
_08029108: .4byte gBgSprites_Unknown1
_0802910C: .4byte gBgSprites_Unknown2
_08029110: .4byte 0x05000010
_08029114: .4byte 0x0600C000
_08029118: .4byte 0x0600E000
_0802911C: .4byte 0x06008000
_08029120: .4byte 0x0600F000
_08029124: .4byte gStageData
_08029128: .4byte gBgScrollRegs
_0802912C: .4byte 0x0000FFD0
_08029130: .4byte 0x06000480
_08029134: .4byte 0x06010000
_08029138: .4byte 0x0000FFFF
_0802913C: .4byte 0x0500000A
_08029140: .4byte 0x0400000A
_08029144: .4byte gUnknown_03000970
_08029148: .4byte 0x00000492
_0802914C: .4byte 0x00000599

.syntax divided
