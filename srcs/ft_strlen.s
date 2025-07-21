global ft_strlen

section .text
ft_strlen:
	xor rax, rax ;set rax to 0, register used to return value

.loop:
	cmp byte [rdi + rax], 0 ;if we reach the NULL terminator
	je .return
	inc rax
	jmp .loop

.return:
	ret