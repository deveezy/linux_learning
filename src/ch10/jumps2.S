	.file	"jumps2.c"
	.text
.Ltext0:
	.section	.rodata
	.align 8
.LC0:
	.string	"Setjmp returned -- i = %d, %p\n"
.LC1:
	.string	"s = %s\n"
	.text
	.globl	a
	.type	a, @function
a:
.LFB6:
	.file 1 "src/ch10/jumps2.c"
	.loc 1 6 1
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 7 11
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_setjmp@PLT
	movl	%eax, -4(%rbp)
	.loc 1 8 3
	movq	-24(%rbp), %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 10 3
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 11 10
	movl	-4(%rbp), %eax
	.loc 1 12 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	a, .-a
	.section	.rodata
	.align 8
.LC2:
	.string	"In B: i=%d.  Calling longjmp(env, i)\n"
	.text
	.globl	b
	.type	b, @function
b:
.LFB7:
	.loc 1 15 1
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 16 3
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 18 3
	movl	-4(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	longjmp@PLT
	.cfi_endproc
.LFE7:
	.size	b, .-b
	.section	.rodata
.LC3:
	.string	"Jim"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.loc 1 22 1
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$224, %rsp
	movl	%edi, -212(%rbp)
	movq	%rsi, -224(%rbp)
	.loc 1 22 1
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 25 7
	leaq	-208(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	call	a
	.loc 1 25 6
	testl	%eax, %eax
	je	.L6
	.loc 1 26 5
	movl	$0, %edi
	call	exit@PLT
.L6:
	.loc 1 27 3
	leaq	-208(%rbp), %rax
	movq	%rax, %rsi
	movl	$3, %edi
	call	b
	.loc 1 28 10
	movl	$0, %eax
	.loc 1 29 1
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/include/bits/setjmp.h"
	.file 3 "/usr/include/bits/types/__sigset_t.h"
	.file 4 "/usr/include/bits/types/struct___jmp_buf_tag.h"
	.file 5 "/usr/include/setjmp.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x1ff
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF20
	.byte	0xc
	.long	.LASF21
	.long	.LASF22
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF2
	.byte	0x2
	.byte	0x1f
	.byte	0x12
	.long	0x39
	.uleb128 0x3
	.long	0x50
	.long	0x49
	.uleb128 0x4
	.long	0x49
	.byte	0x7
	.byte	0
	.uleb128 0x5
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x5
	.byte	0x8
	.byte	0x5
	.long	.LASF1
	.uleb128 0x6
	.byte	0x80
	.byte	0x3
	.byte	0x5
	.byte	0x9
	.long	0x6e
	.uleb128 0x7
	.long	.LASF4
	.byte	0x3
	.byte	0x7
	.byte	0x15
	.long	0x6e
	.byte	0
	.byte	0
	.uleb128 0x3
	.long	0x49
	.long	0x7e
	.uleb128 0x4
	.long	0x49
	.byte	0xf
	.byte	0
	.uleb128 0x2
	.long	.LASF3
	.byte	0x3
	.byte	0x8
	.byte	0x3
	.long	0x57
	.uleb128 0x8
	.long	.LASF23
	.byte	0xc8
	.byte	0x4
	.byte	0x1a
	.byte	0x8
	.long	0xbf
	.uleb128 0x7
	.long	.LASF5
	.byte	0x4
	.byte	0x20
	.byte	0xf
	.long	0x2d
	.byte	0
	.uleb128 0x7
	.long	.LASF6
	.byte	0x4
	.byte	0x21
	.byte	0x9
	.long	0xbf
	.byte	0x40
	.uleb128 0x7
	.long	.LASF7
	.byte	0x4
	.byte	0x22
	.byte	0x10
	.long	0x7e
	.byte	0x48
	.byte	0
	.uleb128 0x9
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.long	.LASF8
	.byte	0x5
	.byte	0x20
	.byte	0x1e
	.long	0xd2
	.uleb128 0x3
	.long	0x8a
	.long	0xe2
	.uleb128 0x4
	.long	0x49
	.byte	0
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.byte	0x7
	.long	.LASF9
	.uleb128 0x5
	.byte	0x1
	.byte	0x8
	.long	.LASF10
	.uleb128 0x5
	.byte	0x2
	.byte	0x7
	.long	.LASF11
	.uleb128 0x5
	.byte	0x1
	.byte	0x6
	.long	.LASF12
	.uleb128 0x5
	.byte	0x2
	.byte	0x5
	.long	.LASF13
	.uleb128 0xa
	.byte	0x8
	.long	0x10b
	.uleb128 0x5
	.byte	0x1
	.byte	0x6
	.long	.LASF14
	.uleb128 0x5
	.byte	0x8
	.byte	0x5
	.long	.LASF15
	.uleb128 0x5
	.byte	0x8
	.byte	0x7
	.long	.LASF16
	.uleb128 0xb
	.long	.LASF19
	.byte	0x1
	.byte	0x15
	.byte	0x5
	.long	0xbf
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x173
	.uleb128 0xc
	.long	.LASF17
	.byte	0x1
	.byte	0x15
	.byte	0xe
	.long	0xbf
	.uleb128 0x3
	.byte	0x91
	.sleb128 -228
	.uleb128 0xc
	.long	.LASF18
	.byte	0x1
	.byte	0x15
	.byte	0x1b
	.long	0x173
	.uleb128 0x3
	.byte	0x91
	.sleb128 -240
	.uleb128 0xd
	.string	"env"
	.byte	0x1
	.byte	0x17
	.byte	0xb
	.long	0xc6
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.byte	0
	.uleb128 0xa
	.byte	0x8
	.long	0x105
	.uleb128 0xe
	.string	"b"
	.byte	0x1
	.byte	0xe
	.byte	0x5
	.long	0xbf
	.quad	.LFB7
	.quad	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x1b6
	.uleb128 0xf
	.string	"i"
	.byte	0x1
	.byte	0xe
	.byte	0xb
	.long	0xbf
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xf
	.string	"env"
	.byte	0x1
	.byte	0xe
	.byte	0x16
	.long	0x1b6
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.uleb128 0xa
	.byte	0x8
	.long	0x8a
	.uleb128 0x10
	.string	"a"
	.byte	0x1
	.byte	0x5
	.byte	0x5
	.long	0xbf
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xf
	.string	"s"
	.byte	0x1
	.byte	0x5
	.byte	0xd
	.long	0x105
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xf
	.string	"env"
	.byte	0x1
	.byte	0x5
	.byte	0x18
	.long	0x1b6
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xd
	.string	"i"
	.byte	0x1
	.byte	0x7
	.byte	0x7
	.long	0xbf
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF15:
	.string	"long long int"
.LASF9:
	.string	"unsigned int"
.LASF4:
	.string	"__val"
.LASF22:
	.string	"/home/tlt/dev/linux"
.LASF19:
	.string	"main"
.LASF3:
	.string	"__sigset_t"
.LASF17:
	.string	"argc"
.LASF0:
	.string	"long unsigned int"
.LASF7:
	.string	"__saved_mask"
.LASF16:
	.string	"long long unsigned int"
.LASF5:
	.string	"__jmpbuf"
.LASF18:
	.string	"argv"
.LASF10:
	.string	"unsigned char"
.LASF20:
	.string	"GNU C17 10.2.0 -mtune=generic -march=x86-64 -g"
.LASF14:
	.string	"char"
.LASF1:
	.string	"long int"
.LASF2:
	.string	"__jmp_buf"
.LASF21:
	.string	"src/ch10/jumps2.c"
.LASF11:
	.string	"short unsigned int"
.LASF12:
	.string	"signed char"
.LASF8:
	.string	"jmp_buf"
.LASF23:
	.string	"__jmp_buf_tag"
.LASF6:
	.string	"__mask_was_saved"
.LASF13:
	.string	"short int"
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
