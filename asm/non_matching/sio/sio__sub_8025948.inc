.syntax unified
.text
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _08025990 @ =gStageData
	ldrb r5, [r0, #6]
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802598A
	ldr r4, _08025994 @ =gMultiSioSend
	adds r0, r4, #0
	adds r0, #0xf
	adds r0, r5, r0
	movs r1, #0xff
	strb r1, [r0]
	movs r0, #0
	strh r0, [r4, #0xc]
	bl sub_80247D4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	bl sub_80248F4
	ldrh r1, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
	adds r0, r6, #0
	bl sub_8025C64
	movs r0, #1
_0802598A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08025990: .4byte gStageData
_08025994: .4byte gMultiSioSend

.syntax divided
