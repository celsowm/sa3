.syntax unified
.text
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x30]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r5, r1, r0
	ldrh r0, [r4, #8]
	cmp r0, #0x82
	beq _08084D58
	cmp r0, #0x82
	bgt _08084C84
	cmp r0, #0x64
	beq _08084CCE
	cmp r0, #0x64
	bgt _08084C7A
	cmp r0, #0
	beq _08084CB4
	cmp r0, #0xa
	beq _08084CBC
	b _08084EA6
_08084C7A:
	cmp r0, #0x6e
	beq _08084D08
	cmp r0, #0x78
	beq _08084D48
	b _08084EA6
_08084C84:
	cmp r0, #0xa0
	bne _08084C8A
	b _08084DE8
_08084C8A:
	cmp r0, #0xa0
	bgt _08084C9A
	cmp r0, #0x8c
	beq _08084D7C
	cmp r0, #0x96
	bne _08084C98
	b _08084DC8
_08084C98:
	b _08084EA6
_08084C9A:
	cmp r0, #0xd2
	bne _08084CA0
	b _08084E7A
_08084CA0:
	cmp r0, #0xd2
	bgt _08084CAC
	cmp r0, #0xc8
	bne _08084CAA
	b _08084E48
_08084CAA:
	b _08084EA6
_08084CAC:
	cmp r0, #0xdc
	bne _08084CB2
	b _08084E98
_08084CB2:
	b _08084EA6
_08084CB4:
	movs r0, #0x78
	strh r0, [r4, #4]
	movs r0, #0xa
	b _08084EA4
_08084CBC:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08084CCA
	b _08084EA6
_08084CCA:
	movs r0, #0x64
	b _08084EA4
_08084CCE:
	adds r1, r4, #0
	adds r1, #0xd0
	movs r0, #0x8c
	lsls r0, r0, #8
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0
	str r2, [r0]
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe4
	str r2, [r0]
	adds r1, r4, #0
	adds r1, #0xe8
	movs r0, #0xd8
	lsls r0, r0, #0xa
	str r0, [r1]
	movs r0, #0x90
	lsls r0, r0, #2
	bl m4aSongNumStart
	movs r0, #0x6e
	b _08084EA4
_08084D08:
	adds r0, r4, #0
	adds r0, #0xd0
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r0, [r0]
	ldr r1, [r2]
	cmp r0, r1
	ble _08084D26
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r1, r0
	str r0, [r2]
	b _08084D32
_08084D26:
	ldr r0, _08084D44 @ =0x0000042E
	strh r0, [r5, #0x2c]
	movs r0, #0x3c
	strh r0, [r4, #4]
	movs r0, #0x78
	strh r0, [r4, #8]
_08084D32:
	adds r1, r4, #0
	adds r1, #0xe4
	ldr r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	b _08084E3A
	.align 2, 0
_08084D44: .4byte 0x0000042E
_08084D48:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084E3A
	movs r0, #0x82
	b _08084E38
_08084D58:
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	ldr r3, _08084D78 @ =0xFFFFFE00
	adds r1, r1, r3
	str r1, [r0]
	asrs r1, r1, #8
	movs r0, #0xb8
	lsls r0, r0, #2
	cmp r1, r0
	bgt _08084D9A
	movs r0, #0x87
	lsls r0, r0, #3
	strh r0, [r5, #0x2c]
	movs r0, #0x8c
	b _08084D98
	.align 2, 0
_08084D78: .4byte 0xFFFFFE00
_08084D7C:
	adds r0, r4, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r3, _08084DBC @ =0xFFFFF800
	adds r1, r1, r3
	str r1, [r0]
	ldr r0, _08084DC0 @ =0xFFFF9600
	cmp r1, r0
	bgt _08084D9A
	ldr r0, _08084DC4 @ =0x0000044C
	strh r0, [r5, #0x2c]
	movs r0, #0x78
	strh r0, [r4, #4]
	movs r0, #0x96
_08084D98:
	strh r0, [r4, #8]
_08084D9A:
	adds r0, r4, #0
	movs r1, #6
	bl sub_8082E2C
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	str r1, [r5, #0x14]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r5, #0x18]
	str r1, [r5, #0x30]
	str r0, [r5, #0x34]
	b _08084EA6
	.align 2, 0
_08084DBC: .4byte 0xFFFFF800
_08084DC0: .4byte 0xFFFF9600
_08084DC4: .4byte 0x0000044C
_08084DC8:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084E3A
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, _08084DE4 @ =0xFFFFFC00
	str r1, [r0]
	movs r0, #0xa0
	b _08084E38
	.align 2, 0
_08084DE4: .4byte 0xFFFFFC00
_08084DE8:
	adds r1, r4, #0
	adds r1, #0xe4
	ldr r0, [r1]
	cmp r0, #0
	beq _08084E02
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	str r0, [r1]
	cmp r0, #0
	blt _08084E02
	movs r0, #0
	str r0, [r1]
_08084E02:
	adds r3, r4, #0
	adds r3, #0xe8
	ldr r2, [r3]
	asrs r1, r2, #8
	movs r0, #0xb0
	lsls r0, r0, #2
	cmp r1, r0
	beq _08084E18
	ldr r1, _08084E44 @ =0xFFFFFF00
	adds r0, r2, r1
	str r0, [r3]
_08084E18:
	adds r2, r4, #0
	adds r2, #0xd4
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r2]
	cmp r1, #0
	bgt _08084E3A
	movs r0, #0
	str r0, [r2]
	movs r0, #0x3c
	strh r0, [r4, #4]
	movs r0, #0xc8
_08084E38:
	strh r0, [r4, #8]
_08084E3A:
	adds r0, r4, #0
	movs r1, #6
	bl sub_8082E2C
	b _08084EA6
	.align 2, 0
_08084E44: .4byte 0xFFFFFF00
_08084E48:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	bne _08084EA6
	movs r0, #0x50
	rsbs r0, r0, #0
	movs r1, #0x78
	bl sa2__sub_8004418
	adds r1, r4, #0
	adds r1, #0xe0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xfc
	str r5, [r0]
	subs r0, #0x58
	str r5, [r0]
	movs r0, #3
	adds r1, #0xd
	strb r0, [r1]
	movs r0, #0xd2
	b _08084EA4
_08084E7A:
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r1, [r0]
	adds r1, #0x80
	str r1, [r0]
	adds r2, r4, #0
	adds r2, #0xfc
	asrs r1, r1, #8
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	cmp r0, #0xc7
	ble _08084EA6
	movs r0, #0xdc
	b _08084EA4
_08084E98:
	ldr r0, _08084EAC @ =gCurTask
	ldr r1, [r0]
	ldr r0, _08084EB0 @ =sub_8086FE4
	str r0, [r1, #8]
	movs r0, #0xfa
	lsls r0, r0, #2
_08084EA4:
	strh r0, [r4, #8]
_08084EA6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084EAC: .4byte gCurTask
_08084EB0: .4byte sub_8086FE4

.syntax divided
