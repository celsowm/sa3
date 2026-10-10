.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r0, _0809FCC0 @ =gBgCntRegs
	mov sl, r0
	movs r7, #0
	movs r4, #0
	ldr r0, _0809FCC4 @ =0x00004E07
	mov r1, sl
	strh r0, [r1]
	ldr r2, _0809FCC8 @ =gBgScrollRegs
	mov r8, r2
	strh r4, [r2]
	strh r4, [r2, #2]
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _0809FCCC @ =0x06004000
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _0809FCD0 @ =0x06007000
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	ldr r2, _0809FCD4 @ =gUnknown_080D8CDC
	mov sb, r2
	ldrh r1, [r2]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	movs r1, #0x2d
	strh r1, [r0, #0x26]
	movs r1, #0x14
	strh r1, [r0, #0x28]
	ldr r2, _0809FCD8 @ =0x0000021E
	adds r1, r5, r2
	strb r7, [r1]
	strh r4, [r0, #0x2e]
	bl DrawBackground
	ldr r0, _0809FCDC @ =0x0000030E
	mov r1, sl
	strh r0, [r1, #2]
	mov r2, r8
	strh r4, [r2, #4]
	strh r4, [r2, #6]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, _0809FCE0 @ =0x0600C000
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _0809FCE4 @ =0x06001800
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	mov r2, sb
	ldrh r1, [r2, #0x16]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	movs r6, #0x10
	strh r6, [r0, #0x26]
	strh r6, [r0, #0x28]
	ldr r2, _0809FCE8 @ =0x0000025E
	adds r1, r5, r2
	strb r7, [r1]
	movs r1, #1
	strh r1, [r0, #0x2e]
	bl DrawBackground
	ldr r0, _0809FCEC @ =0x00001B89
	mov r1, sl
	strh r0, [r1, #4]
	mov r2, r8
	strh r4, [r2, #8]
	strh r4, [r2, #0xa]
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, _0809FCF0 @ =0x06008000
	str r1, [r0, #4]
	strh r4, [r0, #0xa]
	ldr r1, _0809FCF4 @ =0x0600D800
	str r1, [r0, #0xc]
	strh r4, [r0, #0x18]
	strh r4, [r0, #0x1a]
	ldrb r1, [r5, #1]
	adds r1, #5
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	strh r6, [r0, #0x26]
	strh r6, [r0, #0x28]
	ldr r2, _0809FCF8 @ =0x0000029E
	adds r5, r5, r2
	strb r7, [r5]
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
_0809FCC0: .4byte gBgCntRegs
_0809FCC4: .4byte 0x00004E07
_0809FCC8: .4byte gBgScrollRegs
_0809FCCC: .4byte 0x06004000
_0809FCD0: .4byte 0x06007000
_0809FCD4: .4byte gUnknown_080D8CDC
_0809FCD8: .4byte 0x0000021E
_0809FCDC: .4byte 0x0000030E
_0809FCE0: .4byte 0x0600C000
_0809FCE4: .4byte 0x06001800
_0809FCE8: .4byte 0x0000025E
_0809FCEC: .4byte 0x00001B89
_0809FCF0: .4byte 0x06008000
_0809FCF4: .4byte 0x0600D800
_0809FCF8: .4byte 0x0000029E

.syntax divided
