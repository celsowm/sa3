.syntax unified
.text
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	cmp r1, #0x64
	beq _0807C960
	cmp r1, #0x64
	bgt _0807C8CE
	cmp r1, #0xa
	beq _0807C90C
	cmp r1, #0xa
	bgt _0807C8C8
	cmp r1, #0
	beq _0807C8EA
	b _0807C9B8
_0807C8C8:
	cmp r1, #0x14
	beq _0807C91E
	b _0807C9B8
_0807C8CE:
	movs r5, #0xfa
	lsls r5, r5, #1
	cmp r1, r5
	beq _0807C988
	cmp r1, r5
	bgt _0807C8E0
	cmp r1, #0xc8
	beq _0807C97A
	b _0807C9B8
_0807C8E0:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	beq _0807C99E
	b _0807C9B8
_0807C8EA:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl sub_807DB00
	adds r0, r4, #0
	movs r1, #1
	movs r2, #2
	bl sub_807DB00
	movs r0, #0xf0
	strh r0, [r4, #8]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	b _0807C9B8
_0807C90C:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807C9B8
	movs r0, #0x14
	strh r0, [r4, #0xc]
	b _0807C9B8
_0807C91E:
	ldr r2, _0807C950 @ =gPseudoRandom
	ldr r1, [r2]
	ldr r0, _0807C954 @ =0x00196225
	muls r0, r1, r0
	ldr r1, _0807C958 @ =0x3C6EF35F
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0807C95C @ =0x00002710
	bl __umodsi3
	lsrs r0, r0, #2
	movs r1, #3
	ands r0, r1
	strb r0, [r4, #3]
	movs r0, #1
	strb r0, [r4, #2]
	ldrb r2, [r4, #3]
	adds r0, r4, #0
	movs r1, #1
	bl sub_807D8B4
	movs r0, #0x64
	strh r0, [r4, #0xc]
	b _0807C9B8
	.align 2, 0
_0807C950: .4byte gPseudoRandom
_0807C954: .4byte 0x00196225
_0807C958: .4byte 0x3C6EF35F
_0807C95C: .4byte 0x00002710
_0807C960:
	adds r0, r4, #0
	movs r1, #0
	bl sub_807D9B4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807C9B8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0xc8
	strh r0, [r4, #0xc]
	b _0807C9B8
_0807C97A:
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_807D8B4
	strh r5, [r4, #0xc]
	b _0807C9B8
_0807C988:
	adds r0, r4, #0
	movs r1, #1
	bl sub_807D9B4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807C9B8
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	b _0807C9B8
_0807C99E:
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
_0807C9B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
