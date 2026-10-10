.syntax unified
.text
	push {lr}
	movs r1, #0x90
	adds r0, #0xe8
	ldr r0, [r0]
	muls r0, r1, r0
	movs r1, #0x90
	lsls r1, r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x90
	bls _08028660
	movs r3, #0x90
_08028660:
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08028680 @ =gWinRegs
	ldr r0, _08028684 @ =0x0000B8D0
	strh r0, [r2]
	movs r0, #0x98
	subs r0, r0, r3
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0
_08028680: .4byte gWinRegs
_08028684: .4byte 0x0000B8D0

@ --- End of singlepak_connections.c in SA2 ---

.syntax divided
