.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _080A0C78 @ =gCurTask
	ldr r2, [r5]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0C80
	ldr r0, _080A0C7C @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A0D16
	.align 2, 0
_080A0C78: .4byte gCurTask
_080A0C7C: .4byte Task_80A14AC
_080A0C80:
	adds r0, r4, #0
	bl sub_80A19C0
	adds r0, r4, #0
	bl sub_80A10B0
	adds r0, r4, #0
	bl sub_80A124C
	ldrh r0, [r4, #6]
	cmp r0, #0
	beq _080A0CCC
	ldr r2, _080A0CE8 @ =gDispCnt
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A0CEC @ =gWinRegs
	movs r3, #0
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #0xa0
	strh r0, [r1, #4]
	ldrh r2, [r1, #8]
	movs r0, #0x3f
	orrs r0, r2
	strh r0, [r1, #8]
	ldrh r2, [r1, #0xa]
	movs r0, #0x1f
	orrs r0, r2
	strh r0, [r1, #0xa]
	ldr r1, _080A0CF0 @ =gBldRegs
	ldr r0, _080A0CF4 @ =0x00003FFF
	strh r0, [r1]
	strh r3, [r4, #6]
	strh r3, [r4, #8]
_080A0CCC:
	ldr r1, _080A0CF0 @ =gBldRegs
	ldrh r0, [r1, #4]
	cmp r0, #0xf
	bhi _080A0CF8
	ldrh r0, [r4, #8]
	lsrs r0, r0, #8
	strh r0, [r1, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r3, [r4, #8]
	adds r0, r0, r3
	strh r0, [r4, #8]
	b _080A0D16
	.align 2, 0
_080A0CE8: .4byte gDispCnt
_080A0CEC: .4byte gWinRegs
_080A0CF0: .4byte gBldRegs
_080A0CF4: .4byte 0x00003FFF
_080A0CF8:
	movs r2, #0
	movs r0, #0x10
	strh r0, [r1, #4]
	movs r0, #0x9b
	lsls r0, r0, #9
	str r0, [r4, #0x4c]
	str r0, [r4, #0x54]
	movs r1, #0x1d
	strb r1, [r4, #3]
	ldr r0, [r4, #0x18]
	strb r1, [r0]
	strh r2, [r4, #4]
	ldr r1, [r5]
	ldr r0, _080A0D1C @ =Task_80A13B4
	str r0, [r1, #8]
_080A0D16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0D1C: .4byte Task_80A13B4

.syntax divided
