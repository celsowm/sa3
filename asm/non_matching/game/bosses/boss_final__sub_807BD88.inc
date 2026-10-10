.syntax unified
.text
	push {r4, r5, r6, lr}
	mov ip, r0
	movs r3, #0x97
	lsls r3, r3, #1
	add r3, ip
	ldrh r0, [r3]
	cmp r0, #0xa
	beq _0807BDA2
	cmp r0, #0xa
	ble _0807BE1A
	cmp r0, #0x14
	beq _0807BDFC
	b _0807BE1A
_0807BDA2:
	movs r5, #0x8e
	lsls r5, r5, #1
	add r5, ip
	movs r4, #0x92
	lsls r4, r4, #1
	add r4, ip
	ldr r2, _0807BDF8 @ =gUnknown_080D5C80
	movs r3, #0x96
	lsls r3, r3, #1
	add r3, ip
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r5]
	movs r5, #0x90
	lsls r5, r5, #1
	add r5, ip
	movs r4, #0x94
	lsls r4, r4, #1
	add r4, ip
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r5]
	ldrh r0, [r3]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	b _0807BE18
	.align 2, 0
_0807BDF8: .4byte gUnknown_080D5C80
_0807BDFC:
	movs r2, #0x90
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0x94
	lsls r1, r1, #1
	add r1, ip
	ldr r0, [r2]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0807BE4C @ =0x00015FFF
	cmp r0, r1
	ble _0807BE1A
	movs r0, #0
_0807BE18:
	strh r0, [r3]
_0807BE1A:
	ldr r4, _0807BE50 @ =gBgScrollRegs
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r3, _0807BE54 @ =gCamera
	ldr r1, [r3]
	subs r0, r0, r1
	movs r2, #0x80
	subs r0, r2, r0
	strh r0, [r4]
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r3, #4]
	subs r0, r0, r1
	subs r2, r2, r0
	strh r2, [r4, #2]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807BE4C: .4byte 0x00015FFF
_0807BE50: .4byte gBgScrollRegs
_0807BE54: .4byte gCamera

.syntax divided
