global ft_strdup
section .text

extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push rdi

	call ft_strlen
	inc rax

	mov rdi, rax
	call malloc
	test rax, rax
	je .fail_malloc

	mov rdi, rax
	pop rsi
	call ft_strcpy
	ret

.fail_malloc:
	pop rdi
	xor rax, rax
	ret