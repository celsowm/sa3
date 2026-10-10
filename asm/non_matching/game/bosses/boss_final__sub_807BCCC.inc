.syntax unified
.text
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov ip, r0
	movs r0, #0xf4
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x92
	lsls r1, r1, #1
	add r1, ip
	movs r4, #0
	str r4, [r1]
	movs r1, #0x94
	lsls r1, r1, #1
	add r1, ip
	str r4, [r1]
	movs r2, #0x96
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0
	mov r8, r1
	movs r1, #1
	strh r1, [r2]
	movs r1, #0x97
	lsls r1, r1, #1
	add r1, ip
	strh r4, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0xcf
	lsls r1, r1, #0xb
	str r1, [r2]
	movs r1, #0x90
	lsls r1, r1, #1
	add r1, ip
	movs r3, #0xb0
	lsls r3, r3, #9
	str r3, [r1]
	ldr r6, _0807BD70 @ =gBgScrollRegs
	ldr r1, [r2]
	asrs r1, r1, #8
	ldr r5, _0807BD74 @ =gCamera
	ldr r2, [r5]
	subs r1, r1, r2
	movs r2, #0x80
	subs r1, r2, r1
	strh r1, [r6]
	asrs r3, r3, #8
	ldr r1, [r5, #4]
	subs r3, r3, r1
	subs r2, r2, r3
	strh r2, [r6, #2]
	ldr r1, _0807BD78 @ =0x0600C000
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _0807BD7C @ =0x0600D800
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	ldr r1, _0807BD80 @ =0x000001D3
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	movs r1, #0x20
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	ldr r1, _0807BD84 @ =0x00000212
	add r1, ip
	mov r2, r8
	strb r2, [r1]
	strh r4, [r0, #0x2e]
	bl DrawBackground
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807BD70: .4byte gBgScrollRegs
_0807BD74: .4byte gCamera
_0807BD78: .4byte 0x0600C000
_0807BD7C: .4byte 0x0600D800
_0807BD80: .4byte 0x000001D3
_0807BD84: .4byte 0x00000212

.syntax divided
