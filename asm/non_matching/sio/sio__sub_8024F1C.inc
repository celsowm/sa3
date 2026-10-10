.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _08024F78 @ =gStageData
	ldr r0, _08024F7C @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	movs r6, #0xff
	adds r5, r0, #0
	cmp r5, #1
	bhi _08024F38
	adds r5, #2
_08024F38:
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024F72
	ldr r4, _08024F80 @ =gMultiSioSend
	adds r1, r4, #0
	adds r1, #0xf
	adds r1, r5, r1
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r0, #0
	strh r0, [r4, #0xc]
	bl sub_80247D4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	bl sub_80248F4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	adds r0, r7, #0
	bl sub_8025C8C
	movs r0, #1
_08024F72:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08024F78: .4byte gStageData
_08024F7C: .4byte 0x04000128
_08024F80: .4byte gMultiSioSend

.syntax divided
