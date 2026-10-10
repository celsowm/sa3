.syntax unified
.text
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080A2A50
	movs r1, #0
	b _080A2A56
_080A2A50:
	cmp r0, #7
	ble _080A2A56
	movs r1, #7
_080A2A56:
	lsls r0, r1, #0x10
	asrs r0, r0, #0xa
	ldr r1, _080A2A90 @ =Palette_unknown_424
	adds r6, r0, r1
	movs r0, #0
_080A2A60:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	bl sub_80C4C0C
	ldr r1, _080A2A94 @ =gBgPalette
	adds r5, r5, r1
	strh r0, [r5]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x1f
	ble _080A2A60
	ldr r0, _080A2A98 @ =gFlags
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2A90: .4byte Palette_unknown_424
_080A2A94: .4byte gBgPalette
_080A2A98: .4byte gFlags

.syntax divided
