.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x60]
	movs r3, #0x91
	lsls r3, r3, #8
	cmp r1, r3
	bgt _080A189C
	str r3, [r2, #0x60]
	movs r0, #1
	b _080A18AC
_080A189C:
	ldr r0, _080A18B0 @ =0xFFFFFA00
	adds r1, r1, r0
	str r1, [r2, #0x60]
	ldr r0, _080A18B4 @ =0x000090FF
	cmp r1, r0
	bgt _080A18AA
	str r3, [r2, #0x60]
_080A18AA:
	movs r0, #0
_080A18AC:
	pop {r1}
	bx r1
	.align 2, 0
_080A18B0: .4byte 0xFFFFFA00
_080A18B4: .4byte 0x000090FF

.syntax divided
