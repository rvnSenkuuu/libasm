/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:29:18 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/14 18:05:38 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_ft_strlen(void)
{
	const char	*str[FT_STRLEN_TEST_CASE] = {
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
		"ccccccccccccccccccccccccc",
		"dddddddddddddddd",
		"eeeeeeeeeee",
		"fffff",
		"g"
	};

	for (int i = 0; i < FT_STRLEN_TEST_CASE; i++) {
		size_t	ft_res = ft_strlen(str[i]);
		size_t libc_res = strlen(str[i]);

		fprintf(stdout, "-----Testing case %d-----\n", i);
		fprintf(stdout, "ft_strlen result: %zu\n", ft_res);
		fprintf(stdout, "strlen result: %zu\n", libc_res);

		if (ft_res != libc_res)
			fprintf(stdout, "TEST FAILED\n");
		else
			fprintf(stdout, "TEST SUCCESS\n");

		write(STDOUT_FILENO, "\n", sizeof(char));
	}
}

int	main(void)
{
	test_ft_strlen();
	return 0;
}