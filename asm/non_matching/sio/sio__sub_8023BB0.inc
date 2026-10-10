.syntax unified
.text
	push {r4, r5, lr}
	ldr r1, _08023BDC @ =gStageData
	ldr r0, _08023BE0 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023C4C
	ldr r0, _08023BE4 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	ldr r1, _08023BE8 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08023BEC
	movs r0, #4
	rsbs r0, r0, #0
	b _08023C4C
	.align 2, 0
_08023BDC: .4byte gStageData
_08023BE0: .4byte 0x04000128
_08023BE4: .4byte gMultiSioStatusFlags
_08023BE8: .4byte 0x00000C0C
_08023BEC:
	ldr r0, _08023C08 @ =gMultiSioSend
	ldr r1, _08023C0C @ =gUnknown_03001060
	ldrb r4, [r0, #2]
	strb r4, [r1, #7]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_8024324
	lsls r4, r4, #0x10
	asrs r0, r4, #0x10
	cmp r0, #3
	beq _08023C14
	b _08023C4C
	.align 2, 0
_08023C08: .4byte gMultiSioSend
_08023C0C: .4byte gUnknown_03001060
_08023C10:
	adds r0, r3, #0
	b _08023C4C
_08023C14:
	movs r1, #0
	movs r3, #3
	ldr r5, _08023C54 @ =0x00006C02
_08023C1A:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r3, #0
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08023C3A
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08023C58 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	bne _08023C10
_08023C3A:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08023C1A
	movs r1, #0x10
	asrs r0, r4, #0x10
	orrs r0, r1
_08023C4C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08023C54: .4byte 0x00006C02
_08023C58: .4byte gMultiSioRecv

.syntax divided
