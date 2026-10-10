.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r2, #0
	ldrh r1, [r4, #0xc]
	cmp r1, #0xa
	beq _0807C7EC
	cmp r1, #0xa
	bgt _0807C746
	cmp r1, #0
	beq _0807C752
	b _0807C892
_0807C746:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _0807C750
	b _0807C86C
_0807C750:
	b _0807C892
_0807C752:
	movs r3, #0
	ldr r0, _0807C7DC @ =gPseudoRandom
	mov sl, r0
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r1, r4
	mov ip, r1
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r7, r4, r2
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r6, r4, r0
	movs r1, #0x90
	lsls r1, r1, #1
	adds r5, r4, r1
	adds r2, #0x90
	mov sb, r2
	mov r8, r3
_0807C778:
	lsls r1, r3, #3
	subs r1, r1, r3
	lsls r1, r1, #2
	adds r0, r4, r1
	add r0, sb
	mov r2, r8
	strh r2, [r0]
	mov r0, ip
	adds r2, r0, r1
	ldr r0, [r7]
	str r0, [r2]
	adds r1, r6, r1
	ldr r0, [r5]
	ldr r2, _0807C7E0 @ =0xFFFFE000
	adds r0, r0, r2
	str r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #2
	bls _0807C778
	mov r0, sl
	ldr r1, [r0]
	ldr r0, _0807C7E4 @ =0x00196225
	muls r0, r1, r0
	ldr r1, _0807C7E8 @ =0x3C6EF35F
	adds r0, r0, r1
	mov r2, sl
	str r0, [r2]
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #2]
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r4, #0xa]
	strh r1, [r4, #8]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl sub_807DB00
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl sub_807DB00
	b _0807C892
	.align 2, 0
_0807C7DC: .4byte gPseudoRandom
_0807C7E0: .4byte 0xFFFFE000
_0807C7E4: .4byte 0x00196225
_0807C7E8: .4byte 0x3C6EF35F
_0807C7EC:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0807C800
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807C808
	b _0807C80C
_0807C800:
	ldrh r0, [r4, #0x16]
	cmp r0, #0
	beq _0807C808
	movs r2, #1
_0807C808:
	cmp r2, #0
	beq _0807C842
_0807C80C:
	movs r3, #0
	movs r6, #0xd6
	lsls r6, r6, #1
	movs r5, #0xd4
	lsls r5, r5, #1
	movs r2, #0xef
_0807C818:
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #1
	bne _0807C82C
	adds r0, r1, r5
	strh r2, [r0]
_0807C82C:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #2
	bls _0807C818
	movs r0, #0x3c
	strh r0, [r4, #8]
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	b _0807C892
_0807C842:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807C892
	adds r0, r4, #0
	bl sub_807CD4C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C866
	adds r0, r4, #0
	bl sub_807CDF0
	movs r0, #0x3c
	strh r0, [r4, #8]
	b _0807C892
_0807C866:
	movs r0, #1
	strh r0, [r4, #8]
	b _0807C892
_0807C86C:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807C892
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
_0807C892:
	adds r0, r4, #0
	bl sub_807CFAC
	adds r0, r4, #0
	bl sub_807CCA8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
