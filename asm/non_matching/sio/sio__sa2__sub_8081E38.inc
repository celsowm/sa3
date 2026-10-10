.syntax unified
.text
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	adds r4, r2, #0
	adds r1, r2, #0
	adds r1, #8
	movs r3, #1
	adds r0, r3, #0
	lsls r0, r1
	ldr r1, _08028628 @ =gMultiSioStatusFlags
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08028638
	adds r0, r3, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _08028630
	ldr r0, _0802862C @ =gUnknown_03001060
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r2, r1, #1
	strb r2, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0xb4
	bls _08028638
	movs r0, #0
	b _0802863A
	.align 2, 0
_08028628: .4byte gMultiSioStatusFlags
_0802862C: .4byte gUnknown_03001060
_08028630:
	ldr r0, _08028640 @ =gUnknown_03001060
	adds r0, r4, r0
	movs r1, #0
	strb r1, [r0]
_08028638:
	movs r0, #1
_0802863A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08028640: .4byte gUnknown_03001060

.syntax divided
