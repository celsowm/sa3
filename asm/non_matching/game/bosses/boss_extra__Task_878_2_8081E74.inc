.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r6, _08081EDC @ =gCurTask
	ldr r0, [r6]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r1, r0
	ldr r0, _08081EE0 @ =gStageData
	ldrb r0, [r0, #4]
	cmp r0, #3
	bne _08081ED4
	ldr r2, _08081EE4 @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _08081EE8 @ =0x00009FFF
	ands r0, r1
	ldr r1, _08081EEC @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08081EF0 @ =gCamera
	adds r1, #0x5c
	ldrh r2, [r1]
	ldr r0, _08081EF4 @ =0x0000FFFE
	ands r0, r2
	movs r4, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r5, #4]
	strh r4, [r5, #8]
	movs r0, #0x3c
	strh r0, [r5, #6]
	adds r0, r5, #0
	bl sub_8081FBC
	adds r0, r5, #0
	bl sub_80824F4
	movs r0, #0x10
	bl VramMalloc
	str r0, [r5, #0x1c]
	movs r0, #0x10
	bl VramMalloc
	str r0, [r5, #0x20]
	str r4, [r5, #0x24]
	ldr r1, [r6]
	ldr r0, _08081EF8 @ =sub_8086F08
	str r0, [r1, #8]
_08081ED4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081EDC: .4byte gCurTask
_08081EE0: .4byte gStageData
_08081EE4: .4byte gDispCnt
_08081EE8: .4byte 0x00009FFF
_08081EEC: .4byte 0x0000FEFF
_08081EF0: .4byte gCamera
_08081EF4: .4byte 0x0000FFFE
_08081EF8: .4byte sub_8086F08

.syntax divided
