.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08081E5C @ =Task_878_2_8086FA4
	ldr r1, _08081E60 @ =0x00000878
	movs r2, #0x84
	lsls r2, r2, #6
	ldr r3, _08081E64 @ =TaskDestructor_878_2_8086ED8
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r3, [r0, #6]
	movs r4, #0xc0
	lsls r4, r4, #0x12
	adds r4, r3, r4
	str r5, [r4, #0x30]
	movs r1, #0
	movs r2, #0
	movs r0, #1
	strh r0, [r4, #4]
	strh r2, [r4, #8]
	movs r0, #6
	strb r0, [r4, #1]
	strb r1, [r4, #0xa]
	strb r1, [r4, #0xc]
	strb r1, [r4, #0xd]
	strb r1, [r4, #0x17]
	str r2, [r4, #0x18]
	str r2, [r4, #0x6c]
	ldr r0, _08081E68 @ =gPlayers
	str r0, [r4, #0x28]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x2c]
	ldr r1, _08081E6C @ =0x0300038C
	adds r0, r3, r1
	str r2, [r0]
	ldr r0, _08081E70 @ =0x03000454
	adds r3, r3, r0
	str r2, [r3]
	adds r0, r4, #0
	bl sub_8081FBC
	adds r0, r4, #0
	bl sub_8082A4C
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081E5C: .4byte Task_878_2_8086FA4
_08081E60: .4byte 0x00000878
_08081E64: .4byte TaskDestructor_878_2_8086ED8
_08081E68: .4byte gPlayers
_08081E6C: .4byte 0x0300038C
_08081E70: .4byte 0x03000454

.syntax divided
