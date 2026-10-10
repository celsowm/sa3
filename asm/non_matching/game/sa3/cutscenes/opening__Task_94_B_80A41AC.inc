.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A41EC @ =gCurTask
	ldr r0, [r5]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	adds r0, r4, #0
	bl sub_80A4598
	ldr r2, _080A41F0 @ =gWinRegs
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r4, #0xc]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	adds r0, r4, #0
	bl sub_80A43E0
	ldrh r2, [r4, #4]
	cmp r2, #0x2c
	bls _080A41F8
	movs r0, #0
	strh r0, [r4, #4]
	ldr r1, [r5]
	ldr r0, _080A41F4 @ =Task_94_B_80A4228
	str r0, [r1, #8]
	b _080A4220
	.align 2, 0
_080A41EC: .4byte gCurTask
_080A41F0: .4byte gWinRegs
_080A41F4: .4byte Task_94_B_80A4228
_080A41F8:
	ldr r0, _080A4218 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A421C
	movs r0, #0x9b
	lsls r0, r0, #9
	str r0, [r4, #0x18]
	movs r0, #0x1d
	strb r0, [r4, #1]
	movs r0, #2
	bl sub_808ADF0
	b _080A4220
	.align 2, 0
_080A4218: .4byte gPressedKeys
_080A421C:
	adds r0, r2, #1
	strh r0, [r4, #4]
_080A4220:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
