.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A4264 @ =gCurTask
	ldr r0, [r5]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	adds r0, r4, #0
	bl sub_80A4598
	adds r0, r4, #0
	bl sub_80A453C
	cmp r0, #1
	bne _080A424A
	movs r0, #0x1b
	strb r0, [r4, #1]
_080A424A:
	adds r0, r4, #0
	bl sub_80A4440
	ldrh r2, [r4, #4]
	cmp r2, #0x77
	bls _080A426C
	movs r0, #0
	strh r0, [r4, #4]
	ldr r1, [r5]
	ldr r0, _080A4268 @ =Task_94_B_80A429C
	str r0, [r1, #8]
	b _080A4294
	.align 2, 0
_080A4264: .4byte gCurTask
_080A4268: .4byte Task_94_B_80A429C
_080A426C:
	ldr r0, _080A428C @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A4290
	movs r0, #0x9b
	lsls r0, r0, #9
	str r0, [r4, #0x18]
	movs r0, #0x1d
	strb r0, [r4, #1]
	movs r0, #2
	bl sub_808ADF0
	b _080A4294
	.align 2, 0
_080A428C: .4byte gPressedKeys
_080A4290:
	adds r0, r2, #1
	strh r0, [r4, #4]
_080A4294:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
