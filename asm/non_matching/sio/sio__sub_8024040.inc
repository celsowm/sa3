.syntax unified
.text
	push {r4, lr}
	bl sub_8025D58
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_8024304
	ldr r1, _08024064 @ =gUnknown_03001060
	movs r0, #0
	strb r0, [r1, #7]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08024064: .4byte gUnknown_03001060

.syntax divided
