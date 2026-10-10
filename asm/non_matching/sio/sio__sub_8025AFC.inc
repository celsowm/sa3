.syntax unified
.text
	push {lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08025B42
	ldr r0, _08025B30 @ =gUnknown_03001060
	adds r0, #0x50
	ldrb r0, [r0]
	bl sub_8025D20
	ldr r0, _08025B34 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08025B40
	ldr r0, _08025B38 @ =gMultiSioRecv
	ldrh r1, [r0]
	ldr r0, _08025B3C @ =0x0000660D
	cmp r1, r0
	bne _08025B40
	movs r0, #1
	b _08025B42
	.align 2, 0
_08025B30: .4byte gUnknown_03001060
_08025B34: .4byte gMultiSioStatusFlags
_08025B38: .4byte gMultiSioRecv
_08025B3C: .4byte 0x0000660D
_08025B40:
	movs r0, #0
_08025B42:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
