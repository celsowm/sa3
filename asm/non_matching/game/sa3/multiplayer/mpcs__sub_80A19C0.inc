.syntax unified
.text
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrh r0, [r4, #0xa]
	adds r0, #0xc0
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x16
	ldrh r1, [r4, #0xc]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	movs r2, #0x80
	lsls r2, r2, #1
	movs r3, #0x40
	str r3, [sp]
	ldr r3, [r4, #0x6c]
	lsls r3, r3, #8
	asrs r3, r3, #0x10
	str r3, [sp, #4]
	ldr r3, [r4, #0x70]
	lsls r3, r3, #8
	asrs r3, r3, #0x10
	str r3, [sp, #8]
	ldr r3, _080A1A00 @ =gBgAffineRegs
	str r3, [sp, #0xc]
	movs r3, #0x40
	bl sa2__sub_8003EE4
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1A00: .4byte gBgAffineRegs

.syntax divided
