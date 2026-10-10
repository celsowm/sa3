.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp, #4]
_0807CFBE:
	ldr r1, [sp, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	adds r0, r7, r0
	str r0, [sp, #0x10]
	lsls r1, r1, #3
	ldr r3, [sp, #4]
	subs r0, r1, r3
	lsls r4, r0, #2
	adds r5, r7, r4
	mov r8, r5
	movs r3, #0xd6
	lsls r3, r3, #1
	add r3, r8
	ldrh r5, [r3]
	str r1, [sp, #0x14]
	cmp r5, #1
	beq _0807D002
	ldr r6, [sp, #4]
	adds r6, #1
	cmp r5, #1
	bgt _0807CFF4
	b _0807D286
_0807CFF4:
	cmp r5, #0x64
	bne _0807CFFA
	b _0807D1F6
_0807CFFA:
	cmp r5, #0x6e
	bne _0807D000
	b _0807D270
_0807D000:
	b _0807D286
_0807D002:
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r0, r0, r4
	mov sl, r0
	ldr r3, [r0]
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r6, r0, r4
	ldr r0, [r6]
	mov sb, r0
	adds r1, #8
	adds r0, r7, r1
	adds r0, r0, r4
	ldr r0, [r0]
	adds r0, r3, r0
	mov r2, sl
	str r0, [r2]
	adds r1, #4
	adds r0, r7, r1
	adds r0, r0, r4
	ldr r1, [r6]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r6]
	adds r0, r7, #0
	ldr r1, [sp, #4]
	str r3, [sp, #0x18]
	bl sub_807D41C
	mov r2, sl
	ldr r0, [r2]
	ldr r3, [sp, #0x18]
	subs r3, r3, r0
	ldr r1, [r6]
	mov r0, sb
	subs r0, r0, r1
	mov sb, r0
	ldr r0, [sp, #0x10]
	adds r0, #0x27
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r1, r1, r0
	str r1, [sp, #0xc]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r1, r7, r1
	adds r0, r7, #0
	str r3, [sp, #0x18]
	bl sub_807D37C
	movs r0, #0xd7
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r3, [sp, #0x18]
	cmp r0, #0
	bne _0807D13C
	mov r2, sl
	ldr r1, [r2]
	ldr r2, [r6]
	mov r0, sb
	str r0, [sp]
	ldr r0, [sp, #0x10]
	bl sub_807C244
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	ldr r4, [r7, #0x20]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807D0EE
	ldr r1, [sp, #8]
	ands r5, r1
	cmp r5, #0
	beq _0807D0CC
	ldr r0, [r6]
	asrs r0, r0, #8
	cmp r0, #0x20
	bgt _0807D0EE
	adds r0, r4, #0
	adds r0, #0x4a
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0807D0EE
	ldrb r0, [r7]
	cmp r0, #0
	beq _0807D0EE
	adds r0, r4, #0
	bl Call__Player_8014550
	b _0807D0EE
_0807D0CC:
	ldr r0, [r4, #0x14]
	ldr r3, [sp, #0xc]
	cmp r0, r3
	ble _0807D0EE
	ldrb r0, [r7]
	cmp r0, #0
	beq _0807D0EE
	mov r5, sl
	ldr r1, [r5]
	asrs r1, r1, #8
	ldr r2, [r6]
	asrs r2, r2, #8
	str r4, [sp]
	ldr r0, [sp, #0x10]
	movs r3, #0
	bl sub_8020CE0
_0807D0EE:
	ldr r4, [r7, #0x24]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807D13C
	movs r0, #2
	ldr r1, [sp, #8]
	ands r0, r1
	cmp r0, #0
	bne _0807D13C
	ldr r0, [r4, #0x14]
	ldr r2, [sp, #0xc]
	cmp r0, r2
	ble _0807D13C
	ldrb r0, [r7]
	cmp r0, #0
	beq _0807D13C
	ldr r3, [sp, #0x14]
	ldr r5, [sp, #4]
	subs r2, r3, r5
	lsls r2, r2, #2
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r0, r0, r2
	ldr r1, [r0]
	asrs r1, r1, #8
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r7, r3
	adds r0, r0, r2
	ldr r2, [r0]
	asrs r2, r2, #8
	str r4, [sp]
	ldr r0, [sp, #0x10]
	movs r3, #0
	bl sub_8020CE0
_0807D13C:
	ldr r5, [sp, #0x14]
	ldr r1, [sp, #4]
	subs r0, r5, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _0807D1B2
	adds r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	beq _0807D1B2
	cmp r0, #0xf0
	bne _0807D1B2
	movs r0, #1
	ldr r5, [sp, #8]
	ands r0, r5
	cmp r0, #0
	beq _0807D182
	ldr r4, [r7, #0x20]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807D182
	adds r0, r4, #0
	bl Call__Player_8014550
_0807D182:
	movs r0, #2
	ldr r1, [sp, #8]
	ands r0, r1
	cmp r0, #0
	beq _0807D19E
	ldr r4, [r7, #0x24]
	adds r0, r4, #0
	bl sub_802C080
	cmp r0, #0
	bne _0807D19E
	adds r0, r4, #0
	bl Call__Player_8014550
_0807D19E:
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #4]
	subs r0, r2, r3
	lsls r0, r0, #2
	adds r0, r7, r0
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r1, #0x64
	strh r1, [r0]
_0807D1B2:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _0807D1DA
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #4]
	subs r0, r1, r2
	lsls r0, r0, #2
	adds r0, r7, r0
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	adds r6, r2, #0
	adds r6, #1
	cmp r0, #0
	bne _0807D286
	movs r0, #1
	strh r0, [r1]
	b _0807D286
_0807D1DA:
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #4]
	subs r0, r1, r2
	lsls r0, r0, #2
	adds r0, r7, r0
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r0, r3
	mov r5, sp
	ldrh r5, [r5, #8]
	strh r5, [r0]
	adds r6, r2, #0
	adds r6, #1
	b _0807D286
_0807D1F6:
	movs r1, #0xd4
	lsls r1, r1, #1
	add r1, r8
	movs r4, #0
	movs r2, #0
	movs r0, #0x1e
	strh r0, [r1]
	movs r0, #0x6e
	strh r0, [r3]
	movs r0, #0xd7
	lsls r0, r0, #1
	add r0, r8
	strh r2, [r0]
	ldr r0, _0807D268 @ =0x00000239
	bl m4aSongNumStart
	ldr r0, _0807D26C @ =0x000004F6
	ldr r1, [sp, #0x10]
	strh r0, [r1, #0xc]
	strb r4, [r1, #0x1a]
	movs r2, #0
	str r2, [sp, #8]
	adds r2, r7, #0
	adds r2, #0x20
	movs r3, #0x20
	mov r8, r3
	movs r5, #0x21
	rsbs r5, r5, #0
	mov sb, r5
	movs r3, #0
_0807D232:
	ldr r1, [sp, #8]
	lsls r0, r1, #2
	adds r0, r2, r0
	ldr r4, [r0]
	ldr r1, [r4, #4]
	adds r0, r1, #0
	mov r5, r8
	ands r0, r5
	cmp r0, #0
	beq _0807D256
	ldr r0, [r4, #0x6c]
	ldr r5, [sp, #0x10]
	cmp r0, r5
	bne _0807D256
	mov r0, sb
	ands r1, r0
	str r1, [r4, #4]
	str r3, [r4, #0x6c]
_0807D256:
	ldr r0, [sp, #8]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #1
	bls _0807D232
	b _0807D286
	.align 2, 0
_0807D268: .4byte 0x00000239
_0807D26C: .4byte 0x000004F6
_0807D270:
	movs r1, #0xd4
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0807D286
	strh r0, [r3]
_0807D286:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	cmp r0, #2
	bhi _0807D292
	b _0807CFBE
_0807D292:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
