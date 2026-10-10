.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r1, _08023C8C @ =gStageData
	ldr r0, _08023C90 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	cmp r0, #0
	beq _08023CA4
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023D4E
	ldr r0, _08023C94 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08023C98 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08023C9C
	movs r0, #4
	rsbs r0, r0, #0
	b _08023D4E
	.align 2, 0
_08023C8C: .4byte gStageData
_08023C90: .4byte 0x04000128
_08023C94: .4byte gMultiSioStatusFlags
_08023C98: .4byte 0x00000C0C
_08023C9C:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08023CA8
_08023CA4:
	movs r0, #0
	b _08023D4E
_08023CA8:
	ldr r3, _08023CC8 @ =gMultiSioSend
	ldr r5, _08023CCC @ =gMultiSioRecv
	ldrh r2, [r5]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r2
	movs r1, #0xd8
	lsls r1, r1, #7
	cmp r0, r1
	beq _08023CD0
	cmp r2, #0
	beq _08023CD0
	movs r0, #5
	rsbs r0, r0, #0
	b _08023D4E
	.align 2, 0
_08023CC8: .4byte gMultiSioSend
_08023CCC: .4byte gMultiSioRecv
_08023CD0:
	ldrb r0, [r5, #2]
	strb r0, [r3, #2]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r1, [r5]
	ldr r0, _08023CE8 @ =0x00006C02
	cmp r1, r0
	bne _08023CEC
	movs r0, #0x10
	orrs r6, r0
	b _08023D48
	.align 2, 0
_08023CE8: .4byte 0x00006C02
_08023CEC:
	ldr r0, _08023D54 @ =0x00006C01
	cmp r1, r0
	bne _08023D48
	ldr r1, _08023D58 @ =gLoadedSaveGame
	ldrb r0, [r5, #3]
	strb r0, [r1, #0x10]
	ldrb r0, [r5, #4]
	strb r0, [r1, #0x11]
	ldrb r0, [r5, #5]
	adds r2, r1, #0
	adds r2, #0x36
	strb r0, [r2]
	movs r2, #0
	ldr r0, _08023D5C @ =gStageData
	mov ip, r0
	adds r3, r1, #0
	adds r7, r3, #0
	adds r7, #0x29
	adds r4, r5, #6
_08023D12:
	adds r1, r2, r7
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #6
	bls _08023D12
	movs r0, #1
	mov r1, ip
	strb r0, [r1, #9]
	ldrb r1, [r5, #0xe]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r3, r2
	strb r1, [r0]
	ldrb r1, [r5, #0xf]
	adds r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	ldrb r0, [r5, #0x10]
	adds r1, r3, #0
	adds r1, #0x32
	strb r0, [r1]
	ldrb r0, [r5, #0x11]
	strh r0, [r3, #0x34]
_08023D48:
	bl sub_8024314
	adds r0, r6, #0
_08023D4E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023D54: .4byte 0x00006C01
_08023D58: .4byte gLoadedSaveGame
_08023D5C: .4byte gStageData

.syntax divided
