.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, _080A0E48 @ =gUnknown_080D8F18
	ldrb r1, [r4, #1]
	adds r1, r1, r2
	ldrb r6, [r1]
	adds r7, r6, #0
	movs r5, #0
	ldr r1, _080A0E4C @ =0x06008000
	str r1, [r0, #4]
	movs r3, #0
	strh r5, [r0, #0xa]
	ldr r1, _080A0E50 @ =0x0600D800
	str r1, [r0, #0xc]
	strh r5, [r0, #0x18]
	strh r5, [r0, #0x1a]
	ldr r2, _080A0E54 @ =gUnknown_080D8CDC
	adds r1, r6, #5
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	strh r1, [r0, #0x1c]
	strh r5, [r0, #0x1e]
	strh r5, [r0, #0x20]
	strh r5, [r0, #0x22]
	strh r5, [r0, #0x24]
	movs r1, #0x10
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x28]
	ldr r2, _080A0E58 @ =0x0000029E
	adds r1, r4, r2
	strb r3, [r1]
	movs r1, #6
	strh r1, [r0, #0x2e]
	bl DrawBackground
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r4, #0x50]
	ldr r0, [r4, #0x18]
	ldrb r0, [r0]
	movs r5, #7
	cmp r0, #0xb
	bhi _080A0E28
	movs r5, #6
_080A0E28:
	ldr r4, _080A0E5C @ =gFlags
	ldr r3, [r4]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r3
	cmp r0, #0
	beq _080A0E64
	lsls r0, r6, #5
	ldr r1, _080A0E60 @ =gUnknown_08E2EE50
	adds r0, r0, r1
	lsls r1, r5, #4
	movs r2, #0x10
	bl CopyObjPaletteMasked
	b _080A0E82
	.align 2, 0
_080A0E48: .4byte gUnknown_080D8F18
_080A0E4C: .4byte 0x06008000
_080A0E50: .4byte 0x0600D800
_080A0E54: .4byte gUnknown_080D8CDC
_080A0E58: .4byte 0x0000029E
_080A0E5C: .4byte gFlags
_080A0E60: .4byte gUnknown_08E2EE50
_080A0E64:
	ldr r2, _080A0E94 @ =0x040000D4
	lsls r0, r7, #5
	ldr r1, _080A0E98 @ =gUnknown_08E2EE50
	adds r0, r0, r1
	str r0, [r2]
	lsls r0, r5, #5
	ldr r1, _080A0E9C @ =gObjPalette
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _080A0EA0 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #2
	orrs r3, r0
	str r3, [r4]
_080A0E82:
	ldr r0, _080A0EA4 @ =gFlags
	ldr r1, [r0]
	movs r2, #2
	orrs r1, r2
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0E94: .4byte 0x040000D4
_080A0E98: .4byte gUnknown_08E2EE50
_080A0E9C: .4byte gObjPalette
_080A0EA0: .4byte 0x80000010
_080A0EA4: .4byte gFlags

.syntax divided
