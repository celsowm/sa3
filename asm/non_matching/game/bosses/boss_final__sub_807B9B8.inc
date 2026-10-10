.syntax unified
.text
	push {r4, lr}
	sub sp, #4
	ldr r3, _0807B9E8 @ =gCurTask
	ldr r0, [r3]
	ldrh r2, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r2, r0
	ldrh r0, [r4, #0xc]
	cmp r0, #0x14
	bne _0807B9D0
	b _0807BAD0
_0807B9D0:
	cmp r0, #0x14
	bgt _0807B9F6
	cmp r0, #0xa
	beq _0807BA80
	cmp r0, #0xa
	bgt _0807B9EC
	cmp r0, #0
	beq _0807BA26
	cmp r0, #1
	beq _0807BA30
	b _0807BBD4
	.align 2, 0
_0807B9E8: .4byte gCurTask
_0807B9EC:
	cmp r0, #0xb
	beq _0807BAAA
	cmp r0, #0xc
	beq _0807BA94
	b _0807BBD4
_0807B9F6:
	cmp r0, #0x1f
	bne _0807B9FC
	b _0807BB64
_0807B9FC:
	cmp r0, #0x1f
	bgt _0807BA0C
	cmp r0, #0x15
	beq _0807BAE2
	cmp r0, #0x1e
	bne _0807BA0A
	b _0807BB30
_0807BA0A:
	b _0807BBD4
_0807BA0C:
	cmp r0, #0x64
	bne _0807BA12
	b _0807BBB0
_0807BA12:
	cmp r0, #0x64
	bgt _0807BA1E
	cmp r0, #0x20
	bne _0807BA1C
	b _0807BB8E
_0807BA1C:
	b _0807BBD4
_0807BA1E:
	cmp r0, #0xc8
	bne _0807BA24
	b _0807BBC2
_0807BA24:
	b _0807BBD4
_0807BA26:
	movs r0, #0x3c
	strh r0, [r4, #8]
	movs r0, #1
	strh r0, [r4, #0xc]
	b _0807BBD4
_0807BA30:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807BA3E
	b _0807BBD4
_0807BA3E:
	ldr r0, _0807BA78 @ =0x00000237
	bl m4aSongNumStart
	movs r0, #0x78
	strh r0, [r4, #8]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	ldr r2, _0807BA7C @ =gDispCnt
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0xd3
	str r1, [sp]
	movs r1, #4
	movs r2, #0
	bl CreateScreenShake
	movs r0, #0xd2
	bl sub_807FB7C
	b _0807BBD4
	.align 2, 0
_0807BA78: .4byte 0x00000237
_0807BA7C: .4byte gDispCnt
_0807BA80:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807BA8E
	b _0807BBD4
_0807BA8E:
	movs r0, #0xc
	strh r0, [r4, #0xc]
	b _0807BBD4
_0807BA94:
	ldr r1, _0807BACC @ =0x03000120
	adds r0, r2, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	cmp r0, #0xb7
	bgt _0807BAAA
	movs r0, #0xdc
	bl sub_807FB7C
	movs r0, #0xb
	strh r0, [r4, #0xc]
_0807BAAA:
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	subs r1, #0x80
	str r1, [r0]
	movs r0, #0x98
	lsls r0, r0, #8
	cmp r1, r0
	ble _0807BAC0
	b _0807BBD4
_0807BAC0:
	movs r0, #0x3c
	strh r0, [r4, #8]
	movs r0, #0x14
	strh r0, [r4, #0xc]
	b _0807BBD4
	.align 2, 0
_0807BACC: .4byte 0x03000120
_0807BAD0:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807BBD4
	movs r0, #0x15
	strh r0, [r4, #0xc]
	b _0807BBD4
_0807BAE2:
	ldr r0, _0807BB1C @ =0x03000144
	adds r1, r2, r0
	ldr r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0807BB20 @ =0x0300016C
	adds r2, r2, r0
	ldr r0, [r2]
	ldr r3, _0807BB24 @ =0xFFFFFF00
	adds r0, r0, r3
	str r0, [r2]
	ldr r1, [r1]
	ldr r0, _0807BB28 @ =0x000613FF
	cmp r1, r0
	ble _0807BBD4
	movs r0, #0x1e
	strh r0, [r4, #8]
	strh r0, [r4, #0xc]
	ldr r0, _0807BB2C @ =0x00000237
	bl m4aSongNumStop
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl sub_8081A74
	b _0807BBD4
	.align 2, 0
_0807BB1C: .4byte 0x03000144
_0807BB20: .4byte 0x0300016C
_0807BB24: .4byte 0xFFFFFF00
_0807BB28: .4byte 0x000613FF
_0807BB2C: .4byte 0x00000237
_0807BB30:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807BBD4
	movs r0, #0x24
	strh r0, [r4, #8]
	movs r0, #0x1f
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl sub_8081A74
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	bl UpdateHandAnimation
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	bl UpdateHandAnimation
	b _0807BBD4
_0807BB64:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807BBD4
	movs r0, #0x24
	strh r0, [r4, #8]
	movs r0, #0x20
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #5
	bl UpdateHandAnimation
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	bl UpdateHandAnimation
	b _0807BBD4
_0807BB8E:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807BBD4
	movs r0, #0xfa
	bl sub_807FB7C
	movs r0, #0x14
	bl sub_807FB7C
	movs r0, #0x1e
	strh r0, [r4, #8]
	movs r0, #0x64
	strh r0, [r4, #0xc]
	b _0807BBD4
_0807BBB0:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807BBD4
	movs r0, #0xc8
	strh r0, [r4, #0xc]
	b _0807BBD4
_0807BBC2:
	movs r2, #0
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #8]
	strh r1, [r4, #0xc]
	strb r2, [r4, #1]
	ldr r1, [r3]
	ldr r0, _0807BC00 @ =sub_807BC04
	str r0, [r1, #8]
_0807BBD4:
	adds r0, r4, #0
	bl sub_807BD88
	adds r0, r4, #0
	bl sub_807BFEC
	adds r0, r4, #0
	bl sub_807DB60
	adds r0, r4, #0
	bl sub_807D81C
	adds r0, r4, #0
	bl sub_807C14C
	adds r0, r4, #0
	bl sub_80816C0
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BC00: .4byte sub_807BC04

.syntax divided
