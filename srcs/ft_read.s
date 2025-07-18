global ft_read
extern __errno_location

section .text
ft_read:
	mov rax, 0
	syscall
	test rax, rax
	js .read_fail
	ret

.read_fail:
	neg rax
	mov r8, rax
	call __errno_location
	mov [rax], r8
	mov rax, -1
	ret