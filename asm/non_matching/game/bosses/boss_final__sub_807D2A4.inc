.syntax unified
.text
	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0
	ldrh r2, [r3, #0x16]
	cmp r1, #1
	beq _0807D2E2
	cmp r1, #1
	bgt _0807D2BE
	cmp r1, #0
	beq _0807D2C8
	b _0807D328
_0807D2BE:
	cmp r0, #2
	beq _0807D2F4
	cmp r0, #3
	beq _0807D308
	b _0807D328
_0807D2C8:
	ldr r0, _0807D2D8 @ =0x000002FF
	cmp r2, r0
	bls _0807D2DC
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r1, #0
	b _0807D322
	.align 2, 0
_0807D2D8: .4byte 0x000002FF
_0807D2DC:
	movs r4, #0x80
	lsls r4, r4, #3
	b _0807D320
_0807D2E2:
	cmp r2, #0xff
	bls _0807D2EE
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r1, #0
	b _0807D322
_0807D2EE:
	movs r4, #0x80
	lsls r4, r4, #3
	b _0807D320
_0807D2F4:
	ldr r0, _0807D304 @ =0x000001FF
	cmp r2, r0
	bls _0807D31C
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r1, #0
	b _0807D322
	.align 2, 0
_0807D304: .4byte 0x000001FF
_0807D308:
	ldr r0, _0807D318 @ =0x000002FF
	cmp r2, r0
	bls _0807D31C
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r1, #0
	b _0807D322
	.align 2, 0
_0807D318: .4byte 0x000002FF
_0807D31C:
	movs r4, #0x80
	lsls r4, r4, #2
_0807D320:
	adds r0, r4, #0
_0807D322:
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0807D328:
	ldr r0, _0807D370 @ =0x000003FF
	ands r2, r0
	strh r2, [r3, #0x16]
	ldr r2, _0807D374 @ =gSineTable
	ldrh r0, [r3, #0x16]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r1, [r3, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	bge _0807D34C
	ldr r4, _0807D378 @ =0x00003FFF
	adds r0, r0, r4
_0807D34C:
	asrs r0, r0, #0xe
	str r0, [r3, #8]
	ldrh r0, [r3, #0x16]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	bge _0807D364
	ldr r4, _0807D378 @ =0x00003FFF
	adds r0, r0, r4
_0807D364:
	asrs r0, r0, #0xe
	str r0, [r3, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D370: .4byte 0x000003FF
_0807D374: .4byte gSineTable
_0807D378: .4byte 0x00003FFF

.syntax divided
