/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:27 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/12 18:00:43 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	char *full;
	char *final;
	static char *reste;
	int ret;
	int xd;
	if (reste == 0)
		full = malloc(sizeof(char));
	else
	{
		full = reste;
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		final = ft_strjoin_gnl(full, buf);
		free(full);
		full = final;
		if ((xd = ft_strchr_gnl(full, '\n')) != 0)
		{
				reste = ft_cutnext_gnl(full, xd);
				final = ft_cutfinal_gnl(full, xd);
				*line = final;
				//printf("#%s# < ligne\n", final);
				//printf("$%s$ < reste\n", reste);
			return (1);
		}
	}

	
	printf("EXIT");
	return (0);	

}
