.syntax unified
.text
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r5, _08025478 @ =gUnknown_03001060
	ldrb r6, [r5, #7]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08025480
	b _080254BE
	.align 2, 0
_08025478: .4byte gUnknown_03001060
_0802547C:
	movs r0, #0
	b _080254BE
_08025480:
	adds r0, r5, #0
	adds r0, #0x50
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_8025D20
	movs r1, #0
	ldr r3, _080254C4 @ =0x0000660E
_08025490:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r6, #0
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080254B0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _080254C8 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _0802547C
_080254B0:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08025490
	movs r0, #1
_080254BE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080254C4: .4byte 0x0000660E
_080254C8: .4byte gMultiSioRecv

.syntax divided
