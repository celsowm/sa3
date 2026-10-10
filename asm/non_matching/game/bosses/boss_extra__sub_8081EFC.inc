.syntax unified
.text
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08081F14 @ =gStageData
	adds r4, r1, #0
	adds r4, #0xac
	ldrh r3, [r4]
	cmp r3, #0
	beq _08081F18
	ldrb r0, [r5]
	cmp r0, #0
	bne _08081F6C
	b _08081FB0
	.align 2, 0
_08081F14: .4byte gStageData
_08081F18:
	ldrb r0, [r1, #4]
	cmp r0, #7
	beq _08081F46
	ldr r2, [r5, #0x28]
	ldr r0, [r2, #4]
	movs r4, #0x80
	lsls r4, r4, #1
	ands r0, r4
	cmp r0, #0
	bne _08081F34
	ldr r1, _08081F68 @ =sub_80105F0
	adds r0, r2, #0
	bl SetPlayerCallback
_08081F34:
	ldr r2, [r5, #0x2c]
	ldr r0, [r2, #4]
	ands r0, r4
	cmp r0, #0
	bne _08081F46
	ldr r1, _08081F68 @ =sub_80105F0
	adds r0, r2, #0
	bl SetPlayerCallback
_08081F46:
	adds r3, r5, #0
	adds r3, #0x5f
	ldrb r0, [r3]
	adds r2, r0, #0
	cmp r2, #1
	bne _08081FB0
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	strh r2, [r5, #4]
	strh r1, [r5, #8]
	movs r0, #7
	strb r0, [r5, #1]
	ldrb r0, [r5, #0xc]
	strb r0, [r5, #0xd]
	b _08081FB0
	.align 2, 0
_08081F68: .4byte sub_80105F0
_08081F6C:
	ldrb r0, [r1, #4]
	cmp r0, #7
	bne _08081F76
	strb r0, [r5, #1]
	b _08081FB0
_08081F76:
	ldr r2, [r5, #0x28]
	ldr r0, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08081FB0
	ldrh r0, [r5, #6]
	subs r0, #1
	strh r0, [r5, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08081FB0
	movs r0, #0x3c
	strh r0, [r5, #6]
	subs r0, r3, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08081FB0
	ldr r4, _08081FB8 @ =sub_80105F0
	adds r0, r2, #0
	adds r1, r4, #0
	bl SetPlayerCallback
	ldr r0, [r5, #0x2c]
	adds r1, r4, #0
	bl SetPlayerCallback
_08081FB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081FB8: .4byte sub_80105F0

.syntax divided
