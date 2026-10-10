.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	asrs r6, r0, #0x10
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _080269D0 @ =gMultiSioRecv
	adds r7, r0, r1
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r6
	lsls r0, r0, #4
	ldr r2, _080269D4 @ =gPlayers
	adds r4, r0, r2
	ldr r3, _080269D8 @ =gStageData
	ldrb r5, [r3, #6]
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r5
	lsls r0, r0, #4
	adds r0, r0, r2
	mov sb, r0
	ldrh r1, [r7]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xd0
	lsls r1, r1, #7
	mov sl, r2
	mov r8, r3
	cmp r0, r1
	beq _0802690A
	b _08026AA6
_0802690A:
	cmp r6, #0
	bne _08026918
	cmp r5, #0
	beq _08026918
	ldrh r0, [r7, #2]
	mov r2, r8
	str r0, [r2, #0x1c]
_08026918:
	ldrh r0, [r7, #4]
	lsls r0, r0, #8
	ldr r1, [r4, #0x10]
	subs r5, r0, r1
	strh r5, [r4, #0x18]
	ldrh r0, [r7, #6]
	lsls r0, r0, #8
	ldr r1, [r4, #0x14]
	subs r3, r0, r1
	strh r3, [r4, #0x1a]
	movs r0, #0x18
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bge _08026936
	rsbs r2, r2, #0
_08026936:
	movs r0, #0x1a
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bge _08026940
	rsbs r1, r1, #0
_08026940:
	adds r0, r5, #0
	cmp r2, r1
	bge _08026948
	adds r0, r3, #0
_08026948:
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08026954
	movs r0, #0x10
	strh r0, [r4, #0x1c]
_08026954:
	ldrh r0, [r7, #4]
	lsls r0, r0, #8
	str r0, [r4, #0x10]
	ldrh r0, [r7, #6]
	lsls r0, r0, #8
	str r0, [r4, #0x14]
	ldr r0, _080269DC @ =0x0000FFFF
	strh r0, [r4, #0x30]
	ldrh r0, [r7, #0xc]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x15
	strh r0, [r4, #0x34]
	ldrb r0, [r7, #0xd]
	lsrs r0, r0, #3
	strh r0, [r4, #0x36]
	ldrb r0, [r7, #0x11]
	adds r1, r4, #0
	adds r1, #0x26
	strb r0, [r1]
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #8
	strh r0, [r4, #0x1c]
	ldr r0, [r7, #8]
	str r0, [r4, #4]
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrb r0, [r2]
	movs r1, #0xf
	ands r1, r0
	ldrb r0, [r7, #0xf]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1b
	lsls r0, r0, #4
	orrs r1, r0
	strb r1, [r2]
	ldrb r0, [r7, #0xf]
	lsrs r0, r0, #7
	adds r1, r4, #0
	adds r1, #0x27
	strb r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #3]
	cmp r0, #7
	beq _08026A94
	cmp r0, #5
	bne _080269E0
	ldrb r0, [r2, #0xa]
	cmp r0, #8
	bne _080269E0
	mov r3, r8
	adds r3, #0x8c
	ldrh r0, [r7, #0xe]
	lsls r0, r0, #0x16
	lsrs r1, r0, #0x16
	ldrh r0, [r3]
	mov r2, ip
	lsls r5, r2, #0x10
	cmp r0, r1
	bhs _08026AA0
	strh r1, [r3]
	b _08026AA0
	.align 2, 0
_080269D0: .4byte gMultiSioRecv
_080269D4: .4byte gPlayers
_080269D8: .4byte gStageData
_080269DC: .4byte 0x0000FFFF
_080269E0:
	mov r1, r8
	ldrb r0, [r1, #9]
	cmp r0, #8
	bne _08026A10
	mov r2, ip
	lsls r0, r2, #0x10
	adds r5, r0, #0
	cmp r5, #0
	bne _08026AA0
	adds r4, r1, #0
	adds r4, #0xac
	ldrh r0, [r7, #0xe]
	lsls r0, r0, #0x16
	ldrh r1, [r4]
	lsrs r0, r0, #0x16
	cmp r1, r0
	bhs _08026A06
	bl PlayRingCollectSE
_08026A06:
	ldrh r0, [r7, #0xe]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	strh r0, [r4]
	b _08026AA0
_08026A10:
	cmp sb, r4
	beq _08026A32
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	add r0, sl
	mov r1, ip
	lsls r5, r1, #0x10
	cmp sb, r0
	bne _08026AA0
_08026A32:
	mov r2, r8
	ldrb r0, [r2, #4]
	mov r1, ip
	lsls r5, r1, #0x10
	cmp r0, #1
	beq _08026AA0
	mov r4, r8
	adds r4, #0xac
	ldrh r0, [r7, #0xe]
	lsls r0, r0, #0x16
	ldrh r1, [r4]
	lsrs r0, r0, #0x16
	cmp r1, r0
	bhs _08026AA0
	mov r0, r8
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08026AA0
	adds r6, r1, #0
	bl PlayRingCollectSE
	ldrh r0, [r7, #0xe]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	strh r0, [r4]
	mov r2, r8
	ldrh r0, [r2, #0xe]
	cmp r0, #0x48
	beq _08026AA0
	ldrh r0, [r4]
	movs r1, #0x64
	bl Div
	adds r4, r0, #0
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	cmp r4, r0
	beq _08026AA0
	mov r1, r8
	ldrb r0, [r1, #3]
	cmp r0, #5
	bne _08026AA0
	movs r0, #1
	bl AddLives
	b _08026AA0
_08026A94:
	ldrh r0, [r7, #0xe]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	strh r0, [r4, #0x30]
	mov r2, ip
	lsls r5, r2, #0x10
_08026AA0:
	asrs r0, r5, #0x10
	bl sub_8026B10
_08026AA6:
	ldrh r0, [r7]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
