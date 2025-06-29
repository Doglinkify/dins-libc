.section .text
.global _start
_start:
    movq $0, %rbp
    pushq %rbp
    pushq %rbp
    movq %rsp, %rbp
    call _init
    movq $0, %rdi
    movq $0, %rsi
    movq $0, %r8
    call main
    movl %eax, %edi
    call exit
    hlt
.size _start, . - _start
