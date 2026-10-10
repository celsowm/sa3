.syntax unified
.text
	push {lr}
	movs r2, #0
	movs r1, #5
	strb r1, [r0, #1]
	movs r1, #1
	strh r1, [r0, #4]
	strh r2, [r0, #8]
	ldr r3, _080854A0 @ =gDispCnt
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _08085494
	ldr r0, _080854A4 @ =0x0000DEFF
	ands r0, r1
	strh r0, [r3]
	ldr r0, _080854A8 @ =gWinRegs
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	ldr r0, _080854AC @ =gBldRegs
	strh r2, [r0]
	strh r2, [r0, #2]
	strh r2, [r0, #4]
	ldr r2, _080854B0 @ =gFlags
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_08085494:
	ldr r1, _080854B4 @ =gStageData
	movs r0, #6
	strb r0, [r1, #4]
	pop {r0}
	bx r0
	.align 2, 0
_080854A0: .4byte gDispCnt
_080854A4: .4byte 0x0000DEFF
_080854A8: .4byte gWinRegs
_080854AC: .4byte gBldRegs
_080854B0: .4byte gFlags
_080854B4: .4byte gStageData

.syntax divided
