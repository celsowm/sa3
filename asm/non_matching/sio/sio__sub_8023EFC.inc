.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023F50
	ldr r0, _08023F1C @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08023F20 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08023F24
	movs r0, #4
	rsbs r0, r0, #0
	b _08023F50
	.align 2, 0
_08023F1C: .4byte gMultiSioStatusFlags
_08023F20: .4byte 0x00000C0C
_08023F24:
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _08023F30
	movs r0, #0
	b _08023F50
_08023F30:
	ldr r0, _08023F58 @ =gMultiSioRecv+1*0x18
	movs r4, #0
	ldrh r1, [r0]
	ldr r0, _08023F5C @ =0x00006C08
	cmp r1, r0
	beq _08023F42
	adds r0, #2
	cmp r1, r0
	bne _08023F44
_08023F42:
	movs r4, #0x10
_08023F44:
	movs r0, #0
	movs r1, #0xff
	bl sub_80243C4
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_08023F50:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08023F58: .4byte gMultiSioRecv+1*0x18
_08023F5C: .4byte 0x00006C08

.syntax divided
