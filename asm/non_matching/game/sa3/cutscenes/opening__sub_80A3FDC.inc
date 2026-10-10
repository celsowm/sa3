.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r3, [r6, #2]
	ldr r1, _080A407C @ =0x06010000
	adds r0, #0x2c
	str r1, [r6, #0x2c]
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r1, r1, r2
	str r1, [r6, #0x28]
	ldr r1, _080A4080 @ =gUnknown_080D99A8
	lsls r3, r3, #3
	adds r3, r3, r1
	ldrh r1, [r3]
	movs r5, #0
	movs r4, #0
	strh r1, [r0, #0xc]
	ldrb r1, [r3, #2]
	strb r1, [r0, #0x1a]
	movs r1, #0xff
	strb r1, [r0, #0x1b]
	ldr r1, [r6, #0x20]
	asrs r1, r1, #8
	strh r1, [r0, #0x10]
	ldr r1, [r6, #0x24]
	asrs r1, r1, #8
	strh r1, [r0, #0x12]
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0, #0x14]
	strh r4, [r0, #0xe]
	strh r4, [r0, #0x16]
	movs r1, #0x10
	strb r1, [r0, #0x1c]
	strb r5, [r0, #0x1f]
	str r4, [r0, #8]
	bl UpdateSpriteAnimation
	ldr r2, _080A4084 @ =gDispCnt
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A4088 @ =gBgCntRegs
	ldr r0, _080A408C @ =0x00005888
	strh r0, [r1]
	ldr r1, _080A4090 @ =gBgScrollRegs
	strh r4, [r1]
	movs r0, #0x6e
	strh r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x54
	ldr r1, _080A4094 @ =0x06008000
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _080A4098 @ =0x0600C000
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	ldr r1, _080A409C @ =0x0000012F
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	movs r1, #0x20
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	adds r1, r6, #0
	adds r1, #0x7e
	strb r5, [r1]
	movs r1, #4
	strh r1, [r0, #0x2e]
	bl DrawBackground
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A407C: .4byte 0x06010000
_080A4080: .4byte gUnknown_080D99A8
_080A4084: .4byte gDispCnt
_080A4088: .4byte gBgCntRegs
_080A408C: .4byte 0x00005888
_080A4090: .4byte gBgScrollRegs
_080A4094: .4byte 0x06008000
_080A4098: .4byte 0x0600C000
_080A409C: .4byte 0x0000012F

.syntax divided
