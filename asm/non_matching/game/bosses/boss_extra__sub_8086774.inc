.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sb, r1
	movs r0, #0
	mov r8, r0
	movs r5, #0
_08086788:
	movs r4, #0
_0808678A:
	lsls r2, r5, #4
	subs r2, r2, r5
	lsls r0, r2, #4
	ldr r1, _080867F8 @ =0x00000454
	adds r0, r0, r1
	adds r0, r6, r0
	lsls r3, r4, #2
	adds r3, r3, r4
	lsls r1, r3, #3
	adds r0, r0, r1
	lsls r3, r3, #2
	lsls r2, r2, #3
	adds r3, r3, r2
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r1, r1, r3
	ldr r1, [r1]
	asrs r1, r1, #8
	movs r7, #0xb8
	lsls r7, r7, #1
	adds r2, r6, r7
	adds r2, r2, r3
	ldr r2, [r2]
	asrs r2, r2, #8
	mov r3, sb
	str r3, [sp]
	movs r3, #0
	bl sub_8010184
	cmp r0, #1
	bne _080867D2
	movs r7, #1
	mov r8, r7
	movs r5, #4
	movs r4, #6
_080867D2:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _0808678A
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _08086788
	mov r0, r8
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080867F8: .4byte 0x00000454

.syntax divided
