.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08081BCE
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _08081BD0
_08081BCE:
	movs r1, #0
_08081BD0:
	ldr r0, _08081BE4 @ =gUnknown_080D5C48
	adds r0, r1, r0
	ldrb r0, [r0]
	movs r1, #0
	strh r0, [r2, #8]
	strh r1, [r2, #0xc]
	movs r0, #5
	strb r0, [r2, #1]
	pop {r0}
	bx r0
	.align 2, 0
_08081BE4: .4byte gUnknown_080D5C48

.syntax divided
