.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x14
	movs r0, #0x30
	adds r0, r0, r6
	mov sb, r0
	adds r7, r6, #0
	adds r7, #0x68
	adds r3, r6, #0
	adds r3, #0xa0
	ldrh r1, [r5, #0x18]
	ldr r4, _08080C20 @ =0x0000041A
	cmp r1, r4
	bne _08080BF8
	b _0808100C
_08080BF8:
	cmp r1, r4
	bgt _08080C7C
	cmp r1, #0x32
	bne _08080C02
	b _08080DD4
_08080C02:
	cmp r1, #0x32
	bgt _08080C32
	cmp r1, #0x14
	bne _08080C0C
	b _08080D58
_08080C0C:
	cmp r1, #0x14
	bgt _08080C24
	cmp r1, #0
	bne _08080C16
	b _08080D30
_08080C16:
	cmp r1, #0xa
	bne _08080C1C
	b _08080D38
_08080C1C:
	b _080811C6
	.align 2, 0
_08080C20: .4byte 0x0000041A
_08080C24:
	cmp r1, #0x1e
	bne _08080C2A
	b _08080D70
_08080C2A:
	cmp r1, #0x28
	bne _08080C30
	b _08080D8C
_08080C30:
	b _080811C6
_08080C32:
	ldr r2, _08080C50 @ =0x000003F2
	cmp r1, r2
	bne _08080C3A
	b _08080F38
_08080C3A:
	cmp r1, r2
	bgt _08080C54
	cmp r1, #0x64
	bne _08080C44
	b _08080E2C
_08080C44:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	bne _08080C4E
	b _08080F34
_08080C4E:
	b _080811C6
	.align 2, 0
_08080C50: .4byte 0x000003F2
_08080C54:
	ldr r2, _08080C6C @ =0x00000406
	cmp r1, r2
	bne _08080C5C
	b _08080F6C
_08080C5C:
	cmp r1, r2
	bgt _08080C70
	movs r0, #0xff
	lsls r0, r0, #2
	cmp r1, r0
	bne _08080C6A
	b _08080F58
_08080C6A:
	b _080811C6
	.align 2, 0
_08080C6C: .4byte 0x00000406
_08080C70:
	movs r0, #0x82
	lsls r0, r0, #3
	cmp r1, r0
	bne _08080C7A
	b _08080FB4
_08080C7A:
	b _080811C6
_08080C7C:
	ldr r4, _08080CA8 @ =0x0000046A
	cmp r1, r4
	bne _08080C84
	b _0808111C
_08080C84:
	cmp r1, r4
	bgt _08080CDC
	movs r0, #0x87
	lsls r0, r0, #3
	cmp r1, r0
	bne _08080C92
	b _0808103E
_08080C92:
	cmp r1, r0
	bgt _08080CB0
	ldr r2, _08080CAC @ =0x00000424
	cmp r1, r2
	bne _08080C9E
	b _080811C6
_08080C9E:
	subs r0, #0xa
	cmp r1, r0
	bne _08080CA6
	b _0808102C
_08080CA6:
	b _080811C6
	.align 2, 0
_08080CA8: .4byte 0x0000046A
_08080CAC: .4byte 0x00000424
_08080CB0:
	ldr r2, _08080CC8 @ =0x00000456
	cmp r1, r2
	bne _08080CB8
	b _08081092
_08080CB8:
	cmp r1, r2
	bgt _08080CD0
	ldr r0, _08080CCC @ =0x0000044C
	cmp r1, r0
	bne _08080CC4
	b _08081084
_08080CC4:
	b _080811C6
	.align 2, 0
_08080CC8: .4byte 0x00000456
_08080CCC: .4byte 0x0000044C
_08080CD0:
	movs r0, #0x8c
	lsls r0, r0, #3
	cmp r1, r0
	bne _08080CDA
	b _080810E0
_08080CDA:
	b _080811C6
_08080CDC:
	movs r2, #0x91
	lsls r2, r2, #3
	cmp r1, r2
	bne _08080CE6
	b _0808116A
_08080CE6:
	cmp r1, r2
	bgt _08080D00
	ldr r0, _08080CFC @ =0x00000474
	cmp r1, r0
	bne _08080CF2
	b _08081128
_08080CF2:
	adds r0, #0xa
	cmp r1, r0
	bne _08080CFA
	b _08081154
_08080CFA:
	b _080811C6
	.align 2, 0
_08080CFC: .4byte 0x00000474
_08080D00:
	ldr r2, _08080D18 @ =0x0000049C
	cmp r1, r2
	bne _08080D08
	b _08081180
_08080D08:
	cmp r1, r2
	bgt _08080D20
	ldr r0, _08080D1C @ =0x00000492
	cmp r1, r0
	bne _08080D14
	b _0808113C
_08080D14:
	b _080811C6
	.align 2, 0
_08080D18: .4byte 0x0000049C
_08080D1C: .4byte 0x00000492
_08080D20:
	ldr r0, _08080D2C @ =0x000004A6
	cmp r1, r0
	bne _08080D28
	b _080811AC
_08080D28:
	b _080811C6
	.align 2, 0
_08080D2C: .4byte 0x000004A6
_08080D30:
	movs r0, #0x4b
	strh r0, [r5, #0x14]
	movs r0, #0xa
	b _080811C4
_08080D38:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	beq _08080D48
	b _080811C6
_08080D48:
	str r0, [r5, #8]
	ldr r0, _08080D54 @ =0xFFFFFF00
	str r0, [r5, #0xc]
	movs r0, #0x14
	b _080811C4
	.align 2, 0
_08080D54: .4byte 0xFFFFFF00
_08080D58:
	ldr r0, [r5, #4]
	ldr r1, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	asrs r0, r0, #8
	cmp r0, #0x6e
	ble _08080D68
	b _080811C6
_08080D68:
	movs r0, #0x28
	strh r0, [r5, #0x14]
	movs r0, #0x1e
	b _080811C4
_08080D70:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08080D80
	b _080811C6
_08080D80:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	movs r0, #0x28
	b _08080F88
_08080D8C:
	ldr r0, [r6, #0x14]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [r6, #0x14]
	asrs r1, r0, #8
	ldr r0, _08080DBC @ =0x00000923
	cmp r1, r0
	ble _08080DC0
	movs r0, #0
	strh r0, [r5, #0x16]
	movs r0, #0x20
	strh r0, [r5, #0x14]
	ldr r0, [r6, #0x14]
	str r0, [r5, #8]
	ldr r0, [r5, #4]
	str r0, [r5, #0xc]
	movs r0, #0x32
	strh r0, [r5, #0x18]
	movs r0, #0x9f
	lsls r0, r0, #2     @ VOICE__EGGMAN__OW
	bl m4aSongNumStart
	b _080811C6
	.align 2, 0
_08080DBC: .4byte 0x00000923
_08080DC0:
	ldr r0, _08080DD0 @ =0x00000833
	cmp r1, r0
	bgt _08080DC8
	b _080811C6
_08080DC8:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r5, #8]
	b _080811C6
	.align 2, 0
_08080DD0: .4byte 0x00000833
_08080DD4:
	ldr r2, _08080E24 @ =gUnknown_080D5C80
	ldrh r0, [r5, #0x16]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #8
	ldr r0, [r5, #8]
	adds r0, r0, r1
	str r0, [r6, #0x14]
	ldrh r0, [r5, #0x16]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #8
	ldr r0, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrh r0, [r5, #0x16]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	strh r0, [r5, #0x16]
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08080E14
	b _080811C6
_08080E14:
	movs r0, #0x80
	str r0, [r5, #0xc]
	movs r0, #0x64
	strh r0, [r5, #0x18]
	ldr r0, _08080E28 @ =0x00000221
	bl m4aSongNumStart
	b _080811C6
	.align 2, 0
_08080E24: .4byte gUnknown_080D5C80
_08080E28: .4byte 0x00000221
_08080E2C:
	ldrh r0, [r5, #0x16]
	adds r0, #8
	ldr r2, _08080F10 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r5, #0x16]
	ldr r3, _08080F14 @ =gSineTable
	mov ip, r3
	ldrh r0, [r5, #0x16]
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bge _08080E4C
	adds r0, #0x3f
_08080E4C:
	asrs r4, r0, #6
	ldr r0, [r6, #0x14]
	adds r0, r0, r4
	str r0, [r6, #0x14]
	ldr r1, [r5, #4]
	ldr r0, [r5, #0xc]
	adds r1, r1, r0
	mov r8, r1
	str r1, [r5, #4]
	ldrh r0, [r5, #0x14]
	adds r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08080EEA
	ldr r0, _08080F18 @ =gStageData
	ldr r0, [r0, #0x1c]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08080ED0
	ldr r4, _08080F1C @ =gPseudoRandom
	ldr r0, [r4]
	ldr r3, _08080F20 @ =0x00196225
	muls r0, r3, r0
	ldr r2, _08080F24 @ =0x3C6EF35F
	adds r0, r0, r2
	ldr r1, _08080F28 @ =0x000003FF
	ands r1, r0
	muls r0, r3, r0
	adds r0, r0, r2
	str r0, [r4]
	movs r3, #0xf
	ands r3, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r1, r2
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	lsrs r4, r0, #6
	lsls r0, r1, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	lsrs r1, r1, #6
	ldr r0, [r6, #0x14]
	adds r0, r0, r4
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	add r1, r8
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	movs r3, #0x80
	lsls r3, r3, #2
	movs r4, #0x1e
	str r4, [sp]
	ldr r4, [r6, #8]
	str r4, [sp, #4]
	bl sub_8086D64
_08080ED0:
	ldr r0, [r6, #0x14]
	asrs r0, r0, #8
	ldr r1, _08080F2C @ =0x00000996
	cmp r0, r1
	bgt _08080EEA
	ldrh r1, [r5, #0x14]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08080EEA
	ldr r0, _08080F30 @ =0x00000221
	bl m4aSongNumStart
_08080EEA:
	movs r2, #0x14
	ldrsh r0, [r5, r2]
	cmp r0, #0xa
	bne _08080F00
	movs r0, #0x9f
	lsls r0, r0, #3
	strh r0, [r7, #0xc]
	movs r0, #4
	strb r0, [r7, #0x1a]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
_08080F00:
	ldr r0, [r5, #4]
	asrs r0, r0, #8
	cmp r0, #0xf9
	bgt _08080F0A
	b _080811C6
_08080F0A:
	movs r0, #0xc8
	b _080811C4
	.align 2, 0
_08080F10: .4byte 0x000001FF
_08080F14: .4byte gSineTable
_08080F18: .4byte gStageData
_08080F1C: .4byte gPseudoRandom
_08080F20: .4byte 0x00196225
_08080F24: .4byte 0x3C6EF35F
_08080F28: .4byte 0x000003FF
_08080F2C: .4byte 0x00000996
_08080F30: .4byte 0x00000221
_08080F34:
	movs r0, #0x4b
	b _08081164
_08080F38:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	beq _08080F48
	b _080811C6
_08080F48:
	str r0, [r5, #8]
	ldr r0, _08080F54 @ =0xFFFFFF00
	str r0, [r5, #0xc]
	movs r0, #0xff
	lsls r0, r0, #2
	b _080811C4
	.align 2, 0
_08080F54: .4byte 0xFFFFFF00
_08080F58:
	ldr r0, [r5, #4]
	ldr r1, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	asrs r0, r0, #8
	cmp r0, #0x6e
	ble _08080F68
	b _080811C6
_08080F68:
	movs r0, #0x28
	b _08081164
_08080F6C:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08080F7C
	b _080811C6
_08080F7C:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	movs r0, #0x82
	lsls r0, r0, #3
_08080F88:
	strh r0, [r5, #0x18]
	movs r0, #0x9f
	lsls r0, r0, #3
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r7, #0x1a]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	ldr r0, [r7, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, [r3, #8]
	orrs r0, r1
	str r0, [r3, #8]
	ldr r0, _08080FB0 @ =0x0000027E @ VOICE__EGGMAN__YOURE_GOING_TO_PAY_FOR_THIS
	bl m4aSongNumStart
	b _080811C6
	.align 2, 0
_08080FB0: .4byte 0x0000027E
_08080FB4:
	ldr r0, [r6, #0x14]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [r6, #0x14]
	asrs r0, r0, #8
	ldr r1, _08080FE8 @ =0x000008FB
	cmp r0, r1
	ble _08080FF4
	ldr r0, _08080FEC @ =0xFFFFFF00
	str r0, [r5, #8]
	movs r1, #0
	movs r0, #0x9f
	lsls r0, r0, #3
	strh r0, [r7, #0xc]
	strb r1, [r7, #0x1a]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	ldr r0, [r7, #8]
	ldr r1, _08080FF0 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r7, #8]
	ldr r0, [r3, #8]
	ands r0, r1
	str r0, [r3, #8]
	strh r4, [r5, #0x18]
	b _080811C6
	.align 2, 0
_08080FE8: .4byte 0x000008FB
_08080FEC: .4byte 0xFFFFFF00
_08080FF0: .4byte 0xFFFFFBFF
_08080FF4:
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r1, _08081008 @ =0x000007CF
	cmp r0, r1
	bgt _08081000
	b _080811C6
_08081000:
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r5, #8]
	b _080811C6
	.align 2, 0
_08081008: .4byte 0x000007CF
_0808100C:
	ldr r0, [r6, #0x14]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [r6, #0x14]
	asrs r0, r0, #8
	ldr r1, _08081024 @ =0x000008BB
	cmp r0, r1
	ble _0808101E
	b _080811C6
_0808101E:
	ldr r0, _08081028 @ =0x00000424
	b _080811C4
	.align 2, 0
_08081024: .4byte 0x000008BB
_08081028: .4byte 0x00000424
_0808102C:
	movs r0, #0x9f
	lsls r0, r0, #3
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r7, #0x1a]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	strh r2, [r5, #0x18]
	b _080811C6
_0808103E:
	movs r0, #0x9f
	lsls r0, r0, #3
	strh r0, [r7, #0xc]
	movs r0, #0xc
	strb r0, [r7, #0x1a]
	movs r0, #0xff
	strb r0, [r7, #0x1b]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r7, #0x14]
	ldr r0, _08081080 @ =0x000004F7
	strh r0, [r3, #0xc]
	movs r0, #5
	strb r0, [r3, #0x1a]
	subs r0, #6
	strb r0, [r3, #0x1b]
	movs r0, #0xb0
	lsls r0, r0, #2
	strh r0, [r3, #0x14]
	ldr r0, [r7, #8]
	movs r1, #0x3e
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, [r3, #8]
	movs r1, #0x3f
	orrs r0, r1
	str r0, [r3, #8]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r6, #2]
	adds r0, #0xa4
	b _080811C4
	.align 2, 0
_08081080: .4byte 0x000004F7
_08081084:
	movs r0, #0
	str r0, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #4
	str r0, [r5, #0xc]
	strh r2, [r5, #0x18]
	b _080811C6
_08081092:
	ldr r0, [r6, #0x14]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [r6, #0x14]
	ldr r1, [r5, #4]
	ldr r0, [r5, #0xc]
	adds r1, r1, r0
	str r1, [r5, #4]
	asrs r1, r1, #8
	ldr r0, _080810D8 @ =gCamera
	ldr r0, [r0, #4]
	adds r0, #0x79
	cmp r1, r0
	bge _080810B0
	b _080811C6
_080810B0:
	movs r0, #0x80
	lsls r0, r0, #4
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0x91
	str r1, [sp]
	movs r1, #0x40
	movs r2, #0
	bl CreateScreenShake
	movs r0, #0x9f
	lsls r0, r0, #2
	bl m4aSongNumStart  @ VOICE__EGGMAN__OW
	ldr r0, _080810DC @ =0xFFFFFC00
	str r0, [r5, #0xc]
	movs r0, #0x8c
	lsls r0, r0, #3
	b _080811C4
	.align 2, 0
_080810D8: .4byte gCamera
_080810DC: .4byte 0xFFFFFC00
_080810E0:
	ldr r0, [r5, #0xc]
	adds r0, #0x2a
	str r0, [r5, #0xc]
	ldr r1, [r5, #4]
	adds r1, r1, r0
	str r1, [r5, #4]
	ldrh r1, [r6, #2]
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	beq _080810FC
	adds r0, r1, #0
	subs r0, #8
	strh r0, [r6, #2]
_080810FC:
	ldr r1, [r5, #4]
	asrs r1, r1, #8
	ldr r0, _08081118 @ =gCamera
	ldr r0, [r0, #4]
	adds r0, #0x79
	cmp r1, r0
	blt _080811C6
	ldr r0, [r5, #0xc]
	cmp r0, #0
	ble _080811C6
	movs r0, #0
	str r0, [r5, #0xc]
	strh r4, [r5, #0x18]
	b _080811C6
	.align 2, 0
_08081118: .4byte gCamera
_0808111C:
	ldr r0, _08081124 @ =0x000004E2
	strh r0, [r5, #0x14]
	subs r0, #0x6e
	b _080811C4
	.align 2, 0
_08081124: .4byte 0x000004E2
_08081128:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080811C6
	ldr r0, _08081138 @ =0x00000492
	b _080811C4
	.align 2, 0
_08081138: .4byte 0x00000492
_0808113C:
	ldrh r0, [r6, #2]
	adds r0, #8
	ldr r3, _08081150 @ =0x000003FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r6, #2]
	cmp r0, #0
	bne _080811C6
	movs r0, #0xb4
	b _08081164
	.align 2, 0
_08081150: .4byte 0x000003FF
_08081154:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080811C6
	movs r0, #0x96
	lsls r0, r0, #1
_08081164:
	strh r0, [r5, #0x14]
	strh r2, [r5, #0x18]
	b _080811C6
_0808116A:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080811C6
	ldr r0, _0808117C @ =0x00000492
	b _080811C4
	.align 2, 0
_0808117C: .4byte 0x00000492
_08081180:
	ldrh r0, [r5, #0x14]
	subs r0, #1
	strh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080811C6
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r5, #8]
	ldr r0, _080811A4 @ =0xFFFFFC00
	str r0, [r5, #0xc]
	ldr r0, _080811A8 @ =0x000004A6
	strh r0, [r5, #0x18]
	movs r0, #0x70
	bl m4aSongNumStart
	b _080811C6
	.align 2, 0
_080811A4: .4byte 0xFFFFFC00
_080811A8: .4byte 0x000004A6
_080811AC:
	ldr r0, [r6, #0x14]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [r6, #0x14]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	cmp r0, #0
	bge _080811C6
	movs r0, #0xfa
	lsls r0, r0, #3
_080811C4:
	strh r0, [r5, #0x18]
_080811C6:
	ldr r0, [r5]
	mov r4, sb
	str r0, [r4]
	ldr r0, [r5, #4]
	str r0, [r4, #4]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	@ struct 0x11C

.syntax divided
