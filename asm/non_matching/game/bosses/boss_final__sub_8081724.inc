.syntax unified
.text
	push {r4, r5, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r2, r0, #2
	adds r0, r3, #0
	adds r0, #0x38
	adds r5, r0, r2
	ldr r0, [r5]
	cmp r0, #0
	bgt _08081782
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r4, r0, #3
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r1, r3, r0
	adds r1, r1, r4
	adds r0, r3, #0
	adds r0, #0x30
	adds r0, r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _08081764
	rsbs r0, r1, #0
_08081764:
	asrs r1, r0, #8
	cmp r1, #0x13
	bgt _08081782
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r3, r1
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [r5]
	adds r1, r3, r2
	movs r0, #0x64
	strh r0, [r1, #0x3e]
	ldr r0, _08081788 @ =0x0000023A
	bl m4aSongNumStart
_08081782:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081788: .4byte 0x0000023A

.syntax divided
