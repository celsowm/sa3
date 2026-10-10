.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r5, r3, #0
	ldr r4, _08025E60 @ =gUnknown_03001060
	movs r6, #0
	ldr r1, _08025E64 @ =gMultiSioStatusFlags
	ldr r2, [r1]
	movs r0, #0x81
	ands r0, r2
	adds r7, r4, #0
	mov ip, r1
	cmp r0, #0
	beq _08025E6C
	movs r0, #1
	lsls r0, r3
	ands r2, r0
	cmp r2, #0
	bne _08025E68
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb4
	bls _08025E6C
	movs r0, #2
	rsbs r0, r0, #0
	b _08025EE4
	.align 2, 0
_08025E60: .4byte gUnknown_03001060
_08025E64: .4byte gMultiSioStatusFlags
_08025E68:
	adds r0, r5, r4
	strb r6, [r0]
_08025E6C:
	mov r0, ip
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08025E7C
	movs r6, #1
_08025E7C:
	ldr r3, _08025EC4 @ =gMultiSioRecv
	ldrb r2, [r7, #7]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne _08025EAC
	cmp r6, #0
	beq _08025E9C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08025E9C
	ldrh r0, [r3]
	cmp r0, #0
	bne _08025EAC
_08025E9C:
	cmp r2, #0
	beq _08025EC8
	mov r1, ip
	ldr r0, [r1]
	movs r1, #0xf
	ands r0, r1
	cmp r2, r0
	beq _08025EC8
_08025EAC:
	ldrb r0, [r4, #6]
	adds r0, #1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	movs r0, #4
	ldrsb r0, [r4, r0]
	adds r0, #8
	cmp r1, r0
	blt _08025ECC
	movs r0, #1
	rsbs r0, r0, #0
	b _08025EE4
	.align 2, 0
_08025EC4: .4byte gMultiSioRecv
_08025EC8:
	movs r0, #0
	strb r0, [r4, #6]
_08025ECC:
	ldrb r0, [r4, #4]
	movs r1, #4
	ldrsb r1, [r4, r1]
	cmp r1, #0
	ble _08025EDA
	subs r0, #1
	b _08025EE0
_08025EDA:
	cmp r1, #0
	bge _08025EE2
	adds r0, #1
_08025EE0:
	strb r0, [r4, #4]
_08025EE2:
	movs r0, #0
_08025EE4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
