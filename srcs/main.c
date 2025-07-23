/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:29:18 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/23 15:22:38 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	main(void)
{
	char	buffer[2] = {0};

	if (ft_atoi_base("1", "123456789ABCDEF") == 0) {
		fprintf(stdout, "FT_ATOI_BASE RETURN 0\n");
		return 0;
	}
	else {
		fprintf(stdout, "FT_ATOI_BASE TEST\n");
		return 0;
	}

	while (1) {
		fprintf(stdout, "Available function are: \n");
		fprintf(stdout, "1- ft_strlen \n");
		fprintf(stdout, "2- ft_strcmp\n");
		fprintf(stdout, "3- ft_strcpy\n");
		fprintf(stdout, "4- ft_strdup\n");
		fprintf(stdout, "5- ft_write\n");
		fprintf(stdout, "6- ft_read\n");
		write(STDOUT_FILENO, ">", sizeof(char));
		scanf("%2s", buffer);

		int user_input = atoi(buffer);
		switch (user_input) {
			case 1:
				test_ft_strlen();
				break;
			case 2:
				test_ft_strcmp();
				break;
			case 3:
				test_ft_strcpy();
				break;
			case 4:
				test_ft_strdup();
				break;
			case 5:
				test_ft_write();
				break;
			case 6:
				test_ft_read();
				break;
			default:
				fprintf(stdout, "Invalid input\n");
				fflush(stdout);
				exit(1);
		}
		fflush(stdout);
	}
	return 0;
}