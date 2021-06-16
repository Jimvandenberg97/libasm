/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:48:44 by jivan-de      #+#    #+#                 */
/*   Updated: 2020/06/23 15:22:26 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void    ft_read_test()
{
    int     fd;
    int     ret;
    char    bufferft[75];
    char    bufferog[75];

    printf("\n -----------------FT_READ-------------------\n");

    fd = open("Makefile", O_RDONLY);
    ret = read(fd, bufferog, 5);
    close(fd);
    printf("1: REAL : %d\n", ret);
    fd = open("Makefile", O_RDONLY);
    ret = ft_read(fd, bufferft, 5);
    close(fd);
    printf("1: FT : %d\n", ret);

    fd = open("Makefile", O_RDONLY);
    ret = read(fd, NULL, 1);
    close(fd);
    printf("2: REAL : %d\n", ret);
    fd = open("Makefile", O_RDONLY);
    ret = ft_read(fd, NULL, 1);
    close(fd);
    printf("2: FT : %d\n", ret);
}

void    ft_read_test2()
{
    int     fd;
    int     ret;

    fd = open("BlaBla", O_RDONLY);
    ret = read(fd, NULL, 1);
    close(fd);
    printf("3: REAL : %d\n", ret);
    fd = open("BlaBla", O_RDONLY);
    ret = ft_read(fd, NULL, 1);
    close(fd);
    printf("3: FT : %d\n", ret);
    printf("\n");
}

void    ft_write_test()
{
    int ret;
    printf("\n -----------------FT_WRITE-------------------\n");

	printf("1: REAL : %zd\n", write(1, "", 0));
	printf("1: FT : %zd\n", ft_write(1, "", 0));
    ret = write(1, "Hello", 3);
    printf("\n2: REAL : %d\n", ret);
    ret = ft_write(1, "Hello", 3);
    printf("\n2: FT : %d\n", ret);
    ret = write(1, "Hello", 5);
    printf("\n3: REAL : %d\n", ret);
    ret = ft_write(1, "Hello", 5);
    printf("\n3: FT : %d\n", ret);
    ret = write(1, "Hello", 10);
    printf("\n4: REAL : %d\n", ret);
    ret = ft_write(1, "Hello", 10);
    printf("\n4: FT : %d\n", ret);
	printf("5: REAL : %zd\n", write(1, NULL, 5));
	printf("5: FT : %zd\n", ft_write(1, NULL, 5));
	printf("6: REAL : %zd\n", write(42, "Hello", 5));
	printf("6: FT : %zd\n", ft_write(42, "Hello", 5));
    printf("7: REAL : %zd\n", write(-42, "Hello", 5));
	printf("7: FT : %zd\n", ft_write(-42, "Hello", 5));
    printf("\n");
}

void    ft_strlen_test()
{
    printf("\n -----------------FT_STRLEN-------------------\n");

	printf("1: REAL : %lu\n", strlen(""));
	printf("1: FT : %lu\n", ft_strlen(""));
    printf("2: REAL : %lu\n", strlen("Hello"));
	printf("2: FT : %lu\n", ft_strlen("Hello"));
    printf("3: REAL : %lu\n", strlen("\n"));
	printf("3: FT : %lu\n", ft_strlen("\n"));
    printf("\n");
}

void    ft_strcpy_test()
{
    char dest[75];

    printf("\n -----------------FT_STRCPY-------------------\n");

    printf("1: REAL : %s\n", strcpy(dest, ""));
	printf("1: FT : %s\n", ft_strcpy(dest, ""));
    printf("2: REAL : %s\n", strcpy(dest, "\n"));
	printf("2: FT : %s\n", ft_strcpy(dest, "\n"));
    printf("3: REAL : %s\n", strcpy(dest, "Hello"));
	printf("3: FT : %s\n", ft_strcpy(dest, "Hello"));
    printf("\n");
}

void    ft_strcmp_test()
{
    printf("\n -----------------FT_STRCMP-------------------\n");

    printf("1: REAL : %d\n", strcmp("", ""));
	printf("1: FT : %d\n", ft_strcmp("", ""));
    printf("2: REAL : %d\n", strcmp("Hello", "Hello"));
	printf("2: FT : %d\n", ft_strcmp("Hello", "Hello"));
    printf("3: REAL : %d\n", strcmp("Goodbye", ""));
	printf("3: FT : %d\n", ft_strcmp("Goodbye", ""));
    printf("4: REAL : %d\n", strcmp("", "Goodbye"));
	printf("4: FT : %d\n", ft_strcmp("", "Goodbye"));
    printf("5: REAL : %d\n", strcmp("Hello", "Goodbye"));
	printf("5: FT : %d\n", ft_strcmp("Hello", "Goodbye"));
    printf("\n");
}

void    ft_strdup_test()
{
    printf("\n -----------------FT_STRDUP-------------------\n");

    printf("1: REAL : %s\n", strdup(""));
	printf("1: FT : %s\n", ft_strdup(""));
    printf("2: REAL : %s\n", strdup("Hello"));
	printf("2: FT : %s\n", ft_strdup("Hello"));
    printf("3: REAL : %s\n", strdup("This is my own strdup function for lib assembly"));
	printf("3: FT : %s\n", ft_strdup("This is my own strdup function for lib assembly"));
    printf("4: REAL : %s\n", strdup("\n"));
	printf("4: FT : %s\n", ft_strdup("\n"));
}

int     main(void)
{
    ft_read_test();
    ft_read_test2();
    ft_write_test();
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_strdup_test();
    
    return (0);
}