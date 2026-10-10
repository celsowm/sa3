.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023E6C
	ldr r0, _08023E24 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08023E28 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08023E2C
	movs r0, #4
	rsbs r0, r0, #0
	b _08023E6C
	.align 2, 0
_08023E24: .4byte gMultiSioStatusFlags
_08023E28: .4byte 0x00000C0C
_08023E2C:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08023E38
	movs r0, #0
	b _08023E6C
_08023E38:
	ldr r2, _08023E74 @ =gMultiSioRecv
	movs r4, #0
	ldrh r1, [r2]
	ldr r3, _08023E78 @ =0xFFFF93FD
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08023E4E
	ldrb r0, [r2, #4]
	adds r4, r0, #1
_08023E4E:
	ldr r0, _08023E7C @ =0x00006C04
	cmp r1, r0
	bne _08023E60
	movs r1, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08023E60:
	movs r0, #1
	movs r1, #0xff
	bl sub_8024354
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_08023E6C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08023E74: .4byte gMultiSioRecv
_08023E78: .4byte 0xFFFF93FD
_08023E7C: .4byte 0x00006C04

.syntax divided
