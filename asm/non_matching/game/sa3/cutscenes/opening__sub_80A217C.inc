.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r0, #0x68
	ldr r2, _080A2274 @ =gDispCnt
	movs r1, #0x42
	strh r1, [r2]
	ldr r2, _080A2278 @ =gBgCntRegs
	movs r7, #0
	movs r4, #0
	ldr r1, _080A227C @ =0x00001F0C
	strh r1, [r2]
	ldr r1, _080A2280 @ =0x00001708
	strh r1, [r2, #2]
	ldr r1, _080A2284 @ =0x00006B81
	strh r1, [r2, #4]
	ldr r1, _080A2288 @ =gBgScrollRegs
	strh r4, [r1]
	strh r4, [r1, #2]
	movs r2, #0x10
	strh r2, [r1, #4]
	movs r2, #0x74
	strh r2, [r1, #6]
	strh r4, [r1, #8]
	strh r4, [r1, #0xa]
	strh r4, [r1, #0xc]
	strh r4, [r1, #0xe]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _080A228C @ =0x06005800
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	movs r1, #0xd4
	lsls r1, r1, #1         @ 424 - Opening Sky/Grass Tilemap
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	movs r6, #0x20
	strh r6, [r0, #0x26]
	strh r6, [r0, #0x28]
	adds r1, r5, #0
	adds r1, #0x92
	strb r7, [r1]
	adds r1, #1
	strb r7, [r1]
	adds r1, #1
	strb r7, [r1]
	movs r1, #6
	strh r1, [r0, #0x2e]
	strh r4, [r0, #0x30]
	strh r4, [r0, #0x32]
	bl DrawBackground
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	beq _080A2200
	cmp r0, #5
	bne _080A2242
_080A2200:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, _080A2290 @ =0x06008000
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _080A2294 @ =0x0600B800
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	ldr r1, _080A2298 @ =0x000001A7 @ Opening Circular Flash
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	strh r6, [r0, #0x26]
	strh r6, [r0, #0x28]
	movs r2, #0x89
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r7, [r1]
	adds r2, #1
	adds r1, r5, r2
	strb r7, [r1]
	adds r2, #1
	adds r1, r5, r2
	strb r7, [r1]
	movs r1, #0x11
	strh r1, [r0, #0x2e]
	strh r4, [r0, #0x30]
	strh r4, [r0, #0x32]
	bl DrawBackground
_080A2242:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080A22DA
	adds r3, r5, #0
	adds r3, #0xa8
	ldr r0, _080A229C @ =0x0600C000
	str r0, [r3, #4]
	movs r1, #0
	strh r1, [r3, #0xa]
	ldr r0, _080A22A0 @ =0x0600F800
	str r0, [r3, #0xc]
	strh r1, [r3, #0x18]
	strh r1, [r3, #0x1a]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #1
	bne _080A22A8
	ldr r0, _080A22A4 @ =0x000001A9 @ Presented by SEGA logo
	b _080A22AC
	.align 2, 0
_080A2274: .4byte gDispCnt
_080A2278: .4byte gBgCntRegs
_080A227C: .4byte 0x00001F0C
_080A2280: .4byte 0x00001708
_080A2284: .4byte 0x00006B81
_080A2288: .4byte gBgScrollRegs
_080A228C: .4byte 0x06005800
_080A2290: .4byte 0x06008000
_080A2294: .4byte 0x0600B800
_080A2298: .4byte 0x000001A7
_080A229C: .4byte 0x0600C000
_080A22A0: .4byte 0x0600F800
_080A22A4: .4byte 0x000001A9
_080A22A8:
	movs r0, #0xd5
	lsls r0, r0, #1         @ Create by Sonic Team Logo
_080A22AC:
	strh r0, [r3, #0x1c]
	movs r2, #0
	movs r1, #0
	strh r1, [r3, #0x1e]
	strh r1, [r3, #0x20]
	strh r1, [r3, #0x22]
	strh r1, [r3, #0x24]
	movs r0, #0x20
	strh r0, [r3, #0x26]
	strh r0, [r3, #0x28]
	adds r0, r3, #0
	adds r0, #0x2a
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	strh r1, [r3, #0x2e]
	strh r1, [r3, #0x30]
	strh r1, [r3, #0x32]
	adds r0, r3, #0
	bl DrawBackground
_080A22DA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
