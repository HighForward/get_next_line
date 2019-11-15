/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:27 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/15 18:11:23 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_read_fd(int fd, char **str)
{
	char *buff;
	char *full;
	int size_read;

	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if ((size_read = read(fd, buff, BUFFER_SIZE)) <= 0)
	{
		free(buff);
		return (0);
	}
	buff[size_read] = '\0';
	if ((full = ft_strnew(ft_strlen(*str) + size_read + 1)) == NULL)
		return (-1);
	if (*str)
	{
		full = ft_strncat(full, *str, ft_strlen(*str));
		free(*str);
	}
	*str = ft_strncat(full, buff, size_read);
	free(buff);
	if (ft_strchr(*str) == 0)
		return (ft_read_fd(fd, str));
	return (1);
}

int get_new_line(char **str, char **bsn)
{
	char *line;
	char *after;
	int i;
	int y;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(line = ft_strnew(i + 1)))
		return (-1);
	line = ft_strncat(line, *str, i);
	*bsn = line;
	y = (ft_strlen(*str) - i);
	if (y == 0)
	{
		free(str);
		return(0);
	}
	if ((after = ft_strnew(y + 1)))
	{
		after = ft_strncat(after, &(*str)[i + 1], (ft_strlen(*str) - i - 1));
		free(*str);
		*str = after;
		printf("%s", *str);
		return (1);
	}
	//printf("%s", *str);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *reste;
	int cut;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	reste = NULL;
	if ((ft_strchr(reste)) == 0)
	{
		if ((ft_read_fd(fd, &reste) == -1))
			return (-1);
		if (!reste)
		{
			*line = ft_strnew(0);
			return (1);
		}
		//*line = toBSN;
	}
	return (get_new_line(&reste, line));
}
