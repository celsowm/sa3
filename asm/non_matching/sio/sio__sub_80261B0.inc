.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	ldr r2, _08026244 @ =gUnknown_03001CC0
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	strb r1, [r2, #1]
	ldr r7, _08026248 @ =gMultiSioSend
	adds r4, r2, #2
	movs r3, #0xff
_080261C8:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #2
	adds r2, r2, r0
	adds r2, r2, r4
	ldrb r1, [r2]
	orrs r1, r3
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _080261C8
	movs r1, #0
	ldr r5, _0802624C @ =gPlayers
	movs r6, #0x39
	rsbs r6, r6, #0
	movs r4, #0x20
_080261EE:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r1, r5
	adds r1, #0x2c
	ldrb r3, [r1]
	adds r0, r6, #0
	ands r0, r3
	orrs r0, r4
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _080261EE
	movs r0, #0xff
	strb r0, [r7, #0x12]
	movs r1, #0
	ldr r4, _08026250 @ =gMultiSioRecv
	movs r3, #0xff
_08026220:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r2, r1, r4
	ldrb r1, [r2, #0x12]
	orrs r1, r3
	strb r1, [r2, #0x12]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08026220
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026244: .4byte gUnknown_03001CC0
_08026248: .4byte gMultiSioSend
_0802624C: .4byte gPlayers
_08026250: .4byte gMultiSioRecv

.syntax divided
