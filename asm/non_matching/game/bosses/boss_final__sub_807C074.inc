.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0x15
	bl VramMalloc
	mov sl, r0
	movs r6, #0
	movs r0, #0
	mov sb, r0
	movs r7, #0
	ldr r2, _0807C140 @ =gCamera
	mov r8, r2
_0807C094:
	lsls r3, r6, #2
	adds r3, r3, r6
	lsls r4, r3, #3
	adds r4, #0x7c
	adds r4, r5, r4
	mov r0, sl
	str r0, [r4]
	ldr r0, _0807C144 @ =0x000003BF @ ANIM_BOSS_7_WIDE_PLATFORM
	strh r0, [r4, #0xc]
	mov r2, sb
	strb r2, [r4, #0x1a]
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r4, #0x14]
	strh r7, [r4, #0xe]
	strh r7, [r4, #0x16]
	movs r0, #0xff
	strb r0, [r4, #0x1b]
	movs r0, #0x10
	strb r0, [r4, #0x1c]
	strb r2, [r4, #0x1f]
	subs r0, #0x11
	str r0, [r4, #0x20]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r4, #8]
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1, #0x3c]
	strh r7, [r1, #0x3e]
	adds r0, r5, #0
	adds r0, #0x34
	adds r0, r0, r3
	str r7, [r0]
	adds r0, r5, #0
	adds r0, #0x38
	adds r0, r0, r3
	str r7, [r0]
	adds r1, r5, #0
	adds r1, #0x2c
	adds r1, r1, r3
	lsls r0, r6, #4
	subs r0, r0, r6
	lsls r0, r0, #2
	subs r0, r0, r6
	ldr r2, _0807C148 @ =0x0000061F
	adds r0, r0, r2
	lsls r0, r0, #8
	str r0, [r1]
	adds r2, r5, #0
	adds r2, #0x30
	adds r2, r2, r3
	movs r0, #0xcc
	lsls r0, r0, #8
	str r0, [r2]
	ldr r0, [r1]
	asrs r0, r0, #8
	mov r3, r8
	ldr r1, [r3]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	ldr r0, [r2]
	asrs r0, r0, #8
	ldr r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r4, #0x27
	ldrb r0, [r4]
	adds r0, #0x20
	strb r0, [r4]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _0807C094
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C140: .4byte gCamera
_0807C144: .4byte 0x000003BF
_0807C148: .4byte 0x0000061F

.syntax divided
