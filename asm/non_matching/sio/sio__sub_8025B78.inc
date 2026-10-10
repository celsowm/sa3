.syntax unified
.text
	push {r4, lr}
	ldr r4, _08025B9C @ =gMultiSioSend
	movs r0, #0
	strh r0, [r4, #0xc]
	bl sub_80247D4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	bl sub_80248F4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08025B9C: .4byte gMultiSioSend

.syntax divided
