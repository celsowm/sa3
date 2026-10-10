.syntax unified
.text
	push {r4, r5, lr}
	movs r2, #1
	movs r1, #1
	ldr r4, _0802859C @ =gMultiBootParam
	ldrb r5, [r4, #0x1d]
	movs r3, #1
_08028568:
	adds r0, r5, #0
	asrs r0, r1
	ands r0, r3
	cmp r0, #0
	beq _08028586
	ldrb r0, [r4, #0x1e]
	asrs r0, r1
	ands r0, r3
	cmp r0, #0
	beq _08028586
	lsls r0, r2, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r0, r0, r2
	lsrs r2, r0, #0x18
_08028586:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _08028568
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802859C: .4byte gMultiBootParam

.syntax divided
