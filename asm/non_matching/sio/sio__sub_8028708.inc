.syntax unified
.text
	push {lr}
	ldr r1, _08028748 @ =gTilemapsRef
	ldr r0, _0802874C @ =gUnknown_080D1C0C
	str r0, [r1]
	ldr r1, _08028750 @ =gRefSpriteTables
	ldr r0, _08028754 @ =gSpriteTables
	str r0, [r1]
	ldr r1, _08028758 @ =gMultiSioEnabled
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0802875C @ =gFlags
	ldr r0, [r2]
	ldr r1, _08028760 @ =0xFFFFBFFF
	ands r0, r1
	str r0, [r2]
	bl m4aSoundVSyncOn
	bl sub_8028688
	ldr r1, _08028764 @ =gStageData
	ldr r0, _08028768 @ =gLoadedSaveGame
	ldr r2, _0802876C @ =0x00000366
	adds r0, r0, r2
	ldrb r0, [r0]
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	strb r0, [r1]
	bl sub_80287B8
	pop {r0}
	bx r0
	.align 2, 0
_08028748: .4byte gTilemapsRef
_0802874C: .4byte gUnknown_080D1C0C
_08028750: .4byte gRefSpriteTables
_08028754: .4byte gSpriteTables
_08028758: .4byte gMultiSioEnabled
_0802875C: .4byte gFlags
_08028760: .4byte 0xFFFFBFFF
_08028764: .4byte gStageData
_08028768: .4byte gLoadedSaveGame
_0802876C: .4byte 0x00000366

.syntax divided
