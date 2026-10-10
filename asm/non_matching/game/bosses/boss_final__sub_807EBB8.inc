.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r5, r7, r0
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r0, r0, r2
	adds r2, r7, r0
	ldrh r0, [r5, #0x16]
	cmp r0, #0xa
	beq _0807EC98
	cmp r0, #0xa
	bgt _0807EBEE
	cmp r0, #0
	beq _0807EBF4
	b _0807ECEE
_0807EBEE:
	cmp r0, #0x14
	beq _0807ECBC
	b _0807ECEE
_0807EBF4:
	cmp r6, #0
	bne _0807EC08
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r3, _0807EC04 @ =0x00000614
	adds r1, r3, #0
	b _0807EC10
	.align 2, 0
_0807EC04: .4byte 0x00000614
_0807EC08:
	ldr r0, [r5]
	asrs r0, r0, #8
	ldr r2, _0807EC64 @ =0x000006DC
	adds r1, r2, #0
_0807EC10:
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807EC68 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r0, [r5, #4]
	asrs r0, r0, #8
	movs r1, #0x98
	subs r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0807EC6C @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, _0807EC68 @ =0xFFFF0000
	mov r4, sp
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #8
	bl sa2__sub_8085A9C
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	str r0, [r5, #8]
	movs r1, #2
	ldrsh r0, [r4, r1]
	lsls r0, r0, #1
	str r0, [r5, #0xc]
	cmp r6, #0
	beq _0807EC70
	cmp r6, #1
	beq _0807EC80
	b _0807EC90
	.align 2, 0
_0807EC64: .4byte 0x000006DC
_0807EC68: .4byte 0xFFFF0000
_0807EC6C: .4byte 0x0000FFFF
_0807EC70:
	movs r3, #0x9e
	lsls r3, r3, #2
	adds r2, r7, r3
	ldr r0, _0807EC7C @ =sBossFinalAnimsHands
	b _0807EC88
	.align 2, 0
_0807EC7C: .4byte sBossFinalAnimsHands
_0807EC80:
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, _0807EC94 @ =sBossFinalAnimsHands+0x18
_0807EC88:
	ldrh r1, [r0, #0x14]
	strh r1, [r2, #0xc]
	ldrh r0, [r0, #0x16]
	strb r0, [r2, #0x1a]
_0807EC90:
	movs r0, #0xa
	b _0807ECEC
	.align 2, 0
_0807EC94: .4byte sBossFinalAnimsHands+0x18
_0807EC98:
	cmp r6, #0
	bne _0807ECA2
	ldrh r0, [r2]
	adds r0, #8
	b _0807ECA6
_0807ECA2:
	ldrh r0, [r2]
	subs r0, #8
_0807ECA6:
	ldr r3, _0807ECB8 @ =0x000003FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, #0
	bne _0807ECEE
	movs r0, #0x14
	b _0807ECEC
	.align 2, 0
_0807ECB8: .4byte 0x000003FF
_0807ECBC:
	ldr r1, [r5]
	ldr r0, [r5, #8]
	adds r2, r1, r0
	str r2, [r5]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0xc]
	adds r0, r0, r1
	str r0, [r5, #4]
	cmp r6, #0
	bne _0807ECE4
	ldr r0, _0807ECE0 @ =0x00061400
	cmp r2, r0
	bgt _0807ECEE
	movs r0, #0x1e
	strh r0, [r5, #0x16]
	movs r0, #0x64
	strh r0, [r7, #0xc]
	b _0807ECEE
	.align 2, 0
_0807ECE0: .4byte 0x00061400
_0807ECE4:
	ldr r0, _0807ECF8 @ =0x0006DBFF
	cmp r2, r0
	ble _0807ECEE
	movs r0, #0x1e
_0807ECEC:
	strh r0, [r5, #0x16]
_0807ECEE:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807ECF8: .4byte 0x0006DBFF

.syntax divided
