.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A0364 @ =gCurTask
	ldr r2, [r6]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	movs r5, #0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A036C
	ldr r0, _080A0368 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A03EE
	.align 2, 0
_080A0364: .4byte gCurTask
_080A0368: .4byte Task_80A14AC
_080A036C:
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
	adds r0, r4, #0
	bl sub_80A1798
	cmp r0, #1
	bne _080A0396
	movs r5, #1
_080A0396:
	adds r0, r4, #0
	bl sub_80A17FC
	cmp r0, #1
	bne _080A03A6
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A03A6:
	adds r0, r4, #0
	bl sub_80A1668
	cmp r0, #1
	bne _080A03B6
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A03B6:
	adds r0, r4, #0
	bl sub_80A163C
	cmp r0, #1
	bne _080A03C6
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A03C6:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x4c]
	str r0, [r4, #0x64]
	cmp r5, #4
	bne _080A03EE
	adds r0, r4, #0
	bl sub_80A1908
	cmp r0, #1
	bne _080A03EE
	ldr r1, [r4, #0x18]
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	strb r0, [r4, #3]
	ldr r1, [r6]
	ldr r0, _080A03F4 @ =sub_80A03F8
	str r0, [r1, #8]
_080A03EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A03F4: .4byte sub_80A03F8

.syntax divided
