%include "list.inc"
global ft_list_remove_if
extern free

section .text
ft_list_remove_if:
	push rbp
	mov rbp, rsp

	push rbx
	push r12
	push r13
	push r14
	push r15

	mov rbx, rdi ; rbx -> begin
	mov r12, rsi ; r12 -> data_ref
	mov r13, rdx ; r13 -> cmp_fct
	mov r14, rcx ; r14 -> free_fct
	xor r15, r15 ; r15 -> prev_node
	mov rdi, [rdi] ; put *begin into rdi

.loop:
	test rdi, rdi ; if current == NULL
	je .return

	push rdi ; save rdi will overwritten for cmp function call
	
	mov rdi, [rdi + s_list.data]
	mov rsi, r12
	call r13 ; cmp(current->data, data_ref)
	pop rdi

	test rax, rax ; if cmp return value != 0
	jne .inc_node

.remove_node:
	push qword [rdi + s_list.next] ; push current->next to the stack to save it
	push rdi ; save current node it will be overwritten for free_fct call
	mov rdi, [rdi + s_list.data] ; put the current->data into rdi for free_fct call

	call r14 ; free_fct(current->data)
	pop rdi
	call free ; free(current)
	test r15, r15
	je .head_node

	pop rdi ; pop current->next
	mov [r15 + s_list.next], rdi ; prev->next = current->next

	jmp .loop

.head_node:
	pop rdi ; rdi = current->next
	mov [rbx], rdi ; *begin = current->next
	jmp .loop

.inc_node:
	mov r15, rdi ; prev = current
	mov rdi, [rdi + s_list.next] ; current = current->next

.return:
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	leave
	ret