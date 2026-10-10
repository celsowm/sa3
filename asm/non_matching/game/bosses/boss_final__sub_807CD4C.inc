.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807CD7E
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807CD7E
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807CD7E
	movs r0, #0
	b _0807CDE6
_0807CD7A:
	movs r7, #1
	b _0807CDE4
_0807CD7E:
	movs r5, #0
	ldr r6, _0807CDEC @ =0x000017FF
_0807CD82:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r3, r0, #2
	adds r0, r4, r3
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807CDDA
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r3
	subs r2, #0x78
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	subs r2, r2, r0
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r0, r3
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r1, r1, r3
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	bls _0807CD7A
_0807CDDA:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	bls _0807CD82
_0807CDE4:
	adds r0, r7, #0
_0807CDE6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807CDEC: .4byte 0x000017FF

.syntax divided
