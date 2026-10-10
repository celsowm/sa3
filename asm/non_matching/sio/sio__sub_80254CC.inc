.syntax unified
.text
	push {r4, r5, lr}
	ldr r4, _080254E0 @ =gUnknown_03001060
	ldrb r5, [r4, #7]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080254E8
	b _08025526
	.align 2, 0
_080254E0: .4byte gUnknown_03001060
_080254E4:
	movs r0, #0
	b _08025526
_080254E8:
	adds r1, r4, #0
	adds r1, #0x50
	movs r0, #0
	strh r0, [r1]
	bl sub_8025D20
	movs r1, #0
	ldr r3, _0802552C @ =0x0000660D
_080254F8:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r5, #0
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08025518
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08025530 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _080254E4
_08025518:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080254F8
	movs r0, #1
_08025526:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802552C: .4byte 0x0000660D
_08025530: .4byte gMultiSioRecv

.syntax divided
