BITS 64
	global asm_puti_base
	extern asm_putc, asm_srlen

section .text

asm_puti_base:
	push rbp
	mov rbp, rsp
	push r8
 	push r9
	push r10

	xor r8, r8
	xor r9, r9
	xor r10, r10
	movsx r8, edi
	xor rax, rax
	cmp r8, 0
	jge positive
	imul r8, -1
	mov r10, 1
	mov rdi, 45
	call asm_putc

positive:
	test r8, r8
	jnz loop
	mov rdi, 48
	call asm_putc
	mov r10, 1

loop:
	xor rdx, rdx
	test r8, r8
	jz check
	mov rax, r8
	mov rbx, 10
	div rbx
	mov r8, rax
	push rdx
	inc r9
	jmp loop
check:

	mov r8, r9
	jmp print

done:

        cmp r10, 1
        jne return
        inc r9
        jmp return

print:
        test r8, r8
        jz done
        pop rdi
        add rdi, 48
        call asm_putc
        dec r8
        jmp print

return:
	mov rax, r9
	pop r10
	pop r9
	pop r8
	mov rsp, rbp
	pop rbp
	ret
