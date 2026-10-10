.syntax unified
.text
	push {r4, r5, lr}
	ldr r5, _08028408 @ =gCurTask
	ldr r0, [r5]
	ldrh r4, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r4, r0
	bl UpdateScreenFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08028400
	ldr r0, _0802840C @ =gMultiBootParam
	ldr r2, _08028410 @ =0x030000E0
	adds r1, r4, r2
	ldr r1, [r1]
	str r1, [r0, #0x28]
	adds r2, r0, #0
	adds r2, #0x4b
	movs r1, #0
	strb r1, [r2]
	bl MultiBootInit
	ldr r1, [r5]
	ldr r0, _08028414 @ =sa2__sub_8081604
	str r0, [r1, #8]
_08028400:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08028408: .4byte gCurTask
_0802840C: .4byte gMultiBootParam
_08028410: .4byte 0x030000E0
_08028414: .4byte sa2__sub_8081604

.syntax divided
