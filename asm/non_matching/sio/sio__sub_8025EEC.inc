.syntax unified
.text
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	ldr r1, _0802601C @ =gTilemapsRef
	ldr r0, _08026020 @ =gTilemaps
	str r0, [r1]
	ldr r0, _08026024 @ =gStageData
	mov sb, r0
	ldr r0, _08026028 @ =gLoadedSaveGame
	ldr r1, _0802602C @ =0x00000366
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r4, #0
	mov r2, sb
	strb r0, [r2]
	ldr r0, _08026030 @ =sub_8026080
	movs r2, #0x80
	lsls r2, r2, #6
	str r4, [sp]
	movs r1, #0x90
	movs r3, #0
	bl TaskCreate
	ldrh r6, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r6, r0
	ldr r3, _08026034 @ =0x0300008C
	adds r2, r6, r3
	movs r1, #0
	mov r8, r1
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r2]
	ldr r2, _08026038 @ =gDispCnt
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r3, #0
	strh r1, [r2]
	strh r4, [r0]
	movs r1, #2
	strh r1, [r0, #2]
	strh r4, [r0, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	strh r1, [r0, #6]
	movs r1, #0xff
	strh r1, [r0, #8]
	strh r4, [r0, #0xa]
	bl ScreenFadeUpdateValues
	ldr r1, _0802603C @ =gBgCntRegs
	ldr r0, _08026040 @ =0x00001F0D
	strh r0, [r1]
	ldr r0, _08026044 @ =0x00001708
	strh r0, [r1, #2]
	ldr r0, _08026048 @ =gBgScrollRegs
	strh r4, [r0]
	strh r4, [r0, #2]
	strh r4, [r0, #4]
	strh r4, [r0, #6]
	ldr r0, _0802604C @ =0x0300004C
	adds r1, r6, r0
	ldr r0, _08026050 @ =0x0600C000
	str r0, [r1, #4]
	strh r4, [r1, #0xa]
	ldr r0, _08026054 @ =0x0600F800
	str r0, [r1, #0xc]
	strh r4, [r1, #0x18]
	strh r4, [r1, #0x1a]
	movs r0, #0xc5
	lsls r0, r0, #1
	strh r0, [r1, #0x1c]
	strh r4, [r1, #0x1e]
	strh r4, [r1, #0x20]
	strh r4, [r1, #0x22]
	strh r4, [r1, #0x24]
	movs r5, #0x20
	strh r5, [r1, #0x26]
	strh r5, [r1, #0x28]
	ldr r2, _08026058 @ =0x03000076
	adds r0, r6, r2
	mov r3, r8
	strb r3, [r0]
	strh r4, [r1, #0x2e]
	adds r0, r1, #0
	bl DrawBackground
	ldr r0, _0802605C @ =0x0300000C
	adds r1, r6, r0
	ldr r0, _08026060 @ =0x06008000
	str r0, [r1, #4]
	strh r4, [r1, #0xa]
	ldr r0, _08026064 @ =0x0600B800
	str r0, [r1, #0xc]
	strh r4, [r1, #0x18]
	strh r4, [r1, #0x1a]
	ldr r2, _08026068 @ =0x00000183
	adds r0, r2, #0
	mov r3, sb
	ldrb r3, [r3]
	adds r0, r0, r3
	strh r0, [r1, #0x1c]
	strh r4, [r1, #0x1e]
	strh r4, [r1, #0x20]
	strh r4, [r1, #0x22]
	strh r4, [r1, #0x24]
	strh r5, [r1, #0x26]
	strh r5, [r1, #0x28]
	ldr r0, _0802606C @ =0x03000036
	adds r6, r6, r0
	mov r2, r8
	strb r2, [r6]
	movs r0, #0x11
	strh r0, [r1, #0x2e]
	adds r0, r1, #0
	bl DrawBackground
	bl m4aMPlayAllStop
	movs r0, #0x64      @ MUS_VS_MISS
	bl m4aSongNumStart
	ldr r2, _08026070 @ =gFlags
	ldr r0, [r2]
	ldr r1, _08026074 @ =0xFFFFBFFF
	ands r0, r1
	ldr r1, _08026078 @ =0xFFFF7FFF
	ands r0, r1
	str r0, [r2]
	bl m4aSoundVSyncOn
	bl sub_8001E84
	ldr r0, _0802607C @ =gMultiSioEnabled
	mov r3, r8
	strb r3, [r0]
	bl MultiSioStop
	movs r0, #0
	bl MultiSioInit
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802601C: .4byte gTilemapsRef
_08026020: .4byte gTilemaps
_08026024: .4byte gStageData
_08026028: .4byte gLoadedSaveGame
_0802602C: .4byte 0x00000366
_08026030: .4byte sub_8026080
_08026034: .4byte 0x0300008C
_08026038: .4byte gDispCnt
_0802603C: .4byte gBgCntRegs
_08026040: .4byte 0x00001F0D
_08026044: .4byte 0x00001708
_08026048: .4byte gBgScrollRegs
_0802604C: .4byte 0x0300004C
_08026050: .4byte 0x0600C000
_08026054: .4byte 0x0600F800
_08026058: .4byte 0x03000076
_0802605C: .4byte 0x0300000C
_08026060: .4byte 0x06008000
_08026064: .4byte 0x0600B800
_08026068: .4byte 0x00000183
_0802606C: .4byte 0x03000036
_08026070: .4byte gFlags
_08026074: .4byte 0xFFFFBFFF
_08026078: .4byte 0xFFFF7FFF
_0802607C: .4byte gMultiSioEnabled

.syntax divided
