.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080818F4 @ =gCurTask
	ldr r0, [r6]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r1, r0
	ldr r4, [r5, #0x20]
	adds r0, r5, #0
	bl sub_807C14C
	adds r0, r5, #0
	bl sub_80816C0
	ldr r0, [r4, #0x10]
	asrs r0, r0, #8
	ldr r1, _080818F8 @ =0x0000066C
	cmp r0, r1
	ble _080818EC
	ldr r1, _080818FC @ =gCamera
	movs r0, #0x10
	str r0, [r1, #0x10]
	adds r0, r5, #0
	bl sub_807BCCC
	adds r0, r5, #0
	bl sub_807BEF0
	adds r0, r5, #0
	bl sub_807D6C4
	adds r0, r5, #0
	bl sub_807CBC8
	movs r1, #0
	strb r1, [r5, #0x10]
	movs r0, #1
	strh r0, [r5, #8]
	strh r1, [r5, #0xc]
	ldr r1, [r6]
	ldr r0, _08081900 @ =sub_807B9B8
	str r0, [r1, #8]
_080818EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080818F4: .4byte gCurTask
_080818F8: .4byte 0x0000066C
_080818FC: .4byte gCamera
_08081900: .4byte sub_807B9B8

.syntax divided
