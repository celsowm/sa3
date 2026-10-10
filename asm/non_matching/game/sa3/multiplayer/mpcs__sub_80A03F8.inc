.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A0418 @ =gCurTask
	ldr r2, [r6]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	movs r5, #0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0420
	ldr r0, _080A041C @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A04C8
	.align 2, 0
_080A0418: .4byte gCurTask
_080A041C: .4byte Task_80A14AC
_080A0420:
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
	ldr r1, [r4, #0x18]
	ldrb r0, [r4, #3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080A04C8
	adds r0, r4, #0
	bl sub_80A1798
	cmp r0, #1
	bne _080A0454
	movs r5, #1
_080A0454:
	adds r0, r4, #0
	bl sub_80A17FC
	cmp r0, #1
	bne _080A0464
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A0464:
	adds r0, r4, #0
	bl sub_80A1668
	cmp r0, #1
	bne _080A0474
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A0474:
	adds r0, r4, #0
	bl sub_80A163C
	cmp r0, #1
	bne _080A0484
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A0484:
	adds r0, r4, #0
	bl sub_80A1908
	cmp r0, #1
	bne _080A0494
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A0494:
	cmp r5, #5
	bne _080A04C8
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	strb r0, [r4, #3]
	ldr r1, [r4, #0x14]
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080A04D0 @ =0x00010500
	str r0, [r4, #0x74]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x7c]
	movs r1, #0xb4
	lsls r1, r1, #8
	str r1, [r4, #0x6c]
	movs r0, #0xf0
	lsls r0, r0, #6
	str r0, [r4, #0x54]
	str r1, [r4, #0x4c]
	movs r0, #0x91
	lsls r0, r0, #8
	str r0, [r4, #0x68]
	ldr r1, [r6]
	ldr r0, _080A04D4 @ =sub_80A0644
	str r0, [r1, #8]
_080A04C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A04D0: .4byte 0x00010500
_080A04D4: .4byte sub_80A0644

.syntax divided
