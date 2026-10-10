.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r3, _08026280 @ =gMultiSioSend
	ldr r0, _08026284 @ =gStageData
	ldrb r1, [r0, #3]
	adds r5, r0, #0
	cmp r1, #7
	bne _08026272
	ldrh r1, [r3]
	ldr r0, _08026288 @ =0x0000600E
	cmp r1, r0
	bne _08026272
	b _0802646E
_08026272:
	ldrb r1, [r5, #4]
	cmp r1, #4
	bne _0802628C
	bl sub_8026720
	b _0802646E
	.align 2, 0
_08026280: .4byte gMultiSioSend
_08026284: .4byte gStageData
_08026288: .4byte 0x0000600E
_0802628C:
	ldrh r2, [r3]
	ldr r0, _080262AC @ =0x000068FC
	cmp r2, r0
	bne _08026296
	b _0802646E
_08026296:
	cmp r1, #5
	bne _080262B4
	ldr r1, _080262B0 @ =0x000068E0
	cmp r2, r1
	beq _080262E8
	subs r0, #0x14
	cmp r2, r0
	beq _080262E8
	strh r1, [r3]
	b _080262E8
	.align 2, 0
_080262AC: .4byte 0x000068FC
_080262B0: .4byte 0x000068E0
_080262B4:
	cmp r1, #8
	bne _080262C0
	ldr r0, _080262BC @ =0x000068FA
	b _080262E6
	.align 2, 0
_080262BC: .4byte 0x000068FA
_080262C0:
	cmp r1, #1
	bne _080262CC
	ldr r0, _080262C8 @ =0x00006801
	b _080262E6
	.align 2, 0
_080262C8: .4byte 0x00006801
_080262CC:
	cmp r1, #2
	bne _080262D8
	ldr r0, _080262D4 @ =0x00006802
	b _080262E6
	.align 2, 0
_080262D4: .4byte 0x00006802
_080262D8:
	cmp r1, #7
	bne _080262E4
	ldr r0, _080262E0 @ =0x000068FE
	b _080262E6
	.align 2, 0
_080262E0: .4byte 0x000068FE
_080262E4:
	ldr r0, _080262FC @ =0x00006810
_080262E6:
	strh r0, [r3]
_080262E8:
	ldr r0, [r5, #0x1c]
	strh r0, [r3, #2]
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	strh r0, [r3, #4]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bge _08026300
	movs r0, #0
	b _08026302
	.align 2, 0
_080262FC: .4byte 0x00006810
_08026300:
	asrs r0, r0, #8
_08026302:
	strh r0, [r3, #6]
	ldr r0, [r4, #4]
	str r0, [r3, #8]
	ldrh r0, [r4, #0x34]
	ldr r1, _08026340 @ =0x000007FF
	ands r1, r0
	ldrh r2, [r3, #0xc]
	ldr r0, _08026344 @ =0xFFFFF800
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #0xc]
	ldrh r1, [r4, #0x36]
	lsls r1, r1, #3
	ldrb r2, [r3, #0xd]
	movs r0, #7
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #0xd]
	ldrb r0, [r5, #3]
	cmp r0, #7
	beq _08026350
	cmp r0, #5
	bne _08026348
	ldrb r0, [r5, #0xa]
	cmp r0, #8
	bne _08026348
	adds r0, r5, #0
	adds r0, #0x8c
	ldrh r0, [r0]
	b _08026352
	.align 2, 0
_08026340: .4byte 0x000007FF
_08026344: .4byte 0xFFFFF800
_08026348:
	adds r0, r5, #0
	adds r0, #0xac
	ldrh r0, [r0]
	b _08026352
_08026350:
	ldrh r0, [r4, #0x30]
_08026352:
	ldr r1, _080263AC @ =0x000003FF
	ands r1, r0
	ldrh r2, [r3, #0xe]
	ldr r0, _080263B0 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #0xe]
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r1, [r0]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	ldrb r2, [r3, #0xf]
	movs r0, #0x7d
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r1, [r1]
	movs r2, #1
	ands r1, r2
	lsls r1, r1, #7
	movs r2, #0x7f
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #0xf]
	ldrh r0, [r4, #0x1c]
	lsrs r0, r0, #8
	strb r0, [r3, #0x10]
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	strb r0, [r3, #0x11]
	ldrh r1, [r3]
	ldr r0, _080263B4 @ =0x000068E0
	cmp r1, r0
	beq _080263A6
	adds r0, #8
	cmp r1, r0
	bne _080263C4
_080263A6:
	bl sub_80278C4
	b _0802646E
	.align 2, 0
_080263AC: .4byte 0x000003FF
_080263B0: .4byte 0xFFFFFC00
_080263B4: .4byte 0x000068E0
_080263B8:
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r0, r0, r6
	movs r1, #0xff
	strb r1, [r0]
	b _08026454
_080263C4:
	ldr r2, _08026460 @ =gUnknown_03001CC0
	ldrb r0, [r2, #1]
	mov r8, r2
	cmp r0, #0
	bne _0802646A
	ldrb r4, [r2, #2]
	adds r0, r4, #0
	cmp r0, #0xff
	beq _08026464
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	lsls r0, r0, #6
	orrs r0, r4
	strb r0, [r3, #0x12]
	ldrb r0, [r2, #3]
	strb r0, [r3, #0x13]
	ldrb r0, [r2, #4]
	strb r0, [r3, #0x14]
	ldrb r0, [r2, #5]
	strb r0, [r3, #0x15]
	ldrb r0, [r2, #6]
	strb r0, [r3, #0x16]
	movs r0, #6
	strb r0, [r2, #1]
	movs r1, #0
	adds r6, r2, #2
	adds r4, r2, #3
	mov ip, r4
	adds r7, r2, #4
_08026404:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r5, r2, #1
	lsls r0, r5, #2
	adds r3, r0, r5
	adds r0, r3, r6
	ldrb r4, [r0]
	adds r0, r4, #0
	cmp r0, #0xff
	beq _080263B8
	lsls r1, r2, #2
	adds r1, r1, r2
	adds r0, r1, r6
	strb r4, [r0]
	mov r0, ip
	adds r2, r1, r0
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, r1, r7
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r2]
	mov r0, r8
	adds r0, #5
	adds r2, r1, r0
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r2]
	mov r0, r8
	adds r0, #6
	adds r1, r1, r0
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r1]
	lsls r0, r5, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble _08026404
_08026454:
	mov r1, r8
	adds r1, #0x25
	movs r0, #0xff
	strb r0, [r1]
	b _0802646E
	.align 2, 0
_08026460: .4byte gUnknown_03001CC0
_08026464:
	movs r0, #0xff
	strb r0, [r3, #0x12]
	b _0802646E
_0802646A:
	subs r0, #1
	strb r0, [r2, #1]
_0802646E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
