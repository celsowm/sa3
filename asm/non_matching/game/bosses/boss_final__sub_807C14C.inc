.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	mov r8, r0
_0807C15C:
	ldrb r0, [r6]
	mov r1, r8
	lsls r1, r1, #2
	mov ip, r1
	adds r1, r6, #0
	adds r1, #0x38
	cmp r0, #0
	bne _0807C18E
	mov r0, ip
	add r0, r8
	lsls r0, r0, #2
	adds r3, r6, r0
	ldrh r2, [r3, #0x3e]
	cmp r2, #0x64
	beq _0807C17E
	cmp r2, #0x6e
	bne _0807C18E
_0807C17E:
	adds r2, r6, #0
	adds r2, #0x38
	adds r1, r2, r0
	ldr r0, _0807C1C0 @ =0xFFFFFC00
	str r0, [r1]
	movs r0, #0xc8
	strh r0, [r3, #0x3e]
	adds r1, r2, #0
_0807C18E:
	mov r0, ip
	add r0, r8
	lsls r0, r0, #2
	adds r2, r6, #0
	adds r2, #0x30
	adds r4, r2, r0
	ldr r7, [r4]
	adds r5, r1, r0
	ldr r1, [r5]
	adds r1, r7, r1
	str r1, [r4]
	subs r7, r7, r1
	adds r3, r6, r0
	ldrh r0, [r3, #0x3e]
	mov sb, r2
	cmp r0, #0x64
	beq _0807C1C4
	cmp r0, #0x64
	ble _0807C208
	cmp r0, #0x6e
	beq _0807C1DC
	cmp r0, #0xc8
	beq _0807C1F8
	b _0807C208
	.align 2, 0
_0807C1C0: .4byte 0xFFFFFC00
_0807C1C4:
	ldr r0, _0807C1D8 @ =0x0000F3FF
	cmp r1, r0
	ble _0807C208
	adds r0, #1
	str r0, [r4]
	movs r0, #0x78
	strh r0, [r3, #0x3c]
	movs r0, #0x6e
	b _0807C206
	.align 2, 0
_0807C1D8: .4byte 0x0000F3FF
_0807C1DC:
	ldrh r0, [r3, #0x3c]
	subs r0, #1
	strh r0, [r3, #0x3c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807C208
	ldr r0, [r5]
	rsbs r0, r0, #0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r5]
	movs r0, #0xc8
	b _0807C206
_0807C1F8:
	movs r0, #0xcc
	lsls r0, r0, #8
	cmp r1, r0
	bgt _0807C208
	str r0, [r4]
	movs r0, #0
	str r0, [r5]
_0807C206:
	strh r0, [r3, #0x3e]
_0807C208:
	mov r2, ip
	add r2, r8
	lsls r0, r2, #3
	adds r0, #0x7c
	adds r0, r6, r0
	lsls r2, r2, #2
	adds r1, r6, #0
	adds r1, #0x2c
	adds r1, r1, r2
	ldr r1, [r1]
	add r2, sb
	ldr r2, [r2]
	str r7, [sp]
	movs r3, #0
	bl sub_807C374
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #3
	bls _0807C15C
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
