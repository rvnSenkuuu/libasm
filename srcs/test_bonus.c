/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:38:03 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/24 11:56:42 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_ft_atoi_base(void)
{
	fprintf(stdout, "=====FT_ATOI_BASE=====\n");

	char	*base_two = "01";
	char	*base_ten = "0123456789";
	char	*base_hex = "0123456789ABCDEF";
	char	*base_invalid = "+123456789";

	ATOI_BASE_ASSERT("122erjerjre", base_two, 1, 1);
	ATOI_BASE_ASSERT("-122erjerjre", base_two, -1, 2);
	ATOI_BASE_ASSERT("    42efefefef", base_ten, 42, 3);
	ATOI_BASE_ASSERT("\t \r 42bbb", base_hex, 66, 4);
	ATOI_BASE_ASSERT("-42wfewfg", base_ten, -42, 5);
	ATOI_BASE_ASSERT("--155wfwef", base_hex, 341, 6);
	ATOI_BASE_ASSERT("444gwgwggwg", base_invalid, 0, 7);
	write(STDOUT_FILENO, "\n", sizeof(char));
}