.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r1
	movs r6, #0
	movs r4, #0
_080871DC:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r0, r5, r0
	lsls r3, r4, #1
	adds r3, r3, r4
	lsls r3, r3, #3
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r3
	ldr r1, [r1]
	asrs r1, r1, #8
	movs r7, #0x88
	lsls r7, r7, #1
	adds r2, r5, r7
	adds r2, r2, r3
	ldr r2, [r2]
	asrs r2, r2, #8
	mov r3, r8
	str r3, [sp]
	movs r3, #0
	bl sub_8010184
	cmp r0, #1
	bne _0808721A
	movs r6, #1
	b _08087224
_0808721A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _080871DC
_08087224:
	adds r0, r6, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
