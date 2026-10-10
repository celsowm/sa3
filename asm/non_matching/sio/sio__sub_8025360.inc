.syntax unified
.text
	push {r4, lr}
	ldr r0, _08025388 @ =gUnknown_03001060
	ldrb r4, [r0, #7]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080253BE
	bl sub_8025D10
	cmp r4, #3
	beq _0802538C
	cmp r4, #7
	beq _0802538C
	cmp r4, #0xf
	beq _0802538C
_08025382:
	movs r0, #0
	b _080253BE
	.align 2, 0
_08025388: .4byte gUnknown_03001060
_0802538C:
	movs r1, #0
	ldr r3, _080253C4 @ =0x0000660C
_08025390:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r4, #0
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080253B0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _080253C8 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _08025382
_080253B0:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08025390
	movs r0, #1
_080253BE:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080253C4: .4byte 0x0000660C
_080253C8: .4byte gMultiSioRecv

.syntax divided
