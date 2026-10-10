.syntax unified
.text
	push {lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #0x25
	strb r0, [r1, #1]
	ldr r0, _080278C0 @ =gStageData
	adds r0, #0xae
	ldrh r0, [r0]
	strh r0, [r1, #2]
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080278C0: .4byte gStageData

.syntax divided
