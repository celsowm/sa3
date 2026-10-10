.syntax unified
.text
	push {r4, lr}
	ldr r0, _08027D80 @ =gCurTask
	ldr r0, [r0]
	ldrh r4, [r0, #6]
	bl MultiSioStop
	ldr r2, _08027D84 @ =0x04000208
	movs r0, #0
	strh r0, [r2]
	ldr r1, _08027D88 @ =gIntrTable
	ldr r0, _08027D8C @ =Sio32MultiLoadIntr
	str r0, [r1]
	movs r0, #1
	strh r0, [r2]
	ldr r0, _08027D90 @ =0x030000DE
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #4
	bne _08027DBC
	ldr r0, _08027D94 @ =gLoadedSaveGame
	ldr r1, _08027D98 @ =0x00000366
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027DA4
	ldr r0, _08027D9C @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	ldr r1, _08027DA0 @ =gUnknown_08E5F6B0
	bl Sio32MultiLoadInit
	b _08027DD2
	.align 2, 0
_08027D80: .4byte gCurTask
_08027D84: .4byte 0x04000208
_08027D88: .4byte gIntrTable
_08027D8C: .4byte Sio32MultiLoadIntr
_08027D90: .4byte 0x030000DE
_08027D94: .4byte gLoadedSaveGame
_08027D98: .4byte 0x00000366
_08027D9C: .4byte gMultiSioStatusFlags
_08027DA0: .4byte gUnknown_08E5F6B0
_08027DA4:
	ldr r0, _08027DB4 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	ldr r1, _08027DB8 @ =gUnknown_08E5C244
	bl Sio32MultiLoadInit
	b _08027DD2
	.align 2, 0
_08027DB4: .4byte gMultiSioStatusFlags
_08027DB8: .4byte gUnknown_08E5C244
_08027DBC:
	ldr r0, _08027DE4 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	ldr r2, _08027DE8 @ =gUnknown_080CEF08
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl Sio32MultiLoadInit
_08027DD2:
	ldr r0, _08027DEC @ =gCurTask
	ldr r1, [r0]
	ldr r0, _08027DF0 @ =sa2__sub_8081A5C
	str r0, [r1, #8]
	bl sub_8028338
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027DE4: .4byte gMultiSioStatusFlags
_08027DE8: .4byte gUnknown_080CEF08
_08027DEC: .4byte gCurTask
_08027DF0: .4byte sa2__sub_8081A5C

.syntax divided
