.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sb, r2
	movs r7, #0
	movs r2, #0
	movs r1, #0xca
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r3, #0xd5
	lsls r3, r3, #1
	mov r8, r3
	movs r6, #0x80
	mov ip, r6
	movs r0, #0x80
	lsls r0, r0, #2
	mov sl, r0
_0807D640:
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r3, r0, #2
	ldr r6, [sp]
	adds r1, r6, r3
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807D6A4
	mov r0, sb
	cmp r0, #0
	bne _0807D680
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, r5
	bgt _0807D6A4
	mov r3, r8
	adds r0, r1, r3
	ldrh r0, [r0]
	subs r6, #0xac
	cmp r0, r6
	bls _0807D6A4
	ldr r1, _0807D67C @ =0x000002FF
	cmp r0, r1
	bhi _0807D6A4
	mov r7, ip
	orrs r7, r2
	b _0807D6A2
	.align 2, 0
_0807D67C: .4byte 0x000002FF
_0807D680:
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, r5
	blt _0807D6A4
	add r1, r8
	ldr r3, _0807D6C0 @ =0xFFFFFF00
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, sl
	bls _0807D6A4
	mov r6, ip
	orrs r2, r6
	lsls r0, r2, #0x18
	lsrs r7, r0, #0x18
_0807D6A2:
	movs r2, #3
_0807D6A4:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #2
	bls _0807D640
	adds r0, r7, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807D6C0: .4byte 0xFFFFFF00

.syntax divided
