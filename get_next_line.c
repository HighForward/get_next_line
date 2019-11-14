/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:27 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/14 14:18:57 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list ft_read_fd(int fd, char *line)
{
	t_list list;
	int ret;
	char *buff;
	char *temp;
	int i;
	
	i = 0;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);

	while ((list.ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[list.ret] = '\0';
		temp = ft_strjoin(line, buff);
		free(line);
		line = temp;
		if((ret = ft_strchr(line, '\n')) != 0)
			break;
	}
	free(buff);
	list.str = line;
	return(list);
}

static char	*ft_strdup(char *s, int size)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	get_next_line(int fd, char **line)
{
	static char *reste;
	t_list final;
	char *str;
	int cut;

	if (reste != 0)
		str = ft_strdup(reste, (ft_strlen(reste)));
	else if (reste == 0)
		str = ft_strnew(0);
	if (fd > 0)
	{
		if ((ft_strchr(str, '\n')) == 0)
		{
			final = ft_read_fd(fd, str);
			if (final.ret == 0)
				return(0);
			cut = ft_strchr(final.str, '\n');
			reste = &final.str[cut];
			*line = ft_strdup(final.str, cut - 1);
			free(final.str);
			return(1);
		}
		else if ((cut = ft_strchr(str, '\n')) != 0)
		{
			if (cut == 1)
			{
				*line = ft_strnew(0);
				reste = &str[1];
				return(1);
			}
			else if (cut > 1)
			{
				reste = &str[cut];
				*line = ft_strdup(str, cut - 1);
				free(str);
				return(1);
			}
		}
	}
	return (0);	
}
