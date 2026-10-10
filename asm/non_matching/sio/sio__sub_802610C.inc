.syntax unified
.text
	push {lr}
	ldr r0, _0802612C @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	ldr r1, _08026130 @ =gStageData
	ldrb r1, [r1, #6]
	cmp r1, r0
	bne _08026134
	adds r0, r1, #0
	bl sub_8025E24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _08026138
	.align 2, 0
_0802612C: .4byte 0x04000128
_08026130: .4byte gStageData
_08026134:
	movs r0, #1
	rsbs r0, r0, #0
_08026138:
	pop {r1}
	bx r1

.syntax divided
