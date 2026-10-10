.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080A244C @ =gCurTask
	ldr r0, [r0]
	ldrh r2, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r0, r2
	mov r8, r0
	ldr r1, _080A2450 @ =gHBlankCopySize
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080A2454 @ =gHBlankCopyTarget
	ldr r0, _080A2458 @ =0x04000020
	str r0, [r1]
	ldr r1, _080A245C @ =gBgOffsetsHBlankPrimary
	ldr r3, _080A2460 @ =0x0300012C
	adds r0, r2, r3
	ldr r4, [r0]
	str r4, [r1]
	ldr r3, _080A2464 @ =gFlags
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	ldr r5, _080A2468 @ =0x03000138
	adds r3, r2, r5
	ldr r1, _080A246C @ =0x03000140
	adds r0, r2, r1
	ldrh r0, [r0]
	ldrh r5, [r3]
	adds r0, r0, r5
	ldr r1, _080A2470 @ =0x00000FFF
	ands r0, r1
	strh r0, [r3]
	ldr r0, _080A2474 @ =0x0300013A
	adds r3, r2, r0
	ldr r1, _080A2478 @ =0x03000142
	adds r0, r2, r1
	ldrh r0, [r0]
	ldrh r5, [r3]
	adds r0, r0, r5
	ldr r1, _080A247C @ =0x000007FF
	ands r0, r1
	strh r0, [r3]
	ldr r0, _080A2480 @ =0x03000148
	adds r1, r2, r0
	ldr r3, _080A2484 @ =0x03000144
	adds r0, r2, r3
	ldrh r0, [r0]
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	ldr r0, _080A2488 @ =0x0300014A
	adds r1, r2, r0
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	movs r1, #0
	ldr r0, _080A248C @ =0x03000136
	adds r6, r2, r0
	subs r3, #0x16
	adds r3, r3, r2
	mov ip, r3
	ldr r5, _080A2474 @ =0x0300013A
	adds r5, r5, r2
	mov sb, r5
_080A2434:
	lsls r1, r1, #0x10
	asrs r2, r1, #0x10
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r0, r2, r0
	adds r7, r1, #0
	cmp r0, #0
	blt _080A2490
	ldrh r0, [r6]
	subs r0, r2, r0
	b _080A2494
	.align 2, 0
_080A244C: .4byte gCurTask
_080A2450: .4byte gHBlankCopySize
_080A2454: .4byte gHBlankCopyTarget
_080A2458: .4byte 0x04000020
_080A245C: .4byte gBgOffsetsHBlankPrimary
_080A2460: .4byte 0x0300012C
_080A2464: .4byte gFlags
_080A2468: .4byte 0x03000138
_080A246C: .4byte 0x03000140
_080A2470: .4byte 0x00000FFF
_080A2474: .4byte 0x0300013A
_080A2478: .4byte 0x03000142
_080A247C: .4byte 0x000007FF
_080A2480: .4byte 0x03000148
_080A2484: .4byte 0x03000144
_080A2488: .4byte 0x0300014A
_080A248C: .4byte 0x03000136
_080A2490:
	ldrh r0, [r6]
	subs r0, r0, r2
_080A2494:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r0, #0
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	mov r0, ip
	ldr r2, [r0]
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	muls r1, r0, r1
	lsls r1, r1, #1
	mov r2, sb
	ldrh r0, [r2]
	lsls r0, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	asrs r1, r7, #0x10
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bge _080A24D4
	lsls r0, r3, #0x10
	cmp r0, #0
	bge _080A24E4
	ldr r1, _080A24D0 @ =0xFFFF8000
	adds r0, r3, r1
	b _080A24E0
	.align 2, 0
_080A24D0: .4byte 0xFFFF8000
_080A24D4:
	lsls r0, r3, #0x10
	cmp r0, #0
	blt _080A24E4
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r3, r2
_080A24E0:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_080A24E4:
	lsls r2, r5, #0x10
	mov r5, ip
	ldr r0, [r5]
	asrs r2, r2, #0xe
	adds r0, r2, r0
	ldr r0, [r0]
	lsrs r0, r0, #2
	strh r0, [r4]
	ldr r0, [r5]
	adds r2, r2, r0
	movs r0, #0x9a
	lsls r0, r0, #1
	add r0, r8
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, [r2]
	muls r1, r0, r1
	lsrs r1, r1, #2
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	strh r1, [r4, #8]
	strh r3, [r4, #0xc]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r7, r1
	adds r4, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _080A2434
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
