.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r7, _08024A00 @ =gUnknown_03001060
	ldrb r6, [r7, #7]
	ldr r0, _08024A04 @ =gStageData
	ldrb r4, [r0, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024A3E
	ldr r1, _08024A08 @ =gMultiSioSend
	adds r2, r1, #0
	adds r2, #0xf
	adds r0, r4, r2
	strb r5, [r0]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	movs r3, #0
	adds r4, r1, #0
	mov ip, r2
	adds r7, r0, #0
_080249B6:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov r1, ip
	adds r2, r1, r0
	adds r1, r0, r7
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080249B6
	movs r0, #0
	strh r0, [r4, #0xc]
	bl sub_80247D4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	bl sub_80248F4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	adds r0, r5, #0
	bl sub_8025714
	cmp r6, #3
	beq _08024A0C
	cmp r6, #7
	beq _08024A0C
	cmp r6, #0xf
	beq _08024A0C
_080249FA:
	movs r0, #0
	b _08024A3E
	.align 2, 0
_08024A00: .4byte gUnknown_03001060
_08024A04: .4byte gStageData
_08024A08: .4byte gMultiSioSend
_08024A0C:
	movs r3, #0
	ldr r4, _08024A44 @ =0x00006604
_08024A10:
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
	adds r0, r6, #0
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08024A30
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08024A48 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r4
	bne _080249FA
_08024A30:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024A10
	movs r0, #2
_08024A3E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08024A44: .4byte 0x00006604
_08024A48: .4byte gMultiSioRecv

.syntax divided
