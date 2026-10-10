.syntax unified
.text
	push {r4, r5, lr}
	ldr r3, _08026748 @ =gStageData
	ldrb r2, [r3, #6]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	ldr r1, _0802674C @ =gPlayers
	adds r5, r0, r1
	ldr r4, _08026750 @ =gMultiSioSend
	adds r0, r3, #0
	adds r0, #0xb9
	ldrb r1, [r0]
	movs r0, #1
	lsls r0, r2
	cmp r1, r0
	bne _08026758
	ldr r0, _08026754 @ =0x000068D0
	b _0802675A
	.align 2, 0
_08026748: .4byte gStageData
_0802674C: .4byte gPlayers
_08026750: .4byte gMultiSioSend
_08026754: .4byte 0x000068D0
_08026758:
	ldr r0, _080267D4 @ =0x000068D1
_0802675A:
	strh r0, [r4]
	ldr r0, [r3, #0x1c]
	strh r0, [r4, #2]
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	strh r0, [r4, #4]
	ldr r0, [r5, #0x14]
	asrs r0, r0, #8
	strh r0, [r4, #6]
	ldr r0, [r5, #4]
	str r0, [r4, #8]
	ldrh r0, [r5, #0x34]
	ldr r1, _080267D8 @ =0x000007FF
	ands r1, r0
	ldrh r2, [r4, #0xc]
	ldr r0, _080267DC @ =0xFFFFF800
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #0xc]
	ldrh r1, [r5, #0x36]
	lsls r1, r1, #3
	ldrb r2, [r4, #0xd]
	movs r0, #7
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #0xd]
	adds r0, r3, #0
	adds r0, #0xac
	ldrh r0, [r0]
	ldr r1, _080267E0 @ =0x000003FF
	ands r1, r0
	ldrh r2, [r4, #0xe]
	ldr r0, _080267E4 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #0xf]
	movs r0, #0x7d
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #0xf]
	adds r0, r3, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	strb r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	strb r0, [r4, #0x11]
	ldrb r0, [r4, #0x12]
	cmp r0, #0xff
	bne _080267CE
	adds r0, r3, #0
	adds r0, #0xae
	ldrh r0, [r0]
	strb r0, [r4, #0x13]
	lsrs r0, r0, #8
	strb r0, [r4, #0x14]
_080267CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080267D4: .4byte 0x000068D1
_080267D8: .4byte 0x000007FF
_080267DC: .4byte 0xFFFFF800
_080267E0: .4byte 0x000003FF
_080267E4: .4byte 0xFFFFFC00

.syntax divided
