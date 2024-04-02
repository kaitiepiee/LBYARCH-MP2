; assembly part using x86-64

section .data

section .text
bits 64
default rel

global asm_main
asm_main:
	push rbp
	mov rbp, rsp
	add rbp, 16

	mov rsi, r8
	mov rdi, r9
	mov r15, [rbp + 32]
	dec rcx

daxpy_loop:
	movsd xmm2, qword [rsi + rcx * 8] 
    movsd xmm3, qword [rdi + rcx * 8] 

    mulsd xmm2, xmm1 ; Multiply X[i] by scalar A
    vaddsd xmm0, xmm2, xmm3 ; Add scalar multiplication result and Y[i], store in XMM0
    movsd qword [r15 + rcx * 8], xmm0 ; Store the result in Z[i]
    dec rcx 
    jge daxpy_loop

    pop rbp 
    ret