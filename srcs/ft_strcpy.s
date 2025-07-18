global ft_strcpy

section .text
ft_strcpy:
	xor rax, rax
	xor rcx, rcx

.loop:
	mov al, byte [rsi + rcx]
	mov byte [rdi + rcx], al
	cmp al, 0
	je .return
	inc rcx
	jmp .loop

.return:
	mov rax, rdi
	ret