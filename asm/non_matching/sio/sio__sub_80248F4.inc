.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r4, #0
	ldr r0, _08024974 @ =gUnknown_03001060
	ldrb r7, [r0, #7]
	ldr r1, _08024978 @ =gMultiSioSend
	mov ip, r1
	movs r2, #0
	ldr r1, _0802497C @ =0x00006605
	mov sb, r1
	adds r0, #0x4c
	mov r8, r0
	movs r6, #0xff
_08024912:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	adds r1, r7, #0
	asrs r1, r3
	movs r0, #1
	ands r1, r0
	adds r5, r2, #0
	cmp r1, #0
	beq _08024958
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	ldr r1, _08024980 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrb r2, [r0, #3]
	ldrh r0, [r0]
	cmp r0, sb
	bne _08024958
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r0, r2
	orrs r4, r0
	lsls r0, r4, #0x10
	lsrs r4, r0, #0x10
	mov r0, r8
	adds r3, r2, r0
	mov r1, ip
	adds r1, #0xf
	adds r1, r1, r2
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	ldrb r0, [r3]
	orrs r0, r6
	strb r0, [r3]
_08024958:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r5, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08024912
	adds r0, r4, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08024974: .4byte gUnknown_03001060
_08024978: .4byte gMultiSioSend
_0802497C: .4byte 0x00006605
_08024980: .4byte gMultiSioRecv

.syntax divided
