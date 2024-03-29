/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:27 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/19 13:47:56 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int free_string(char **str, int value)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (value);
}

static int ft_read_fd(int fd, char **str)
{
	char *buffer;
	char *temp;
	int size_read;

	if (!(buffer = ft_strnew(BUFFER_SIZE)))
		return (KO);
	if ((size_read = read(fd, buffer, BUFFER_SIZE)) <= 0)
	{
		free(buffer);
		return (size_read);
	}
	buffer[size_read] = '\0';
	if (!(temp = ft_strnew(ft_strlen(*str) + size_read)))
		return (KO);
	if (*str)
	{
		temp = ft_strncat(temp, *str, ft_strlen(*str));
		free(*str);
	}
	*str = ft_strncat(temp, buffer, size_read);
	free(buffer);
	if (!ft_is_line(*str))
		return (ft_read_fd(fd, str));
	return (OK);
}

static int ft_split_str(char **str, char **line)
{
	char *temp;
	char *temp_line;
	int size_line;
	int size_rest;

	size_line = 0;
	while ((*str)[size_line] && (*str)[size_line] != '\n')
		size_line++;
	if (!(temp_line = ft_strnew(size_line)))
		return (KO);
	*line = ft_strncat(temp_line, *str, size_line);
	size_rest = ft_strlen(*str) - size_line;
	if (size_rest == 0)
		return (free_string(str, END));
	if ((temp = ft_strnew(size_rest)))
	{
		temp = ft_strncat(temp, &(*str)[size_line + 1], size_rest - 1);
		free(*str);
		*str = temp;
		return (OK);
	}
	return (free_string(str, KO));
}

int get_next_line(int fd, char **line)
{
	static char *str;
	int cut;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (KO);

	if (!ft_is_line(str))
	{
		if (ft_read_fd(fd, &str) == KO)
			return (KO);
		if (!str)
		{
			*line = ft_strnew(0);
			return (END);
		}
	}
	if ((cut = ft_split_str(&str, line)) != OK)
		return (free_string(&str, END));
	return (OK);
}
