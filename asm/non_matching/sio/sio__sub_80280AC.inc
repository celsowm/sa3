.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, _08028134 @ =gBgCntRegs
	movs r6, #0
	movs r4, #0
	ldr r0, _08028138 @ =0x00001E0F
	strh r0, [r1]
	ldr r0, _0802813C @ =0x00001C0A
	strh r0, [r1, #2]
	adds r2, r7, #0
	adds r2, #0xc
	ldr r0, _08028140 @ =0x0600C000
	str r0, [r2, #4]
	strh r4, [r2, #0xa]
	ldr r0, _08028144 @ =0x0600F000
	str r0, [r2, #0xc]
	strh r4, [r2, #0x18]
	strh r4, [r2, #0x1a]
	ldr r0, _08028148 @ =0x00000189
	strh r0, [r2, #0x1c]
	strh r4, [r2, #0x1e]
	strh r4, [r2, #0x20]
	strh r4, [r2, #0x22]
	strh r4, [r2, #0x24]
	movs r5, #0x20
	strh r5, [r2, #0x26]
	strh r5, [r2, #0x28]
	adds r0, r7, #0
	adds r0, #0x36
	strb r6, [r0]
	strh r4, [r2, #0x2e]
	adds r0, r2, #0
	bl DrawBackground
	adds r2, r7, #0
	adds r2, #0x4c
	ldr r0, _0802814C @ =0x06008000
	str r0, [r2, #4]
	strh r4, [r2, #0xa]
	ldr r0, _08028150 @ =0x0600E000
	str r0, [r2, #0xc]
	strh r4, [r2, #0x18]
	strh r4, [r2, #0x1a]
	ldr r1, _08028154 @ =gLoadedSaveGame
	ldr r0, _08028158 @ =0x00000366
	adds r1, r1, r0
	ldr r3, _0802815C @ =0x00000177
	adds r0, r3, #0
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	strh r4, [r2, #0x1e]
	strh r4, [r2, #0x20]
	strh r4, [r2, #0x22]
	strh r4, [r2, #0x24]
	strh r5, [r2, #0x26]
	strh r5, [r2, #0x28]
	adds r0, r7, #0
	adds r0, #0x76
	strb r6, [r0]
	movs r0, #0x11
	strh r0, [r2, #0x2e]
	adds r0, r2, #0
	bl DrawBackground
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028134: .4byte gBgCntRegs
_08028138: .4byte 0x00001E0F
_0802813C: .4byte 0x00001C0A
_08028140: .4byte 0x0600C000
_08028144: .4byte 0x0600F000
_08028148: .4byte 0x00000189
_0802814C: .4byte 0x06008000
_08028150: .4byte 0x0600E000
_08028154: .4byte gLoadedSaveGame
_08028158: .4byte 0x00000366
_0802815C: .4byte 0x00000177

.syntax divided
