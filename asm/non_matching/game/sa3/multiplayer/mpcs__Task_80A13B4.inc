.syntax unified
.text
	push {r4, lr}
	ldr r4, _080A13D0 @ =gCurTask
	ldr r2, [r4]
	ldrh r0, [r2, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r1, r0, r1
	ldr r3, [r1, #0x18]
	ldrb r0, [r3]
	cmp r0, #0x22
	bne _080A13D8
	ldr r0, _080A13D4 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A13E8
	.align 2, 0
_080A13D0: .4byte gCurTask
_080A13D4: .4byte Task_80A14AC
_080A13D8:
	ldrb r0, [r1, #3]
	cmp r0, #0x25
	bne _080A13E8
	movs r0, #0x26
	strb r0, [r3]
	ldr r1, [r4]
	ldr r0, _080A13F0 @ =sub_80A0D20
	str r0, [r1, #8]
_080A13E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A13F0: .4byte sub_80A0D20

.syntax divided
