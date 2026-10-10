.syntax unified
.text
	push {lr}
	bl sub_802610C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _08025B72
	bl sub_8025D48
	ldr r0, _08025B68 @ =gMultiSioRecv
	ldrh r1, [r0]
	ldr r0, _08025B6C @ =0x0000660F
	cmp r1, r0
	bhi _08025B70
	movs r0, #0
	b _08025B72
	.align 2, 0
_08025B68: .4byte gMultiSioRecv
_08025B6C: .4byte 0x0000660F
_08025B70:
	movs r0, #1
_08025B72:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
