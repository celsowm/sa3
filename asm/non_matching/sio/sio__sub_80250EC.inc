.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _08025124 @ =gUnknown_03001060
	ldrb r5, [r0, #7]
	movs r6, #0
	ldr r1, _08025128 @ =gStageData
	ldr r0, _0802512C @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r4, r0, #0
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080251E8
	cmp r4, #1
	bhi _08025130
	movs r0, #4
	lsls r0, r4
	ands r0, r5
	cmp r0, #0
	bne _08025130
	adds r2, r4, #2
	b _08025132
	.align 2, 0
_08025124: .4byte gUnknown_03001060
_08025128: .4byte gStageData
_0802512C: .4byte 0x04000128
_08025130:
	adds r2, r4, #0
_08025132:
	ldr r0, _08025160 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080251E0
	subs r0, r2, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080251C4
	cmp r2, #3
	bne _08025168
	ldr r1, _08025164 @ =gMultiSioRecv+2*0x18
	cmp r4, #1
	bhi _0802518E
	movs r0, #4
	lsls r0, r4
	ands r5, r0
	cmp r5, #0
	bne _0802518E
	b _0802518C
	.align 2, 0
_08025160: .4byte gMultiSioStatusFlags
_08025164: .4byte gMultiSioRecv+2*0x18
_08025168:
	cmp r4, #1
	bhi _08025180
	movs r0, #4
	lsls r0, r4
	ands r0, r5
	cmp r0, #0
	bne _08025180
	ldr r1, _0802517C @ =gMultiSioRecv+1*0x18
	b _0802518E
	.align 2, 0
_0802517C: .4byte gMultiSioRecv+1*0x18
_08025180:
	lsrs r0, r5, #3
	movs r1, #1
	ands r0, r1
	ldr r1, _080251B4 @ =gMultiSioRecv+3*0x18
	cmp r0, #0
	bne _0802518E
_0802518C:
	subs r1, #0x30
_0802518E:
	ldrh r1, [r1]
	ldr r2, _080251B8 @ =0xFFFF99F9
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _080251AA
	adds r2, r1, #0
	ldr r0, _080251BC @ =0x0000660B
	cmp r2, r0
	beq _080251AA
	subs r0, #1
	cmp r2, r0
	bne _080251E0
_080251AA:
	ldr r0, _080251C0 @ =0x00006608
	cmp r1, r0
	beq _080251DE
	adds r0, #3
	b _080251DA
	.align 2, 0
_080251B4: .4byte gMultiSioRecv+3*0x18
_080251B8: .4byte 0xFFFF99F9
_080251BC: .4byte 0x0000660B
_080251C0: .4byte 0x00006608
_080251C4:
	cmp r4, #0
	bne _080251D0
	ldr r1, _080251CC @ =gMultiSioRecv+2*0x18
	b _080251D6
	.align 2, 0
_080251CC: .4byte gMultiSioRecv+2*0x18
_080251D0:
	cmp r4, #1
	bne _080251E0
	ldr r1, _080251F0 @ =gMultiSioRecv+3*0x18
_080251D6:
	ldrh r1, [r1]
	ldr r0, _080251F4 @ =0x0000660B
_080251DA:
	cmp r1, r0
	bne _080251E0
_080251DE:
	movs r6, #1
_080251E0:
	adds r0, r7, #0
	bl sub_8025874
	adds r0, r6, #0
_080251E8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080251F0: .4byte gMultiSioRecv+3*0x18
_080251F4: .4byte 0x0000660B

.syntax divided
