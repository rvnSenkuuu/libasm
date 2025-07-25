%include "list.inc"
global ft_list_sort

; void	ft_list_sort(t_list **begin, int (*cmp)())

section .text
ft_list_sort:
	push rbp
	mov rbp, rsp

.return:
	leave
	ret