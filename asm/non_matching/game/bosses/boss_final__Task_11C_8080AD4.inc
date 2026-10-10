.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08080B1C @ =gCurTask
	ldr r1, [r0]
	ldrh r2, [r1, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r5, r2, r1
	ldr r1, _08080B20 @ =0x03000110
	adds r7, r2, r1
	ldrh r1, [r5, #0x2c]
	adds r3, r0, #0
	cmp r1, #0xc8
	bne _08080B00
	ldr r4, _08080B24 @ =0x03000064
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #0xc8
	beq _08080B12
_08080B00:
	movs r0, #0xfa
	lsls r0, r0, #3
	cmp r1, r0
	bne _08080B28
	ldr r4, _08080B24 @ =0x03000064
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, r1
	bne _08080B28
_08080B12:
	ldr r0, [r3]
	bl TaskDestroy
	b _08080BC0
	.align 2, 0
_08080B1C: .4byte gCurTask
_08080B20: .4byte 0x03000110
_08080B24: .4byte 0x03000064
_08080B28:
	adds r0, r5, #0
	bl sub_8080BD0
	adds r0, r5, #0
	bl sub_80811E0
	movs r6, #0
	movs r0, #0x14
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x18
	adds r1, r1, r5
	mov sb, r1
	ldr r2, _08080B9C @ =gCamera
	mov r8, r2
_08080B46:
	lsls r2, r6, #3
	subs r2, r2, r6
	lsls r0, r2, #3
	adds r0, #0x68
	adds r4, r5, r0
	lsls r2, r2, #2
	mov r3, sl
	adds r0, r3, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r3, r8
	ldr r1, [r3]
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	add r2, sb
	ldr r0, [r2]
	asrs r0, r0, #8
	ldr r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	ldr r0, [r4, #8]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08080BA0
	ldrh r0, [r5, #2]
	strh r0, [r7]
	ldrh r0, [r4, #0x10]
	strh r0, [r7, #6]
	ldrh r0, [r4, #0x12]
	strh r0, [r7, #8]
	adds r0, r4, #0
	adds r1, r7, #0
	bl TransformSprite
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
	b _08080BAC
	.align 2, 0
_08080B9C: .4byte gCamera
_08080BA0:
	adds r0, r4, #0
	bl UpdateSpriteAnimation
	adds r0, r4, #0
	bl DisplaySprite
_08080BAC:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #2
	bhi _08080BC0
	cmp r6, #2
	bne _08080B46
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _08080B46
_08080BC0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	@ struct 0x11C

.syntax divided
