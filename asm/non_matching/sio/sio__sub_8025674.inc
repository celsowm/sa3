.syntax unified
.text
	push {r4, lr}
	ldr r0, _0802569C @ =gUnknown_03001060
	ldrb r4, [r0, #7]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080256D2
	bl sub_8025D48
	cmp r4, #3
	beq _080256A0
	cmp r4, #7
	beq _080256A0
	cmp r4, #0xf
	beq _080256A0
_08025696:
	movs r0, #0
	b _080256D2
	.align 2, 0
_0802569C: .4byte gUnknown_03001060
_080256A0:
	movs r1, #0
	ldr r3, _080256D8 @ =0x0000660F
_080256A4:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r4, #0
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080256C4
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _080256DC @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _08025696
_080256C4:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080256A4
	movs r0, #1
_080256D2:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080256D8: .4byte 0x0000660F
_080256DC: .4byte gMultiSioRecv

.syntax divided
