.syntax unified
.text
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #8]
	cmp r0, #0x64
	beq _08084B66
	cmp r0, #0x64
	bgt _08084B44
	cmp r0, #0
	beq _08084B4A
	cmp r0, #0xa
	beq _08084B52
	b _08084BDA
_08084B44:
	cmp r0, #0xc8
	beq _08084BB4
	b _08084BDA
_08084B4A:
	movs r0, #0xf0
	strh r0, [r3, #4]
	movs r0, #0xa
	b _08084BD8
_08084B52:
	ldrh r0, [r3, #4]
	subs r0, #1
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084BDA
	movs r0, #0x78
	strh r0, [r3, #4]
	movs r0, #0x64
	b _08084BD8
_08084B66:
	ldrh r1, [r3, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08084B7E
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_08084B7E:
	ldrh r0, [r3, #4]
	subs r0, #1
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084BDA
	movs r0, #0xb4
	strh r0, [r3, #4]
	movs r0, #8
	adds r1, r3, #0
	adds r1, #0xed
	strb r0, [r1]
	subs r1, #0x49
	ldr r0, _08084BAC @ =0xFFFFFE00
	str r0, [r1]
	adds r1, #4
	ldr r0, _08084BB0 @ =0xFFFFFF00
	str r0, [r1]
	movs r0, #0x96
	adds r1, #0x47
	strb r0, [r1]
	movs r0, #0xc8
	b _08084BD8
	.align 2, 0
_08084BAC: .4byte 0xFFFFFE00
_08084BB0: .4byte 0xFFFFFF00
_08084BB4:
	ldrh r0, [r3, #4]
	subs r0, #1
	movs r1, #0
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084BDA
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xed
	strb r1, [r0]
	ldr r0, _08084BE8 @ =0x00000BB8
	strh r0, [r3, #0x12]
	movs r0, #0x96
	lsls r0, r0, #1
_08084BD8:
	strh r0, [r3, #8]
_08084BDA:
	ldrb r1, [r3, #0xd]
	adds r0, r3, #0
	bl sub_8082E2C
	pop {r0}
	bx r0
	.align 2, 0
_08084BE8: .4byte 0x00000BB8

.syntax divided
