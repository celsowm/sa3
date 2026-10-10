.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _08081930 @ =gCurTask
	ldr r0, [r5]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_807C14C
	adds r0, r4, #0
	bl sub_80816C0
	ldr r0, [r4, #4]
	ldrb r0, [r0]
	cmp r0, #3
	bne _08081934
	ldr r0, [r5]
	bl TaskDestroy
	b _0808194E
	.align 2, 0
_08081930: .4byte gCurTask
_08081934:
	bl sub_8079FFC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08081948
	ldr r1, [r5]
	ldr r0, _08081944 @ =Task_8081958
	b _0808194C
	.align 2, 0
_08081944: .4byte Task_8081958
_08081948:
	ldr r1, [r5]
	ldr r0, _08081954 @ =Task_807B808
_0808194C:
	str r0, [r1, #8]
_0808194E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081954: .4byte Task_807B808

.syntax divided
