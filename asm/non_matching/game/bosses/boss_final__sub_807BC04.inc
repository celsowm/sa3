.syntax unified
.text
	push {r4, r5, lr}
	ldr r0, _0807BC84 @ =gCurTask
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r4, r0
	ldr r1, _0807BC88 @ =gUnknown_08E2ED00
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl sub_807ED8C
	adds r0, r4, #0
	bl sub_807BD88
	adds r0, r4, #0
	bl sub_807DB60
	adds r0, r4, #0
	bl sub_807D81C
	adds r0, r4, #0
	bl sub_807BFEC
	adds r0, r4, #0
	bl sub_807C14C
	adds r0, r4, #0
	bl sub_80816C0
	ldr r0, _0807BC8C @ =gStageData
	ldrb r1, [r0, #6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _0807BC90 @ =gPlayers
	adds r4, r0, r1
	ldr r0, [r4, #0x14]
	asrs r0, r0, #8
	cmp r0, #0xd9
	ble _0807BCBA
	ldr r0, [r4, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0807BC98
	movs r0, #0xa0
	bl sub_807FB7C
	ldr r1, _0807BC94 @ =Player_HitWithoutRingsUpdate
	adds r0, r4, #0
	bl SetPlayerCallback
	b _0807BCBA
	.align 2, 0
_0807BC84: .4byte gCurTask
_0807BC88: .4byte gUnknown_08E2ED00
_0807BC8C: .4byte gStageData
_0807BC90: .4byte gPlayers
_0807BC94: .4byte Player_HitWithoutRingsUpdate
_0807BC98:
	ldr r1, [r4]
	ldr r5, _0807BCC0 @ =Player_HitWithoutRingsUpdate
	cmp r1, r5
	beq _0807BCBA
	ldr r0, _0807BCC4 @ =Player_800913C
	cmp r1, r0
	beq _0807BCBA
	ldr r0, _0807BCC8 @ =Player_800DF9C
	cmp r1, r0
	beq _0807BCBA
	movs r0, #0xa0
	bl sub_807FB7C
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetPlayerCallback
_0807BCBA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BCC0: .4byte Player_HitWithoutRingsUpdate
_0807BCC4: .4byte Player_800913C
_0807BCC8: .4byte Player_800DF9C

.syntax divided
