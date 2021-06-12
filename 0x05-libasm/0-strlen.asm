BITS 64

	global asm_strlen
	section .text

asm_strlen:
	push rbp
	mov rbp, rsp

	push rcx
	xor rcx, rcx

_strlen:
	cmp [rdi], byte 0
	je asm_len

	inc rcx
	inc rdi
	jmp _strlen

asm_len:
	mov rax, rcx
	pop rcx

	mov rsp, rbp
	pop rbp

	ret

