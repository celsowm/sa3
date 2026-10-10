.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A01B8 @ =gCurTask
	ldr r2, [r6]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	movs r5, #0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A01C0
	ldr r0, _080A01BC @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A0210
	.align 2, 0
_080A01B8: .4byte gCurTask
_080A01BC: .4byte Task_80A14AC
_080A01C0:
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
	bl sub_80A1694
	cmp r0, #1
	bne _080A01EA
	movs r5, #1
_080A01EA:
	adds r0, r4, #0
	movs r1, #0x78
	bl sub_80A1740
	cmp r0, #1
	bne _080A01FC
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A01FC:
	cmp r5, #2
	bne _080A0210
	movs r0, #0x1d
	strb r0, [r4, #3]
	movs r0, #0x9b
	lsls r0, r0, #9
	str r0, [r4, #0x54]
	ldr r1, [r6]
	ldr r0, _080A0218 @ =Task_80A1430
	str r0, [r1, #8]
_080A0210:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A0218: .4byte Task_80A1430

.syntax divided
