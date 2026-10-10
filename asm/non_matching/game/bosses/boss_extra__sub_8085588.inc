.syntax unified
.text
	push {r4, lr}
	ldr r1, _080855B8 @ =gStageData
	adds r1, #0x88
	ldr r1, [r1]
	ldrh r2, [r1, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r4, r2, r1
	ldrb r2, [r0, #2]
	movs r1, #0x7f
	ands r1, r2
	ldrb r2, [r0, #3]
	ldrb r0, [r0, #4]
	lsls r0, r0, #8
	orrs r2, r0
	subs r0, r1, #1
	cmp r0, #5
	bhi _08085610
	lsls r0, r0, #2
	ldr r1, _080855BC @ =_080855C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080855B8: .4byte gStageData
_080855BC: .4byte _080855C0
_080855C0: @ jump table
	.4byte _080855D8 @ case 0
	.4byte _08085610 @ case 1
	.4byte _080855EE @ case 2
	.4byte _080855EE @ case 3
	.4byte _08085602 @ case 4
	.4byte _08085602 @ case 5
_080855D8:
	movs r0, #0
	strb r0, [r4]
	adds r0, r4, #0
	bl sub_8085458
	movs r0, #0x78
	strh r0, [r4, #0x10]
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r4, #0x12]
	b _08085610
_080855EE:
	ldrb r1, [r4]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	beq _08085610
	adds r0, r4, #0
	movs r1, #1
	bl sub_80854B8
	b _08085610
_08085602:
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne _08085610
	adds r0, r4, #0
	movs r1, #0
	bl sub_80854B8
_08085610:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
