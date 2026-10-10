.syntax unified
.text
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	cmp r1, #0x6e
	beq _0807CB00
	cmp r1, #0x6e
	bgt _0807CA5A
	cmp r1, #0xa
	beq _0807CA9A
	cmp r1, #0xa
	bgt _0807CA54
	cmp r1, #0
	beq _0807CA78
	b _0807CB70
_0807CA54:
	cmp r1, #0x64
	beq _0807CAAA
	b _0807CB70
_0807CA5A:
	movs r0, #0xff
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807CB42
	cmp r1, r0
	bgt _0807CA6E
	subs r0, #0xa
	cmp r1, r0
	beq _0807CB32
	b _0807CB70
_0807CA6E:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r1, r0
	beq _0807CB56
	b _0807CB70
_0807CA78:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	bl sub_807DB00
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	bl sub_807DB00
	movs r0, #0
	movs r1, #1
	strh r1, [r4, #8]
	strb r0, [r4, #0xe]
	movs r0, #0xa
	strh r0, [r4, #0xc]
	b _0807CB70
_0807CA9A:
	adds r0, r4, #0
	movs r1, #2
	bl sub_807D9B4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807CB70
	b _0807CB1C
_0807CAAA:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807CABA
	movs r0, #0x6e
	strh r0, [r4, #0xc]
_0807CABA:
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #0xa
	bne _0807CB70
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807CAE4
	ldr r0, [r4, #0x20]
	ldr r0, [r0, #0x10]
	asrs r0, r0, #8
	ldr r1, _0807CADC @ =gCamera
	ldr r1, [r1]
	subs r0, r0, r1
	cmp r0, #0x77
	bgt _0807CAE0
	movs r0, #0
	b _0807CAE2
	.align 2, 0
_0807CADC: .4byte gCamera
_0807CAE0:
	movs r0, #1
_0807CAE2:
	strb r0, [r4, #2]
_0807CAE4:
	ldr r0, _0807CAFC @ =gUnknown_080D5C78
	ldrb r1, [r4, #2]
	lsls r1, r1, #2
	ldrb r2, [r4, #0xe]
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r1, [r1]
	adds r0, r4, #0
	bl sub_807DA34
	b _0807CB70
	.align 2, 0
_0807CAFC: .4byte gUnknown_080D5C78
_0807CB00:
	adds r0, r4, #0
	movs r1, #2
	bl sub_807D9B4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807CB70
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0807CB26
_0807CB1C:
	movs r0, #0x1e
	strh r0, [r4, #8]
	movs r0, #0x64
	strh r0, [r4, #0xc]
	b _0807CB70
_0807CB26:
	movs r0, #0xff
	lsls r0, r0, #1
	strh r0, [r4, #0xc]
	movs r0, #0x3c
	strh r0, [r4, #8]
	b _0807CB70
_0807CB32:
	adds r0, r4, #0
	movs r1, #0
	bl sub_807D9B4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807CB70
	b _0807CB4E
_0807CB42:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807CB70
_0807CB4E:
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	b _0807CB70
_0807CB56:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #5
	bl sub_807DB00
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	bl sub_807DB00
	adds r0, r4, #0
	bl sub_8081BBC
_0807CB70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

.syntax divided
