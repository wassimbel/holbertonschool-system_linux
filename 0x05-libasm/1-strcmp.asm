BITS 64

	global asm_strcmp


section .text


asm_strcmp:
	push rbp
	mov rbp, rsp

	push rcx
	push r8
	push r9
	xor rcx, rcx
strcmp:
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rcx]

	cmp r8b, byte 0
	je str_cmp
	cmp r9b, byte 0
	je str_cmp
	cmp r8b, r9b
	jne str_cmp
	inc rcx
	jmp strcmp

str_cmp:
	cmp r8b, r9b
	je equal
	jl less
	jg greater

equal:
	mov rax, 0
	jmp return_

less:
	mov rax, -1
	jmp return_

greater:
	mov rax, 1
	jmp return_

return_:
	pop r9
	pop r8
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
