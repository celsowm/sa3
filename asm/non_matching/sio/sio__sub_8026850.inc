.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, _080268AC @ =gStageData
	ldrb r0, [r5, #6]
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #2
	adds r4, r4, r0
	lsls r4, r4, #4
	ldr r0, _080268B0 @ =gPlayers
	adds r4, r4, r0
	adds r0, r4, #0
	bl Player_8015D7C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r2, sp
	movs r1, #0x38
	strb r1, [r2]
	movs r1, #0xb
	strb r1, [r2, #1]
	mov r1, sp
	strb r0, [r1, #2]
	adds r4, #0x27
	ldrb r1, [r4]
	strb r1, [r2, #3]
	ldr r4, _080268B4 @ =gUnknown_03001060
	ldrb r1, [r5, #6]
	adds r1, #4
	movs r2, #1
	lsls r2, r1
	ldrb r3, [r4, #9]
	bics r3, r2
	ldrb r1, [r5, #6]
	adds r1, #4
	lsls r0, r1
	orrs r3, r0
	strb r3, [r4, #9]
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080268AC: .4byte gStageData
_080268B0: .4byte gPlayers
_080268B4: .4byte gUnknown_03001060

.syntax divided
