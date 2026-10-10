.syntax unified
.text
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, _0807FEEC @ =gPlayers
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1e
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r2, r0, r3
	ldrh r1, [r4, #0x12]
	cmp r1, #0xc8
	bne _0807FED8
	b _08080076
_0807FED8:
	cmp r1, #0xc8
	bgt _0807FEFC
	cmp r1, #0xa
	beq _0807FF2E
	cmp r1, #0xa
	bgt _0807FEF0
	cmp r1, #0
	beq _0807FF24
	b _08080076
	.align 2, 0
_0807FEEC: .4byte gPlayers
_0807FEF0:
	cmp r1, #0x64
	beq _0807FF44
	cmp r1, #0x82
	bne _0807FEFA
	b _08080054
_0807FEFA:
	b _08080076
_0807FEFC:
	movs r5, #0x9b
	lsls r5, r5, #1
	cmp r1, r5
	beq _0807FFB0
	cmp r1, r5
	bgt _0807FF12
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807FF70
	b _08080076
_0807FF12:
	movs r0, #0xa0
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807FFEC
	adds r0, #0xa
	cmp r1, r0
	bne _0807FF22
	b _0808001C
_0807FF22:
	b _08080076
_0807FF24:
	movs r0, #0xb9
	lsls r0, r0, #1
	strh r0, [r4, #0x10]
	movs r0, #0xa
	b _08080074
_0807FF2E:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807FF3C
	b _08080076
_0807FF3C:
	movs r0, #0xb4
	strh r0, [r4, #0x10]
	movs r0, #0x64
	b _08080074
_0807FF44:
	ldrh r0, [r4, #0x14]
	movs r3, #0x10
	movs r2, #0
	orrs r0, r3
	strh r0, [r4, #0x14]
	ldrh r1, [r4, #0x10]
	movs r5, #0x10
	ldrsh r0, [r4, r5]
	cmp r0, #0x95
	bgt _0807FF5E
	ldrh r0, [r4, #0x16]
	orrs r0, r3
	strh r0, [r4, #0x16]
_0807FF5E:
	subs r0, r1, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807FF6A
	b _08080076
_0807FF6A:
	movs r0, #0x96
	lsls r0, r0, #1
	b _08080074
_0807FF70:
	ldr r0, [r3, #0x10]
	asrs r2, r0, #8
	ldr r0, _0807FFA8 @ =0x00000898
	cmp r2, r0
	ble _0807FF82
	ldrh r1, [r4, #0x14]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r4, #0x14]
_0807FF82:
	ldr r0, _0807FFAC @ =0x000008CB
	cmp r2, r0
	ble _08080076
	ldr r0, [r3, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08080076
	movs r1, #0
	movs r0, #0x3c
	strh r0, [r4, #0x10]
	strh r1, [r3, #0x1c]
	strh r1, [r3, #0x18]
	strh r1, [r3, #0x1a]
	adds r0, r3, #0
	bl Player_8005380
	strh r5, [r4, #0x12]
	b _08080076
	.align 2, 0
_0807FFA8: .4byte 0x00000898
_0807FFAC: .4byte 0x000008CB
_0807FFB0:
	ldrh r0, [r4, #0x10]
	subs r0, #1
	movs r3, #0
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807FFC8
	movs r0, #0x14
	strh r0, [r4, #0x10]
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r4, #0x12]
_0807FFC8:
	ldr r0, [r2, #0x10]
	asrs r0, r0, #8
	ldr r1, _0807FFE8 @ =0x00000897
	cmp r0, r1
	ble _08080076
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08080076
	strh r3, [r2, #0x1c]
	strh r3, [r2, #0x18]
	strh r3, [r2, #0x1a]
	adds r0, r2, #0
	bl Player_8005380
	b _08080076
	.align 2, 0
_0807FFE8: .4byte 0x00000897
_0807FFEC:
	ldrh r1, [r4, #0x14]
	movs r0, #0x10
	adds r2, r0, #0
	orrs r2, r1
	strh r2, [r4, #0x14]
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08080076
	ldr r0, [r3, #0xc]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r3, #0xc]
	ldr r0, _08080018 @ =gStageData
	ldrh r0, [r0, #0x14]
	orrs r2, r0
	strh r2, [r4, #0x14]
	movs r0, #0xa5
	lsls r0, r0, #1
	b _08080074
	.align 2, 0
_08080018: .4byte gStageData
_0808001C:
	ldrh r1, [r4, #0x14]
	movs r0, #0x10
	orrs r0, r1
	ldr r1, _0808004C @ =gStageData
	ldrh r1, [r1, #0x14]
	orrs r0, r1
	strh r0, [r4, #0x14]
	ldr r0, [r3, #0x10]
	asrs r0, r0, #8
	ldr r1, _08080050 @ =0x0000090F
	cmp r0, r1
	ble _08080076
	movs r5, #0x18
	ldrsh r0, [r3, r5]
	rsbs r0, r0, #0
	strh r0, [r3, #0x18]
	movs r0, #0
	strh r0, [r3, #0x1a]
	adds r0, r3, #0
	bl sub_80044CC
	movs r0, #0x82
	b _08080074
	.align 2, 0
_0808004C: .4byte gStageData
_08080050: .4byte 0x0000090F
_08080054:
	ldr r0, [r3, #0x14]
	asrs r0, r0, #8
	cmp r0, #0xb0
	ble _08080076
	movs r1, #0x1a
	ldrsh r0, [r3, r1]
	cmp r0, #0
	ble _08080076
	movs r0, #0
	strh r0, [r3, #0x1c]
	strh r0, [r3, #0x18]
	strh r0, [r3, #0x1a]
	adds r0, r3, #0
	bl Player_8005380
	movs r0, #0xc8
_08080074:
	strh r0, [r4, #0x12]
_08080076:
	pop {r4, r5}
	pop {r0}
	bx r0

.syntax divided
