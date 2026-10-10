.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r3, r1, #0
	movs r0, #0
	mov sb, r0
	adds r0, r3, #0
	adds r0, #0xe0
	ldr r6, [r0]
	movs r1, #0xc
	adds r1, r1, r6
	mov ip, r1
	ldr r0, [r3, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08086430
	mov r4, ip
	ldr r1, [r4, #0x20]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08086434
_08086430:
	movs r0, #0
	b _0808659E
_08086434:
	mov r0, r8
	ldr r1, [r0, #0x34]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080864EC
	ldr r5, [r3, #0x10]
	ldr r0, _080864D8 @ =gCamera
	adds r0, #0x6a
	asrs r5, r5, #8
	ldrh r0, [r0]
	adds r5, r5, r0
	mov r0, r8
	adds r0, #0xe3
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r0, #4
	subs r5, r5, r0
	ldr r4, [r3, #0x14]
	asrs r4, r4, #8
	movs r0, #0x88
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl sa2__sub_8004418
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r1, _080864DC @ =gUnknown_080D5D30
	mov r0, r8
	adds r0, #0xce
	ldrh r0, [r0]
	lsrs r0, r0, #5
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r0
	mov r1, r8
	lsls r1, r1, #6
	mov r8, r1
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r1, r0
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc
	bl __divsi3
	adds r1, r0, #0
	movs r0, #0x20
	subs r1, r0, r1
	mov r3, r8
	lsls r6, r6, #0x10
	asrs r0, r6, #0x10
	subs r2, r3, r0
	cmp r2, #0
	blt _080864E0
	cmp r2, r1
	ble _080864E6
	b _0808659C
	.align 2, 0
_080864D8: .4byte gCamera
_080864DC: .4byte gUnknown_080D5D30
_080864E0:
	subs r0, r0, r3
	cmp r0, r1
	bgt _0808659C
_080864E6:
	movs r4, #2
	mov sb, r4
	b _0808659C
_080864EC:
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _0808659C
	ldr r2, [r3, #0x10]
	asrs r2, r2, #8
	ldr r1, _080865AC @ =gCamera
	adds r0, r1, #0
	adds r0, #0x6a
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r2, r2, r0
	ldr r0, [r1]
	subs r2, r2, r0
	ldr r0, [r3, #0x14]
	asrs r0, r0, #8
	ldr r1, [r1, #4]
	subs r7, r0, r1
	mov r0, r8
	adds r0, #0x3c
	movs r4, #0
	ldrsb r4, [r0, r4]
	mov r1, r8
	ldr r0, [r1, #0x48]
	adds r3, r0, r4
	adds r0, r6, #0
	adds r0, #0x30
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r1, r2, r5
	cmp r3, r1
	bgt _08086542
	mov r0, r8
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r4
	adds r0, r3, r0
	cmp r0, r1
	bge _08086554
	cmp r3, r1
	blt _0808659C
_08086542:
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r5
	adds r0, r1, r0
	cmp r0, r3
	blt _0808659C
_08086554:
	mov r0, r8
	adds r0, #0x3d
	movs r3, #0
	ldrsb r3, [r0, r3]
	mov r4, r8
	ldr r0, [r4, #0x4c]
	adds r2, r0, r3
	mov r0, ip
	adds r0, #0x25
	movs r4, #0
	ldrsb r4, [r0, r4]
	adds r1, r7, r4
	cmp r2, r1
	bgt _08086586
	mov r0, r8
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r3
	adds r0, r2, r0
	cmp r0, r1
	bge _08086598
	cmp r2, r1
	blt _0808659C
_08086586:
	mov r0, ip
	adds r0, #0x27
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r4
	adds r0, r1, r0
	cmp r0, r2
	blt _0808659C
_08086598:
	movs r0, #1
	mov sb, r0
_0808659C:
	mov r0, sb
_0808659E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080865AC: .4byte gCamera

.syntax divided
