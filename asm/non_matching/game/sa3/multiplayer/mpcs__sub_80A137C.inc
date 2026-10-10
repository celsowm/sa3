.syntax unified
.text
	ldr r2, _080A13AC @ =gBgScrollRegs
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
	adds r1, r0, #0
	adds r1, #0x80
	ldr r1, [r1]
	asrs r1, r1, #8
	strh r1, [r2, #2]
	ldr r1, [r0, #0x6c]
	asrs r1, r1, #8
	strh r1, [r2, #8]
	ldr r0, [r0, #0x70]
	asrs r0, r0, #8
	rsbs r0, r0, #0
	strh r0, [r2, #0xa]
	bx lr
	.align 2, 0
_080A13AC: .4byte gBgScrollRegs

.syntax divided
