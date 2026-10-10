.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08028CC4 @ =gCurTask
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r0, r4
	mov r8, r0
	movs r7, #0
	bl sub_802610C
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _08028CBE
	bl sub_8029368
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08028CC8
_08028CBE:
	bl sub_802613C
	b _08028DCC
	.align 2, 0
_08028CC4: .4byte gCurTask
_08028CC8:
	ldr r5, _08028D68 @ =gUnknown_03001060
	ldrb r1, [r5, #7]
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #1
	bl sub_8029150
	ldr r3, _08028D6C @ =gMultiSioSend
	ldr r1, _08028D70 @ =0x00006002
	strh r1, [r3]
	ldrb r0, [r5, #7]
	strb r0, [r3, #2]
	ldr r2, _08028D74 @ =0x0300048D
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3, #4]
	subs r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3, #5]
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3, #6]
	adds r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3, #8]
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3, #9]
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3, #0xa]
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3, #0xb]
	movs r2, #0
	ldrb r0, [r5, #7]
	mov ip, r0
	movs r6, #1
	adds r4, r5, #0
	ldr r5, _08028D78 @ =gMultiSioRecv
_08028D24:
	mov r0, ip
	asrs r0, r2
	ands r0, r6
	cmp r0, #0
	beq _08028D46
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r3, r0, r5
	ldrh r0, [r3]
	cmp r0, r1
	bne _08028D46
	adds r0, r6, #0
	lsls r0, r2
	orrs r7, r0
	lsls r0, r7, #0x18
	lsrs r7, r0, #0x18
_08028D46:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08028D24
	movs r1, #0x91
	lsls r1, r1, #3
	add r1, r8
	ldrh r0, [r1]
	movs r2, #0
	ldrsh r3, [r1, r2]
	cmp r3, #0
	beq _08028D7C
	subs r0, #1
	strh r0, [r1]
	b _08028DCC
	.align 2, 0
_08028D68: .4byte gUnknown_03001060
_08028D6C: .4byte gMultiSioSend
_08028D70: .4byte 0x00006002
_08028D74: .4byte 0x0300048D
_08028D78: .4byte gMultiSioRecv
_08028D7C:
	ldrb r0, [r4, #7]
	cmp r0, r7
	bne _08028DCC
	ldr r0, _08028DD8 @ =0x0000048B
	add r0, r8
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x54
	strb r1, [r0]
	ldr r0, _08028DDC @ =0x0000048C
	add r0, r8
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x55
	strb r0, [r1]
	ldr r0, _08028DE0 @ =0x0000048D
	add r0, r8
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x56
	strb r1, [r0]
	ldr r1, _08028DE4 @ =gStageData
	adds r2, r1, #0
	adds r2, #0x8e
	movs r0, #0xff
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x8f
	strb r3, [r0]
	ldr r0, _08028DE8 @ =0x0000048E
	add r0, r8
	ldrb r2, [r1, #6]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1, #0xb]
	bl sub_800214C
	movs r0, #0
	bl sub_80022E8
_08028DCC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028DD8: .4byte 0x0000048B
_08028DDC: .4byte 0x0000048C
_08028DE0: .4byte 0x0000048D
_08028DE4: .4byte gStageData
_08028DE8: .4byte 0x0000048E

.syntax divided
