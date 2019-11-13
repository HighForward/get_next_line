/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:27 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/13 15:20:52 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s, int size)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size - 1)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_get_reste(char *s)
{
	int i;
	int size;
	char *d;

	size = ft_strlen_gnl(s);
	d = (char*)malloc(sizeof(char) * size + 1);
	i = 0;
	
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	char *full;
	char *final;
	static char *reste;
	int ret;

	if (reste == 0)
		full = ft_calloc(1, 0);
	else
		full = ft_get_reste(reste);

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		final = ft_strjoin_gnl(full, buf);
		free(full);
		full = final;
		if ((ret = ft_strchr_gnl(full, '\n')) != 0)
		{
			*line = ft_strdup(full, ret);
			if (ret + 1 < ft_strlen_gnl(full))
			{
				reste =  &full[ret];
			}
			free(full);
			return(1);
		}
	}
	printf("EXIT");
	return (0);	
}
