.syntax unified
.text
	push {r4, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, [r1, #0x74]
	ldr r2, _080A17D4 @ =0x000104FF
	cmp r0, r2
	bgt _080A17B2
	movs r4, #0xc0
	lsls r4, r4, #3
	adds r0, r0, r4
	str r0, [r1, #0x74]
	cmp r0, r2
	ble _080A17B8
_080A17B2:
	ldr r0, _080A17D8 @ =0x00010500
	str r0, [r1, #0x74]
	movs r3, #1
_080A17B8:
	ldr r2, [r1, #0x7c]
	ldr r0, _080A17DC @ =0x000077FF
	cmp r2, r0
	bgt _080A17E0
	movs r4, #0xfc
	lsls r4, r4, #3
	adds r0, r2, r4
	str r0, [r1, #0x7c]
	movs r2, #0xf0
	lsls r2, r2, #7
	cmp r0, r2
	ble _080A17EC
	str r2, [r1, #0x7c]
	b _080A17E6
	.align 2, 0
_080A17D4: .4byte 0x000104FF
_080A17D8: .4byte 0x00010500
_080A17DC: .4byte 0x000077FF
_080A17E0:
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r1, #0x7c]
_080A17E6:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080A17EC:
	cmp r3, #2
	beq _080A17F4
	movs r0, #0
	b _080A17F6
_080A17F4:
	movs r0, #1
_080A17F6:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
