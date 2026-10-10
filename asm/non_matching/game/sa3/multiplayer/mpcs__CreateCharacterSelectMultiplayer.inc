.syntax unified
.text
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0809F944 @ =gDispCnt
	ldr r2, _0809F948 @ =0x00001541
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0809F94C @ =Task_809FCFC
	movs r1, #0xad
	lsls r1, r1, #2
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, _0809F950 @ =TaskDestructor_80A13B0
	str r3, [sp]
	movs r3, #0
	bl TaskCreate
	ldrh r1, [r0, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r4, r1, r0
	ldr r0, _0809F954 @ =gLoadedSaveGame
	ldr r2, _0809F958 @ =0x00000366
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r4]
	movs r2, #0
	ldr r0, _0809F95C @ =0x0300001C
	adds r3, r1, r0
_0809F88A:
	lsls r0, r2, #2
	adds r0, r3, r0
	adds r1, r2, #0
	adds r1, #0xe
	adds r1, r5, r1
	str r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0809F88A
	adds r0, r5, #0
	adds r0, #0x12
	str r0, [r4, #0x30]
	adds r0, #2
	str r0, [r4, #0x2c]
	adds r0, #3
	str r0, [r4, #0x18]
	ldrb r0, [r5, #0x17]
	movs r1, #0
	strb r0, [r4, #3]
	adds r0, r5, #0
	adds r0, #0x16
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r5, #0x16]
	ldrb r0, [r5, #0x12]
	strb r0, [r4, #1]
	movs r0, #1
	strh r0, [r4, #6]
	strh r1, [r4, #8]
	strh r1, [r4, #4]
	strh r1, [r4, #0xa]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r4, #0xc]
	movs r2, #0xf0
	lsls r2, r2, #7
	str r2, [r4, #0x4c]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r4, #0x50]
	str r2, [r4, #0x54]
	str r0, [r4, #0x58]
	str r2, [r4, #0x34]
	movs r0, #0x88
	lsls r0, r0, #5
	str r0, [r4, #0x38]
	str r2, [r4, #0x3c]
	str r0, [r4, #0x40]
	str r1, [r4, #0x44]
	str r1, [r4, #0x48]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x80
	str r1, [r0]
	str r2, [r4, #0x6c]
	movs r0, #0xaa
	lsls r0, r0, #7
	str r0, [r4, #0x70]
	movs r0, #0xc9
	lsls r0, r0, #8
	str r0, [r4, #0x74]
	movs r0, #0xb0
	lsls r0, r0, #5
	str r0, [r4, #0x78]
	str r2, [r4, #0x5c]
	movs r1, #0x91
	lsls r1, r1, #8
	str r1, [r4, #0x60]
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [r4, #0x64]
	str r1, [r4, #0x68]
	adds r1, r4, #0
	adds r1, #0x84
	ldr r0, _0809F960 @ =0x06010000
	str r0, [r1]
	adds r0, r4, #0
	bl sub_809F964
	adds r0, r4, #0
	bl sub_809FBD0
	bl m4aMPlayAllStop
	movs r0, #3         @ MUS_CHARACTER_SELECT
	bl m4aSongNumStart
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F944: .4byte gDispCnt
_0809F948: .4byte 0x00001541
_0809F94C: .4byte Task_809FCFC
_0809F950: .4byte TaskDestructor_80A13B0
_0809F954: .4byte gLoadedSaveGame
_0809F958: .4byte 0x00000366
_0809F95C: .4byte 0x0300001C
_0809F960: .4byte 0x06010000

.syntax divided
