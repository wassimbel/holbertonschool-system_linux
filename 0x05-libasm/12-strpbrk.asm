BITS 64
	global asm_strpbrk
section .text

asm_strpbrk:
	push rbp
	mov rbp, rsp

	push rax
	push rcx
	push rdx
	push r8
	push r9
	xor rax, rax
	xor rcx, rcx
	xor rdx, rdx
	xor r8, r8
	xor r9, r9

strpbrk:
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rdx]
	test r9b, r9b
	jz increment_rsi
	test r8b, r8b
	jz return
	cmp r8b, r9b
	je next
	inc rdx
	jmp strpbrk

increment_rsi:
	inc rcx
	mov rdx, 0
	jmp strpbrk

next:
	mov rax, rdi
	add rax, rcx
	jmp return

return:
	mov rsp, rbp
	pop rbp
	ret
