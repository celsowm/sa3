.syntax unified
.text
	push {lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #0x23
	strb r0, [r1, #1]
	ldr r0, _08027858 @ =gStageData
	adds r0, #0xb4
	ldrb r0, [r0]
	strb r0, [r1, #3]
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08027858: .4byte gStageData

.syntax divided
