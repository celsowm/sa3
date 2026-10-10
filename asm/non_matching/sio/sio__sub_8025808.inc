.syntax unified
.text
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r5, _0802585C @ =gMultiSioSend
	ldr r1, _08025860 @ =gStageData
	ldr r0, _08025864 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r1, #6]
	adds r2, r0, #0
	cmp r2, #1
	bhi _08025832
	ldr r0, _08025868 @ =gUnknown_03001060
	ldrb r1, [r0, #7]
	movs r0, #4
	lsls r0, r2
	ands r1, r0
	cmp r1, #0
	bne _08025832
	adds r2, #2
_08025832:
	ldr r0, _0802586C @ =0x00006607
	strh r0, [r5]
	strb r2, [r5, #3]
	movs r2, #0
	adds r3, r5, #0
	adds r3, #0xf
	ldr r4, _08025870 @ =gUnknown_030010AC
_08025840:
	adds r1, r3, r2
	adds r0, r2, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08025840
	strb r6, [r5, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802585C: .4byte gMultiSioSend
_08025860: .4byte gStageData
_08025864: .4byte 0x04000128
_08025868: .4byte gUnknown_03001060
_0802586C: .4byte 0x00006607
_08025870: .4byte gUnknown_030010AC

.syntax divided
