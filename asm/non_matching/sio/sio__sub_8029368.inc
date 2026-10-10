.syntax unified
.text
	push {r4, r5, lr}
	movs r2, #0
	ldr r0, _08029398 @ =gUnknown_03001060
	ldrb r4, [r0, #7]
	ldr r5, _0802939C @ =0x000060FF
_08029372:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	adds r1, r4, #0
	asrs r1, r3
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080293A4
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	ldr r1, _080293A0 @ =gMultiSioRecv
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	bne _080293A4
	movs r0, #1
	b _080293B4
	.align 2, 0
_08029398: .4byte gUnknown_03001060
_0802939C: .4byte 0x000060FF
_080293A0: .4byte gMultiSioRecv
_080293A4:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08029372
	movs r0, #0
_080293B4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
    
.if 0
.endif

.syntax divided
