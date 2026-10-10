.syntax unified
.text
	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	adds r4, r0, #0
	lsls r2, r2, #0x18
	lsrs r1, r2, #0x18
	adds r2, r1, #0
	cmp r0, #1
	beq _0807D910
	cmp r0, #1
	bgt _0807D8D2
	cmp r0, #0
	beq _0807D8DC
	b _0807D9AC
_0807D8D2:
	cmp r4, #0xa
	beq _0807D978
	cmp r4, #0x14
	beq _0807D998
	b _0807D9AC
_0807D8DC:
	cmp r1, #1
	bhi _0807D8F8
	movs r0, #0x80
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r2, r3, r4
	orrs r1, r0
	strb r1, [r2]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0xfa
	lsls r0, r0, #2
	b _0807D9AA
_0807D8F8:
	movs r0, #0x80
	movs r4, #0xc3
	lsls r4, r4, #1
	adds r2, r3, r4
	orrs r1, r0
	strb r1, [r2]
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0xfa
	lsls r0, r0, #2
	b _0807D9AA
_0807D910:
	cmp r1, #1
	beq _0807D93A
	cmp r1, #1
	bgt _0807D91E
	cmp r1, #0
	beq _0807D928
	b _0807D9AC
_0807D91E:
	cmp r2, #2
	beq _0807D94C
	cmp r2, #3
	beq _0807D962
	b _0807D9AC
_0807D928:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r3, r2
	movs r0, #0x80
	strb r0, [r1]
	movs r4, #0xc3
	lsls r4, r4, #1
	adds r1, r3, r4
	b _0807D95C
_0807D93A:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x80
	strb r0, [r1]
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r3, r2
	b _0807D972
_0807D94C:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #0x81
	strb r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r3, r0
_0807D95C:
	movs r0, #0x82
	strb r0, [r1]
	b _0807D9AC
_0807D962:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r3, r2
	movs r0, #0x81
	strb r0, [r1]
	movs r4, #0xc3
	lsls r4, r4, #1
	adds r1, r3, r4
_0807D972:
	movs r0, #0x83
	strb r0, [r1]
	b _0807D9AC
_0807D978:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	movs r4, #0xad
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #0x14
	strh r0, [r1]
	subs r2, #4
	b _0807D9A8
_0807D998:
	movs r4, #0xad
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0xc1
	lsls r2, r2, #1
_0807D9A8:
	adds r1, r3, r2
_0807D9AA:
	strh r0, [r1]
_0807D9AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
