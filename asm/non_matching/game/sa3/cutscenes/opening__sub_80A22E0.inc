.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	mov r6, ip
	adds r6, #0x50
	ldr r0, _080A238C @ =0x06010000
	mov r1, ip
	str r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #5
	str r0, [r1, #8]
	movs r1, #0
	movs r2, #0
	movs r0, #0xa1
	mov r3, ip
	strh r0, [r3, #0xc]
	movs r0, #0x82
	strh r0, [r3, #0x10]
	movs r5, #0x8c
	strh r5, [r3, #0x12]
	movs r0, #0x88
	lsls r0, r0, #3
	strh r0, [r3, #0x14]
	strh r2, [r3, #0x16]
	ldr r0, _080A2390 @ =0x0000FFFF
	strh r0, [r3, #0x18]
	movs r0, #3
	strb r0, [r3, #0x1a]
	movs r0, #0xff
	strb r0, [r3, #0x1b]
	movs r3, #0x10
	mov r7, ip
	strb r3, [r7, #0x1c]
	strb r1, [r7, #0x1f]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [r7, #0x20]
	strh r2, [r6]
	ldr r0, _080A2394 @ =0x0000FF20
	strh r0, [r6, #2]
	movs r0, #0xe0
	strh r0, [r6, #4]
	ldrh r0, [r7, #0x10]
	strh r0, [r6, #6]
	ldrh r0, [r7, #0x12]
	strh r0, [r6, #8]
	mov r1, ip
	adds r1, #0x28
	adds r6, #0xc
	ldr r0, _080A2398 @ =0x06010800
	str r0, [r7, #0x28]
	ldr r0, _080A239C @ =0x00001021
	str r0, [r1, #8]
	ldr r0, _080A23A0 @ =0x000001E7
	strh r0, [r1, #0xc]
	movs r0, #0x64
	strh r0, [r1, #0x10]
	strh r5, [r1, #0x12]
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1, #0x14]
	strh r2, [r1, #0x16]
	adds r0, r4, #0
	strh r0, [r1, #0x18]
	movs r0, #4
	strb r0, [r1, #0x1a]
	adds r0, r4, #0
	strb r0, [r1, #0x1b]
	strb r3, [r1, #0x1c]
	movs r0, #1
	strb r0, [r1, #0x1f]
	str r4, [r1, #0x20]
	strh r2, [r6]
	movs r0, #0xff
	lsls r0, r0, #8
	strh r0, [r6, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r6, #4]
	ldrh r0, [r1, #0x10]
	strh r0, [r6, #6]
	ldrh r0, [r1, #0x12]
	strh r0, [r6, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A238C: .4byte 0x06010000
_080A2390: .4byte 0x0000FFFF
_080A2394: .4byte 0x0000FF20
_080A2398: .4byte 0x06010800
_080A239C: .4byte 0x00001021
_080A23A0: .4byte 0x000001E7

.syntax divided
