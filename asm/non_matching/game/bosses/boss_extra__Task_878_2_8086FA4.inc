.syntax unified
.text
	push {r4, lr}
	ldr r0, _08086FDC @ =gCurTask
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_808211C
	ldr r1, _08086FE0 @ =gUnknown_08E2ED50
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl sub_8082388
	adds r0, r4, #0
	bl sub_8082D08
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086FDC: .4byte gCurTask
_08086FE0: .4byte gUnknown_08E2ED50

.syntax divided
