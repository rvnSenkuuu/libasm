global ft_write
extern __errno_location

section .text
ft_write:
	mov rax, 1
	syscall
	test rax, rax
	js .write_fail
	ret

.write_fail:
	neg rax ;reverse the errno value sent from the syscall
	mov r8, rax ;move the value into r8 register for saving
	call __errno_location
	mov [rax], r8 ;set the value into *errno
	mov rax, -1
	ret