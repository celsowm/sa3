.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	ldr r0, _08081B90 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r1, r0
	movs r6, #0
_08081B42:
	lsls r0, r6, #2
	adds r1, r5, #0
	adds r1, #0x20
	adds r1, r1, r0
	ldr r4, [r1]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _08081BA4
	ldr r0, [r4, #4]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08081B94
	adds r0, r5, #0
	adds r0, #0x7c
	ldr r1, [r4, #0x6c]
	cmp r1, r0
	beq _08081B7C
	adds r0, #0x28
	cmp r1, r0
	beq _08081B7C
	adds r0, #0x28
	cmp r1, r0
	beq _08081B7C
	adds r0, #0x28
	cmp r1, r0
	bne _08081BA4
_08081B7C:
	str r4, [sp]
	mov r0, sb
	mov r2, r8
	asrs r1, r2, #8
	asrs r2, r7, #8
	movs r3, #0
	bl sub_8020CE0
	b _08081BA4
	.align 2, 0
_08081B90: .4byte gCurTask
_08081B94:
	str r4, [sp]
	mov r0, sb
	mov r2, r8
	asrs r1, r2, #8
	asrs r2, r7, #8
	movs r3, #0
	bl sub_8020CE0
_08081BA4:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bls _08081B42
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
