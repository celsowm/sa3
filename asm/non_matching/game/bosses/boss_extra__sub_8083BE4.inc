.syntax unified
.text
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #8]
	movs r3, #0x9b
	lsls r3, r3, #1
	cmp r1, r3
	bne _08083BF4
	b _08083E46
_08083BF4:
	cmp r1, r3
	bgt _08083C2C
	cmp r1, #0x14
	bne _08083BFE
	b _08083D92
_08083BFE:
	cmp r1, #0x14
	bgt _08083C0E
	cmp r1, #0
	beq _08083C78
	cmp r1, #0xa
	bne _08083C0C
	b _08083D3A
_08083C0C:
	b _08083F86
_08083C0E:
	cmp r1, #0xc8
	bne _08083C14
	b _08083DBC
_08083C14:
	cmp r1, #0xc8
	bgt _08083C20
	cmp r1, #0x64
	bne _08083C1E
	b _08083D6C
_08083C1E:
	b _08083F86
_08083C20:
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _08083C2A
	b _08083E18
_08083C2A:
	b _08083F86
_08083C2C:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	beq _08083CC6
	cmp r1, r0
	bgt _08083C4C
	movs r0, #0xa0
	lsls r0, r0, #1
	cmp r1, r0
	bne _08083C42
	b _08083F04
_08083C42:
	adds r0, #0xb4
	cmp r1, r0
	bne _08083C4A
	b _08083F44
_08083C4A:
	b _08083F86
_08083C4C:
	movs r0, #0xfa
	lsls r0, r0, #3
	cmp r1, r0
	bne _08083C56
	b _08083F70
_08083C56:
	cmp r1, r0
	bgt _08083C68
	ldr r0, _08083C64 @ =0x000003F2
	cmp r1, r0
	beq _08083C9A
	b _08083F86
	.align 2, 0
_08083C64: .4byte 0x000003F2
_08083C68:
	ldr r0, _08083C74 @ =0x00001770
	cmp r1, r0
	bne _08083C70
	b _08083F76
_08083C70:
	b _08083F86
	.align 2, 0
