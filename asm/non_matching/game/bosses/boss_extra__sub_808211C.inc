.syntax unified
.text
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r0, [r0, #0x28]
	ldr r0, [r0, #0x10]
	asrs r0, r0, #8
	ldr r2, _08082148 @ =gCamera
	adds r1, r2, #0
	adds r1, #0x6a
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r1, r1, #1
	adds r1, r0, r1
	ldr r0, [r2]
	subs r0, r1, r0
	adds r1, r0, #0
	subs r1, #0xb4
	adds r3, r2, #0
	cmp r1, #0
	bgt _0808214C
	movs r1, #0
	b _0808214E
	.align 2, 0
_08082148: .4byte gCamera
_0808214C:
	rsbs r1, r1, #0
_0808214E:
	ldr r0, _08082180 @ =gStageData
	ldrb r0, [r0, #3]
	cmp r0, #5
	bne _08082186
	cmp r1, #0
	bne _08082186
	mov r4, ip
	ldr r0, [r4, #0x2c]
	ldr r0, [r0, #0x10]
	asrs r0, r0, #8
	adds r1, r3, #0
	adds r1, #0x6a
	movs r5, #0
	ldrsh r1, [r1, r5]
	lsls r1, r1, #1
	adds r1, r0, r1
	ldr r0, [r3]
	subs r0, r1, r0
	adds r1, r0, #0
	subs r1, #0xb4
	cmp r1, #0
	bgt _08082184
	movs r1, #0
	b _08082186
	.align 2, 0
_08082180: .4byte gStageData
_08082184:
	rsbs r1, r1, #0
_08082186:
	mov r2, ip
	ldrb r0, [r2, #1]
	cmp r0, #7
	bne _08082190
	movs r1, #0
_08082190:
	adds r4, r3, #0
	adds r4, #0x6a
	movs r5, #0
	ldrsh r0, [r4, r5]
	mov r5, ip
	ldrb r2, [r5, #0x17]
	cmp r0, #0
	bne _080821A4
	cmp r2, #0
	beq _080821C0
_080821A4:
	cmp r2, #0
	beq _080821AE
	subs r0, r2, #1
	mov r1, ip
	strb r0, [r1, #0x17]
_080821AE:
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _080821BC
	movs r0, #1
	mov r4, ip
	strb r0, [r4, #0x17]
_080821BC:
	mov r5, ip
	ldr r1, [r5, #0x18]
_080821C0:
	mov r0, ip
	str r1, [r0, #0x18]
	mov r2, ip
	adds r2, #0xf4
	adds r1, #0x78
	ldr r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #8
	str r0, [r2]
	mov r1, ip
	adds r1, #0xee
	movs r0, #0
	strb r0, [r1]
	mov r0, ip
	adds r0, #0xed
	ldrb r0, [r0]
	adds r6, r2, #0
	adds r5, r1, #0
	mov r3, ip
	adds r3, #0xb0
	mov r4, ip
	adds r4, #0xb4
	cmp r0, #8
	bls _080821F2
	b _08082360
_080821F2:
	lsls r0, r0, #2
	ldr r1, _080821FC @ =_08082200
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080821FC: .4byte _08082200
_08082200: @ jump table
	.4byte _08082360 @ case 0
	.4byte _08082224 @ case 1
	.4byte _08082248 @ case 2
	.4byte _08082270 @ case 3
	.4byte _080822C0 @ case 4
	.4byte _080822F0 @ case 5
	.4byte _08082310 @ case 6
	.4byte _08082360 @ case 7
	.4byte _08082338 @ case 8
_08082224:
	mov r0, ip
	adds r0, #0xb0
	ldr r1, [r0]
	ldr r2, _08082244 @ =0xFFFFFE00
	adds r1, r1, r2
	str r1, [r0]
	adds r3, r0, #0
	mov r4, ip
	adds r4, #0xb4
	cmp r1, #0
	ble _0808223C
	b _08082360
_0808223C:
	movs r0, #0
	str r0, [r3]
	b _0808232C
	.align 2, 0
_08082244: .4byte 0xFFFFFE00
_08082248:
	mov r0, ip
	adds r0, #0xb0
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r1, r3
	str r1, [r0]
	ldr r2, _0808226C @ =0x000077FF
	adds r3, r0, #0
	mov r4, ip
	adds r4, #0xb4
	cmp r1, r2
	bgt _08082264
	b _08082360
_08082264:
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r3]
	b _0808232C
	.align 2, 0
_0808226C: .4byte 0x000077FF
_08082270:
	ldr r5, _080822BC @ =gSineTable
	mov r4, ip
	adds r4, #0xe0
	ldrh r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r2, ip
	adds r2, #0xfc
	ldr r0, [r2]
	muls r0, r1, r0
	mov r3, ip
	adds r3, #0xb0
	cmp r0, #0
	bge _08082298
	adds r0, #0x3f
_08082298:
	asrs r0, r0, #6
	str r0, [r3]
	ldrh r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r0, [r2]
	muls r0, r1, r0
	mov r4, ip
	adds r4, #0xb4
	cmp r0, #0
	bge _080822B4
	adds r0, #0x3f
_080822B4:
	asrs r0, r0, #6
	str r0, [r4]
	b _08082360
	.align 2, 0
_080822BC: .4byte gSineTable
_080822C0:
	mov r0, ip
	adds r0, #0xb4
	ldr r3, [r0]
	adds r4, r0, #0
	cmp r3, #0
	bge _080822DE
	adds r0, r3, #0
	adds r0, #0x80
	str r0, [r4]
	mov r3, ip
	adds r3, #0xb0
	cmp r0, #0
	blt _08082360
	movs r0, #0
	b _0808232A
_080822DE:
	adds r0, r3, #0
	subs r0, #0x80
	str r0, [r4]
	mov r3, ip
	adds r3, #0xb0
	cmp r0, #0
	bgt _08082360
	movs r0, #0
	b _0808232A
_080822F0:
	mov r1, ip
	adds r1, #0xb4
	ldr r0, [r1]
	subs r0, #0x80
	str r0, [r1]
	ldr r2, _0808230C @ =0xFFFFA000
	mov r3, ip
	adds r3, #0xb0
	adds r4, r1, #0
	cmp r0, r2
	bgt _08082360
	str r2, [r4]
	b _0808232C
	.align 2, 0
_0808230C: .4byte 0xFFFFA000
_08082310:
	mov r0, ip
	adds r0, #0xb4
	ldr r1, [r0]
	adds r1, #0x80
	str r1, [r0]
	ldr r2, _08082334 @ =0x00005FFF
	mov r3, ip
	adds r3, #0xb0
	adds r4, r0, #0
	cmp r1, r2
	ble _08082360
	movs r0, #0xc0
	lsls r0, r0, #7
_0808232A:
	str r0, [r4]
_0808232C:
	movs r0, #1
	strb r0, [r5]
	b _08082360
	.align 2, 0
_08082334: .4byte 0x00005FFF
_08082338:
	mov r4, ip
	adds r4, #0xa8
	ldr r0, [r4]
	adds r0, #4
	str r0, [r4]
	mov r3, ip
	adds r3, #0xb0
	mov r1, ip
	adds r1, #0xa4
	ldr r0, [r3]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r3]
	mov r2, ip
	adds r2, #0xb4
	ldr r0, [r2]
	ldr r1, [r4]
	adds r0, r0, r1
	str r0, [r2]
	adds r4, r2, #0
_08082360:
	mov r2, ip
	adds r2, #0x9c
	ldr r0, [r6]
	ldr r1, [r3]
	adds r0, r0, r1
	str r0, [r2]
	adds r2, #4
	mov r0, ip
	adds r0, #0xf8
	ldr r0, [r0]
	ldr r1, [r4]
	adds r0, r0, r1
	str r0, [r2]
	mov r0, ip
	movs r1, #0
	bl sub_8082E2C
	pop {r4, r5, r6}
	pop {r0}
	bx r0

.syntax divided
