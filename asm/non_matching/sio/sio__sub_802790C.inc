.syntax unified
.text
	push {lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08027940 @ =gPlayers
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r2, r0, r2
	adds r0, r2, #0
	adds r0, #0x69
	strb r3, [r0]
	ldr r0, _08027944 @ =gStageData
	adds r0, #0x8f
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xf0
	ands r0, r3
	cmp r0, #0x10
	beq _08027948
	cmp r0, #0x20
	beq _08027954
	b _0802795C
	.align 2, 0
_08027940: .4byte gPlayers
_08027944: .4byte gStageData
_08027948:
	adds r1, r2, #0
	adds r1, #0x66
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	b _0802795C
_08027954:
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	bl sub_80296F8
_0802795C:
	pop {r0}
	bx r0

.syntax divided
