/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:45 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/15 16:18:48 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int ft_read_fd(int fd, char **str);
int get_next_line(int fd, char **line);
int ft_strlen(char *s);
int ft_strchr(char *s);
char *ft_strjoin(char *s1, char *s2);
char *ft_strncat(char *dest, char *src, size_t n);
char *ft_strnew(int size);

#endif
