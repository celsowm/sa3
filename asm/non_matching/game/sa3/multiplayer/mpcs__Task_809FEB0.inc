.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, _0809FED8 @ =gCurTask
	ldr r2, [r7]
	ldrh r0, [r2, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r4, r0, r1
	ldr r0, _0809FEDC @ =gStageData
	ldrb r5, [r0, #6]
	movs r6, #0
	ldr r1, [r4, #0x18]
	ldrb r0, [r1]
	cmp r0, #0x22
	bne _0809FEE4
	ldr r0, _0809FEE0 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A006C
	.align 2, 0
_0809FED8: .4byte gCurTask
_0809FEDC: .4byte gStageData
_0809FEE0: .4byte Task_80A14AC
_0809FEE4:
	cmp r0, #0x23
	bne _0809FF1C
	movs r0, #0x1d
	strb r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	strb r0, [r4, #3]
	ldrb r0, [r4, #1]
	strb r0, [r4, #2]
	movs r0, #0x9b
	lsls r0, r0, #9
	str r0, [r4, #0x4c]
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl sub_80A19C0
	adds r0, r4, #0
	bl sub_80A10B0
	adds r0, r4, #0
	bl sub_80A1110
	ldr r1, [r7]
	ldr r0, _0809FF18 @ =Task_80A13F4
	b _080A006A
	.align 2, 0
_0809FF18: .4byte Task_80A13F4
_0809FF1C:
	adds r0, r4, #0
	bl sub_80A19C0
	adds r0, r4, #0
	bl sub_80A10B0
	adds r0, r4, #0
	bl sub_80A1110
	lsls r0, r5, #0x10
	lsrs r1, r0, #0x10
	adds r7, r0, #0
	cmp r1, #1
	bhi _0809FF7C
	ldrb r0, [r4, #1]
	ldr r1, [r4, #0x30]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	bne _0809FF7C
	movs r5, #0
	ldr r0, _0809FF98 @ =gUnknown_030010AC
	mov sb, r0
	ldr r0, _0809FF9C @ =gUnknown_080D8F18
	mov r8, r0
_0809FF50:
	asrs r0, r7, #0x10
	cmp r0, r5
	beq _0809FF72
	mov r0, sb
	adds r1, r5, r0
	ldr r0, [r4, #0x30]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add r0, r8
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _0809FF72
	adds r0, r4, #0
	bl sub_80A1A28
_0809FF72:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _0809FF50
_0809FF7C:
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0xb
	bls _0809FFA8
	ldr r1, [r4, #0x14]
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	strb r0, [r4, #3]
	ldr r0, _0809FFA0 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _0809FFA4 @ =sub_80A021C
	b _080A006A
	.align 2, 0
_0809FF98: .4byte gUnknown_030010AC
_0809FF9C: .4byte gUnknown_080D8F18
_0809FFA0: .4byte gCurTask
_0809FFA4: .4byte sub_80A021C
_0809FFA8:
	ldrb r0, [r4, #1]
	ldr r1, [r4, #0x30]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	beq _0809FFF6
	ldr r0, [r4, #0x14]
	movs r1, #0
	strb r1, [r0]
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _0809FFCE
	ldr r0, [r4, #0x30]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0809FFEC
_0809FFCE:
	ldrb r0, [r4, #1]
	ldr r2, [r4, #0x30]
	cmp r0, #4
	bne _0809FFE2
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _0809FFE2
	movs r6, #2
	b _0809FFFA
_0809FFE2:
	ldrb r1, [r4, #1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	ble _0809FFF0
_0809FFEC:
	movs r6, #1
	b _0809FFFA
_0809FFF0:
	cmp r1, r0
	bge _0809FFF6
	movs r6, #2
_0809FFF6:
	cmp r6, #0
	beq _080A0002
_0809FFFA:
	adds r0, r4, #0
	bl sub_80A18B8
	b _080A000E
_080A0002:
	adds r0, r4, #0
	bl sub_80A18E0
	adds r0, r4, #0
	bl sub_80A1030
_080A000E:
	cmp r6, #1
	beq _080A0018
	cmp r6, #2
	beq _080A0048
	b _080A006C
_080A0018:
	adds r0, r4, #0
	bl sub_80A14E4
	cmp r0, #1
	bne _080A006C
	ldr r0, _080A003C @ =0xFFFFC400
	str r0, [r4, #0x4c]
	ldr r0, [r4, #0x30]
	ldrb r0, [r0]
	strb r0, [r4, #1]
	adds r0, r4, #0
	bl sub_80A0DC8
	ldr r0, _080A0040 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A0044 @ =sub_80A0080
	b _080A006A
	.align 2, 0
_080A003C: .4byte 0xFFFFC400
_080A0040: .4byte gCurTask
_080A0044: .4byte sub_80A0080
_080A0048:
	adds r0, r4, #0
	bl sub_80A1540
	cmp r0, #1
	bne _080A006C
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r4, #0x4c]
	ldr r0, [r4, #0x30]
	ldrb r0, [r0]
	strb r0, [r4, #1]
	adds r0, r4, #0
	bl sub_80A0DC8
	ldr r0, _080A0078 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A007C @ =sub_80A010C
_080A006A:
	str r0, [r1, #8]
_080A006C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0078: .4byte gCurTask
_080A007C: .4byte sub_80A010C

.syntax divided
