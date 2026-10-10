.syntax unified
.text
	push {r4, lr}
	mov ip, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, [r0, #0x34]
	movs r4, #2
	orrs r0, r4
	mov r4, ip
	str r0, [r4, #0x34]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x10
	lsrs r1, r1, #0x1f
	adds r4, r4, r1
	asrs r4, r4, #1
	mov r0, ip
	str r4, [r0, #0x48]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	str r2, [r0, #0x4c]
	rsbs r1, r4, #0
	adds r0, #0x3c
	strb r1, [r0]
	rsbs r0, r3, #0
	mov r1, ip
	adds r1, #0x3d
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x3e
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0

.syntax divided
