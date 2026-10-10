.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #0xc
	movs r5, #0
	str r5, [sp]
	ldr r1, _080286EC @ =gUnknown_03000970
	ldr r2, _080286F0 @ =0x05000004
	mov r0, sp
	bl CpuSet
	str r5, [sp, #4]
	add r0, sp, #4
	ldr r4, _080286F4 @ =gStageData
	ldr r2, _080286F8 @ =0x05000032
	adds r1, r4, #0
	bl CpuSet
	movs r0, #7
	strb r0, [r4, #3]
	strb r5, [r4, #1]
	ldr r0, _080286FC @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r4, #6]
	str r5, [sp, #8]
	add r0, sp, #8
	ldr r4, _08028700 @ =gUnknown_03001060
	ldr r2, _08028704 @ =0x05000016
	adds r1, r4, #0
	bl CpuSet
	movs r1, #0
	adds r2, r4, #0
	adds r2, #0xc
	adds r4, #0x4c
_080286CE:
	lsls r0, r1, #2
	adds r0, r0, r2
	str r1, [r0]
	adds r0, r1, r4
	strb r1, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _080286CE
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080286EC: .4byte gUnknown_03000970
_080286F0: .4byte 0x05000004
_080286F4: .4byte gStageData
_080286F8: .4byte 0x05000032
_080286FC: .4byte 0x04000128
_08028700: .4byte gUnknown_03001060
_08028704: .4byte 0x05000016

.syntax divided
