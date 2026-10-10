.syntax unified
.text
	push {lr}
	ldr r1, _0802879C @ =gMultiSioEnabled
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080287A0 @ =gFlags
	ldr r0, [r2]
	ldr r1, _080287A4 @ =0xFFFFBFFF
	ands r0, r1
	str r0, [r2]
	ldr r1, _080287A8 @ =gTilemapsRef
	ldr r0, _080287AC @ =gUnknown_02035000
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080287B0 @ =gRefSpriteTables
	ldr r0, _080287B4 @ =0x02022000
	str r0, [r1]
	bl sub_8025D58
	bl sub_80287B8
	pop {r0}
	bx r0
	.align 2, 0
_0802879C: .4byte gMultiSioEnabled
_080287A0: .4byte gFlags
_080287A4: .4byte 0xFFFFBFFF
_080287A8: .4byte gTilemapsRef
_080287AC: .4byte gUnknown_02035000
_080287B0: .4byte gRefSpriteTables
_080287B4: .4byte 0x02022000

.syntax divided
