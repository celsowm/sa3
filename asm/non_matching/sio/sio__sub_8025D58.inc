.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #4
	bl sub_80260F0
	movs r2, #0
	str r2, [sp]
	ldr r1, _08025DF8 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08025DFC @ =gMultiSioSend
	str r0, [r1, #4]
	ldr r0, _08025E00 @ =0x85000006
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r2, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r0, _08025E04 @ =gMultiSioRecv
	str r0, [r1, #4]
	ldr r0, _08025E08 @ =0x85000018
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r2, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r2, _08025E0C @ =gUnknown_03001060
	str r2, [r1, #4]
	ldr r0, _08025E10 @ =0x85000001
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	adds r3, r2, #0
	adds r6, r3, #0
	adds r6, #0x4c
	movs r5, #0xff
	movs r4, #0
_08025DA0:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r6
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r0, r1, r3
	strb r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08025DA0
	movs r0, #0
	bl MultiSioInit
	ldr r0, _08025DFC @ =gMultiSioSend
	ldr r1, _08025E04 @ =gMultiSioRecv
	movs r2, #0
	bl MultiSioMain
	ldr r1, _08025E14 @ =gMultiSioStatusFlags
	str r0, [r1]
	ldr r4, _08025E18 @ =gStageData
	ldr r1, _08025E1C @ =0x04000128
	ldr r1, [r1]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1e
	strb r1, [r4, #6]
	ldr r2, _08025E20 @ =gMultiSioEnabled
	movs r1, #1
	strb r1, [r2]
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08025DEE
	bl MultiSioStart
_08025DEE:
	ldrb r0, [r4, #6]
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08025DF8: .4byte 0x040000D4
_08025DFC: .4byte gMultiSioSend
_08025E00: .4byte 0x85000006
_08025E04: .4byte gMultiSioRecv
_08025E08: .4byte 0x85000018
_08025E0C: .4byte gUnknown_03001060
_08025E10: .4byte 0x85000001
_08025E14: .4byte gMultiSioStatusFlags
_08025E18: .4byte gStageData
_08025E1C: .4byte 0x04000128
_08025E20: .4byte gMultiSioEnabled

.syntax divided
