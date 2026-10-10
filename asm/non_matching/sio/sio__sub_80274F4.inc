.syntax unified
.text
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	mov r4, sp
	movs r3, #7
	ands r0, r3
	movs r3, #0x10
	orrs r0, r3
	strb r0, [r4]
	lsrs r1, r1, #8
	ldr r0, [sp]
	ldr r3, _08027534 @ =0xFF0000FF
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r3, sp
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	movs r1, #0xff
	ands r0, r1
	strb r0, [r3, #3]
	lsrs r2, r2, #0x18
	strb r2, [r3, #4]
	mov r0, sp
	bl sub_8026AB8
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027534: .4byte 0xFF0000FF

.syntax divided
