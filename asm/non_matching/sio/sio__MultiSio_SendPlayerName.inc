.syntax unified
.text
	ldr r2, _0802570C @ =gMultiSioSend
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r2, #2]
	ldr r1, _08025710 @ =gLoadedSaveGame
	ldr r0, [r1]            @ playerId
	str r0, [r2, #4]
	ldrh r0, [r1, #4]       @ playerName[0]
	strh r0, [r2, #8]
	ldrh r0, [r1, #6]       @ playerName[1]       
	strh r0, [r2, #0xa]
	ldrh r0, [r1, #8]       @ playerName[2]
	strh r0, [r2, #0xc]
	ldrh r0, [r1, #0xa]     @ playerName[3]
	strh r0, [r2, #0xe]
	ldrh r0, [r1, #0xc]     @ playerName[4]
	strh r0, [r2, #0x10]
	ldrh r0, [r1, #0xe]     @ playerName[5]
	strh r0, [r2, #0x12]
	bx lr
	.align 2, 0
_0802570C: .4byte gMultiSioSend
_08025710: .4byte gLoadedSaveGame

.syntax divided
