.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r0, _080A0EDC @ =gUnknown_080D8F18
	ldrb r1, [r7, #1]
	adds r1, r1, r0
	ldrb r1, [r1]
	ldr r4, _080A0EE0 @ =gFlags
	ldr r3, [r4]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r3
	cmp r0, #0
	beq _080A0EE8
	lsls r0, r1, #5
	ldr r1, _080A0EE4 @ =gUnknown_08E2EE50
	adds r0, r0, r1
	movs r1, #0x70
	movs r2, #0x10
	bl CopyObjPaletteMasked
	b _080A0F02
	.align 2, 0
_080A0EDC: .4byte gUnknown_080D8F18
_080A0EE0: .4byte gFlags
_080A0EE4: .4byte gUnknown_08E2EE50
_080A0EE8:
	ldr r2, _080A0FDC @ =0x040000D4
	lsls r0, r1, #5
	ldr r1, _080A0FE0 @ =gUnknown_08E2EE50
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080A0FE4 @ =gObjPalette + 0xE0
	str r0, [r2, #4]
	ldr r0, _080A0FE8 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #2
	orrs r3, r0
	str r3, [r4]
_080A0F02:
	ldr r2, _080A0FEC @ =gFlags
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A0FF0 @ =gDispCnt
	ldr r2, _080A0FF4 @ =0x00001741
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080A0FF8 @ =gBgSprites_Unknown1
	movs r4, #0
	strb r4, [r0, #1]
	ldr r1, _080A0FFC @ =gBgSprites_Unknown2
	strb r4, [r1, #4]
	strb r4, [r1, #5]
	movs r0, #0xff
	strb r0, [r1, #6]
	movs r0, #0x40
	strb r0, [r1, #7]
	ldr r0, _080A1000 @ =gBgCntRegs
	mov sl, r0
	ldr r0, _080A1004 @ =0x0000030E
	mov r1, sl
	strh r0, [r1, #2]
	ldr r6, _080A1008 @ =gBgScrollRegs
	strh r4, [r6, #4]
	strh r4, [r6, #6]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, _080A100C @ =gUnknown_080D8F18
	mov r8, r1
	ldrb r1, [r7, #2]
	add r1, r8
	ldrb r1, [r1]
	ldr r2, _080A1010 @ =0x0600C000
	str r2, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r2, _080A1014 @ =0x06001800
	str r2, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	ldr r2, _080A1018 @ =gCharSelect3_Tilemaps
	mov sb, r2
	adds r1, #0xa
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	movs r5, #0x10
	strh r5, [r0, #0x26]
	strh r5, [r0, #0x28]
	ldr r2, _080A101C @ =0x0000025E
	adds r1, r7, r2
	movs r2, #0
	strb r2, [r1]
	movs r1, #1
	strh r1, [r0, #0x2e]
	bl DrawBackground
	ldr r0, _080A1020 @ =0x00001B89
	mov r1, sl
	strh r0, [r1, #4]
	strh r4, [r6, #8]
	strh r4, [r6, #0xa]
	movs r2, #0x9d
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r1, [r7, #1]
	add r1, r8
	ldrb r1, [r1]
	ldr r2, _080A1024 @ =0x06008000
	str r2, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r2, _080A1028 @ =0x0600D800
	str r2, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	adds r1, #5
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	strh r5, [r0, #0x26]
	strh r5, [r0, #0x28]
	ldr r2, _080A102C @ =0x0000029E
	adds r1, r7, r2
	movs r2, #0
	strb r2, [r1]
	movs r1, #6
	strh r1, [r0, #0x2e]
	bl DrawBackground
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0FDC: .4byte 0x040000D4
_080A0FE0: .4byte gUnknown_08E2EE50
_080A0FE4: .4byte gObjPalette + 0xE0
_080A0FE8: .4byte 0x80000010
_080A0FEC: .4byte gFlags
_080A0FF0: .4byte gDispCnt
_080A0FF4: .4byte 0x00001741
_080A0FF8: .4byte gBgSprites_Unknown1
_080A0FFC: .4byte gBgSprites_Unknown2
_080A1000: .4byte gBgCntRegs
_080A1004: .4byte 0x0000030E
_080A1008: .4byte gBgScrollRegs
_080A100C: .4byte gUnknown_080D8F18
_080A1010: .4byte 0x0600C000
_080A1014: .4byte 0x06001800
_080A1018: .4byte gCharSelect3_Tilemaps
_080A101C: .4byte 0x0000025E
_080A1020: .4byte 0x00001B89
_080A1024: .4byte 0x06008000
_080A1028: .4byte 0x0600D800
_080A102C: .4byte 0x0000029E

.syntax divided
