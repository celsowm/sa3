.syntax unified
.text
	push {r4, r5, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023FCE
	ldr r0, _08023F80 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08023F84 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08023F88
	movs r0, #4
	rsbs r0, r0, #0
	b _08023FCE
	.align 2, 0
_08023F80: .4byte gMultiSioStatusFlags
_08023F84: .4byte 0x00000C0C
_08023F88:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08023F94
	movs r0, #0
	b _08023FCE
_08023F94:
	ldr r4, _08023FD4 @ =gMultiSioRecv
	movs r5, #0
	ldr r1, _08023FD8 @ =0xFFFF93F5
	adds r0, r1, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08023FAA
	ldrb r5, [r4, #7]
_08023FAA:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl sub_80243E4
	ldrh r1, [r4]
	ldr r0, _08023FDC @ =0x00006C0C
	cmp r1, r0
	bne _08023FCA
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r0, #0
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_08023FCA:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
_08023FCE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08023FD4: .4byte gMultiSioRecv
_08023FD8: .4byte 0xFFFF93F5
_08023FDC: .4byte 0x00006C0C

.syntax divided
