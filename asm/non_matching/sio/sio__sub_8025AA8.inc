.syntax unified
.text
	push {lr}
	ldr r1, _08025AE0 @ =gStageData
	ldr r0, _08025AE4 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08025AF6
	bl sub_8025D10
	ldr r0, _08025AE8 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08025AF4
	ldr r0, _08025AEC @ =gMultiSioRecv
	ldrh r1, [r0]
	ldr r0, _08025AF0 @ =0x0000660D
	cmp r1, r0
	bne _08025AF4
	movs r0, #1
	b _08025AF6
	.align 2, 0
_08025AE0: .4byte gStageData
_08025AE4: .4byte 0x04000128
_08025AE8: .4byte gMultiSioStatusFlags
_08025AEC: .4byte gMultiSioRecv
_08025AF0: .4byte 0x0000660D
_08025AF4:
	movs r0, #0
_08025AF6:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
