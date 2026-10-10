.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r4, #0
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, _080A0A78 @ =gUnknown_080D8F00
	ldrh r1, [r2]
	movs r3, #0
	strh r1, [r0, #0xc]
	ldrb r1, [r2, #2]
	strb r1, [r0, #0x1a]
	movs r1, #0xff
	strb r1, [r0, #0x1b]
	ldr r1, [r6, #0x5c]
	asrs r1, r1, #8
	strh r1, [r0, #0x10]
	ldr r1, [r6, #0x60]
	asrs r1, r1, #8
	strh r1, [r0, #0x12]
	movs r1, #0x40
	strh r1, [r0, #0x14]
	strh r4, [r0, #0xe]
	strh r4, [r0, #0x16]
	movs r1, #0x10
	strb r1, [r0, #0x1c]
	strb r3, [r0, #0x1f]
	str r4, [r0, #8]
	bl UpdateSpriteAnimation
	adds r7, r6, #0
	adds r7, #0xb4
	ldr r1, _080A0A7C @ =gUnknown_080D8F18
	ldrb r0, [r6, #2]
	adds r0, r0, r1
	ldrb r4, [r0]
	ldrb r0, [r6, #1]
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r4, #4
	bhi _080A0A5E
	cmp r5, #4
	bls _080A0A62
_080A0A5E:
	bl sub_802613C
_080A0A62:
	cmp r4, #0
	beq _080A0A6A
	cmp r5, #0
	bne _080A0A98
_080A0A6A:
	cmp r4, #2
	beq _080A0A72
	cmp r5, #2
	bne _080A0A80
_080A0A72:
	movs r4, #4
	b _080A0AAE
	.align 2, 0
_080A0A78: .4byte gUnknown_080D8F00
_080A0A7C: .4byte gUnknown_080D8F18
_080A0A80:
	cmp r4, #3
	beq _080A0A88
	cmp r5, #3
	bne _080A0A8C
_080A0A88:
	movs r4, #6
	b _080A0AAE
_080A0A8C:
	cmp r4, #4
	beq _080A0A94
	cmp r5, #4
	bne _080A0AAC
_080A0A94:
	movs r4, #3
	b _080A0AAE
_080A0A98:
	cmp r4, #4
	bne _080A0AA0
	cmp r5, #1
	beq _080A0AA8
_080A0AA0:
	cmp r4, #1
	bne _080A0AAC
	cmp r5, #4
	bne _080A0AAC
_080A0AA8:
	movs r4, #5
	b _080A0AAE
_080A0AAC:
	movs r4, #2
_080A0AAE:
	ldr r1, _080A0AD8 @ =gUnknown_080D8D08
	ldrb r0, [r6]
	lsls r0, r0, #3
	adds r0, r4, r0
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	ldrb r0, [r6]
	lsls r0, r0, #3
	adds r0, r4, r0
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	strb r0, [r7, #0x1a]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0AD8: .4byte gUnknown_080D8D08

.syntax divided
