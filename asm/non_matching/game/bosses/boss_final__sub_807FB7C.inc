.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r4, r3, #0
	ldr r7, _0807FBE0 @ =gPlayers
	movs r0, #0x2b
	adds r0, r0, r7
	mov sb, r0
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r6, r0, r7
	ldr r2, [r7, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0807FBB6
	b _0807FE36
_0807FBB6:
	ldr r5, [r6, #4]
	ands r5, r1
	cmp r5, #0
	beq _0807FBC0
	b _0807FE36
_0807FBC0:
	cmp r3, #0x1e
	bne _0807FBC6
	b _0807FD64
_0807FBC6:
	cmp r3, #0x1e
	bgt _0807FBFC
	cmp r3, #0xa
	beq _0807FCBC
	cmp r3, #0xa
	bgt _0807FBEA
	cmp r3, #1
	beq _0807FC44
	cmp r3, #1
	bgt _0807FBE4
	cmp r3, #0
	beq _0807FC3A
	b _0807FE36
	.align 2, 0
_0807FBE0: .4byte gPlayers
_0807FBE4:
	cmp r3, #2
	beq _0807FCB0
	b _0807FE36
_0807FBEA:
	cmp r3, #0xc
	bne _0807FBF0
	b _0807FE36
_0807FBF0:
	cmp r3, #0xc
	blt _0807FCC8
	cmp r3, #0x14
	bne _0807FBFA
	b _0807FD40
_0807FBFA:
	b _0807FE36
_0807FBFC:
	cmp r3, #0xc8
	bne _0807FC02
	b _0807FDE2
_0807FC02:
	cmp r3, #0xc8
	bgt _0807FC20
	cmp r3, #0x96
	bne _0807FC0C
	b _0807FD88
_0807FC0C:
	cmp r3, #0x96
	bgt _0807FC18
	cmp r3, #0x64
	bne _0807FC16
	b _0807FD78
_0807FC16:
	b _0807FE36
_0807FC18:
	cmp r3, #0xa0
	bne _0807FC1E
	b _0807FDA0
_0807FC1E:
	b _0807FE36
_0807FC20:
	cmp r3, #0xdc
	bne _0807FC26
	b _0807FE0C
_0807FC26:
	cmp r3, #0xdc
	bgt _0807FC32
	cmp r3, #0xd2
	bne _0807FC30
	b _0807FDFC
_0807FC30:
	b _0807FE36
_0807FC32:
	cmp r4, #0xfa
	bne _0807FC38
	b _0807FE24
_0807FC38:
	b _0807FE36
_0807FC3A:
	movs r1, #0x80
	lsls r1, r1, #0x14
	orrs r2, r1
	str r2, [r7, #4]
	b _0807FCA2
_0807FC44:
	ldr r0, _0807FCAC @ =gStageData
	adds r0, #0xac
	strh r5, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	ands r2, r1
	str r2, [r7, #4]
	ldr r0, [r6, #4]
	ands r0, r1
	subs r1, #0xff
	ands r0, r1
	str r0, [r6, #4]
	ldr r0, [r6, #8]
	ands r0, r1
	str r0, [r6, #8]
	strh r5, [r7, #0x1c]
	strh r5, [r7, #0x18]
	strh r5, [r7, #0x1a]
	adds r0, r7, #0
	adds r0, #0x4a
	strh r5, [r0]
	adds r0, r7, #0
	bl Player_8005380
	movs r0, #0xcf
	lsls r0, r0, #0xb
	str r0, [r7, #0x10]
	movs r4, #0xb3
	lsls r4, r4, #8
	str r4, [r7, #0x14]
	strh r5, [r6, #0x1c]
	strh r5, [r6, #0x18]
	strh r5, [r6, #0x1a]
	adds r0, r6, #0
	adds r0, #0x4a
	strh r5, [r0]
	adds r0, r6, #0
	bl Player_8005380
	movs r0, #0xcb
	lsls r0, r0, #0xb
	str r0, [r6, #0x10]
	str r4, [r6, #0x14]
	ldr r0, [r7, #4]
	movs r1, #0x20
	orrs r0, r1
	str r0, [r7, #4]
_0807FCA2:
	ldr r0, [r6, #4]
	orrs r0, r1
	str r0, [r6, #4]
	b _0807FE36
	.align 2, 0
_0807FCAC: .4byte gStageData
_0807FCB0:
	ldr r1, _0807FCB8 @ =0xF7FFFFFF
	ands r2, r1
	str r2, [r7, #4]
	b _0807FD38
	.align 2, 0
_0807FCB8: .4byte 0xF7FFFFFF
_0807FCBC:
	ldr r1, _0807FCC4 @ =gStageData
	movs r0, #9
	strb r0, [r1, #4]
	b _0807FD52
	.align 2, 0
_0807FCC4: .4byte gStageData
_0807FCC8:
	movs r4, #0xc0
	lsls r4, r4, #0x10
	ands r2, r4
	cmp r2, #0
	beq _0807FCE6
	adds r0, r7, #0
	bl sub_8016F28
	adds r2, r7, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0807FCE6:
	ldr r0, [r6, #4]
	ands r0, r4
	cmp r0, #0
	beq _0807FD02
	adds r0, r6, #0
	bl sub_8016F28
	adds r2, r6, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0807FD02:
	ldr r0, [r7, #4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _0807FD12
	adds r0, r7, #0
	bl Player_8005380
_0807FD12:
	ldr r0, [r6, #4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _0807FD28
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #0x1c
	ands r0, r1
	cmp r0, #8
	bne _0807FD2E
_0807FD28:
	adds r0, r6, #0
	bl Player_8005380
_0807FD2E:
	ldr r0, [r7, #4]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #4]
_0807FD38:
	ldr r0, [r6, #4]
	ands r0, r1
	str r0, [r6, #4]
	b _0807FE36
_0807FD40:
	ldr r1, _0807FD5C @ =gStageData
	movs r0, #3
	strb r0, [r1, #4]
	ldr r1, _0807FD60 @ =0xF7FFFFFF
	ands r2, r1
	str r2, [r7, #4]
	ldr r0, [r6, #4]
	ands r0, r1
	str r0, [r6, #4]
_0807FD52:
	strh r5, [r7, #0x1e]
	strh r5, [r7, #0x20]
	strh r5, [r6, #0x1e]
	strh r5, [r6, #0x20]
	b _0807FE36
	.align 2, 0
_0807FD5C: .4byte gStageData
_0807FD60: .4byte 0xF7FFFFFF
_0807FD64:
	adds r2, r6, #0
	adds r2, #0x2a
	ldrb r1, [r2]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2]
	b _0807FE36
_0807FD78:
	ldr r1, _0807FD84 @ =sub_8081810
	adds r0, r7, #0
	bl SetPlayerCallback
	b _0807FE36
	.align 2, 0
_0807FD84: .4byte sub_8081810
_0807FD88:
	bl sub_807C5D0
	ldr r1, [r7]
	ldr r0, _0807FD9C @ =PlayerCB_80819BC
	cmp r1, r0
	bne _0807FE36
	adds r0, r7, #0
	bl Player_8005380
	b _0807FE36
	.align 2, 0
_0807FD9C: .4byte PlayerCB_80819BC
_0807FDA0:
	movs r4, #0xc0
	lsls r4, r4, #0x10
	ands r2, r4
	cmp r2, #0
	beq _0807FDBE
	adds r0, r7, #0
	bl sub_8016F28
	adds r2, r7, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0807FDBE:
	ldr r0, [r6, #4]
	ands r0, r4
	cmp r0, #0
	beq _0807FE36
	adds r0, r6, #0
	bl sub_8016F28
	adds r2, r6, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl Player_8005380
	b _0807FE36
_0807FDE2:
	strh r5, [r6, #0x18]
	strh r5, [r6, #0x1a]
	ldr r4, _0807FDF8 @ =sub_808183C
	adds r0, r6, #0
	adds r1, r4, #0
	bl SetPlayerCallback
	adds r0, r6, #0
	bl _call_via_r4
	b _0807FE36
	.align 2, 0
_0807FDF8: .4byte sub_808183C
_0807FDFC:
	movs r0, #1
	orrs r2, r0
	str r2, [r7, #4]
	ldr r4, _0807FE08 @ =sub_8081840
	b _0807FE0E
	.align 2, 0
_0807FE08: .4byte sub_8081840
_0807FE0C:
	ldr r4, _0807FE20 @ =sub_808186C
_0807FE0E:
	adds r0, r7, #0
	adds r1, r4, #0
	bl SetPlayerCallback
	adds r0, r6, #0
	adds r1, r4, #0
	bl SetPlayerCallback
	b _0807FE36
	.align 2, 0
_0807FE20: .4byte sub_808186C
_0807FE24:
	ldr r4, _0807FE44 @ =Player_8005380
	adds r0, r7, #0
	adds r1, r4, #0
	bl SetPlayerCallback
	adds r0, r6, #0
	adds r1, r4, #0
	bl SetPlayerCallback
_0807FE36:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FE44: .4byte Player_8005380

.syntax divided
