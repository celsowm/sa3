.syntax unified
.text
	push {r4, lr}
	ldr r0, _08025A7C @ =gUnknown_03001060
	ldrb r4, [r0, #7]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08025A8A
	bl sub_8025CD8
	cmp r4, #3
	beq _08025A5A
	cmp r4, #7
	beq _08025A5A
	cmp r4, #0xf
	bne _08025A88
_08025A5A:
	lsrs r0, r4, #3
	movs r1, #1
	ands r0, r1
	ldr r1, _08025A80 @ =gMultiSioRecv+1*0x18
	cmp r0, #0
	beq _08025A68
	adds r1, #0x30
_08025A68:
	ldr r2, _08025A84 @ =0xFFFF99F6
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08025A88
	movs r0, #1
	b _08025A8A
	.align 2, 0
_08025A7C: .4byte gUnknown_03001060
_08025A80: .4byte gMultiSioRecv+1*0x18
_08025A84: .4byte 0xFFFF99F6
_08025A88:
	movs r0, #0
_08025A8A:
	pop {r4}
	pop {r1}
	bx r1

.syntax divided
