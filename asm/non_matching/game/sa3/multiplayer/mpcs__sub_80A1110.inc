.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r7, #0
_080A111E:
	ldr r0, [r5, #0x5c]
	asrs r0, r0, #8
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	strb r7, [r4, #0x1f]
	cmp r6, #0
	beq _080A113A
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080A1140
_080A113A:
	ldr r0, [r4, #8]
	ldr r1, _080A1168 @ =0xFFFFFBFF
	ands r0, r1
_080A1140:
	str r0, [r4, #8]
	adds r0, r4, #0
	bl DisplaySprite
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bls _080A111E
	ldrb r1, [r5]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r3, r0, #0x1f
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	cmp r0, #0xc
	bls _080A1170
	ldr r1, _080A116C @ =gUnknown_080D8F18
	ldrb r0, [r5, #2]
	b _080A1174
	.align 2, 0
_080A1168: .4byte 0xFFFFFBFF
_080A116C: .4byte gUnknown_080D8F18
_080A1170:
	ldr r1, _080A11B0 @ =gUnknown_080D8F18
	ldrb r0, [r5, #1]
_080A1174:
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, _080A11B4 @ =gUnknown_080D8E80
	lsls r0, r3, #3
	adds r0, r2, r0
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r4, #0xc]
	ldrb r0, [r0, #2]
	strb r0, [r4, #0x1a]
	ldr r0, [r5, #0x5c]
	asrs r0, r0, #8
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A11B0: .4byte gUnknown_080D8F18
_080A11B4: .4byte gUnknown_080D8E80

.syntax divided
