.syntax unified
.text
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	beq _0808171E
	bl VramFree
	movs r0, #0
	str r0, [r4, #0x7c]
_0808171E:
	pop {r4}
	pop {r0}
	bx r0

.syntax divided
