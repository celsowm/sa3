.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0
	ldr r5, _08026AF8 @ =gUnknown_03001CC0
	adds r6, r5, #2
_08026AC2:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	lsls r0, r1, #2
	adds r2, r0, r1
	adds r3, r2, r6
	ldrb r0, [r3]
	cmp r0, #0xff
	bne _08026AFC
	ldrb r0, [r4]
	strb r0, [r3]
	adds r0, r5, #3
	adds r0, r2, r0
	ldrb r1, [r4, #1]
	strb r1, [r0]
	adds r0, r5, #4
	adds r0, r2, r0
	ldrb r1, [r4, #2]
	strb r1, [r0]
	adds r0, r5, #5
	adds r0, r2, r0
	ldrb r1, [r4, #3]
	strb r1, [r0]
	adds r0, r5, #6
	adds r0, r2, r0
	ldrb r1, [r4, #4]
	strb r1, [r0]
	b _08026B08
	.align 2, 0
_08026AF8: .4byte gUnknown_03001CC0
_08026AFC:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _08026AC2
_08026B08:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
