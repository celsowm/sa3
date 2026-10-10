.syntax unified
.text
	push {lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r2, sp
	movs r1, #0x38
	strb r1, [r2]
	movs r1, #0x24
	strb r1, [r2, #1]
	mov r1, sp
	strb r0, [r1, #2]
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
