.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r6, _080A023C @ =gCurTask
	ldr r1, [r6]
	ldrh r4, [r1, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r4, r0
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0244
	ldr r0, _080A0240 @ =Task_80A14AC
	str r0, [r1, #8]
	b _080A033C
	.align 2, 0
_080A023C: .4byte gCurTask
_080A0240: .4byte Task_80A14AC
_080A0244:
	cmp r0, #0xd
	bne _080A02EC
	ldr r1, _080A02D4 @ =0x030000B4
	adds r0, r4, r1
	ldr r2, _080A02D8 @ =gUnknown_080D8D08
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, #1
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r1, [r1]
	strh r1, [r0, #0xc]
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, #1
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	strb r1, [r0, #0x1a]
	bl UpdateSpriteAnimation
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r5, #0x6c]
	str r0, [r5, #0x4c]
	ldrb r0, [r5, #1]
	strb r0, [r5, #2]
	ldr r0, [r5, #0x30]
	ldrb r0, [r0]
	strb r0, [r5, #1]
	movs r0, #0xc9
	lsls r0, r0, #8
	str r0, [r5, #0x74]
	adds r0, r5, #0
	bl sub_80A0EA8
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r5, #0x54]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r5, #0x58]
	ldr r2, _080A02DC @ =0x03000002
	adds r0, r4, r2
	ldr r3, _080A02E0 @ =0x03000003
	adds r1, r4, r3
	ldr r7, _080A02E4 @ =0x03000054
	adds r2, r4, r7
	adds r7, #4
	adds r3, r4, r7
	adds r7, #0x30
	adds r4, r4, r7
	ldr r4, [r4]
	str r4, [sp]
	bl CreateSomeTask_809BF3C
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	strb r0, [r5, #3]
	adds r0, r5, #0
	bl sub_80A19C0
	adds r0, r5, #0
	bl sub_80A1A04
	adds r0, r5, #0
	bl sub_80A10B0
	ldr r1, [r6]
	ldr r0, _080A02E8 @ =sub_80A0344
	str r0, [r1, #8]
	b _080A033C
	.align 2, 0
_080A02D4: .4byte 0x030000B4
_080A02D8: .4byte gUnknown_080D8D08
_080A02DC: .4byte 0x03000002
_080A02E0: .4byte 0x03000003
_080A02E4: .4byte 0x03000054
_080A02E8: .4byte sub_80A0344
_080A02EC:
	cmp r0, #2
	bne _080A0324
	adds r0, r5, #0
	bl sub_80A19C0
	adds r0, r5, #0
	bl sub_80A1A04
	adds r0, r5, #0
	bl sub_80A10B0
	adds r0, r5, #0
	bl sub_80A1110
	ldr r0, [r5, #0x14]
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	strb r0, [r5, #3]
	ldr r1, [r6]
	ldr r0, _080A0320 @ =Task_809FEB0
	str r0, [r1, #8]
	b _080A033C
	.align 2, 0
_080A0320: .4byte Task_809FEB0
_080A0324:
	adds r0, r5, #0
	bl sub_80A19C0
	adds r0, r5, #0
	bl sub_80A1A04
	adds r0, r5, #0
	bl sub_80A10B0
	adds r0, r5, #0
	bl sub_80A1110
_080A033C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
