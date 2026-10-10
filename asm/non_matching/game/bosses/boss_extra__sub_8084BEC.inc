.syntax unified
.text
	push {r4, lr}
	adds r3, r0, #0
	ldrh r1, [r3, #8]
	cmp r1, #0
	bne _08084C2E
	movs r0, #1
	strh r0, [r3, #4]
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r3, #8]
	ldr r4, _08084C3C @ =gDispCnt
	ldrh r2, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _08084C2E
	ldr r0, _08084C40 @ =0x0000DEFF
	ands r0, r2
	strh r0, [r4]
	ldr r0, _08084C44 @ =gWinRegs
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	ldr r0, _08084C48 @ =gBldRegs
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	ldr r2, _08084C4C @ =gFlags
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_08084C2E:
	ldrb r1, [r3, #0xd]
	adds r0, r3, #0
	bl sub_8082E2C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08084C3C: .4byte gDispCnt
_08084C40: .4byte 0x0000DEFF
_08084C44: .4byte gWinRegs
_08084C48: .4byte gBldRegs
_08084C4C: .4byte gFlags

.syntax divided
