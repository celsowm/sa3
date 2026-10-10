.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08025018
	ldr r0, _08025000 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08025010
	ldr r3, _08025004 @ =gMultiSioRecv
	ldr r1, _08025008 @ =0xFFFF99F9
	adds r0, r1, #0
	ldrh r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08025010
	movs r1, #0
	ldr r5, _0802500C @ =gUnknown_030010AC
	adds r4, r3, #0
	adds r4, #0xf
_08024FC0:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r5
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024FC0
	ldrh r2, [r3, #0xc]
	adds r0, r2, #0
	asrs r0, r6
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08025010
	movs r0, #0x10
	lsls r0, r6
	ands r2, r0
	cmp r2, #0
	beq _08025010
	mov r0, r8
	adds r0, #0xf
	adds r0, r0, r6
	movs r1, #0xff
	strb r1, [r0]
	movs r0, #2
	b _08025018
	.align 2, 0
_08025000: .4byte gMultiSioStatusFlags
_08025004: .4byte gMultiSioRecv
_08025008: .4byte 0xFFFF99F9
_0802500C: .4byte gUnknown_030010AC
_08025010:
	adds r0, r7, #0
	bl sub_80257AC
	movs r0, #0
_08025018:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
