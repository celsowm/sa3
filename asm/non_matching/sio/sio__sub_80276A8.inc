.syntax unified
.text
	push {lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r1, sp
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #6
	strb r0, [r1, #1]
	ldr r0, _080276D8 @ =gStageData
	ldrb r1, [r0, #6]
	adds r2, r0, #0
	cmp r1, #0
	bne _080276DC
	adds r0, #0xae
	ldrh r0, [r0]
	cmp r0, #0
	bne _080276DC
	mov r0, sp
	adds r1, r2, #0
	adds r1, #0x8e
	ldrb r1, [r1]
	strb r1, [r0, #2]
	b _080276E6
	.align 2, 0
_080276D8: .4byte gStageData
_080276DC:
	mov r0, sp
	strb r3, [r0, #2]
	adds r0, r2, #0
	adds r0, #0x8e
	strb r3, [r0]
_080276E6:
	mov r0, sp
	bl sub_8026AB8
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
