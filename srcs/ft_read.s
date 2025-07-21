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
	neg rax ;reverse the errno value sent from the syscall
	mov r8, rax ;move the value into r8 register for saving
	call __errno_location
	mov [rax], r8 ;set the value into *errno
	mov rax, -1
	ret