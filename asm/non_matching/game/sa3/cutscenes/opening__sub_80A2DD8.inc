.syntax unified
.text
	push {lr}
	ldr r0, _080A2E1C @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	ldr r0, _080A2E20 @ =gStageData
	ldrb r0, [r0, #7]
	cmp r0, #0
	beq _080A2E30
	ldr r2, _080A2E24 @ =0x03000128
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080A2E30
	cmp r0, #3
	bgt _080A2E30
	ldr r0, _080A2E28 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A2E30
	ldr r0, _080A2E2C @ =gFlags
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	movs r0, #2
	bl sub_808ADF0
	movs r0, #1
	b _080A2E32
	.align 2, 0
_080A2E1C: .4byte gCurTask
_080A2E20: .4byte gStageData
_080A2E24: .4byte 0x03000128
_080A2E28: .4byte gPressedKeys
_080A2E2C: .4byte gFlags
_080A2E30:
	movs r0, #0
_080A2E32:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
