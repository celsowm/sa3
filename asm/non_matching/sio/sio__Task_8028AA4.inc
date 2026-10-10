.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r0, _08028ACC @ =gCurTask
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r4, r0
	bl sub_802610C
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _08028AC6
	bl sub_8029368
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08028AD0
_08028AC6:
	bl sub_802613C
	b _08028C80
	.align 2, 0
_08028ACC: .4byte gCurTask
_08028AD0:
	ldr r2, _08028BAC @ =gUnknown_03001060
	ldr r0, _08028BB0 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #4
	ands r0, r1
	lsrs r0, r0, #8
	mov ip, r0
	ldr r0, _08028BB4 @ =0x04000128
	ldr r1, [r0]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1e
	movs r0, #1
	lsls r0, r1
	mov r1, ip
	orrs r0, r1
	strb r0, [r2, #7]
	ldr r3, _08028BB8 @ =gMultiSioSend
	ldr r0, _08028BBC @ =0x00006001
	strh r0, [r3]
	ldrb r0, [r2, #7]
	strb r0, [r3, #2]
	ldr r2, _08028BC0 @ =0x0300048C
	adds r7, r4, r2
	ldrb r0, [r7]
	lsls r0, r0, #4
	ldr r1, _08028BC4 @ =0x0300048B
	adds r6, r4, r1
	ldrb r1, [r6]
	orrs r0, r1
	strb r0, [r3, #5]
	ldr r1, _08028BC8 @ =gStageData
	adds r0, r1, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	strb r0, [r3, #7]
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _08028B70
	ldr r2, _08028BCC @ =gPseudoRandom
	ldr r1, [r2]
	ldr r0, _08028BD0 @ =0x00196225
	muls r1, r0, r1
	ldr r3, _08028BD4 @ =0x3C6EF35F
	adds r1, r1, r3
	str r1, [r2]
	movs r2, #7
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r6]
	lsrs r3, r1, #3
	movs r0, #1
	ands r3, r0
	strb r3, [r7]
	lsrs r3, r1, #6
	ands r3, r2
	ldr r2, _08028BD8 @ =0x0300048D
	adds r0, r4, r2
	strb r3, [r0]
	lsrs r1, r1, #9
	movs r2, #3
	ands r1, r2
	ldr r3, _08028BDC @ =0x0300048E
	adds r0, r4, r3
	strb r1, [r0]
	adds r1, #1
	ands r1, r2
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r1, #1
	ands r1, r2
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r1, #1
	ands r1, r2
	ldr r2, _08028BE0 @ =0x03000491
	adds r0, r4, r2
	strb r1, [r0]
_08028B70:
	ldr r3, _08028BE4 @ =0x0300048A
	adds r2, r4, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _08028C58
	mov r0, ip
	cmp r0, #3
	beq _08028B88
	cmp r0, #7
	beq _08028B88
	cmp r0, #0xf
	bne _08028C44
_08028B88:
	movs r1, #0x8c
	lsls r1, r1, #3
	adds r0, r5, r1
	bl DisplaySprite
	ldr r0, _08028BC8 @ =gStageData
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _08028BEC
	ldr r0, _08028BE8 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08028C72
	bl sub_8029324
	b _08028C72
	.align 2, 0
_08028BAC: .4byte gUnknown_03001060
_08028BB0: .4byte gMultiSioStatusFlags
_08028BB4: .4byte 0x04000128
_08028BB8: .4byte gMultiSioSend
_08028BBC: .4byte 0x00006001
_08028BC0: .4byte 0x0300048C
_08028BC4: .4byte 0x0300048B
_08028BC8: .4byte gStageData
_08028BCC: .4byte gPseudoRandom
_08028BD0: .4byte 0x00196225
_08028BD4: .4byte 0x3C6EF35F
_08028BD8: .4byte 0x0300048D
_08028BDC: .4byte 0x0300048E
_08028BE0: .4byte 0x03000491
_08028BE4: .4byte 0x0300048A
_08028BE8: .4byte gPressedKeys
_08028BEC:
	ldr r3, _08028C34 @ =gMultiSioRecv
	ldrh r1, [r3]
	ldr r0, _08028C38 @ =0x00006002
	cmp r1, r0
	bne _08028C72
	ldrb r1, [r3, #6]
	ldr r2, _08028C3C @ =0x0000048C
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r1, [r3, #5]
	subs r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r1, [r3, #4]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r1, [r3, #8]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r1, [r3, #9]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r1, [r3, #0xa]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r1, [r3, #0xb]
	ldr r3, _08028C40 @ =0x00000491
	adds r0, r5, r3
	strb r1, [r0]
	bl sub_8029324
	b _08028C72
	.align 2, 0
_08028C34: .4byte gMultiSioRecv
_08028C38: .4byte 0x00006002
_08028C3C: .4byte 0x0000048C
_08028C40: .4byte 0x00000491
_08028C44:
	ldr r2, _08028C50 @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _08028C54 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	b _08028C72
	.align 2, 0
_08028C50: .4byte gDispCnt
_08028C54: .4byte 0x0000FEFF
_08028C58:
	ldr r0, _08028C88 @ =0x03000488
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08028C72
	movs r0, #0
	strb r0, [r2]
	ldr r0, _08028C8C @ =0x00000321     @ MUS_VS_BGM_6
	bl m4aSongNumStart
_08028C72:
	ldr r0, _08028C90 @ =gUnknown_03001060
	ldrb r1, [r0, #7]
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #1
	bl sub_8029150
_08028C80:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028C88: .4byte 0x03000488
_08028C8C: .4byte 0x00000321
_08028C90: .4byte gUnknown_03001060

.syntax divided
