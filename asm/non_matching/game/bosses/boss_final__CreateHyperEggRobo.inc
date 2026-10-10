.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0807B704 @ =Task_HyperEggRoboInit
	movs r1, #0xd6
	lsls r1, r1, #2     @ 0x358
	movs r2, #0x84
	lsls r2, r2, #6
	ldr r3, _0807B708 @ =TaskDestructor_HyperEggRobo
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r2, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r2, r2, r1
	mov ip, r2
	ldr r2, _0807B70C @ =gStageData
	adds r1, r2, #0
	adds r1, #0x88
	str r0, [r1]
	ldrb r0, [r2, #1]
	cmp r0, #0
	bne _0807B710
	movs r0, #8
	b _0807B712
	.align 2, 0
_0807B704: .4byte Task_HyperEggRoboInit
_0807B708: .4byte TaskDestructor_HyperEggRobo
_0807B70C: .4byte gStageData
_0807B710:
	movs r0, #6
_0807B712:
	mov r1, ip
	strb r0, [r1]
	mov r0, ip
	str r4, [r0, #4]
	movs r3, #0
	movs r0, #1
	mov r1, ip
	strh r0, [r1, #0x14]
	strh r3, [r1, #0x16]
	strh r0, [r1, #8]
	strh r3, [r1, #0xc]
	ldr r2, _0807B7E8 @ =gPlayers
	str r2, [r1, #0x20]
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r2
	mov r1, ip
	str r0, [r1, #0x24]
	movs r0, #0x94
	lsls r0, r0, #2
	add r0, ip
	str r3, [r0]
	movs r0, #0x8a
	lsls r0, r0, #2
	add r0, ip
	str r3, [r0]
	movs r1, #0
	ldr r5, _0807B7EC @ =gDispCnt
	ldr r6, _0807B7F0 @ =gBgScrollRegs
	ldr r7, _0807B7F4 @ =gBgCntRegs
	ldr r0, _0807B7F8 @ =gBgSprites_Unknown1
	mov r8, r0
	ldr r4, _0807B7FC @ =gBgSprites_Unknown2
	mov r2, ip
	adds r2, #0x7c
_0807B768:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r2, r0
	str r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _0807B768
	movs r0, #0
	mov r1, ip
	str r0, [r1, #0x18]
	movs r1, #0
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, ip
	movs r3, #0
_0807B78C:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r2, r0
	str r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #2
	bls _0807B78C
	movs r0, #0x9e
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r0, #0xa8
	lsls r0, r0, #2
	add r0, ip
	str r2, [r0]
	ldrh r1, [r5]
	ldr r0, _0807B800 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r5]
	movs r1, #0
	strh r2, [r6]
	strh r2, [r6, #2]
	ldr r0, _0807B804 @ =0x00009B0E
	strh r0, [r7]
	mov r0, r8
	strb r1, [r0]
	strb r1, [r4]
	strb r1, [r4, #1]
	movs r0, #0xff
	strb r0, [r4, #2]
	movs r0, #0x20
	strb r0, [r4, #3]
	mov r0, ip
	bl sub_807C074
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807B7E8: .4byte gPlayers
_0807B7EC: .4byte gDispCnt
_0807B7F0: .4byte gBgScrollRegs
_0807B7F4: .4byte gBgCntRegs
_0807B7F8: .4byte gBgSprites_Unknown1
_0807B7FC: .4byte gBgSprites_Unknown2
_0807B800: .4byte 0x0000FEFF
_0807B804: .4byte 0x00009B0E

.syntax divided
