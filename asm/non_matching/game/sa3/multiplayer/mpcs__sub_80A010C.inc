.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A0128 @ =gCurTask
	ldr r2, [r5]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0130
	ldr r0, _080A012C @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A018A
	.align 2, 0
_080A0128: .4byte gCurTask
_080A012C: .4byte Task_80A14AC
_080A0130:
	adds r0, r4, #0
	bl sub_80A19C0
	adds r0, r4, #0
	bl sub_80A10B0
	adds r0, r4, #0
	bl sub_80A1110
	adds r0, r4, #0
	bl sub_80A1598
	cmp r0, #1
	bne _080A0168
	adds r0, r4, #0
	bl sub_80A1888
	adds r1, r0, #0
	cmp r1, #1
	bne _080A0168
	ldr r0, [r4, #0x14]
	strb r1, [r0]
	ldr r1, [r5]
	ldr r0, _080A0164 @ =Task_809FEB0
	b _080A0188
	.align 2, 0
_080A0164: .4byte Task_809FEB0
_080A0168:
	ldr r1, [r4, #0x18]
	ldrb r0, [r1]
	cmp r0, #0x23
	bne _080A018A
	movs r0, #0x1d
	strb r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	strb r0, [r4, #3]
	movs r0, #0x9b
	lsls r0, r0, #9
	str r0, [r4, #0x4c]
	str r0, [r4, #0x54]
	ldr r0, _080A0190 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A0194 @ =Task_80A13F4
_080A0188:
	str r0, [r1, #8]
_080A018A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0190: .4byte gCurTask
_080A0194: .4byte Task_80A13F4

.syntax divided
