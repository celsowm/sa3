.syntax unified
.text
	push {r4, lr}
	adds r3, r0, #0
	ldr r2, _080A39E8 @ =gDispCnt
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A39EC @ =gBgCntRegs
	movs r4, #0
	movs r2, #0
	ldr r0, _080A39F0 @ =0x00000D81
	strh r0, [r1, #2]
	ldr r0, _080A39F4 @ =gBgScrollRegs
	strh r2, [r0, #4]
	strh r2, [r0, #6]
	adds r0, r3, #0
	adds r0, #0x54
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	strh r2, [r0, #0xa]
	ldr r1, _080A39F8 @ =0x06006800
	str r1, [r0, #0xc]
	strh r2, [r0, #0x18]
	strh r2, [r0, #0x1a]
	movs r1, #0x97
	lsls r1, r1, #1
	strh r1, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r2, [r0, #0x20]
	strh r2, [r0, #0x22]
	strh r2, [r0, #0x24]
	movs r1, #0x20
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	adds r3, #0x7e
	strb r4, [r3]
	movs r1, #5
	strh r1, [r0, #0x2e]
	bl DrawBackground
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A39E8: .4byte gDispCnt
_080A39EC: .4byte gBgCntRegs
_080A39F0: .4byte 0x00000D81
_080A39F4: .4byte gBgScrollRegs
_080A39F8: .4byte 0x06006800

.syntax divided
