.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r5, _08027E30 @ =gCurTask
	ldr r0, [r5]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r6, r4, r0
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	bl Sio32MultiLoadMain
	cmp r0, #0
	beq _08027E18
	ldr r1, [r5]
	ldr r0, _08027E34 @ =sub_8028478
	str r0, [r1, #8]
_08027E18:
	ldr r0, _08027E38 @ =0x030000EC
	adds r5, r4, r0
	ldr r1, [sp]
	ldr r3, [r5]
	cmp r1, r3
	bls _08027E3C
	subs r0, #4
	adds r2, r4, r0
	subs r1, r1, r3
	ldr r0, [r2]
	b _08027E52
	.align 2, 0
_08027E30: .4byte gCurTask
_08027E34: .4byte sub_8028478
_08027E38: .4byte 0x030000EC
_08027E3C:
	cmp r1, r3
	bhs _08027E5A
	ldr r1, _08027E6C @ =0x030000E8
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	subs r0, r0, r3
	str r0, [r2]
	ldr r1, [sp]
_08027E52:
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [sp]
	str r0, [r5]
_08027E5A:
	adds r0, r6, #0
	bl sa2__sub_8081E90
	bl sub_8028338
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08027E6C: .4byte 0x030000E8

.syntax divided
