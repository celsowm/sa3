.syntax unified
.text
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _080243AC @ =gMultiSioSend
	ldr r3, _080243B0 @ =0x00006C07
	strh r3, [r2]
	strb r1, [r2, #4]
	adds r0, r0, r2
	strb r1, [r0, #5]
	bx lr
	.align 2, 0
_080243AC: .4byte gMultiSioSend
_080243B0: .4byte 0x00006C07

.syntax divided
