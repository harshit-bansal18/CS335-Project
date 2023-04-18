.section    .rodata
.LC0:
	.string    "%d\n" 
	 .globl   TestEmployee1.main
	 .type    TestEmployee1.main, @function
TestEmployee1.main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8,%rsp
	movl	$0,-4(%rbp)
	movl	$20,-8(%rbp)
	movl	-4(%rbp),%r8
	addl	$20,%r8
	movl	%r8,4(%rsp)
	movl	4(%rsp),%r9
	movl	%r9,-4(%rbp)
	return:	
	addq	$8,%rsp
	movl	$0, %eax
	leave
	ret


