.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r4, r6, r0
	ldrh r1, [r4, #0x16]
	cmp r1, #0
	beq _0807ED20
	cmp r1, #0xa
	beq _0807ED30
	b _0807ED84
_0807ED20:
	str r1, [r4, #8]
	ldr r0, _0807ED2C @ =0xFFFFFD00
	str r0, [r4, #0xc]
	strh r1, [r4, #0x14]
	movs r0, #0xa
	b _0807ED82
	.align 2, 0
_0807ED2C: .4byte 0xFFFFFD00
_0807ED30:
	ldr r1, [r4]
	ldr r0, [r4, #8]
	adds r3, r1, r0
	str r3, [r4]
	ldr r1, [r4, #4]
	ldr r0, [r4, #0xc]
	adds r2, r1, r0
	str r2, [r4, #4]
	adds r0, #0x40
	str r0, [r4, #0xc]
	ldrh r0, [r4, #0x14]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807ED72
	lsls r1, r3, #8
	asrs r1, r1, #0x10
	lsls r2, r2, #8
	asrs r2, r2, #0x10
	movs r3, #0xc0
	lsls r3, r3, #2
	str r5, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	str r5, [sp, #8]
	ldr r0, [r6, #0x18]
	str r0, [sp, #0xc]
	movs r0, #7
	bl sub_8079758
_0807ED72:
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	movs r1, #0x96
	lsls r1, r1, #9
	cmp r0, r1
	ble _0807ED84
	movs r0, #0xfa
	lsls r0, r0, #2
_0807ED82:
	strh r0, [r4, #0x16]
_0807ED84:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

.syntax divided
