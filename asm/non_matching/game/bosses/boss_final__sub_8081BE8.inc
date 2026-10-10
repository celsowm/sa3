.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	beq _08081BFA
	cmp r1, #1
	beq _08081BFE
	b _08081C02
_08081BFA:
	movs r0, #0xa
	b _08081C00
_08081BFE:
	movs r0, #0x64
_08081C00:
	strh r0, [r2, #0xc]
_08081C02:
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
