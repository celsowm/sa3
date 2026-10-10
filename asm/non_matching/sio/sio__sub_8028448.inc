.syntax unified
.text
	push {r4, lr}
	ldr r4, _08028470 @ =gCurTask
	ldr r0, [r4]
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	bl sub_80284E8
	ldr r1, [r4]
	ldr r0, _08028474 @ =Task_F4_8027E70
	str r0, [r1, #8]
	bl MultiSioStart
	bl sub_8028338
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028470: .4byte gCurTask
_08028474: .4byte Task_F4_8027E70

.syntax divided
