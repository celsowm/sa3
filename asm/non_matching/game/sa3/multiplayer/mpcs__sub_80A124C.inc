.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #1]
	ldrb r0, [r5, #2]
	cmp r0, #4
	bhi _080A125C
	cmp r1, #4
	bls _080A1298
_080A125C:
	ldr r3, _080A1278 @ =gStageData
	ldrb r2, [r3, #6]
	cmp r2, #1
	bls _080A1280
	ldr r1, _080A127C @ =gUnknown_03001060
	movs r0, #1
	ands r0, r2
	adds r1, #0x4c
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #2]
	ldrb r0, [r3, #6]
	b _080A1292
	.align 2, 0
_080A1278: .4byte gStageData
_080A127C: .4byte gUnknown_03001060
_080A1280:
	ldr r1, _080A12B0 @ =gUnknown_03001060
	ldrb r0, [r3, #6]
	adds r1, #0x4c
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #2]
	movs r0, #1
	ands r0, r2
	adds r0, #2
_080A1292:
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #1]
_080A1298:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080A12B8
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	ldrb r1, [r5, #1]
	adds r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, _080A12B4 @ =gUnknown_080D8F95
	b _080A12C6
	.align 2, 0
_080A12B0: .4byte gUnknown_03001060
_080A12B4: .4byte gUnknown_080D8F95
_080A12B8:
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	ldrb r1, [r5, #1]
	adds r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, _080A1300 @ =gUnknown_080D8F1D
_080A12C6:
	adds r7, r1, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _080A12DA
	ldrb r0, [r7, #1]
	cmp r0, #0
	beq _080A12DA
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _080A12DE
_080A12DA:
	bl sub_802613C
_080A12DE:
	movs r6, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r5, r0
_080A12E6:
	movs r0, #0x78
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	cmp r6, #0
	beq _080A1304
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080A130A
	.align 2, 0
_080A1300: .4byte gUnknown_080D8F1D
_080A1304:
	ldr r0, [r4, #8]
	ldr r1, _080A1378 @ =0xFFFFFBFF
	ands r0, r1
_080A130A:
	str r0, [r4, #8]
	adds r0, r4, #0
	bl DisplaySprite
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bls _080A12E6
	movs r1, #0x82
	lsls r1, r1, #1
	adds r4, r5, r1
	ldrb r0, [r7]
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r7, #1]
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r4, r5, r1
	ldrb r0, [r7, #2]
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x68]
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
_080A1378: .4byte 0xFFFFFBFF

.syntax divided
