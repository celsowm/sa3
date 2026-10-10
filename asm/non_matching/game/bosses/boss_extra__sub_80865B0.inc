.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov sb, r0
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r1, r1, r3
	mov r8, r1
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r0, [r0]
	mov ip, r0
	mov r7, ip
	adds r7, #0xc
	ldr r0, [r6, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080865EE
	mov r2, r8
	ldr r0, [r2, #0x20]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	bne _080865F2
_080865EE:
	movs r0, #0
	b _0808675C
_080865F2:
	ldr r1, [r7, #0x20]
	cmp r1, r2
	beq _080866A4
	adds r0, r3, #0
	adds r0, #0x9c
	ldr r0, [r0]
	asrs r0, r0, #8
	movs r4, #0xec
	lsls r4, r4, #2
	adds r1, r3, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r1
	adds r2, r0, r1
	ldr r1, [r6, #0x10]
	asrs r1, r1, #8
	ldr r0, _0808669C @ =gCamera
	adds r0, #0x6a
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r1, r1, r0
	mov r0, ip
	adds r0, #0x30
	movs r4, #0
	ldrsb r4, [r0, r4]
	adds r1, r1, r4
	cmp r2, r1
	bgt _08086646
	ldr r5, _080866A0 @ =0x000003B2
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r5, sl
	subs r0, r0, r5
	adds r0, r2, r0
	cmp r0, r1
	bge _0808665A
	cmp r2, r1
	bge _08086646
	b _0808675A
_08086646:
	mov r0, ip
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r4
	adds r0, r1, r0
	cmp r0, r2
	bge _0808665A
	b _0808675A
_0808665A:
	adds r0, r3, #0
	adds r0, #0xa0
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r2, r8
	adds r2, #0x25
	movs r4, #0
	ldrsb r4, [r2, r4]
	adds r3, r0, r4
	ldr r0, [r6, #0x14]
	asrs r0, r0, #8
	adds r2, r7, #0
	adds r2, #0x25
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r1, r0, r2
	cmp r3, r1
	bgt _08086696
	mov r0, r8
	adds r0, #0x27
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r4
	adds r0, r3, r0
	cmp r0, r1
	bge _08086756
	cmp r3, r1
	blt _0808675A
_08086696:
	adds r0, r7, #0
	adds r0, #0x27
	b _08086748
	.align 2, 0
_0808669C: .4byte gCamera
_080866A0: .4byte 0x000003B2
_080866A4:
	ldr r0, [r7, #0x28]
	cmp r0, r1
	beq _0808675A
	adds r0, r3, #0
	adds r0, #0x9c
	ldr r0, [r0]
	asrs r0, r0, #8
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r1
	adds r2, r0, r1
	ldr r1, [r6, #0x10]
	asrs r1, r1, #8
	ldr r0, _0808676C @ =gCamera
	adds r0, #0x6a
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r1, r0
	mov r0, ip
	adds r0, #0x38
	movs r4, #0
	ldrsb r4, [r0, r4]
	adds r1, r1, r4
	cmp r2, r1
	bgt _080866F6
	ldr r5, _08086770 @ =0x000003B2
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r5, sl
	subs r0, r0, r5
	adds r0, r2, r0
	cmp r0, r1
	bge _08086708
	cmp r2, r1
	blt _0808675A
_080866F6:
	mov r0, ip
	adds r0, #0x3a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r4
	adds r0, r1, r0
	cmp r0, r2
	blt _0808675A
_08086708:
	adds r0, r3, #0
	adds r0, #0xa0
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r2, r8
	adds r2, #0x25
	movs r4, #0
	ldrsb r4, [r2, r4]
	adds r3, r0, r4
	ldr r0, [r6, #0x14]
	asrs r0, r0, #8
	adds r2, r7, #0
	adds r2, #0x2d
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r1, r0, r2
	cmp r3, r1
	bgt _08086744
	mov r0, r8
	adds r0, #0x27
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r4
	adds r0, r3, r0
	cmp r0, r1
	bge _08086756
	cmp r3, r1
	blt _0808675A
_08086744:
	adds r0, r7, #0
	adds r0, #0x2f
_08086748:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r2
	adds r0, r1, r0
	cmp r0, r3
	blt _0808675A
_08086756:
	movs r0, #1
	mov sb, r0
_0808675A:
	mov r0, sb
_0808675C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808676C: .4byte gCamera
_08086770: .4byte 0x000003B2

.syntax divided
