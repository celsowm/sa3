.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	cmp r2, #1
	beq _0807F382
	cmp r2, #1
	ble _0807F34E
	cmp r2, #2
	beq _0807F3B6
_0807F34E:
	cmp r3, #0
	bne _0807F366
	mov r1, ip
	adds r1, #0x24
	movs r0, #0xf3
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xed
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	b _0807F378
_0807F366:
	mov r1, ip
	adds r1, #0x24
	movs r0, #0xf8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xed
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xd
_0807F378:
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x1e
	strb r0, [r1]
	b _0807F42C
_0807F382:
	cmp r3, #0
	bne _0807F39A
	mov r1, ip
	adds r1, #0x24
	movs r0, #0xe2
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xf3
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x13
	b _0807F3AC
_0807F39A:
	mov r1, ip
	adds r1, #0x24
	movs r0, #0xed
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xf3
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x1e
_0807F3AC:
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	b _0807F42C
_0807F3B6:
	cmp r3, #0
	bne _0807F3D2
	mov r4, ip
	adds r4, #0x24
	movs r0, #0xe2
	strb r0, [r4]
	mov r3, ip
	adds r3, #0x25
	movs r0, #0xf3
	strb r0, [r3]
	mov r2, ip
	adds r2, #0x26
	movs r0, #0x13
	b _0807F3E8
_0807F3D2:
	mov r4, ip
	adds r4, #0x24
	movs r0, #0xed
	strb r0, [r4]
	mov r3, ip
	adds r3, #0x25
	movs r0, #0xf3
	strb r0, [r3]
	mov r2, ip
	adds r2, #0x26
	movs r0, #0x1e
_0807F3E8:
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r5, r1, #0
	movs r1, #0
	ldrsb r1, [r4, r1]
	movs r7, #2
	ldrsh r0, [r6, r7]
	muls r0, r1, r0
	asrs r0, r0, #8
	strb r0, [r4]
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r4, #4
	ldrsh r0, [r6, r4]
	muls r0, r1, r0
	asrs r0, r0, #8
	strb r0, [r3]
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r7, #2
	ldrsh r0, [r6, r7]
	muls r0, r1, r0
	asrs r0, r0, #8
	strb r0, [r2]
	movs r1, #0
	ldrsb r1, [r5, r1]
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	strb r0, [r5]
_0807F42C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
