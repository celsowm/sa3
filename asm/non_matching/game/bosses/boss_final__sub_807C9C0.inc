.syntax unified
.text
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	cmp r1, #0xa
	beq _0807CA00
	cmp r1, #0xa
	bgt _0807C9D4
	cmp r1, #0
	beq _0807C9DE
	b _0807CA30
_0807C9D4:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	beq _0807CA16
	b _0807CA30
_0807C9DE:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	bl sub_807DB00
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	bl sub_807DB00
	movs r0, #0
	movs r1, #1
	strh r1, [r4, #8]
	strb r0, [r4, #0xe]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	b _0807CA30
_0807CA00:
	adds r0, r4, #0
	movs r1, #0
	bl sub_807D9B4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807CA30
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	b _0807CA30
_0807CA16:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #5
	bl sub_807DB00
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	bl sub_807DB00
	adds r0, r4, #0
	bl sub_8081BBC
_0807CA30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
