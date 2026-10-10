.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _0807F538 @ =gStageData
	adds r1, r5, #0
	adds r1, #0x88
	ldr r1, [r1]
	ldrh r4, [r1, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r3, r4, r1
	ldrb r2, [r0, #2]
	movs r1, #0x7f
	ands r1, r2
	ldrb r2, [r0, #3]
	ldrb r0, [r0, #4]
	lsls r0, r0, #8
	orrs r2, r0
	adds r0, r2, #0
	cmp r1, #1
	bne _0807F544
	movs r0, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xae
	strh r2, [r0]
	movs r0, #0x3c
	strh r0, [r3, #0x14]
	ldr r0, _0807F53C @ =0x03000228
	adds r2, r4, r0
	ldr r1, _0807F540 @ =gUnknown_080D5C38
	ldrh r0, [r1]
	strh r0, [r2, #0xc]
	ldrh r0, [r1, #2]
	strb r0, [r2, #0x1a]
	movs r0, #0x64
	strh r0, [r3, #0x16]
	b _0807F560
	.align 2, 0
_0807F538: .4byte gStageData
_0807F53C: .4byte 0x03000228
_0807F540: .4byte gUnknown_080D5C38
_0807F544:
	cmp r1, #1
	blt _0807F560
	cmp r1, #4
	bgt _0807F560
	cmp r1, #3
	blt _0807F560
	ldrb r1, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	beq _0807F560
	adds r0, r3, #0
	bl sub_807F434
_0807F560:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
