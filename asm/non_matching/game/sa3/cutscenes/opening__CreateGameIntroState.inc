.syntax unified
.text
	push {r4, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _080A20D4 @ =Task_170_GameIntroInit
	movs r1, #0xb8
	lsls r1, r1, #1
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r3, _080A20D8 @ =TaskDestructor_GameIntro
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r1, r1, r0
	mov ip, r1
	lsls r0, r4, #0x10
	ldr r1, _080A20DC @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080A20E4
	ldr r1, _080A20E0 @ =gStageData
	movs r0, #0
	b _080A20E8
	.align 2, 0
_080A20D4: .4byte Task_170_GameIntroInit
_080A20D8: .4byte TaskDestructor_GameIntro
_080A20DC: .4byte 0xFFFF0000
_080A20E0: .4byte gStageData
_080A20E4:
	ldr r1, _080A216C @ =gStageData
	movs r0, #1
_080A20E8:
	strb r0, [r1, #7]
	movs r1, #0x9a
	lsls r1, r1, #1
	add r1, ip
	movs r2, #0
	ldr r0, _080A2170 @ =0x0000FF10
	strh r0, [r1]
	movs r1, #0x9b
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x8c
	strh r0, [r1]
	adds r0, #0xac
	add r0, ip
	strh r2, [r0]
	movs r0, #0x9d
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xa0
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r1, #0xa1
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _080A2174 @ =0x0000FFD0
	strh r0, [r1]
	movs r0, #0xa2
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0x10
	strh r3, [r0]
	movs r0, #0xa3
	lsls r0, r0, #1
	add r0, ip
	strh r3, [r0]
	movs r0, #0xa4
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	strh r4, [r0]
	ldr r0, _080A2178 @ =gBldRegs
	movs r1, #0xff
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A216C: .4byte gStageData
_080A2170: .4byte 0x0000FF10
_080A2174: .4byte 0x0000FFD0
_080A2178: .4byte gBldRegs

.syntax divided
