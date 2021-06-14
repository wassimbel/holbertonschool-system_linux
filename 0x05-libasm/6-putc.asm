BITS 64
	global asm_putc
section .text

asm_putc:
	push rbp
	mov rbp, rsp
	push rax
	push rsi
	push rdx

	test rdi, rdi
	jz return
putc:
	add rsp, -1
	mov [rsp], dil

	mov rax, 1
	mov [rsi], rdi
	mov rdi, 1
	mov rdx, 1
	syscall

return:
	add rsp, 1
	pop rdx
	pop rsi
	mov rsp, rbp
	pop rbp
	ret
