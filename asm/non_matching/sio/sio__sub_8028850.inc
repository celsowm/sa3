.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, _080288C8 @ =Task_80288F0
	ldr r1, _080288CC @ =0x00000494
	movs r2, #0x80
	lsls r2, r2, #5
	movs r6, #0
	str r6, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r4, [r0, #6]
	movs r5, #0xc0
	lsls r5, r5, #0x12
	adds r5, r4, r5
	ldr r1, _080288D0 @ =0x03000488
	adds r0, r4, r1
	movs r2, #0
	strh r6, [r0]
	ldr r0, _080288D4 @ =0x0300048A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080288D8 @ =0x0300048B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	bl sub_80293BC
	ldr r1, _080288DC @ =0x03000492
	adds r4, r4, r1
	strb r0, [r4]
	adds r0, r5, #0
	bl sub_8028DEC
	bl m4aMPlayAllStop
	ldr r0, _080288E0 @ =0x00000323     @ MUS_VS_BGM_9
	bl m4aSongNumStart
	movs r0, #0xa0
	lsls r0, r0, #0x13
	strh r6, [r0]
	ldr r0, _080288E4 @ =gBgPalette
	strh r6, [r0]
	ldr r2, _080288E8 @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _080288EC @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080288C8: .4byte Task_80288F0
_080288CC: .4byte 0x00000494
_080288D0: .4byte 0x03000488
_080288D4: .4byte 0x0300048A
_080288D8: .4byte 0x0300048B
_080288DC: .4byte 0x03000492
_080288E0: .4byte 0x00000323
_080288E4: .4byte gBgPalette
_080288E8: .4byte gDispCnt
_080288EC: .4byte 0x0000FEFF

.syntax divided
