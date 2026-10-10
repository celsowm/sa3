.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	movs r1, #0
	ldr r0, _08085648 @ =gBgOffsetsHBlankPrimary
	ldr r0, [r0]
	ldr r2, _0808564C @ =gBgOffsetsBuffer
	cmp r0, r2
	bne _08085658
	add r0, sp, #4
	strh r1, [r0]
	ldr r0, _08085650 @ =0x040000D4
	add r1, sp, #4
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _08085654 @ =0x81000140
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	b _0808566E
	.align 2, 0
_08085648: .4byte gBgOffsetsHBlankPrimary
_0808564C: .4byte gBgOffsetsBuffer
_08085650: .4byte 0x040000D4
_08085654: .4byte 0x81000140
_08085658:
	add r0, sp, #4
	strh r1, [r0]
	ldr r1, _080856B0 @ =0x040000D4
	str r0, [r1]
	movs r6, #0xa0
	lsls r6, r6, #2
	adds r0, r2, r6
	str r0, [r1, #4]
	ldr r0, _080856B4 @ =0x81000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0808566E:
	cmp r4, #0
	bne _08085674
	movs r4, #1
_08085674:
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	subs r0, r3, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge _08085688
	movs r2, #0
_08085688:
	adds r0, r3, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa0
	ble _08085696
	movs r1, #0xa0
_08085696:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	bgt _080856A4
	lsls r0, r1, #0x10
	cmp r0, #0
	bgt _080856BC
_080856A4:
	ldr r0, _080856B8 @ =gFlags
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
	b _080856D2
	.align 2, 0
_080856B0: .4byte 0x040000D4
_080856B4: .4byte 0x81000140
_080856B8: .4byte gFlags
_080856BC:
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r5, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl sa2__sub_8007A08
_080856D2:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
