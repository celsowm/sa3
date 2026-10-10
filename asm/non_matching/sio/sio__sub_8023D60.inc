.syntax unified
.text
	push {r4, r5, lr}
	ldr r1, _08023D8C @ =gStageData
	ldr r0, _08023D90 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08023DE8
	ldr r0, _08023D94 @ =gMultiSioStatusFlags
	ldr r1, [r0]
	ldr r0, _08023D98 @ =0x00000C0C
	ands r0, r1
	cmp r0, #0
	beq _08023D9C
	movs r0, #4
	rsbs r0, r0, #0
	b _08023DE8
	.align 2, 0
_08023D8C: .4byte gStageData
_08023D90: .4byte 0x04000128
_08023D94: .4byte gMultiSioStatusFlags
_08023D98: .4byte 0x00000C0C
_08023D9C:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08023DA8
	movs r0, #0
	b _08023DE8
_08023DA8:
	ldr r5, _08023DF0 @ =gMultiSioSend
	ldr r3, _08023DF4 @ =gMultiSioRecv
	movs r4, #0
	ldr r1, _08023DF8 @ =0xFFFF93FE
	adds r0, r1, #0
	ldrh r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08023DCC
	ldr r2, _08023DFC @ =gUnknown_03001060
	ldrb r1, [r3, #2]
	strb r1, [r5, #2]
	movs r0, #0xff
	ands r0, r1
	strb r0, [r2, #7]
	adds r4, r0, #0
_08023DCC:
	ldrh r1, [r3]
	ldr r0, _08023E00 @ =0x00006C03
	cmp r1, r0
	bne _08023DE0
	movs r1, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08023DE0:
	bl sub_8024324
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
_08023DE8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08023DF0: .4byte gMultiSioSend
_08023DF4: .4byte gMultiSioRecv
_08023DF8: .4byte 0xFFFF93FE
_08023DFC: .4byte gUnknown_03001060
_08023E00: .4byte 0x00006C03

.syntax divided
