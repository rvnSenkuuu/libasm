/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:29:18 by tkara2            #+#    #+#             */
/*   Updated: 2025/07/18 12:24:36 by tkara2           ###   ########.fr       */
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

		fprintf(stdout, "\n-----Testing Case %d-----\n", i);
		fprintf(stdout, "Str = %s\n", str[i]);
		fprintf(stdout, "ft_strlen result = %zu\nstrlen result = %zu\n", ft_res, libc_res);

		if (ft_res != libc_res)
			fprintf(stdout, "TEST FAILED\n");
		else
			fprintf(stdout, "TEST SUCCESS\n");
	}
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void	test_ft_strcmp(void)
{
	fprintf(stdout, "=====FT_STRCMP=====\n");

	srand(time(NULL));
	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		int random = rand() % FT_STR_TEST_CASE;
		int ft_res = ft_strcmp(str[i], str[random]);
		int libc_res = strcmp(str[i], str[random]);

		fprintf(stdout, "\n-----Testing Case %d-----\n", i);
		fprintf(stdout, "S1 = %s\nS2 = %s\n", str[i], str[random]);
		fprintf(stdout, "ft_strcmp result = %d\nstrcmp result = %d\n", ft_res, libc_res);
		
		if ((ft_res < 0 && libc_res < 0)
			|| (ft_res > 0 && libc_res > 0)
			|| (ft_res == 0 && libc_res == 0))
			fprintf(stdout, "TEST SUCCESS\n");
		else
			fprintf(stdout, "TEST FAILED\n");
	}
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void	test_ft_strcpy(void)
{
	fprintf(stdout, "=====FT_STRCPY=====\n");
	char	ft_dest[256] = {0};
	char	libc_dest[256] = {0};

	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		fprintf(stdout, "\n-----Testing Case %d-----\n", i);
		fprintf(stdout, "Src = %s\n", str[i]);

		ft_strcpy(ft_dest, str[i]);
		strcpy(libc_dest, str[i]);

		fprintf(stdout, "Ft_Dest = %s\n", ft_dest);
		fprintf(stdout, "Libc_Dest = %s\n", libc_dest);

		if (strncmp(ft_dest, libc_dest, strlen(str[i])) == 0)
			fprintf(stdout, "TEST SUCCESS\n");
		else
			fprintf(stdout, "TEST FAILED\n");
	}
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void	test_ft_strdup(void)
{
	fprintf(stdout, "=====FT_STRDUP=====\n");
	char	*ft_dest;
	char	*libc_dest;

	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		fprintf(stdout, "\n-----Testing Case %d-----\n", i);
		fprintf(stdout, "Src[%p] = %s\n", str[i], str[i]);

		ft_dest = ft_strdup(str[i]);
		libc_dest = strdup(str[i]);

		fprintf(stdout, "Ft_Dest[%p] = %s\n", ft_dest, ft_dest);
		fprintf(stdout, "Libc_Dest[%p] = %s\n", libc_dest, libc_dest);
		
		if (strncmp(ft_dest, libc_dest, strlen(str[i])) == 0)
			fprintf(stdout, "TEST SUCCESS\n");
		else
			fprintf(stdout, "TEST FAILED\n");
		free(ft_dest);
		free(libc_dest);
	}
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void	test_ft_write(void)
{
	fprintf(stdout, "=====FT_WRITE=====\n");
	for (int i = 0; i < FT_STR_TEST_CASE; i++) {
		fprintf(stdout, "\n-----Testing Case %d-----\n", i);
		int ft_write_res = ft_write(STDOUT_FILENO, str[i], strlen(str[i]));
		perror("\nFt_write errno");
		int sys_write_res = write(STDOUT_FILENO, str[i], strlen(str[i]));
		perror("\nSys_write errno");

		if (ft_write_res != sys_write_res)
			fprintf(stdout, "Expected %lu byte(s)\nFt_write = %d Sys_write = %d\n", strlen(str[i]), ft_write_res, sys_write_res);
		else
			fprintf(stdout, "Same byte(s) written from ft_write (%d) and sys_write (%d)\n", ft_write_res, sys_write_res);
	}
	fprintf(stdout, "\nTesting invalid fd for errno check\n");
	ft_write(42, str[1], strlen(str[1]));
	fprintf(stdout, "Ft_write = %s (%d)\n", strerror(errno), errno);
	write(42, str[1], strlen(str[1]));
	fprintf(stdout, "Sys_write = %s (%d)\n", strerror(errno), errno);
}

void	test_ft_read(void)
{
	fprintf(stdout, "=====FT_READ=====\n");
	int	read_byte = 1;
	char	buffer[BUFFER_SIZE] = {0};
	const char	*file = "Makefile";

	int	fd = open(file, O_RDONLY);
	if (fd < 0) {
		perror("Open");
		return;
	} 
	while (read_byte != 0) {
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0) {
			perror("Sys_Read");
			return;
		}
	}
	fprintf(stdout, "Sys_read\n%s\n", buffer);

	lseek(fd, 0, SEEK_SET);
	memset(buffer, 0, BUFFER_SIZE);
	read_byte = 1;
	while (read_byte != 0) {
		read_byte = ft_read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0) {
			perror("Ft_read");
			return;
		}
	}
	fprintf(stdout, "\nFt_read\n%s\n", buffer);
	close(fd);

	fprintf(stdout, "\nErrno Check\n");
	char	err_buffer[BUFFER_SIZE] = {0};
	const char	*dir = "srcs";
	int	err_fd = open(dir, O_RDONLY);
	if (err_fd < 0) {
		perror("Open");
		return;
	}
	int ft_res = ft_read(err_fd, err_buffer, BUFFER_SIZE);
	fprintf(stdout, "Ft_read = %s (%d) return value = %d\n", strerror(errno), errno, ft_res);
	int sys_ret = read(err_fd, err_buffer, BUFFER_SIZE);
	fprintf(stdout, "Sys_read = %s (%d) return value = %d\n", strerror(errno), errno, sys_ret);
	close(err_fd);
}

int	main(void)
{
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_strdup();
	test_ft_write();
	test_ft_read();
	return 0;
}