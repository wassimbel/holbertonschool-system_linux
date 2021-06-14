BITS 64
	global asm_putc
section .text

asm_putc:
	push rbp
	mov rbp, rsp

	push rax
	push rsi
	push rdx
	push rdi

putc:

	mov rax, 1
	mov rdi, 1
	mov rdx, 1
	mov rsi, rsp
	syscall

return:
	pop rdi
	pop rdx
	pop rsi
	pop rax

	mov rsp, rbp
	pop rbp
	ret
