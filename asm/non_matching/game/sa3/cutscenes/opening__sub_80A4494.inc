.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	movs r0, #3
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080A44C0
	ldr r1, [r2, #0x18]
	movs r3, #0x9b
	lsls r3, r3, #9
	cmp r1, r3
	bgt _080A44E0
	ldrb r0, [r2]
	lsls r0, r0, #0xa
	adds r0, r1, r0
	str r0, [r2, #0x18]
	ldr r1, _080A44BC @ =0x000135FF
	cmp r0, r1
	ble _080A44E0
	b _080A44D4
	.align 2, 0
_080A44BC: .4byte 0x000135FF
_080A44C0:
	ldr r1, [r2, #0x18]
	ldr r3, _080A44DC @ =0xFFFFBA00
	cmp r1, r3
	blt _080A44E0
	ldrb r0, [r2]
	lsls r0, r0, #0xa
	subs r0, r1, r0
	str r0, [r2, #0x18]
	cmp r0, r3
	bgt _080A44E0
_080A44D4:
	str r3, [r2, #0x18]
	movs r0, #1
	b _080A44E2
	.align 2, 0
_080A44DC: .4byte 0xFFFFBA00
_080A44E0:
	movs r0, #0
_080A44E2:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
