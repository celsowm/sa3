.syntax unified
.text
	push {r4, lr}
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	cmp r3, #1
	beq _0807BEA4
	cmp r3, #1
	bgt _0807BE6E
	cmp r3, #0
	beq _0807BE74
	b _0807BEE8
_0807BE6E:
	cmp r3, #0xa
	beq _0807BECC
	b _0807BEE8
_0807BE74:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r4, #0x8e
	lsls r4, r4, #1
	adds r0, r2, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r4, #4
	adds r0, r2, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	movs r3, #0x97
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0xa
	b _0807BEE6
_0807BEA4:
	movs r4, #0x97
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r1]
	subs r4, #0xe
	adds r1, r2, r4
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r1]
	b _0807BEE8
_0807BECC:
	movs r4, #0x94
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0x80
	str r0, [r1]
	adds r0, #0xac
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0x97
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0x14
_0807BEE6:
	strh r0, [r1]
_0807BEE8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
