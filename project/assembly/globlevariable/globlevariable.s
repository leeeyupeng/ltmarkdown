	.file	"globlevariable.cpp"
	.text
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.zero	4
	.globl	aa
	.align 4
	.type	aa, @object
	.size	aa, 4
aa:
	.zero	4
	.globl	bb
	.align 4
	.type	bb, @object
	.size	bb, 4
bb:
	.zero	4
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	a(%rip), %rax
	movq	%rax, -32(%rbp)
	leaq	b(%rip), %rax
	movq	%rax, -24(%rbp)
	leaq	aa(%rip), %rax
	movq	%rax, -16(%rbp)
	leaq	bb(%rip), %rax
	movq	%rax, -8(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
