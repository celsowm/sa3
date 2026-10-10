.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A27C4 @ =gCurTask
	ldr r0, [r6]
	ldrh r4, [r0, #6]
	bl sub_80A2DD8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A27E2
	ldr r0, _080A27C8 @ =0x0300013E
	adds r5, r4, r0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	bl sub_80A2978
	ldr r0, _080A27CC @ =0x0300013C
	adds r4, r4, r0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	bl sub_80A2A40
	bl sub_80A2D80
	bl sub_80A23A4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	bgt _080A27D0
	cmp r0, #0x20
	ble _080A27E2
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b _080A27E2
	.align 2, 0
_080A27C4: .4byte gCurTask
_080A27C8: .4byte 0x0300013E
_080A27CC: .4byte 0x0300013C
_080A27D0:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r0, #7
	bl sub_80A2A40
	ldr r1, [r6]
	ldr r0, _080A27E8 @ =sub_80A27EC
	str r0, [r1, #8]
_080A27E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A27E8: .4byte sub_80A27EC

.syntax divided
