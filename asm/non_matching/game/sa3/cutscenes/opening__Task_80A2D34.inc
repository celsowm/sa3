.syntax unified
.text
	push {lr}
	ldr r0, _080A2D50 @ =gCurTask
	ldr r0, [r0]
	ldrh r0, [r0, #6]
	ldr r1, _080A2D54 @ =0x03000128
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	beq _080A2D58
	cmp r0, #5
	beq _080A2D60
	b _080A2D76
	.align 2, 0
_080A2D50: .4byte gCurTask
_080A2D54: .4byte 0x03000128
_080A2D58:
	movs r0, #2
	bl sub_808ADF0
	b _080A2D76
_080A2D60:
	ldr r2, _080A2D7C @ =gLoadedSaveGame
	ldrh r1, [r2, #0x34]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2, #0x34]
	bl sub_8001E58
	movs r0, #2
	movs r1, #0
	bl WarpToMap
_080A2D76:
	pop {r0}
	bx r0
	.align 2, 0
_080A2D7C: .4byte gLoadedSaveGame

.syntax divided
