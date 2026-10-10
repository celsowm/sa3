.syntax unified
.text
	push {r4, r5, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r1, #2
	adds r3, r3, r1
	lsls r3, r3, #3
	movs r4, #0xa6
	lsls r4, r4, #1
	adds r1, r0, r4
	adds r1, r1, r3
	movs r4, #0
	str r4, [r1]
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r1, r0, r5
	adds r1, r1, r3
	str r4, [r1]
	adds r0, r0, r3
	mov ip, r0
	movs r1, #0xac
	lsls r1, r1, #1
	add r1, ip
	movs r3, #0
	movs r5, #1
	movs r0, #1
	strh r0, [r1]
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, ip
	strh r4, [r0]
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, ip
	strb r2, [r0]
	ldr r0, _0807DB58 @ =0x0000015D
	add r0, ip
	strb r3, [r0]
	ldr r0, _0807DB5C @ =0x00000157
	add r0, ip
	strb r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807DB58: .4byte 0x0000015D
_0807DB5C: .4byte 0x00000157

.syntax divided
