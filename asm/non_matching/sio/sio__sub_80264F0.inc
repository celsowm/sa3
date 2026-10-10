.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08026520 @ =gStageData
	ldrb r1, [r4, #6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08026524 @ =gPlayers
	adds r5, r0, r1
	bl sub_802610C
	lsls r0, r0, #0x10
	adds r3, r4, #0
	cmp r0, #0
	beq _08026528
	bl sub_802613C
	movs r0, #1
	rsbs r0, r0, #0
	b _08026716
	.align 2, 0
_08026520: .4byte gStageData
_08026524: .4byte gPlayers
_08026528:
	movs r2, #0
	adds r6, r3, #0
	adds r6, #0xae
	adds r7, r3, #0
_08026530:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r0, r0, #4
	ldr r1, _0802657C @ =gPlayers
	adds r0, r0, r1
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #0x1c
	ands r0, r1
	mov r8, r2
	cmp r0, #0xc
	beq _08026552
	b _08026704
_08026552:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	ldr r1, _08026580 @ =gMultiSioRecv
	adds r4, r0, r1
	ldrh r1, [r4]
	ldr r0, _08026584 @ =0x000068E0
	cmp r1, r0
	beq _080265EC
	cmp r1, r0
	bgt _080265A8
	subs r0, #0xde
	cmp r1, r0
	bgt _0802658C
	subs r0, #1
	cmp r1, r0
	bge _080265E8
	cmp r1, #6
	beq _0802663E
	ldr r3, _08026588 @ =gStageData
	b _080266F0
	.align 2, 0
_0802657C: .4byte gPlayers
_08026580: .4byte gMultiSioRecv
_08026584: .4byte 0x000068E0
_08026588: .4byte gStageData
_0802658C:
	ldr r0, _080265A0 @ =0x000068D0
	cmp r1, r0
	beq _0802665C
	adds r0, #1
	cmp r1, r0
	bne _0802659A
	b _0802668A
_0802659A:
	ldr r3, _080265A4 @ =gStageData
	b _080266F0
	.align 2, 0
_080265A0: .4byte 0x000068D0
_080265A4: .4byte gStageData
_080265A8:
	ldr r0, _080265C4 @ =0x000068FC
	cmp r1, r0
	beq _080265E4
	cmp r1, r0
	bgt _080265CC
	subs r0, #0x14
	cmp r1, r0
	beq _08026646
	adds r0, #0x12
	cmp r1, r0
	bne _080265C0
	b _080266BC
_080265C0:
	ldr r3, _080265C8 @ =gStageData
	b _080266F0
	.align 2, 0
_080265C4: .4byte 0x000068FC
_080265C8: .4byte gStageData
_080265CC:
	ldr r0, _080265DC @ =0x000068FE
	cmp r1, r0
	beq _080266A4
	adds r0, #1
	cmp r1, r0
	beq _080265E8
	ldr r3, _080265E0 @ =gStageData
	b _080266F0
	.align 2, 0
_080265DC: .4byte 0x000068FE
_080265E0: .4byte gStageData
_080265E4:
	bl sub_8004D30
_080265E8:
	movs r0, #1
	b _08026716
_080265EC:
	ldr r0, _08026614 @ =gStageData
	ldrb r1, [r0, #4]
	adds r3, r0, #0
	cmp r1, #1
	bhi _080265F8
	b _08026714
_080265F8:
	cmp r1, #4
	bhi _08026634
	movs r1, #0
	movs r0, #5
	strb r0, [r3, #4]
	ldrb r0, [r3, #3]
	cmp r0, #6
	bne _08026618
	ldrb r0, [r4, #0x12]
	strb r0, [r3, #5]
	ldrh r0, [r4, #0x14]
	strh r0, [r6]
	adds r0, r3, #0
	b _0802664C
	.align 2, 0
_08026614: .4byte gStageData
_08026618:
	ldrh r0, [r4, #0x14]
	strh r0, [r6]
	strh r1, [r5, #0x1c]
	ldrb r0, [r3, #0xa]
	cmp r0, #7
	bne _0802662C
	adds r0, r5, #0
	bl Player_800613C
	b _080265E8
_0802662C:
	adds r0, r5, #0
	bl Player_8005DAC
	b _080265E8
_08026634:
	cmp r1, #5
	bne _080266F0
	ldrh r0, [r4, #0x14]
	strh r0, [r6]
	b _080266F0
_0802663E:
	ldrb r0, [r7, #4]
	cmp r0, #1
	bls _08026714
	b _080265E8
_08026646:
	ldrb r0, [r4, #0x12]
	strb r0, [r7, #5]
	adds r0, r7, #0
_0802664C:
	adds r0, #0x90
	ldr r1, [r0]
	ldr r0, _08026658 @ =Task_800303C
	str r0, [r1, #8]
	b _080265E8
	.align 2, 0
_08026658: .4byte Task_800303C
_0802665C:
	ldr r1, _08026678 @ =gStageData
	ldrb r0, [r1, #4]
	cmp r0, #3
	bne _0802668A
	adds r3, r1, #0
	adds r3, #0xb9
	ldrb r1, [r3]
	cmp r1, #0
	bne _0802667C
	ldrb r0, [r4, #0x10]
	strb r0, [r3]
	bl sub_800341C
	b _0802668A
	.align 2, 0
_08026678: .4byte gStageData
_0802667C:
	ldrb r2, [r4, #0x10]
	adds r0, r2, #0
	cmp r1, r0
	bls _0802668A
	cmp r0, #0
	beq _0802668A
	strb r2, [r3]
_0802668A:
	ldrb r0, [r4, #0x12]
	ldr r3, _080266A0 @ =gStageData
	cmp r0, #0xff
	bne _080266F0
	ldrb r1, [r4, #0x13]
	ldrb r0, [r4, #0x14]
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r6]
	b _080266F0
	.align 2, 0
_080266A0: .4byte gStageData
_080266A4:
	ldrb r0, [r7, #4]
	cmp r0, #7
	beq _080265E8
	bl sub_8002414
	adds r0, r5, #0
	ldr r1, _080266B8 @ =Player_800DF9C
	bl SetPlayerCallback
	b _080265E8
	.align 2, 0
_080266B8: .4byte Player_800DF9C
_080266BC:
	ldr r1, _080266E4 @ =gStageData
	ldrb r0, [r1, #4]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080265E8
	movs r0, #0
	strh r0, [r5, #0x1c]
	movs r0, #8
	strb r0, [r1, #4]
	ldr r0, [r5, #4]
	ldr r1, _080266E8 @ =0xEFFFFFFF
	ands r0, r1
	str r0, [r5, #4]
	adds r0, r5, #0
	ldr r1, _080266EC @ =Player_800EB4C
	bl SetPlayerCallback
	b _080265E8
	.align 2, 0
_080266E4: .4byte gStageData
_080266E8: .4byte 0xEFFFFFFF
_080266EC: .4byte Player_800EB4C
_080266F0:
	ldrb r0, [r3, #3]
	cmp r0, #5
	bne _08026704
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08026704
	b _080265E8
_08026704:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _08026714
	b _08026530
_08026714:
	movs r0, #0
_08026716:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

.syntax divided
