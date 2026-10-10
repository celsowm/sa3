.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A3058 @ =gCurTask
	ldr r6, [r0]
	ldrh r3, [r6, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r3, r3, r0
	ldr r4, _080A305C @ =gBldRegs
	movs r5, #0
	ldr r0, _080A3060 @ =0x00003FFF
	strh r0, [r4]
	ldr r2, _080A3064 @ =gDispCnt
	ldrh r0, [r2]
	movs r7, #0xc0
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _080A3068 @ =gWinRegs
	movs r0, #0xff
	strh r0, [r2]
	strh r0, [r2, #2]
	strh r0, [r2, #6]
	ldr r0, _080A306C @ =0x00003117
	strh r0, [r2, #8]
	strh r5, [r2, #0xa]
	movs r5, #0x10
	strh r5, [r4, #4]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r3, #6]
	movs r0, #1
	strh r0, [r3, #8]
	ldr r0, [r3, #0x14]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r3, #0xc]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2, #4]
	movs r0, #0x1f
	strh r0, [r4, #2]
	strh r5, [r4, #4]
	ldr r0, _080A3070 @ =Task_A0_80A3074
	str r0, [r6, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3058: .4byte gCurTask
_080A305C: .4byte gBldRegs
_080A3060: .4byte 0x00003FFF
_080A3064: .4byte gDispCnt
_080A3068: .4byte gWinRegs
_080A306C: .4byte 0x00003117
_080A3070: .4byte Task_A0_80A3074

.syntax divided
