/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:27 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/18 20:45:06 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_read_fd(int fd, char **rest)
{
	char *buffer;
	char *str;
	int size_read;

	if (!(buffer = ft_strnew(BUFFER_SIZE)))
		return (FAILURE);
	if ((size_read = read(fd, buffer, BUFFER_SIZE)) <= 0)
	{
		free(buffer);
		return (size_read);
	}
	buffer[size_read] = '\0';
	if (!(str = ft_strnew(ft_strlen(*rest) + BUFFER_SIZE)))
		return (FAILURE);
	if (*rest)
	{
		str = ft_strncat(str, *rest, ft_strlen(*rest));
		free(*rest);
	}
	*rest = ft_strncat(str, buffer, size_read);
	free(buffer);
	if (!(ft_is_line(str)))
		return (ft_read_fd(fd, rest));
	return (SUCCESS);
}

static int ft_split_rest(char **rest, char **line)
{
	int i;
	int size;
	char *temp_line;
	char *temp;

	i = 0;
	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	if (!(temp_line = ft_strnew(i)))
		return (FAILURE);
	*line = ft_strncat(temp_line, *rest, i);
	size = ft_strlen(*rest) - i;
	if (size == 0)
		return (free_string(rest, END_FILE));
	if ((temp = ft_strnew(size)))
	{
		temp = ft_strncat(temp, &(*rest)[i + 1], size - 1);
		free(*rest);
		*rest = temp;
		return (SUCCESS);
	}
	return (free_string(rest, FAILURE));
}

int get_next_line(int fd, char **line)
{
	static char *rest = NULL;
	int error;

	error = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (FAILURE);
	if (!ft_is_line(rest))
	{
		if (ft_read_fd(fd, &rest) == FAILURE)
			return (free_string(&rest, FAILURE));
		if (!rest)
		{
			*line = ft_strnew(0);
			return (END_FILE);
		}
	}
	if ((error = ft_split_rest(&rest, line)) != SUCCESS)
		return (free_string(&rest, 0));
	return (SUCCESS);
}