global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

section .text
ft_strdup:
	push rdi ;push rdi onto the stack to save it

	call ft_strlen
	inc rax ;increment it for NULL terminator

	mov rdi, rax ;store the length into rdi as a parameter for malloc
	call malloc
	test rax, rax ;check if malloc failed
	je .fail_malloc

	mov rdi, rax ;store the address of the malloc pointer into rdi as s1
	pop rsi ;pop the pointer saved at the beginning into rsi
	call ft_strcpy
	ret

.fail_malloc:
	pop rdi ;remove what we pushed onto the stack
	xor rax, rax
	ret