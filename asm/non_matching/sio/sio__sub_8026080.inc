.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080260E0 @ =gCurTask
	ldr r0, [r6]
	ldrh r5, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r5, r0
	adds r4, r0, #0
	bl UpdateScreenFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080260D8
	ldr r0, _080260E4 @ =0x0300008C
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r2, r0, #1
	movs r3, #0
	strh r2, [r1]
	ldr r0, _080260E8 @ =gPressedKeys
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080260B8
	lsls r0, r2, #0x10
	cmp r0, #0
	bne _080260D8
_080260B8:
	strh r3, [r4]
	movs r0, #1
	strh r0, [r4, #2]
	strh r3, [r4, #4]
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r4, #6]
	movs r0, #0xff
	strh r0, [r4, #8]
	strh r3, [r4, #0xa]
	adds r0, r4, #0
	bl ScreenFadeUpdateValues
	ldr r1, [r6]
	ldr r0, _080260EC @ =sub_802618C
	str r0, [r1, #8]
_080260D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080260E0: .4byte gCurTask
_080260E4: .4byte 0x0300008C
_080260E8: .4byte gPressedKeys
_080260EC: .4byte sub_802618C

.syntax divided
