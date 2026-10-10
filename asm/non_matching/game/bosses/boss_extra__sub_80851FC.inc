.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	beq _0808522A
	cmp r1, #1
	beq _0808527E
	movs r0, #0
	mov sb, r0
	movs r2, #0x80
	str r2, [sp, #8]
	subs r1, #0xa
	str r1, [sp, #0x10]
	adds r3, r6, #0
	adds r3, #0x9c
	str r3, [sp, #0x14]
	b _080852D4
_0808522A:
	ldrb r0, [r6, #0xc]
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	movs r4, #0
	mov sb, r4
	movs r3, #1
	movs r4, #0xbe
	lsls r4, r4, #1
_0808523A:
	mov r5, sb
	lsls r0, r5, #1
	add r0, sb
	lsls r0, r0, #3
	adds r0, r6, r0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r3, [r0]
	movs r7, #0
	lsls r5, r5, #4
	mov r1, sb
	adds r1, #1
	mov r2, sb
	subs r0, r5, r2
	lsls r2, r0, #3
_0808525A:
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, r6, r0
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #5
	bls _0808525A
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #3
	bls _0808523A
	b _080853C4
_0808527E:
	movs r3, #0
	mov sb, r3
_08085282:
	mov r5, sb
	lsls r4, r5, #1
	add r4, sb
	lsls r4, r4, #3
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r4
	ldr r0, [r0]
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r1, r1, r4
	ldr r1, [r1]
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	movs r2, #0x1e
	str r2, [sp]
	ldr r2, [r6, #0x24]
	str r2, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r3, #0
	bl sub_8086D64
	adds r4, r6, r4
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r4, r4, r3
	movs r0, #0
	strh r0, [r4]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #3
	bls _08085282
	b _080853C4
_080852D4:
	ldr r4, [sp, #0x10]
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	ldr r2, _080853D4 @ =gSineTable
	ldr r5, [sp, #8]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _080852F8
	adds r0, #0x3f
_080852F8:
	asrs r0, r0, #6
	str r0, [sp, #0xc]
	ldr r4, [sp, #8]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _08085312
	adds r0, #0x3f
_08085312:
	asrs r0, r0, #6
	mov sl, r0
	lsls r3, r7, #2
	adds r1, r3, r7
	lsls r1, r1, #2
	mov r0, sb
	lsls r2, r0, #4
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r6, r4
	adds r0, r0, r1
	mov ip, r0
	ldr r4, [r0]
	ldr r5, [sp, #0x14]
	ldr r0, [r5]
	mov r8, r3
	adds r5, r2, #0
	cmp r4, r0
	bne _08085360
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r3, r0, r1
	adds r2, r6, #0
	adds r2, #0xa0
	ldr r1, [r3]
	ldr r0, [r2]
	cmp r1, r0
	bne _08085360
	ldr r1, [sp, #0xc]
	adds r0, r4, r1
	mov r4, ip
	str r0, [r4]
	ldr r0, [r2]
	add r0, sl
	str r0, [r3]
_08085360:
	mov r0, r8
	adds r4, r0, r7
	lsls r4, r4, #2
	mov r1, sb
	subs r0, r5, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r0, r0, r4
	ldr r0, [r0]
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r1, r1, r4
	ldr r1, [r1]
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	adds r2, #0x94
	movs r3, #0x1e
	str r3, [sp]
	ldr r3, [r6, #0x24]
	str r3, [sp, #4]
	movs r3, #0
	bl sub_8086D64
	adds r4, r6, r4
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r4, r4, r5
	movs r0, #0
	strh r0, [r4]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r1, [sp, #8]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	mov r3, sb
	cmp r3, #3
	bls _080852D4
_080853C4:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080853D4: .4byte gSineTable

.syntax divided
