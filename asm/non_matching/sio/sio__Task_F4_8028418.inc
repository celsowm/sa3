.syntax unified
.text
	push {r4, lr}
	ldr r4, _08028444 @ =gCurTask
	ldr r0, [r4]
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	bl UpdateScreenFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802843E
	movs r0, #1
	movs r1, #4
	bl LaunchChaoMenu
	ldr r0, [r4]
	bl TaskDestroy
_0802843E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028444: .4byte gCurTask

.syntax divided
