.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A43C4 @ =gCurTask
	ldr r0, [r6]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r1, r0
	movs r4, #0xa0
	lsls r4, r4, #0x13
	ldr r2, _080A43C8 @ =gBldRegs
	movs r3, #0
	movs r0, #0xa0
	strh r0, [r2]
	ldr r1, _080A43CC @ =gWinRegs
	movs r0, #0xc0
	lsls r0, r0, #6
	strh r0, [r1, #8]
	strh r3, [r1, #0xa]
	movs r0, #0x10
	strh r0, [r2, #4]
	str r3, [r4]
	ldrh r0, [r5, #4]
	cmp r0, #2
	bls _080A43D0
	movs r0, #0
	bl CreateIntroEggmanCutscene
	ldr r0, [r6]
	bl TaskDestroy
	b _080A43D4
	.align 2, 0
_080A43C4: .4byte gCurTask
_080A43C8: .4byte gBldRegs
_080A43CC: .4byte gWinRegs
_080A43D0:
	adds r0, #1
	strh r0, [r5, #4]
_080A43D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
