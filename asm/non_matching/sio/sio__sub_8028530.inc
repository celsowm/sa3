.syntax unified
.text
	push {lr}
	ldr r0, _08028550 @ =gMultiBootParam
	bl MultiBootMain
	cmp r0, #0x50
	beq _08028548
	cmp r0, #0x60
	beq _08028548
	cmp r0, #0x70
	beq _08028548
	cmp r0, #0x71
	bne _08028554
_08028548:
	bl sub_802613C
	movs r0, #1
	b _08028556
	.align 2, 0
_08028550: .4byte gMultiBootParam
_08028554:
	movs r0, #0
_08028556:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
