.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	mov sl, r0
	movs r0, #0x94
	lsls r0, r0, #2
	add r0, sb
	mov r8, r0
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	add r1, sb
	ldr r1, [r1]
	bl sub_8004D68
	ldr r2, _0807F2FC @ =gPlayers
	ldr r0, _0807F300 @ =gStageData
	ldrb r1, [r0, #6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	cmp r0, #1
	beq _0807F298
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r2
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	cmp r0, #1
	bne _0807F2A6
_0807F298:
	mov r0, r8
	bl IsCollidingWithCheese
	cmp r0, #1
	bne _0807F2A6
	movs r0, #1
	mov sl, r0
_0807F2A6:
	movs r7, #0
_0807F2A8:
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r7
	lsls r0, r0, #4
	ldr r1, _0807F2FC @ =gPlayers
	adds r4, r0, r1
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807F316
	mov r0, r8
	ldr r1, [r0, #0x20]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0807F316
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	ldr r1, [r6]
	asrs r1, r1, #8
	movs r5, #0x9a
	lsls r5, r5, #1
	add r5, sb
	ldr r2, [r5]
	asrs r2, r2, #8
	str r4, [sp]
	mov r0, r8
	movs r3, #0
	bl sub_8020E3C
	cmp r0, #1
	bne _0807F304
	movs r0, #1
	mov sl, r0
	adds r0, r4, #0
	bl sub_80044CC
	b _0807F316
	.align 2, 0
_0807F2FC: .4byte gPlayers
_0807F300: .4byte gStageData
_0807F304:
	ldr r1, [r6]
	asrs r1, r1, #8
	ldr r2, [r5]
	asrs r2, r2, #8
	str r4, [sp]
	mov r0, r8
	movs r3, #0
	bl sub_8020CE0
_0807F316:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #1
	bls _0807F2A8
	mov r0, sl
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
