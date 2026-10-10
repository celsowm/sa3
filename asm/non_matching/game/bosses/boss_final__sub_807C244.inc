.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	str r3, [sp, #4]
	ldr r0, [sp, #0x2c]
	mov sl, r0
	ldr r0, _0807C2BC @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r1, r1, r0
	str r1, [sp, #8]
	movs r6, #0
	movs r5, #0
_0807C26E:
	lsls r0, r5, #2
	ldr r1, [sp, #8]
	adds r1, #0x20
	adds r1, r1, r0
	ldr r4, [r1]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807C356
	ldr r1, [r4, #4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0807C2CC
	ldr r0, [r4, #0x6c]
	cmp r0, sb
	bne _0807C2CC
	ldr r0, [r4, #0x10]
	ldr r2, [sp, #4]
	subs r0, r0, r2
	str r0, [r4, #0x10]
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	bne _0807C2C0
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r2, sl
	subs r0, r0, r2
	str r0, [r4, #0x14]
	movs r0, #1
	lsls r0, r5
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
	b _0807C2CC
	.align 2, 0
_0807C2BC: .4byte gCurTask
_0807C2C0:
	ldr r0, [r4, #0x14]
	mov r1, sl
	subs r0, r0, r1
	ldr r2, _0807C31C @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [r4, #0x14]
_0807C2CC:
	ldr r1, [r4, #0x10]
	mov r2, r8
	subs r0, r1, r2
	cmp r0, #0
	bge _0807C2DA
	mov r2, r8
	subs r0, r2, r1
_0807C2DA:
	asrs r0, r0, #8
	cmp r0, #0x40
	bgt _0807C356
	ldr r1, [r4, #0x14]
	subs r0, r1, r7
	cmp r0, #0
	bge _0807C2EA
	subs r0, r7, r1
_0807C2EA:
	asrs r0, r0, #8
	cmp r0, #0x40
	bgt _0807C356
	movs r0, #0
	str r0, [sp]
	mov r0, sb
	mov r2, r8
	asrs r1, r2, #8
	asrs r2, r7, #8
	adds r3, r4, #0
	bl sub_8020950
	adds r2, r0, #0
	movs r3, #0x80
	lsls r3, r3, #9
	ands r3, r2
	cmp r3, #0
	beq _0807C320
	lsls r1, r2, #0x18
	asrs r1, r1, #0x10
	ldr r0, [r4, #0x14]
	adds r0, r0, r1
	str r0, [r4, #0x14]
	b _0807C33C
	.align 2, 0
_0807C31C: .4byte 0xFFFFFE00
_0807C320:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r2
	cmp r0, #0
	beq _0807C33C
	ldr r1, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r0, r2, #0x18
	asrs r0, r0, #0x10
	adds r1, r1, r0
	str r1, [r4, #0x14]
	strh r3, [r4, #0x1a]
_0807C33C:
	movs r0, #0xc0
	lsls r0, r0, #0xc
	ands r0, r2
	cmp r0, #0
	beq _0807C356
	lsls r0, r2, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	ldr r1, [r4, #0x10]
	adds r1, r1, r0
	str r1, [r4, #0x10]
	movs r0, #0
	strh r0, [r4, #0x18]
_0807C356:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #1
	bls _0807C26E
	adds r0, r6, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
