.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A144C @ =gCurTask
	ldr r2, [r5]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A1454
	ldr r0, _080A1450 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A148E
	.align 2, 0
_080A144C: .4byte gCurTask
_080A1450: .4byte Task_80A14AC
_080A1454:
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
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x4c]
	ldr r0, [r4, #0x14]
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4, #0x18]
	strb r1, [r0]
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	strb r0, [r4, #3]
	ldr r1, [r5]
	ldr r0, _080A1494 @ =Task_809FEB0
	str r0, [r1, #8]
_080A148E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A1494: .4byte Task_809FEB0

.syntax divided
