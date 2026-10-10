.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _0807CD28 @ =gCamera
	mov r8, r0
_0807CCB6:
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r2, r0, #2
	adds r3, r6, r2
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807CD38
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r0, r4
	adds r5, r6, r0
	subs r1, #0x18
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	mov r4, r8
	ldr r1, [r4]
	subs r0, r0, r1
	strh r0, [r5, #0x10]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	movs r2, #0xd7
	lsls r2, r2, #1
	adds r4, r3, r2
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _0807CD2C
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807CD20
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
_0807CD20:
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _0807CD38
	.align 2, 0
_0807CD28: .4byte gCamera
_0807CD2C:
	adds r0, r5, #0
	bl UpdateSpriteAnimation
	adds r0, r5, #0
	bl DisplaySprite
_0807CD38:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #2
	bls _0807CCB6
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

.syntax divided
