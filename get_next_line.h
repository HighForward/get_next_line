/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:45 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/18 20:47:16 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define SUCCESS 1
# define FAILURE -1
# define END_FILE 0

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);
int		ft_is_line(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strnew(int size);
int		free_string(char **str, int value);

#endif