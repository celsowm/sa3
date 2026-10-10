.syntax unified
.text
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x78
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	movs r1, #0
	bl sub_807BE58
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, _0807F494 @ =gUnknown_080D5C38
	ldrh r0, [r1, #8]
	strh r0, [r2, #0xc]
	ldrh r0, [r1, #0xa]
	strb r0, [r2, #0x1a]
	ldr r0, _0807F498 @ =0x000004F4
	movs r1, #0x14
	ldrsh r2, [r4, r1]
	movs r1, #0
	movs r3, #0
	bl sub_8078DB0
	ldr r0, _0807F49C @ =0x000004F5
	movs r1, #0x14
	ldrsh r2, [r4, r1]
	movs r1, #0
	movs r3, #0
	bl sub_8078DB0
	ldrb r0, [r4]
	subs r1, r0, #1
	strb r1, [r4]
	movs r0, #1
	strh r0, [r4, #0x16]
	ldr r0, _0807F4A0 @ =gStageData
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _0807F4A4
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _0807F4B2
	movs r0, #0x37
	bl sub_80299D4
	b _0807F4B2
	.align 2, 0
_0807F494: .4byte gUnknown_080D5C38
_0807F498: .4byte 0x000004F4
_0807F49C: .4byte 0x000004F5
_0807F4A0: .4byte gStageData
_0807F4A4:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0807F4B2
	movs r0, #0x37
	bl sub_80299D4
_0807F4B2:
	movs r0, #0xeb
	bl m4aSongNumStart
	bl PlayVoiceEggmanHit
	ldr r1, _0807F4DC @ =gStageData
	ldrb r0, [r1, #3]
	cmp r0, #5
	bne _0807F4E8
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _0807F4E0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0807F4E8
	adds r1, r0, #0
	movs r0, #3
	bl sub_8027674
	b _0807F4E8
	.align 2, 0
_0807F4DC: .4byte gStageData
_0807F4E0:
	ldrb r1, [r4]
	movs r0, #4
	bl sub_8027674
_0807F4E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
