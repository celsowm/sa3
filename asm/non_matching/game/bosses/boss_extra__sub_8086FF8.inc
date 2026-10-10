.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	adds r0, #0xed
	strb r1, [r0]
	ldrb r0, [r0]
	cmp r0, #7
	beq _0808700C
	cmp r0, #8
	beq _0808701C
	b _0808702A
_0808700C:
	adds r1, r2, #0
	adds r1, #0xb0
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r1]
	adds r1, #4
	movs r0, #0
	b _08087028
_0808701C:
	adds r1, r2, #0
	adds r1, #0xa4
	ldr r0, _08087030 @ =0xFFFFFE00
	str r0, [r1]
	adds r1, #4
	ldr r0, _08087034 @ =0xFFFFFF00
_08087028:
	str r0, [r1]
_0808702A:
	pop {r0}
	bx r0
	.align 2, 0
_08087030: .4byte 0xFFFFFE00
_08087034: .4byte 0xFFFFFF00

.syntax divided
