.syntax unified
.text
	push {r4, r5, lr}
	ldr r0, _080A0664 @ =gCurTask
	ldr r2, [r0]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	movs r5, #0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A066C
	ldr r0, _080A0668 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A06DA
	.align 2, 0
_080A0664: .4byte gCurTask
_080A0668: .4byte Task_80A14AC
_080A066C:
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
	bl sub_80A16EC
	cmp r0, #1
	bne _080A0696
	movs r5, #1
_080A0696:
	ldr r1, [r4, #0x68]
	movs r2, #0x91
	lsls r2, r2, #8
	cmp r1, r2
	ble _080A06AC
	ldr r0, _080A06B4 @ =0xFFFFFA00
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r0, _080A06B8 @ =0x000090FF
	cmp r1, r0
	bgt _080A06BC
_080A06AC:
	str r2, [r4, #0x68]
	movs r0, #1
	b _080A06BE
	.align 2, 0
_080A06B4: .4byte 0xFFFFFA00
_080A06B8: .4byte 0x000090FF
_080A06BC:
	movs r0, #0
_080A06BE:
	cmp r0, #1
	bne _080A06C8
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A06C8:
	cmp r5, #2
	bne _080A06DA
	ldr r1, [r4, #0x14]
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080A06E0 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A06E4 @ =sub_80A04D8
	str r0, [r1, #8]
_080A06DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A06E0: .4byte gCurTask
_080A06E4: .4byte sub_80A04D8

.syntax divided
