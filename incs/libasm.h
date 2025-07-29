/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:35:40 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/28 14:02:29 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
#define LIBASM_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <time.h>
# include <fcntl.h>
# include <limits.h>

# define FT_STR_TEST_CASE 7
# define BUFFER_SIZE 2048

typedef struct s_list
{
	void	*data;
	struct s_list	*next;
} t_list;

extern int	ft_strcmp(const char *s1, const char *s2);
extern size_t	ft_strlen(const char *s);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char	*ft_strcpy(char *dest, const char *src);
extern char	*ft_strdup(const char *s);

extern int	ft_atoi_base(char *str, char *base);
extern int	ft_list_size(t_list *lst);
extern void	ft_list_push_front(t_list **list, t_list *node);
extern void	ft_list_sort(t_list **list, int (*cmp)());
extern void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

void	test_ft_strlen(void);
void	test_ft_strcmp(void);
void	test_ft_strcpy(void);
void	test_ft_strdup(void);
void	test_ft_write(void);
void	test_ft_read(void);
void	test_ft_atoi_base(void);
void	test_ft_list_size(void);
void	test_ft_list_push_front(void);
void	test_ft_list_sort(void);
void	test_ft_list_remove_if(void);

#define ATOI_BASE_ASSERT(str, base, expected, test_number) do {                  \
	fprintf(stdout, "\n-----Testing Case %d-----\n", test_number);               \
	int	res = ft_atoi_base(str, base);                                           \
	fprintf(stdout, "Result = %d\nExpected = %d\n", res, expected);              \
	if (res == expected)                                                         \
		fprintf(stdout, "TEST SUCCESS\n");                                       \
	else                                                                         \
		fprintf(stdout, "TEST FAILED\n");                                        \
} while (0)

#define LIST_SIZE_ASSERT(node, expected, test_number) do {                       \
	fprintf(stdout, "\n-----Testing Case %d-----\n", test_number);               \
	int	res = ft_list_size(node);                                                \
	fprintf(stdout, "Result = %d\nExpected = %d\n", res, expected);              \
	if (res == expected)                                                         \
		fprintf(stdout, "TEST SUCCESS\n");                                       \
	else                                                                         \
		fprintf(stdout, "TEST FAILED\n");                                        \
} while (0)

#endif