; assembly part using x86-64

section .data

section .text
bits 64
default rel

global asm_main

asm_main:
	push rbp
    mov rbp, rsp
    sub rsp, 16 ; Adjust stack pointer

    mov rsi, r8 ;
    mov rdi, r9 ; 
    mov r15, qword [rbp + 32] ;copy vector address to R15

    dec rcx ; decrement to start from n - 1

daxpy_loop:
	movsd xmm2, qword [rsi + rcx * 8] ; Load X[i] into XMM2
    movsd xmm3, qword [rdi + rcx * 8] ; Load Y[i] into XMM3

    mulsd xmm2, xmm1 ; Multiply X[i] by scalar A

    vaddsd xmm0, xmm2, xmm3 ; Add scalar multiplication result and Y[i], store in XMM0

    movsd qword [r15 + rcx * 8], xmm0 ; Store the result in Z[i]
    dec rcx ; 
    jge mul_loop ; jump if greater than or equal to zero

    pop rbp 
    ret