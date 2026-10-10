.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080A0504 @ =gCurTask
	ldr r2, [r0]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, _080A0508 @ =gStageData
	ldrb r7, [r0, #6]
	movs r0, #0
	mov r8, r0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0510
	ldr r0, _080A050C @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A0638
	.align 2, 0
_080A0504: .4byte gCurTask
_080A0508: .4byte gStageData
_080A050C: .4byte Task_80A14AC
_080A0510:
	adds r0, r4, #0
	bl sub_80A19C0
	adds r0, r4, #0
	bl sub_80A1A04
	adds r0, r4, #0
	bl sub_80A10B0
	adds r0, r4, #0
	bl sub_80A1110
	adds r0, r4, #0
	bl sub_80A11B8
	lsls r0, r7, #0x10
	lsrs r1, r0, #0x10
	adds r6, r0, #0
	cmp r1, #1
	bhi _080A0540
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r6, r1
	lsrs r7, r0, #0x10
_080A0540:
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080A0550
	ldr r0, [r4, #0x14]
	mov r1, r8
	strb r1, [r0]
	b _080A0638
_080A0550:
	movs r5, #0
	lsls r6, r7, #0x10
	ldr r0, _080A05A4 @ =gUnknown_030010AC
	mov sb, r0
	ldr r7, _080A05A8 @ =gUnknown_080D8F18
_080A055A:
	asrs r0, r6, #0x10
	cmp r0, r5
	beq _080A057C
	mov r0, sb
	adds r1, r5, r0
	ldr r0, [r4, #0x30]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r7
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _080A057C
	adds r0, r4, #0
	bl sub_80A1A28
_080A057C:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _080A055A
	ldr r1, [r4, #0x18]
	ldrb r0, [r1]
	cmp r0, #0x14
	bne _080A05B4
	ldr r0, [r4, #0x30]
	ldrb r0, [r0]
	strb r0, [r4, #1]
	ldrb r0, [r1]
	strb r0, [r4, #3]
	ldr r0, _080A05AC @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A05B0 @ =sub_80A06E8
	str r0, [r1, #8]
	b _080A0638
	.align 2, 0
_080A05A4: .4byte gUnknown_030010AC
_080A05A8: .4byte gUnknown_080D8F18
_080A05AC: .4byte gCurTask
_080A05B0: .4byte sub_80A06E8
_080A05B4:
	cmp r0, #0x13
	bne _080A05BE
	ldr r1, [r4, #0x14]
	movs r0, #1
	strb r0, [r1]
_080A05BE:
	ldrb r0, [r4, #1]
	ldr r1, [r4, #0x30]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	beq _080A0624
	ldr r0, [r4, #0x14]
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	bl sub_80A1694
	cmp r0, #1
	bne _080A05E6
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_080A05E6:
	adds r0, r4, #0
	bl sub_80A1938
	cmp r0, #1
	bne _080A05FA
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_080A05FA:
	mov r1, r8
	cmp r1, #2
	bne _080A0638
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r4, #0x4c]
	ldr r0, [r4, #0x30]
	ldrb r0, [r0]
	strb r0, [r4, #1]
	adds r0, r4, #0
	bl sub_80A0DC8
	ldr r0, _080A061C @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A0620 @ =sub_80A0644
	str r0, [r1, #8]
	b _080A0638
	.align 2, 0
_080A061C: .4byte gCurTask
_080A0620: .4byte sub_80A0644
_080A0624:
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x13
	bhi _080A0638
	adds r0, r4, #0
	bl sub_80A18E0
	adds r0, r4, #0
	bl sub_80A1030
_080A0638:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
