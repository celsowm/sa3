.syntax unified
.text
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080862E4
	b _080863F0
_080862E4:
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #4]
	movs r2, #0x80
	lsls r2, r2, #1
	ands r0, r2
	cmp r0, #0
	bne _080863F0
	ldr r0, [r5, #0x2c]
	ldr r0, [r0, #4]
	ands r0, r2
	cmp r0, #0
	bne _080863F0
	adds r4, r1, #0
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08086354
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80863FC
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808634E
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80865B0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808634E
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80871CC
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808634E
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_8086774
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08086354
_0808634E:
	adds r0, r4, #0
	bl sub_801038C
_08086354:
	ldr r4, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	cmp r0, #0
	beq _08086392
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80865B0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808638A
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80871CC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808638A
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_8086774
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080863F0
_0808638A:
	adds r0, r4, #0
	bl sub_8010C58
	b _080863F0
_08086392:
	ldr r0, _080863F8 @ =gStageData
	ldrb r0, [r0, #3]
	cmp r0, #5
	bne _080863F0
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080863F0
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80863FC
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080863EA
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80865B0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080863EA
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_80871CC
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080863EA
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_8086774
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080863F0
_080863EA:
	adds r0, r4, #0
	bl sub_801038C
_080863F0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080863F8: .4byte gStageData

.syntax divided
