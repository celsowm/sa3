.syntax unified
.text
	push {r4, lr}
	movs r4, #0
	ldr r1, _08024E08 @ =gStageData
	ldr r0, _08024E0C @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024E02
	ldr r0, _08024E10 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08024DFC
	ldr r0, _08024E14 @ =gMultiSioRecv
	ldrh r1, [r0]
	ldr r0, _08024E18 @ =0x00006606
	cmp r1, r0
	bne _08024DFC
	movs r4, #1
_08024DFC:
	bl sub_8025770
	adds r0, r4, #0
_08024E02:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08024E08: .4byte gStageData
_08024E0C: .4byte 0x04000128
_08024E10: .4byte gMultiSioStatusFlags
_08024E14: .4byte gMultiSioRecv
_08024E18: .4byte 0x00006606

.syntax divided
