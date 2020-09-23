/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:04:11 by rbeach            #+#    #+#             */
/*   Updated: 2020/08/10 19:43:04 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(char *dst, const char *src);
ssize_t	ft_write(int fildes, const void *buf, size_t nbytes);
ssize_t	ft_read(int fildes, const void *buf, size_t nbytes);
char	*ft_strdup(const char *str);

int			main(void)
{
	char	test[] = "Test string";
	char	test2[100];
	char	*test3;
	char	*test4;
	int		fd;

	fd = open("Makefile", O_RDONLY);
	//ft_strlen tests
	printf("Tests: \n\nft_strlen:\n");
	printf("Line: |%s|, original strlen: %ld, asm strlen %d\n", test, strlen(test), (int)ft_strlen(test));
	//ft_strcpy tests
	test3 = ft_strcpy(test2, test);
	printf("\nft_strcpy:\nsrc line: |%s|, dest line : |%s|, return ptr line: |%s|\n", test, test2, test3);
	printf ("src line addr: |%p|, dest line addr: |%p|, ptr line addr: |%p|\n", test, test2, test3);
	//ft_strcmp
	ft_strcpy(test2, "Test2");
	printf("FT: 1 line: |%s|, 2 line: |%s|, return : |%d|\n", test, test2, ft_strcmp(test, test2));
	printf("OR: 1 line: |%s|, 2 line: |%s|, return : |%d|\n", test, test2, strcmp(test, test2));
	printf("FT: 1 line: |%s|, 2 line: |%s|, return : |%d|\n", test2, test, ft_strcmp(test2, test));
	printf("OR: 1 line: |%s|, 2 line: |%s|, return : |%d|\n", test2, test, strcmp(test2, test));
	printf("FT: 1 line: |%s|, 2 line: |%s|, return : |%d|\n", test, test, ft_strcmp(test, test));
	printf("OR: 1 line: |%s|, 2 line: |%s|, return : |%d|\n", test, test, strcmp(test, test));
	printf("NULL tests:\n1 line: |%s|, 2 line: |%s|, return : |%d|\n", NULL, NULL, ft_strcmp(NULL, NULL));
	printf("1 line: |%s|, 2 line: |%s|, return : |%d|\n", test, NULL, ft_strcmp(test, NULL));
	printf("1 line: |%s|, 2 line: |%s|, return : |%d|\n\n", NULL, test, ft_strcmp(NULL, test));
	//ft_write and read tests
	printf("ft_read and ft_write:\n");
	ft_write(1, "Read and write first 5 byte from Makefile: ", 43);
	ft_read(fd, test2, 5);
	ft_write(1, test2, 5);
	ft_write(1, "\n", 1);
	ft_write(1, "Read and write next 40 byte from Makefile: ", 43);
	ft_read(fd, test2, 40);
	ft_write(1, test2, 40);
	ft_write(1, "\n", 1);
	ft_write(1, "Read and write next 80 byte from Makefile: ", 43);
	ft_read(fd, test2, 80);
	ft_write(1, test2, 80);
	ft_write(1, "\n", 1);
	test4 = NULL;
	printf("\nft_strdup:\nTest dst: |%s|, ", test4);
	test4 = strdup(test);
	printf("Test src: |%s|, test dst after ft_strdup: |%s|\n", test, test4);
	printf("Test src addr: |%p|, Test dst addr: |%p|\n", test, test4);
	printf("\nTests with errno\n");
	test4 = NULL;
	printf("Write with null buf return: %zd\n", ft_write(1, test4, 3));
	perror("Error");
	printf("Write with wrong file descriptor return: %zd\n", ft_write(-5, "blabla", 3));
	perror("Error");
	printf("Read with null buf return: %zd\n", ft_read(fd, NULL, 3));
	perror("Error");
	printf("Read with wrong file descriptor return: %zd\n", ft_read(-5, test4, 3));
	perror("Error");
	return(1);
}
