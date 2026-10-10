.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _080817D8 @ =Task_ExtraChaosEmeraldsInit
	movs r1, #0xe0
	lsls r1, r1, #1
	movs r2, #0x88
	lsls r2, r2, #6
	ldr r3, _080817DC @ =TaskDestructor_ExtraChaosEmeralds
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r4, r0
	movs r1, #0
	strb r5, [r4]
	movs r0, #1
	strh r0, [r4, #0x10]
	strh r1, [r4, #0x12]
	strh r1, [r4, #0xc]
	strh r1, [r4, #0x16]
	strh r1, [r4, #0x14]
	movs r0, #0x1c
	bl VramMalloc
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl InitChaosEmeraldSprites
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080817D8: .4byte Task_ExtraChaosEmeraldsInit
_080817DC: .4byte TaskDestructor_ExtraChaosEmeralds

.syntax divided
