.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	ldr r0, [r2, #0x54]
	cmp r0, r1
	bge _080A175A
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r0, r3
	str r0, [r2, #0x54]
	cmp r0, r1
	ble _080A1760
_080A175A:
	str r1, [r2, #0x54]
	movs r0, #1
	b _080A1762
_080A1760:
	movs r0, #0
_080A1762:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
