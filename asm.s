.text
.section    .rodata
.LC0:
	.string    "%d\n" 
	.text
	 .globl   main
	 .type    main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$24,%rsp
	subq	$4,%rsp
	movq	16(%rbp),%r8
	movq	%r8,8(%rsp)
	movq	8(%rsp),%r9
	movq	%r9,0(%rsp)
	call	FuncTest.get_int
	addq	$4,%rsp
	movq	%rax,0(%rsp)
	movq	0(%rsp),%r10
	movq	%r10,-8(%rbp)
	movq	-8(%rbp),%rsi
	movq	$.LC0,%rdi
	movq	$0,%rax
	call	printf
	return0:	
	addq	$24,%rsp
	movq	$0, %rax
	leave
	ret


	.text
	 .globl   FuncTest.get_int
	 .type    FuncTest.get_int, @function
FuncTest.get_int:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rax,$1
	jmp	return1
	return1:	
	movq	$0, %rax
	leave
	ret


