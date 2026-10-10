.syntax unified
.text
	push {r4, r5, lr}
	ldr r4, _08029354 @ =gCurTask
	ldr r0, [r4]
	ldrh r2, [r0, #6]
	ldr r3, _08029358 @ =gDispCnt
	ldrh r0, [r3]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0802935C @ =0x03000488
	adds r2, r2, r0
	movs r0, #0x78
	strh r0, [r2]
	ldr r0, _08029360 @ =0x0000032A     @ SE_VS__SELECT
	bl m4aSongNumStart
	ldr r1, [r4]
	ldr r0, _08029364 @ =sub_8028C94
	str r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029354: .4byte gCurTask
_08029358: .4byte gDispCnt
_0802935C: .4byte 0x03000488
_08029360: .4byte 0x0000032A
_08029364: .4byte sub_8028C94

.syntax divided
