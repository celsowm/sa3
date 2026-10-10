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
	ldr r0, _0807C434 @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r1, r1, r0
	str r1, [sp, #8]
	movs r6, #0
	movs r5, #0
_0807C39E:
	lsls r0, r5, #2
	ldr r1, [sp, #8]
	adds r1, #0x20
	adds r1, r1, r0
	ldr r4, [r1]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807C46E
	ldr r0, [r4, #4]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0807C3DC
	ldr r0, [r4, #0x6c]
	cmp r0, sb
	bne _0807C3DC
	ldr r0, [r4, #0x10]
	ldr r1, [sp, #4]
	subs r0, r0, r1
	str r0, [r4, #0x10]
	mov r2, sl
	cmp r2, #0
	beq _0807C3DC
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	subs r0, r0, r2
	str r0, [r4, #0x14]
_0807C3DC:
	ldr r1, [r4, #0x10]
	mov r2, r8
	subs r0, r1, r2
	cmp r0, #0
	bge _0807C3EA
	mov r2, r8
	subs r0, r2, r1
_0807C3EA:
	asrs r0, r0, #8
	cmp r0, #0x40
	bgt _0807C46E
	ldr r1, [r4, #0x14]
	subs r0, r1, r7
	cmp r0, #0
	bge _0807C3FA
	subs r0, r7, r1
_0807C3FA:
	asrs r0, r0, #8
	cmp r0, #0x40
	bgt _0807C46E
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
	beq _0807C438
	lsls r1, r2, #0x18
	asrs r1, r1, #0x10
	ldr r0, [r4, #0x14]
	adds r0, r0, r1
	str r0, [r4, #0x14]
	movs r0, #1
	lsls r0, r5
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
	b _0807C454
	.align 2, 0
_0807C434: .4byte gCurTask
_0807C438:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r2
	cmp r0, #0
	beq _0807C454
	ldr r1, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r0, r2, #0x18
	asrs r0, r0, #0x10
	adds r1, r1, r0
	str r1, [r4, #0x14]
	strh r3, [r4, #0x1a]
_0807C454:
	movs r0, #0xc0
	lsls r0, r0, #0xc
	ands r0, r2
	cmp r0, #0
	beq _0807C46E
	lsls r0, r2, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	ldr r1, [r4, #0x10]
	adds r1, r1, r0
	str r1, [r4, #0x10]
	movs r0, #0
	strh r0, [r4, #0x18]
_0807C46E:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #1
	bls _0807C39E
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
