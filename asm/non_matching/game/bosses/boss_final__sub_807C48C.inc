.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0807C514 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r6, r1, r0
	movs r5, #0
_0807C49E:
	lsls r0, r5, #2
	adds r1, r6, #0
	adds r1, #0x20
	adds r1, r1, r0
	ldr r4, [r1]
	adds r0, r4, #0
	bl sub_802C0D4
	cmp r0, #0
	bne _0807C504
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #0x1c
	ands r1, r0
	cmp r1, #4
	beq _0807C4C8
	cmp r1, #8
	beq _0807C4C8
	cmp r1, #0x10
	bne _0807C504
_0807C4C8:
	ldr r1, [r4, #4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0807C504
	ldr r0, [r4, #0x6c]
	cmp r0, r7
	bne _0807C504
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	movs r0, #4
	orrs r1, r0
	str r1, [r4, #4]
	movs r0, #0
	str r0, [r4, #0x6c]
	adds r0, r4, #0
	bl sub_8016F28
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r3, #5
	rsbs r3, r3, #0
	adds r1, r3, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl Player_8005380
_0807C504:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #1
	bls _0807C49E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C514: .4byte gCurTask

.syntax divided
