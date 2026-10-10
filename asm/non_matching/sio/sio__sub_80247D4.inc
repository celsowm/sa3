.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _08024840 @ =gUnknown_03001060
	ldrb r0, [r0, #7]
	str r0, [sp]
	movs r7, #0
	movs r5, #0
	ldr r0, _08024844 @ =gMultiSioSend
	mov sl, r0
	movs r2, #0
	mov r6, sl
	adds r6, #0xf
	adds r3, r6, #0
	movs r4, #1
_080247F8:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _08024810
	adds r0, r4, #0
	ldrb r1, [r1]
	lsls r0, r1
	orrs r7, r0
	lsls r0, r7, #0x18
	lsrs r7, r0, #0x18
_08024810:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080247F8
	movs r2, #0
	ldr r0, _08024848 @ =gUnknown_030010AC
	mov sb, r0
	movs r0, #0xff
	mov r8, r0
_08024826:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	ldr r1, [sp]
	asrs r1, r3
	movs r0, #1
	ands r1, r0
	mov ip, r2
	cmp r1, #0
	beq _080248D4
	cmp r3, #0
	bne _0802484C
	mov r1, sl
	b _08024856
	.align 2, 0
_08024840: .4byte gUnknown_03001060
_08024844: .4byte gMultiSioSend
_08024848: .4byte gUnknown_030010AC
_0802484C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	ldr r1, _08024880 @ =gMultiSioRecv
	adds r1, r0, r1
_08024856:
	ldrb r0, [r1, #3]
	ldrh r3, [r1]
	ldr r2, _08024884 @ =0x00006604
	cmp r3, r2
	beq _08024866
	adds r2, #4
	cmp r3, r2
	bne _08024888
_08024866:
	mov r2, sb
	adds r3, r0, r2
	adds r2, r6, r0
	adds r1, #0xf
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r1, [r1]
	mov r0, r8
	ands r0, r1
	strb r0, [r3]
	b _080248D4
	.align 2, 0
_08024880: .4byte gMultiSioRecv
_08024884: .4byte 0x00006604
_08024888:
	adds r3, r0, #0
	adds r0, r1, #0
	adds r0, #0xf
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080248A0
	adds r2, r6, r3
	ldrb r1, [r2]
	mov r0, r8
	orrs r0, r1
	b _080248D2
_080248A0:
	ldrb r4, [r1]
	adds r0, r7, #0
	asrs r0, r4
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080248BA
	movs r0, #0x10
	lsls r0, r3
	orrs r5, r0
	lsls r0, r5, #0x10
	lsrs r5, r0, #0x10
	b _080248D4
_080248BA:
	adds r0, r2, #0
	lsls r0, r3
	orrs r5, r0
	lsls r0, r5, #0x10
	lsrs r5, r0, #0x10
	mov r0, sb
	adds r2, r3, r0
	adds r0, r6, r3
	strb r4, [r0]
	ldrb r1, [r1]
	mov r0, r8
	ands r0, r1
_080248D2:
	strb r0, [r2]
_080248D4:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024826
	adds r0, r5, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

.syntax divided
