.syntax unified
.text
	push {lr}
	ldr r0, _080284D8 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080284CA
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	beq _080284C2
	ldr r1, _080284DC @ =gMultiSioSend
	ldrb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #2]
_080284C2:
	ldr r0, _080284E0 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080284E4 @ =Task_F4_8027E70
	str r0, [r1, #8]
_080284CA:
	bl Task_F4_8027E70
	bl sub_8028338
	pop {r0}
	bx r0
	.align 2, 0
_080284D8: .4byte gMultiSioStatusFlags
_080284DC: .4byte gMultiSioSend
_080284E0: .4byte gCurTask
_080284E4: .4byte Task_F4_8027E70

.syntax divided
