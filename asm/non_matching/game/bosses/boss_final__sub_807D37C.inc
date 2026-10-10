.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	movs r5, #0
	ldr r0, [r4]
	asrs r0, r0, #8
	ldr r2, _0807D400 @ =gCamera
	ldr r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	ldr r1, [r2, #4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r0, #0
	bgt _0807D3B4
	ldrh r1, [r4, #0x16]
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bls _0807D3B4
	adds r0, r4, #0
	movs r1, #0
	bl sub_807D2A4
	movs r5, #1
_0807D3B4:
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	adds r0, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xbf
	ble _0807D3D8
	ldrh r1, [r4, #0x16]
	ldr r0, _0807D404 @ =0x000001FF
	cmp r1, r0
	bhi _0807D3D8
	cmp r5, #0
	bne _0807D40C
	adds r0, r4, #0
	movs r1, #1
	bl sub_807D2A4
	movs r5, #2
_0807D3D8:
	cmp r5, #0
	bne _0807D40C
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb3
	bgt _0807D3F6
	lsls r0, r7, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x14
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0807D3F6
	ldr r0, _0807D408 @ =0x00000103
	cmp r1, r0
	ble _0807D414
_0807D3F6:
	movs r0, #0
	strh r0, [r4, #0x18]
	movs r5, #3
	b _0807D414
	.align 2, 0
_0807D400: .4byte gCamera
_0807D404: .4byte 0x000001FF
_0807D408: .4byte 0x00000103
_0807D40C:
	movs r0, #0x8e
	lsls r0, r0, #2
	bl m4aSongNumStart
_0807D414:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

.syntax divided
