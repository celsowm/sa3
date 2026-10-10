.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #3
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r1, r2
	adds r0, r0, r5
	mov r8, r0
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r0, r1, r2
	adds r6, r5, r0
	movs r7, #0
_0807C540:
	lsls r0, r7, #2
	adds r1, r5, #0
	adds r1, #0x20
	adds r1, r1, r0
	ldr r4, [r1]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807C5BA
	adds r0, r6, #0
	adds r0, #0x27
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	mov r1, r8
	ldr r2, [r1, #4]
	adds r0, r2, r0
	ldr r1, [r4, #0x14]
	adds r3, r2, #0
	cmp r1, r0
	ble _0807C5BA
	ldr r0, [r4, #4]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0807C5A8
	adds r0, r5, #0
	adds r0, #0x7c
	ldr r1, [r4, #0x6c]
	cmp r1, r0
	beq _0807C594
	adds r0, #0x28
	cmp r1, r0
	beq _0807C594
	adds r0, #0x28
	cmp r1, r0
	beq _0807C594
	adds r0, #0x28
	cmp r1, r0
	bne _0807C5BA
_0807C594:
	mov r2, r8
	ldr r1, [r2]
	asrs r1, r1, #8
	asrs r2, r3, #8
	str r4, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl sub_8020CE0
	b _0807C5BA
_0807C5A8:
	mov r0, r8
	ldr r1, [r0]
	asrs r1, r1, #8
	asrs r2, r2, #8
	str r4, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl sub_8020CE0
_0807C5BA:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #1
	bls _0807C540
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
