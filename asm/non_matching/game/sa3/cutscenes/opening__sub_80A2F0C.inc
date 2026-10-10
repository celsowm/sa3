.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r2, _080A2FD0 @ =gDispCnt
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080A2FD4 @ =gBgCntRegs
	mov r8, r0
	movs r1, #0
	mov sb, r1
	movs r4, #0
	ldr r0, _080A2FD8 @ =0x00000C81
	mov r3, r8
	strh r0, [r3, #2]
	ldr r6, _080A2FDC @ =gBgScrollRegs
	strh r4, [r6, #4]
	strh r4, [r6, #6]
	adds r0, r7, #0
	adds r0, #0x60
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _080A2FE0 @ =0x06006000
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	movs r1, #0x97
	lsls r1, r1, #1
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	movs r5, #0x20
	strh r5, [r0, #0x26]
	strh r5, [r0, #0x28]
	adds r1, r7, #0
	adds r1, #0x8a
	mov r3, sb
	strb r3, [r1]
	movs r1, #5
	strh r1, [r0, #0x2e]
	str r2, [sp]
	bl DrawBackground
	ldr r2, [sp]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080A2FE4 @ =0x00005888
	mov r1, r8
	strh r0, [r1, #4]
	strh r4, [r6, #8]
	strh r4, [r6, #0xa]
	adds r0, r7, #0
	adds r0, #0x20
	ldr r1, _080A2FE8 @ =0x06008000
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _080A2FEC @ =0x0600C000
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	ldr r1, _080A2FF0 @ =0x0000012D
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	strh r5, [r0, #0x26]
	strh r5, [r0, #0x28]
	adds r1, r7, #0
	adds r1, #0x4a
	mov r2, sb
	strb r2, [r1]
	movs r1, #6
	strh r1, [r0, #0x2e]
	bl DrawBackground
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2FD0: .4byte gDispCnt
_080A2FD4: .4byte gBgCntRegs
_080A2FD8: .4byte 0x00000C81
_080A2FDC: .4byte gBgScrollRegs
_080A2FE0: .4byte 0x06006000
_080A2FE4: .4byte 0x00005888
_080A2FE8: .4byte 0x06008000
_080A2FEC: .4byte 0x0600C000
_080A2FF0: .4byte 0x0000012D

.syntax divided
