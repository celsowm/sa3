.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r5, _08025560 @ =gUnknown_03001060
	ldrb r4, [r5, #7]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802559E
	adds r0, r5, #0
	adds r0, #0x50
	ldrb r0, [r0]
	bl sub_8025D34
	cmp r4, #3
	beq _08025564
	cmp r4, #7
	beq _08025564
	cmp r4, #0xf
	beq _08025564
_0802555C:
	movs r0, #0
	b _0802559E
	.align 2, 0
_08025560: .4byte gUnknown_03001060
_08025564:
	movs r2, #0
	ldr r6, _080255A4 @ =0x0000660E
	ldr r5, _080255A8 @ =0x00006810
_0802556A:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	adds r1, r4, #0
	asrs r1, r3
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0802558E
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	ldr r1, _080255AC @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r6
	beq _0802558E
	cmp r0, r5
	bne _0802555C
_0802558E:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0802556A
	movs r0, #1
_0802559E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080255A4: .4byte 0x0000660E
_080255A8: .4byte 0x00006810
_080255AC: .4byte gMultiSioRecv

.syntax divided
