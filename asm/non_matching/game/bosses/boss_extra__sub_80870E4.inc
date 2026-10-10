.syntax unified
.text
	push {lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0808710C @ =gBgOffsetsHBlankPrimary
	ldr r0, [r0]
	ldr r2, _08087110 @ =gBgOffsetsBuffer
	cmp r0, r2
	bne _0808711C
	mov r0, sp
	strh r1, [r0]
	ldr r0, _08087114 @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _08087118 @ =0x81000140
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	b _08087132
	.align 2, 0
_0808710C: .4byte gBgOffsetsHBlankPrimary
_08087110: .4byte gBgOffsetsBuffer
_08087114: .4byte 0x040000D4
_08087118: .4byte 0x81000140
_0808711C:
	mov r0, sp
	strh r1, [r0]
	ldr r1, _08087138 @ =0x040000D4
	str r0, [r1]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r0, r2, r3
	str r0, [r1, #4]
	ldr r0, _0808713C @ =0x81000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08087132:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08087138: .4byte 0x040000D4
_0808713C: .4byte 0x81000140

.syntax divided
