.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _080282DC @ =0x06010000
	str r0, [sp, #4]
	ldr r2, _080282E0 @ =gDispCnt
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080282E4 @ =gBgCntRegs
	movs r5, #0
	movs r4, #0
	ldr r0, _080282E8 @ =0x00001E0F
	strh r0, [r1]
	ldr r0, _080282EC @ =0x00001C0A
	strh r0, [r1, #2]
	ldr r1, _080282F0 @ =gBgScrollRegs
	strh r4, [r1]
	strh r4, [r1, #2]
	ldr r0, _080282F4 @ =0x0000FFE0
	strh r0, [r1, #4]
	adds r0, #0x10
	strh r0, [r1, #6]
	str r4, [sp]
	ldr r1, _080282F8 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _080282FC @ =0x06009FE0
	str r0, [r1, #4]
	ldr r0, _08028300 @ =0x85000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08028304 @ =gBgSprites_Unknown1
	movs r0, #0xff
	strb r0, [r1, #1]
	ldr r1, _08028308 @ =gBgSprites_Unknown2
	strb r5, [r1, #4]
	strb r5, [r1, #5]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #6]
	movs r0, #0x20
	strb r0, [r1, #7]
	adds r2, r7, #0
	adds r2, #0xc
	ldr r0, _0802830C @ =0x0600C000
	str r0, [r2, #4]
	strh r4, [r2, #0xa]
	ldr r0, _08028310 @ =0x0600F000
	str r0, [r2, #0xc]
	strh r4, [r2, #0x18]
	strh r4, [r2, #0x1a]
	movs r0, #0xc6
	lsls r0, r0, #1
	strh r0, [r2, #0x1c]
	strh r4, [r2, #0x1e]
	strh r4, [r2, #0x20]
	strh r4, [r2, #0x22]
	strh r4, [r2, #0x24]
	movs r0, #0x1e
	strh r0, [r2, #0x26]
	movs r0, #0x14
	strh r0, [r2, #0x28]
	adds r0, r7, #0
	adds r0, #0x36
	strb r5, [r0]
	strh r4, [r2, #0x2e]
	adds r0, r2, #0
	bl DrawBackground
	adds r2, r7, #0
	adds r2, #0x4c
	ldr r0, _08028314 @ =0x06008000
	str r0, [r2, #4]
	strh r4, [r2, #0xa]
	ldr r0, _08028318 @ =0x0600E000
	str r0, [r2, #0xc]
	strh r4, [r2, #0x18]
	strh r4, [r2, #0x1a]
	ldr r1, _0802831C @ =gLoadedSaveGame
	ldr r3, _08028320 @ =0x00000366
	adds r1, r1, r3
	ldr r3, _08028324 @ =0x0000018D
	adds r0, r3, #0
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	strh r4, [r2, #0x1e]
	strh r4, [r2, #0x20]
	strh r4, [r2, #0x22]
	strh r4, [r2, #0x24]
	movs r0, #0xe
	strh r0, [r2, #0x26]
	movs r0, #3
	strh r0, [r2, #0x28]
	adds r0, r7, #0
	adds r0, #0x76
	strb r5, [r0]
	movs r0, #1
	mov sl, r0
	movs r0, #1
	strh r0, [r2, #0x2e]
	adds r0, r2, #0
	bl DrawBackground
	ldr r1, _08028328 @ =gWinRegs
	ldr r0, _0802832C @ =0x0000B8D0
	strh r0, [r1]
	ldr r0, _08028330 @ =0x00000898
	strh r0, [r1, #4]
	strh r4, [r1, #8]
	movs r0, #0x13
	strh r0, [r1, #0xa]
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r3, [sp, #4]
	str r3, [r1]
	ldr r0, _08028334 @ =0x000005AD
	mov sb, r0
	mov r3, sb			@ r3 = sb = ANIM_MP_SINGLEPAK_TRANSFER_SCREEN_CHAO
	strh r3, [r1, #0xc]
	strb r5, [r1, #0x1a]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #0x1b]
	movs r0, #0x50
	strh r0, [r1, #0x10]
	movs r0, #0x6c
	strh r0, [r1, #0x12]
	strh r4, [r1, #0x14]
	strh r4, [r1, #0xe]
	strh r4, [r1, #0x16]
	movs r0, #0x10
	mov r8, r0
	mov r3, r8
	strb r3, [r1, #0x1c]
	strb r5, [r1, #0x1f]
	str r4, [r1, #8]
	movs r6, #1
	rsbs r6, r6, #0
	str r6, [r1, #0x20]
	adds r0, r1, #0
	bl UpdateSpriteAnimation
	movs r0, #0xc0
	lsls r0, r0, #3
	ldr r1, [sp, #4]
	adds r1, r1, r0
	str r1, [sp, #4]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r3, [sp, #4]
	str r3, [r1]
	mov r0, sb			@ r0 = sb = ANIM_MP_SINGLEPAK_TRANSFER_SCREEN_CHAO
	strh r0, [r1, #0xc]
	mov r3, sl
	strb r3, [r1, #0x1a]
	adds r0, r6, #0
	strb r0, [r1, #0x1b]
	movs r0, #0x70
	strh r0, [r1, #0x10]
	movs r0, #0x58
	strh r0, [r1, #0x12]
	strh r4, [r1, #0x14]
	strh r4, [r1, #0xe]
	strh r4, [r1, #0x16]
	mov r0, r8
	strb r0, [r1, #0x1c]
	strb r5, [r1, #0x1f]
	str r4, [r1, #8]
	str r6, [r1, #0x20]
	adds r0, r1, #0
	bl UpdateSpriteAnimation
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080282DC: .4byte 0x06010000
_080282E0: .4byte gDispCnt
_080282E4: .4byte gBgCntRegs
_080282E8: .4byte 0x00001E0F
_080282EC: .4byte 0x00001C0A
_080282F0: .4byte gBgScrollRegs
_080282F4: .4byte 0x0000FFE0
_080282F8: .4byte 0x040000D4
_080282FC: .4byte 0x06009FE0
_08028300: .4byte 0x85000008
_08028304: .4byte gBgSprites_Unknown1
_08028308: .4byte gBgSprites_Unknown2
_0802830C: .4byte 0x0600C000
_08028310: .4byte 0x0600F000
_08028314: .4byte 0x06008000
_08028318: .4byte 0x0600E000
_0802831C: .4byte gLoadedSaveGame
_08028320: .4byte 0x00000366
_08028324: .4byte 0x0000018D
_08028328: .4byte gWinRegs
_0802832C: .4byte 0x0000B8D0
_08028330: .4byte 0x00000898
_08028334: .4byte 0x000005AD

.syntax divided
