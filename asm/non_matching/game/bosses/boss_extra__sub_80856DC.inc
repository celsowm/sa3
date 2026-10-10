.syntax unified
.text
	push {r4, r5, r6, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0
	ldr r0, _0808570C @ =gBgOffsetsHBlankPrimary
	ldr r0, [r0]
	ldr r4, _08085710 @ =gBgOffsetsBuffer
	cmp r0, r4
	bne _0808571C
	add r0, sp, #8
	strh r1, [r0]
	ldr r0, _08085714 @ =0x040000D4
	add r1, sp, #8
	str r1, [r0]
	str r4, [r0, #4]
	ldr r1, _08085718 @ =0x81000140
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	b _08085732
	.align 2, 0
_0808570C: .4byte gBgOffsetsHBlankPrimary
_08085710: .4byte gBgOffsetsBuffer
_08085714: .4byte 0x040000D4
_08085718: .4byte 0x81000140
_0808571C:
	add r0, sp, #8
	strh r1, [r0]
	ldr r1, _0808577C @ =0x040000D4
	str r0, [r1]
	movs r6, #0xa0
	lsls r6, r6, #2
	adds r0, r4, r6
	str r0, [r1, #4]
	ldr r0, _08085780 @ =0x81000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08085732:
	cmp r2, #0
	bne _08085738
	movs r2, #1
_08085738:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsls r5, r2, #0x10
	asrs r2, r5, #0x10
	subs r0, r4, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge _0808574C
	movs r1, #0
_0808574C:
	adds r0, r4, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa0
	ble _0808575A
	movs r2, #0xa0
_0808575A:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	str r4, [sp]
	lsrs r0, r5, #0x10
	str r0, [sp, #4]
	movs r0, #0
	bl sa2__sub_80075D0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808577C: .4byte 0x040000D4
_08085780: .4byte 0x81000140

.syntax divided
