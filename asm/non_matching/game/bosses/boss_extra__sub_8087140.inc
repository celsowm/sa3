.syntax unified
.text
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _08087170 @ =gBgOffsetsHBlankPrimary
	ldr r3, [r0]
	lsls r0, r1, #1
	adds r3, r3, r0
	cmp r1, r2
	bhs _08087168
_0808715A:
	strh r4, [r3]
	adds r3, #2
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r2
	blo _0808715A
_08087168:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08087170: .4byte gBgOffsetsHBlankPrimary

.syntax divided
