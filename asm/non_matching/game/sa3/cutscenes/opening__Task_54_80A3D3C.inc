.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A3D94 @ =gCurTask
	ldr r6, [r0]
	ldrh r3, [r6, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r3, r3, r0
	ldr r5, _080A3D98 @ =gBldRegs
	movs r4, #0
	ldr r0, _080A3D9C @ =0x00003FBF
	strh r0, [r5]
	ldr r2, _080A3DA0 @ =gDispCnt
	ldrh r0, [r2]
	movs r7, #0xc0
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _080A3DA4 @ =gWinRegs
	movs r0, #0xff
	strh r0, [r2]
	strh r0, [r2, #2]
	strh r0, [r2, #6]
	movs r0, #0x21
	strh r0, [r2, #8]
	strh r4, [r2, #0xa]
	strh r4, [r5, #4]
	strh r4, [r3, #4]
	movs r0, #1
	strh r0, [r3, #6]
	ldr r0, [r3, #0x10]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r3, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r0, _080A3DA8 @ =Task_54_80A3DAC
	str r0, [r6, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D94: .4byte gCurTask
_080A3D98: .4byte gBldRegs
_080A3D9C: .4byte 0x00003FBF
_080A3DA0: .4byte gDispCnt
_080A3DA4: .4byte gWinRegs
_080A3DA8: .4byte Task_54_80A3DAC

.syntax divided
