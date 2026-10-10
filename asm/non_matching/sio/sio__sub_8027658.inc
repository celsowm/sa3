.syntax unified
.text
	push {lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