_08083C74: .4byte 0x00001770
_08083C78:
	adds r0, r4, #0
	adds r0, #0xe2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r2, _08083D24 @ =gPseudoRandom
	ldr r1, [r2]
	ldr r0, _08083D28 @ =0x00196225
	muls r0, r1, r0
	ldr r1, _08083D2C @ =0x3C6EF35F
	adds r0, r0, r1
	str r0, [r2]
	adds r2, r4, #0
	adds r2, #0xf2
	movs r1, #0
	strh r0, [r2]
	strb r1, [r4, #2]
_08083C9A:
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r4, #8]
	movs r0, #0x3c
	strh r0, [r4, #4]
	movs r1, #0
	ldr r3, _08083D30 @ =0x000004FE
	movs r2, #1
_08083CAA:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r5, #0xed
	lsls r5, r5, #2
	adds r0, r0, r5
	adds r0, r4, r0
	strh r3, [r0, #0xc]
	strb r2, [r0, #0x1a]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _08083CAA
_08083CC6:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08083CD4
	b _08083F86
_08083CD4:
	adds r0, r4, #0
	adds r0, #0xf2
	adds r2, r4, #0
	adds r2, #0xe2
	ldrb r1, [r2]
	movs r3, #1
	lsls r3, r1
	ldrh r0, [r0]
	ands r3, r0
	cmp r1, #4
	bhi _08083CEE
	cmp r3, #0
	bne _08083CF2
_08083CEE:
	cmp r1, #0
	bne _08083D34
_08083CF2:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r0, #0x3c
	strh r0, [r4, #4]
	movs r1, #0
	movs r3, #0
	ldr r2, _08083D30 @ =0x000004FE
_08083D02:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r5, #0xed
	lsls r5, r5, #2
	adds r0, r0, r5
	adds r0, r4, r0
	strh r2, [r0, #0xc]
	strb r3, [r0, #0x1a]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _08083D02
	movs r0, #0xa
	b _08083F84
	.align 2, 0
_08083D24: .4byte gPseudoRandom
_08083D28: .4byte 0x00196225
_08083D2C: .4byte 0x3C6EF35F
_08083D30: .4byte 0x000004FE
_08083D34:
	movs r0, #0xfa
	lsls r0, r0, #3
	b _08083F84
_08083D3A:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08083D56
	movs r0, #0x64
	strh r0, [r4, #8]
	movs r0, #0x90
	lsls r0, r0, #2
	bl m4aSongNumStart
	b _08083D62
_08083D56:
	cmp r0, #0xa
	bne _08083D62
	adds r0, r4, #0
	movs r1, #0
	bl sub_8083A44
_08083D62:
	adds r0, r4, #0
	movs r1, #0
	bl sub_8082E2C
	b _08083F86
_08083D6C:
	adds r0, r4, #0
	adds r0, #0xd0
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r0, [r0]
	ldr r1, [r2]
	cmp r0, r1
	ble _08083D8A
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r1, r0
	str r0, [r2]
	b _08083F60
_08083D8A:
	movs r0, #0x3c
	strh r0, [r4, #4]
	movs r0, #0x14
	b _08083F5E
_08083D92:
	adds r0, r4, #0
	movs r1, #1
	bl sub_8082E2C
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08083DAC
	movs r0, #0xc8
	b _08083F84
_08083DAC:
	cmp r0, #0xa
	beq _08083DB2
	b _08083F86
_08083DB2:
	adds r0, r4, #0
	movs r1, #1
	bl sub_8083A44
	b _08083F86
_08083DBC:
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #8]
	ldrb r0, [r4]
	cmp r0, #2
	bls _08083DD0
	movs r0, #0x78
	strh r0, [r4, #4]
	movs r0, #0
	b _08083DFA
_08083DD0:
	adds r0, r4, #0
	adds r0, #0xce
	ldrh r1, [r0]
	ldr r0, _08083DE4 @ =0x000001FF
	cmp r1, r0
	bhi _08083DE8
	adds r1, r4, #0
	adds r1, #0xe4
	movs r0, #1
	b _08083DEE
	.align 2, 0
_08083DE4: .4byte 0x000001FF
_08083DE8:
	adds r1, r4, #0
	adds r1, #0xe4
	movs r0, #0
_08083DEE:
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	movs r1, #0
	str r1, [r0]
	movs r0, #1
_08083DFA:
	strb r0, [r4, #2]
	ldr r0, _08083E14 @ =0x00000241
	bl m4aSongNumStart
	movs r0, #0
	bl sub_80870E4
	adds r0, r4, #0
	movs r1, #2
	bl sub_8082E2C
	b _08083F86
	.align 2, 0
_08083E14: .4byte 0x00000241
_08083E18:
	ldr r2, _08083EA4 @ =gDispCnt
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #6
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08083EA8 @ =gWinRegs
	movs r0, #0xa0
	strh r0, [r1]
	movs r0, #0xf0
	strh r0, [r1, #4]
	movs r0, #0x3f
	strh r0, [r1, #8]
	movs r0, #0x18
	strh r0, [r1, #0xa]
	ldr r1, _08083EAC @ =gBldRegs
	ldr r0, _08083EB0 @ =0x00003FBF
	strh r0, [r1]
	movs r0, #8
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r3, [r4, #8]
_08083E46:
	adds r0, r4, #0
	movs r1, #2
	bl sub_8082E2C
	adds r0, r4, #0
	adds r0, #0xe3
	ldrb r0, [r0]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #3
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r3, _08083EB4 @ =gCamera
	ldr r1, [r3]
	subs r0, r0, r1
	movs r5, #0x88
	lsls r5, r5, #1
	adds r1, r4, r5
	adds r1, r1, r2
	ldr r1, [r1]
	asrs r1, r1, #8
	ldr r2, [r3, #4]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r5, r4, #0
	adds r5, #0xce
	ldrh r2, [r5]
	bl sub_808587C
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _08083EB8
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08083EF2
	b _08083EEC
	.align 2, 0
_08083EA4: .4byte gDispCnt
_08083EA8: .4byte gWinRegs
_08083EAC: .4byte gBldRegs
_08083EB0: .4byte 0x00003FBF
_08083EB4: .4byte gCamera
_08083EB8:
	adds r0, r4, #0
	adds r0, #0xe4
	ldr r0, [r0]
	cmp r0, #0
	beq _08083ED0
	ldrh r0, [r5]
	adds r0, #8
	ldr r2, _08083ECC @ =0x000003FF
	adds r1, r2, #0
	b _08083ED8
	.align 2, 0
_08083ECC: .4byte 0x000003FF
_08083ED0:
	ldrh r0, [r5]
	subs r0, #8
	ldr r3, _08083EFC @ =0x000003FF
	adds r1, r3, #0
_08083ED8:
	ands r0, r1
	strh r0, [r5]
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	adds r1, #8
	str r1, [r0]
	ldr r0, _08083F00 @ =0x000005FF
	cmp r1, r0
	ble _08083EF2
_08083EEC:
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r4, #8]
_08083EF2:
	adds r0, r4, #0
	bl sub_808717C
	b _08083F86
	.align 2, 0
_08083EFC: .4byte 0x000003FF
_08083F00: .4byte 0x000005FF
_08083F04:
	ldr r2, _08083F30 @ =gDispCnt
	ldrh r1, [r2]
	ldr r0, _08083F34 @ =0x0000DFFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08083F38 @ =gWinRegs
	movs r1, #0
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	ldr r0, _08083F3C @ =gBldRegs
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	ldr r2, _08083F40 @ =gFlags
	ldr r0, [r2]
	subs r1, #5
	ands r0, r1
	str r0, [r2]
	movs r0, #0xfa
	lsls r0, r0, #1
	b _08083F5E
	.align 2, 0
_08083F30: .4byte gDispCnt
_08083F34: .4byte 0x0000DFFF
_08083F38: .4byte gWinRegs
_08083F3C: .4byte gBldRegs
_08083F40: .4byte gFlags
_08083F44:
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r2]
	cmp r1, #0
	beq _08083F5C
	movs r5, #0xa2
	lsls r5, r5, #1
	adds r0, r4, r5
	ldr r0, [r0]
	subs r0, r1, r0
	str r0, [r2]
	b _08083F60
_08083F5C:
	ldr r0, _08083F6C @ =0x000003F2
_08083F5E:
	strh r0, [r4, #8]
_08083F60:
	adds r0, r4, #0
	movs r1, #1
	bl sub_8082E2C
	b _08083F86
	.align 2, 0
_08083F6C: .4byte 0x000003F2
_08083F70:
	movs r0, #0
	strb r0, [r4, #1]
	b _08083F86
_08083F76:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08083F86
_08083F84:
	strh r0, [r4, #8]
_08083F86:
	pop {r4, r5}
	pop {r0}
	bx r0

.syntax divided
