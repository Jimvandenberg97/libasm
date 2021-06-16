/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:48:36 by jivan-de       #+#    #+#                */
/*   Updated: 2020/02/27 12:33:46 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <sys/types.h>

size_t      ft_strlen(const char *s);
ssize_t     ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t     ft_read(int fildes, void *buf, size_t nbyte);
int         ft_strcmp(const char *s1, const char *s2);
char        *ft_strcpy(char * dst, const char * src);
char        *ft_strdup(const char *s1);

# endif