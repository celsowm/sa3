.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _08086F3C @ =gCurTask
	ldr r0, [r5]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r4, r0
	ldr r0, _08086F40 @ =0x0000023F @ SE_EXTRA_BOSS_578
	bl m4aSongNumStart
	adds r0, r4, #0
	bl sub_808211C
	adds r0, r4, #0
	bl sub_8082388
	adds r0, r4, #0
	bl sub_8082794
	ldr r1, [r5]
	ldr r0, _08086F44 @ =sub_8086F48
	str r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086F3C: .4byte gCurTask
_08086F40: .4byte 0x0000023F
_08086F44: .4byte sub_8086F48

.syntax divided
