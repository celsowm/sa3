.syntax unified
.text
	push {r4, lr}
	movs r4, #0
	ldr r1, _08025348 @ =gStageData
	ldr r0, _0802534C @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08025342
	ldr r0, _08025350 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0802533C
	ldr r2, _08025354 @ =gMultiSioRecv
	ldrh r1, [r2]
	ldr r0, _08025358 @ =0x0000660A
	cmp r1, r0
	bne _0802533C
	movs r1, #0
	ldr r4, _0802535C @ =gUnknown_030010AC
	adds r3, r2, #0
	adds r3, #0xf
_08025322:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r4
	adds r1, r3, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08025322
	movs r4, #1
_0802533C:
	bl sub_8025CD8
	adds r0, r4, #0
_08025342:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08025348: .4byte gStageData
_0802534C: .4byte 0x04000128
_08025350: .4byte gMultiSioStatusFlags
_08025354: .4byte gMultiSioRecv
_08025358: .4byte 0x0000660A
_0802535C: .4byte gUnknown_030010AC

.syntax divided
