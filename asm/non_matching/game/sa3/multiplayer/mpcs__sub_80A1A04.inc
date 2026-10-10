.syntax unified
.text
	ldr r2, _080A1A24 @ =gBgScrollRegs
	ldr r1, [r0, #0x74]
	asrs r1, r1, #8
	strh r1, [r2, #4]
	ldr r1, [r0, #0x78]
	asrs r1, r1, #8
	rsbs r1, r1, #0
	strh r1, [r2, #6]
	ldr r1, [r0, #0x7c]
	asrs r1, r1, #8
	strh r1, [r2]
	adds r0, #0x80
	ldr r0, [r0]
	asrs r0, r0, #8
	strh r0, [r2, #2]
	bx lr
	.align 2, 0
_080A1A24: .4byte gBgScrollRegs

.syntax divided
