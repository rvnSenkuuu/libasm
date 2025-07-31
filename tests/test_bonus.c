/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:38:03 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/31 11:00:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_ft_atoi_base(void)
{
	fprintf(stdout, "=====FT_ATOI_BASE=====\n");

	char	*base_two = "01";
	char	*base_ten = "0123456789";
	char	*base_hex = "0123456789ABCDEF";

	ATOI_BASE_ASSERT("122erjerjre", base_two, 1);
	ATOI_BASE_ASSERT("-122erjerjre", base_two, 2);
	ATOI_BASE_ASSERT("    42efefefef", base_ten, 3);
	ATOI_BASE_ASSERT("\t \r 42bbb", base_hex, 4);
	ATOI_BASE_ASSERT("-42wfewfg", base_ten, 5);
	ATOI_BASE_ASSERT("--155wfwef", "123456189", 6);
	ATOI_BASE_ASSERT("444gwgwggwg", "+123456789", 7);
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

	print_list(list, NULL, 0);
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

	print_list(list, "before", 's');
	ft_list_sort(&list, strcmp);
	print_list(list, "after", 's');
}

void	test_ft_list_remove_if(void)
{
	fprintf(stdout, "=====FT_LIST_REMOVE_IF=====\n");
	
	char	*strs[] = {"aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"};
	char	*to_remove_str = "bbbbb";

	t_list	*list_str = create_list_str(strs, 5);
	fprintf(stdout, "=====TEST 1=====\n");
	fprintf(stdout, "Trying to remove : %s\n", to_remove_str);
	print_list(list_str, "before", 's');
	ft_list_remove_if(&list_str, to_remove_str, ft_strcmp, free);
	print_list(list_str, "after", 's');
	free_list(list_str);

	t_list	*list_str1 = create_list_str(strs, 5);
	char	*to_remove1_str = "xxxxx";
	fprintf(stdout, "=====TEST 2=====\n");
	fprintf(stdout, "Trying to remove : %s\n", to_remove1_str);
	print_list(list_str1, "before", 's');
	ft_list_remove_if(&list_str1, to_remove1_str, ft_strcmp, free);
	print_list(list_str1, "after", 's');
	free_list(list_str1);

	int	array[] = {1, 2, 3, 4, 5, 6};
	t_list	*list_int = create_list_int(array, ARRAY_LEN(array));
	int	to_remove_int = 1;
	fprintf(stdout, "=====TEST 3=====\n");
	fprintf(stdout, "Trying to remove : %d\n", to_remove_int);
	print_list(list_int, "before", 'd');
	ft_list_remove_if(&list_int, &to_remove_int, cmp_int, free);
	print_list(list_int, "after", 'd');
	free_list(list_int);

	int	array1[] = {1, 2, 3, 4, 5, 6};
	t_list	*list_int1 = create_list_int(array1, ARRAY_LEN(array1));
	int	to_remove_int1 = 55;
	fprintf(stdout, "=====TEST 4=====\n");
	fprintf(stdout, "Trying to remove : %d\n", to_remove_int1);
	print_list(list_int1, "before", 'd');
	ft_list_remove_if(&list_int1, &to_remove_int1, cmp_int, free);
	print_list(list_int1, "after", 'd');
	free_list(list_int1);

	int	array2[] = {42, 42, 42, 42, 42, 42};
	t_list	*list_int2 = create_list_int(array2, ARRAY_LEN(array2));
	int	to_remove_int2 = 42;
	fprintf(stdout, "=====TEST 5=====\n");
	fprintf(stdout, "Trying to remove : %d\n", to_remove_int2);
	print_list(list_int2, "before", 'd');
	ft_list_remove_if(&list_int2, &to_remove_int2, cmp_int, free);
	print_list(list_int2, "after", 'd');
	free_list(list_int2);
}