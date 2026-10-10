.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r1, #4
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bne _08086A58
	b _08086B84
_08086A58:
	ldr r0, _08086A94 @ =Task_50_8086B94
	movs r2, #0x84
	lsls r2, r2, #6
	ldr r1, _08086A98 @ =TaskDestructor_50_80870AC
	str r1, [sp]
	movs r1, #0x50
	movs r3, #0
	bl TaskCreate
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r6, r1, r0
	str r7, [r6, #0x4c]
	strb r4, [r6, #0x16]
	ldr r2, _08086A9C @ =gPseudoRandom
	ldr r1, [r2]
	ldr r0, _08086AA0 @ =0x00196225
	muls r0, r1, r0
	ldr r1, _08086AA4 @ =0x3C6EF35F
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08086AA8
	movs r0, #0x80
	lsls r0, r0, #2
	b _08086AAC
	.align 2, 0
_08086A94: .4byte Task_50_8086B94
_08086A98: .4byte TaskDestructor_50_80870AC
_08086A9C: .4byte gPseudoRandom
_08086AA0: .4byte 0x00196225
_08086AA4: .4byte 0x3C6EF35F
_08086AA8:
	movs r0, #0x80
	lsls r0, r0, #1
_08086AAC:
	str r0, [r6, #0xc]
	ldrb r0, [r6, #0x16]
	cmp r0, #2
	bne _08086AC8
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [r6, #8]
	movs r0, #0
	strh r0, [r6, #0x14]
	movs r0, #1
	strb r0, [r7, #3]
	b _08086AE0
_08086AC8:
	ldr r0, [r6, #0xc]
	rsbs r0, r0, #0
	str r0, [r6, #0xc]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [r6, #8]
	movs r0, #0
	strh r0, [r6, #0x14]
	movs r0, #1
	strb r0, [r7, #2]
_08086AE0:
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #3
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r6]
	adds r2, #4
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r6, #4]
	movs r0, #0
	mov r8, r0
	movs r4, #0
	movs r0, #1
	strh r0, [r6, #0x10]
	strh r4, [r6, #0x12]
	movs r0, #0x96
	lsls r0, r0, #2     @ SE_MINECART_DESTROYED
	bl m4aSongNumStart
	adds r3, r6, #0
	adds r3, #0x18
	adds r5, r6, #0
	adds r5, #0x40
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r3, #0xc]
	mov r1, r8
	strb r1, [r3, #0x1a]
	movs r0, #0xb0
	lsls r0, r0, #2
	strh r0, [r3, #0x14]
	strh r4, [r3, #0xe]
	strh r4, [r3, #0x16]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	movs r0, #0x10
	strb r0, [r3, #0x1c]
	strb r1, [r3, #0x1f]
	subs r0, #0x11
	str r0, [r3, #0x20]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r3, #8]
	ldrb r0, [r6, #0x16]
	cmp r0, #2
	bne _08086B56
	ldr r0, [r7, #0x1c]
	str r0, [r6, #0x18]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r3, #8]
	b _08086B5A
_08086B56:
	ldr r0, [r7, #0x20]
	str r0, [r6, #0x18]
_08086B5A:
	ldr r0, [r6]
	asrs r0, r0, #8
	ldr r2, _08086B90 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	strh r0, [r3, #0x10]
	ldr r0, [r6, #4]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #0x12]
	ldrh r0, [r6, #0x14]
	strh r0, [r5]
	ldrh r0, [r3, #0x10]
	strh r0, [r5, #6]
	ldrh r0, [r3, #0x12]
	strh r0, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #2]
	strh r0, [r5, #4]
_08086B84:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08086B90: .4byte gCamera

.syntax divided
