.syntax unified
.text
	movs r1, #0x3c
	strh r1, [r0, #0x14]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r2, _08081C20 @ =gUnknown_080D5C38
	ldrh r1, [r2]
	strh r1, [r0, #0xc]
	ldrh r1, [r2, #2]
	strb r1, [r0, #0x1a]
	bx lr
	.align 2, 0
_08081C20: .4byte gUnknown_080D5C38

.syntax divided
