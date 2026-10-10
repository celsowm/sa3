.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _080A4178 @ =gCurTask
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r4, r0
	movs r6, #0
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080A4102
	ldr r3, _080A417C @ =gBldRegs
	ldr r0, _080A4180 @ =0x00003FFF
	strh r0, [r3]
	ldr r2, _080A4184 @ =gDispCnt
	ldrh r0, [r2]
	movs r7, #0xc0
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A4188 @ =gWinRegs
	movs r0, #0xff
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #6]
	ldr r0, _080A418C @ =0x00001011
	strh r0, [r1, #8]
	strh r6, [r1, #0xa]
	movs r0, #0x10
	strh r0, [r3, #4]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r5, #6]
	movs r0, #1
	strh r0, [r5, #8]
	ldr r1, _080A4190 @ =0x03000002
	adds r0, r4, r1
	ldr r2, _080A4194 @ =0x03000001
	adds r1, r4, r2
	ldr r3, _080A4198 @ =0x03000018
	adds r2, r4, r3
	ldr r7, _080A419C @ =0x0300001C
	adds r3, r4, r7
	ldr r4, [r5, #0x28]
	str r4, [sp]
	bl CreateSomeTask_809BF3C
_080A4102:
	ldr r1, [r5, #0x14]
	ldr r0, _080A4180 @ =0x00003FFF
	cmp r1, r0
	ble _080A411C
	ldr r2, _080A41A0 @ =0xFFFFFF00
	adds r0, r1, r2
	str r0, [r5, #0x14]
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bgt _080A411C
	str r1, [r5, #0x14]
	movs r6, #1
_080A411C:
	ldr r1, [r5, #0xc]
	movs r2, #0x80
	lsls r2, r2, #6
	cmp r1, r2
	bgt _080A413C
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r1, r3
	str r1, [r5, #0xc]
	ldr r0, _080A41A4 @ =0x00001FFF
	cmp r1, r0
	ble _080A413C
	str r2, [r5, #0xc]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080A413C:
	ldr r3, _080A4188 @ =gWinRegs
	ldr r0, [r5, #0x14]
	asrs r0, r0, #8
	lsls r1, r0, #8
	adds r1, r1, r0
	ldr r0, [r5, #0xc]
	asrs r0, r0, #8
	adds r1, r1, r0
	movs r2, #0
	strh r1, [r3, #4]
	cmp r6, #2
	bne _080A416E
	ldr r1, _080A417C @ =gBldRegs
	ldr r0, _080A4180 @ =0x00003FFF
	strh r0, [r1]
	ldr r0, _080A418C @ =0x00001011
	strh r0, [r3, #8]
	strh r2, [r1, #2]
	movs r0, #0x10
	strh r0, [r1, #4]
	strh r2, [r5, #8]
	ldr r0, _080A4178 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A41A8 @ =Task_94_B_80A41AC
	str r0, [r1, #8]
_080A416E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4178: .4byte gCurTask
_080A417C: .4byte gBldRegs
_080A4180: .4byte 0x00003FFF
_080A4184: .4byte gDispCnt
_080A4188: .4byte gWinRegs
_080A418C: .4byte 0x00001011
_080A4190: .4byte 0x03000002
_080A4194: .4byte 0x03000001
_080A4198: .4byte 0x03000018
_080A419C: .4byte 0x0300001C
_080A41A0: .4byte 0xFFFFFF00
_080A41A4: .4byte 0x00001FFF
_080A41A8: .4byte Task_94_B_80A41AC

.syntax divided
