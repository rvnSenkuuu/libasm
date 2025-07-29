%include "list.inc"
global ft_list_sort

; void	ft_list_sort(t_list **begin, int (*cmp)())
; r12 --> current_node
; r13 --> next_node
; r14 --> ptr func

section .text
ft_list_sort:
	push rbp
	mov rbp, rsp

	push rbx
	push r12
	push r13
	push r14
	push r15

	mov r15, rdi ; save the ptr to the head of the list
	mov r14, rsi ; save cmp function

.outer_loop:
	xor rbx, rbx ; set to 0 the swap flag
	mov r12, [r15] ; current_node = *begin

.inner_loop:
	test r12, r12 ; if current_node == NULL
	jz .check_flag
	mov r13, [r12 + s_list.next] ; next_node = current_node->next
	test r13, r13 ; if next_node == NULL
	jz .check_flag

	mov rdi, [r12]
	mov rsi, [r13]
	call r14 ; (*cmp)(current_node->data, next_node->data) (rdi, rsi)
	test eax, eax
	jle .inc_node

	mov rcx, [r12] ; swap nodes
	mov rdx, [r13]
	mov [r12], rdx
	mov [r13], rcx
	mov rbx, 1

.inc_node:
	mov r12, r13 ; current_node = next_node
	jmp .inner_loop

.check_flag:
	test rbx, rbx
	jnz .outer_loop

.return:
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	leave
	ret