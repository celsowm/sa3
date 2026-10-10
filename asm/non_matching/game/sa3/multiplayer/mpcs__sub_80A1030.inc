.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x8c
	movs r0, #2
	mov sb, r0
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	movs r1, #0x78
	cmp r0, #0xd
	bls _080A104E
	movs r1, #0xb4
_080A104E:
	movs r6, #0
	movs r0, #0x28
	rsbs r0, r0, #0
	adds r0, r0, r1
	mov r8, r0
	adds r7, r1, #0
	adds r7, #0x28
_080A105C:
	cmp r6, #0
	beq _080A106A
	ldr r0, [r5, #0x44]
	asrs r0, r0, #8
	mov r1, r8
	subs r0, r1, r0
	b _080A1070
_080A106A:
	ldr r0, [r5, #0x44]
	asrs r0, r0, #8
	adds r0, r7, r0
_080A1070:
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x48]
	asrs r0, r0, #8
	strh r0, [r4, #0x12]
	cmp r6, #0
	beq _080A1086
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080A108C
_080A1086:
	ldr r0, [r4, #8]
	ldr r1, _080A10AC @ =0xFFFFFBFF
	ands r0, r1
_080A108C:
	str r0, [r4, #8]
	adds r0, r4, #0
	bl DisplaySprite
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, sb
	blo _080A105C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A10AC: .4byte 0xFFFFFBFF

.syntax divided
