.syntax unified
.text
	push {lr}
	sub sp, #4
	ldr r2, _08026160 @ =gFlags
	ldr r0, [r2]
	ldr r1, _08026164 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
	ldr r0, _08026168 @ =Task_8026178
	movs r2, #0x80
	lsls r2, r2, #6
	movs r1, #0
	str r1, [sp]
	movs r3, #0
	bl TaskCreate
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08026160: .4byte gFlags
_08026164: .4byte 0xFFFFFBFF
_08026168: .4byte Task_8026178

.syntax divided
