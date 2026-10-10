.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080819DC @ =gCurTask
	ldr r2, [r5]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, [r4, #4]
	ldrb r0, [r0]
	cmp r0, #3
	bne _080819E0
	adds r0, r2, #0
	bl TaskDestroy
	b _08081A06
	.align 2, 0
_080819DC: .4byte gCurTask
_080819E0:
	adds r0, r4, #0
	bl sub_807C14C
	adds r0, r4, #0
	bl sub_80816C0
	ldr r0, [r4, #4]
	ldrb r0, [r0]
	cmp r0, #2
	bne _08081A06
	movs r0, #5
	strh r0, [r4, #8]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	bl SetFixedRandomIfTimeAttackMode
	ldr r1, [r5]
	ldr r0, _08081A0C @ =Task_807B808
	str r0, [r1, #8]
_08081A06:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081A0C: .4byte Task_807B808

.syntax divided
