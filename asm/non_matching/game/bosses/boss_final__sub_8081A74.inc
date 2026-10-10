.syntax unified
.text
	push {lr}
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r1, #0
	bne _08081A98
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, _08081A9C @ =gUnknown_080D5C38
	lsls r2, r2, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	strh r0, [r3, #0xc]
	adds r1, #2
	adds r2, r2, r1
	ldrh r0, [r2]
	strb r0, [r3, #0x1a]
_08081A98:
	pop {r0}
	bx r0
	.align 2, 0
_08081A9C: .4byte gUnknown_080D5C38

.syntax divided
