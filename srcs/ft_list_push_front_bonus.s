%include "list.inc"
global ft_list_push_front

; void	ft_list_push_front(t_list **lst, t_list *new_node)
; ft_list_push_front(rdi, rsi)

section .text
ft_list_push_front:
	push rbp ; function prologue save the current state of the stack
	mov rbp, rsp

	mov rax, [rdi] ; save *lst in rax
	mov [rsi + s_list.next], rax ; new_node->next = *lst
	mov [rdi], rsi ; *lst = new_node

.return:
	leave
	ret