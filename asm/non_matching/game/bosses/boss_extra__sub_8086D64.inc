.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	adds r4, r2, #0
	mov sb, r3
	ldr r5, [sp, #0x24]
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r7, sb
	lsls r7, r7, #0x10
	adds r0, r7, #0
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _08086E40 @ =Task_38_8086E58
	movs r2, #0x84
	lsls r2, r2, #6
	ldr r1, _08086E44 @ =TaskDestructor_38_8087234
	str r1, [sp]
	movs r1, #0x38
	movs r3, #0
	bl TaskCreate
	ldrh r2, [r0, #6]
	movs r3, #0xc0
	lsls r3, r3, #0x12
	adds r3, r2, r3
	ldr r7, _08086E48 @ =0x03000010
	adds r2, r2, r7
	movs r0, #0
	mov sl, r0
	strb r5, [r3, #0xe]
	movs r5, #0
	mov ip, r5
	mov r7, sl
	strh r7, [r3, #0xc]
	ldr r5, _08086E4C @ =gSineTable
	ldr r1, _08086E50 @ =0x000003FF
	mov r0, sb
	ands r1, r0
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r1, r7
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	muls r0, r4, r0
	asrs r0, r0, #0xe
	strh r0, [r3, #8]
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	muls r0, r4, r0
	asrs r0, r0, #0xe
	strh r0, [r3, #0xa]
	ldr r7, [sp, #0x28]
	str r7, [r2]
	ldr r0, _08086E54 @ =0x000004F9
	strh r0, [r2, #0xc]
	mov r0, ip
	strb r0, [r2, #0x1a]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2, #0x14]
	mov r5, sl
	strh r5, [r2, #0xe]
	strh r5, [r2, #0x16]
	movs r0, #0xff
	strb r0, [r2, #0x1b]
	movs r0, #0x10
	strb r0, [r2, #0x1c]
	mov r7, ip
	strb r7, [r2, #0x1f]
	subs r0, #0x11
	str r0, [r2, #0x20]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r2, #8]
	lsls r6, r6, #0x10
	asrs r6, r6, #8
	str r6, [r3]
	mov r0, r8
	lsls r0, r0, #0x10
	asrs r0, r0, #8
	str r0, [r3, #4]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08086E40: .4byte Task_38_8086E58
_08086E44: .4byte TaskDestructor_38_8087234
_08086E48: .4byte 0x03000010
_08086E4C: .4byte gSineTable
_08086E50: .4byte 0x000003FF
_08086E54: .4byte 0x000004F9

.syntax divided
