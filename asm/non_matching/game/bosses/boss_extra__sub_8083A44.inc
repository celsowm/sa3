.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [r7, #0x28]
	cmp r1, #0
	beq _08083A62
	cmp r1, #1
	bne _08083A60
	b _08083B7E
_08083A60:
	b _08083BD0
_08083A62:
	ldr r0, _08083AA4 @ =gCamera
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	ldr r1, [r2, #0x10]
	adds r4, r1, r0
	ldr r5, [r2, #0x14]
	adds r0, r7, #0
	adds r0, #0xa0
	ldr r1, [r0]
	movs r2, #1
	mov sl, r2
	adds r3, r0, #0
	cmp r5, r1
	bgt _08083A86
	movs r6, #2
	mov sl, r6
_08083A86:
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r1, [r0]
	ldr r2, _08083AA8 @ =0xFFFF5800
	adds r0, r1, r2
	cmp r4, r0
	bgt _08083AAC
	asrs r0, r1, #8
	subs r0, #0xa8
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r4, sl
	lsls r2, r4, #1
	b _08083ACA
	.align 2, 0
_08083AA4: .4byte gCamera
_08083AA8: .4byte 0xFFFF5800
_08083AAC:
	mov r6, sl
	lsls r2, r6, #1
	adds r1, r2, r6
	lsls r1, r1, #3
	movs r6, #0x86
	lsls r6, r6, #1
	adds r0, r7, r6
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r4, r0
	blt _08083AC6
	lsls r0, r0, #8
	b _08083AC8
_08083AC6:
	lsls r0, r4, #8
_08083AC8:
	lsrs r1, r0, #0x10
_08083ACA:
	ldr r4, [r3]
	ldr r3, _08083ADC @ =0xFFFFE000
	adds r0, r4, r3
	cmp r5, r0
	bgt _08083AE0
	asrs r0, r4, #8
	subs r0, #0x20
	lsls r0, r0, #0x10
	b _08083AF4
	.align 2, 0
_08083ADC: .4byte 0xFFFFE000
_08083AE0:
	movs r6, #0x80
	lsls r6, r6, #6
	adds r0, r4, r6
	cmp r5, r0
	blt _08083AF2
	asrs r0, r4, #8
	adds r0, #0x20
	lsls r0, r0, #0x10
	b _08083AF4
_08083AF2:
	lsls r0, r5, #8
_08083AF4:
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r3, r1, #8
	mov r8, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r6, r0, #8
	mov r4, sl
	adds r3, r2, r4
	lsls r3, r3, #3
	movs r2, #0x86
	lsls r2, r2, #1
	adds r5, r7, r2
	adds r5, r5, r3
	ldr r2, [r5]
	asrs r2, r2, #8
	subs r1, r1, r2
	movs r2, #0x88
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r4, r4, r3
	ldr r2, [r4]
	asrs r2, r2, #8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sa2__sub_8004418
	adds r1, r7, #0
	adds r1, #0xcc
	movs r3, #0
	mov sb, r3
	strh r0, [r1]
	ldr r0, [r5]
	mov r1, r8
	subs r1, r1, r0
	mov r8, r1
	ldr r0, [r4]
	subs r6, r6, r0
	mov r0, r8
	muls r0, r1, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r7, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xd4
	mov r2, sb
	str r2, [r0]
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x80
	lsls r0, r0, #4
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xe3
	mov r4, sl
	strb r4, [r0]
	b _08083BD0
_08083B7E:
	adds r0, r7, #0
	adds r0, #0xe3
	ldrb r0, [r0]
	mov sl, r0
	ldr r1, [r2, #0x10]
	ldr r0, _08083BE0 @ =gCamera
	adds r0, #0x6a
	asrs r1, r1, #8
	ldrh r0, [r0]
	adds r1, r1, r0
	mov r6, sl
	lsls r3, r6, #1
	add r3, sl
	lsls r3, r3, #3
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r7, r4
	adds r0, r0, r3
	ldr r0, [r0]
	asrs r0, r0, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	subs r1, r1, r0
	ldr r0, [r2, #0x14]
	asrs r0, r0, #8
	movs r6, #0x88
	lsls r6, r6, #1
	adds r2, r7, r6
	adds r2, r2, r3
	ldr r2, [r2]
	asrs r2, r2, #8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sa2__sub_8004418
	adds r1, r7, #0
	adds r1, #0xce
	strh r0, [r1]
_08083BD0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08083BE0: .4byte gCamera

.syntax divided
