.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r1, _080A2A20 @ =gCurTask
	ldr r1, [r1]
	ldrh r3, [r1, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r6, r3, r1
	lsls r5, r0, #0x10
	asrs r4, r5, #0x10
	cmp r4, #0xff
	bgt _080A2A18
	ldr r0, _080A2A24 @ =0x03000136
	adds r2, r3, r0
	adds r0, r4, #0
	adds r0, #0x20
	asrs r0, r0, #4
	subs r0, #4
	ldrh r1, [r2]
	subs r1, r1, r0
	strh r1, [r6, #0x12]
	ldr r7, _080A2A28 @ =0x03000058
	adds r0, r3, r7
	strh r1, [r0]
	asrs r0, r5, #0x14
	subs r0, #4
	ldrh r1, [r2]
	subs r1, r1, r0
	strh r1, [r6, #0x3a]
	ldr r2, _080A2A2C @ =0x03000064
	adds r0, r3, r2
	strh r1, [r0]
	asrs r2, r5, #0x11
	adds r0, r2, #0
	adds r0, #0x82
	adds r0, r4, r0
	strh r0, [r6, #0x10]
	subs r7, #2
	adds r1, r3, r7
	strh r0, [r1]
	adds r2, r2, r4
	mov ip, r2
	movs r0, #0xe0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	ble _080A29E6
	rsbs r0, r0, #0
	subs r7, #4
	adds r1, r3, r7
	strh r0, [r1]
	ldr r1, _080A2A30 @ =0x03000054
	adds r0, r3, r1
	strh r2, [r0]
_080A29E6:
	lsls r1, r4, #1
	asrs r0, r5, #0x12
	subs r0, #0x64
	subs r1, r1, r0
	strh r1, [r6, #0x38]
	ldr r2, _080A2A34 @ =0x03000062
	adds r0, r3, r2
	strh r1, [r0]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r4, #0
	mov r7, ip
	subs r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	ble _080A2A18
	rsbs r0, r0, #0
	ldr r4, _080A2A38 @ =0x0300005E
	adds r1, r3, r4
	strh r0, [r1]
	ldr r7, _080A2A3C @ =0x03000060
	adds r0, r3, r7
	strh r2, [r0]
_080A2A18:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2A20: .4byte gCurTask
_080A2A24: .4byte 0x03000136
_080A2A28: .4byte 0x03000058
_080A2A2C: .4byte 0x03000064
_080A2A30: .4byte 0x03000054
_080A2A34: .4byte 0x03000062
_080A2A38: .4byte 0x0300005E
_080A2A3C: .4byte 0x03000060

.syntax divided
