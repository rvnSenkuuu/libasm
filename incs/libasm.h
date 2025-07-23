/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:35:40 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/21 14:17:14 by tkara2           ###   ########.fr       */
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

# define FT_STR_TEST_CASE 7
# define BUFFER_SIZE 2048

extern int	ft_strcmp(const char *s1, const char *s2);
extern size_t	ft_strlen(const char *s);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char	*ft_strcpy(char *dest, const char *src);
extern char	*ft_strdup(const char *s);

extern int	ft_atoi_base(char *str, char *base);

void	test_ft_strlen(void);
void	test_ft_strcmp(void);
void	test_ft_strcpy(void);
void	test_ft_strdup(void);
void	test_ft_write(void);
void	test_ft_read(void);

#endif