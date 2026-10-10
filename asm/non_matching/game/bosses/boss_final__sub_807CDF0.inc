.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0
	mov ip, r0
_0807CDFC:
	mov r2, ip
	lsls r1, r2, #3
	subs r0, r1, r2
	lsls r6, r0, #2
	adds r2, r5, r6
	movs r7, #0xd6
	lsls r7, r7, #1
	adds r3, r2, r7
	ldrh r4, [r3]
	adds r7, r1, #0
	cmp r4, #0
	beq _0807CE16
	b _0807CF86
_0807CE16:
	movs r0, #1
	strh r0, [r3]
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r4, [r0]
	movs r3, #0xd7
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0x1e
	strh r0, [r1]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r1, r1, r6
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [r1]
	subs r3, #0x16
	adds r1, r5, r3
	adds r1, r1, r6
	adds r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r3, _0807CE78 @ =0xFFFFE000
	adds r0, r0, r3
	str r0, [r1]
	ldr r2, _0807CE7C @ =gPseudoRandom
	ldr r1, [r2]
	ldr r0, _0807CE80 @ =0x00196225
	muls r0, r1, r0
	ldr r1, _0807CE84 @ =0x3C6EF35F
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0807CE88 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsrs r0, r0, #0x17
	cmp r0, #7
	bhi _0807CEE4
	lsls r0, r0, #2
	ldr r1, _0807CE8C @ =_0807CE90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807CE78: .4byte 0xFFFFE000
_0807CE7C: .4byte gPseudoRandom
_0807CE80: .4byte 0x00196225
_0807CE84: .4byte 0x3C6EF35F
_0807CE88: .4byte 0x000003FF
_0807CE8C: .4byte _0807CE90
_0807CE90: @ jump table
	.4byte _0807CEB0 @ case 0
	.4byte _0807CEC2 @ case 1
	.4byte _0807CED0 @ case 2
	.4byte _0807CEB0 @ case 3
	.4byte _0807CEB0 @ case 4
	.4byte _0807CEC2 @ case 5
	.4byte _0807CED0 @ case 6
	.4byte _0807CEB0 @ case 7
_0807CEB0:
	mov r3, ip
	subs r0, r7, r3
	lsls r0, r0, #2
	adds r0, r5, r0
	movs r1, #0xd5
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	b _0807CEE4
_0807CEC2:
	mov r3, ip
	subs r0, r7, r3
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r1, r2, #0
	subs r1, #0x80
	b _0807CEDC
_0807CED0:
	mov r3, ip
	subs r0, r7, r3
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r1, r2, #0
	adds r1, #0x80
_0807CEDC:
	movs r2, #0xd5
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
_0807CEE4:
	mov r3, ip
	subs r0, r7, r3
	lsls r2, r0, #2
	movs r7, #0xd2
	lsls r7, r7, #1
	adds r0, r5, r7
	adds r6, r0, r2
	ldr r1, _0807CFA0 @ =gUnknown_080D5C50
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	str r1, [r6]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r4, r0, r2
	ldr r7, _0807CFA4 @ =gSineTable
	mov r8, r7
	adds r0, r5, r2
	movs r7, #0xd5
	lsls r7, r7, #1
	adds r3, r0, r7
	ldrh r0, [r3]
	subs r7, #0xaa
	adds r0, r0, r7
	lsls r0, r0, #1
	add r0, r8
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r1, r0
	cmp r0, #0
	bge _0807CF2A
	ldr r1, _0807CFA8 @ =0x00003FFF
	adds r0, r0, r1
_0807CF2A:
	asrs r0, r0, #0xe
	str r0, [r4]
	movs r7, #0xd0
	lsls r7, r7, #1
	adds r0, r5, r7
	adds r2, r0, r2
	ldrh r0, [r3]
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r6]
	muls r0, r1, r0
	cmp r0, #0
	bge _0807CF4C
	ldr r7, _0807CFA8 @ =0x00003FFF
	adds r0, r0, r7
_0807CF4C:
	asrs r0, r0, #0xe
	str r0, [r2]
	mov r1, ip
	lsls r0, r1, #2
	add r0, ip
	lsls r0, r0, #3
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	adds r0, r5, r0
	movs r4, #0
	movs r1, #0x9e
	lsls r1, r1, #3
	strh r1, [r0, #0xc]
	strb r4, [r0, #0x1a]
	movs r0, #0x8e
	lsls r0, r0, #2
	bl m4aSongNumStart
	ldrb r0, [r5, #0x10]
	adds r0, #1
	strb r0, [r5, #0x10]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0807CF82
	strb r4, [r5, #0x10]
_0807CF82:
	movs r3, #3
	mov ip, r3
_0807CF86:
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #2
	bhi _0807CF96
	b _0807CDFC
_0807CF96:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807CFA0: .4byte gUnknown_080D5C50
_0807CFA4: .4byte gSineTable
_0807CFA8: .4byte 0x00003FFF

.syntax divided
