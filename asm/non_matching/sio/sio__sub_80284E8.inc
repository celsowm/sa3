.syntax unified
.text
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r2, _08028520 @ =0x04000208
	movs r5, #0
	strh r5, [r2]
	ldr r1, _08028524 @ =gIntrTable
	ldr r0, _08028528 @ =gMultiSioIntrFuncBuf
	str r0, [r1]
	movs r0, #1
	strh r0, [r2]
	ldr r6, _0802852C @ =gMultiSioStatusFlags
	ldr r0, [r6]
	movs r1, #0xf0
	lsls r1, r1, #4
	ands r0, r1
	lsrs r0, r0, #8
	bl MultiSioInit
	adds r1, r4, #0
	adds r1, #0xdd
	movs r0, #0
	strb r5, [r1]
	adds r4, #0xdf
	strb r5, [r4]
	str r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028520: .4byte 0x04000208
_08028524: .4byte gIntrTable
_08028528: .4byte gMultiSioIntrFuncBuf
_0802852C: .4byte gMultiSioStatusFlags

.syntax divided
