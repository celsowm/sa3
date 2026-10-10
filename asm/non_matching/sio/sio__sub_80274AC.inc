.syntax unified
.text
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov r3, sp
	movs r2, #8
	strb r2, [r3]
	lsrs r0, r0, #8
	ldr r2, [sp]
	ldr r3, _080274EC @ =0xFF0000FF
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	mov r2, sp
	movs r0, #0xff
	ands r4, r0
	strb r4, [r2, #3]
	lsrs r1, r1, #0x18
	strb r1, [r2, #4]
	ldr r0, _080274F0 @ =gStageData
	adds r0, #0xbb
	movs r1, #7
	strb r1, [r0]
	mov r0, sp
	bl sub_8026AB8
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080274EC: .4byte 0xFF0000FF
_080274F0: .4byte gStageData

.syntax divided
