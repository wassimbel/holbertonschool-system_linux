BITS 64

	global asm_strncasecmp

section .text


asm_strncasecmp:
	push rbp
	mov rbp, rsp
	push rcx
	push r8
	push r9
	xor rcx, rcx
	xor rax, rax
	xor r8, r8
	xor r9, r9

strncasecmp:
	cmp rcx, rdx
	je return
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rcx]

	cmp r8b, 65
	jl next
	cmp r8b, 90
	jg next
	add r8b, 32
	jmp next

next:
	cmp r9b, 65
	jl continue
	cmp r9b, 90
	jg continue
	add r9b, 32
	jmp continue

continue:
	test r8b, r8b
	jz return
	test r9b, r9b
	jz return
	inc rcx
	cmp r8b, r9b
	je strncasecmp
	jmp return
return:
	mov rax, r8
	sub rax, r9
	pop r9
	pop r8
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
