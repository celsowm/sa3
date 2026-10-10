.syntax unified
.text
	push {r4, lr}
	sub sp, #8
	ldr r1, _080275B4 @ =gStageData
	adds r1, #0x94
	ldr r1, [r1]
	ldrh r1, [r1, #6]
	movs r2, #0xc0
	lsls r2, r2, #0x12
	adds r1, r1, r2
	ldr r1, [r1, #8]
	subs r0, r0, r1
	mov r2, sp
	movs r1, #0x20
	strb r1, [r2]
	mov r4, sp
	lsls r3, r0, #8
	ldr r1, [sp]
	movs r2, #0xff
	ands r1, r2
	orrs r1, r3
	str r1, [sp]
	lsrs r0, r0, #0x18
	strb r0, [r4, #4]
	mov r0, sp
	bl sub_8026AB8
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080275B4: .4byte gStageData

.syntax divided
