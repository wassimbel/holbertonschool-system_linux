BITS 64
	global asm_strcspn
section .text

asm_strcspn:
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
strcspn:
	test rsi, rsi
	jz len_rdi
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rdx]
	test r8b, r8b
	jz return
	test r9b, r9b
	jz increment
	cmp r8b, r9b
	jne next
	jmp return

increment:
	inc rax
	inc rcx
	mov rdx, 0
	jmp strcspn

next:
	inc rdx
	jmp strcspn

len_rdi:
	mov r8b, [rdi + rcx]
	test r8b, r8b
	jz return
	inc rcx
	inc rax
	jmp len_rdi

return:
	push rax
	pop rcx
	pop rdx
	pop r9
	pop r8
	mov rsp, rbp
	pop rbp
	ret
