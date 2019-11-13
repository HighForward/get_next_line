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

char *ft_read_fd(int fd)
{
	int ret;
	char *buff;
	char *temp;
	char *line;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = malloc(sizeof(char));

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(line, buff);
		free(line);
		line = temp;
		if((ret = ft_strchr(line, '\n')) != 0)
			break;
	}
	free(buff);
	return(line);
}

char	*ft_strdup(char *s, int size)
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
	free(s);
	return (dup);
}

int	get_next_line(int fd, char **line)
{
	static char *reste;
	char *final;
	int cut;

	if (fd > 0)
	{
		if (reste == 0)
		{
			final = ft_read_fd(fd);
			cut = ft_strchr(final, '\n');
			reste = &final[cut + 1];
			*line = ft_strdup(final, cut);
			return (1);
		}
		else
		{
			if ((cut = ft_strchr(reste, '\n')) == 0)
			{
				
			}
		}
	}

	//printf("%s", reste);
	//printf("EXIT\n");
	return (0);	
}
