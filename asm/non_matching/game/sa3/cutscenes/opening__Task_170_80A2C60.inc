.syntax unified
.text
	push {r4, r5, lr}
	ldr r0, _080A2C90 @ =gCurTask
	ldr r0, [r0]
	ldrh r5, [r0, #6]
	ldr r0, _080A2C94 @ =0x0300013C
	adds r4, r5, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	bl sub_80A2DD8
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	bne _080A2CF2
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _080A2C98
	bl sub_80A2D80
	bl sub_80A23A4
	b _080A2CF2
	.align 2, 0
_080A2C90: .4byte gCurTask
_080A2C94: .4byte 0x0300013C
_080A2C98:
	ldr r1, _080A2CBC @ =gBldRegs
	movs r0, #0xff
	strh r0, [r1]
	strh r2, [r1, #2]
	movs r0, #0x10
	strh r0, [r1, #4]
	ldr r1, _080A2CC0 @ =0x03000128
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _080A2CD6
	cmp r0, #1
	bgt _080A2CC4
	cmp r0, #0
	beq _080A2CCE
	b _080A2CEA
	.align 2, 0
_080A2CBC: .4byte gBldRegs
_080A2CC0: .4byte 0x03000128
_080A2CC4:
	cmp r0, #2
	beq _080A2CDE
	cmp r0, #4
	beq _080A2CE4
	b _080A2CEA
_080A2CCE:
	movs r0, #1
	bl sub_80A2E38
	b _080A2CEA
_080A2CD6:
	movs r0, #0
	bl sub_80A2E38
	b _080A2CEA
_080A2CDE:
	bl sub_80A3F18
	b _080A2CEA
_080A2CE4:
	movs r0, #1
	bl CreateIntroEggmanCutscene
_080A2CEA:
	ldr r0, _080A2CF8 @ =gCurTask
	ldr r0, [r0]
	bl TaskDestroy
_080A2CF2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CF8: .4byte gCurTask

.syntax divided
