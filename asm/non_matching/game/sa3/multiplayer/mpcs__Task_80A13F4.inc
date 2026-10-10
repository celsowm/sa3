.syntax unified
.text
	push {r4, lr}
	ldr r4, _080A1410 @ =gCurTask
	ldr r2, [r4]
	ldrh r0, [r2, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r1, r0, r1
	ldr r3, [r1, #0x18]
	ldrb r0, [r3]
	cmp r0, #0x22
	bne _080A1418
	ldr r0, _080A1414 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A1428
	.align 2, 0
_080A1410: .4byte gCurTask
_080A1414: .4byte Task_80A14AC
_080A1418:
	ldrb r0, [r1, #3]
	cmp r0, #0x25
	bne _080A1428
	movs r0, #0x26
	strb r0, [r3]
	ldr r0, [r4]
	bl TaskDestroy
_080A1428:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
