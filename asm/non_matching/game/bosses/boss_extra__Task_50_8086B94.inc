.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _08086BDC @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r7, [r4, #0x4c]
	adds r0, #0x18
	adds r6, r1, r0
	ldr r2, _08086BE0 @ =0x03000040
	adds r2, r2, r1
	mov r8, r2
	movs r0, #0
	mov sb, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _08086BCA
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne _08086BCA
	movs r0, #0x64
	strh r0, [r4, #0x12]
_08086BCA:
	ldrh r0, [r4, #0x12]
	cmp r0, #0x64
	beq _08086C0C
	cmp r0, #0x64
	bgt _08086BE4
	cmp r0, #0
	beq _08086BEA
	b _08086C38
	.align 2, 0
_08086BDC: .4byte gCurTask
_08086BE0: .4byte 0x03000040
_08086BE4:
	cmp r0, #0x6e
	beq _08086C28
	b _08086C38
_08086BEA:
	ldr r0, [r4, #4]
	ldr r1, [r4, #0xc]
	adds r1, r0, r1
	str r1, [r4, #4]
	ldrb r0, [r4, #0x16]
	cmp r0, #2
	bne _08086C00
	ldr r0, [r4, #8]
	cmp r1, r0
	blt _08086C38
	b _08086C06
_08086C00:
	ldr r0, [r4, #8]
	cmp r1, r0
	bgt _08086C38
_08086C06:
	movs r0, #0x64
	strh r0, [r4, #0x12]
	b _08086C38
_08086C0C:
	movs r1, #0
	ldr r0, _08086C24 @ =0x00000501
	strh r0, [r6, #0xc]
	strb r1, [r6, #0x1a]
	movs r0, #0x90          @ SE_CAPSULE_DESTROY
	bl m4aSongNumStart
	movs r0, #0x15
	strh r0, [r4, #0x10]
	movs r0, #0x6e
	strh r0, [r4, #0x12]
	b _08086C38
	.align 2, 0
_08086C24: .4byte 0x00000501
_08086C28:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08086C38
	movs r1, #1
	mov sb, r1
_08086C38:
	ldr r0, _08086C7C @ =gCamera
	adds r0, #0x6a
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r0, r1
	str r2, [r4]
	ldr r5, [r7, #0x28]
	ldr r0, [r5, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08086CA6
	asrs r1, r2, #8
	ldr r2, [r4, #4]
	asrs r2, r2, #8
	str r5, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl sub_8010184
	cmp r0, #0
	beq _08086C80
	adds r0, r5, #0
	movs r1, #1
	bl sub_801038C
	b _08086CA6
	.align 2, 0
_08086C7C: .4byte gCamera
_08086C80:
	ldr r1, [r4]
	asrs r1, r1, #8
	ldr r2, [r4, #4]
	asrs r2, r2, #8
	str r5, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl sub_8010288
	cmp r0, #0
	beq _08086CA6
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne _08086CA0
	movs r0, #0x64
	strh r0, [r4, #0x12]
_08086CA0:
	adds r0, r5, #0
	bl sub_8010C88
_08086CA6:
	ldr r5, [r7, #0x2c]
	ldr r0, _08086CF0 @ =gStageData
	ldrb r0, [r0, #3]
	cmp r0, #5
	bne _08086CFC
	ldr r0, [r5, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08086CFC
	ldr r1, [r4]
	asrs r1, r1, #8
	ldr r2, [r4, #4]
	asrs r2, r2, #8
	str r5, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl sub_8010184
	cmp r0, #0
	beq _08086CFC
	adds r0, r7, #0
	adds r0, #0x70
	ldrb r0, [r0]
	cmp r0, #0
	beq _08086CF4
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne _08086CE6
	movs r0, #0x64
	strh r0, [r4, #0x12]
_08086CE6:
	adds r0, r5, #0
	bl sub_8010C58
	b _08086CFC
	.align 2, 0
_08086CF0: .4byte gStageData
_08086CF4:
	adds r0, r5, #0
	movs r1, #1
	bl sub_801038C
_08086CFC:
	mov r2, sb
	cmp r2, #0
	beq _08086D20
	ldrb r0, [r4, #0x16]
	cmp r0, #2
	bne _08086D0E
	movs r0, #0
	strb r0, [r7, #3]
	b _08086D12
_08086D0E:
	movs r0, #0
	strb r0, [r7, #2]
_08086D12:
	ldr r0, _08086D1C @ =gCurTask
	ldr r0, [r0]
	bl TaskDestroy
	b _08086D50
	.align 2, 0
_08086D1C: .4byte gCurTask
_08086D20:
	ldr r0, [r4]
	asrs r0, r0, #8
	ldr r2, _08086D60 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r6, #0x12]
	ldrh r0, [r4, #0x14]
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r6, #0x10]
	strh r0, [r1, #6]
	ldrh r0, [r6, #0x12]
	strh r0, [r1, #8]
	adds r0, r6, #0
	bl UpdateSpriteAnimation
	adds r0, r6, #0
	bl DisplaySprite
_08086D50:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08086D60: .4byte gCamera

.syntax divided
