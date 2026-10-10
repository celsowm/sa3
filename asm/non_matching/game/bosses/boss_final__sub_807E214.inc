.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r0, r1
	mov r2, r8
	adds r4, r2, r0
	movs r7, #0
	ldrh r1, [r4, #0x16]
	cmp r1, #0xc8
	bne _0807E23C
	b _0807E3E0
_0807E23C:
	cmp r1, #0xc8
	bgt _0807E254
	cmp r1, #0xa
	beq _0807E292
	cmp r1, #0xa
	bgt _0807E24E
	cmp r1, #0
	beq _0807E282
	b _0807E53A
_0807E24E:
	cmp r1, #0x64
	beq _0807E31E
	b _0807E53A
_0807E254:
	movs r2, #0x9b
	lsls r2, r2, #1
	cmp r1, r2
	bne _0807E25E
	b _0807E424
_0807E25E:
	cmp r1, r2
	bgt _0807E26E
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _0807E26C
	b _0807E414
_0807E26C:
	b _0807E53A
_0807E26E:
	movs r0, #0xa0
	lsls r0, r0, #1
	cmp r1, r0
	bne _0807E278
	b _0807E484
_0807E278:
	adds r0, #0xb4
	cmp r1, r0
	bne _0807E280
	b _0807E508
_0807E280:
	b _0807E53A
_0807E282:
	str r7, [r4, #8]
	str r7, [r4, #0xc]
	strb r7, [r4, #0x1b]
	str r7, [r4, #0x1c]
	movs r0, #0x79
	strh r0, [r4, #0x14]
	movs r0, #0xa
	b _0807E538
_0807E292:
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x1c]
	adds r1, r1, r0
	str r1, [r4, #0xc]
	cmp r1, #0
	bge _0807E2AC
	ldr r0, _0807E2A8 @ =0xFFFFFE00
	cmp r1, r0
	bgt _0807E2B6
	b _0807E2B4
	.align 2, 0
_0807E2A8: .4byte 0xFFFFFE00
_0807E2AC:
	ldr r0, _0807E2D4 @ =0x000001FF
	cmp r1, r0
	ble _0807E2B6
	adds r0, #1
_0807E2B4:
	str r0, [r4, #0xc]
_0807E2B6:
	ldr r1, [r4, #4]
	ldr r0, [r4, #0xc]
	adds r7, r1, r0
	str r7, [r4, #4]
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807E2EC
	cmp r6, #0
	bne _0807E2D8
	movs r0, #0x80
	lsls r0, r0, #3
	b _0807E2DA
	.align 2, 0
_0807E2D4: .4byte 0x000001FF
_0807E2D8:
	ldr r0, _0807E2E8 @ =0xFFFFFC00
_0807E2DA:
	str r0, [r4, #8]
	movs r1, #0
	movs r0, #0x64
	strh r0, [r4, #0x16]
	strb r1, [r4, #0x13]
	b _0807E53A
	.align 2, 0
_0807E2E8: .4byte 0xFFFFFC00
_0807E2EC:
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807E2FE
	b _0807E53A
_0807E2FE:
	mov r2, r8
	ldr r5, [r2, #0x20]
	ldr r0, [r5, #0x14]
	ldr r1, _0807E314 @ =0xFFFFF000
	adds r0, r0, r1
	cmp r7, r0
	ble _0807E318
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r4, #0x1c]
	b _0807E53A
	.align 2, 0
_0807E314: .4byte 0xFFFFF000
_0807E318:
	movs r0, #0x40
	str r0, [r4, #0x1c]
	b _0807E53A
_0807E31E:
	ldr r3, [r4]
	ldr r0, [r4, #8]
	adds r1, r3, r0
	str r1, [r4]
	cmp r6, #0
	bne _0807E338
	ldr r0, _0807E334 @ =0x000667FF
	cmp r1, r0
	ble _0807E344
	adds r0, #1
	b _0807E340
	.align 2, 0
_0807E334: .4byte 0x000667FF
_0807E338:
	movs r0, #0xd1
	lsls r0, r0, #0xb
	cmp r1, r0
	bgt _0807E344
_0807E340:
	str r0, [r4]
	movs r7, #1
_0807E344:
	ldr r1, [r4]
	subs r3, r3, r1
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r0, r0, r2
	add r0, r8
	ldr r2, [r4, #4]
	movs r5, #0
	str r5, [sp]
	bl sub_807C244
	cmp r7, #0
	bne _0807E366
	b _0807E53A
_0807E366:
	movs r0, #0xc8
	strh r0, [r4, #0x16]
	cmp r6, #0
	bne _0807E370
	b _0807E53A
_0807E370:
	bl sub_807C5D0
	str r5, [sp, #0x28]
	add r0, sp, #0x2c
	movs r1, #0xf0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r1, sp
	adds r1, #0x2e
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x1e
	strb r0, [r1]
	mov r0, r8
	ldr r5, [r0, #0x20]
	adds r0, r5, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0807E3D4
	movs r6, #0x8e
	lsls r6, r6, #1
	add r6, r8
	ldr r1, [r6]
	asrs r1, r1, #8
	ldr r2, [r4, #4]
	asrs r2, r2, #8
	str r5, [sp]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r3, #0
	bl sub_8020700
	cmp r0, #0
	beq _0807E3D4
	movs r0, #1
	strb r0, [r4, #0x1b]
	movs r0, #0xa0
	bl sub_807FB7C
	adds r0, r5, #0
	bl sub_8081A10
	ldr r0, [r6]
	str r0, [r5, #0x10]
	ldr r0, [r4, #4]
	str r0, [r5, #0x14]
_0807E3D4:
	ldr r0, _0807E3DC @ =0x0000023B
	bl m4aSongNumStart
	b _0807E53A
	.align 2, 0
_0807E3DC: .4byte 0x0000023B
_0807E3E0:
	cmp r6, #0
	bne _0807E3E6
	b _0807E53A
_0807E3E6:
	adds r1, r4, #0
	subs r1, #0x28
	ldrh r0, [r1, #0x16]
	cmp r0, #0xc8
	beq _0807E3F2
	b _0807E53A
_0807E3F2:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _0807E3FE
	movs r0, #0x96
	lsls r0, r0, #1
	b _0807E402
_0807E3FE:
	movs r0, #0xfa
	lsls r0, r0, #1
_0807E402:
	strh r0, [r4, #0x16]
	strh r0, [r1, #0x16]
	ldr r0, [r4, #8]
	rsbs r0, r0, #0
	str r0, [r4, #8]
	ldr r0, [r1, #8]
	rsbs r0, r0, #0
	str r0, [r1, #8]
	b _0807E53A
_0807E414:
	ldr r0, _0807E420 @ =0xFFFFF800
	str r0, [r4, #0xc]
	movs r0, #4
	strb r0, [r4, #0x1b]
	strh r2, [r4, #0x16]
	b _0807E53A
	.align 2, 0
_0807E420: .4byte 0xFFFFF800
_0807E424:
	ldr r1, [r4, #4]
	ldr r0, [r4, #0xc]
	adds r1, r1, r0
	str r1, [r4, #4]
	adds r0, #0x80
	str r0, [r4, #0xc]
	cmp r6, #0
	beq _0807E440
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _0807E440
	mov r2, r8
	ldr r5, [r2, #0x20]
	str r1, [r5, #0x14]
_0807E440:
	ldr r1, [r4, #4]
	ldr r0, _0807E480 @ =0x0000AFFF
	cmp r1, r0
	ble _0807E53A
	ldr r0, [r4, #0xc]
	cmp r0, #0
	blt _0807E53A
	movs r0, #0xb0
	lsls r0, r0, #8
	str r0, [r4, #4]
	movs r0, #0x1e
	strh r0, [r4, #0x14]
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r4, #0x16]
	cmp r6, #0
	beq _0807E53A
	adds r0, #0xfc
	bl m4aSongNumStart
	movs r0, #0x80
	lsls r0, r0, #4
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0x91
	str r1, [sp]
	movs r1, #0x20
	movs r2, #0
	bl CreateScreenShake
	b _0807E53A
	.align 2, 0
_0807E480: .4byte 0x0000AFFF
_0807E484:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807E53A
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _0807E49A
	subs r0, #1
	strb r0, [r4, #0x1b]
_0807E49A:
	ldrb r0, [r4, #0x1b]
	cmp r0, #1
	bhi _0807E4FA
	cmp r6, #0
	beq _0807E4EE
	mov r1, r8
	ldr r5, [r1, #0x20]
	cmp r0, #0
	beq _0807E4EE
	adds r6, r5, #0
	adds r6, #0x4a
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bgt _0807E4C4
	adds r0, r5, #0
	adds r0, #0x4c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0807E4E8
_0807E4C4:
	adds r0, r5, #0
	adds r0, #0x9e
	strh r7, [r0]
	ldr r0, [r5, #4]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #4]
	str r7, [r5, #0x6c]
	ldr r1, _0807E4E4 @ =Player_8008CD0
	adds r0, r5, #0
	bl SetPlayerCallback
	movs r0, #0x78
	strh r0, [r6]
	b _0807E4EE
	.align 2, 0
_0807E4E4: .4byte Player_8008CD0
_0807E4E8:
	adds r0, r5, #0
	bl Player_8014550
_0807E4EE:
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r4, #0x16]
	movs r0, #1
	strb r0, [r4, #0x13]
	b _0807E53A
_0807E4FA:
	ldr r0, _0807E504 @ =0xFFFFF600
	str r0, [r4, #0xc]
	strh r2, [r4, #0x16]
	b _0807E53A
	.align 2, 0
_0807E504: .4byte 0xFFFFF600
_0807E508:
	ldr r1, [r4]
	ldr r0, [r4, #8]
	adds r1, r1, r0
	str r1, [r4]
	cmp r6, #0
	bne _0807E524
	ldr r0, _0807E520 @ =0x00061400
	cmp r1, r0
	bgt _0807E530
	str r0, [r4]
	b _0807E534
	.align 2, 0
_0807E520: .4byte 0x00061400
_0807E524:
	ldr r0, _0807E548 @ =0x0006DBFF
	cmp r1, r0
	ble _0807E530
	adds r0, #1
	str r0, [r4]
	movs r7, #1
_0807E530:
	cmp r7, #0
	beq _0807E53A
_0807E534:
	movs r0, #0xfa
	lsls r0, r0, #2
_0807E538:
	strh r0, [r4, #0x16]
_0807E53A:
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E548: .4byte 0x0006DBFF

.syntax divided
