.syntax unified
.text
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0802436C @ =gMultiSioSend
	ldr r3, _08024370 @ =0x00006C03
	strh r3, [r2]
	strb r1, [r2, #4]
	adds r0, r0, r2
	strb r1, [r0, #5]
	bx lr
	.align 2, 0
_0802436C: .4byte gMultiSioSend
_08024370: .4byte 0x00006C03

.syntax divided
