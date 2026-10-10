.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080283B4 @ =gCurTask
	ldr r0, [r0]
	ldrh r6, [r0, #6]
	ldr r0, _080283B8 @ =0x030000F0
	adds r4, r6, r0
	ldrh r0, [r4]
	adds r0, #1
	ldr r5, _080283BC @ =0x000003FF
	ands r0, r5
	strh r0, [r4]
	ldrh r0, [r4]
	lsls r0, r0, #3
	ands r0, r5
	ldr r1, _080283C0 @ =0x0300008C
	adds r7, r6, r1
	ldr r1, _080283C4 @ =gSineTable
	mov r8, r1
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x1a
	adds r0, #8
	asrs r0, r0, #1
	adds r0, #0x67
	strh r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	adds r0, r7, #0
	bl DisplaySprite
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, #0x20
	ands r0, r5
	ldr r1, _080283C8 @ =0x030000B4
	adds r7, r6, r1
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x1a
	adds r0, #8
	asrs r0, r0, #1
	adds r0, #0x5d
	strh r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	adds r0, r7, #0
	bl DisplaySprite
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080283B4: .4byte gCurTask
_080283B8: .4byte 0x030000F0
_080283BC: .4byte 0x000003FF
_080283C0: .4byte 0x0300008C
_080283C4: .4byte gSineTable
_080283C8: .4byte 0x030000B4

.syntax divided
