.syntax unified
.text
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _080243DC @ =gMultiSioSend
	ldr r3, _080243E0 @ =0x00006C08
	strh r3, [r2]
	strb r1, [r2, #4]
	adds r0, r0, r2
	strb r1, [r0, #5]
	bx lr
	.align 2, 0
_080243DC: .4byte gMultiSioSend
_080243E0: .4byte 0x00006C08

.syntax divided
