/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:38:03 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/29 17:08:01 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_ft_atoi_base(void)
{
	fprintf(stdout, "=====FT_ATOI_BASE=====\n");

	char	*base_two = "01";
	char	*base_ten = "0123456789";
	char	*base_hex = "0123456789ABCDEF";

	ATOI_BASE_ASSERT("122erjerjre", base_two, 1, 1);
	ATOI_BASE_ASSERT("-122erjerjre", base_two, -1, 2);
	ATOI_BASE_ASSERT("    42efefefef", base_ten, 42, 3);
	ATOI_BASE_ASSERT("\t \r 42bbb", base_hex, 66, 4);
	ATOI_BASE_ASSERT("-42wfewfg", base_ten, -42, 5);
	ATOI_BASE_ASSERT("--155wfwef", "123456189", 0, 6);
	ATOI_BASE_ASSERT("444gwgwggwg", "+123456789", 0, 7);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void	test_ft_list_size(void)
{
	fprintf(stdout, "=====FT_LIST_SIZE=====\n");
	
	t_list	node, node1, node2, node3;

	node.next = &node1;
	node1.next = &node2;
	node2.next = &node3;

	LIST_SIZE_ASSERT(&node, 4, 1);
	LIST_SIZE_ASSERT(&node2, 2, 2);
	LIST_SIZE_ASSERT(&node3, 1, 3);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

static void	print_list(t_list *list)
{
	while (list) {
		fprintf(stdout, "List data = %s\n", (char *)list->data);
		list = list->next;
	}
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void	test_ft_list_push_front(void)
{
	fprintf(stdout, "=====FT_LIST_PUSH_FRONT=====\n");

	t_list	*list = NULL;
	t_list	node, node1, node2, node3;

	node.data = "aaaaaa";
	node1.data = "bbbbbbbb";
	node2.data = "cccccccccc";
	node3.data = "ddddddddddddd";

	ft_list_push_front(&list, &node);
	ft_list_push_front(&list, &node1);
	ft_list_push_front(&list, &node3);
	ft_list_push_front(&list, &node2);

	print_list(list);
}

void	test_ft_list_sort(void)
{
	fprintf(stdout, "=====FT_LIST_SORT=====\n");

	t_list	*list = NULL;
	t_list	node, node1, node2, node3;

	node.data = "aaaaa";
	node1.data = "bbbbb";
	node2.data = "ccccc";
	node3.data = "ddddd";

	ft_list_push_front(&list, &node);
	ft_list_push_front(&list, &node1);
	ft_list_push_front(&list, &node2);
	ft_list_push_front(&list, &node3);

	fprintf(stdout, "List before sort: \n");
	print_list(list);
	fprintf(stdout, "List after sort: \n");
	ft_list_sort(&list, strcmp);
	print_list(list);
}

t_list	*create_list_str(char **strs, int size)
{
	t_list	*head = NULL;
	for (int i = size - 1; i >= 0; i--) {
		t_list	*node = malloc(sizeof(*node));
		node->data = strdup(strs[i]);
		node->next = head;
		head = node;
	}
	return head;
}

void	free_list(t_list *list)
{
	t_list *tmp;
	while (list) {
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
}

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
// {
// 	t_list	*cur;

// 	if (begin_list == NULL || *begin_list == NULL)
// 		return;

// 	cur = *begin_list;
// 	if (cmp(cur->data, data_ref) == 0) {
// 		*begin_list = cur->next;
// 		free_fct(cur);
// 		ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
// 	}
// 	else
// 		ft_list_remove_if(&cur->next, data_ref, cmp, free_fct);
// }

void ft_list_remove_if(t_list **begin, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*prev;
	t_list	*tmp;

	current = *begin;
	while (current) {
		if (cmp(current->data, data_ref) == 0) {
			tmp = current;
			if (!prev) {
				*begin = current->next;
				prev = current;
			} else {
				prev->next = current->next;
				current = prev->next;
			}
			free_fct(tmp->data);
			free(tmp);
		}
		prev = current;
		current = current->next;
	}
}

void	test_ft_list_remove_if(void)
{
	fprintf(stdout, "=====FT_LIST_REMOVE_IF=====\n");
	
	char	*strs[] = {"aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"};
	char	*to_remove = "ccccc";

	t_list	*list = create_list_str(strs, 5);

	fprintf(stdout, "List before remove_if:\n");
	print_list(list);

	ft_list_remove_if(&list, to_remove, strcmp, free);

	fprintf(stdout, "List after remove_if:\n");
	print_list(list);

	free_list(list);
}