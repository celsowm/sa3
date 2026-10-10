.syntax unified
.text
	push {lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sp
	movs r2, #0x38
	strb r2, [r3]
	movs r2, #7
	strb r2, [r3, #1]
	movs r2, #1
	lsls r2, r0
	strb r2, [r3, #2]
	mov r0, sp
	strb r1, [r0, #3]
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
