.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _080A274C @ =gCurTask
	ldr r0, [r6]
	ldrh r5, [r0, #6]
	ldr r1, _080A2750 @ =gDispCnt
	ldr r2, _080A2754 @ =0x00001641
	adds r0, r2, #0
	strh r0, [r1]
	bl sub_80A2DD8
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	bne _080A2768
	ldr r3, _080A2758 @ =0x0300013E
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_80A2978
	movs r0, #0
	bl sub_80A2A40
	bl sub_80A2D80
	bl sub_80A23A4
	ldr r2, _080A275C @ =0x0300013C
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080A2760
	subs r0, r2, #1
	strh r0, [r1]
	b _080A2768
	.align 2, 0
_080A274C: .4byte gCurTask
_080A2750: .4byte gDispCnt
_080A2754: .4byte 0x00001641
_080A2758: .4byte 0x0300013E
_080A275C: .4byte 0x0300013C
_080A2760:
	strh r4, [r1]
	ldr r1, [r6]
	ldr r0, _080A2770 @ =sub_80A2774
	str r0, [r1, #8]
_080A2768:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2770: .4byte sub_80A2774

.syntax divided
