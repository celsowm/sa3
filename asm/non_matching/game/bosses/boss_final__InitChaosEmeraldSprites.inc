.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xa8
	ldr r6, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #1]
	movs r5, #0
	movs r4, #0
	ldr r7, _08080544 @ =sBossExtraAnimsChaosEmeralds
	adds r0, r7, #4
	mov ip, r0
_080804CC:
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r3, #0
	adds r0, #0x24
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r3, #0
	adds r0, #0x28
	adds r0, r0, r1
	str r4, [r0]
	adds r1, r3, r1
	movs r0, #1
	strh r0, [r1, #0x2c]
	strh r4, [r1, #0x2e]
	str r6, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r2, #0x14]
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #1
	adds r0, r1, r7
	ldrh r0, [r0]
	strh r0, [r2, #0xc]
	adds r0, r7, #2
	adds r0, r1, r0
	ldrh r0, [r0]
	strb r0, [r2, #0x1a]
	strh r4, [r2, #0x16]
	movs r0, #0xff
	strb r0, [r2, #0x1b]
	movs r0, #0x10
	strb r0, [r2, #0x1c]
	add r1, ip
	ldrh r0, [r1]
	strb r0, [r2, #0x1f]
	strh r4, [r2, #0x10]
	strh r4, [r2, #0x12]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r2, #8]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r2, #0x28
	adds r6, #0x80
	cmp r5, #6
	bls _080804CC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080544: .4byte sBossExtraAnimsChaosEmeralds

.syntax divided
