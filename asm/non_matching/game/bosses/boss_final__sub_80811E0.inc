.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x4c
	adds r3, r5, #0
	adds r3, #0xd8
	ldrh r1, [r4, #0x18]
	ldr r2, _08081218 @ =0x000003F2
	cmp r1, r2
	bne _080811F6
	b _0808148E
_080811F6:
	cmp r1, r2
	bgt _08081260
	cmp r1, #0x32
	bne _08081200
	b _08081380
_08081200:
	cmp r1, #0x32
	bgt _0808122A
	cmp r1, #0x14
	bne _0808120A
	b _08081328
_0808120A:
	cmp r1, #0x14
	bgt _0808121C
	cmp r1, #0
	beq _08081300
	cmp r1, #0xa
	beq _08081308
	b _080816B8
	.align 2, 0
_08081218: .4byte 0x000003F2
_0808121C:
	cmp r1, #0x1e
	bne _08081222
	b _08081340
_08081222:
	cmp r1, #0x28
	bne _08081228
	b _0808135E
_08081228:
	b _080816B8
_0808122A:
	cmp r1, #0x50
	bne _08081230
	b _080813EC
_08081230:
	cmp r1, #0x50
	bgt _08081242
	cmp r1, #0x3c
	bne _0808123A
	b _080813A4
_0808123A:
	cmp r1, #0x46
	bne _08081240
	b _080813CC
_08081240:
	b _080816B8
_08081242:
	cmp r1, #0x64
	bne _08081248
	b _08081464
_08081248:
	cmp r1, #0x64
	bgt _08081254
	cmp r1, #0x5a
	bne _08081252
	b _08081420
_08081252:
	b _080816B8
_08081254:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _0808125E
	b _08081486
_0808125E:
	b _080816B8
_08081260:
	ldr r6, _08081290 @ =0x0000042E
	cmp r1, r6
	bne _08081268
	b _08081598
_08081268:
	cmp r1, r6
	bgt _080812AC
	movs r2, #0x82
	lsls r2, r2, #3
	cmp r1, r2
	bne _08081276
	b _08081504
_08081276:
	cmp r1, r2
	bgt _08081294
	movs r0, #0xff
	lsls r0, r0, #2
	cmp r1, r0
	bne _08081284
	b _080814B0
_08081284:
	adds r0, #0xa
	cmp r1, r0
	bne _0808128C
	b _080814CC
_0808128C:
	b _080816B8
	.align 2, 0
_08081290: .4byte 0x0000042E
_08081294:
	ldr r0, _080812A8 @ =0x0000041A
	cmp r1, r0
	bne _0808129C
	b _08081544
_0808129C:
	adds r0, #0xa
	cmp r1, r0
	bne _080812A4
	b _08081570
_080812A4:
	b _080816B8
	.align 2, 0
_080812A8: .4byte 0x0000041A
_080812AC:
	ldr r6, _080812CC @ =0x00000442
	cmp r1, r6
	bne _080812B4
	b _0808163C
_080812B4:
	cmp r1, r6
	bgt _080812D4
	ldr r0, _080812D0 @ =0x00000433
	cmp r1, r0
	bne _080812C0
	b _080815E6
_080812C0:
	adds r0, #5
	cmp r1, r0
	bne _080812C8
	b _08081600
_080812C8:
	b _080816B8
	.align 2, 0
_080812CC: .4byte 0x00000442
_080812D0: .4byte 0x00000433
_080812D4:
	ldr r2, _080812EC @ =0x00000456
	cmp r1, r2
	bne _080812DC
	b _0808168C
_080812DC:
	cmp r1, r2
	bgt _080812F4
	ldr r0, _080812F0 @ =0x0000044C
	cmp r1, r0
	bne _080812E8
	b _08081664
_080812E8:
	b _080816B8
	.align 2, 0
_080812EC: .4byte 0x00000456
_080812F0: .4byte 0x0000044C
_080812F4:
	movs r0, #0x8c
	lsls r0, r0, #3
	cmp r1, r0
	bne _080812FE
	b _080816A8
_080812FE:
	b _080816B8
_08081300:
	movs r0, #0x4b
	strh r0, [r4, #0x14]
	movs r0, #0xa
	b _080816B6
_08081308:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	beq _08081318
	b _080816B8
_08081318:
	str r0, [r4, #8]
	ldr r0, _08081324 @ =0xFFFFFF00
	str r0, [r4, #0xc]
	movs r0, #0x14
	b _080816B6
	.align 2, 0
_08081324: .4byte 0xFFFFFF00
_08081328:
	ldr r0, [r4, #4]
	ldr r1, [r4, #0xc]
	adds r0, r0, r1
	str r0, [r4, #4]
	asrs r0, r0, #8
	cmp r0, #0x8e
	ble _08081338
	b _080816B8
_08081338:
	movs r0, #0x28
	strh r0, [r4, #0x14]
	movs r0, #0x1e
	b _080816B6
_08081340:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08081350
	b _080816B8
_08081350:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	movs r0, #0x28
	strh r0, [r4, #0x18]
	b _080814E6
_0808135E:
	ldr r0, [r5, #0x4c]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	str r0, [r5, #0x4c]
	asrs r0, r0, #8
	ldr r1, _0808137C @ =0x00000819
	cmp r0, r1
	bgt _08081370
	b _080816B8
_08081370:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #8]
	movs r0, #0x32
	b _080816B6
	.align 2, 0
_0808137C: .4byte 0x00000819
_08081380:
	ldr r0, [r5, #0x4c]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	str r0, [r5, #0x4c]
	asrs r0, r0, #8
	ldr r1, _080813A0 @ =0x000008F2
	cmp r0, r1
	bgt _08081392
	b _080816B8
_08081392:
	movs r0, #0
	str r0, [r4, #8]
	movs r0, #0x80
	str r0, [r4, #0xc]
	movs r0, #0x3c
	strh r0, [r4, #0x14]
	b _080816B6
	.align 2, 0
_080813A0: .4byte 0x000008F2
_080813A4:
	ldr r0, [r4, #4]
	ldr r1, [r4, #0xc]
	adds r0, r0, r1
	str r0, [r4, #4]
	asrs r0, r0, #8
	cmp r0, #0xb3
	bgt _080813B4
	b _080816B8
_080813B4:
	ldr r0, _080813C8 @ =0x0000050B
	strh r0, [r3, #0xc]
	movs r0, #1
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	movs r0, #0x14
	strh r0, [r4, #0x14]
	movs r0, #0x46
	b _080816B6
	.align 2, 0
_080813C8: .4byte 0x0000050B
_080813CC:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080813DA
	b _080816B8
_080813DA:
	movs r0, #0x3c
	strh r0, [r4, #0x14]
	movs r0, #0x50
	strh r0, [r4, #0x18]
	ldr r0, _080813E8 @ =0x00000506
	b _08081586
	.align 2, 0
_080813E8: .4byte 0x00000506
_080813EC:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080813FA
	b _080816B8
_080813FA:
	movs r0, #0x96
	strh r0, [r4, #0x14]
	movs r0, #0x5a
	strh r0, [r4, #0x18]
	ldr r0, _08081418 @ =0x0000050B
	strh r0, [r3, #0xc]
	movs r0, #2
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	ldr r0, [r3, #8]
	ldr r1, _0808141C @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r3, #8]
	b _080816B8
	.align 2, 0
_08081418: .4byte 0x0000050B
_0808141C: .4byte 0xFFFFFBFF
_08081420:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808142E
	b _080816B8
_0808142E:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #8]
	ldr r0, _0808145C @ =0xFFFFFC00
	str r0, [r4, #0xc]
	ldr r0, _08081460 @ =0x0000050A
	strh r0, [r3, #0xc]
	movs r0, #0
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r3, #8]
	movs r0, #0x64
	strh r0, [r4, #0x18]
	movs r0, #0x74      @ SE_JUMP
	bl m4aSongNumStart
	b _080816B8
	.align 2, 0
_0808145C: .4byte 0xFFFFFC00
_08081460: .4byte 0x0000050A
_08081464:
	ldr r0, [r4, #0xc]
	adds r0, #0x2a
	str r0, [r4, #0xc]
	ldr r0, [r5, #0x4c]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	str r0, [r5, #0x4c]
	ldr r0, [r4, #4]
	ldr r1, [r4, #0xc]
	adds r0, r0, r1
	str r0, [r4, #4]
	asrs r0, r0, #8
	cmp r0, #0xf9
	bgt _08081482
	b _080816B8
_08081482:
	movs r0, #0xc8
	b _080816B6
_08081486:
	movs r0, #0x4b
	strh r0, [r4, #0x14]
	strh r2, [r4, #0x18]
	b _080816B8
_0808148E:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	beq _0808149E
	b _080816B8
_0808149E:
	str r0, [r4, #8]
	ldr r0, _080814AC @ =0xFFFFFF00
	str r0, [r4, #0xc]
	movs r0, #0xff
	lsls r0, r0, #2
	b _080816B6
	.align 2, 0
_080814AC: .4byte 0xFFFFFF00
_080814B0:
	ldr r0, [r4, #4]
	ldr r1, [r4, #0xc]
	adds r0, r0, r1
	str r0, [r4, #4]
	asrs r0, r0, #8
	cmp r0, #0x8e
	ble _080814C0
	b _080816B8
_080814C0:
	movs r0, #0x28
	strh r0, [r4, #0x14]
	ldr r0, _080814C8 @ =0x00000406
	b _080816B6
	.align 2, 0
_080814C8: .4byte 0x00000406
_080814CC:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _080814DC
	b _080816B8
_080814DC:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	strh r2, [r4, #0x18]
_080814E6:
	ldr r0, _08081500 @ =0x0000050A
	strh r0, [r3, #0xc]
	movs r0, #0
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r3, #8]
	b _080816B8
	.align 2, 0
_08081500: .4byte 0x0000050A
_08081504:
	ldr r0, [r5, #0x4c]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	str r0, [r5, #0x4c]
	asrs r1, r0, #8
	ldr r0, _08081528 @ =0x000008AB
	cmp r1, r0
	ble _08081530
	movs r0, #0
	str r0, [r4, #8]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0xc]
	movs r0, #0x3c
	strh r0, [r4, #0x14]
	ldr r0, _0808152C @ =0x0000041A
	b _080816B6
	.align 2, 0
_08081528: .4byte 0x000008AB
_0808152C: .4byte 0x0000041A
_08081530:
	ldr r0, _08081540 @ =0x0000076B
	cmp r1, r0
	bgt _08081538
	b _080816B8
_08081538:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #8]
	b _080816B8
	.align 2, 0
_08081540: .4byte 0x0000076B
_08081544:
	ldr r0, [r4, #4]
	ldr r1, [r4, #0xc]
	adds r0, r0, r1
	str r0, [r4, #4]
	asrs r0, r0, #8
	cmp r0, #0xb3
	bgt _08081554
	b _080816B8
_08081554:
	ldr r0, _08081568 @ =0x0000050B
	strh r0, [r3, #0xc]
	movs r0, #1
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	movs r0, #0x14
	strh r0, [r4, #0x14]
	ldr r0, _0808156C @ =0x00000424
	b _080816B6
	.align 2, 0
_08081568: .4byte 0x0000050B
_0808156C: .4byte 0x00000424
_08081570:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808157E
	b _080816B8
_0808157E:
	movs r0, #0xb4
	strh r0, [r4, #0x14]
	strh r6, [r4, #0x18]
	ldr r0, _08081594 @ =0x00000509
_08081586:
	strh r0, [r3, #0xc]
	movs r0, #0
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	b _080816B8
	.align 2, 0
_08081594: .4byte 0x00000509
_08081598:
	ldrh r0, [r4, #0x14]
	subs r1, r0, #1
	strh r1, [r4, #0x14]
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _080815D4
	movs r0, #0xa
	strh r0, [r4, #0x14]
	ldr r0, _080815C8 @ =0x00000433
	strh r0, [r4, #0x18]
	adds r0, #0xd8
	strh r0, [r3, #0xc]
	movs r0, #0
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	ldr r0, [r3, #8]
	ldr r1, _080815CC @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r3, #8]
	ldr r0, _080815D0 @ =0x00000223
	bl m4aSongNumStart
	b _080816B8
	.align 2, 0
_080815C8: .4byte 0x00000433
_080815CC: .4byte 0xFFFFFBFF
_080815D0: .4byte 0x00000223
_080815D4:
	movs r0, #0x3f
	ands r1, r0
	cmp r1, #0
	bne _080816B8
	movs r0, #0x89
	lsls r0, r0, #2
	bl m4aSongNumStart
	b _080816B8
_080815E6:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080816B8
	ldr r0, _080815FC @ =0xFFFFFC00
	str r0, [r4, #8]
	movs r0, #0x87
	lsls r0, r0, #3
	b _080816B6
	.align 2, 0
_080815FC: .4byte 0xFFFFFC00
_08081600:
	ldr r0, [r5, #0x4c]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	str r0, [r5, #0x4c]
	asrs r0, r0, #8
	ldr r1, _08081630 @ =0x0000085C
	cmp r0, r1
	bgt _080816B8
	movs r1, #0
	movs r2, #0
	ldr r0, _08081634 @ =0x00000509
	strh r0, [r3, #0xc]
	strb r1, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	str r2, [r4, #8]
	str r2, [r4, #0xc]
	movs r0, #0x78
	strh r0, [r4, #0x14]
	strh r6, [r4, #0x18]
	ldr r0, _08081638 @ =0x00000223
	bl m4aSongNumStop
	b _080816B8
	.align 2, 0
_08081630: .4byte 0x0000085C
_08081634: .4byte 0x00000509
_08081638: .4byte 0x00000223
_0808163C:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080816B8
	ldr r0, _0808165C @ =0x000005CA
	strh r0, [r3, #0xc]
	movs r0, #0
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	movs r0, #0xb4
	strh r0, [r4, #0x14]
	ldr r0, _08081660 @ =0x0000044C
	b _080816B6
	.align 2, 0
_0808165C: .4byte 0x000005CA
_08081660: .4byte 0x0000044C
_08081664:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080816B8
	ldr r0, _08081688 @ =0x000005CA
	strh r0, [r3, #0xc]
	movs r0, #1
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r4, #0xc]
	strh r2, [r4, #0x18]
	b _080816B8
	.align 2, 0
_08081688: .4byte 0x000005CA
_0808168C:
	ldr r0, [r4, #4]
	ldr r1, [r4, #0xc]
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _080816A4 @ =gBldRegs
	ldrh r0, [r0, #4]
	cmp r0, #0x10
	bne _080816B8
	movs r0, #0x8c
	lsls r0, r0, #3
	b _080816B6
	.align 2, 0
_080816A4: .4byte gBldRegs
_080816A8:
	ldr r0, [r5, #0x10]
	bl VramFree
	movs r0, #0
	str r0, [r5, #0x10]
	movs r0, #0xfa
	lsls r0, r0, #3
_080816B6:
	strh r0, [r4, #0x18]
_080816B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
