/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:38:03 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/28 13:55:36 by tkara2           ###   ########.fr       */
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
	write(STDOUT_FILENO, "\n", sizeof(char));
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
	write(STDOUT_FILENO, "\n", sizeof(char));
	fprintf(stdout, "List after sort: \n");
	ft_list_sort(&list, strcmp);
	print_list(list);
	write(STDOUT_FILENO, "\n", sizeof(char));
}