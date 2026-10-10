.syntax unified
.text
	push {r4, r5, r6, lr}
	ldr r0, _0807FEA8 @ =gCurTask
	ldr r0, [r0]
	ldrh r5, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r5, r0
	ldr r6, _0807FEAC @ =gPlayers
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1e
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #2
	adds r4, r4, r0
	lsls r4, r4, #4
	adds r4, r4, r6
	movs r0, #0
	strh r0, [r5, #0x16]
	strh r0, [r5, #0x14]
	ldr r1, _0807FEB0 @ =gUnknown_08E2ED48
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldrh r1, [r6, #0x1e]
	ldrh r0, [r5, #0x14]
	strh r0, [r6, #0x1e]
	eors r1, r0
	ands r1, r0
	strh r1, [r6, #0x20]
	ldrh r1, [r4, #0x1e]
	ldrh r0, [r5, #0x16]
	strh r0, [r4, #0x1e]
	eors r1, r0
	ands r1, r0
	strh r1, [r4, #0x20]
	adds r0, r5, #0
	bl sub_8080548
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807FEA8: .4byte gCurTask
_0807FEAC: .4byte gPlayers
_0807FEB0: .4byte gUnknown_08E2ED48

.syntax divided
