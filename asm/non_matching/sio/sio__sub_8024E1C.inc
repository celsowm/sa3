.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _08024E60 @ =gUnknown_03001060
	ldrb r5, [r0, #7]
	ldr r0, _08024E64 @ =gStageData
	ldrb r6, [r0, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08024F12
	ldr r7, _08024E68 @ =gMultiSioSend
	cmp r6, #1
	bhi _08024E6C
	movs r0, #4
	lsls r0, r6
	ands r0, r5
	cmp r0, #0
	bne _08024E6C
	adds r0, r6, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r7, #0
	adds r0, #0xf
	adds r0, r4, r0
	mov r1, r8
	strb r1, [r0]
	b _08024E6E
	.align 2, 0
_08024E60: .4byte gUnknown_03001060
_08024E64: .4byte gStageData
_08024E68: .4byte gMultiSioSend
_08024E6C:
	adds r4, r6, #0
_08024E6E:
	movs r0, #0
	strh r0, [r7, #0xc]
	bl sub_80247D4
	ldrh r1, [r7, #0xc]
	orrs r1, r0
	strh r1, [r7, #0xc]
	bl sub_80248F4
	ldrh r1, [r7, #0xc]
	orrs r1, r0
	strh r1, [r7, #0xc]
	mov r0, r8
	bl sub_8025874
	cmp r5, #3
	beq _08024E98
	cmp r5, #7
	beq _08024E98
	cmp r5, #0xf
	bne _08024F00
_08024E98:
	cmp r6, #1
	bhi _08024EDC
	cmp r4, r6
	beq _08024EDC
	cmp r4, #2
	bne _08024EB4
	lsrs r0, r5, #3
	movs r1, #1
	ands r0, r1
	ldr r1, _08024EB0 @ =gMultiSioRecv+1*0x18
	b _08024EBC
	.align 2, 0
_08024EB0: .4byte gMultiSioRecv+1*0x18
_08024EB4:
	lsrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	ldr r1, _08024ED4 @ =gMultiSioRecv
_08024EBC:
	cmp r0, #0
	beq _08024EC2
	adds r1, #0x30
_08024EC2:
	ldrh r1, [r1]
	ldr r0, _08024ED8 @ =0x00006608
	cmp r1, r0
	beq _08024F10
	adds r0, #3
	cmp r1, r0
	beq _08024F10
	b _08024F00
	.align 2, 0
_08024ED4: .4byte gMultiSioRecv
_08024ED8: .4byte 0x00006608
_08024EDC:
	ldr r1, _08024F04 @ =gMultiSioRecv+3*0x18
	cmp r4, #0
	bne _08024EE4
	subs r1, #0x18
_08024EE4:
	ldrh r2, [r1]
	ldr r0, _08024F08 @ =0x0000660B
	cmp r2, r0
	bne _08024F00
	lsrs r0, r5, #3
	movs r1, #1
	ands r0, r1
	ldr r1, _08024F0C @ =gMultiSioRecv+1*0x18
	cmp r0, #0
	beq _08024EFA
	adds r1, #0x30
_08024EFA:
	ldrh r0, [r1]
	cmp r0, r2
	beq _08024F10
_08024F00:
	movs r0, #0
	b _08024F12
	.align 2, 0
_08024F04: .4byte gMultiSioRecv+3*0x18
_08024F08: .4byte 0x0000660B
_08024F0C: .4byte gMultiSioRecv+1*0x18
_08024F10:
	movs r0, #1
_08024F12:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

.syntax divided
