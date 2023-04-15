.section .data
result:
    .long 0
msg:
    .asciz "The sum of %d and %d is %d.\n"

.section .text
.globl sum
.type sum, @function
sum:
    push %rbp
    mov %rsp, %rbp
    mov 8(%rbp), %rax
    add 12(%rbp), %rax
    leave
    ret

.globl main
.type main, @function
main:
    push %rbp
    mov %rsp, %rbp
    sub $16, %rsp
    mov $5, -4(%rbp)
    mov $10, -8(%rbp)
    mov -8(%rbp), %rax
    push %rax
    mov -4(%rbp), %rax
    push %rax
    call sum
    add $8, %rsp
    mov %rax, -12(%rbp)
    mov $0, %rax
    leave
    ret
