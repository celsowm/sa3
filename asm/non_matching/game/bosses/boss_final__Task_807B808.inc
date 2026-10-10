.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _0807B854 @ =gCurTask
	mov sb, r0
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r5, [r4, #0x20]
	ldr r6, [r4, #0x24]
	adds r0, r4, #0
	bl sub_807C14C
	adds r0, r4, #0
	bl sub_80816C0
	mov r1, sp
	mov r0, sp
	movs r2, #0
	mov r8, r2
	movs r7, #0
	strh r7, [r0, #2]
	strh r7, [r1]
	ldrh r1, [r4, #0xc]
	cmp r1, #0x64
	beq _0807B8B0
	cmp r1, #0x64
	bgt _0807B858
	cmp r1, #0
	beq _0807B874
	cmp r1, #0xa
	beq _0807B896
	b _0807B9A8
	.align 2, 0
_0807B854: .4byte gCurTask
_0807B858:
	cmp r1, #0xc8
	bne _0807B85E
	b _0807B95E
_0807B85E:
	cmp r1, #0xc8
	bgt _0807B868
	cmp r1, #0x6e
	beq _0807B94C
	b _0807B9A8
_0807B868:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _0807B872
	b _0807B99C
_0807B872:
	b _0807B9A8
_0807B874:
	movs r0, #0xc
	bl sub_807FB7C
	movs r0, #0
	bl sub_807FB7C
	movs r0, #0xa
	bl sub_807FB7C
	movs r0, #0xb
	bl sub_807FB7C
	movs r0, #5
	strh r0, [r4, #8]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	b _0807B9A8
_0807B896:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807B8A4
	b _0807B9A8
_0807B8A4:
	movs r0, #0x36
	bl sub_80299D4
	movs r0, #0x64
	strh r0, [r4, #0xc]
	b _0807B9A8
_0807B8B0:
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	ldr r1, _0807B8C4 @ =0x0000068C
	cmp r0, r1
	ble _0807B8CC
	ldr r0, _0807B8C8 @ =0x00068D00
	str r0, [r5, #0x10]
	strh r7, [r5, #0x1c]
	strh r7, [r5, #0x18]
	b _0807B8D2
	.align 2, 0
_0807B8C4: .4byte 0x0000068C
_0807B8C8: .4byte 0x00068D00
_0807B8CC:
	mov r1, sp
	movs r0, #0x10
	strh r0, [r1]
_0807B8D2:
	ldr r0, [r6, #0x10]
	asrs r0, r0, #8
	ldr r1, _0807B8E8 @ =0x00000664
	cmp r0, r1
	ble _0807B8F0
	ldr r0, _0807B8EC @ =0x00066500
	str r0, [r6, #0x10]
	movs r0, #0
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x18]
	b _0807B8FC
	.align 2, 0
_0807B8E8: .4byte 0x00000664
_0807B8EC: .4byte 0x00066500
_0807B8F0:
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #2]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r2, #2]
_0807B8FC:
	ldrh r1, [r5, #0x1e]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, #0x1e]
	eors r1, r0
	ands r1, r0
	strh r1, [r5, #0x20]
	ldrh r1, [r6, #0x1e]
	mov r0, sp
	ldrh r0, [r0, #2]
	strh r0, [r6, #0x1e]
	eors r1, r0
	ands r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	ldr r1, _0807B948 @ =0x0000068C
	cmp r0, r1
	ble _0807B9A8
	ldr r0, [r5, #0x14]
	asrs r0, r0, #8
	cmp r0, #0xb2
	ble _0807B9A8
	ldr r0, [r6, #0x10]
	asrs r0, r0, #8
	subs r1, #0x28
	cmp r0, r1
	ble _0807B9A8
	ldr r0, [r6, #0x14]
	asrs r0, r0, #8
	cmp r0, #0xb2
	ble _0807B9A8
	movs r0, #0x1e
	strh r0, [r4, #8]
	movs r0, #0x6e
	strh r0, [r4, #0xc]
	b _0807B9A8
	.align 2, 0
_0807B948: .4byte 0x0000068C
_0807B94C:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807B9A8
	movs r0, #0xc8
	strh r0, [r4, #0xc]
	b _0807B9A8
_0807B95E:
	ldr r1, _0807B994 @ =gCamera
	movs r0, #0x10
	str r0, [r1, #0x10]
	adds r0, r4, #0
	bl sub_807BCCC
	adds r0, r4, #0
	bl sub_807BEF0
	adds r0, r4, #0
	bl sub_807D6C4
	adds r0, r4, #0
	bl sub_807CBC8
	mov r0, r8
	strb r0, [r4, #0x10]
	strb r0, [r4, #0x12]
	movs r0, #1
	strh r0, [r4, #8]
	strh r7, [r4, #0xc]
	mov r2, sb
	ldr r1, [r2]
	ldr r0, _0807B998 @ =sub_807B9B8
	str r0, [r1, #8]
	b _0807B9A8
	.align 2, 0
_0807B994: .4byte gCamera
_0807B998: .4byte sub_807B9B8
_0807B99C:
	strh r7, [r5, #0x1c]
	strh r7, [r5, #0x18]
	strh r7, [r6, #0x1c]
	strh r7, [r6, #0x18]
	bl sub_807A4A8
_0807B9A8:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
