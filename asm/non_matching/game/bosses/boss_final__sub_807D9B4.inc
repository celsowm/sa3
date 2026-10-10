.syntax unified
.text
	push {r4, lr}
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0
	movs r3, #0
	cmp r1, #1
	beq _0807D9F2
	cmp r1, #1
	bgt _0807D9CE
	cmp r1, #0
	beq _0807D9D4
	b _0807DA2A
_0807D9CE:
	cmp r0, #2
	beq _0807DA10
	b _0807DA2A
_0807D9D4:
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _0807DA2A
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, r1
	bne _0807DA2A
	b _0807DA28
_0807D9F2:
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #1
	cmp r1, r0
	bne _0807DA2A
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, r1
	bne _0807DA2A
	b _0807DA28
_0807DA10:
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0x6e
	bne _0807DA2A
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #0x6e
	bne _0807DA2A
_0807DA28:
	movs r3, #1
_0807DA2A:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
