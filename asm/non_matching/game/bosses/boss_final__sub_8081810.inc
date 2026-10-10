.syntax unified
.text
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0
	ldr r0, _08081834 @ =0x00000125
	strh r0, [r4, #0x30]
	strh r1, [r4, #0x18]
	strh r1, [r4, #0x1a]
	ldr r5, _08081838 @ =sub_808183C
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetPlayerCallback
	adds r0, r4, #0
	bl _call_via_r5
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081834: .4byte 0x00000125
_08081838: .4byte sub_808183C

.syntax divided
