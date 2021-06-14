BITS 64
	global asm_strstr
section .text

asm_strstr:
	push rbp
	mov rbp, rsp

	push rax
	push rcx
	push rbx
	push rdx
	push r8
	push r9
	xor rax, rax
	xor rcx, rcx
	xor rbx, rbx
	xor rdx, rdx
	xor r8, r8
	xor r9, r9

	test rdi, rdi
	jz null
	test rsi, rsi
	jz null

strstr:
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rbx]
	test r9b, r9b
	jz match
	cmp r8b, r9b
	jne break
	inc rcx
	inc rbx
	jmp strstr

break:
	mov r8b, [rdi + rcx]
	test r8b, r8b
	jz null
	inc rcx
	jmp pos

null:
	add rax, 0
	jmp return

pos:
        mov rdx, rcx
        xor rbx, rbx
        jmp strstr

match:
	mov rax, rdi
	add rax, rdx
	jmp return

return:
	pop r9
	pop r8
	pop rdx
	pop rbx
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
