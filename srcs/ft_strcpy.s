global ft_strcpy

section .text
ft_strcpy:
	xor rax, rax
	xor rcx, rcx

.loop:
	mov al, byte [rsi + rcx] ;put the character from s2[i] into al register
	mov byte [rdi + rcx], al ;put the character from al register into s1[i]
	cmp al, 0
	je .return
	inc rcx
	jmp .loop

.return:
	mov rax, rdi ;return the address of s1
	ret