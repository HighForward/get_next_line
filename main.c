/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:07 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/14 13:57:54 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int i;
	char **line;

	fd = 1;	
	i = 0;
	line = (char**)malloc(sizeof(char*) * 80);
	
	fd = open(argv[1], O_RDONLY);

	while ((get_next_line(fd, &line[i])) == 1)
		printf("ligne : %s\n", line[i++]);
}
