/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:29:18 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/17 16:13:02 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

const char	*str[FT_STR_TEST_CASE] = {
	"62e836796jkshjhgvhjr343shvkjshjkhkjshbajkgjh43433bvjhbvj9337278",
	"!&($^!$!^$jherjherjvhkjhv{}{}?>::>:)",
	"2121ccccc      whvv27286rhvjehvg",
	"    }{|}{|%&^%^%}      ",
	"56176365",
	"__ejgehg",
	"42"
};

void	test_ft_strlen(void)
{
	fprintf(stdout, "=====FT_STRLEN=====\n");

	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		size_t	ft_res = ft_strlen(str[i]);
		size_t libc_res = strlen(str[i]);

		fprintf(stdout, "-----Testing Case %d-----\n", i);
		fprintf(stdout, "Str = %s\n", str[i]);
		fprintf(stdout, "ft_strlen result = %zu\nstrlen result = %zu\n", ft_res, libc_res);

		if (ft_res != libc_res)
			fprintf(stdout, "TEST FAILED\n");
		else
			fprintf(stdout, "TEST SUCCESS\n");
		write(STDOUT_FILENO, "\n", sizeof(char));
	}
}

void	test_ft_strcmp(void)
{
	fprintf(stdout, "=====FT_STRCMP=====\n");

	srand(time(NULL));
	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		int random = rand() % FT_STR_TEST_CASE;
		int ft_res = ft_strcmp(str[i], str[random]);
		int libc_res = strcmp(str[i], str[random]);

		fprintf(stdout, "-----Testing Case %d-----\n", i);
		fprintf(stdout, "S1 = %s\nS2 = %s\n", str[i], str[random]);
		fprintf(stdout, "ft_strcmp result = %d\nstrcmp result = %d\n", ft_res, libc_res);
		
		if ((ft_res < 0 && libc_res < 0)
			|| (ft_res > 0 && libc_res > 0)
			|| (ft_res == 0 && libc_res == 0))
			fprintf(stdout, "TEST SUCCESS\n");
		else
			fprintf(stdout, "TEST FAILED\n");
		write(STDOUT_FILENO, "\n", sizeof(char));
	}
}

void	test_ft_strcpy(void)
{
	fprintf(stdout, "=====FT_STRCPY=====\n");
	char	ft_dest[256] = {0};
	char	libc_dest[256] = {0};

	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		fprintf(stdout, "-----Testing Case %d-----\n", i);
		fprintf(stdout, "Src = %s\n", str[i]);

		ft_strcpy(ft_dest, str[i]);
		strcpy(libc_dest, str[i]);

		fprintf(stdout, "Ft_Dest = %s\n", ft_dest);
		fprintf(stdout, "Libc_Dest = %s\n", libc_dest);

		if (strncmp(ft_dest, libc_dest, strlen(str[i])) == 0)
			fprintf(stdout, "TEST SUCCESS\n");
		else
			fprintf(stdout, "TEST FAILED\n");
		write(STDOUT_FILENO, "\n", sizeof(char));
	}
}

void	test_ft_strdup(void)
{
	fprintf(stdout, "=====FT_STRDUP=====\n");
	char	*ft_dest;
	char	*libc_dest;

	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		fprintf(stdout, "-----Testing Case %d-----\n", i);
		fprintf(stdout, "Src[%p] = %s\n", str[i], str[i]);

		ft_dest = ft_strdup(str[i]);
		libc_dest = strdup(str[i]);

		fprintf(stdout, "Ft_Dest[%p] = %s\n", ft_dest, ft_dest);
		fprintf(stdout, "Libc_Dest[%p] = %s\n", libc_dest, libc_dest);
		
		if (strncmp(ft_dest, libc_dest, strlen(str[i])) == 0)
			fprintf(stdout, "TEST SUCCESS\n");
		else
			fprintf(stdout, "TEST FAILED\n");
		write(STDOUT_FILENO, "\n", sizeof(char));
		free(ft_dest);
		free(libc_dest);
	}
}

int	main(void)
{
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_strdup();
	return 0;
}