.syntax unified
.text
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov r3, sp
	movs r2, #0x38
	strb r2, [r3]
	movs r2, #0xc
	strb r2, [r3, #1]
	mov r2, sp
	strb r0, [r2, #2]
	movs r0, #0xff
	ands r4, r0
	strb r4, [r2, #3]
	lsrs r1, r1, #0x18
	strb r1, [r2, #4]
	mov r0, sp
	bl sub_8026AB8
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
