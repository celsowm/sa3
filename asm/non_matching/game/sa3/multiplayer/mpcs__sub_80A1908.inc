.syntax unified
.text
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x68]
	movs r3, #0x91
	lsls r3, r3, #8
	cmp r1, r3
	ble _080A1922
	ldr r0, _080A1928 @ =0xFFFFFA00
	adds r1, r1, r0
	str r1, [r2, #0x68]
	ldr r0, _080A192C @ =0x000090FF
	cmp r1, r0
	bgt _080A1930
_080A1922:
	str r3, [r2, #0x68]
	movs r0, #1
	b _080A1932
	.align 2, 0
_080A1928: .4byte 0xFFFFFA00
_080A192C: .4byte 0x000090FF
_080A1930:
	movs r0, #0
_080A1932:
	pop {r1}
	bx r1
	.align 2, 0

.syntax divided
