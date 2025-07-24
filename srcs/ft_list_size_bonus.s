%include "list.inc"
global ft_list_size

section .text
ft_list_size:
	push rbp ; function prologue save the current state of the stack
	mov rbp, rsp

	xor rax, rax

.loop:
	test rdi, rdi
	je .return
	inc rax
	mov rdi, [rdi + s_list.next]
	jmp .loop

.return:
	leave ; the function epilogue restores the state of the stack before the function call
	ret