.syntax unified
.text
	push {r4, lr}
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r1, _08081C48 @ =gStageData
	movs r0, #5
	strb r0, [r1, #4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _08081C42
	bl VramFree
	movs r0, #0
	str r0, [r4, #0x18]
_08081C42:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08081C48: .4byte gStageData

.syntax divided
