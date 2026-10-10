.syntax unified
.text
	push {lr}
	sub sp, #8
	mov r3, sp
	movs r2, #0x30
	strb r2, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #8
	ldr r2, [sp]
	ldr r3, _08027654 @ =0xFF0000FF
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	mov r3, sp
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	movs r2, #0xff
	ands r0, r2
	strb r0, [r3, #3]
	lsrs r1, r1, #0x18
	strb r1, [r3, #4]
	mov r0, sp
	bl sub_8026AB8
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08027654: .4byte 0xFF0000FF

.syntax divided
