.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _08081978 @ =gCurTask
	ldr r2, [r5]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, [r4, #4]
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808197C
	adds r0, r2, #0
	bl TaskDestroy
	b _080819B2
	.align 2, 0
_08081978: .4byte gCurTask
_0808197C:
	adds r0, r4, #0
	bl sub_807C14C
	adds r0, r4, #0
	bl sub_80816C0
	ldr r0, [r4, #4]
	ldrb r0, [r0]
	cmp r0, #2
	bne _080819B2
	bl sub_807A074
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080819B2
	movs r0, #0
	bl sub_807FB7C
	movs r0, #0xa
	bl sub_807FB7C
	movs r0, #0xb
	bl sub_807FB7C
	ldr r1, [r5]
	ldr r0, _080819B8 @ =Task_80819BC
	str r0, [r1, #8]
_080819B2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080819B8: .4byte Task_80819BC

.syntax divided
