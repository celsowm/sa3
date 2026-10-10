.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A0800 @ =gCurTask
	ldr r2, [r6]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	movs r5, #0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0808
	ldr r0, _080A0804 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A0872
	.align 2, 0
_080A0800: .4byte gCurTask
_080A0804: .4byte Task_80A14AC
_080A0808:
	adds r0, r4, #0
	bl sub_80A137C
	adds r0, r4, #0
	bl sub_80A10B0
	adds r0, r4, #0
	bl sub_80A1110
	adds r0, r4, #0
	bl sub_80A11B8
	adds r0, r4, #0
	movs r1, #0x5a
	bl sub_80A1740
	cmp r0, #1
	bne _080A082E
	movs r5, #1
_080A082E:
	adds r0, r4, #0
	bl sub_80A1768
	cmp r0, #1
	bne _080A083E
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A083E:
	adds r0, r4, #0
	bl sub_80A185C
	cmp r0, #1
	bne _080A084E
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A084E:
	adds r0, r4, #0
	bl sub_80A182C
	cmp r0, #1
	bne _080A085E
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080A085E:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x4c]
	adds r0, #5
	str r0, [r4, #0x64]
	cmp r5, #4
	bne _080A0872
	ldr r1, [r6]
	ldr r0, _080A0878 @ =sub_80A087C
	str r0, [r1, #8]
_080A0872:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A0878: .4byte sub_80A087C

.syntax divided
