.syntax unified
.text
	push {r4, lr}
	ldr r4, _0802849C @ =gCurTask
	ldr r0, [r4]
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	bl sub_80284E8
	ldr r1, [r4]
	ldr r0, _080284A0 @ =Task_F4_80284A4
	str r0, [r1, #8]
	bl sub_8028338
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802849C: .4byte gCurTask
_080284A0: .4byte Task_F4_80284A4

.syntax divided
