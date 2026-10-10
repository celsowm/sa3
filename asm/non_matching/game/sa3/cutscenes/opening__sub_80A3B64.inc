.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080A3BD0 @ =gCurTask
	mov r8, r0
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r3, r1, r0
	ldr r5, _080A3BD4 @ =gWinRegs
	ldr r0, [r3, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r3, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r5, #4]
	ldrh r4, [r3, #6]
	ldr r6, _080A3BD8 @ =gBldRegs
	cmp r4, #0
	bne _080A3BBA
	ldr r0, _080A3BDC @ =0x00003FBF
	strh r0, [r6]
	ldr r2, _080A3BE0 @ =gDispCnt
	ldrh r0, [r2]
	movs r7, #0xc0
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xff
	strh r0, [r5]
	strh r0, [r5, #2]
	strh r0, [r5, #6]
	movs r0, #0x24
	strh r0, [r5, #8]
	strh r4, [r5, #0xa]
	strh r4, [r3, #4]
	movs r0, #1
	strh r0, [r3, #6]
	strh r4, [r6, #4]
_080A3BBA:
	ldrh r0, [r6, #4]
	cmp r0, #0xe
	bhi _080A3BE4
	ldrh r0, [r3, #4]
	adds r0, #0x30
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r6, #4]
	b _080A3BF2
	.align 2, 0
_080A3BD0: .4byte gCurTask
_080A3BD4: .4byte gWinRegs
_080A3BD8: .4byte gBldRegs
_080A3BDC: .4byte 0x00003FBF
_080A3BE0: .4byte gDispCnt
_080A3BE4:
	ldrb r0, [r3]
	bl sub_80A3BFC
	mov r1, r8
	ldr r0, [r1]
	bl TaskDestroy
_080A3BF2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
