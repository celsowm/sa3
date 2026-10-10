.syntax unified
.text
	push {r4, lr}
	sub sp, #4
	ldr r0, _08028830 @ =Task_80288F0
	ldr r1, _08028834 @ =0x00000494
	movs r2, #0x80
	lsls r2, r2, #5
	movs r4, #0
	str r4, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r1, r0
	ldr r3, _08028838 @ =0x03000488
	adds r2, r1, r3
	movs r3, #0
	strh r4, [r2]
	ldr r4, _0802883C @ =0x0300048A
	adds r2, r1, r4
	strb r3, [r2]
	adds r4, #1
	adds r2, r1, r4
	strb r3, [r2]
	adds r4, #1
	adds r2, r1, r4
	strb r3, [r2]
	adds r4, #1
	adds r2, r1, r4
	strb r3, [r2]
	ldr r2, _08028840 @ =0x03000492
	adds r1, r1, r2
	strb r3, [r1]
	bl sub_8028DEC
	bl m4aMPlayAllStop
	ldr r0, _08028844 @ =0x00000321     @ MUS_VS_BGM_6
	bl m4aSongNumStart
	ldr r2, _08028848 @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _0802884C @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028830: .4byte Task_80288F0
_08028834: .4byte 0x00000494
_08028838: .4byte 0x03000488
_0802883C: .4byte 0x0300048A
_08028840: .4byte 0x03000492
_08028844: .4byte 0x00000321
_08028848: .4byte gDispCnt
_0802884C: .4byte 0x0000FEFF

.syntax divided
