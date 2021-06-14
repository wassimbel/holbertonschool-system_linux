BITS 64
	global asm_memcpy
section .text

asm_memcpy:
	push rbp
	mov rbp, rsp
	push rcx
	push r8
	push r9
	xor rcx, rcx
	xor r8, r8
	xor r9, r9
	test rdx, rdx
	jz return

memcpy:
	cmp rcx, rdx
	je return
	mov r9d, [rsi + rcx]
	mov [rdi + rcx], r9d
	inc rcx
	jmp memcpy
return:
	pop r9
	pop r8
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
