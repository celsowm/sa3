.syntax unified
.text
	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080854FE
	adds r0, #0x5a
	ldrh r0, [r0]
	strh r0, [r4, #0x10]
	movs r0, #0x32
	adds r1, r4, #0
	adds r1, #0xef
	strb r0, [r1]
	movs r0, #0xa
	strh r0, [r4, #0x12]
	movs r0, #0x91
	lsls r0, r0, #2
	bl m4aSongNumStart
	ldr r1, _080854F0 @ =gStageData
	ldrb r0, [r1, #3]
	cmp r0, #5
	bne _08085580
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _080854F4
	movs r0, #5
	b _080854F6
	.align 2, 0
_080854F0: .4byte gStageData
_080854F4:
	movs r0, #6
_080854F6:
	movs r1, #0
	bl sub_8027674
	b _08085580
_080854FE:
	movs r0, #0x78
	strh r0, [r4, #0x14]
	ldr r0, _08085548 @ =0x00000502
	movs r1, #0
	movs r2, #0x78
	movs r3, #0
	bl sub_8078DB0
	movs r0, #0x64
	strh r0, [r4, #0x12]
	movs r0, #0xeb
	bl m4aSongNumStart
	ldrb r0, [r4]
	cmp r0, #0
	beq _08085528
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08085530
_08085528:
	adds r0, r4, #0
	movs r1, #0
	bl sub_80851FC
_08085530:
	ldr r0, _0808554C @ =gStageData
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _08085550
	ldrb r0, [r4]
	cmp r0, #6
	bne _0808555C
	movs r0, #0x39
	bl sub_80299D4
	b _0808555C
	.align 2, 0
_08085548: .4byte 0x00000502
_0808554C: .4byte gStageData
_08085550:
	ldrb r0, [r4]
	cmp r0, #5
	bne _0808555C
	movs r0, #0x39
	bl sub_80299D4
_0808555C:
	ldr r1, _08085574 @ =gStageData
	ldrb r0, [r1, #3]
	cmp r0, #5
	bne _08085580
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _08085578
	ldrb r1, [r4]
	movs r0, #3
	bl sub_8027674
	b _08085580
	.align 2, 0
_08085574: .4byte gStageData
_08085578:
	ldrb r1, [r4]
	movs r0, #4
	bl sub_8027674
_08085580:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
