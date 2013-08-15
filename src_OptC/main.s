	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"main.c"
	.section	.rodata
	.align	2
	.type	lookup, %object
	.size	lookup, 32
lookup:
	.word	16641
	.word	16641
	.word	16641
	.word	16641
	.word	16898
	.word	16898
	.word	17155
	.word	17411
	.align	2
	.type	huffBinLength, %object
	.size	huffBinLength, 4
huffBinLength:
	.word	3
	.align	2
.LC0:
	.ascii	"pwd\000"
	.align	2
.LC1:
	.ascii	"encoded.dat\000"
	.align	2
.LC2:
	.ascii	"rb\000"
	.align	2
.LC3:
	.ascii	"Error\000"
	.align	2
.LC4:
	.ascii	"Unable to open file!\000"
	.align	2
.LC5:
	.ascii	"DecodedOutput.txt\000"
	.align	2
.LC6:
	.ascii	"w\000"
	.align	2
.LC7:
	.ascii	"\000\000"
	.align	2
.LC8:
	.ascii	"%c\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 176
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #176
	str	r0, [fp, #-176]
	str	r1, [fp, #-180]
	mov	r3, #0
	str	r3, [fp, #-64]
	mov	r3, #29
	str	r3, [fp, #-60]
	mov	r3, #0
	str	r3, [fp, #-56]
	mov	r3, #1
	str	r3, [fp, #-48]
	ldr	r0, .L12
	bl	system
	ldr	r0, .L12+4
	ldr	r1, .L12+8
	bl	fopen
	mov	r3, r0
	str	r3, [fp, #-44]
	ldr	r3, [fp, #-44]
	cmp	r3, #0
	bne	.L2
	ldr	r0, .L12+12
	bl	perror
	ldr	r0, .L12+16
	bl	printf
	mov	r3, #0
	str	r3, [fp, #-44]
	mov	r0, #0
	bl	exit
.L2:
	ldr	r0, .L12+20
	ldr	r1, .L12+24
	bl	fopen
	mov	r3, r0
	str	r3, [fp, #-40]
	mov	r3, #0
	str	r3, [fp, #-168]
	sub	r3, fp, #164
	mov	r2, #96
	mov	r0, r3
	mov	r1, #0
	bl	memset
	ldr	r3, .L12+28
	and	r3, r3, #255
	strb	r3, [fp, #-69]
	ldrb	r3, [fp, #-168]	@ zero_extendqisi2
	str	r3, [fp, #-36]
	mov	r3, #0
	str	r3, [fp, #-32]
	mov	r3, #0
	str	r3, [fp, #-172]
	mov	r3, #0
	str	r3, [fp, #-24]
	mov	r3, #4
	str	r3, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-68]
	mov	r3, #1
	str	r3, [fp, #-8]
	sub	r3, fp, #172
	mov	r0, r3
	mov	r1, #1
	mov	r2, #3
	ldr	r3, [fp, #-44]
	bl	fread
	mov	r3, r0
	str	r3, [fp, #-48]
	ldr	r3, [fp, #-48]
	mov	r3, r3, asl #3
	str	r3, [fp, #-48]
	ldr	r3, [fp, #-172]
	mov	r3, r3, asl #8
	str	r3, [fp, #-172]
	b	.L3
.L8:
	ldr	r3, [fp, #-172]
	mov	r3, r3, lsr #29
	strb	r3, [fp, #-25]
	ldrb	r2, [fp, #-25]	@ zero_extendqisi2
	ldr	r3, .L12+32
	ldr	r3, [r3, r2, asl #2]
	str	r3, [fp, #-56]
	ldr	r3, [fp, #-56] ;Remove this line?
	mov	r3, r3, lsr #8
	str	r3, [fp, #-52]
	ldr	r1, [fp, #-32]
	ldr	r3, [fp, #-52]
	and	r0, r3, #255
	mvn	r2, #163
	sub	ip, fp, #4
	add	r3, ip, r1
	add	r2, r3, r2
	mov	r3, r0
	strb	r3, [r2, #0]
	ldr	r3, [fp, #-32]
	add	r3, r3, #1
	str	r3, [fp, #-32]
	ldr	r3, [fp, #-56]
	and	r3, r3, #255
	str	r3, [fp, #-68]
	ldr	r2, [fp, #-64]
	ldr	r3, [fp, #-68]
	add	r3, r2, r3
	str	r3, [fp, #-64]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	sub	r2, r3, #3
	ldr	r3, [fp, #-64]
	cmp	r2, r3
	bhi	.L4
	ldr	r2, [fp, #-172]
	ldr	r3, [fp, #-68]
	mov	r3, r2, asl r3
	str	r3, [fp, #-24]
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-64]
	rsb	r3, r3, r2
	add	r3, r3, #24
	str	r3, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-172]
	sub	r3, fp, #172
	mov	r0, r3
	mov	r1, #1
	mov	r2, #3
	ldr	r3, [fp, #-44]
	bl	fread
	mov	r3, r0
	str	r3, [fp, #-48]
	ldr	r3, [fp, #-48]
	mov	r3, r3, asl #3
	str	r3, [fp, #-48]
	ldr	r1, [fp, #-172]
	ldr	r3, [fp, #-12]
	rsb	r2, r3, #0
	ldr	r3, [fp, #-48]
	rsb	r3, r3, r2
	add	r3, r3, #32
	mov	r2, r1, asl r3
	ldr	r3, [fp, #-24]
	orr	r3, r2, r3
	str	r3, [fp, #-172]
	mov	r3, #0
	str	r3, [fp, #-64]
	mov	r3, #0
	str	r3, [fp, #-24]
	b	.L5
.L4:
	ldr	r3, [fp, #-172]
	ldr	r2, [fp, #-68]
	mov	r3, r3, asl r2
	str	r3, [fp, #-172]
.L5:
	ldr	r3, [fp, #-32]
	cmp	r3, #99
	beq	.L6
	ldr	r3, [fp, #-48]
	cmp	r3, #0
	bne	.L3
.L6:
	ldr	r3, [fp, #-48]
	cmp	r3, #0
	bne	.L7
	ldr	r3, [fp, #-32]
	mvn	r2, #163
	sub	r1, fp, #4
	add	r3, r1, r3
	add	r2, r3, r2
	mov	r3, #0
	strb	r3, [r2, #0]
.L7:
	sub	r3, fp, #168
	mov	r0, r3
	ldr	r1, [fp, #-40]
	bl	printbits
	mov	r3, #0
	str	r3, [fp, #-32]
.L3:
	ldr	r3, [fp, #-48]
	cmp	r3, #0
	bne	.L8
	b	.L9
.L10:
	ldr	r3, [fp, #-172]
	mov	r3, r3, lsr #29
	strb	r3, [fp, #-25]
	ldrb	r2, [fp, #-25]	@ zero_extendqisi2
	ldr	r3, .L12+32
	ldr	r3, [r3, r2, asl #2]
	str	r3, [fp, #-56]
	ldr	r3, [fp, #-56]
	mov	r3, r3, lsr #8
	str	r3, [fp, #-52]
	ldr	r1, [fp, #-32]
	ldr	r3, [fp, #-52]
	and	r0, r3, #255
	mvn	r2, #163
	sub	ip, fp, #4
	add	r3, ip, r1
	add	r2, r3, r2
	mov	r3, r0
	strb	r3, [r2, #0]
	ldr	r3, [fp, #-32]
	add	r3, r3, #1
	str	r3, [fp, #-32]
	ldr	r0, .L12+36
	ldr	r1, [fp, #-52]
	bl	printf
	ldr	r3, [fp, #-56]
	and	r3, r3, #255
	str	r3, [fp, #-68]
	ldr	r2, [fp, #-172]
	ldr	r3, [fp, #-68]
	mov	r3, r2, asl r3
	str	r3, [fp, #-172]
.L9:
	ldr	r3, [fp, #-172]
	cmp	r3, #0
	bne	.L10
	ldr	r3, [fp, #-32]
	mvn	r2, #163
	sub	r1, fp, #4
	add	r3, r1, r3
	add	r2, r3, r2
	mov	r3, #0
	strb	r3, [r2, #0]
	sub	r3, fp, #168
	mov	r0, r3
	ldr	r1, [fp, #-40]
	bl	fputs
	ldr	r0, [fp, #-40]
	bl	fclose
	ldr	r0, [fp, #-44]
	bl	fclose
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, lr}
	bx	lr
.L13:
	.align	2
.L12:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	.LC7
	.word	lookup
	.word	.LC8
	.size	main, .-main
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
