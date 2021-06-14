BITS 64
	global asm_memcpy
section .text

asm_memcpy:
	push rbp
	mov rbp, rsp
	push rcx
	push r8
	xor rcx, rcx
	xor r8, r8
	test rdx, rdx
	jz return

memcpy:
	cmp rcx, rdx
	je return
	mov r8b, [rsi + rcx]
	mov [rdi + rcx], r8b
	inc rcx
	jmp memcpy
return:
	pop r8
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
