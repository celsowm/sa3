.syntax unified
.text
	lsls r1, r1, #0x18
	ldr r2, _08087064 @ =0x00000814
	adds r0, r0, r2
	ldr r3, _08087068 @ =gUnknown_080D5D0C
	lsrs r1, r1, #0x16
	adds r2, r1, r3
	ldrh r2, [r2]
	strh r2, [r0, #0xc]
	adds r3, #2
	adds r1, r1, r3
	ldrh r1, [r1]
	strb r1, [r0, #0x1a]
	movs r1, #0xff
	strb r1, [r0, #0x1b]
	bx lr
	.align 2, 0
_08087064: .4byte 0x00000814
_08087068: .4byte gUnknown_080D5D0C

.syntax divided
