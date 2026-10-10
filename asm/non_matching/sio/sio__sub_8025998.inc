.syntax unified
.text
	push {r4, lr}
	ldr r0, _080259D8 @ =gUnknown_03001060
	ldrb r4, [r0, #7]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080259E6
	bl sub_8025770
	cmp r4, #3
	beq _080259BA
	cmp r4, #7
	beq _080259BA
	cmp r4, #0xf
	bne _080259D4
_080259BA:
	ldr r2, _080259DC @ =gMultiSioRecv+1*0x18
	ldr r0, _080259D8 @ =gUnknown_03001060
	ldrb r1, [r2, #4]
	adds r0, #0x4d
	strb r1, [r0]
	ldr r1, _080259E0 @ =0xFFFF99FA
	adds r0, r1, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _080259E4
_080259D4:
	movs r0, #0
	b _080259E6
	.align 2, 0
_080259D8: .4byte gUnknown_03001060
_080259DC: .4byte gMultiSioRecv+1*0x18
_080259E0: .4byte 0xFFFF99FA
_080259E4:
	movs r0, #1
_080259E6:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
