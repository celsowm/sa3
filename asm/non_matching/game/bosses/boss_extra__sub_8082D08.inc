.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _08082DEC @ =gCamera
	mov r8, r0
_08082D1C:
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r4, r6, r0
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r0, r2, #2
	ldr r7, _08082DF0 @ =0x00000848
	adds r0, r0, r7
	adds r3, r6, r0
	lsls r2, r2, #3
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r7, r8
	ldr r1, [r7]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	cmp r5, #2
	bne _08082E00
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r7, _08082DF4 @ =0xFFFFFD80
	adds r0, r7, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r2, _08082DF8 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #0x10]
	strh r0, [r3, #6]
	ldrh r0, [r4, #0x12]
	strh r0, [r3, #8]
	adds r0, r4, #0
	adds r1, r3, #0
	bl TransformSprite
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	movs r5, #0
	movs r7, #3
	mov sb, r7
	ldr r0, _08082DFC @ =0x00000634
	adds r0, r0, r6
	mov sl, r0
	movs r3, #0xf0
_08082DA2:
	lsls r2, r5, #2
	adds r2, r2, r5
	lsls r0, r2, #3
	mov r1, sl
	adds r4, r1, r0
	lsls r2, r2, #2
	adds r2, r2, r3
	movs r7, #0xb6
	lsls r7, r7, #1
	adds r0, r6, r7
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r7, r8
	ldr r1, [r7]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	str r3, [sp]
	bl DisplaySprite
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r3, [sp]
	cmp r5, #5
	bls _08082DA2
	b _08082E10
	.align 2, 0
_08082DEC: .4byte gCamera
_08082DF0: .4byte 0x00000848
_08082DF4: .4byte 0xFFFFFD80
_08082DF8: .4byte 0x000003FF
_08082DFC: .4byte 0x00000634
_08082E00:
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	adds r5, #1
	mov sb, r5
_08082E10:
	mov r2, sb
	lsls r0, r2, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bhi _08082E1C
	b _08082D1C
_08082E1C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
