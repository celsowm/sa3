.syntax unified
.text
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802593C
	ldr r4, _08025944 @ =gMultiSioSend
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
	adds r0, r5, #0
	bl sub_8025BEC
	movs r0, #0
_0802593C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08025944: .4byte gMultiSioSend

.syntax divided
