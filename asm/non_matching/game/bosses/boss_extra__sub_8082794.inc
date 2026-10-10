.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, #0
	bne _080827AA
	b _08082924
_080827AA:
	movs r7, #0
	ldr r0, _08082908 @ =gCamera
	mov sb, r0
_080827B0:
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r5, r6, r0
	lsls r2, r7, #1
	adds r2, r2, r7
	lsls r0, r2, #2
	ldr r3, _0808290C @ =0x00000848
	adds r0, r0, r3
	adds r3, r6, r0
	lsls r2, r2, #3
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r6, r4
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r4, sb
	ldr r1, [r4]
	subs r0, r0, r1
	strh r0, [r5, #0x10]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	adds r2, r6, r2
	movs r4, #0x90
	lsls r4, r4, #1
	adds r2, r2, r4
	ldr r1, _08082910 @ =0xFFFFFD80
	adds r0, r1, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	ldr r2, _08082914 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r5, #0x10]
	strh r0, [r3, #6]
	ldrh r0, [r5, #0x12]
	strh r0, [r3, #8]
	adds r0, r5, #0
	adds r1, r3, #0
	bl TransformSprite
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
	movs r4, #0
	lsls r0, r7, #4
	adds r3, r7, #1
	mov r8, r3
	subs r1, r0, r7
	lsls r0, r1, #4
	ldr r7, _08082918 @ =0x00000454
	adds r0, r0, r7
	adds r3, r6, r0
	lsls r1, r1, #3
	mov sl, r1
_0808283C:
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r0, r2, #3
	adds r5, r3, r0
	lsls r2, r2, #2
	add r2, sl
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r7, sb
	ldr r1, [r7]
	subs r0, r0, r1
	strh r0, [r5, #0x10]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	adds r0, r5, #0
	str r3, [sp]
	bl DisplaySprite
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, [sp]
	cmp r4, #5
	bls _0808283C
	mov r2, r8
	lsls r0, r2, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080827B0
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _08082894
	b _08082A28
_08082894:
	ldr r3, _0808291C @ =0x00000814
	adds r5, r6, r3
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r4, _08082908 @ =gCamera
	ldr r1, [r4]
	subs r0, r0, r1
	subs r0, #0x10
	strh r0, [r5, #0x10]
	movs r7, #0xac
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	adds r0, #4
	strh r0, [r5, #0x12]
	ldr r0, [r5, #8]
	ldr r1, _08082920 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r5, #8]
	adds r0, r5, #0
	bl DisplaySprite
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4]
	subs r0, r0, r1
	subs r0, #0x10
	strh r0, [r5, #0x10]
	movs r2, #0x88
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	subs r0, #4
	strh r0, [r5, #0x12]
	ldr r0, [r5, #8]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r5, #8]
	adds r0, r5, #0
	bl DisplaySprite
	b _08082A28
	.align 2, 0
_08082908: .4byte gCamera
_0808290C: .4byte 0x00000848
_08082910: .4byte 0xFFFFFD80
_08082914: .4byte 0x000003FF
_08082918: .4byte 0x00000454
_0808291C: .4byte 0x00000814
_08082920: .4byte 0xFFFFF7FF
_08082924:
	movs r7, #0
	ldr r3, _08082A38 @ =gCamera
	mov sl, r3
_0808292A:
	lsls r0, r7, #1
	adds r1, r0, r7
	lsls r2, r1, #3
	adds r4, r6, r2
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _080829B4
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	movs r3, #0xed
	lsls r3, r3, #2
	adds r0, r0, r3
	adds r5, r6, r0
	lsls r0, r1, #2
	ldr r1, _08082A3C @ =0x00000848
	adds r0, r0, r1
	adds r3, r6, r0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov sb, r0
	mov r0, sl
	ldr r0, [r0]
	mov r1, sb
	subs r1, r1, r0
	strh r1, [r5, #0x10]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r2, sl
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r2, _08082A40 @ =0xFFFFFD80
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r4, _08082A44 @ =0x000003FF
	adds r1, r4, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r5, #0x10]
	strh r0, [r3, #6]
	ldrh r0, [r5, #0x12]
	strh r0, [r3, #8]
	adds r0, r5, #0
	adds r1, r3, #0
	bl TransformSprite
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
_080829B4:
	movs r4, #0
	lsls r0, r7, #4
	adds r1, r7, #1
	mov r8, r1
	subs r7, r0, r7
	lsls r0, r7, #4
	ldr r2, _08082A48 @ =0x00000454
	adds r0, r0, r2
	adds r0, r0, r6
	mov sb, r0
_080829C8:
	lsls r0, r4, #2
	adds r2, r0, r4
	lsls r1, r2, #2
	lsls r0, r7, #3
	adds r3, r1, r0
	adds r0, r6, r3
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08082A14
	lsls r0, r2, #3
	mov r2, sb
	adds r5, r2, r0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r3
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r2, sl
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r5, #0x10]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r3
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	adds r0, r5, #0
	bl DisplaySprite
_08082A14:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _080829C8
	mov r2, r8
	lsls r0, r2, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _0808292A
_08082A28:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082A38: .4byte gCamera
_08082A3C: .4byte 0x00000848
_08082A40: .4byte 0xFFFFFD80
_08082A44: .4byte 0x000003FF
_08082A48: .4byte 0x00000454

.syntax divided
