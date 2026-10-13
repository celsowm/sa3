.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r5, r0
_080A11C4:
	ldr r0, [r5, #0x64]
	asrs r0, r0, #8
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x68]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0x1f]
	cmp r6, #0
	beq _080A11E2
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080A11E8
_080A11E2:
	ldr r0, [r4, #8]
	ldr r1, _080A1240 @ =0xFFFFFBFF
	ands r0, r1
_080A11E8:
	str r0, [r4, #8]
	adds r0, r4, #0
	bl DisplaySprite
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bls _080A11C4
	ldrb r1, [r5]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	ldr r2, _080A1244 @ =gUnknown_080D8F18
	ldrb r1, [r5, #1]
	adds r1, r1, r2
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r2, _080A1248 @ =gTileInfo_CharSelect3_NameTagNames
	lsls r0, r0, #3
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	strh r1, [r4, #0xc]
	ldrb r0, [r0, #2]
	strb r0, [r4, #0x1a]
	ldr r0, [r5, #0x64]
	asrs r0, r0, #8
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x68]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1240: .4byte 0xFFFFFBFF
_080A1244: .4byte gUnknown_080D8F18
_080A1248: .4byte gTileInfo_CharSelect3_NameTagNames

.syntax divided
