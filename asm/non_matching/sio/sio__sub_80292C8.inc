.syntax unified
.text
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0
_080292CE:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	movs r0, #0xc8
	muls r0, r4, r0
	adds r0, r0, r5
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xb3
	lsls r1, r1, #3		@ r1 = ANIM_PALETTE_1432
	strh r1, [r0, #0xc]
	ldr r1, _0802931C @ =gStageData
	ldrb r1, [r1]
	lsls r3, r1, #1
	adds r3, r3, r1
	adds r3, #4
	ldr r2, _08029320 @ =0x00000492
	adds r1, r5, r2
	ldrb r2, [r1]
	lsls r1, r4, #1
	asrs r2, r1
	movs r1, #3
	ands r2, r1
	adds r3, r3, r2
	strb r3, [r0, #0x1a]
	movs r1, #0xff
	strb r1, [r0, #0x1b]
	bl UpdateSpriteAnimation
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _080292CE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802931C: .4byte gStageData
_08029320: .4byte 0x00000492

.syntax divided
