.syntax unified
.text
	push {r4, lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802560E
	ldr r0, _080255F8 @ =gUnknown_03001060
	adds r4, r0, #0
	adds r4, #0x50
	ldrb r0, [r4]
	bl sub_8025D20
	ldr r0, _080255FC @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0802560C
	ldr r2, _08025600 @ =gMultiSioRecv
	ldrh r1, [r2]
	ldr r3, _08025604 @ =0xFFFF99F3
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0802560C
	ldrb r0, [r2, #5]
	strh r0, [r4]
	lsls r1, r1, #0x10
	ldr r0, _08025608 @ =0x660E0000
	cmp r1, r0
	bne _0802560C
	movs r0, #1
	b _0802560E
	.align 2, 0
_080255F8: .4byte gUnknown_03001060
_080255FC: .4byte gMultiSioStatusFlags
_08025600: .4byte gMultiSioRecv
_08025604: .4byte 0xFFFF99F3
_08025608: .4byte 0x660E0000
_0802560C:
	movs r0, #0
_0802560E:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
