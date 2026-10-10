.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r6, _08028098 @ =0x06010000
	ldr r1, _0802809C @ =gUnknown_080CEF2C
	mov r0, sp
	movs r2, #0x24
	bl memcpy
	ldr r0, _080280A0 @ =gLoadedSaveGame
	ldr r1, _080280A4 @ =0x00000366	@ gLoadedSaveGame::language
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r7, #0
	adds r1, #0x8c
	str r6, [r1]
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #1
	mov r2, sp
	adds r0, r2, r4
	ldrh r0, [r0]
	movs r2, #0
	mov sl, r2
	movs r5, #0
	strh r0, [r1, #0xc]
	mov r0, sp
	adds r0, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r1, #0x1a]
	movs r0, #0xff
	strb r0, [r1, #0x1b]
	movs r0, #0x78
	strh r0, [r1, #0x10]
	movs r0, #0x8c
	strh r0, [r1, #0x12]
	strh r5, [r1, #0x14]
	strh r5, [r1, #0xe]
	strh r5, [r1, #0x16]
	movs r0, #0x10
	mov sb, r0
	mov r2, sb
	strb r2, [r1, #0x1c]
	mov r0, sl
	strb r0, [r1, #0x1f]
	str r5, [r1, #8]
	movs r2, #1
	rsbs r2, r2, #0
	mov r8, r2
	str r2, [r1, #0x20]
	adds r0, r1, #0
	bl UpdateSpriteAnimation
	add r0, sp, #4
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r6, r0, r6
	adds r1, r7, #0
	adds r1, #0xb4
	str r6, [r1]
	ldr r0, _080280A8 @ =0x00000596		@ ANIM_MP_TXT_CHARS_AND_ACTS
	strh r0, [r1, #0xc]
	movs r0, #0xf
	strb r0, [r1, #0x1a]
	subs r0, #0x10
	strb r0, [r1, #0x1b]
	movs r0, #0x70
	strh r0, [r1, #0x10]
	movs r0, #0x68
	strh r0, [r1, #0x12]
	strh r5, [r1, #0x14]
	strh r5, [r1, #0xe]
	strh r5, [r1, #0x16]
	mov r0, sb
	strb r0, [r1, #0x1c]
	mov r2, sl
	strb r2, [r1, #0x1f]
	str r5, [r1, #8]
	mov r0, r8
	str r0, [r1, #0x20]
	adds r0, r1, #0
	bl UpdateSpriteAnimation
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028098: .4byte 0x06010000
_0802809C: .4byte gUnknown_080CEF2C
_080280A0: .4byte gLoadedSaveGame
_080280A4: .4byte 0x00000366
_080280A8: .4byte 0x00000596

.syntax divided
