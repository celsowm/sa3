.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	movs r5, #0
	ldr r1, _08024D0C @ =gStageData
	ldr r0, _08024D10 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r4, r0, #0
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08024C94
	b _08024DBA
_08024C94:
	ldr r2, _08024D14 @ =gMultiSioSend
	subs r1, r4, #2
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	adds r3, r4, #0
	mov r8, r1
	cmp r0, #1
	bhi _08024CA6
	adds r3, r0, #0
_08024CA6:
	ldr r1, _08024D18 @ =gUnknown_03001060
	adds r1, #0x4c
	adds r0, r3, r1
	mov r3, sb
	strb r3, [r0]
	movs r3, #0
	ldr r0, _08024D1C @ =gMultiSioStatusFlags
	mov ip, r0
	adds r7, r2, #0
	adds r7, #0xf
	adds r6, r1, #0
_08024CBC:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r7, r0
	adds r1, r0, r6
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024CBC
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08024D5C
	ldr r2, _08024D20 @ =gMultiSioRecv
	cmp r4, #1
	bhi _08024D30
	ldrh r1, [r2]
	ldr r2, _08024D24 @ =0xFFFF99FD
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08024CFA
	ldr r0, _08024D28 @ =0x00006606
	cmp r1, r0
	bne _08024D5C
_08024CFA:
	ldr r0, _08024D2C @ =0x00006604
	cmp r1, r0
	bne _08024D02
	movs r5, #1
_08024D02:
	ldr r0, _08024D28 @ =0x00006606
	cmp r1, r0
	bne _08024D5C
_08024D08:
	movs r5, #2
	b _08024D5C
	.align 2, 0
_08024D0C: .4byte gStageData
_08024D10: .4byte 0x04000128
_08024D14: .4byte gMultiSioSend
_08024D18: .4byte gUnknown_03001060
_08024D1C: .4byte gMultiSioStatusFlags
_08024D20: .4byte gMultiSioRecv
_08024D24: .4byte 0xFFFF99FD
_08024D28: .4byte 0x00006606
_08024D2C: .4byte 0x00006604
_08024D30:
	mov r3, r8
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08024D5C
	adds r0, r4, #0
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r2, r1, r2
	ldrh r1, [r2]
	ldr r2, _08024D6C @ =0xFFFF99F9
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08024D08
	ldr r0, _08024D70 @ =0x0000660A
	cmp r1, r0
	beq _08024D08
	movs r5, #1
_08024D5C:
	cmp r4, #1
	bhi _08024D74
	mov r3, sb
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	bl sub_8025714
	b _08024D7A
	.align 2, 0
_08024D6C: .4byte 0xFFFF99F9
_08024D70: .4byte 0x0000660A
_08024D74:
	movs r0, #0xff
	bl sub_8025714
_08024D7A:
	cmp r4, #1
	bne _08024D88
	movs r0, #0
	cmp r5, #2
	bne _08024DBA
	movs r0, #2
	b _08024DBA
_08024D88:
	cmp r4, #2
	beq _08024DB8
	cmp r4, #3
	bne _08024DB8
	cmp r5, #2
	bne _08024D98
	movs r0, #2
	b _08024DBA
_08024D98:
	ldr r2, _08024DAC @ =gMultiSioRecv+1*0x18
	ldrh r1, [r2]
	ldr r0, _08024DB0 @ =0x00006604
	cmp r1, r0
	beq _08024DA8
	adds r0, #2
	cmp r1, r0
	bne _08024DB4
_08024DA8:
	movs r0, #1
	b _08024DBA
	.align 2, 0
_08024DAC: .4byte gMultiSioRecv+1*0x18
_08024DB0: .4byte 0x00006604
_08024DB4:
	movs r0, #0
	b _08024DBA
_08024DB8:
	adds r0, r5, #0
_08024DBA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
