.syntax unified
.text
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0xc]
	cmp r0, #0xa
	beq _0807CB90
	cmp r0, #0xa
	ble _0807CBC2
	cmp r0, #0x14
	beq _0807CBC2
	cmp r0, #0x64
	beq _0807CBB6
	b _0807CBC2
_0807CB90:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807CBC2
	movs r0, #0x14
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xa
	bl sub_807DB00
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xa
	bl sub_807DB00
	b _0807CBC2
_0807CBB6:
	movs r2, #0
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #8]
	strh r1, [r4, #0xc]
	strb r2, [r4, #1]
_0807CBC2:
	pop {r4}
	pop {r0}
	bx r0

.syntax divided
