.syntax unified
.text
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
	movs r0, #0x96
	strh r0, [r4, #0x30]
	ldr r5, _08081868 @ =PlayerCB_8081894
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetPlayerCallback
	adds r0, r4, #0
	bl _call_via_r5
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081868: .4byte PlayerCB_8081894

.syntax divided
