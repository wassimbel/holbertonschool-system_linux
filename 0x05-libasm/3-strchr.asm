BITS 64
	global asm_strchr

section .text

asm_strchr:
	push rbp
	mov rbp, rsp
	push rax

strchr:
	mov r8b, [rdi]
	cmp r8b, sil
	je str_chr
	cmp r8b, byte 0
	je null
	inc rdi
	jmp strchr

str_chr:
	mov rax, rdi
	jmp return
null:
	mov rax, 0

return:
	pop rax
	mov rsp, rbp
	pop rbp
	ret
