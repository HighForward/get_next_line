/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:07 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/15 18:10:35 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int i;
	char *line;
	(void)argc;
	fd = 1;	
	i = 0;
	//line = (char**)malloc(sizeof(char*) * 80);
	
	fd = open(argv[1], O_RDONLY);

	while(i < 2 &&(get_next_line(fd, &line) >= 0))
	{
		printf("ligne: %s\n", line);
		i++;
	}
}
