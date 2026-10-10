.syntax unified
.text
	ldr r1, _08027900 @ =gStageData
	ldrh r0, [r0, #2]
	strh r0, [r1, #0x12]
	bx lr
	.align 2, 0
_08027900: .4byte gStageData

.syntax divided
