BITS 64

	global asm_strcmp


section .text


asm_strcmp:
	push rbp
	mov rbp, rsp
	push rcx
	xor rcx, rcx
strcmp:
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]
	test al, al
	jz str_cmp
	test bl, bl
	jz str_cmp
	cmp al, bl
	jne str_cmp
	inc rcx
	jmp strcmp

str_cmp:
	cmp al, bl
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
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
