.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802566E
	ldr r0, _08025658 @ =gUnknown_03001060
	adds r4, r0, #0
	adds r4, #0x50
	ldrb r0, [r4]
	bl sub_8025D34
	ldr r0, _0802565C @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0802566C
	ldr r3, _08025660 @ =gMultiSioRecv
	ldrh r1, [r3]
	ldr r2, _08025664 @ =0x0000660E
	cmp r1, r2
	beq _0802564A
	ldr r0, _08025668 @ =0x0000680F
	cmp r1, r0
	bls _0802566C
_0802564A:
	ldrb r0, [r3, #5]
	strh r0, [r4]
	cmp r1, r2
	bne _0802566C
	movs r0, #1
	b _0802566E
	.align 2, 0
_08025658: .4byte gUnknown_03001060
_0802565C: .4byte gMultiSioStatusFlags
_08025660: .4byte gMultiSioRecv
_08025664: .4byte 0x0000660E
_08025668: .4byte 0x0000680F
_0802566C:
	movs r0, #0
_0802566E:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
