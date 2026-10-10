.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	ldr r0, _08082B38 @ =0x06012800
	str r0, [sp, #4]
	movs r0, #1
	bl VramMalloc
	str r0, [sp, #8]
	movs r1, #0
	mov sl, r1
	movs r2, #0x80
	str r2, [sp]
_08082A6E:
	ldr r2, _08082B3C @ =gSineTable
	ldr r3, [sp]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r3, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _08082A8C
	adds r0, #0x3f
_08082A8C:
	asrs r5, r0, #6
	ldr r7, [sp]
	lsls r0, r7, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _08082AA4
	adds r0, #0x3f
_08082AA4:
	asrs r4, r0, #6
	mov r3, sl
	lsls r3, r3, #1
	mov r8, r3
	add r3, sl
	lsls r2, r3, #3
	movs r1, #0x86
	lsls r1, r1, #1
	add r1, sb
	adds r1, r1, r2
	mov r6, sb
	adds r6, #0x9c
	ldr r0, [r6]
	adds r0, r0, r5
	str r0, [r1]
	movs r1, #0x88
	lsls r1, r1, #1
	add r1, sb
	adds r1, r1, r2
	mov r5, sb
	adds r5, #0xa0
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r1]
	add r2, sb
	movs r7, #0x90
	lsls r7, r7, #1
	adds r2, r2, r7
	movs r4, #0
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r2]
	mov r1, sl
	lsls r0, r1, #2
	add r0, sl
	lsls r0, r0, #3
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r0, r2
	mov r1, sb
	adds r7, r1, r0
	lsls r3, r3, #2
	ldr r2, _08082B40 @ =0x00000848
	adds r3, r3, r2
	add r3, sb
	ldr r0, [sp, #4]
	str r0, [r7]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r7, #0x14]
	strh r4, [r7, #0xe]
	strh r4, [r7, #0x16]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r0, #0x10
	strb r0, [r7, #0x1c]
	strb r4, [r7, #0x1f]
	subs r0, #0x11
	str r0, [r7, #0x20]
	movs r1, #0x80
	lsls r1, r1, #5
	str r1, [r7, #8]
	mov r2, r8
	str r6, [sp, #0x14]
	str r5, [sp, #0x18]
	mov r0, sl
	cmp r0, #1
	beq _08082B5C
	cmp r0, #1
	bgt _08082B44
	cmp r0, #0
	beq _08082B50
	b _08082B88
	.align 2, 0
_08082B38: .4byte 0x06012800
_08082B3C: .4byte gSineTable
_08082B40: .4byte 0x00000848
_08082B44:
	mov r0, sl
	cmp r0, #2
	beq _08082B68
	cmp r0, #3
	beq _08082B80
	b _08082B88
_08082B50:
	ldr r1, _08082B58 @ =0x000004FE
	strh r1, [r7, #0xc]
	movs r0, #4
	b _08082B86
	.align 2, 0
_08082B58: .4byte 0x000004FE
_08082B5C:
	ldr r0, _08082B64 @ =0x000004FE
	strh r0, [r7, #0xc]
	movs r0, #2
	b _08082B86
	.align 2, 0
_08082B64: .4byte 0x000004FE
_08082B68:
	ldr r0, _08082B7C @ =0x000004FE
	strh r0, [r7, #0xc]
	strb r4, [r7, #0x1a]
	movs r0, #0x20
	orrs r0, r1
	movs r1, #0xd
	orrs r0, r1
	str r0, [r7, #8]
	b _08082B88
	.align 2, 0
_08082B7C: .4byte 0x000004FE
_08082B80:
	ldr r1, _08082CEC @ =0x000004FE
	strh r1, [r7, #0xc]
	movs r0, #6
_08082B86:
	strb r0, [r7, #0x1a]
_08082B88:
	add r2, sl
	lsls r2, r2, #3
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r2
	ldr r1, [r0]
	asrs r1, r1, #8
	ldr r4, _08082CF0 @ =gCamera
	ldr r0, [r4]
	subs r1, r1, r0
	strh r1, [r7, #0x10]
	movs r0, #0x88
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	add r2, sb
	movs r0, #0x90
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _08082CF4 @ =0xFFFFFD80
	adds r0, r1, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	ldr r2, _08082CF8 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r7, #0x10]
	strh r0, [r3, #6]
	ldrh r0, [r7, #0x12]
	strh r0, [r3, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3, #2]
	strh r0, [r3, #4]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	ldr r3, [sp, #4]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r3, r3, r7
	str r3, [sp, #4]
	movs r5, #0
	mov r1, sl
	lsls r0, r1, #4
	adds r1, #1
	str r1, [sp, #0x10]
	mov r2, sl
	subs r6, r0, r2
	lsls r0, r6, #4
	ldr r3, _08082CFC @ =0x00000454
	adds r0, r0, r3
	add r0, sb
	str r0, [sp, #0xc]
	mov r8, r4
_08082C04:
	lsls r4, r5, #2
	adds r3, r4, r5
	lsls r2, r3, #2
	lsls r0, r6, #3
	adds r2, r2, r0
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r2
	ldr r7, [sp, #0x14]
	ldr r1, [r7]
	str r1, [r0]
	movs r0, #0xb8
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r2
	ldr r2, [sp, #0x18]
	ldr r1, [r2]
	str r1, [r0]
	lsls r3, r3, #3
	ldr r0, [sp, #0xc]
	adds r7, r0, r3
	ldr r1, [sp, #8]
	str r1, [r7]
	ldr r0, _08082D00 @ =0x000004FF
	strh r0, [r7, #0xc]
	movs r2, #0
	strb r2, [r7, #0x1a]
	subs r0, #0x3f
	strh r0, [r7, #0x14]
	movs r3, #0
	strh r3, [r7, #0xe]
	strh r3, [r7, #0x16]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r0, #0x10
	strb r0, [r7, #0x1c]
	movs r0, #0
	strb r0, [r7, #0x1f]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r7, #0x20]
	movs r1, #0x80
	lsls r1, r1, #5
	str r1, [r7, #8]
	mov r2, sl
	cmp r2, #0
	bne _08082C68
	cmp r5, #0
	beq _08082C74
_08082C68:
	movs r0, #0x80
	lsls r0, r0, #0xc
	movs r3, #0x80
	lsls r3, r3, #5
	orrs r0, r3
	str r0, [r7, #8]
_08082C74:
	adds r2, r4, r5
	lsls r2, r2, #2
	lsls r0, r6, #3
	adds r2, r2, r0
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r3, r8
	ldr r1, [r3]
	subs r0, r0, r1
	strh r0, [r7, #0x10]
	movs r0, #0xb8
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #5
	bls _08082C04
	ldr r7, [sp, #0x10]
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	mov r3, sl
	cmp r3, #3
	bhi _08082CD0
	b _08082A6E
_08082CD0:
	ldr r7, _08082D04 @ =0x00000814
	add r7, sb
	movs r0, #0
	str r0, [r7]
	mov r7, sb
	strb r0, [r7, #0xf]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082CEC: .4byte 0x000004FE
_08082CF0: .4byte gCamera
_08082CF4: .4byte 0xFFFFFD80
_08082CF8: .4byte 0x000003FF
_08082CFC: .4byte 0x00000454
_08082D00: .4byte 0x000004FF
_08082D04: .4byte 0x00000814

.syntax divided
