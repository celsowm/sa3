.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r2, #0
	movs r7, #0xed
	lsls r7, r7, #2
	movs r6, #0
	ldr r3, _08087094 @ =0x000004FE
	movs r5, #1
_08087080:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r7
	adds r0, r4, r0
	cmp r1, #0
	bne _08087098
	strh r3, [r0, #0xc]
	strb r5, [r0, #0x1a]
	b _0808709C
	.align 2, 0
_08087094: .4byte 0x000004FE
_08087098:
	strh r3, [r0, #0xc]
	strb r6, [r0, #0x1a]
_0808709C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08087080
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
