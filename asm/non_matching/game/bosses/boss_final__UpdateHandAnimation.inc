.syntax unified
.text
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r1, #0
	beq _08081AE8
	cmp r1, #1
	beq _08081AF8
	b _08081B10
_08081AE8:
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, _08081AF4 @ =sBossFinalAnimsHands
	b _08081B00
	.align 2, 0
_08081AF4: .4byte sBossFinalAnimsHands
_08081AF8:
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, _08081B14 @ =sBossFinalAnimsHands+0x18
_08081B00:
	lsls r2, r2, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	strh r0, [r3, #0xc]
	adds r1, #2
	adds r2, r2, r1
	ldrh r0, [r2]
	strb r0, [r3, #0x1a]
_08081B10:
	pop {r0}
	bx r0
	.align 2, 0
_08081B14: .4byte sBossFinalAnimsHands+0x18

.syntax divided
