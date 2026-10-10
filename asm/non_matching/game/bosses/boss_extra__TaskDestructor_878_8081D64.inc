.syntax unified
.text
	push {r4, r5, lr}
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r4, r0
	ldr r1, _08081DE4 @ =0x0300038C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08081D7C
	bl VramFree
_08081D7C:
	ldr r1, _08081DE8 @ =0x030003B4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08081D8A
	bl VramFree
_08081D8A:
	ldr r1, _08081DEC @ =0x03000454
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08081D98
	bl VramFree
_08081D98:
	ldr r1, _08081DF0 @ =0x03000814
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08081DA6
	bl VramFree
_08081DA6:
	ldrb r0, [r5, #1]
	cmp r0, #6
	beq _08081DDE
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq _08081DB6
	bl VramFree
_08081DB6:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _08081DC0
	bl VramFree
_08081DC0:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _08081DCA
	bl VramFree
_08081DCA:
	ldr r0, [r5, #0x6c]
	cmp r0, #0
	beq _08081DD4
	bl VramFree
_08081DD4:
	ldr r0, [r5, #0x74]
	cmp r0, #0
	beq _08081DDE
	bl VramFree
_08081DDE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081DE4: .4byte 0x0300038C
_08081DE8: .4byte 0x030003B4
_08081DEC: .4byte 0x03000454
_08081DF0: .4byte 0x03000814

.syntax divided
