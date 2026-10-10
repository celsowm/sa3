.syntax unified
.text
	push {r4, lr}
	ldr r1, _08025440 @ =gStageData
	ldr r0, _08025444 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802545A
	bl sub_8025D00
	ldr r0, _08025448 @ =gMultiSioStatusFlags
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08025458
	ldr r4, _0802544C @ =gMultiSioRecv
	ldr r1, _08025450 @ =0xFFFF99F5
	adds r0, r1, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08025458
	ldr r3, _08025454 @ =gUnknown_03001060
	ldrb r0, [r4, #0xf]
	adds r2, r3, #0
	adds r2, #0x4c
	strb r0, [r2]
	ldrb r0, [r4, #0x10]
	adds r1, r3, #0
	adds r1, #0x4d
	strb r0, [r1]
	ldrb r0, [r4, #0x11]
	adds r1, #1
	strb r0, [r1]
	ldrb r1, [r4, #0x12]
	adds r0, r3, #0
	adds r0, #0x4f
	strb r1, [r0]
	movs r1, #0
_0802542A:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08025458
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _0802542A
	movs r0, #1
	b _0802545A
	.align 2, 0
_08025440: .4byte gStageData
_08025444: .4byte 0x04000128
_08025448: .4byte gMultiSioStatusFlags
_0802544C: .4byte gMultiSioRecv
_08025450: .4byte 0xFFFF99F5
_08025454: .4byte gUnknown_03001060
_08025458:
	movs r0, #0
_0802545A:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
