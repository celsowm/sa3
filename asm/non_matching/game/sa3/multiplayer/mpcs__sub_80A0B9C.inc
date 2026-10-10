.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r0, _080A0BC8 @ =gCurTask
	ldr r2, [r0]
	ldrh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r1, _080A0BCC @ =gUnknown_080D8F18
	ldrb r0, [r4, #2]
	adds r0, r0, r1
	ldrb r5, [r0]
	ldrb r0, [r4, #1]
	adds r0, r0, r1
	ldrb r6, [r0]
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080A0BD4
	ldr r0, _080A0BD0 @ =Task_80A14AC
	str r0, [r2, #8]
	b _080A0C44
	.align 2, 0
_080A0BC8: .4byte gCurTask
_080A0BCC: .4byte gUnknown_080D8F18
_080A0BD0: .4byte Task_80A14AC
_080A0BD4:
	adds r0, r4, #0
	bl sub_80A19C0
	adds r0, r4, #0
	bl sub_80A10B0
	adds r0, r4, #0
	bl sub_80A124C
	ldrh r0, [r4, #4]
	cmp r0, #0
	bne _080A0C08
	ldr r1, _080A0C00 @ =gAnnouncerSelect1st
	ldr r0, _080A0C04 @ =gCharacterSelectOrderLUT
	adds r0, r5, r0
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl m4aSongNumStart
	b _080A0C2E
	.align 2, 0
_080A0C00: .4byte gAnnouncerSelect1st
_080A0C04: .4byte gCharacterSelectOrderLUT
_080A0C08:
	cmp r0, #0x3c
	bne _080A0C18
	ldr r0, _080A0C14 @ =0x000001FF @ VOICE__ANNOUNCER__AND
	bl m4aSongNumStart
	b _080A0C2E
	.align 2, 0
_080A0C14: .4byte 0x000001FF
_080A0C18:
	cmp r0, #0x5a
	bne _080A0C2E
	ldr r1, _080A0C4C @ =gAnnouncerSelect2nd
	ldr r0, _080A0C50 @ =gCharacterSelectOrderLUT
	adds r0, r6, r0
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl m4aSongNumStart
_080A0C2E:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080A0C44
	ldr r0, _080A0C54 @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080A0C58 @ =sub_80A0C5C
	str r0, [r1, #8]
_080A0C44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A0C4C: .4byte gAnnouncerSelect2nd
_080A0C50: .4byte gCharacterSelectOrderLUT
_080A0C54: .4byte gCurTask
_080A0C58: .4byte sub_80A0C5C

.syntax divided
