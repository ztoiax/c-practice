	.file	"binary\344\274\240\351\200\201.c"
	.text
	.globl	binary
	.type	binary, @function
binary:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -56(%rbp)
	jmp	.L2
.L4:
	movl	$0, -52(%rbp)
	movl	-68(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L3
	movl	$1, -52(%rbp)
.L3:
	movl	-52(%rbp), %eax
	movl	%eax, %edx
	movl	-56(%rbp), %eax
	cltq
	movb	%dl, -48(%rbp,%rax)
	addl	$1, -56(%rbp)
	sarl	-68(%rbp)
.L2:
	cmpl	$0, -68(%rbp)
	jg	.L4
	movl	-56(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -56(%rbp)
	cltq
	movb	$0, -48(%rbp,%rax)
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	binary, .-binary
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
