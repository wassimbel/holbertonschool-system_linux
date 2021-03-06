BITS 64
	global asm_putc
section .text

asm_putc:
	push rbp
	mov rbp, rsp
	push rax
	push rsi
	push rdx

	add rsp, -1
	mov [rsp], dil

	mov rax, 1
	mov rdi, 1
	mov rdx, 1
	mov rsi, rsp
	syscall

return:
	add rsp, 1
	pop rdx
	pop rsi
	mov rsp, rbp
	pop rbp
	ret

