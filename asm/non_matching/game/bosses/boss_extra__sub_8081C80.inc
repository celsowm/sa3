.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _08081CB0 @ =Task_878_2_8081E74
	ldr r1, _08081CB4 @ =0x00000878
	movs r2, #0xc4
	lsls r2, r2, #6
	ldr r3, _08081CB8 @ =TaskDestructor_878_8081D64
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r2, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r5, r2, r1
	ldr r2, _08081CBC @ =gStageData
	adds r1, r2, #0
	adds r1, #0x88
	str r0, [r1]
	ldrb r0, [r2, #1]
	cmp r0, #0
	bne _08081CC0
	movs r0, #0xc
	b _08081CC2
	.align 2, 0
_08081CB0: .4byte Task_878_2_8081E74
_08081CB4: .4byte 0x00000878
_08081CB8: .4byte TaskDestructor_878_8081D64
_08081CBC: .4byte gStageData
_08081CC0:
	movs r0, #0xa
_08081CC2:
	strb r0, [r5]
	movs r4, #0
	movs r2, #0
	movs r3, #1
	movs r0, #1
	strh r0, [r5, #0x10]
	strh r2, [r5, #0x12]
	strh r0, [r5, #4]
	strh r2, [r5, #8]
	strb r4, [r5, #1]
	strb r4, [r5, #0xa]
	strb r4, [r5, #0xc]
	strb r4, [r5, #0xd]
	str r2, [r5, #0x6c]
	strb r4, [r5, #0x17]
	str r2, [r5, #0x18]
	ldr r1, _08081D54 @ =gBgScrollRegs
	movs r0, #0x68
	strh r0, [r1]
	movs r0, #0x30
	strh r0, [r1, #2]
	ldr r1, _08081D58 @ =gCamera
	adds r1, #0x5c
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r5, r1
	str r2, [r0]
	adds r1, #0x28
	adds r0, r5, r1
	str r2, [r0]
	adds r1, #0xa0
	adds r0, r5, r1
	str r2, [r0]
	ldr r1, _08081D5C @ =0x00000814
	adds r0, r5, r1
	str r2, [r0]
	str r2, [r5, #0x1c]
	str r2, [r5, #0x20]
	str r2, [r5, #0x24]
	str r2, [r5, #0x6c]
	str r2, [r5, #0x74]
	bl SetFixedRandomIfTimeAttackMode
	ldr r1, _08081D60 @ =gPlayers
	str r1, [r5, #0x28]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r1, r2
	str r0, [r5, #0x2c]
	subs r2, #8
	adds r1, r1, r2
	adds r0, r5, #0
	adds r0, #0x58
	str r0, [r1]
	ldr r0, [r5, #0x2c]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x68
	str r1, [r0]
	adds r0, r5, #0
	adds r0, #0x70
	strb r4, [r0]
	adds r0, r5, #0
	bl sub_80853D8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081D54: .4byte gBgScrollRegs
_08081D58: .4byte gCamera
_08081D5C: .4byte 0x00000814
_08081D60: .4byte gPlayers

.syntax divided
