.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	ldr r1, _0807C6AC @ =gUnknown_080D5CA0
	mov r0, sp
	movs r2, #4
	bl memcpy
	ldr r2, _0807C6B0 @ =gPseudoRandom
	ldr r1, [r2]
	ldr r0, _0807C6B4 @ =0x00196225
	muls r0, r1, r0
	ldr r1, _0807C6B8 @ =0x3C6EF35F
	adds r0, r0, r1
	str r0, [r2]
	adds r2, r0, #0
	ldr r1, _0807C6BC @ =0x00002710
	bl __umodsi3
	adds r2, r0, #0
	ldr r0, _0807C6C0 @ =gStageData
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _0807C6C4
	ldrb r0, [r4]
	cmp r0, #4
	bhi _0807C6CC
	b _0807C6E4
	.align 2, 0
_0807C6AC: .4byte gUnknown_080D5CA0
_0807C6B0: .4byte gPseudoRandom
_0807C6B4: .4byte 0x00196225
_0807C6B8: .4byte 0x3C6EF35F
_0807C6BC: .4byte 0x00002710
_0807C6C0: .4byte gStageData
_0807C6C4:
	ldrb r0, [r4]
	cmp r0, #3
	bhi _0807C6CC
	movs r5, #1
_0807C6CC:
	cmp r5, #0
	bne _0807C6E4
	ldrb r0, [r4, #0x12]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r4, #1]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r4, #0x12]
	b _0807C718
_0807C6E4:
	ldr r0, _0807C6F0 @ =0x000009C3
	cmp r2, r0
	bhi _0807C6F4
	movs r0, #1
	b _0807C716
	.align 2, 0
_0807C6F0: .4byte 0x000009C3
_0807C6F4:
	ldr r0, _0807C700 @ =0x00001387
	cmp r2, r0
	bhi _0807C704
	movs r0, #2
	b _0807C716
	.align 2, 0
_0807C700: .4byte 0x00001387
_0807C704:
	ldr r0, _0807C710 @ =0x00001D4B
	cmp r2, r0
	bhi _0807C714
	movs r0, #3
	b _0807C716
	.align 2, 0
_0807C710: .4byte 0x00001D4B
_0807C714:
	movs r0, #4
_0807C716:
	strb r0, [r4, #1]
_0807C718:
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #8]
	strh r1, [r4, #0xc]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

.syntax divided
