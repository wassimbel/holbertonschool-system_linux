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
	test rdi, rdi
	jz return
	test rsi, rsi
	jz return

strpbrk:
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rdx]
	test r8b, r8b
	jz return
	test r9b, r9b
	jz increment_rsi
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
return:
	pop r9
	pop r8
	pop rdx
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
