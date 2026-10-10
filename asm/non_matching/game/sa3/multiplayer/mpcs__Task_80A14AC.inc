.syntax unified
.text
	push {r4, lr}
	ldr r4, _080A14DC @ =gCurTask
	ldr r0, [r4]
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	movs r1, #0x9b
	lsls r1, r1, #9
	str r1, [r0, #0x4c]
	str r1, [r0, #0x54]
	movs r3, #0
	movs r2, #0x1d
	strb r2, [r0, #3]
	ldr r1, [r0, #0x18]
	strb r2, [r1]
	strh r3, [r0, #4]
	ldr r1, [r4]
	ldr r0, _080A14E0 @ =Task_CallDestroy_80A1498
	str r0, [r1, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A14DC: .4byte gCurTask
_080A14E0: .4byte Task_CallDestroy_80A1498

.syntax divided
