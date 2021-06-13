BITS 64

	global asm_strcmp


section .text


asm_strcmp:
	push rbp
	mov rbp, rsp

	push rcx
	push r8
	push r9
	xor rcx, rcx
strcmp:
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rcx]

	cmp r8b, byte 0
	je str_cmp
	cmp r9b, byte 0
	je str_cmp
	cmp r8b, r9b
	jne str_cmp
	inc rcx
	jmp strcmp

str_cmp:
	cmp r8b, r9b
	je equal
	jl less
	jg greater

equal:
	mov rax, 0
	jmp return

less:
	mov rax, -1
	jmp return

greater:
	mov rax, 1
	jmp return


;str1_ascii:
;	mov r10b, [r12]
;	add byte[r11], r10b
;	cmp r10b, byte 0
;	je str2_ascii
;	inc r12
;	add byte[r11], r10b
;	jmp str1_ascii
;
;str2_ascii:
;	mov r12b, [r13]
;	add byte[r13], r12b
;	cmp r12b, byte 0
;	je ret_ascii
;	inc r13
;	add byte[r13], r12b
;	jmp str2_ascii
;
;ret_ascii:
;       sub r11, r13
;	jmp return
;strcmp returns the ascii difference between s1 and s2 which is different from the current version of my program

return:
	pop r9
	pop r8
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
