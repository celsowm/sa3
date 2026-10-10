.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r5, #0
	ldr r1, _080250B8 @ =gStageData
	ldr r0, _080250BC @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r4, r0, #0
	cmp r4, #1
	bhi _08025046
	adds r4, #2
_08025046:
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080250E2
	ldr r2, _080250C0 @ =gMultiSioSend
	ldr r0, _080250C4 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080250D6
	ldr r6, _080250C8 @ =gMultiSioRecv
	ldr r1, _080250CC @ =0xFFFF99F9
	adds r0, r1, #0
	ldrh r1, [r6]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080250D6
	movs r1, #0
	adds r7, r2, #0
	adds r7, #0xf
	adds r5, r7, #0
	ldr r3, _080250D0 @ =gUnknown_030010AC
_0802507C:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r2, r5, r0
	adds r1, r0, r3
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0802507C
	ldrh r2, [r6, #0xc]
	adds r0, r2, #0
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080250D4
	movs r0, #0x10
	lsls r0, r4
	ands r2, r0
	cmp r2, #0
	beq _080250D4
	adds r1, r7, r4
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #2
	b _080250E2
	.align 2, 0
_080250B8: .4byte gStageData
_080250BC: .4byte 0x04000128
_080250C0: .4byte gMultiSioSend
_080250C4: .4byte gMultiSioStatusFlags
_080250C8: .4byte gMultiSioRecv
_080250CC: .4byte 0xFFFF99F9
_080250D0: .4byte gUnknown_030010AC
_080250D4:
	movs r5, #1
_080250D6:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl sub_8025808
	adds r0, r5, #0
_080250E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

.syntax divided
