.syntax unified
.text
	push {lr}
	adds r1, r0, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r1, r0
	adds r3, r1, #0
	adds r3, #0xef
	ldrb r0, [r3]
	cmp r0, #0x34
	beq _080824EA
	cmp r0, #0x34
	bgt _0808244A
	cmp r0, #0x32
	beq _08082462
	cmp r0, #0x32
	bgt _08082478
	b _080824EA
_0808244A:
	cmp r0, #0x65
	beq _080824A8
	cmp r0, #0x65
	bgt _08082458
	cmp r0, #0x64
	beq _08082494
	b _080824EA
_08082458:
	cmp r0, #0x66
	beq _080824C4
	cmp r0, #0x96
	beq _080824C8
	b _080824EA
_08082462:
	adds r1, #0xf0
	movs r0, #6
	strh r0, [r1]
	ldr r0, _08082474 @ =0x000004FD
	strh r0, [r2, #0xc]
	movs r0, #1
	strb r0, [r2, #0x1a]
	b _080824E4
	.align 2, 0
_08082474: .4byte 0x000004FD
_08082478:
	adds r1, #0xf0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080824EA
	ldr r0, _08082490 @ =0x000004FD
	strh r0, [r2, #0xc]
	movs r0, #2
	strb r0, [r2, #0x1a]
	b _080824E4
	.align 2, 0
_08082490: .4byte 0x000004FD
_08082494:
	adds r1, #0xf0
	movs r0, #6
	strh r0, [r1]
	ldr r0, _080824A4 @ =0x000004FD
	strh r0, [r2, #0xc]
	movs r0, #1
	strb r0, [r2, #0x1a]
	b _080824E4
	.align 2, 0
_080824A4: .4byte 0x000004FD
_080824A8:
	adds r1, #0xf0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080824EA
	ldr r0, _080824C0 @ =0x000004FD
	strh r0, [r2, #0xc]
	movs r0, #0
	strb r0, [r2, #0x1a]
	b _080824E4
	.align 2, 0
_080824C0: .4byte 0x000004FD
_080824C4:
	movs r0, #0
	b _080824E8
_080824C8:
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #2
	strb r0, [r1]
	movs r1, #0
	ldr r0, _080824F0 @ =0x00000507
	strh r0, [r2, #0xc]
	strb r1, [r2, #0x1a]
	subs r0, #0x47
	strh r0, [r2, #0x14]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r2, #8]
_080824E4:
	ldrb r0, [r3]
	adds r0, #1
_080824E8:
	strb r0, [r3]
_080824EA:
	pop {r0}
	bx r0
	.align 2, 0
_080824F0: .4byte 0x00000507

.syntax divided
