.syntax unified
.text
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, _080258C0 @ =gMultiSioSend
	ldr r1, _080258C4 @ =gStageData
	ldr r0, _080258C8 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r2, r0, #0
	cmp r2, #1
	bhi _0802589E
	ldr r0, _080258CC @ =gUnknown_03001060
	ldrb r1, [r0, #7]
	movs r0, #4
	lsls r0, r2
	ands r1, r0
	cmp r1, #0
	bne _0802589E
	adds r2, #2
_0802589E:
	ldr r0, _080258D0 @ =0x00006608
	strh r0, [r3]
	strb r2, [r3, #3]
	cmp r2, #1
	bls _080258B8
	adds r0, r3, #0
	adds r0, #0xf
	adds r0, r0, r2
	ldr r1, _080258CC @ =gUnknown_03001060
	adds r1, #0x4c
	adds r1, r2, r1
	ldrb r1, [r1]
	strb r1, [r0]
_080258B8:
	strb r4, [r3, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080258C0: .4byte gMultiSioSend
_080258C4: .4byte gStageData
_080258C8: .4byte 0x04000128
_080258CC: .4byte gUnknown_03001060
_080258D0: .4byte 0x00006608

.syntax divided
