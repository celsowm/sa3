.syntax unified
.text
	push {lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov r2, sp
	movs r1, #0x38
	strb r1, [r2]
	mov r1, sp
	movs r2, #0xa
	strb r2, [r1, #1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08027816
	cmp r3, #0
	bne _08027822
	b _0802781A
_08027816:
	cmp r3, #0
	beq _08027822
_0802781A:
	mov r1, sp
	movs r0, #5
	strb r0, [r1, #2]
	b _08027826
_08027822:
	mov r0, sp
	strb r2, [r0, #2]
_08027826:
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
