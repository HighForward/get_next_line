/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:07 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/12 18:00:47 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;
	int i;
	char **line;

	fd = 1;	
	i = 0;
	line = (char**)malloc(sizeof(char*) * 9);
	
	fd = open("test", O_RDONLY);

	while(get_next_line(fd, &line[i]) == 1)
	{
		printf("#%s# < ligne\n", line[i]);
		i++;
	}
}
