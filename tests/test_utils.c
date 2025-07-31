/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:57:42 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/31 13:57:50 by tkara2           ###   ########.fr       */
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

inline int	cmp_int(void *a, void  *b)
{
	if (*(int *)a == *(int *)b) return 0;
	return 1;
}

inline int	cmp_int_sort(void *a, void *b)
{
	return *(int *)a > *(int *)b;
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
			fprintf(stdout, "unknown type\n");
	}

	write(STDOUT_FILENO, "\n", sizeof(char));
}

static int	check_duplicate(char *base)
{
	int	i = 0;

	while (base[i]) {
		if (strchr(base, base[i]) == NULL) return 1;
		i++;
	}
	return 0;
}

static int	check_base(char *base)
{
	if (strlen(base) < 2) return 1;
	if (check_duplicate(base) == 1) return 1;
	int	i = 0;
	while (base[i]) {
		if (base[i] == '+' || base[i] == '-' || isspace(base[i]))
			return 1;
		i++;
	}
	return 0;
}

static int	ft_inbase(char *base, char c)
{
	int	i = 0;
	while (base[i]) {
		if (base[i] == c) return i;
		i++;
	}
	return 0;
}

int	c_atoi_base(char *str, char *base)
{
	int	i = 0;
	int j = 0;
	int	res = 0;
	int	sign = 1;
	int	base_len = strlen(base);

	if (base_len < 2 || check_base(base) == 1) return 0;
	while (base[i]) {
		if (base[i] == '-' || base[i] == '+' || isspace(base[i])) return 0;
		j = i + 1;
		while (base[j]) {
			if (base[i] == base[j]) return 0;
			j++;
		}
		i++;
	}

	i = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i] && ft_inbase(base, str[i]) > 0) {
		res = (res * base_len) + ft_inbase(base, str[i]);
		i++;
	}
	return res * sign;
}