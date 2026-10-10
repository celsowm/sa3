.syntax unified
.text
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r1, sp
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	mov r0, sp
	strb r2, [r0, #2]
	cmp r3, #1
	bne _080275DE
	strb r4, [r0, #4]
_080275DE:
	mov r0, sp
	strb r3, [r0, #3]
	bl sub_8026AB8
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
