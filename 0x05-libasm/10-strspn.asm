BITS 64
	global asm_strspn
section .text

asm_strspn:
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
strspn:
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rdx]
	test r8b, r8b
	jz return
	test r9b, r9b
	jz return
	cmp r8b, r9b
	jne next
	inc rax
	inc rcx
	mov rdx, 0
	jmp strspn

next:
	inc rdx
	jmp strspn
return:
	pop rcx
	pop rdx
	pop r9
	pop r8
	mov rsp, rbp
	pop rbp
	ret
