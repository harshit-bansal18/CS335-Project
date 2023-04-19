.text
.section    .rodata
.LC0:
	.string    "%d\n" 
	.text
	 .globl   Arg.func_int0_int0
	 .type    Arg.func_int0_int0, @function
Arg.func_int0_int0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8,%rsp
	movq	$100,-8(%rbp)
	movq	-8(%rbp),%rax
	jmp	return0
	return0:	
	addq	$8,%rsp
	popq	%rbp
	ret


	.text
	 .globl   main
	 .type    main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$72,%rsp
	movq	$16,%rdi
	call	malloc
	movq	%rax,0(%rsp)
	movq	0(%rsp),%r8
	movq	%r8,-8(%rbp)
	movq	-8(%rbp),%r9
	movq	%r9,8(%rsp)
	movq	8(%rsp),%r10
	addq	$0,%r10
	movq	%r10,16(%rsp)
	movq	16(%rsp),%r8
	movq	$20,(%r8)
	movq	-8(%rbp),%r9
	movq	%r9,24(%rsp)
	movq	24(%rsp),%r10
	addq	$0,%r10
	movq	%r10,32(%rsp)
	subq	$8,%rsp
	movq	$500,0(%rsp)
	movq	$20,8(%rsp)
	subq	$4,%rsp
	movq	-8(%rbp),%r8
	movq	%r8,0(%rsp)
	call	Arg.func_int0_int0
	addq	$4,%rsp
	movq	%rax,40(%rsp)
	addq	$16,%rsp
	movq	40(%rsp),%r9
	movq	32(%rsp),%r10
	movq	%r9,(%r10)
	movq	-8(%rbp),%r8
	movq	%r8,48(%rsp)
	movq	48(%rsp),%r9
	addq	$0,%r9
	movq	%r9,56(%rsp)
	movq	56(%rsp),%r10
	movq	(%r10),%rsi
	movq	$.LC0,%rdi
	movq	$0,%rax
	call	printf
	return1:	
	addq	$72,%rsp
	popq	%rbp
	ret


	.text
	 .globl   FuncTest.get_int
	 .type    FuncTest.get_int, @function
FuncTest.get_int:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$56,%rsp
	movq	$20,%r8
	addq	$30,%r8
	movq	%r8,0(%rsp)
	movq	0(%rsp),%r9
	movq	%r9,-8(%rbp)
	movq	-8(%rbp),%rax
	cqto	
	movq	$5,%r10
	idivq	%r10
	movq	%rax,8(%rsp)
	movq	8(%rsp),%r8
	movq	%r8,-16(%rbp)
	movq	-8(%rbp),%r9
	addq	-16(%rbp),%r9
	movq	%r9,16(%rsp)
	movq	16(%rsp),%r10
	imulq	$5,%r10
	movq	%r10,24(%rsp)
	movq	24(%rsp),%r8
	addq	-8(%rbp),%r8
	movq	%r8,32(%rsp)
	movq	32(%rsp),%rax
	jmp	return2
	return2:	
	addq	$56,%rsp
	popq	%rbp
	ret


