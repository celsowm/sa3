.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #4]
	lsls r2, r2, #0x10
	ldr r0, _080291AC @ =gCurTask
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r1, r1, r0
	mov r8, r1
	movs r5, #0
	lsrs r0, r2, #0x10
	mov sb, r0
	asrs r2, r2, #0x10
	mvns r2, r2
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r6, r0, #0x1f
	movs r1, #0
_0802918A:
	lsls r7, r1, #0x10
	cmp r6, #0
	beq _080291D8
	asrs r1, r7, #0x10
	movs r0, #0x32
	muls r1, r0, r1
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080291B0
	movs r2, #0
	b _080291B6
	.align 2, 0
_080291AC: .4byte gCurTask
_080291B0:
	cmp r0, #0xf0
	ble _080291B6
	movs r2, #0xf0
_080291B6:
	asrs r0, r7, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080291CE
	movs r1, #0xf0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	b _080291D6
_080291CE:
	lsls r0, r2, #0x10
	ldr r1, _080291F8 @ =0xFF100000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
_080291D6:
	adds r5, r0, #0
_080291D8:
	ldr r0, _080291FC @ =gUnknown_03001060
	ldrb r1, [r0, #7]
	asrs r2, r7, #0x10
	asrs r1, r2
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08029200
	movs r1, #4
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x10
	b _08029202
	.align 2, 0
_080291F8: .4byte 0xFF100000
_080291FC: .4byte gUnknown_03001060
_08029200:
	movs r0, #0
_08029202:
	asrs r4, r7, #0x10
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x18
	adds r4, #1
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #0x1b
	lsrs r2, r2, #0x18
	lsls r3, r5, #0x10
	lsrs r3, r3, #0x10
	str r0, [sp]
	movs r0, #3
	bl sa2__sub_80078D4
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _0802918A
	mov r2, sl
	cmp r2, #0
	beq _080292B4
	movs r1, #0
_08029234:
	lsls r2, r1, #0x10
	asrs r4, r2, #0x10
	ldr r1, [sp, #4]
	asrs r1, r4
	movs r0, #1
	ands r1, r0
	adds r7, r2, #0
	cmp r1, #0
	beq _080292A6
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #4
	adds r0, #0x80
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
	movs r1, #0
	ldr r0, _080292C4 @ =0x0000048A
	add r0, r8
	ldrb r0, [r0]
	adds r0, #4
	cmp r1, r0
	bge _080292A6
	movs r0, #0xc8
	muls r0, r4, r0
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	mov r2, r8
	adds r6, r2, r0
_0802927A:
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r5, r6, r0
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	asrs r4, r4, #0x10
	ldr r0, _080292C4 @ =0x0000048A
	add r0, r8
	ldrb r0, [r0]
	adds r0, #4
	cmp r4, r0
	blt _0802927A
_080292A6:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r7, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08029234
_080292B4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080292C4: .4byte 0x0000048A

.syntax divided
