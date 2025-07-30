/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:57:42 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/30 15:58:19 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

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

t_list	*create_list_int(int *array, int size)
{
	t_list	*head = NULL;
	for (int i = size - 1; i >= 0; i--) {
		t_list	*node = malloc(sizeof(*node));
		node->data = malloc(sizeof(int));
		*(int *)node->data = array[i];
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

int	cmp_int(void *a, void  *b)
{
	if (*(int *)a == *(int *)b) return 0;
	return 1;
}

void	print_list(t_list *list, char *test_state, char list_type)
{
	if (test_state)
		fprintf(stdout, "List %s test:\n", test_state);

	switch (list_type) {
		case 's':
			while (list) {
				fprintf(stdout, "List data = %s\n", (char *)list->data);
				list = list->next;
			}
			break;
		case 'd':
			while (list) {
				fprintf(stdout, "List data = %d\n", *(int *)list->data);
				list = list->next;
			}
			break;
		default:	
			fprintf(stdout, "unknow type\n");
	}

	write(STDOUT_FILENO, "\n", sizeof(char));
}