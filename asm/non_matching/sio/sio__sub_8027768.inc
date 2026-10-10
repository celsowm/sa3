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
	movs r1, #8
	strb r1, [r2, #1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08027790
	cmp r3, #0
	bne _0802779A
	mov r1, sp
	movs r0, #5
	b _0802779E
_08027790:
	cmp r3, #0
	beq _0802779A
	mov r1, sp
	movs r0, #5
	b _0802779E
_0802779A:
	mov r1, sp
	movs r0, #0xa
_0802779E:
	strb r0, [r1, #2]
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0

.syntax divided
