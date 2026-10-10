.syntax unified
.text
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r4, sp
	movs r3, #0x38
	strb r3, [r4]
	movs r3, #0x20
	strb r3, [r4, #1]
	mov r3, sp
	strb r2, [r3, #2]
	mov r2, sp
	strb r1, [r2, #4]
	mov r1, sp
	strb r0, [r1, #3]
	mov r0, sp
	bl sub_8026AB8
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

.syntax divided
