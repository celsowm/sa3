.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldr r1, _080870DC @ =gUnknown_080D5D18
	ldrb r0, [r2, #0xa]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r2, #1]
	ldrb r0, [r2, #0xa]
	adds r0, #1
	strb r0, [r2, #0xa]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080870D0
	strb r1, [r2, #0xa]
_080870D0:
	movs r0, #1
	strh r0, [r2, #4]
	strh r1, [r2, #8]
	pop {r0}
	bx r0
	.align 2, 0
_080870DC: .4byte gUnknown_080D5D18

.syntax divided
