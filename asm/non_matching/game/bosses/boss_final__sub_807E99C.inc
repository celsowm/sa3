.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r5, r4, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r3, r4, r0
	ldrh r0, [r5, #0x16]
	cmp r0, #0x1f
	bls _0807E9CA
	b _0807EBAC
_0807E9CA:
	lsls r0, r0, #2
	ldr r1, _0807E9D4 @ =_0807E9D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807E9D4: .4byte _0807E9D8
_0807E9D8: @ jump table
	.4byte _0807EA58 @ case 0
	.4byte _0807EBAC @ case 1
	.4byte _0807EBAC @ case 2
	.4byte _0807EBAC @ case 3
	.4byte _0807EBAC @ case 4
	.4byte _0807EBAC @ case 5
	.4byte _0807EBAC @ case 6
	.4byte _0807EBAC @ case 7
	.4byte _0807EBAC @ case 8
	.4byte _0807EBAC @ case 9
	.4byte _0807EADC @ case 10
	.4byte _0807EBAC @ case 11
	.4byte _0807EBAC @ case 12
	.4byte _0807EBAC @ case 13
	.4byte _0807EBAC @ case 14
	.4byte _0807EBAC @ case 15
	.4byte _0807EBAC @ case 16
	.4byte _0807EBAC @ case 17
	.4byte _0807EBAC @ case 18
	.4byte _0807EBAC @ case 19
	.4byte _0807EB1E @ case 20
	.4byte _0807EBAC @ case 21
	.4byte _0807EBAC @ case 22
	.4byte _0807EBAC @ case 23
	.4byte _0807EBAC @ case 24
	.4byte _0807EBAC @ case 25
	.4byte _0807EBAC @ case 26
	.4byte _0807EBAC @ case 27
	.4byte _0807EBAC @ case 28
	.4byte _0807EBAC @ case 29
	.4byte _0807EB3A @ case 30
	.4byte _0807EB6C @ case 31
_0807EA58:
	cmp r2, #0
	bne _0807EA6E
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	asrs r1, r1, #8
	ldr r0, [r5]
	asrs r0, r0, #8
	adds r0, #0x20
	b _0807EA7E
_0807EA6E:
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	asrs r1, r1, #8
	ldr r0, [r5]
	asrs r0, r0, #8
	subs r0, #0x20
_0807EA7E:
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807EAD4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	asrs r1, r1, #8
	ldr r0, [r5, #4]
	asrs r0, r0, #8
	subs r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0807EAD8 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, _0807EAD4 @ =0xFFFF0000
	mov r4, sp
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #8
	bl sa2__sub_8085A9C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r5, #8]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	str r0, [r5, #0xc]
	movs r0, #0xa
	b _0807EBAA
	.align 2, 0
_0807EAD4: .4byte 0xFFFF0000
_0807EAD8: .4byte 0x0000FFFF
_0807EADC:
	ldr r1, [r5]
	ldr r0, [r5, #8]
	adds r3, r1, r0
	str r3, [r5]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	cmp r2, #0
	bne _0807EB08
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r2, _0807EB04 @ =0xFFFFE000
	adds r0, r0, r2
	cmp r0, r3
	bgt _0807EBAC
	movs r0, #0x14
	b _0807EBAA
	.align 2, 0
_0807EB04: .4byte 0xFFFFE000
_0807EB08:
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	cmp r0, r3
	blt _0807EBAC
	movs r0, #0x14
	b _0807EBAA
_0807EB1E:
	cmp r2, #0
	beq _0807EBAC
	adds r1, r5, #0
	subs r1, #0x28
	ldrh r0, [r5, #0x16]
	cmp r0, #0x14
	bne _0807EBAC
	ldrh r0, [r1, #0x16]
	cmp r0, #0x14
	bne _0807EBAC
	movs r0, #0x1e
	strh r0, [r5, #0x16]
	strh r0, [r1, #0x16]
	b _0807EBAC
_0807EB3A:
	cmp r2, #0
	beq _0807EB44
	cmp r2, #1
	beq _0807EB54
	b _0807EB64
_0807EB44:
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, _0807EB50 @ =sBossFinalAnimsHands
	b _0807EB5C
	.align 2, 0
_0807EB50: .4byte sBossFinalAnimsHands
_0807EB54:
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r0, _0807EB68 @ =sBossFinalAnimsHands+0x18
_0807EB5C:
	ldrh r1, [r0, #0x10]
	strh r1, [r2, #0xc]
	ldrh r0, [r0, #0x12]
	strb r0, [r2, #0x1a]
_0807EB64:
	movs r0, #0x1f
	b _0807EBAA
	.align 2, 0
_0807EB68: .4byte sBossFinalAnimsHands+0x18
_0807EB6C:
	cmp r2, #0
	bne _0807EB94
	ldrh r0, [r3]
	subs r0, #8
	ldr r2, _0807EB90 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	bne _0807EBAC
	movs r0, #0x64
	strh r0, [r5, #0x16]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	b _0807EBAC
	.align 2, 0
_0807EB90: .4byte 0x000003FF
_0807EB94:
	ldrh r0, [r3]
	adds r0, #8
	ldr r2, _0807EBB4 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bne _0807EBAC
	movs r0, #0x64
_0807EBAA:
	strh r0, [r5, #0x16]
_0807EBAC:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807EBB4: .4byte 0x000003FF

.syntax divided
