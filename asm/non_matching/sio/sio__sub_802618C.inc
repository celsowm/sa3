.syntax unified
.text
	push {lr}
	ldr r0, _080261AC @ =gCurTask
	ldr r0, [r0]
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	bl UpdateScreenFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080261A8
	bl LaunchTitleScreen
_080261A8:
	pop {r0}
	bx r0
	.align 2, 0
_080261AC: .4byte gCurTask

.syntax divided
