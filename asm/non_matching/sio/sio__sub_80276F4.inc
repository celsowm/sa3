.syntax unified
.text
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x10      @ r0 = param0 << 16
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10      @ r4 = playerIndex
	ldr r2, _08027734 @ =gStageData
	adds r2, #0x8f
	movs r3, #1
	strb r3, [r2]
	mov r3, sp
	movs r2, #0x28
	strb r2, [r3]
	lsrs r0, r0, #8
	ldr r2, [sp]
	ldr r3, _08027738 @ =0xFF0000FF
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	mov r2, sp
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
_08027734: .4byte gStageData
_08027738: .4byte 0xFF0000FF

.syntax divided
