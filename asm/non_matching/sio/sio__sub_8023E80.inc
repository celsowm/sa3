.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023EE8
	ldr r0, _08023EA0 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08023EA4 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08023EA8
	movs r0, #4
	rsbs r0, r0, #0
	b _08023EE8
	.align 2, 0
_08023EA0: .4byte gMultiSioStatusFlags
_08023EA4: .4byte 0x00000C0C
_08023EA8:
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _08023EB4
	movs r0, #0
	b _08023EE8
_08023EB4:
	ldr r2, _08023EF0 @ =gMultiSioRecv+1*0x18
	movs r4, #0
	ldrh r1, [r2]
	ldr r3, _08023EF4 @ =0xFFFF93F9
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08023ECA
	ldrb r0, [r2, #4]
	adds r4, r0, #1
_08023ECA:
	ldr r0, _08023EF8 @ =0x00006C08
	cmp r1, r0
	bne _08023EDC
	movs r1, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08023EDC:
	movs r0, #0
	movs r1, #0xff
	bl sub_8024394
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_08023EE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08023EF0: .4byte gMultiSioRecv+1*0x18
_08023EF4: .4byte 0xFFFF93F9
_08023EF8: .4byte 0x00006C08

.syntax divided
