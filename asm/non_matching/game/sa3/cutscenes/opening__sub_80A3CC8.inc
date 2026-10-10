.syntax unified
.text
	push {r4, lr}
	adds r3, r0, #0
	ldr r2, _080A3D20 @ =gDispCnt
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A3D24 @ =gBgCntRegs
	movs r4, #0
	movs r2, #0
	ldr r0, _080A3D28 @ =0x00005888
	strh r0, [r1]
	ldr r0, _080A3D2C @ =gBgScrollRegs
	strh r2, [r0]
	strh r2, [r0, #2]
	adds r0, r3, #0
	adds r0, #0x14
	ldr r1, _080A3D30 @ =0x06008000
	str r1, [r0, #4]
	strh r2, [r0, #0xa]
	ldr r1, _080A3D34 @ =0x0600C000
	str r1, [r0, #0xc]
	strh r2, [r0, #0x18]
	strh r2, [r0, #0x1a]
	ldr r1, _080A3D38 @ =0x0000012F
	strh r1, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r2, [r0, #0x20]
	strh r2, [r0, #0x22]
	strh r2, [r0, #0x24]
	movs r1, #0x20
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	adds r3, #0x3e
	strb r4, [r3]
	movs r1, #4
	strh r1, [r0, #0x2e]
	bl DrawBackground
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D20: .4byte gDispCnt
_080A3D24: .4byte gBgCntRegs
_080A3D28: .4byte 0x00005888
_080A3D2C: .4byte gBgScrollRegs
_080A3D30: .4byte 0x06008000
_080A3D34: .4byte 0x0600C000
_080A3D38: .4byte 0x0000012F

.syntax divided
